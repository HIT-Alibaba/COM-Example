//--------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   COMProvider.cpp
//    Author:      Streamlet
//    Create Time: 2012-09-04
//    Description: 
//
//    Version history:
//
//
//--------------------------------------------------------------------


#include "COMProvider.h"
#include <Windows.h>
#include <tchar.h>
#include <string.h>
#include "../xl/Win32/Registry/xlRegistry.h"
#include "ClassFactory.h"

LONG g_nModuleCount = 0;

/*
    http://msdn.microsoft.com/en-us/library/windows/desktop/ms690368.aspx

    Determines whether the DLL that implements this function is in use.
    If not, the caller can unload the DLL from memory.

    OLE does not provide this function. DLLs that support the OLE Component Object Model (COM)
    should implement and export DllCanUnloadNow.

    Syntax
        HRESULT __stdcall DllCanUnloadNow(void);

    Parameters
        This entry point has no parameters.

    Return value
        If the function succeeds, the return value is S_OK. Otherwise, it is S_FALSE.

    Remarks
        A call to DllCanUnloadNow determines whether the DLL from which it is exported is still in use.
        A DLL is no longer in use when it is not managing any existing objects (the reference count on
        all of its objects is 0). 

        Notes to Callers
            You should not have to call DllCanUnloadNow directly.
            OLE calls it only through a call to the CoFreeUnusedLibraries function.
            When it returns S_OK, CoFreeUnusedLibraries frees the DLL. 

        Notes to Implementers
            You must implement DllCanUnloadNow in, and export it from, DLLs
            that are to be dynamically loaded through a call to the CoGetClassObject function.
            (You also need to implement and export the DllGetClassObject function in the same DLL).

            If a DLL loaded through a call to CoGetClassObject fails to export DllCanUnloadNow,
            the DLL will not be unloaded until the application calls the CoUninitialize function
            to release the OLE libraries.

            DllCanUnloadNow should return S_FALSE if there are any existing references to objects
            that the DLL manages.
*/
STDAPI DllCanUnloadNow()
{
    return g_nModuleCount > 0 ? S_FALSE : S_OK;
}

/*
    http://msdn.microsoft.com/en-us/library/windows/desktop/ms680760.aspx

    Retrieves the class object from a DLL object handler or object application.

    OLE does not provide this function. DLLs that support the OLE Component Object Model (COM)
    must implement DllGetClassObject in OLE object handlers or DLL applications.

    Syntax
        HRESULT __stdcall DllGetClassObject(
          _In_   REFCLSID rclsid,
          _In_   REFIID riid,
          _Out_  LPVOID *ppv
        );

    Parameters
        rclsid [in]
            The CLSID that will associate the correct data and code.

        riid [in]
            A reference to the identifier of the interface that the caller is to use to communicate
            with the class object. Usually, this is IID_IClassFactory (defined in the OLE headers
            as the interface identifier for IClassFactory).

        ppv [out]
            The address of a pointer variable that receives the interface pointer requested in riid.
            Upon successful return, *ppv contains the requested interface pointer.
            If an error occurs, the interface pointer is NULL. 

    Return value
        This function can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED,
        as well as the following values.

        S_OK 
            The object was retrieved successfully.
 
        CLASS_E_CLASSNOTAVAILABLE 
            The DLL does not support the class (object definition).
 
    Remarks
        If a call to the CoGetClassObject function finds the class object that is to be loaded in a DLL,
        CoGetClassObject uses the DLL's exported DllGetClassObject function. 

        Notes to Callers
            You should not call DllGetClassObject directly. When an object is defined in a DLL, CoGetClassObject
            calls the CoLoadLibrary function to load the DLL, which, in turn, calls DllGetClassObject. 

        Notes to Implementers
            You need to implement DllGetClassObject in (and export it from) DLLs that support COM. 

    Examples
        The following is an example (in C++) of an implementation of DllGetClassObject. In this example,
        DllGetClassObject creates a class object and calls its QueryInterface method to retrieve a pointer
        to the interface requested in riid. The implementation releases the reference it holds to the
        IClassFactory interface because it returns a reference-counted pointer to IClassFactory to the caller. 

        HRESULT _export CALLBACK DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppvObj) 
        { 
            HRESULT hr = E_OUTOFMEMORY; 
            *ppvObj = NULL; 
 
            CClassFactory *pClassFactory = new CClassFactory(rclsid); 

            if (pClassFactory != NULL)
            { 
                hr = pClassFactory->QueryInterface(riid, ppvObj); 
                pClassFactory->Release(); 
            } 

            return hr;
        } 
*/
STDAPI DllGetClassObject(_In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID *ppv)
{
    if (riid == __uuidof(IClassFactory) && rclsid == __uuidof(SampleClass))
    {
        IClassFactory *p = new ClassFactory(rclsid);
        p->QueryInterface(riid, ppv);

        return S_OK;
    }

    return CLASS_E_CLASSNOTAVAILABLE;
}

