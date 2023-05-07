export COMPILER := gcc
export EXE_FILE := map
export SOURCE_FILES := $(wildcard *.cpp)
export DEP_FOLDER := DEPS
export OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))
export DEP_FILES := $(patsubst %.cpp, $(DEP_FOLDER)/%.dep, $(SOURCE_FILES))


.PHONY: run
run : $(EXE_FILE)
	./map

$(EXE_FILE) : $(OBJ_FILES)
	$(COMPILER) $^ -lm -lstdc++ -o $@

%.o :
	$(COMPILER) -c $< -o $@

$(DEP_FOLDER)/%.dep : %.cpp
	mkdir -p $(DEP_FOLDER)
	$(COMPILER) -M $< -o $@

ifneq ($(MAKECMDGOALS),clean)
    -include $(DEP_FILES)
endif

.PHONY: clean
clean:
	rm -rf $(OBJ_FILES) $(DEP_FOLDER) $(EXE_FILE)
