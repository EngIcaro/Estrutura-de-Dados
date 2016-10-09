#include "descompress.h"

int is_empty(Tree *bt){
        return (bt == NULL);
}

Tree *creat_empty_tree()
{
    Tree *bt = (Tree*) malloc(sizeof(Tree));
    bt->character = '0';
    bt->left = NULL;
    bt->right = NULL;
    return bt;
}

Tree *recreate_tree (char x)
{
    Tree *bt = (Tree*) malloc(sizeof(Tree));
    bt->character = x;
    bt->left = NULL;
    bt->right = NULL;
    return bt;
}

Node_list *creat_linked_list() 
{
    return NULL;
}

Node_list *insert_node(unsigned char c) 
{
    Node_list *new = (Node_list*) calloc(1, sizeof(Node_list));
    new->character = c;
    new->NextNode = NULL;
    return new;
}

int is_bit_i_set(unsigned char c, int x) 
{
    unsigned char mask = 1 << x;
    return mask & c;
}

Tree *write_extract(unsigned char c, Tree *move_root, Tree  *root, FILE *output, int byte) 
{
    int i;
    int bit_set;
    for(i = 7; i >= byte; i--)
    {
        bit_set = is_bit_i_set(c, i);
        if(bit_set)
            move_root = move_root->right;
        else
            move_root = move_root->left;
        if(move_root->left == NULL && move_root->right == NULL) 
        {
            fputc(move_root->character, output);
            move_root = root;
        }
    }
    return move_root;
}


void extract (Tree *root)
{
	int i, j, file_size, counter;
	unsigned char positivo;
  	j = counter = 0;
    FILE *file, *output;
    file = fopen("huffman.txt", "rb");
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);
    Node_list *first, *aux;
    first = creat_linked_list();
    positivo = fgetc(file);
    while(j < file_size-1) 
    {
    	positivo = fgetc(file);
        j++;
        if(j == size_tree+2) 
        {
            first = insert_node(positivo);
            aux = first;
            counter++;
        } 
        if(j > size_tree+2) 
        {
            aux->NextNode = insert_node(positivo);
            aux = aux->NextNode;
            counter++;
        }
    }
    Tree *move_root = root;
    output = fopen("final.txt", "wb");
    for(i=0; i<counter-1; i++) 
    {
        move_root = write_extract(first->character, move_root, root, output, 0);
        aux = first;
        first = first->NextNode;
        free(aux);
    }
        move_root = write_extract(first->character, move_root, root, output, trash);
        free(first);
}


Tree *recreate(Tree *bt)
{
    if(string_tree[idx] == '\\') 
    {
	    idx++;
        bt = recreate_tree (string_tree[idx]);
        return bt;
    }
    bt = recreate_tree (string_tree[idx]);
    if(string_tree[idx] != '*')return bt;
    idx += 1;
    bt->left = recreate(bt->left);
    idx += 1;
    bt->right = recreate(bt->right);
    return bt;
}

void descomprimir() 
{
    int i;
    FILE *file;
    file = fopen("huffman.txt", "rb");
    unsigned char first_byte, second_byte;
    first_byte = fgetc(file);
    trash = 0;
    trash = first_byte>>5;
    size_tree  = 0;
    size_tree |= (first_byte<<3)&(0xFF);
    size_tree = size_tree<<5;
    second_byte = fgetc(file);
    size_tree |= second_byte;
    for(i=0; i<size_tree; i++)
        string_tree[i] = fgetc(file);
}