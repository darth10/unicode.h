#include <wchar.h>
#include <stdarg.h>
#include <stdlib.h>

#ifdef _WIN32
#ifndef _AFXDLL
#include <Windows.h>
#endif
#include <tchar.h>
#else
#include <string.h>
#endif

#ifndef _WIN32
#define _TCHAR	wchar_t
#define _T(x)	L##x
#define __T(x)	_T(x)
#endif

#ifndef	_UNICODE
#define _UNICODE
#endif

#define __WCHAR		wchar_t
#define __WCSTR		wchar_t *
#define __WCSTOMBS	__wcstombs
#define __WCSTRLEN	wcslen
#define __WCATOL	__wcatol
#define __WCATOI	__wcatoi
#define __WCLTOA	__wcltoa
#define __WCITOA	__wcitoa

#ifdef _WIN32
#define __WCSTRCPY	lstrcpy
#define __WCSTRCAT	lstrcat

#define __WCPRINTF	wprintf_s
#define __WCSPRINTF     swprintf_s
#define __WCFPRINTF     fwprintf_s

#define __WCSCANF	wscanf_s
#define __WCSSCANF	swscanf_s
#define __WCFSCANF	fwscanf_s
#else
#define __WCSTRCPY	wcscpy
#define __WCSTRCAT	wcscat

#define __WCPRINTF	wprintf
#define __WCSPRINTF     swprintf
#define __WCFPRINTF     fwprintf

#define __WCSCANF	wscanf
#define __WCSSCANF	swscanf
#define __WCFSCANF	fwscanf
#endif

size_t __wcstombs(char *dest, const wchar_t* src, size_t _MaxCount);
long __wcatol(wchar_t *a);
int __wcatoi(wchar_t *a);
wchar_t *__wcltoa(long l);
wchar_t *__wcitoa(int l);

#ifndef _WIN32
size_t __wcstombs(char *dest, const wchar_t* src, size_t len)
{
	size_t _size;
#ifdef _WIN32
	wcstombs_s(&_size, dest, len, src, len);
#else
	mbstate_t _state;
	memset((void*)&_state, 0, sizeof(_state));
	const __WCHAR* _temp = src;
	_size = wcsrtombs(dest, &_temp, len, &_state);
#endif
	return _size;
}

long __wcatol(wchar_t *a)
{
#ifdef _WIN32
	return _tstol(a);
#else
	return wcstol(a, NULL, 10);
#endif
}

int __wcatoi(wchar_t *a)
{
	char _temp[10];
	__wcstombs(_temp, a, 10);
	return atoi(_temp);
}

wchar_t *__wcltoa(long l)
{
	wchar_t *_retval = (wchar_t*) calloc(10, sizeof(wchar_t));
	__WCSPRINTF(_retval, 10, L"%ld", l);
	return _retval;
}

wchar_t *__wcitoa(int i)
{
	wchar_t *_retval = (wchar_t*) calloc(10, sizeof(wchar_t));
	__WCSPRINTF(_retval, 10, L"%d", i);
	return _retval;
}
#endif

