#ifndef __IA__LIB__H__

#define __IA__LIB__H__


// Макрос IA_EXPORTS необходимо определить только при сборке DLL
#ifdef IA_EXPORTS
    #define IA_DLL __declspec(dllexport)
#else
    #define IA_DLL __declspec(dllimport)
#endif

// Соглашение о вызовах
#define IA_DECL __cdecl


IA_DLL int IA_DECL ia_read(int *arr, int n);

IA_DLL float IA_DECL ia_calc_avg(const int *arr, int n);

IA_DLL void IA_DECL ia_print(const int *arr, int n);

IA_DLL int IA_DECL ia_filter_pos(const int *src_arr, int src_n, int *dst_arr, int *dst_n);

#endif  // __IA__LIB__H__
