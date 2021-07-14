gcc -std=c99 -Wall -Werror -fPIC -c ia_lib.c

gcc -shared ia_lib.o -o ia.so
