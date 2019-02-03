#
# rtrace Makefile
#

CXX=clang++
CXXFLAGS=-g -std=c++11 -Wall -Wextra -pedantic -O3
LDFLAGS=-g
LDLIBS=
RM=rm
BINARY=traycer
BUILD_DIR=./build
SRCS=camera.cc dielectric.cc diffuselight.cc lambertian.cc main.cc material.cc metal.cc objcollection.cc object.cc ray.cc sphere.cc utils.cc vec3.cc
OBJS=$(SRCS:%.cc=$(BUILD_DIR)/%.o)
DEPS=$(OBJS:%.o=%.d)

all: $(BUILD_DIR)/$(BINARY)

$(BUILD_DIR)/$(BINARY): $(OBJS)
	mkdir -p $(@D)
	$(CXX) $(LDFLAGS) $^ -o $@

-include $(DEPS)

$(BUILD_DIR)/%.o: %.cc
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

.PHONY: clean
clean:
	$(RM) -f $(OBJS) $(DEPS)

distclean: clean
	$(RM) -f $(BUILD_DIR)/$(BINARY)

# vim:ft=make
#
