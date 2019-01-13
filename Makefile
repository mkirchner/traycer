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
SRCS=camera.cc lambertian.cc main.cc material.cc metal.cc objcollection.cc object.cc ray.cc sphere.cc utils.cc vec3.cc
OBJS=$(subst .cc,.o,$(SRCS))

all: $(BINARY)

traycer: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(BINARY) $(OBJS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) $(BINARY)

# vim:ft=make
#
