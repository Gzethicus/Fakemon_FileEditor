JSON = -ljsoncpp
BEFFECTS = build/Effect.o build/EffectPackage.o
BMOVES = build/Move.o build/MovePackage.o
BTRIGGERS = build/Trigger.o build/TriggerPackage.o
BMAIN = -o file-editor build/main.o

HEFFECTS = src/Effect.hpp src/EffectPackage.hpp
HMOVES = src/Move.hpp src/MovePackage.hpp
HTRIGGERS = src/Trigger.hpp src/TriggerPackage.hpp

OEFFECTS = Effect.o EffectPackage.o
OMOVES = Move.o MovePackage.o
OTRIGGERS = Trigger.o TriggerPackage.o

BUILD = -o build/main.o -c src/main
B = mkdir -p build

all: ${OEFFECTS} ${OMOVES} main.o
	g++ ${BMAIN} ${BEFFECTS} ${BMOVES} ${JSON}

main.o: ${HEFFECTS} ${HMOVES}
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
