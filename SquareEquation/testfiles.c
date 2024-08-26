#include <stdio.h>
#include <math.h> 
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "SolveFiles.h"
#include "testfiles.h"

void UnitTester()
{
    const int nTests = 10;
    
    DataTest ArrDataTest[nTests] = {{1, 1, 0, -4, 2, -2, 2}, {2, 0, 0, 0, NAN, NAN, AnyRoot}, {3, 0, 2, 0, 0 , 0, 1},
                                {4, 1, 2, 1, -1, -1, 1}, {5, 1, 2, -3, 1, -3, 2}, {6, 1, 2, 8, NAN, NAN, No_Real_Roots},
                                {7, 1, 2.321, 32, NAN, NAN, No_Real_Roots}, {8, 0, 2.321, -0.213, 0.0917708, 0.0917708, 1},
                                {9, -9.34623, 8882.321, -42.154, 0.00474586, 950.359305, 2}, 
                                {10, 0.00001, 0.999999, -0.9999999, 0.999991, -100000.89999, 2}};

    for (int i = 0; i < nTests; i++)
    {
        RunTest(ArrDataTest[i]);
    }
}


void RunTest(DataTest data)
{
    double x1 = NAN, x2 = NAN;
    int nRoots = SolveSquare(data.a, data.b, data.c, &x1, &x2);
    
    if (nRoots != data.nRoots_expected || (!DoubleEquality(x1, data.x1_expected)) || (!DoubleEquality(x2, data.x2_expected)))
    {
        printf("ERROR Test%d, a=%lg, b=%lg, c=%lg, x1=%lg, x2=%lg, nRoots=%d \n"
        "EXPECTED: x1=%lg, x2=%lg, nRoots=%d \n", data.nTest, data.a, data.b, data.c,
         x1, x2, nRoots, data.x1_expected, data.x2_expected, data.nRoots_expected);    
    } 
    else
    {
        printf("Test%d correct \n", data.nTest);
    }
}
