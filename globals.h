#ifndef GLOBALS_H
#define GLOBALS_H

#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

#define MAX 256

char string_tree[MAX];
int array[MAX];
char auxi[MAX]; // vai ser usado pra colocar os bits na struct de bits(sequenc)
char string[8192];
int size_tree;
int trash, tree, idx;
FILE *output;

typedef struct priorityqueue PriorityQueue;
typedef struct node Node;

struct priorityqueue 
{
	Node *first;
};

struct node 
{
	int frequency;
	unsigned char caracter;
	Node *nextNode;
	Node *left;
	Node *right;
};


typedef struct Tree
{
    char character;
    struct Tree *left;
    struct Tree *right;
}Tree;

typedef struct Node_list
{
    unsigned char character;
    struct Node_list *NextNode;
}Node_list;

struct Sequenc
{
    char bits[MAX];
}sequenc[MAX];
 
#endif
