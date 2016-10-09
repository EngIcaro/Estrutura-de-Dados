#include "compress.h"
#include "descompress.h"
#include "queue.h"

int main() 
{
	int choose;
	printf("Digite:\n1: comprimir\n2:descomprimir\n");
	scanf("%d", &choose);
	if(choose == 1) 
	{
		PriorityQueue *Queue;
		int i, trash;
		FILE *file;
		file = fopen("entrada", "rb");
		char negativo;
		unsigned char positivo;
		for(i=0; i<MAX; i++)
			array[i] = 0;
		while((negativo = (positivo = fgetc(file))) != EOF)
			array[positivo]++;
		fclose(file);
		size_tree = 0;
		Queue = creat_queue(Queue);
		Queue = creat_tree(Queue);
		Node *root= Queue->first;
		crearebits(Queue->first, 0);
		Queue->first = root;
		creat_Header(Queue->first);
		trash = compress(file);
	} 
	else 
	{
		Tree *bt;
		bt = creat_empty_tree();
		descomprimir();
		bt = recreate(bt);
		extract(bt);
	}
}
