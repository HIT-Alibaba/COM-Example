

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Mar 25 08:48:42 2015
 */
/* Compiler settings for IAdd.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IAdd_h_h__
#define __IAdd_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
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

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IAdd_INTERFACE_DEFINED__
#define __IAdd_INTERFACE_DEFINED__

/* interface IAdd */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAdd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1221db62-f3d8-11d4-825d-00104b3646c0")
    IAdd : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetFirstNumber( 
            long nX1) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSecondNumber( 
            long nX2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoTheAddition( 
            /* [retval][out] */ long *pBuffer) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAddVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAdd * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAdd * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAdd * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetFirstNumber )( 
            IAdd * This,
            long nX1);
        
        HRESULT ( STDMETHODCALLTYPE *SetSecondNumber )( 
            IAdd * This,
            long nX2);
        
        HRESULT ( STDMETHODCALLTYPE *DoTheAddition )( 
            IAdd * This,
            /* [retval][out] */ long *pBuffer);
        
        END_INTERFACE
    } IAddVtbl;

    interface IAdd
    {
        CONST_VTBL struct IAddVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAdd_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAdd_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAdd_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAdd_SetFirstNumber(This,nX1)	\
    ( (This)->lpVtbl -> SetFirstNumber(This,nX1) ) 

#define IAdd_SetSecondNumber(This,nX2)	\
    ( (This)->lpVtbl -> SetSecondNumber(This,nX2) ) 

#define IAdd_DoTheAddition(This,pBuffer)	\
    ( (This)->lpVtbl -> DoTheAddition(This,pBuffer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAdd_INTERFACE_DEFINED__ */


#ifndef __IFileIO_INTERFACE_DEFINED__
#define __IFileIO_INTERFACE_DEFINED__

/* interface IFileIO */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFileIO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6bee2d26-f3d8-11d4-825d-00104b3646c0")
    IFileIO : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnableLog( 
            long nEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEnabled( 
            long *pEnabled) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFileIOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFileIO * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFileIO * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFileIO * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnableLog )( 
            IFileIO * This,
            long nEnable);
        
        HRESULT ( STDMETHODCALLTYPE *IsEnabled )( 
            IFileIO * This,
            long *pEnabled);
        
        END_INTERFACE
    } IFileIOVtbl;

    interface IFileIO
    {
        CONST_VTBL struct IFileIOVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileIO_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFileIO_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFileIO_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFileIO_EnableLog(This,nEnable)	\
    ( (This)->lpVtbl -> EnableLog(This,nEnable) ) 

#define IFileIO_IsEnabled(This,pEnabled)	\
    ( (This)->lpVtbl -> IsEnabled(This,pEnabled) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFileIO_INTERFACE_DEFINED__ */



#ifndef __CodeGuruMathLib_LIBRARY_DEFINED__
#define __CodeGuruMathLib_LIBRARY_DEFINED__

/* library CodeGuruMathLib */
/* [helpstring][uuid] */ 




EXTERN_C const IID LIBID_CodeGuruMathLib;
#endif /* __CodeGuruMathLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


