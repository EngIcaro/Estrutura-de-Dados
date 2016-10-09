#ifndef DESCOMPRESS_H_INCLUDED
#define DESCOMPRESS_H_INCLUDED

#include "globals.h"

/*
    Função is_empty recebe como parâmetro um nó da raiz e retorna 1 caso
    aquele nó seja NULL e 0 caso contrário 

*/

int is_empty(Tree *bt);

/*
    Função creat_empty_tree, cria a raiz da árvore. com caractere '0'
    e seus filhos apontando para NULL 
*/

Tree *creat_empty_tree();

/*
    Função recreat_Tree recebe como parâmetro um caractere. Sua função é 
    criar um novo nó com o caractere recebido e apontar seus filhos para NULL.
    Retornando o nó criado.
*/
Tree *recreate_tree(char x);

/*
    Função  creat_linked_list. retorna NULL

*/

Node_list *creat_linked_list();


/*
    A função insert_node, recebe como parâmetro o caractere. Sua função é 
    criar um novo nó com esse caractere e fazer o nextNode apontar para null.

*/

Node_list *insert_node(unsigned char c);

/*
    A função is_bit_i set, recebe como parâmetro um caractere e um inteiro x. Sua função
    é chegar se um determinado bit da caractere C está setado em 1 ou 0.
*/

int is_bit_i_set(unsigned char c, int x);

/*
    Função write_extract, recebe como parâmetro um caractere, dois nós da árvore, um FILE para escrever no 
    arquivo de saída e um inteiro. Sua função é percorrer todos os bits co caractere C descobrindo se está setado
    em 1 ou 0. Se estiver setado em 1 o move_root que começa na raiz, passa a ser o filho da direita. Se for 0
    passa a ser o filho da esquerda. Quando move_root chegar em uma folha. printa o caractere da folha e move_root
    passa a ser a raiz. Byte sempre vai ser 0 menos quando c for o ultimo caractere do arquivo. onde byte vai ser = lixo
    Função retorna move_rote para não perder a referência de onde parou

*/

Tree *write_extract(unsigned char c, Tree *move_root, Tree  *root, FILE *output, int byte);

/*
    A função extract recebe como parâmetro o nó da raiz. Sua função é criar uma lista encadeada com todos os
    caracteres gerados pela compressão. E ao final da criação vai chamar a função write_extract para escrever no
    arquivo descomprimido

*/

void	extract(Tree *root);

/*
    Função recursiva recreate recebe como parâmetro um Nó de uma árvore. Sua função é percorrer a string_tree no qual
    tem a árvore da cabeçalho em pré_ordem e remonta a árvore com a função recursiva
*/

Tree	*recreate(Tree *bt);

/*
    Função descomprimir vai ler os dois primeiros bytes do arquivo. Salvar o tamanho do lixo em
    uma variável global trash e descobrir o tamanho da árvore a ser reconstruida. Salvando em uma string
    global a árvore em pré ordem.

*/

void  descomprimir();

#endif
