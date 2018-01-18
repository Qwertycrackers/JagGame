#A library built to contain the reusable work of Joseph Gerardot with the SDL2 library

CC = g++

win32CC = /opt/mingw32/bin/i686-w64-mingw32-g++

win64CC = /opt/mingw64/bin/x86_64-w64-mingw32-g++

FLAGS = -c -std=c++11

win32FLAGS = -mwindows -std=c++11

win64FLAGS = -mwindows -std=c++11

LIBS = -lSDL2 -lSDL2_image

win32LIBS = -lmingw32 -lSDL2main

win64LIBS = -lmingw32 -lSDL2main

INCLUDE = -I../include

win32INCLUDE = 

win64INCLUDE = 

LIBS_BIN = 

win32LIBS_BIN = 

win64LIBS_BIN =


all: libjaggame.a libjaggamewin32.a libjaggamewin64.a

libjaggame.a: $(patsubst %.cpp,%lin64.o,$(wildcard *.cpp)) 
	ar rcs ../linux/$@ $^

libjaggamewin32.a: $(patsubst %.cpp,%win32.o,$(wildcard *.cpp))
	ar rcs ../win32/$@ $^

libjaggamewin64.a: $(patsubst %.cpp,%win64.o,$(wildcard *.cpp))
	ar rcs ../win64/$@ $^

%lin64.o: %.cpp ../include/%.h
	${CC} $< ${FLAGS} ${LIBS} ${INCLUDE} ${LIBS_BIN} -o $@

%win32.o: %.cpp ../include/%.h
	${win32CC} $< ${FLAGS} ${win32FLAGS} ${win32LIBS} ${LIBS} ${INCLUDE} ${win32INCLUDE} ${LIBS_BIN} ${win32LIBS_BIN} -o $@

%win64.o: %.cpp ../include/%.h
	${win64CC} $< ${FLAGS} ${win64FLAGS} ${win64LIBS} ${LIBS} ${INCLUDE} ${win64INCLUDE} ${LIBS_BIN} ${win64LIBS_BIN} -o $@

