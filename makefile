EXECUTABLE   		:= $(shell basename $(shell pwd))
LIB_DIR_PATH 		:= lib
LIB_INC_PATH 		:= inc
BUILD_ROOT   		:= build
DEBUG_BUILD_ROOT   	:= $(BUILD_ROOT)/debug
RELEASE_BUILD_ROOT 	:= $(BUILD_ROOT)/release

all:
	echo $(EXECUTABLE)
