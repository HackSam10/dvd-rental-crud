CC = gcc

CFLAGS = -c -Wall -Wextra

#Directories
INCLUDE_DIR = ../include

BUILD_DIR = ../build


#Public APIs
API_UTILS = $(INCLUDE_DIR)/utils/utils.h

API_INTERFACE = $(INCLUDE_DIR)/interface/interface.h

API_USER = $(INCLUDE_DIR)/user/user.h

API_RANKING = $(INCLUDE_DIR)/ranking/ranking.h

#Private APIs
API_MAIN = main.h


#Default rule
all: main.o message_main.o


main.o: $(API_MAIN) $(API_UTILS) $(API_INTERFACE) $(API_USER) $(API_RANKING)
	$(CC) $(CFLAGS) main.c -o $(BUILD_DIR)/main.o
	

message_main.o: $(API_MAIN)
	$(CC) $(CFLAGS) message_main.c -o $(BUILD_DIR)/message_main.o
