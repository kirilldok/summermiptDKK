static const int AnyRoot = -1;
static const int No_Real_Roots = 0;
static const double Delta = 0.000001;

void SquareEquationSolver();
bool DoubleEquality(double x, double y);
int SolveSquare(double a, double b, double c, double* x1, double* x2);
void Print_Roots(int nRoots, double x1, double x2);