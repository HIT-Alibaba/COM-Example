//--------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   SampleClass.h
//    Author:      Streamlet
//    Create Time: 2012-09-06
//    Description: 
//
//    Version history:
//
//
//--------------------------------------------------------------------

#ifndef __SAMPLECLASS_H_4B81D513_4BB1_4FA8_8B09_192237846EAD_INCLUDED__
#define __SAMPLECLASS_H_4B81D513_4BB1_4FA8_8B09_192237846EAD_INCLUDED__


#include <Unknwn.h>
#include <Windows.h>
#include <tchar.h>
#include "../xl/Win32/COM/xlComClass.h"
#include "../xl/Win32/COM/InterfaceHelper/xlIUnknownImpl.h"
#include "COMProvider.h"
#include "Interface.h"

class SampleClass : public xl::ComClass<SampleClass>,
                    public xl::IUnknownImpl<ISampleInterface>
{
public:
    SampleClass();
    ~SampleClass();

public:
    STDMETHOD(SampleMethod)();

public:
    XL_COM_INTERFACE_BEGIN(SampleClass)
        XL_COM_INTERFACE(ISampleInterface)
    XL_COM_INTERFACE_END()
};

#endif // #ifndef __SAMPLECLASS_H_4B81D513_4BB1_4FA8_8B09_192237846EAD_INCLUDED__
