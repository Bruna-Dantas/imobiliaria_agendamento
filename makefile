CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
OBJ = main.o corretor.o cliente.o imovel.o pessoa.o agendamentos.o
EXEC = imobiliaria

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

main.o: main.cpp corretor.h cliente.h imovel.h agendamentos.h
corretor.o: corretor.cpp corretor.h pessoa.h
cliente.o: cliente.cpp cliente.h pessoa.h
imovel.o: imovel.cpp imovel.h
pessoa.o: pessoa.cpp pessoa.h
agendamentos.o: agendamentos.cpp agendamentos.h corretor.h imovel.h

clean:
	rm -f *.o $(EXEC)
