CC = g++
CFLAGS = -g -c 
#DBFLAG = -DDEBUG
DBFLAG = 
LDFLAG = -o 

HackAssembler: HackAssembler.o Parser.o  Code.o SymbolTable.o
	$(CC) $(LDFLAG) HackAssembler HackAssembler.o Parser.o  Code.o SymbolTable.o

HackAssembler.o: HackAssembler.cpp 
	$(CC) $(CFLAGS) $(DBFLAG) HackAssembler.cpp

Parser.o: Parser.cpp Parser.h
	$(CC) $(CFLAGS) $(DBFLAG) Parser.cpp

Code.o: Code.cpp Code.h
	$(CC) $(CFLAGS) $(DBFLAG) Code.cpp

SymbolTable.o: SymbolTable.cpp SymbolTable.h
	$(CC) $(CFLAGS) $(DBFLAG) SymbolTable.cpp

clean:
	- rm *.o
	- rm HackAssembler

run:
	./HackAssembler
