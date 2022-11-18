JSON = -ljsoncpp
BEFFECTS = build/Effect.o build/EffectPackage.o
BMOVES = build/Move.o build/MovePackage.o
BTRIGGERS = build/Trigger.o build/TriggerPackage.o
BITEM = build/Item.o build/ItemPackage.o
BTYPE = build/Type.o build/TypePackage.o
BMAIN = -o file-editor build/main.o

HEFFECTS = src/Effect.hpp src/EffectPackage.hpp
HMOVES = src/Move.hpp src/MovePackage.hpp
HTRIGGERS = src/Trigger.hpp src/TriggerPackage.hpp
HITEM = src/Item.hpp src/ItemPackage.hpp
HTYPE = src/Type.hpp src/TypePackage.hpp

OEFFECTS = Effect.o EffectPackage.o
OMOVES = Move.o MovePackage.o
OTRIGGERS = Trigger.o TriggerPackage.o
OITEM = Item.o ItemPackage.o
OTYPE = Type.o TypePackage.o

BUILD = -o build/main.o -c src/main
B = mkdir -p build

all: ${OEFFECTS} ${OMOVES} ${OTRIGGERS} ${OITEM} ${OTYPE} main.o
	g++ ${BMAIN} ${BEFFECTS} ${BMOVES} ${BTRIGGERS} ${BITEM} ${BTYPE} ${JSON}

main.o: ${HEFFECTS} ${HMOVES} ${HTRIGGERS} ${HITEM} ${HTYPE}
	${B}
	g++ ${BUILD}.cpp


Effects: ${OEFFECTS} main_Effect.o
	g++ ${BMAIN} ${BEFFECTS} ${JSON}

main_Effect.o: ${HEFFECTS}
	${B}
	g++ ${BUILD}_Effect.cpp

Effect.o: src/Effect.hpp
	${B}
	g++ -o build/Effect.o -c src/Effect.cpp

EffectPackage.o: src/EffectPackage.hpp src/IPackage.hpp
	${B}
	g++ -o build/EffectPackage.o -c src/EffectPackage.cpp


Moves: ${OMOVES} main_Move.o
	g++ ${BMAIN} ${BMOVES} ${JSON}

main_Move.o: ${HMOVES}
	${B}
	g++ ${BUILD}_Move.cpp

Move.o: src/Move.hpp
	${B}
	g++ -o build/Move.o -c src/Move.cpp

MovePackage.o: src/MovePackage.hpp src/IPackage.hpp
	${B}
	g++ -o build/MovePackage.o -c src/MovePackage.cpp


Triggers: ${OTRIGGERS} main_Trigger.o
	g++ ${BMAIN} ${BTRIGGERS} ${JSON}

main_Trigger.o: ${HTRIGGERS}
	${B}
	g++ ${BUILD}_Trigger.cpp

Trigger.o: src/Trigger.hpp
	${B}
	g++ -o build/Trigger.o -c src/Trigger.cpp

TriggerPackage.o: src/TriggerPackage.hpp src/IPackage.hpp
	${B}
	g++ -o build/TriggerPackage.o -c src/TriggerPackage.cpp


Items: ${OITEM} main_Item.o
	g++ ${BMAIN} ${BITEM} ${JSON}

main_Item.o: ${HITEM}
	${B}
	g++ ${BUILD}_Item.cpp

Item.o: src/Item.hpp
	${B}
	g++ -o build/Item.o -c src/Item.cpp

ItemPackage.o: src/ItemPackage.hpp src/IPackage.hpp
	${B}
	g++ -o build/ItemPackage.o -c src/ItemPackage.cpp


Types: ${OTYPE} main_Type.o
	g++ ${BMAIN} ${BTYPE} ${JSON}

main_Type.o: ${HTYPE}
	${B}
	g++ ${BUILD}_Type.cpp

Type.o: src/Type.hpp
	${B}
	g++ -o build/Type.o -c src/Type.cpp

TypePackage.o: src/TypePackage.hpp src/IPackage.hpp
	${B}
	g++ -o build/TypePackage.o -c src/TypePackage.cpp