/*
    http://msdn.microsoft.com/en-us/library/windows/desktop/ms682162.aspx

    Instructs an in-process server to create its registry entries for all classes supported in this server module.

    Syntax
        HRESULT __stdcall DllRegisterServer(void);

    Parameters
        This entry point has no parameters.

    Return value
        This function can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED,
        as well as the following values.

        S_OK 
            The registry entries were created successfully.
 
        SELFREG_E_TYPELIB 
            The server was unable to complete the registration of all the type libraries used by its classes.
 
        SELFREG_E_CLASS 
            The server was unable to complete the registration of all the object classes. 
 
    Remarks
        E_NOTIMPL is not a valid return code.
        If this function fails, the state of the registry for all its classes is undefined.
*/
STDAPI DllRegisterServer(void)
{
    TCHAR szModulePath[MAX_PATH] = {};
    GetModuleFileName(g_hModule, szModulePath, ARRAYSIZE(szModulePath));

    xl::Registry::SetString(HKEY_CLASSES_ROOT,
                            _T("CLSID\\{0DECBFF5-A8A5-49E8-9962-3D18AAC6088E}\\InprocServer32"),
                            _T(""),
                            szModulePath);

    xl::Registry::SetString(HKEY_CLASSES_ROOT,
                            _T("CLSID\\{0DECBFF5-A8A5-49E8-9962-3D18AAC6088E}\\ProgID"),
                            _T(""),
                            _T("Streamlet.COMProvider.SampleClass.1"));

    xl::Registry::SetString(HKEY_CLASSES_ROOT,
                            _T("Streamlet.COMProvider.SampleClass.1"),
                            _T(""),
                            _T("SampleClass Class"));

    xl::Registry::SetString(HKEY_CLASSES_ROOT,
                            _T("Streamlet.COMProvider.SampleClass.1\\CLSID"),
                            _T(""),
                            _T("{0DECBFF5-A8A5-49E8-9962-3D18AAC6088E}"));

    return S_OK;
}

/*
    http://msdn.microsoft.com/en-us/library/windows/desktop/ms691457.aspx

    Instructs an in-process server to remove only those entries created through DllRegisterServer. 

    Syntax
        HRESULT __stdcall DllUnregisterServer(void);

    Parameters
        This entry point has no parameters.

    Return value
        This function can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED,
        as well as the following values.

        S_OK 
            The registry entries were deleted successfully.
 
        S_FALSE 
            Unregistration of this server's known entries was successful,
            but other entries still exist for this server's classes.
 
        SELFREG_E_TYPELIB 
            The server was unable to remove the entries of all the type libraries used by its classes.
 
        SELFREG_E_CLASS 
            The server was unable to remove the entries of all the object classes.
 
    Remarks
        The server must not disturb any entries that it did not create which currently exist for its
        object classes. For example, between registration and unregistration, the user may have
        specified a Treat As relationship between this class and another. In that case, unregistration
        can remove all entries except the TreatAs key and any others that were not explicitly created
        in DllRegisterServer. The registry functions specifically disallow the deletion of an entire
        populated tree in the registry. The server can attempt, as the last step, to remove the CLSID key,
        but if other entries still exist, the key will remain.
*/
STDAPI DllUnregisterServer(void)
{
    xl::Registry::DeleteKeyRecursion(HKEY_CLASSES_ROOT,
                                     _T("CLSID\\{0DECBFF5-A8A5-49E8-9962-3D18AAC6088E}"));

    xl::Registry::DeleteKeyRecursion(HKEY_CLASSES_ROOT,
                                     _T("Streamlet.COMProvider.SampleClass.1"));

    return S_OK;
}

/*
    http://msdn.microsoft.com/en-us/library/windows/desktop/bb759846.aspx

    Handles installation and setup for a DLL.

    Syntax
        HRESULT DllInstall(
          BOOL bInstall,
          _In_opt_  PCWSTR pszCmdLine
        );

    Parameters
        bInstall 
            Type: BOOL
            TRUE if the DLL is being installed; FALSE if it is being uninstalled.

        pszCmdLine [in, optional]
            Type: PCWSTR
            A string passed in by regsvr32 that indicates which setup procedure to use. This value can be NULL.

    Return value
        Type: HRESULT
        If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

    Remarks
        This function may be implemented and exported by name by a DLL for use during application
        installation or setup. It is invoked by regsvr32 to allow the DLL to perform tasks such as
        adding information to the registry.

        DllInstall is used only for application installation and setup. It should not be called
        by an application. It is similar in purpose to DllRegisterServer or DllUnregisterServer.
        Unlike these functions, DllInstall takes an input string which can be used to specify
        a variety of different actions. This allows a DLL to be installed in more than one way,
        based on any criteria that is appropriate.

        To use DllInstall with regsvr32, add a "/i" flag followed by a colon (:) and a string.
        The string will be passed to DllInstall as the pszCmdLine parameter.
        If you omit the colon and string, pszCmdLine will be set to NULL.
        The following example would be used to install a DLL.
            regsvr32 /i:"Install_1" dllname.dll
        DllInstall is invoked with bInstall set to TRUE and pszCmdLine set to "Install_1".

        To uninstall a DLL, use the following:
            regsvr32 /u /i:"Install_1" dllname.dll

        With both of the above examples, DllRegisterServer or DllUnregisterServer will also be called.
        To call DllInstall only, add a "/n" flag.
            regsvr32 /n /i:"Install_1" dllname.dll
*/
STDAPI DllInstall(BOOL bInstall, _In_opt_ LPCTSTR lpszCmdLine)
{
    static const TCHAR szUserSwitch[] = _T("user");

    if (lpszCmdLine != NULL)
    {
        if (_tcsnicmp(lpszCmdLine, szUserSwitch, _countof(szUserSwitch)) == 0)
        {
            // TODO: Register for current user
        }
    }

    HRESULT hr = S_OK;

    if (bInstall)
    {    
        hr = DllRegisterServer();

        if (FAILED(hr))
        {
            DllUnregisterServer();
        }
    }
    else
    {
        hr = DllUnregisterServer();
    }

    return hr;
}
