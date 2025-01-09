CC = gcc

CFLAGS = -c -Wall -Wextra

#Directories
INCLUDE_DIR = ../../include

BUILD_DIR = ../../build

#Public APIs
API_INTERFACE = $(INCLUDE_DIR)/interface/interface.h

API_UTILS = $(INCLUDE_DIR)/utils/utils.h

#Private APIs
API_INTERFACE_INTERNAL = interface_internal.h


#Default rule
all: interface.o message_interface.o


interface.o: $(API_INTERFACE) $(API_UTILS) $(API_INTERFACE_INTERNAL) message_interface.o
	$(CC) $(CFLAGS) interface.c -o $(BUILD_DIR)/interface.o
	


message_interface.o: $(API_INTERFACE_INTERNAL)
	$(CC) $(CFLAGS) message_interface.c -o $(BUILD_DIR)/message_interface.o
