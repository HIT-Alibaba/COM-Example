//
//AddObj.cpp
//Contains the C++ class body for implementing the IAdd, IFileIO
//interfaces
//


#include    <objbase.h>

#include    "AddObj.h"
#include    "IAdd_i.c"


HRESULT __stdcall CAddObj::SetFirstNumber( long nX1)
    {
    m_nX1=nX1;
    if (m_bIsLogEnabled) WriteToLog("Junk");
    return S_OK;
    }

HRESULT __stdcall CAddObj::SetSecondNumber( long nX2)
    {
    m_nX2=nX2;
    return S_OK;
    }

HRESULT __stdcall CAddObj::DoTheAddition( long *pBuffer)
    {
    *pBuffer =m_nX1 + m_nX2;

    return S_OK;
    }


HRESULT __stdcall CAddObj::EnableLog( long nEnable)
    {
    if (nEnable)
        m_bIsLogEnabled=TRUE;
    else
        m_bIsLogEnabled=FALSE;

    return S_OK;
    }

HRESULT __stdcall CAddObj::IsEnabled( long *pEnabled)
    {
    *pEnabled = m_bIsLogEnabled;
    return S_OK;
    }


HRESULT __stdcall CAddObj::QueryInterface(
                                    REFIID riid , 
                                    void **ppObj)
    {
    if (riid == IID_IUnknown)
        {
	    *ppObj = static_cast<IAdd*>(this) ; 
        AddRef() ;
        return S_OK;
        }

    if (riid == IID_IAdd)
	    {
	    *ppObj = static_cast<IAdd*>(this) ;
        AddRef() ;
        return S_OK;
	    }

    if (riid == IID_IFileIO)
	    {
	    *ppObj = static_cast<IFileIO*>(this) ;
        AddRef() ;
        return S_OK;
	    }

    //
    //if control reaches here then , let the client know that
    //we do not satisfy the required interface
    //

    *ppObj = NULL ;
    return E_NOINTERFACE ;
    }

void  CAddObj::WriteToLog(char *szBuffer)
    {
    //
    //write to the log file
    //
    /*
    FILE *fp=NULL;
    fp = fopen("
    YOU WERE HERE
    */
    }