# Fila de prioridades

É uma árvore _heap_ binária:
- quase completa (folhas estão ou no último ou penúltimo nível). Todos, exceto o último nível, estão necessariamente cheios
- os nós do último nível estão o mais à esquerda possível
-  a raiz é o nó de maior ou menor prioridade, a depender do tipo de prioridade da árvore
- a ordenação não é como de uma árvore binária. A ordenação é feita com a condição de que os filhos de uma raiz sejam menores/maiores que o nó pai

##### Representada por um vetor
- Preenchimento por largura facilita a deixá-la completa
- Primeiro índice do vetor é 1 por questões de contas matemáticas
	- Os filhos de um nó de índice **k** são representados por **2k** e **2k+1**
	- Já o pai de um nó é representado pela função chão de **2k/2** ($\lfloor{\frac{2k}{2}}\rfloor$)
- Se utilizar a posição 0, os filhos do índice k são 2k+1 e 2k+2

## Operações com filas de prioridades
### Criação
```c
#define Item int
#define less(A, B) ((A) < (B))
#define exch(A, B) {Item t=A; A=B; B=t;}

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
```
`N` é uma variável auxiliar para indicar o numero de elementos da fila
Criamos a fila com `maxN+1` de tamanho porque não usamos o índice 0

### Inserção
Para inserir um item à fila, inserimos na ultima posição (após incrementar N) e chamamos a função `fixUp` para comparar com o nó pai e fazer `swap` enquanto conserta
- [[complexidade]] dessa operação é $O(logn)$, por conta da altura da árvore, e inserção é sempre feita no fim

**fixUp:** quando um elemento é inserido à fila e ele é maior que seu pai, o `fixUp` conserta para cima, ou seja, troca o pai e o filho até que o pai seja maior que o filho.
```c
void PQinsert(Item v){

    pq[++N] = v;
    fixUp(N);
}
```
- Primeiro incrementa a última posição do vetor e depois insere o elemento nela
- Aplica o `fixUp` para consertar a prioridade

**fixUp**: restaura a ordenação da heap: bottom-up (swim - fixUp)
- Flutue (swap) caso a chave seja maior que seu pai
- Repetidamente, flutue até pai maior ou raiz
```c
// enquanto o pai do elemento de referência for menor que ele e o índice for maior que 1 (raiz), a troca é feita e a referência se atualiza

void fixUp (int k){

    while (k>1 && less(pq[k/2], pq[k])){
        exch(pq[k], pq[k/2]);
        // atualiza k
        k = k/2;
    }
}
```

❓**Dúvida:** Essa forma é válida?
```c
void fixUp(int k){
	if (k>1 && less(pq[k/2], pq[k])){
		exch(pq[k/2], pq[k]);
	}
	
	fixUp(k/2);
	//return;
}
```

##### <mark style="background: #D2B3FFA6; color: white">Complexidade de inserção:</mark>
- Custo: $1 + logn$, pois realiza 1 operação de inserção (incrementa N e insere o elemento) e realiza, no máximo, $logn$ operações para consertar a heap. Lembrando que $logn$ é o tamanho máximo desse tipo de árvore. 
- Portanto, a complexidade assintótica da inserção é $O(logn)$, um algoritmo de complexidade logarítmica.

### Remoção
Usamos a função `fixDown`
- O nó a ser retirado é sempre a raiz. Trocamos a raiz com o menor nó de todos (último nó folha) através de um swap.
- Com isso, comparamos essa nova raiz aos seus filhos e fazemos as trocas até chegar a um nó folha ou até que o requisito dos filhos serem menores seja satisfeito.

```c
// remover nó do topo
Item PQdelmax(){

    // troca-se o topo com o último
    exch(pq[1], pq[N]);

    // faz fixDown do primeiro item até o N-1, pois é o novo tamanho da heap
    fixDown(1, N-1);

    // retorne o removido e decremente
    return pq[N--];
}
```

**fixDown**: top-down (sink - fixDown)
- Afunda elemento caso seja menor que um dos seus filhos
	- swap com o maior filho caso seja menor que ele
- Repete-se isso
```c
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
```


#### <mark style="background: #D2B3FFA6; color: white">Complexidade de remoção:</mark>
Custo da remoção é $2logn$ e a complexidade é $O(logn)$
- Custo: a cada "nível de comparação" são realizadas duas operações; uma para verificar entre o maior entre os filhos e outra para verificar se o pai é menor, e por fim tem o swap.
- Isso acontece duas vezes a cada nível, por isso o dobro da altura máxima desse tipo de árvore
## Várias filas
Além de passar o item que se quer adicionar e realizar as demais operações, temos que identificar também a fila que está sendo operada, então usamos ponteiros para realizar essas referências

### Alterar prioridade
Se temos o índice na fila de prioridades (acesso direto), basta trocar o elemento pelo novo valor e aplicar fixUp e depois fixDown. Em um dos casos (ou nos dois) ele vai reprovar.

O código fica assim:
```c
void PQchange(int k, int value){
	p[k] = value;
	
	fixUp(k);
	fixDown(k, N);
}
```

Caso não se tenha acesso direto (através dos índices), para trocar a prioridade utilizamos uma base de dados (aqui, é a `data[i]`)
Nesse caso, temos uma base de dados à parte e o `pq[k]` é mais como um auxiliar que vai informar as prioridades.
- O índice do elemento na base de dados é o valor do elemento em `pq`. O índice em `pq` indica a sua prioridade em `data`

❓Como pq inicia?

Contudo, esse método tem um custo maior, pois para saber a prioridade de um elemento `data[i]` é preciso percorrer o `pq` inteiro para encontrar a prioridade com base na posição do elemento
- Dessa maneira, é adicionado um vetor auxiliar, que guarda tanto a posição do elemento em `data` quanto sua prioridade (índice) correspondente em `pq`
- Com isso, é possível ter acesso direto ao elemento e à sua prioridade sem precisar percorrer todo o vetor `pq`. Então ele passa de custo linear para constante
- Assim, temos:
	- `pq[k] = i`
	- `qp[i] = k`
	- `pq[qp[i]] = i`

