#include <stdio.h>
#include <math.h> 
#include <assert.h>

const int AnyRoot = -1;
const int No_Real_Roots = 0;
const int Delta = 0.00000000001;
const bool TRUE = 1;
const bool FALSE = -2;

struct DataTest
{
    int nTest;
    double a, b, c;
    double x1_expected, x2_expected;
    int nRoots_expected;
};

int SolveSquare(double a, double b, double c, double* x1, double* x2);
void RunTest(DataTest data);
void UnitTester(double a, double b, double c);
void Print_Roots(int nRoots, double x1, double x2);
bool DoubleCompare(double x, double y);



int main()
{
    // printf("Square equation solver\n");
    // printf("Enter a,b,c:");
    
    // int k = scanf("%lg %lg %lg", &a,  &b, &c);    
    
    // if (k != 3)
    // {
    //     printf("ERROR! TRY AGAIN \n");
    // }

    double a=NAN, b=NAN, c=NAN;

    UnitTester(a, b, c);

    // int nRoots = SolveSquare(a, b, c, &x1, &x2);

    // Print_Roots(nRoots, x1, x2);
    
    return 0;  
}



void UnitTester(double a, double b, double c)
{


    DataTest test1 = {1, 1, 0, -4, 2, -2, 2}, test2 = {2, 0, 0, 0, NAN, NAN, AnyRoot}, test3 = {3, 0, 2, 0, 0 , 0, 1},
             test4 = {4, 1, 2, 1, -1, -1, 1}, test5 = {5, 1, 2, -3, 1, -3, 2}, test6 = {6, 1, 2, 8, NAN, NAN, No_Real_Roots},
             test7 = {7, 1, 2.321, 32, NAN, NAN, No_Real_Roots}, test8 = {8, 0, 2.321, -0.213, 0.0917708, 0.0917708, 1},
             test9 = {9, -9.34623, 8882.321, -42.154, 0.00474586, 950.3593, 2}, 
             test10 = {10, 0.00001, 0.999999, -0.9999999, -100000.89999, 0.999991, 2};
    
    DataTest ArrDataTest[10] = {test1, test2, test3, test4, test5, test6, test7, test8, test9, test10};
    
    int i = NAN;

    for (i=0; i<10; i++)
    {
        RunTest(ArrDataTest[i]);
    }


}


bool DoubleCompare(double x, double y)
{
    if ((abs(x - y)) <= Delta)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


void RunTest(DataTest data)
{
    int count = 0;
    double x1 = NAN, x2 = NAN;
    int nRoots = SolveSquare(data.a, data.b, data.c, &x1, &x2);
    if (nRoots != data.nRoots_expected || (!DoubleCompare(x1, data.x1_expected)) || (!DoubleCompare(x2, data.x2_expected)))
    {
        printf("ERROR Test%d, a=%lg, b=%lg, c=%lg, x1=%lg, x2=%lg, nRoots=%d \n"
        "EXPECTED: x1=%lg, x2=%lg, nRoots=%d \n", data.nTest, data.a, data.b, data.c, x1, x2, nRoots, data.x1_expected, data.x2_expected, data.nRoots_expected);    
    } 
    else
    {
        printf("Test%d correct \n", data.nTest);
    }
}


int SolveSquare(double a, double b, double c, double* x1, double* x2)
{
    assert(x1 != x2);
    assert(a != NAN);
    assert(b != NAN);
    assert(c != NAN);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    
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
            *x1 = *x2 = -c/b;
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
    
}

void Print_Roots(int nRoots, double x1, double x2)
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

