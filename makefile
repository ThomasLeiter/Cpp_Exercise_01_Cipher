LINKER = g++

COMPILER = g++ -c

OBJ = main.o SimpleCaesar.o ExtendedCaesar.o 

app: $(OBJ)
	$(LINKER) $(OBJ) -o app.exe

$(OBJ): %.o : %.cpp
	$(COMPILER) -o $@ $<