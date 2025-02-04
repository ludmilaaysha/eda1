typedef struct {
    char nome[20];
    int chave;
}Item;

static int *pq;
static int *qp;
static int N;

void PQinit(int);
void PQinsert(int);
void PQchange(int);
void PQdelmax();

int main(){
    Item data[6] = {
        {"José", 10},
        {"Maria", 9},
        {"Júlio", 4},
        {"Paulo", 23},
        {"Ana", 30},
        {"Carla", 17},
    };

    PQinit(6);
    for (int i=0; i<6; i++) PQinsert(i);
}