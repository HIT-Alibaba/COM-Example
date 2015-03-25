//--------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   SampleClass.cpp
//    Author:      Streamlet
//    Create Time: 2012-09-04
//    Description: 
//
//    Version history:
//
//
//--------------------------------------------------------------------


#include "SampleClass.h"
#include <stdio.h>

SampleClass::SampleClass()
{
    InterlockedIncrement(&g_nModuleCount);
}

SampleClass::~SampleClass()
{
    InterlockedDecrement(&g_nModuleCount);
}

STDMETHODIMP SampleClass::SampleMethod()
{
	int c;
	int a;
	int b;
    MessageBox(NULL, _T("Add SampleMethod called.\n"), _T("Begin"), MB_OK | MB_ICONINFORMATION);
	printf("a = ");
	scanf("%d", &a); 
	printf("b = ");
	scanf("%d", &b);
	c = a + b;
	printf("c = a + b = %d", c);
	MessageBox(NULL, _T("Add SampleMethod finished.\n"), _T("End"), MB_OK | MB_ICONINFORMATION);
    return S_OK;
}
