LINKER = g++

COMPILER = g++ -c

OBJ = main.o SimpleCaesar.o ExtendedCaesar.o Cipher.o

EXE = app.exe

CLEAN = del $(EXE) $(OBJ)

test: $(OBJ)
	$(LINKER) $(OBJ) -o $(EXE)
	./$(EXE)
	$(CLEAN)

app: $(OBJ)
	$(LINKER) $(OBJ) -o $(EXE)

$(OBJ): %.o : %.cpp
	$(COMPILER) -o $@ $<

clean:
	$(CLEAN)