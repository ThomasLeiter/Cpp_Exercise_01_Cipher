LINKER := g++ -Wall

COMPILER := g++ -c -Wall

OBJ := main.o SimpleCaesar.o ExtendedCaesar.o Cipher.o

EXE := app.exe

CLEAN := del $(EXE) $(OBJ)

# Test the code by building and running. 
# Afterwards, all machine code and the exe 
# will be deleted.
test: $(OBJ)
	$(LINKER) $(OBJ) -o $(EXE)
	./$(EXE)
	$(CLEAN)

# Link all objects to build the exe
build: $(OBJ)
	$(LINKER) $(OBJ) -o $(EXE)

# Targets for compilation
# For all objects, create a target %.o with requirements %.cpp
# $@ refers to target, $< refers to corresponding requirement
# e.g. object main.o leads to
# main.o : main.cpp
# 	$(COMPILER) -o main.o main.cpp
$(OBJ): %.o : %.cpp
	$(COMPILER) -o $@ $<

# Clean up
clean:
	$(CLEAN)