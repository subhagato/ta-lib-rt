# makefile for building a Python ta_lib.py module
# CMR (commandline multitheraded release only)
# Handmade (experimental)
#
# Tested with SWIG v1.3.24, Python v2.3.5

TOPDIR=../../../..
WRAPDIR=$(TOPDIR)/temp/python/wrap
TEMPDIR=$(TOPDIR)/temp/python/wrap
INSTDIR=/usr/local/lib/python2.3/site-packages

CPPFLAGS   = -I$(TOPDIR)/../c/include -I/usr/include/python2.3
CFLAGS     = -pipe -Wall -Wno-unused -O2 -fno-strict-aliasing -fPIC

####### Support for 64-bit systems
ifeq ($(shell uname -m), x86_64)
    CFLAGS   += -m64 -D__64BIT__
    ifeq ($(shell uname -r | cut -d- -f3-), amd64-k8)
        CFLAGS   += -march=k8
    else
        CFLAGS   += -march=x86-64
    endif
endif

CC         = gcc
LDFLAGS    = -shared -fPIC
LDLIBS     = -lpthread -lcurl

all: $(TOPDIR)/lib/python/_ta_lib.so $(TOPDIR)/lib/python/ta_lib.py

clean:
	rm -f $(WRAPDIR)/*.c
	rm -f $(WRAPDIR)/*.py
	rm -f $(TEMPDIR)/*.o

$(TOPDIR)/lib/python/_ta_lib.so: \
		$(TEMPDIR)/ta_libc_wrap.o \
		$(TOPDIR)/../c/lib/libta_libc_cmr.a
	$(CC) $(LDFLAGS) -o $@ $< \
		$(TOPDIR)/../c/lib/libta_libc_cmr.a $(LDLIBS)

$(TOPDIR)/lib/python/ta_lib.py: \
		$(WRAPDIR)/ta_lib.py
	cp $(WRAPDIR)/ta_lib.py $@

$(WRAPDIR)/ta_lib.py $(WRAPDIR)/ta_libc_wrap.c: \
		$(TOPDIR)/src/interface/ta_libc.swg \
		$(TOPDIR)/src/interface/ta_func.swg
	swig -python -module "ta_lib" -modern -Fstandard -o $(WRAPDIR)/ta_libc_wrap.c \
		-I$(TOPDIR)/src/interface -I$(TOPDIR)/../c/include \
		$<

install: $(INSTDIR)/_ta_lib.so $(INSTDIR)/ta_lib.py

$(INSTDIR)/_ta_lib.so: $(TOPDIR)/lib/python/_ta_lib.so
	cp -f $(TOPDIR)/lib/python/_ta_lib.so $(INSTDIR)/_ta_lib.so

$(INSTDIR)/ta_lib.py: $(TOPDIR)/lib/python/ta_lib.py
	cp -f $(TOPDIR)/lib/python/ta_lib.py $(INSTDIR)/ta_lib.py

.PHONY: all clean install