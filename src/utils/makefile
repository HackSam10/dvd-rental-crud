CC = gcc

CFLAGS = -c

#Directories
INCLUDE_DIR = ../../include

BUILD_DIR = ../../build

#Public APIs

API_UTILS = $(INCLUDE_DIR)/utils/utils.h


#Private API
API_UTILS_INTERNAL = utiuls_internal.h


#Default rule
all: utils.o message_utils.o


utils.o: $(API_UTILS) $(API_UTILS_INTERNA)
	$(CC) $(CFLAGS) utils.c -o $(BUILD_DIR)/utils.o
	
message_utils.o: $(API_UTILS_INTERNA)
	$(CC) $(CFLAGS) message_utils.c -o $(BUILD_DIR)/message_utils.o
