gcc -std=c99 -Wall -Werror -D IA_EXPORTS -c ia_lib.c

gcc -shared ia_lib.o -Wl,--subsystem,windows -o ia.dll
