# File Editor
L'exécutable file-editor a pour but de simplifier et accélérer la création et édition des fichiers Json définissant les créatures et objets
utilisables lors d'un championnat donné.  
Ainsi, cela nous permet en tant que développeurs de perdre moins de temps à rédiger du boilerplate en Json, et de se concentrer sur ce qui définit
vraiment les divers éléments du jeu, mais permet également, en distribuant l'exécutable avec le jeu ou en l'intégrant plus tard avec une interface
graphique, aux joueurs de personnaliser leurs championnats.

# Fonctionnalités :
- [x] Création de fichier
- [x] Ouverture de fichiers existants
- [x] Navigation avec les flèches directionnelles
- [x] Ajout/Suppression d'éléments
- [x] Recherche d'élément par nom
- [ ] Autocomplétion de nom d'éléments provenant de dépendances
- [ ] Mise en évidence d'éléments introuvables dans les dépendances

# Architecture
L'architecture du programme est organisée comme suit :
la fonction [main](#main) crée un PackageExplorer avec les arguments donnés à l'exécution, et en appelle les méthodes de navigation.  
Le [PackageExplorer](#PackageExplorer) crée un Package à partir du contenu du fichier donné en argument, ou en crée un vide si le type de fichier
a été spécifié lors de l'appel à l'exécutable. Il gère la navigation au plus haut niveau, ainsi que les entrées/sorties.  
Le [Package](#Package) parse un string au format Json et enregistre ses éléments sous forme d'objets héritant de l'interface IPackageElement.
Il sert principalement à agglomérer les IPackageElement et offre des méthodes qui, le plus souvent, appellent les méthodes de ses éléments pour
créer un effet aggloméré.  
Les [IPackageElement](#IPackageElement) représentent les éléments primaires du jeu. Ils sont au nombre de 6 et sont identifiés par un numéro :
Creature(0), Item(2), Move(3), Type(5), Aura(1), Trigger(4).

## main
Utilise la librairie ncurses pour simplifier l'utilisation du terminal.  
A chaque appui de touche, avant de rafraîchir l'affichage, appelle une méthode de son PackageExplorer comme tel :  
<kbd>↑</kbd> : Up  
<kbd>↓</kbd> : Down  
<kbd>←</kbd> : Leave  
<kbd>→</kbd> : Enter  
<kbd>Return</kbd> : NavByName  
<kbd>Delete</kbd> : Erase  

## PackageExplorer
L'objet PackageExplorer retient l'arborescence de sa sélection sous forme d'un C-array d'entiers, sa profondeur courante, le nom du fichier ouvert, ainsi
qu'une référence au Package qu'il explore.
Il propose les méthodes suivantes :
<details>
  <summary>Display</summary>
  Affiche le package que cet explorer gère en déroulant les objets sur l'arborescence courante.
</details>
<details>
  <summary>Up</summary>
  Retranche 1 à la position de profondeur courante.
</details>
<details>
  <summary>Down</summary>
  Ajoute 1 à la position de profondeur courante.
</details>
<details>
  <summary>Enter</summary>
  Ajoute 1 à la profondeur courante, sauf si un sous-appel indique qu'il est impossible d'aller plus profond, et qu'une édition a eu lieu à la place.
</details>
<details>
  <summary>Leave</summary>
  Réinitialise la position à la profondeur courante, puis retranche 1 à celle-ci.
</details>
<details>
  <summary>NavByName</summary>
  Demande saisie d'un nom d'élément, puis, si un élément de même nom a été trouvé, le sélectionne.
</details>
<details>
  <summary>Erase</summary>
  Supprime l'élément sélectionné.
</details>
<details>
  <summary>Save</summary>
  *private* Enregistre le package géré au format Json dans le fichier nommé à la création de l'exploreur.
</details>

## Package
L'objet Package conserve l'identifiant du type de ses objets, une hashMap de ses éléments, un ensemble de leurs noms,
ainsi que les ensembles de ses dépendances.  
Il propose les méthodes suivantes :
<details>
  <summary>GetNames</summary>
  Retourne l'ensemble des noms des éléments de ce package.
</details>
<details>
  <summary>Get</summary>
  Retourne l'élément identifié par le nom passé en paramètre.
</details>
<details>
  <summary>JsonExport</summary>
  Retourne une représentation Json de ce package.
</details>
<details>
  <summary>AddElement</summary>
  Ajoute un élément donné en paramètre et l'associe à la clé également donnée en paramètre.
</details>
<details>
  <summary>AddNew</summary>
  Crée un élément et l'associe à la clé donnée en paramètre.
</details>
<details>
  <summary>AddDependency</summary>
  Ajoute la dépendance donnée en paramètre à l'ensemble approprié. Cette méthode essaie de lire le fichier pour déterminer son type, et pourrait
  à terme être utilisée pour créer une librairie d'auto-complétion, mais cette fonctionnalité n'a pas été implémentée.
</details>
<details>
  <summary>Display</summary>
  Ajoute une représentation textuelle du package au flux passé en argument, en prenant en compte le chemin passée en argument.
</details>
<details>
  <summary>NavigateTo</summary>
  Change le chemin passé en argument pour pointer vers l'élément dont le nom a été passé en argument, s'il existe.
</details>
<details>
  <summary>Prompt</summary>
  Essaie de modifier l'élément référencé par le chemin passé en argument, et renvoie si oui ou non une modification peut avoir lieu à cette profondeur.
</details>
<details>
  <summary>Erase</summary>
  Efface l'élément référencé par le chemin passé en argument, si cela fait sens (ex: impossible de supprimer les statistiques d'une créature).
</details>

## IPackageElement
Les objets héritant de IPackageElement stockent des données disparates selon le type précis de l'élément, mais doivent tous implémenter les méthodes
suivantes :
<details>
  <summary>JsonExport</summary>
  Retourne une représentation Json de l'élément.
</details>
<details>
  <summary>Display</summary>
  Ajoute une représentation textuelle de l'élément au flux passé en argument, en prenant en compte le chemin passé en argument.
</details>
<details>
  <summary>SetField</summary>
  Essaie d'appliquer la valeur passée en argument au champ référencé par le chemin passé en argument. Si la valeur ne peut pas être parsée vers le
  type du champ, crash l'application.
</details>
<details>
  <summary>Prompt</summary>
  Change la valeur du champ référencé par le chemin passé en indice. Peut demander une saisie si le champ est de type string, ou numérique non borné.
</details>
<details>
  <summary>Erase</summary>
  Efface l'élément référencé par le chemin passé en argument, si cela fait sens (ex: impossible de supprimer les statistiques d'une créature).
</details>
