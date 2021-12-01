// Copyright (c) 2021 Frederic 경진 Rezeau.

#ifndef COMMON_H
#define COMMON_H

#ifdef __linux__
    #include <sys/mman.h>
#elif _WIN32
    #include <windows.h>
#else
#error Platform not supported
#endif

#define DECLARE_NO_COPY(TypeName) \
    private: \
    explicit TypeName(const TypeName&); \
    void operator=(const TypeName&);

// byte type.
using byte = uint8_t;

template <typename T, size_t N>
T* begin(T(&arr)[N]) { return &arr[0]; }
template <typename T, size_t N>
T* end(T(&arr)[N]) { return &arr[0] + N; }

namespace litemint
{
};

#endif // COMMON_H
