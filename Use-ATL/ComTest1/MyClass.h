// MyClass.h : CMyClass ������

#pragma once
#include "resource.h"       // ������



#include "ComTest1_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CMyClass

class ATL_NO_VTABLE CMyClass :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMyClass, &CLSID_MyClass>,
	public IDispatchImpl<IMyClass, &IID_IMyClass, &LIBID_ComTest1Lib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMyClass()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MYCLASS)


BEGIN_COM_MAP(CMyClass)
	COM_INTERFACE_ENTRY(IMyClass)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(IsValidNum)(CHAR* str, BYTE* result);
};

OBJECT_ENTRY_AUTO(__uuidof(MyClass), CMyClass)
