//
//AddObjFactory.h
//
//Contains the declaration for the class factory for our super-fast
//addition algorithm COM object
//

extern long g_nComObjsInUse;

class CAddFactory : public IClassFactory
    {

    public:
    CAddFactory()
        {
        m_nRefCount=0;
        //
        //increment the global count
        //
        InterlockedIncrement(&g_nComObjsInUse);
        }

    ~CAddFactory()
        {
        //
        //decrement the global count
        //
        InterlockedDecrement(&g_nComObjsInUse);
        }


    //IUnknown methods are implemented here
    HRESULT __stdcall QueryInterface(
                                REFIID riid , 
                                void **ppObj);


    ULONG   __stdcall AddRef()
        {
        return InterlockedIncrement(&m_nRefCount) ;
        }

    ULONG   __stdcall Release()
        {
        long nRefCount=0;
        nRefCount=InterlockedDecrement(&m_nRefCount) ;
        if (nRefCount == 0) delete this;
        return nRefCount;
        }


	// Interface IClassFactory
	virtual HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter,
	                                         const IID& iid,
	                                         void** ppv) ;
	virtual HRESULT __stdcall LockServer(BOOL bLock) ; 

    private:
    long m_nRefCount;
    };

