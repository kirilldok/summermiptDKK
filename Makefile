.PHONY : all run

all: squaresolvertest.exe 

CC := g++ 

CFLAG := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE 

Allo/%.o : %.c
	$(CC) $(CFLAG) $< -c -o $@

# squaresolvertest.o : squaresolvertest.c 
# 	$(CC) $(CFLAG) squaresolvertest.c -c -o squaresolvertest.o
#TestFiles.o : TestFiles.c 
#	$(CC) $(CFLAG) TestFiles.c -c -o TestFiles.o
#SolveFiles.o : SolveFiles.c
#	$(CC) $(CFLAG) SolveFiles.c -c -o SolveFiles.o

OBJECTS := Allo/squaresolvertest.o Allo/TestFiles.o Allo/SolveFiles.o

squaresolvertest.exe: $(OBJECTS)
	$(CC)  $(OBJECTS) -o squaresolvertest.exe 

run : squaresolvertest.exe
	squaresolvertest.exe
