//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlWindowAPIMacroRedefine.h
//    Author:      Streamlet
//    Create Time: 2011-02-27
//    Description: 
//
//    Version history:
//
//
//
//------------------------------------------------------------------------------

#ifndef __XLWINDOWAPIMACROREDEFINE_H_61336F01_F8A8_4FA6_8762_1F60789DBC99_INCLUDED__
#define __XLWINDOWAPIMACROREDEFINE_H_61336F01_F8A8_4FA6_8762_1F60789DBC99_INCLUDED__


#include "../xlWin32Ver.h"
#include <Windows.h>

#ifdef GetClassName
#undef GetClassName
inline BOOL WINAPI GetClassName(__in HWND hWnd, __out_ecount_part(nMaxCount, return) LPWSTR lpClassName, __in int nMaxCount)
{
#ifdef UNICODE
    return GetClassNameW(hWnd, lpClassName, nMaxCount);
#else
    return GetClassNameA(hWnd, lpClassName, nMaxCount);
#endif
}
#endif

#ifdef GetWindowLong
#undef GetWindowLong
inline LONG WINAPI GetWindowLong(__in HWND hWnd, __in int nIndex)
{
#ifdef UNICODE
    return GetWindowLongW(hWnd, nIndex);
#else
    return GetWindowLongA(hWnd, nIndex);
#endif
}
#endif

#ifdef SetWindowLong
#undef SetWindowLong
inline LONG WINAPI SetWindowLong(__in HWND hWnd, __in int nIndex, __in LONG dwNewLong)
{
#ifdef UNICODE
    return SetWindowLongW(hWnd, nIndex, dwNewLong);
#else
    return SetWindowLongA(hWnd, nIndex, dwNewLong);
#endif
}
#endif

#ifdef GetWindowLongPtr
#undef GetWindowLongPtr
inline LONG_PTR WINAPI GetWindowLongPtr(__in HWND hWnd, __in int nIndex)
{
#ifdef UNICODE
    return GetWindowLongPtrW(hWnd, nIndex);
#else
    return GetWindowLongPtrA(hWnd, nIndex);
#endif
}
#endif

#ifdef SetWindowLongPtr
#undef SetWindowLongPtr
inline LONG_PTR WINAPI SetWindowLongPtr(__in HWND hWnd, __in int nIndex, __in LONG_PTR dwNewLong)
{
#ifdef UNICODE
    return SetWindowLongPtrW(hWnd, nIndex, dwNewLong);
#else
    return SetWindowLongPtrA(hWnd, nIndex, dwNewLong);
#endif
}
#endif

#ifdef SendMessage
#undef SendMessage
inline LRESULT WINAPI SendMessage(__in HWND hWnd, __in UINT Msg, __in WPARAM wParam, __in LPARAM lParam)
{
#ifdef UNICODE
    return SendMessageW(hWnd, Msg, wParam, lParam);
#else
    return SendMessageA(hWnd, Msg, wParam, lParam);
#endif
}
#endif

#ifdef PostMessage
#undef PostMessage
inline BOOL WINAPI PostMessage(__in HWND hWnd, __in UINT Msg, __in WPARAM wParam, __in LPARAM lParam)
{
#ifdef UNICODE
    return PostMessageW(hWnd, Msg, wParam, lParam);
#else
    return PostMessageA(hWnd, Msg, wParam, lParam);
#endif
}
#endif

#ifdef SendNotifyMessage
#undef SendNotifyMessage
inline BOOL WINAPI SendNotifyMessage(__in HWND hWnd, __in UINT Msg, __in WPARAM wParam, __in LPARAM lParam)
{
#ifdef UNICODE
    return SendNotifyMessageW(hWnd, Msg, wParam, lParam);
#else
    return SendNotifyMessageA(hWnd, Msg, wParam, lParam);
#endif
}
#endif

#ifdef GetWindowTextLength
#undef GetWindowTextLength
inline int WINAPI GetWindowTextLength(__in HWND hWnd)
{
#ifdef UNICODE
    return GetWindowTextLengthW(hWnd);
#else
    return GetWindowTextLengthA(hWnd);
#endif
}
#endif

#ifdef GetWindowText
#undef GetWindowText
inline int WINAPI GetWindowText(__in HWND hWnd, __out_ecount(nMaxCount) LPWSTR lpString, __in int nMaxCount)
{
#ifdef UNICODE
    return GetWindowTextW(hWnd, lpString, nMaxCount);
#else
    return GetWindowTextA(hWnd, lpString, nMaxCount);
#endif
}
#endif

#ifdef SetWindowText
#undef SetWindowText
inline int WINAPI SetWindowText(__in HWND hWnd, __in_opt LPCWSTR lpString)
{
#ifdef UNICODE
    return SetWindowTextW(hWnd, lpString);
#else
    return SetWindowTextA(hWnd, lpString);
#endif
}
#endif

