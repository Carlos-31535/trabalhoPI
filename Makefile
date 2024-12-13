OBJ_DIR := obj
SRC_DIR := src

TrabPratico.exe: $(OBJ_DIR)/main.o 
	gcc $(OBJ_DIR)/main.o 

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c | $(OBJ_DIR)
	gcc -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
