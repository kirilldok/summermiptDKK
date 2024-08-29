/**
 * @file squaresolvertest.c, SolveFiles.c, TestFiles.c, SolveFiles.h, TestFiles.h
 * @author DKK (dokuchaev.kv@phystech.edu)
 * @brief 
 *  programm can solve square equations or run tests
 *  function UnitTester runs tests
 *  function RunTest compare programm resualts with tests and  outputs the differences if there are any
 *  function SquareEquationSolver reads input data and starts SolveSquare
 *  function SolveSquare solves equation and output namber of roots(nRoots)
 *  function PrintRoots in dependence of nRoots output the answers of equation
 *  function DoubleEquality compares double nambers
 *  function Find_t finds -t in the command line
 * @version 0.1
 * @date 2024-08-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

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

