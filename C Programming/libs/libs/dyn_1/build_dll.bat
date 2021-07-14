gcc -std=c99 -Wall -Werror -c ia_lib.c

gcc -shared ia_lib.o -Wl,--subsystem,windows -o ia.dll
