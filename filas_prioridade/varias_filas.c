typedef int Item;

typedef struct{
    Item *pq; // ponteiro que aponta para o início do vetor
    int N; // tamanho do vetor/numero de elementos
}PQueue;

PQueue *PQinit(int maxN);
int PQempty(PQueue*);
void PQinsert(PQueue*, Item);
Item PQdelmax(PQueue*);

void fixUp(PQueue*, int);
void fixDown(PQueue*, int);