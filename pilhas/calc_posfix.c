#include <stdio.h>
#include <stdlib.h>



int main(Pilha *p, int argc, char *argv[]){
    char *a = argv[1];
    head *pilha = criar_lista();

    for(int i=0; a[i]!='\0'; i++){
        if (a[i] == '+'){
            empilha(pilha, desempilha(pilha) + desempilha(pilha));
        }
        if (a[i] == '-'){
            empilha(pilha, desempilha(pilha) - desempilha(pilha));
        }
        if (a[i] == '/'){
            empilha(pilha, desempilha(pilha) / desempilha(pilha));
        }
        if (a[i] == '*'){
            empilha(pilha, desempilha(pilha) * desempilha(pilha));
        }
    }


    return 0;
}