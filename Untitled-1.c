#include <stdio.h>
#include <math.h> 
#include <assert.h>

const int AnyRoot = -1;

int SolveSquare(double a, double b, double c, double* x1, double* x2);
int RunTest(int nTest, double a, double b, double c, double x1_expected, double x2_expected, double nRoots_expected );
void Print_Roots(int nRoots, double x1, double x2);


int main()
{
    printf("Square eguation solver\n");
    printf("Enter a,b,c:");

    double a=NAN, b=NAN, c=NAN;

    // scanf("%lg %lg %lg", &a,  &b, &c);


    double x1 = NAN, x2 = NAN;
    
    RunTest(1, 1, 0, -4, 2, -2, 2);
    RunTest(2, 0, 0, 0, 0, 0, Any_Root);

    int nRoots = SolveSquare(a, b, c, &x1, &x2);

    Print_Roots(nRoots, x1, x2);
    
    return 0;  
}


int SolveSquare(double a, double b, double c, double* x1, double* x2)
{
    if (a == 0) 
    {
        if (b == 0)
        {
            if (c == 0)
            {
                return AnyRoot;
            }
            else
            {
            return 0;
            }
        }
        else 
        {
            *x1 = -c/b;
            return 1; 
        }
    }
    else
    {
        double D = b*b - 4*a*c;
        if (D < 0)
        {
            return 0;
        }
        else if (D == 0)
        {
            *x1 = -b / (2*a);
            return 1;
        }
        else if (D > 0)
        {
            *x1 = (-b + sqrt(D))/(2*a);
            *x2 = (-b - sqrt(D))/(2*a);
            return 2;
        }
    }
    
}


int Print_Roots(int nRoots, double x1, double x2)
{
    switch(nRoots)
    {
        case AnyRoot:
            printf("Any Number");
            break;
        case 0:
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


int RunTest(int nTest, double a, double b, double c, double x1_expected, double x2_expected, double nRoots_expected )
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(a, b, c, &x1, &x2);
    if (nRoots != nRoots_expected || x1 != x1_expected || x2 != x2_expected)
    {
        printf("ERROR Test%d, a=%lg, b=%lg, c=%lg, x1=%lg, x2=%lg, nRoots=%d\n"
        "EXPECTED: x1=%lg, x2=%lg, nRoots=%d", nTest, a, b, c, x1, x2, nRoots, x1_expected, x2_expected, nRoots_expected);
    } 
}