#ifdef MessageBox
#undef MessageBox
inline int WINAPI MessageBox(__in_opt HWND hWnd, __in_opt LPCWSTR lpText, __in_opt LPCWSTR lpCaption, __in UINT uType)
{
#ifdef UNICODE
    return MessageBoxW(hWnd, lpText, lpCaption, uType);
#else
    return MessageBoxA(hWnd, lpText, lpCaption, uType);
#endif
}
#endif

#ifdef WinHelp
#undef WinHelp
inline BOOL WINAPI WinHelp(__in_opt HWND hWndMain, __in_opt LPCWSTR lpszHelp, __in UINT uCommand, __in ULONG_PTR dwData)
{
#ifdef UNICODE
    return WinHelpW(hWndMain, lpszHelp, uCommand, dwData);
#else
    return WinHelpA(hWndMain, lpszHelp, uCommand, dwData);
#endif
}
#endif

#ifdef SendDlgItemMessage
#undef SendDlgItemMessage
inline LRESULT WINAPI SendDlgItemMessage(__in HWND hDlg, __in int nIDDlgItem, __in UINT uMsg, __in WPARAM wParam, __in LPARAM lParam)
{
#ifdef UNICODE
    return SendDlgItemMessageW(hDlg, nIDDlgItem, uMsg, wParam, lParam);
#else
    return SendDlgItemMessageA(hDlg, nIDDlgItem, uMsg, wParam, lParam);
#endif
}
#endif

#ifdef GetDlgItemText
#undef GetDlgItemText
inline BOOL WINAPI GetDlgItemText(__in HWND hDlg, __in int nIDDlgItem, __out_ecount(cchMax) LPWSTR lpString, __in int cchMax)
{
#ifdef UNICODE
    return GetDlgItemTextW(hDlg, nIDDlgItem, lpString, cchMax);
#else
    return GetDlgItemTextA(hDlg, nIDDlgItem, lpString, cchMax);
#endif
}
#endif

#ifdef AppendMenu
#undef AppendMenu
inline BOOL WINAPI AppendMenu(__in HMENU hMenu, __in UINT uFlags, __in UINT_PTR uIDNewItem, __in_opt LPCWSTR lpNewItem)
{
#ifdef UNICODE
    return AppendMenuW(hMenu, uFlags, uIDNewItem, lpNewItem);
#else
    return AppendMenuA(hMenu, uFlags, uIDNewItem, lpNewItem);
#endif
}
#endif

#ifdef GetMenuString
#undef GetMenuString
inline BOOL WINAPI GetMenuString(__in HMENU hMenu, __in UINT uIDItem, __out_ecount_opt(cchMax) LPWSTR lpString, __in int cchMax, __in UINT flags)
{
#ifdef UNICODE
    return GetMenuStringW(hMenu, uIDItem, lpString, cchMax, flags);
#else
    return GetMenuStringA(hMenu, uIDItem, lpString, cchMax, flags);
#endif
}
#endif

#ifdef GetMenuItemInfo
#undef GetMenuItemInfo
inline BOOL WINAPI GetMenuItemInfo(HMENU hMenu, UINT uItem, BOOL fByPosition, LPMENUITEMINFOW lpmii)
{
#ifdef UNICODE
    return GetMenuItemInfoW(hMenu, uItem, fByPosition, lpmii);
#else
    return GetMenuItemInfoA(hMenu, uItem, fByPosition, lpmii);
#endif
}
#endif

#ifdef SetMenuItemInfo
#undef SetMenuItemInfo
inline BOOL WINAPI SetMenuItemInfo(__in HMENU hMenu, __in UINT uItem, __in BOOL fByPosition, __in LPCMENUITEMINFOW lpmii)
{
#ifdef UNICODE
    return SetMenuItemInfoW(hMenu, uItem, fByPosition, lpmii);
#else
    return SetMenuItemInfoA(hMenu, uItem, fByPosition, lpmii);
#endif
}
#endif

#ifdef InsertMenuItem
#undef InsertMenuItem
inline BOOL WINAPI InsertMenuItem(__in HMENU hMenu, __in UINT uItem, __in BOOL fByPosition, __in LPCMENUITEMINFOW lpmii)
{
#ifdef UNICODE
    return InsertMenuItemW(hMenu, uItem, fByPosition, lpmii);
#else
    return InsertMenuItemA(hMenu, uItem, fByPosition, lpmii);
#endif
}
#endif

#ifdef ModifyMenu
#undef ModifyMenu
inline BOOL WINAPI ModifyMenu(__in HMENU hMenu, __in UINT uPosition, __in UINT uFlags, __in UINT_PTR uIDNewItem, __in_opt LPCWSTR lpNewItem)
{
#ifdef UNICODE
    return ModifyMenuW(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem);
#else
    return ModifyMenuA(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem);
#endif
}
#endif

#endif // #ifndef __XLWINDOWAPIMACROREDEFINE_H_61336F01_F8A8_4FA6_8762_1F60789DBC99_INCLUDED__
