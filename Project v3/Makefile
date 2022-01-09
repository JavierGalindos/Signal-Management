# Use C++11, dont warn on long-to-float conversion
CXXFLAGS += -std=c++11 -Wno-conversion

# Default to using system's default version of python
PYTHON_BIN     ?= python3
PYTHON_CONFIG  := $(PYTHON_BIN)-config
PYTHON_INCLUDE ?= $(shell $(PYTHON_CONFIG) --includes)
EXTRA_FLAGS    := $(PYTHON_INCLUDE)
# NOTE: Since python3.8, the correct invocation is `python3-config --libs --embed`.
# So of course the proper way to get python libs for embedding now is to
# invoke that, check if it crashes, and fall back to just `--libs` if it does.
LDFLAGS        += $(shell if $(PYTHON_CONFIG) --ldflags --embed >/dev/null; then $(PYTHON_CONFIG) --ldflags --embed; else $(PYTHON_CONFIG) --ldflags; fi)

# Either finds numpy or set -DWITHOUT_NUMPY
EXTRA_FLAGS     += $(shell $(PYTHON_BIN) $(CURDIR)/numpy_flags.py)
WITHOUT_NUMPY   := $(findstring $(EXTRA_FLAGS), WITHOUT_NUMPY)


Project: main.cpp FileManagement.cpp SquareWave.cpp UI.cpp
	$(CXX) $(EXTRA_FLAGS) $(CXXFLAGS) $(LDFLAGS)	-o Project main.cpp FileManagement.cpp SquareWave.cpp UI.cpp


clean:
	rm -f main
