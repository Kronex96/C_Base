SRCS += mydir.c
LIBNAME += libmydir.so

all:
	gcc $(SRCS) -o $(LIBNAME) -shared -fPIC

install:
	cp $(LIBNAME) /usr/lib
	cp mydir.h /usr/include

uninstall:
	rm -f /usr/lib/$(LIBNAME) /usr/include/mydir.h

clean:
	rm -f $(LIBNAME) *.o