#pragma once
#include<Windows.h>

static int (WINAPI* OriginalMultiByteToWideChar)(
	UINT CodePage, 
	DWORD dwFlags,
	LPCSTR lpMultiByteStr, 
	int cbMultiByte, 
	LPWSTR lpWideCharStr, 
	int cchWideChar
	) = MultiByteToWideChar;


static int (WINAPI* OriginalWideCharToMultiByte)(
	UINT CodePage,
	DWORD dwFlags,
	LPCWSTR lpWideCharStr,
	int cchWideChar,
	LPSTR lpMultiByteStr,
	int cbMultiByte,
	LPCSTR lpDefaultChar,
	LPBOOL lpUsedDefaultChar
	) = WideCharToMultiByte;

static UINT(WINAPI* OriginalGetACP)(void) = GetACP;
static UINT(WINAPI* OriginalGetOEMCP)(void) = GetOEMCP;
static BOOL(WINAPI* OriginalGetCPInfo)(
	_In_ UINT       CodePage,
	_Out_ LPCPINFO  lpCPInfo
	) = GetCPInfo;

static LRESULT(WINAPI* OriginalSendMessageA)(
	_In_ HWND hWnd,
	_In_ UINT Msg,
	_Pre_maybenull_ _Post_valid_ WPARAM wParam,
	_Pre_maybenull_ _Post_valid_ LPARAM lParam
	) = SendMessageA;

static UINT(WINAPI* OriginalWinExec)(
	_In_ LPCSTR lpCmdLine,
	_In_ UINT uCmdShow
	) = WinExec;

static BOOL(WINAPI* OriginalCreateProcessA)(
	_In_opt_ LPCSTR lpApplicationName,
	_Inout_opt_ LPSTR lpCommandLine,
	_In_opt_ LPSECURITY_ATTRIBUTES lpProcessAttributes,
	_In_opt_ LPSECURITY_ATTRIBUTES lpThreadAttributes,
	_In_ BOOL bInheritHandles,
	_In_ DWORD dwCreationFlags,
	_In_opt_ LPVOID lpEnvironment,
	_In_opt_ LPCSTR lpCurrentDirectory,
	_In_ LPSTARTUPINFOA lpStartupInfo,
	_Out_ LPPROCESS_INFORMATION lpProcessInformation
	) = CreateProcessA;

static HINSTANCE(__stdcall *OriginalShellExecuteA)(
	_In_opt_ HWND hwnd, 
	_In_opt_ LPCSTR lpOperation, 
	_In_ LPCSTR lpFile, 
	_In_opt_ LPCSTR lpParameters,
	_In_opt_ LPCSTR lpDirectory, 
	_In_ INT nShowCmd
	)= ShellExecuteA;

static int(WINAPI* OriginalMessageBoxA)(
	_In_opt_ HWND hWnd,
	_In_opt_ LPCSTR lpText,
	_In_opt_ LPCSTR lpCaption,
	_In_ UINT uType
	) = MessageBoxA;

static BOOL(WINAPI* OriginalSetWindowTextA)(
	_In_ HWND hWnd,
	_In_opt_ LPCSTR lpString
	) = SetWindowTextA;
