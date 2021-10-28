# -*- Made by Facundo Diaz for Holberton School 2021 -*-

aux = hnm
aux2 = hobjdump 

compilador = gcc
flags_compilacion = -Wall -Werror -Wextra -pedantic -g
ubicacion = src
i = hreadelf

FIRST = symbolnames
SECOND = objdump
COMUN = common_tools
HEADER = print_header
OBJ0 += $(patsubst %.c, %.o, $(wildcard $(ubicacion)/$(FIRST)/*.c))
OBJ1 += $(patsubst %.c, %.o, $(ubicacion)/$(SECOND)/0-main.c)

$(aux): $(OBJ0)
	$(compilador) $(OBJ0) -o $(aux)

$(aux2): $(OBJ1)
	$(compilador) $(OBJ1) -o $(aux2)
