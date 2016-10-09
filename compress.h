#ifndef COMPRESS_H_INCLUDED
#define COMPRESS_H_INCLUDED

#include "globals.h"

/*
    A função creare_bits recebe como parâmetro a raiz da árvore e um 
    conatador iniciado em 0. Tem como objetivo mapear os bits de cada
    caracteres e salvar em um array de structs. OBS: auxi é um string
    global 
*/

void	crearebits(Node *root, int idx);

/*
    Essa função recebe como parâmetro a raiz da arvóre. E sua função
    é percorrer a árvore em pré ordem e salvar em uma string global.           
*/

void	pre_order(Node *atual);

/*
    A função creat_Header recebe como parâmetro a raiz da árvore, e tem como
    obejtivo imprimir no .huff dois caracteres nulo e a árvore em pré ordem

*/

void	creat_Header(Node *root);

/* 
    Essa função pega a string de tamanho oito com o mapeamento dos bits e transforma
    a string em um número decimal. retornando o numero em decimal. OBS: a codificação dos
    bits começa no menos significativo para o mais significativo


*/

int	nbyte(char *byte);

/*
    A função compress recebe como parâmetro o arquivo de entrada. E tem como 
    objetivo ler os caracteres do arquivo e comprimir de acordo com seu mapeamento.
    imprimindo os novos caracteres no arquivo .huff. No final ele escreve no começo
    do arquivo o primeiro byte que contem o lixo e os 5 bits da árvore e o segundo byte
    com o tamanho da árvore. Retorna o lixo
*/

int	compress(FILE *file);

#endif
