#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "globals.h"

/*
	A função creat_empty_queue, cria uma fila vazia.

*/
PriorityQueue *creat_empty_queue();

/*
	A função is_empty, recebe como parâmetro o primeiro nó da fila
	e retorna verdadeiro caso a fila esteja vazia
*/

int is_empty_queue(PriorityQueue *Queue);

/*
 	A função enqueue, recebe como parâmetro a fila e o novo nó a ser 
 	adicionado. Esse novo nó é adicionado na fila deacordo com sua 
 	frequência. Onde quem tem a menor frequência tem a maior prioridade. 
	Retornando a nova fila.
*/

PriorityQueue *enqueue(PriorityQueue *Queue, Node *newNode);

/*
	A função creat_queue vai receber como parâmetro a fila. Sua função é pecorrer 
	todo array mapeado, criando uma fila de prioridade. Retornado a nova fila criada.
*/


PriorityQueue*	creat_queue	(PriorityQueue *Queue);

/*
	A função dequeue vai receber como parâmetro a fila e o nó que se quer
	remover. Sua função é retirar ele da lista e retorna-lo.
	
*/

Node*	dequeue	(PriorityQueue *Queue, Node *newNode);

/*
 	A função creat_node, recebe como parâmetro dois inteiros um é a
 	frequência do caracter e outro é a posição do caracter na tabela
 	ASCII  

*/

Node*	creat_node	(int caracter , int frequency);

/*
	A função recursiva creat_tree recebe como parâmetro a fila. E sua função é criar uma 
	árvore desenfileirando dois nós e enfileirando o novo pai na fila. Ao final da função
	o primeiro nó da fila será a raiz da árvore. Retorna a nova fila 

*/


PriorityQueue*	creat_tree		(PriorityQueue *Queue);

/*
	A função creat_father recebe como parâmetro a fila, dois nós que vão ser os respectivos
	filhos. Sua função é criar um novo nó chamado fahter, onde sua frequência vai ser a soma
	dos seus filhos e enfileira de acordo com sua prioridade. Essa função Retorna a nova fila.

*/

PriorityQueue*	creat_father		(PriorityQueue *Queue, Node *left, Node *right);

#endif
