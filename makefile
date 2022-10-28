all: main.o Effect.o EffectPackage.o
	g++ -o file-editor build/main.o build/Effect.o build/EffectPackage.o

main.o: src/Effect.hpp src/EffectPackage.hpp
	mkdir -p build
	g++ -o build/main.o -c src/main.cpp

Effect.o: src/Effect.hpp
	mkdir -p build
	g++ -o build/Effect.o -c src/Effect.cpp

EffectPackage.o: src/EffectPackage.hpp src/Package.hpp
	mkdir -p build
	g++ -o build/EffectPackage.o -c src/EffectPackage.cpp 
