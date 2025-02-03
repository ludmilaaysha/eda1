#include <stdio.h>
#include <stdlib.h>

int n = 10;

typedef int Item;
typedef struct {
    Item *item;
    int topo, tamanho;
}Pilha;

Pilha *criar(maxN){
    Pilha *p = malloc(sizeof(Pilha));
    p->item = malloc(maxN*sizeof(Item));
    p->topo = 0;

    return p;
}

int vazia(Pilha *p){
    return p->topo == 0; 
}

Item espia(Pilha *p){
    int x = p->topo - 1;
    return p->item[x];
}

void empilha(Pilha *p, Item x){
    p->item[p->topo++] = x;
}

Item desempilha(Pilha *p){
    return p->item[p->topo--];
}

int main(){

}