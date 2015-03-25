/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Sun Feb 25 19:43:41 2001
 */
/* Compiler settings for IAdd.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IAdd_h__
#define __IAdd_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAdd_FWD_DEFINED__
#define __IAdd_FWD_DEFINED__
typedef interface IAdd IAdd;
#endif 	/* __IAdd_FWD_DEFINED__ */


#ifndef __IFileIO_FWD_DEFINED__
#define __IFileIO_FWD_DEFINED__
typedef interface IFileIO IFileIO;
#endif 	/* __IFileIO_FWD_DEFINED__ */


#ifndef __IAdd_FWD_DEFINED__
#define __IAdd_FWD_DEFINED__
typedef interface IAdd IAdd;
#endif 	/* __IAdd_FWD_DEFINED__ */


#ifndef __IFileIO_FWD_DEFINED__
#define __IFileIO_FWD_DEFINED__
typedef interface IFileIO IFileIO;
#endif 	/* __IFileIO_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IAdd_INTERFACE_DEFINED__
#define __IAdd_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAdd
 * at Sun Feb 25 19:43:41 2001
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][uuid][object] */ 



EXTERN_C const IID IID_IAdd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("1221db62-f3d8-11d4-825d-00104b3646c0")
    IAdd : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetFirstNumber( 
            long nX1) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSecondNumber( 
            long nX2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoTheAddition( 
            /* [retval][out] */ long __RPC_FAR *pBuffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAddVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAdd __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAdd __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAdd __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFirstNumber )( 
            IAdd __RPC_FAR * This,
            long nX1);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSecondNumber )( 
            IAdd __RPC_FAR * This,
            long nX2);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoTheAddition )( 
            IAdd __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pBuffer);
        
        END_INTERFACE
    } IAddVtbl;

    interface IAdd
    {
        CONST_VTBL struct IAddVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAdd_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAdd_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAdd_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAdd_SetFirstNumber(This,nX1)	\
    (This)->lpVtbl -> SetFirstNumber(This,nX1)

#define IAdd_SetSecondNumber(This,nX2)	\
    (This)->lpVtbl -> SetSecondNumber(This,nX2)

#define IAdd_DoTheAddition(This,pBuffer)	\
    (This)->lpVtbl -> DoTheAddition(This,pBuffer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAdd_SetFirstNumber_Proxy( 
    IAdd __RPC_FAR * This,
    long nX1);


void __RPC_STUB IAdd_SetFirstNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAdd_SetSecondNumber_Proxy( 
    IAdd __RPC_FAR * This,
    long nX2);


void __RPC_STUB IAdd_SetSecondNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAdd_DoTheAddition_Proxy( 
    IAdd __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pBuffer);


void __RPC_STUB IAdd_DoTheAddition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAdd_INTERFACE_DEFINED__ */


#ifndef __IFileIO_INTERFACE_DEFINED__
#define __IFileIO_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IFileIO
 * at Sun Feb 25 19:43:41 2001
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][uuid][object] */ 



EXTERN_C const IID IID_IFileIO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("6bee2d26-f3d8-11d4-825d-00104b3646c0")
    IFileIO : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnableLog( 
            long nEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEnabled( 
            long __RPC_FAR *pEnabled) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFileIOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IFileIO __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IFileIO __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IFileIO __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnableLog )( 
            IFileIO __RPC_FAR * This,
            long nEnable);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsEnabled )( 
            IFileIO __RPC_FAR * This,
            long __RPC_FAR *pEnabled);
        
        END_INTERFACE
    } IFileIOVtbl;

    interface IFileIO
    {
        CONST_VTBL struct IFileIOVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileIO_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFileIO_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFileIO_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFileIO_EnableLog(This,nEnable)	\
    (This)->lpVtbl -> EnableLog(This,nEnable)

#define IFileIO_IsEnabled(This,pEnabled)	\
    (This)->lpVtbl -> IsEnabled(This,pEnabled)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFileIO_EnableLog_Proxy( 
    IFileIO __RPC_FAR * This,
    long nEnable);


void __RPC_STUB IFileIO_EnableLog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFileIO_IsEnabled_Proxy( 
    IFileIO __RPC_FAR * This,
    long __RPC_FAR *pEnabled);


void __RPC_STUB IFileIO_IsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFileIO_INTERFACE_DEFINED__ */



#ifndef __CodeGuruMathLib_LIBRARY_DEFINED__
#define __CodeGuruMathLib_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: CodeGuruMathLib
 * at Sun Feb 25 19:43:41 2001
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][uuid] */ 





EXTERN_C const IID LIBID_CodeGuruMathLib;
#endif /* __CodeGuruMathLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
