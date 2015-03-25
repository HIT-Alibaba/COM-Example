//--------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   Main.cpp
//    Author:      Streamlet
//    Create Time: 2012-09-04
//    Description: 
//
//    Version history:
//
//
//--------------------------------------------------------------------


#include <tchar.h>
#include <Objbase.h>
#include <iostream>
#include "../COMProvider/Interface.h"

using namespace std;


int _tmain(int argc, TCHAR *argv[])
{
    HRESULT hr = CoInitialize(NULL);

    ISampleInterface *pSampleInterface = nullptr;
    hr = CoCreateInstance(__uuidof(SampleClass),
                          nullptr,
                          CLSCTX_INPROC_SERVER,
                          __uuidof(ISampleInterface),
                          (LPVOID *)&pSampleInterface);

    if (SUCCEEDED(hr))
    {
        pSampleInterface->SampleMethod();
        pSampleInterface->Release();
    }
    
    CoUninitialize();

    return 0;
}
