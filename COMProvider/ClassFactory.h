//--------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   ClassFactory.h
//    Author:      Streamlet
//    Create Time: 2012-09-06
//    Description: 
//
//    Version history:
//
//
//--------------------------------------------------------------------

#ifndef __CLASSFACTORY_H_9DB2DE69_0493_4A97_9337_A9ABDAEE0849_INCLUDED__
#define __CLASSFACTORY_H_9DB2DE69_0493_4A97_9337_A9ABDAEE0849_INCLUDED__


#include "../xl/Win32/COM/InterfaceHelper/xlIClassFactoryImpl.h"
#include "../xl/Win32/COM/xlComClass.h"
#include "SampleClass.h"

class ClassFactory : public xl::ComClass<ClassFactory>,
                     public xl::IClassFactoryImpl<>
{
public:
    ClassFactory(REFCLSID rclsid);
    ~ClassFactory();

public:
    STDMETHOD(CreateInstance)(_In_opt_ IUnknown *pUnkOuter,
                              _In_ REFIID riid,
                              _COM_Outptr_  void **ppvObject);

public:
    XL_COM_INTERFACE_BEGIN(ClassFactory)
        XL_COM_INTERFACE(IClassFactory)
    XL_COM_INTERFACE_END()

private:
    CLSID m_clsid;
};


#endif // #ifndef __CLASSFACTORY_H_9DB2DE69_0493_4A97_9337_A9ABDAEE0849_INCLUDED__
