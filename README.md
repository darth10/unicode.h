# unicode.h

Micro library for cross-platform Unicode string support in C.

The library provides a handful of macros to handle Unicode strings.
You can use the `_T` macro to represent a Unicode string. For example, `_T("unicode.h")` is `"unicode.h"` in Unicode.
Several functions for basic string manipulation are also provided, and begin with the `__WC` prefix.

Make sure you add a `#include "unicode.h"` directive to your source files.

* For Linux, include the `unicode.h` file in your Makefile.
* For Windows, include the `unicode.h` and `unicode.cpp` files in your Visual Studio project.

