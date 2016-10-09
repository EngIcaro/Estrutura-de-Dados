#Todos os seus .c
OBJS	=	compress.c	\
		descompress.c	\
		main.c		\
		queue.c

#Todos os seus .h
DEPS	=	compress.h	\
		descompress.h	\
		queue.h         \
		globals.h   
#Seu compilador
CC = gcc

#Suas flags
COMPILER_FLAGS	=	-w -std=c11

#Nome do seu executavel
OBJ_NAME	=	Huffman

#Todos os alvos marcados para a compilação
all : $(OBJS)
	$(CC) $(OBJS) $(DEPS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
