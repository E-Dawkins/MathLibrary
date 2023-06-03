// TestLib.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "TestLib.h"


// This is an example of an exported variable
TESTLIB_API int nTestLib=0;

// This is an example of an exported function.
TESTLIB_API int fnTestLib(void)
{
    return 0;
}

TESTLIB_API int Sum(int a, int b)
{
    return a + b;
}

// This is the constructor of a class that has been exported.
CTestLib::CTestLib()
{
    return;
}