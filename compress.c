#include "compress.h"

void crearebits(Node *root, int idx)
{
    if(root->left != NULL) 
    {
        auxi[idx] = '0';
        crearebits(root->left, idx+1);
    } 
    if(root->right != NULL)
    {
        auxi[idx] = '1';
        crearebits(root->right, idx+1);
    } 
    if(root->left == NULL && root->right == NULL)
        memcpy(sequenc[root->caracter].bits, auxi, idx);
}


void pre_order(Node *atual)
{
    if(atual != NULL) 
    {
        if((atual->caracter == '*') && (atual->left == NULL) &&(atual->right == NULL))
        {
            string[size_tree++] = '\\';
            string[size_tree++] = '*';
        } 
        else if ((atual->caracter == '\\') && (atual->left == NULL) && (atual->right == NULL))
        {
            string[size_tree++] = '\\';
            string[size_tree++] = '\\';
        } 
        else 
        {
            string[size_tree++] = atual->caracter;
            pre_order(atual->left);
            pre_order(atual->right);
        }
    }
}




void creat_Header(Node *root)
{
    int i=0;
    output =  output = fopen("huffman.huff", "wb");
    pre_order (root);
    fputc('0', output);
    fputc('0', output);
    while(string[i] != '\0')
        fputc(string[i++], output);
}


int potencia(int i,int j)
{
    int result=1;
    while(j--)
        result*=i;
    return result;
}

int nbyte(char *byte)
{
    int i, k;
    k = 0;
    int contador = 0;
    for(i = 7; i>=0; i--) 
    {
        if(byte[i] == '1')
        {
            contador += potencia(2, k);
        }
        k++;
    }
    return contador;
}

int compress(FILE *file)
{
    file = fopen("entrada", "rb");
    fseek(file, 0, SEEK_END);
    int file_size;
    file_size = ftell(file);
    rewind(file);
    int i, k, trash, j;
    k = trash = j = 0;
    unsigned char x, positivo;
    char apoio[20];
    char byte[8];
    memset(apoio, '*', sizeof apoio);
    memset(byte, '*', sizeof byte);

    while(j < file_size) 
    {
        j++;
        positivo = fgetc(file);
        memcpy(apoio, sequenc[positivo].bits, strlen(sequenc[positivo].bits));
        for(i = 0; apoio[i] != '*'; i++)
        {
            byte[k] = apoio[i];
            k++;
            if(k == 8)
            {
                x = nbyte(byte);
                fputc(x, output);
                k = 0;
                memset(byte, '*', sizeof byte);
            }
        }
            memset(apoio, '*', sizeof apoio);
    }
    if(k>0)
    {
        trash = (8 - k);
        x = nbyte(byte);
        fputc(x, output);
    }
    unsigned char first_byte, second_byte;
    first_byte = second_byte = 0;
    first_byte |= trash<<5;
    first_byte |= ((size_tree>>8)&(0xFF));
    second_byte = (size_tree)&(0xFF);
    fseek(output, 0, SEEK_SET);
    fputc(first_byte, output);
    fputc(second_byte, output);
    return trash;
}
