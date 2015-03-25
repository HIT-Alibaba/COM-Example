//
//AddObj.h
//Contains the C++ class declarations for implementing the IAdd, IFileIO
//interfaces
//
#include    "IAdd.h"
extern long g_nComObjsInUse;
class CAddObj : 
        public IAdd , 
        public IFileIO
    {
    public:

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


    //IAdd interface
    HRESULT __stdcall SetFirstNumber( long nX1);
    HRESULT __stdcall SetSecondNumber( long nX2);
    HRESULT __stdcall DoTheAddition( long *pBuffer);

    //IFileIO interface
    HRESULT __stdcall EnableLog( long nEnable);
    HRESULT __stdcall IsEnabled( long *pEnabled);


    

    CAddObj()
        {
        //
        //constructor
        //

        m_nRefCount=0;
        m_bIsLogEnabled=FALSE;

        //
        //increment the global count
        //
        InterlockedIncrement(&g_nComObjsInUse);
        
        //
        //set the path to the log file
        //
        GetTempPath(sizeof(szLogPath),szLogPath);
        lstrcat(szLogPath,"cguruAdd.log");
        }


    ~CAddObj()
        {
        //
        //destructor
        //decerement the global object count
        InterlockedDecrement(&g_nComObjsInUse);
            
        }



    
    private:
    void WriteToLog(char *szBuffer);

    long m_nX1 , m_nX2; //operands for addition

    long m_nRefCount;   //for managing the reference count
    char m_szLogFile[260];
    BOOL m_bIsLogEnabled;
    char szLogPath[MAX_PATH];

    };