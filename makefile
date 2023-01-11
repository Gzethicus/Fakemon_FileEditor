JSON = -ljsoncpp
CLI = -lncurses
BMAIN = -o file-editor build/main.o
BUILD = -o build/main.o -c src/main
BUILCOMP = g++ ${BMAIN} ${BELEMENTS} ${BPACKAGE} ${JSON} ${CLI}
B = mkdir -p build

BPACKAGE = build/Package.o
BEXPLORER = build/PackageExplorer.o
BEF = build/Aura.o
BMO = build/Move.o
BTR = build/Trigger.o
BIT = build/Item.o
BTY = build/Type.o
BCR = build/Creature.o
BELEMENTS = ${BEF} ${BMO} ${BTR} ${BIT} ${BTY} ${BCR}

OELEMENTS = Aura.o Move.o Trigger.o Item.o Type.o Creature.o

HPA = src/Package.hpp
HEF = src/Aura.hpp
HMO = src/Move.hpp
HTR = src/Trigger.hpp
HIT = src/Item.hpp
HTY = src/Type.hpp
HCR = src/Creature.hpp
HELEMENTS = ${HEF} ${HMO} ${HTR} ${HIT} ${HTY} ${HCR}

all: Package.o PackageExplorer.o ${OELEMENTS} main.o
	g++ ${BMAIN} ${BPACKAGE} ${BEXPLORER} ${BELEMENTS} ${JSON} ${CLI}

main.o: src/PackageExplorer.hpp ${HELEMENTS}
	$B
	g++ ${BUILD}.cpp

PackageExplorer.o: src/PackageExplorer.hpp
	$B
	g++ -o ${BEXPLORER} -c src/PackageExplorer.cpp

Package.o: ${OELEMENTS} ${HELEMENTS} ${HPA}
	$B
	g++ -o ${BPACKAGE} -c src/Package.cpp


Auras: Aura.o main_Aura.o Package.o
	${BUILCOMP}

main_Aura.o:
	$B
	g++ ${BUILD}_Aura.cpp

Aura.o: ${HEF}
	$B
	g++ -o ${BEF} -c src/Aura.cpp


Moves: Move.o main_Move.o Package.o
	${BUILCOMP}

main_Move.o:
	$B
	g++ ${BUILD}_Move.cpp

Move.o: ${HMO}
	$B
	g++ -o ${BMO} -c src/Move.cpp


Triggers: Trigger.o main_Trigger.o Package.o
	${BUILCOMP}

main_Trigger.o: ${HTRIGGERS}
	$B
	g++ ${BUILD}_Trigger.cpp

Trigger.o: src/Trigger.hpp
	$B
	g++ -o ${BTR} -c src/Trigger.cpp


Items: Item.o main_Item.o Package.o
	${BUILCOMP}

main_Item.o: ${HITEM}
	$B
	g++ ${BUILD}_Item.cpp

Item.o: src/Item.hpp
	$B
	g++ -o ${BIT} -c src/Item.cpp


Types: Type.o main_Type.o Package.o
	${BUILCOMP}

main_Type.o: ${HTYPE}
	$B
	g++ ${BUILD}_Type.cpp

Type.o: src/Type.hpp
	$B
	g++ -o ${BTY} -c src/Type.cpp


Creatures: Creature.o main_Creature.o Package.o
	${BUILCOMP}

main_Creature.o: ${HCREATURE}
	$B
	g++ ${BUILD}_Creature.cpp

Creature.o: src/Creature.hpp
	$B
	g++ -o ${BCR} -c src/Creature.cpp
