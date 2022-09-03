LINKER = g++

COMPILER = g++ -c

OBJ = main.o SimpleCaesar.o ExtendedCaesar.o 

EXE = app.exe

test: $(EXE)
	./$(EXE)

app: $(OBJ)
	$(LINKER) $(OBJ) -o $(EXE)

$(OBJ): %.o : %.cpp
	$(COMPILER) -o $@ $<

clean:
	del $(EXE)
	del $(OBJ)