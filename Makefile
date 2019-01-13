#
# rtrace Makefile
#

CXX=g++
CPPFLAGS=-g
CFLAGS=-Wall
LDFLAGS=-g
LDLIBS=
RM=rm -f

BINARY=traycer
SRCS=main.cc objcollection.cc object.cc ray.cc sphere.cc vec3.cc 
OBJS=$(subst .cc,.o,$(SRCS))

all: $(BINARY)

rtrace: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(BINARY) $(OBJS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) $(BINARY)

# vim:ft=make
#
