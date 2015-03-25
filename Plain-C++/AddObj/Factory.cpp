#include	"Factory.h"
#include	"trace.h"
#include	"..\\Interface Declarations\\ISort.h"
#include	"Sort.h"
#include	"Compnt.h"


//
// Class factory IUnknown implementation
//
HRESULT __stdcall CFactory::QueryInterface(const IID& iid, void** ppv)
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

ULONG __stdcall CFactory::AddRef()
    {
    //
    //The InterlockedIncrement function increments (increases by one) the 
    //value of the specified variable and checks the resulting value. The 
    //function prevents more than one thread from using the same variable 
    //simultaneously. 
    //
	return InterlockedIncrement(&m_cRef) ;
    }

ULONG __stdcall CFactory::Release() 
    {
	if (InterlockedDecrement(&m_cRef) == 0)
	    {
		delete this ;
		return 0 ;
	    }
	return m_cRef ;
    }

//
// IClassFactory implementation
//
HRESULT __stdcall CFactory::CreateInstance(IUnknown* pUnknownOuter,
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
	trace("Class factory:\t\tCreate component.") ;

	// Cannot aggregate.
	if (pUnknownOuter != NULL)
	    {
		return CLASS_E_NOAGGREGATION ;
	    }

	// Create component.
	Sort* pObject = new Sort ;
	if (pObject == NULL)
	    {
		return E_OUTOFMEMORY ;
	    }

	// Get the requested interface.
	HRESULT hr = pObject->QueryInterface(iid, ppv) ;

	// Release the IUnknown pointer.
	// (If QueryInterface failed, component will delete itself.)
	pObject->Release() ;
	return hr ;
    }

// LockServer
HRESULT __stdcall CFactory::LockServer(BOOL bLock) 
    {
	if (bLock)
	    {
		InterlockedIncrement(&g_cServerLocks) ; 
	    }
	else
	    {
		InterlockedDecrement(&g_cServerLocks) ;
	    }
	return S_OK ;
    }
