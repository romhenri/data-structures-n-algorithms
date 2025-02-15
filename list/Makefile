# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -Wextra -std=c++11

# Nome do arquivo fonte e executável
SRC = array-list.cpp
OBJ = array-list.o
EXEC = array-list

# Regra principal (compila tudo)
all: $(EXEC)

# Regra para compilar o executável
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# Regra para compilar o código fonte em um objeto
$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC)

# Limpa arquivos compilados
clean:
	rm -f $(OBJ) $(EXEC)

# Regra para rodar o programa (depois de compilar)
run: all
	./$(EXEC)
