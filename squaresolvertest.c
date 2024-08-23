#include <stdio.h>
#include <math.h> 
#include <assert.h>
#include <string.h>

const int AnyRoot = -1;
const int No_Real_Roots = 0;
const double Delta = 0.000001;
const bool TRUE = 1;
const bool FALSE = 0;

struct DataTest
{
    int nTest;
    double a, b, c;
    double x1_expected, x2_expected;
    int nRoots_expected;
};

void SquareEquationSolver();
void UnitTester();
bool DoubleEquality(double x, double y);
bool Find_t(int count, char* arr[]);
void RunTest(DataTest data);
int SolveSquare(double a, double b, double c, double* x1, double* x2);
void InputTester(int k);
void Print_Roots(int nRoots, double x1, double x2);



int main(int argc, const char* argv[])
{
    printf("Enter '-t' if you want to run test\n"
    "Press 'Enter' if you want to run Square equation solver\n");
    
    if(Find_t(argc, argv[]))
    {
        UnitTester();
    }
    else
    {
        SquareEquationSolver();    
    }
    
    return 0;  
}




void SquareEquationSolver()
{
    printf("Square equation solver\n");
    printf("Enter a,b,c:");
            
    double a=NAN, b=NAN, c=NAN;
    int nDigits = scanf("%lg %lg %lg", &a,  &b, &c);  

    InputTester(nDigits);  
            
    double x1 = NAN, x2 = NAN;
    int nRoots = SolveSquare(a, b, c, &x1, &x2);

    Print_Roots(nRoots, x1, x2);
}


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


bool DoubleEquality(double x, double y)
{
    if (isnan(x))
    {
        return isnan(y);
    }


    if ((abs(x - y)) <= Delta)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


bool Find_t(int count, char* arr[])
{
    for(int i = 0; i < count; i++)
    {
        if (!strcmp(arr[i], "-t"))
        {
            return TRUE;
        }
    }
    return FALSE;
}


void RunTest(DataTest data)
{
    double x1 = NAN, x2 = NAN;
    int nRoots = SolveSquare(data.a, data.b, data.c, &x1, &x2);
    
    if (nRoots != data.nRoots_expected || (!DoubleEquality(x1, data.x1_expected)) || (!DoubleEquality(x2, data.x2_expected)))
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
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));
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


void InputTester(int nDigits)
{
    if (nDigits != 3)
    {
        printf("ERROR! TRY AGAIN \n");
    }
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