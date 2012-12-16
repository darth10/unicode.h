# unicode.h

Micro library for cross-platform Unicode string support in C.

The library provides a handful of macros to handle Unicode strings.
You can use the `_T` macro to represent a Unicode string. For example, `_T("unicode.h")` is `"unicode.h"` in Unicode.
Several functions for basic string manipulation are also provided, and begin with the `__WC` prefix.

* For Linux, include the `unicode.h` file in your project.
* For Windows, include the `unicode.h` and `unicode.cpp` files in your project.

