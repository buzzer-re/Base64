SRC    = src/*
FOLDER = bin
TARGET = $(FOLDER)/b64
CC     = g++


all:
	@rm -rf $(FOLDER)
	@mkdir -p $(FOLDER)
	$(CC) -o $(TARGET) $(SRC)
