#include "unicode.h"

#ifdef _WIN32
#include "stdafx.h"

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
