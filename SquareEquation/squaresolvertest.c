#include <stdio.h>
#include <math.h> 
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "testfiles.h"
#include "SolveFiles.h"

bool Find_t(int count,const char* arr[]);

int main(int argc, const char* argv[])
{
    printf("Enter '-t' if you want to run test\n"
    "Press 'Enter' if you want to run Square equation solver\n");
    
    if(Find_t(argc, argv))
    {
        UnitTester();
    }
    else
    {
        SquareEquationSolver();    
    }
    
    return 0;  
}


bool Find_t(int count,const char* arr[])
{
    for(int i = 0; i < count; i++)
    {
        if (!strcmp(arr[i], "-t"))
        {
            return true;
        }
    }
    return false;
}

