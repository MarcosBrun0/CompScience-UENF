//
// Created by Marcos Bruno P. Campos on 03/09/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reheapUP ( int* heap, int newNode){
    int parent;
    int hold;

    if(newNode){
        parent =(newNode-1)/2;
        if ( heap[newNode]> heap[parent])
        {

            hold = heap[ parent];
            heap[parent] = heap[newNode];
            heap[newNode] = hold;
            reheapUP(heap,parent);
        }
    }
    return;
}
void reheapDown ( int* heap, int root , int last)
{
    int hold;
    int leftkey;
    int rightkey;
    int largeChildkey;
    int largeChild_index;

    if((root*2+1)<=last)
    {
        leftkey = heap[root*2+1];
        if ((root *2+2)<= last)
            rightkey = heap[root *2+2];
        else
            rightkey = -1;
        if (leftkey > rightkey)
        {
            largeChildkey = leftkey;
            largeChild_index = root*2+1;
        }
        else
        {
            largeChildkey = rightkey;
            largeChild_index= root *2+2;

        }
        if(heap[root]< heap[largeChild_index])
        {
            hold = heap[root];
            heap[root]= heap[largeChild_index];
            heap[largeChild_index] = hold;
            reheapDown(heap, largeChild_index,last);

        }
    }
    return;

}


void HeapSort(int list[ ], int last){
//recebe o vetor e o tamanho

    int sorted;
    int holdData;


    //creat heap, coloca elementos no heao
    for (int walker = 1;walker <= last; walker++)
        reheapUP ( list, walker);

    //sort it
    sorted = last; //sorted recebe tamanho
    while(sorted>0){
        //coloca a raiz por ultimo e o ultimo no lugar da raiz e faz o reheapDown para ordenar

        holdData = list[0];
        list[0] = list[sorted];
        list[sorted ]= holdData;
        sorted--;
        reheapDown (list, 0 ,sorted);

    }
    return;
}






int main(void){
    int *vet;
    int n,i;


    printf("Digite o tamanho do vetor:");
    scanf("%d", &n);


    vet = (int*)malloc(sizeof(int) * n);
    srand(time(NULL));

    for( i = 0; i<n;i++){
        vet[i] = rand()%100;
        printf("[%d]" ,vet[i]);
    }

    printf("\n_______________HEAPSORT________________\n\n");
    HeapSort(vet, n-1);

    for(i=0;i<n;i++){
        printf("[%d]", vet[i]);
    }




    return 0;
}
