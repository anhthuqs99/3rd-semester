#ifndef __IA__LIB__H__

#define __IA__LIB__H__

__declspec(dllexport) int __cdecl ia_read(int *arr, int n);

__declspec(dllexport) float __cdecl ia_calc_avg(const int *arr, int n);

__declspec(dllexport) void __cdecl ia_print(const int *arr, int n);

#endif  // __IA__LIB__H__
