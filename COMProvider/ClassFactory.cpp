//--------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   ClassFactory.cpp
//    Author:      Streamlet
//    Create Time: 2012-09-06
//    Description: 
//
//    Version history:
//
//
//--------------------------------------------------------------------


#include "ClassFactory.h"
#include "SampleClass.h"

ClassFactory::ClassFactory(REFCLSID rclsid)
{
    m_clsid = rclsid;
}

ClassFactory::~ClassFactory()
{

}

STDMETHODIMP ClassFactory::CreateInstance(_In_opt_ IUnknown *pUnkOuter,
                                          _In_ REFIID riid,
                                          _COM_Outptr_  void **ppvObject)
{
    if (riid == __uuidof(ISampleInterface) && m_clsid == __uuidof(SampleClass))
    {
        ISampleInterface *p = new SampleClass;
        p->QueryInterface(riid, ppvObject);

        return S_OK;
    }

    return CLASS_E_CLASSNOTAVAILABLE;
}
