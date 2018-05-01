SRC    = src/*
TARGET = bin/b64
CC     = g++


all:
	$(CC) -o $(TARGET) $(SRC)
