#include <stdio.h>
#include <stdlib.h>

int n = 10;

typedef int Item;
typedef struct {
    Item *item;
    int primeiro, ultimo;
}Fila;

Fila * criar(int maxN) {
    Fila *p = malloc(sizeof(Fila));  // Aloca a estrutura Fila dinamicamente
    p->item = malloc(maxN * sizeof(Item));  // Aloca o vetor de itens dinamicamente
    p->primeiro = p->ultimo = 0;  // Inicializa os índices
    return p;  // Retorna o ponteiro para a estrutura Fila alocada
}

int vazia(Fila *f){
    return f->primeiro == f->ultimo;
}

int desenfileira(Fila *f){
    return f->item[f->primeiro++];
}

void enfileira(Fila *f, int z){
    f->item[f->ultimo++] = z;
}

void imprime(Fila *f){
    printf("\nFILA p = %d e u = %d\n", f->primeiro, f->ultimo);
    for (int i=f->primeiro; i<f->ultimo; i++){
        printf("F[%d]  |", i);
    }
    printf("\n");

    for (int i=f->primeiro; i<f->ultimo; i++){
        printf(" %3d  |", f->item[i]);
    }
    printf("\n");
}

void redimensiona1(Fila *f, int n){
    n *= 2;
    f->item = realloc(f->item, n*sizeof(Item));
}

void redimensiona2(Fila *f, int n){
    n *= 2;
    Item *g = malloc(n*sizeof(Item));

    int j = 0;
    for (int i = f->primeiro; i<f->ultimo; i++, j++){
        g[j] = f->item[i];
    }

    f->primeiro = 0;
    f->ultimo = j;
    
    free(f->item);
    f->item = g;
}
int main(){

    printf("\nCriando a fila e enfileirando %d elementos\n", n);
    Fila *f = criar(n);
    for (int i = 0; i<n; i++) enfileira(f, i);
    imprime(f);

    printf("\nDesenfileirando os %d primeiros elementos\n", n);
    for (int i=f->primeiro; i<3; i++) desenfileira(f);
    imprime(f);
    printf("\n");

    return 0;

    // Fila *f = criar(7);
    // int x = f->primeiro;
    // int y = f->ultimo;
    // printf("Primeira posição da fila: %d\n", x);
    // printf("Última posição da fila: %d\n", y);

    // x = vazia(f);
    // if(x){
    //     printf("Fila vazia\n");
    // }
}