
all: 
	cd src;
	make

lin64:
	cd ./src;\
	make libjaggame.a

win32: 
	cd src; make libjaggamewin32.a

win64:
	cd src;
	make libjaggamewin64.a
