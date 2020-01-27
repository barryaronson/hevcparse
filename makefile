objects = main.o nal_unit.o

ifeq ($(MAKECMDGOALS), debug)
target = hevcparse
CXXFLAGS = -Og -g -std=c++17
LFLAGS = -g
else ifeq ($(MAKECMDGOALS), release)
target = hevcparse
CXXFLAGS = -Ofast -g -std=c++17
LFLAGS = -g
else ifeq ($(MAKECMDGOALS), debug_switch)
target = hevcparse_switch
CXXFLAGS = -Og -g -std=c++17 -DNAL_UNIT_USE_SWITCH
LFLAGS = -g
else ifeq ($(MAKECMDGOALS), release_switch)
target = hevcparse_switch
CXXFLAGS = -Ofast -g -std=c++17 -DNAL_UNIT_USE_SWITCH
LFLAGS = -g
endif

release: $(target)

debug: $(target)

release_switch: $(target)

debug_switch: $(target)

clean:
	rm -f *.o

$(target): $(objects) makefile
	g++ $(LFLAGS) $(objects) -o $@

main.o: nal_unit.h makefile

nal_unit.o: nal_unit.h makefile
