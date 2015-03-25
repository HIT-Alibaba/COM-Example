//
//AddObjFactory.cpp
//
//Contains the method body for the class factory for our super-fast
//addition algorithm COM object
//
#include    <objbase.h>
#include    "AddObjFactory.h"
#include    "AddObj.h"




HRESULT __stdcall CAddFactory::QueryInterface(
                                const IID& iid, 
                                void** ppv)
    {    
	if ((iid == IID_IUnknown) || (iid == IID_IClassFactory))
	    {
		*ppv = static_cast<IClassFactory*>(this) ; 
	    }
	else
	    {
		*ppv = NULL ;
		return E_NOINTERFACE ;
	    }
	reinterpret_cast<IUnknown*>(*ppv)->AddRef() ;
	return S_OK ;
    }


HRESULT __stdcall CAddFactory::LockServer(BOOL bLock) 
    {
	return E_NOTIMPL;
    }

HRESULT __stdcall CAddFactory::CreateInstance(IUnknown* pUnknownOuter,
                                           const IID& iid,
                                           void** ppv) 
    {
    //
    //This method lets the client manufacture components en masse
    //The class factory provides a mechanism to control the way
    //the component is created. Within the class factory the 
    //author of the component may decide to selectivey enable
    //or disable creation as per license agreements 
    //
    //

	// Cannot aggregate.
	if (pUnknownOuter != NULL)
	    {
		return CLASS_E_NOAGGREGATION ;
	    }

    //
	// Create an instance of the component.
    //
	CAddObj* pObject = new CAddObj ;
	if (pObject == NULL)
	    {
		return E_OUTOFMEMORY ;
	    }

    //
	// Get the requested interface.
    //
	return pObject->QueryInterface(iid, ppv) ;
    }
