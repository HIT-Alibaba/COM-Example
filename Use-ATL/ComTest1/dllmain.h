// dllmain.h : 模块类的声明。

class CComTest1Module : public ATL::CAtlDllModuleT< CComTest1Module >
{
public :
	DECLARE_LIBID(LIBID_ComTest1Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_COMTEST1, "{15ACC332-D5A4-4BC0-A280-BB89137AD391}")
};

extern class CComTest1Module _AtlModule;
