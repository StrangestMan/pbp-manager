#!/usr/bin/env make -f

compile: build/Makefile
	$(MAKE) -C build

build/Makefile:
	-mkdir build
	cd build && qmake ../src

clean: build/Makefile
	$(MAKE) -C build clean

distclean: build/Makefile
	$(MAKE) -C build distclean

install: build/Makefile
	$(MAKE) -c build install

.PHONY: all clean compile distclean install
