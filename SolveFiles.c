#include <stdio.h>
#include <math.h> 
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "SolveFiles.h"

void SquareEquationSolver()
{
    printf("Square equation solver\n");
    printf("Enter a,b,c:");
            
    double a=NAN, b=NAN, c=NAN;
    int nDigits = scanf("%lg %lg %lg", &a,  &b, &c);  

    if (nDigits != 3)
    {
        printf("ERROR! \n");
        return;
    }
            
    double x1 = NAN, x2 = NAN;
    int nRoots = SolveSquare(a, b, c, &x1, &x2);

    Print_Roots(nRoots, x1, x2);
}


bool DoubleEquality(double x, double y)
{
    if (isnan(x))
    {
        return isnan(y);
    }


    if ((abs(x - y)) <= Delta)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int SolveSquare(double a, double b, double c, double* x1, double* x2)
{
    assert(x1 != x2);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    
    if (DoubleEquality(a, 0)) 
    {
        if (DoubleEquality(b, 0))
        {
            if (DoubleEquality(c, 0))
            {
                return AnyRoot;
            }
            else
            {
                return No_Real_Roots;
            }
        }
        else 
        {
            *x1 = *x2 = -c/b;
            return 1; 
        }
    }
    else
    {
        double D = b*b - 4*a*c;
        if (D < 0)
        {
            return No_Real_Roots;
        }
        else if (DoubleEquality(D, 0))
        {
            *x1 = *x2 = -b / (2*a);
            return 1;
        }
        else if (D > 0)
        {
            *x1 = (-b + sqrt(D))/(2*a);
            *x2 = (-b - sqrt(D))/(2*a);
            return 2;
        }
    }
    return 0;
}



void Print_Roots(int nRoots, double x1, double x2)
{
    switch(nRoots)
    {
        case AnyRoot:
            printf("Any Number");
            break;
        case No_Real_Roots:
            printf("No real roots\n");
            break;
        case 1:
            printf("x = %lg", x1);
            break;
        case 2:
            printf("x1 = %lg, x2 = %lg", x1, x2);
            break;
        default: 
            printf("Error");
    }
}