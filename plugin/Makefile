__start__: obj ../libs/libInterp4Move.so ../libs/libInterp4Set.so\
	../libs/libInterp4Rotate.so ../libs/libInterp4Pause.so
	@echo "Tworzenie wtyczek zakonczone"

obj:
	mkdir obj

CPPFLAGS=-Wall -fPIC -pedantic -std=c++17 -Iinc -I../inc
LDFLAGS=-Wall -shared

__lines_for_space__:
	@echo
	@echo
	@echo
	@echo
	@echo

../libs/libInterp4Move.so: obj/Interp4Move.o
	g++ ${LDFLAGS} -o ../libs/libInterp4Move.so obj/Interp4Move.o
	@echo "Wtyczka dla polecenia 'Move' zostala utworzona"

../libs/libInterp4Set.so: obj/Interp4Set.o
	g++ ${LDFLAGS} -o ../libs/libInterp4Set.so obj/Interp4Set.o
	@echo "Wtyczka dla polecenia 'Set' zostala utworzona"

../libs/libInterp4Rotate.so: obj/Interp4Rotate.o
	g++ ${LDFLAGS} -o ../libs/libInterp4Rotate.so obj/Interp4Rotate.o
	@echo "Wtyczka dla polecenia 'Rotate' zostala utworzona"

../libs/libInterp4Pause.so: obj/Interp4Pause.o
	g++ ${LDFLAGS} -o ../libs/libInterp4Pause.so obj/Interp4Pause.o
	@echo "Wtyczka dla polecenia 'Pause' zostala utworzona"

obj/Interp4Move.o: src/Interp4Move.cpp ../inc/Interp4Command.hpp\
                        inc/Interp4Move.hpp
	g++ -c ${CPPFLAGS} -o obj/Interp4Move.o src/Interp4Move.cpp

obj/Interp4Set.o: src/Interp4Set.cpp ../inc/Interp4Command.hpp\
                        inc/Interp4Set.hpp
	g++ -c ${CPPFLAGS} -o obj/Interp4Set.o src/Interp4Set.cpp

obj/Interp4Rotate.o: src/Interp4Rotate.cpp ../inc/Interp4Command.hpp\
                        inc/Interp4Rotate.hpp
	g++ -c ${CPPFLAGS} -o obj/Interp4Rotate.o src/Interp4Rotate.cpp

obj/Interp4Pause.o: src/Interp4Pause.cpp ../inc/Interp4Command.hpp\
                        inc/Interp4Pause.hpp
	g++ -c ${CPPFLAGS} -o obj/Interp4Pause.o src/Interp4Pause.cpp

clean:
	rm -f obj/*

cleanall: clean
	find . -name \*~ -print -exec rm {} \;
