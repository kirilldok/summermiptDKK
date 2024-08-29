#ifndef TESTFILES_H
#define TESTFILES_H

struct DataTest
{
    int nTest;
    double data, b, c;
    double x1_expected, x2_expected;
    int nRoots_expected;
};

void UnitTester();
void RunTest(DataTest data);

#endif