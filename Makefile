# __start__: obj interp __plugin__
__start__: obj xmlinterp4config __plugin__
	export LD_LIBRARY_PATH="./libs"
	# ./xmlinterp4config

obj:
	mkdir obj


__lines_for_space__:
	@echo
	@echo
	@echo
	@echo
	@echo


__plugin__:
	cd plugin; make

CPPFLAGS=-Wall -pedantic -std=c++17 -Iinc
LDFLAGS=-Wall

xmlinterp4config: obj/LibInterface.o obj/Handlers.o obj/main.o obj/Set4LibInterfaces.o obj/ProgramInterpreter.o obj/xmlinterp.o
	g++ ${LDFLAGS} -o xmlinterp4config  obj/main.o obj/LibInterface.o obj/Handlers.o obj/Set4LibInterfaces.o\
	 obj/ProgramInterpreter.o obj/xmlinterp.o -lxerces-c

interp: obj/LibInterface.o obj/Handlers.o obj/main.o obj/Set4LibInterfaces.o obj/ProgramInterpreter.o
	g++ ${LDFLAGS} -o interp  obj/main.o obj/LibInterface.o obj/Handlers.o obj/Set4LibInterfaces.o obj/ProgramInterpreter.o -ldl

obj/Handlers.o: inc/Handlers.hpp src/Handlers.cpp
	g++ -c ${CPPFLAGS} -o obj/Handlers.o src/Handlers.cpp

obj/LibInterface.o: inc/LibInterface.hpp inc/Interp4Command.hpp src/LibInterface.cpp inc/Handlers.hpp inc/MobileObj.hpp
	g++ -c ${CPPFLAGS} -o obj/LibInterface.o src/LibInterface.cpp

obj/ProgramInterpreter.o: inc/ProgramInterpreter.hpp src/ProgramInterpreter.cpp
	g++ -c ${CPPFLAGS} -o obj/ProgramInterpreter.o src/ProgramInterpreter.cpp

obj/Set4LibInterfaces.o: inc/Set4LibInterfaces.hpp src/Set4LibInterfaces.cpp
	g++ -c ${CPPFLAGS} -o obj/Set4LibInterfaces.o src/Set4LibInterfaces.cpp

obj/xmlinterp.o: src/xmlinterp.cpp inc/xmlinterp.hpp
	g++ -c ${CPPFLAGS} -o obj/xmlinterp.o src/xmlinterp.cpp

obj/main.o: src/main.cpp inc/Interp4Command.hpp inc/LibInterface.hpp inc/Handlers.hpp
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/* interp core*


clean_plugin:
	cd plugin; make clean

cleanall: clean
	cd plugin; make cleanall
	cd dox; make cleanall
	rm -f libs/*
	find . -name \*~ -print -exec rm {} \;

help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  clean    - usuwa produkty kompilacji oraz program"
	@echo "  clean_plugin - usuwa plugin"
	@echo "  cleanall - wykonuje wszystkie operacje dla podcelu clean oraz clean_plugin"
	@echo "             oprocz tego usuwa wszystkie kopie (pliki, ktorych nazwa "
	@echo "             konczy sie znakiem ~)."
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo
 
