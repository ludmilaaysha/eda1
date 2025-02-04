#define Item int
#define less(A, B) ((A) < (B))
#define exch(A, B) {Item t=A; A=B; B=t;}

// typedef struct{
//     int priority;
//     int value;
// }Item;

//static: acessível somente no arquivo
static Item *pq; // apontador que irá apontar para o início da fila
static int N; // representa a quantidade de elementos da fila. Quando ela é criada, o N é inicializado com 0

void PQinit(int maxN) {
    // cria uma fila com maxN+1 elementos. O início da fila é apontado por pq
    pq = malloc(sizeof(Item)*(maxN+1));
    // N é inicializado com 0 (pois a fila está vazia)
    N = 0;
}

// função para verificar se a fila está vazia. Se for verdade, no condicional o retorno será 1
int PQempty() {
    return N==0;
}

void PQinsert(Item v){
    pq[++N] = v;

    fixUp(N);
}

// enquanto o pai do elemento de referência for menor que ele e o índice for maior que 1 (raiz), a troca é feita e a referência se atualiza
void fixUp (int k){
    while (k>1 && less(pq[k/2], pq[k])){
        exch(pq[k], pq[k/2]);
        k = k/2;
    }
}


// O código a seguir é válido?
// void fixUp(int k){
// 	if (k>1 && less(pq[k/2], pq[k])){
// 		exch(pq[k/2], pq[k]);
// 	}

// 	fixUp(k/2);
// 	// return;
// }

// remover nó do topo
Item PQdelmax(){
    // troca-se o topo com o último
    exch(pq[1], pq[N]);
    // faz fixDown do primeiro item até o N-1, pois é o novo tamanho da heap
    fixDown(1, N-1);
    // retorne o removido e decremente
    return pq[N--];
}

void fixDown(int k, int n){
    int j;
    while (2*k <= N){
        // variável que auxilia comparações
        j = 2*k;

        // se o índice do filho à esquerda for o menor que o último índice e menor que o filho à direita, a referência passa a ser o filho à direita
        if (j<N && less(pq[j], pq[j+1])) j++;

        // se o maior filho do nó for menor que ele, nada acontece
        if (!less(pq[k], pq[j])) break;

        //caso contrário, o maior nó ocupa o lugar e k é atualizado
        exch(pq[k], pq[j]);
        k = j;
    }

}

