// ComTest1Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <ObjBase.h>
#include "ComTest1_i.h"
#include "ComTest1_i.c"

int _tmain(int argc, _TCHAR* argv[])
{
	HRESULT hr;
	IMyClass *pMyClass = NULL;
	hr = CoInitialize(NULL);
	hr = CoCreateInstance(CLSID_MyClass,NULL,1,IID_IMyClass,(void**)&pMyClass);
	byte result=100;
	char str[100];
	if(SUCCEEDED(hr))
	{
		printf("%s","Please enter a string, we will check if it is an integer:\n");
		gets_s(str);
		pMyClass->IsValidNum(str,&result);
		if(result<100)
			printf("%s","It's a integer.");
		else 
			printf("%s","It isn't a integer.");

	}
	CoUninitialize();
	//printf("%d",result);
	getchar();
	return 0;
}
