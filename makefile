JSON = -ljsoncpp
BMAIN = -o file-editor build/main.o
BUILD = -o build/main.o -c src/main
B = mkdir -p build

BEFFECTS = build/Effect.o build/EffectPackage.o
BMOVES = build/Move.o build/MovePackage.o
BTRIGGERS = build/Trigger.o build/TriggerPackage.o
BITEM = build/Item.o build/ItemPackage.o
BTYPE = build/Type.o build/TypePackage.o
BCREATURE = build/Creature.o build/CreaturePackage.o

HEFFECTS = src/Effect.hpp src/EffectPackage.hpp
HMOVES = src/Move.hpp src/MovePackage.hpp
HTRIGGERS = src/Trigger.hpp src/TriggerPackage.hpp
HITEM = src/Item.hpp src/ItemPackage.hpp
HTYPE = src/Type.hpp src/TypePackage.hpp
HCREATURE = src/Creature.hpp src/CreaturePackage.hpp

OEXPLORER = PackageExplorer.o 
OEFFECTS = Effect.o EffectPackage.o
OMOVES = Move.o MovePackage.o
OTRIGGERS = Trigger.o TriggerPackage.o
OITEM = Item.o ItemPackage.o
OTYPE = Type.o TypePackage.o
OCREATURE = Creature.o CreaturePackage.o

all: PackageExplorer.o ${OEFFECTS} ${OMOVES} ${OTRIGGERS} ${OITEM} ${OTYPE} ${OCREATURE} main.o
	g++ ${BMAIN} build/PackageExplorer.o ${BEFFECTS} ${BMOVES} ${BTRIGGERS} ${BITEM} ${BTYPE} ${BCREATURE} ${JSON}

main.o: src/PackageExplorer.hpp ${HEFFECTS} ${HMOVES} ${HTRIGGERS} ${HITEM} ${HTYPE} ${HCREATURE}
	$B
	g++ ${BUILD}.cpp

PackageExplorer.o: src/PackageExplorer.hpp
	$B
	g++ -o build/PackageExplorer.o -c src/PackageExplorer.cpp


Effects: ${OEFFECTS} main_Effect.o
	g++ ${BMAIN} ${BEFFECTS} ${JSON}

main_Effect.o: ${HEFFECTS}
	$B
	g++ ${BUILD}_Effect.cpp

Effect.o: src/Effect.hpp
	$B
	g++ -o build/Effect.o -c src/Effect.cpp

EffectPackage.o: src/EffectPackage.hpp src/IPackage.hpp
	$B
	g++ -o build/EffectPackage.o -c src/EffectPackage.cpp


Moves: ${OMOVES} main_Move.o
	g++ ${BMAIN} ${BMOVES} ${JSON}

main_Move.o: ${HMOVES}
	$B
	g++ ${BUILD}_Move.cpp

Move.o: src/Move.hpp
	$B
	g++ -o build/Move.o -c src/Move.cpp

MovePackage.o: src/MovePackage.hpp src/IPackage.hpp
	$B
	g++ -o build/MovePackage.o -c src/MovePackage.cpp


Triggers: ${OTRIGGERS} main_Trigger.o
	g++ ${BMAIN} ${BTRIGGERS} ${JSON}

main_Trigger.o: ${HTRIGGERS}
	$B
	g++ ${BUILD}_Trigger.cpp

Trigger.o: src/Trigger.hpp
	$B
	g++ -o build/Trigger.o -c src/Trigger.cpp

TriggerPackage.o: src/TriggerPackage.hpp src/IPackage.hpp
	$B
	g++ -o build/TriggerPackage.o -c src/TriggerPackage.cpp


Items: ${OITEM} main_Item.o
	g++ ${BMAIN} ${BITEM} ${JSON}

main_Item.o: ${HITEM}
	$B
	g++ ${BUILD}_Item.cpp

Item.o: src/Item.hpp
	$B
	g++ -o build/Item.o -c src/Item.cpp

ItemPackage.o: src/ItemPackage.hpp src/IPackage.hpp
	$B
	g++ -o build/ItemPackage.o -c src/ItemPackage.cpp


Types: ${OTYPE} main_Type.o
	g++ ${BMAIN} ${BTYPE} ${JSON}

main_Type.o: ${HTYPE}
	$B
	g++ ${BUILD}_Type.cpp

Type.o: src/Type.hpp
	$B
	g++ -o build/Type.o -c src/Type.cpp

TypePackage.o: src/TypePackage.hpp src/IPackage.hpp
	$B
	g++ -o build/TypePackage.o -c src/TypePackage.cpp


Creatures: ${OCREATURE} main_Creature.o
	g++ ${BMAIN} ${BCREATURE} ${JSON}

main_Creature.o: ${HCREATURE}
	$B
	g++ ${BUILD}_Creature.cpp

Creature.o: src/Creature.hpp
	$B
	g++ -o build/Creature.o -c src/Creature.cpp

CreaturePackage.o: src/CreaturePackage.hpp src/IPackage.hpp
	$B
	g++ -o build/CreaturePackage.o -c src/CreaturePackage.cpp
