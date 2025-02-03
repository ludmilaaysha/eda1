#include <stdio.h>

#define N 7

int fila[N];
int p, u;

void criar_fila (){
    p = u = 0;
}

int vazia (){ // retorna 1 se a fila estiver vazia e 0 se não estiver
    return p == u;
}

int desenfileira (){
    return fila[p++];
}

int enfileira (int x){
    fila[u++] = x;
}

int main (){

    return 0;
}