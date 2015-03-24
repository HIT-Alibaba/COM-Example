//--------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   DLLMain.cpp
//    Author:      Streamlet
//    Create Time: 2012-09-04
//    Description: 
//
//    Version history:
//
//
//--------------------------------------------------------------------


#include <Windows.h>

HMODULE g_hModule = nullptr;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
        g_hModule = hModule;
        break;
	case DLL_THREAD_ATTACH:
        break;
	case DLL_THREAD_DETACH:
        break;
	case DLL_PROCESS_DETACH:
		break;
    default:
        break;
	}

    return TRUE;
}
