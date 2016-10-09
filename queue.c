#include "queue.h"

PriorityQueue *creat_empty_queue() 
{
	PriorityQueue *newQueue = (PriorityQueue*) calloc(1, sizeof(PriorityQueue));
	newQueue->first = NULL;
	return newQueue;
}

int is_empty_queue(PriorityQueue *Queue) 
{
	return(Queue->first == NULL);
}

Node *creat_node(int caracter , int frequency) 
{
	Node *newNode = (Node*) calloc(1,sizeof(Node));
	newNode->frequency = frequency;
	newNode->caracter = caracter;
	newNode->nextNode = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

PriorityQueue *enqueue(PriorityQueue *Queue, Node *newNode) 
{
	if(is_empty_queue(Queue) || newNode->frequency < Queue->first->frequency) 
	{
		newNode->nextNode = Queue->first;
		Queue->first = newNode;
	} 
	else 
	{
		Node *aux = Queue->first;
		while((aux->nextNode != NULL) && (aux->nextNode->frequency < newNode->frequency))
			aux = aux->nextNode;
		
		newNode->nextNode = aux->nextNode;
		aux->nextNode = newNode;
	}
	return Queue;
}

PriorityQueue *creat_queue(PriorityQueue *Queue)
{
	Queue = creat_empty_queue();
	int i;
	for(i = 0; i < MAX; i++)
		if(array[i] != 0) 
		{
			Node *newNode = creat_node(i, array[i]);
			enqueue(Queue, newNode);
		}
	Node *aux = Queue->first;
	while(aux!= NULL)
		aux = aux->nextNode;
	return Queue;
}

Node *dequeue(PriorityQueue *Queue, Node *newNode){
	newNode = (Node*) calloc(1,sizeof(Node));
	Node *aux = Queue->first;
	newNode->caracter = Queue->first->caracter;
	newNode->frequency = Queue->first->frequency;

	if(Queue->first->left != NULL && Queue->first->right != NULL) 
	{
		newNode->left = Queue->first->left;
		newNode->right = Queue->first->right;
	} 
	else 
	{
		newNode->left = NULL;
		newNode->right = NULL;
	}

	Queue->first = Queue->first->nextNode;
	free (aux);
	return newNode;
}

PriorityQueue *creat_tree(PriorityQueue *Queue) 
{
	if((!is_empty_queue(Queue)) && Queue->first->nextNode != NULL) 
	{
		Node *left = dequeue(Queue, left);
		Node *right = dequeue(Queue, right);
		Queue = creat_father(Queue, left, right);
		creat_tree(Queue);
	}
	return Queue;
}

PriorityQueue *creat_father(PriorityQueue *Queue, Node *left, Node *right) 
{
	Node *father = (Node*) calloc(1,sizeof(Node));
	father->caracter = '*';
	father->frequency = (left->frequency + right->frequency);
	father->left = left;
	father->right = right;
	Queue = enqueue(Queue,father);
	return Queue;
}
