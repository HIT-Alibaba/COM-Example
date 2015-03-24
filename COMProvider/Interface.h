//--------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   Interface.h
//    Author:      Streamlet
//    Create Time: 2012-09-06
//    Description: 
//
//    Version history:
//
//
//--------------------------------------------------------------------

#ifndef __INTERFACE_H_F9F0BB86_D3F9_4C0A_91AE_E8A0C46675B9_INCLUDED__
#define __INTERFACE_H_F9F0BB86_D3F9_4C0A_91AE_E8A0C46675B9_INCLUDED__


#include <Unknwn.h>

struct __declspec(uuid("{83C783E3-F989-4E0D-BFC5-631273EDFFDA}"))
ISampleInterface : public IUnknown
{
    STDMETHOD(SampleMethod)() PURE;
};

class __declspec(uuid("{0DECBFF5-A8A5-49E8-9962-3D18AAC6088E}"))
SampleClass;


#endif // #ifndef __INTERFACE_H_F9F0BB86_D3F9_4C0A_91AE_E8A0C46675B9_INCLUDED__
