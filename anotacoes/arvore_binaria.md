# Conceitos importantes sobre árvores
- Grau de uma árvore: quantidade de filhos (subárvores) de um nó;
- Um nó folha possui grau 0, ou seja, não possui filhos
- Árvores n-árias: quando todos os nós possuem grau máximo n
### Profundidade
A profundidade de uma árvore é definida pelo caminho máximo que leva para chegar a um nó folha. É o máximo de arestas em um caminho de árvore de um nó x até a raiz. A raiz possui profundidade 0.
### Altura
É a quantidade de "andares" de nós na árvore. O nó raiz representa altura 0 e a altura é a maior profundidade de um nó externo (NULL).

# Árvores Binárias
Uma árvore binária é uma estrutura composta de nós que se interligam. O ponto de partida de uma árvore binária é o nó raiz, a partir do qual são gerados todos os outros.
- Cada nó possui um endereço que o identifica na memória e dois ponteiros, que indicam seus filhos à esquerda e à direita.
- Uma folha é um nó que não tem filho algum
- Nós internos são nós que não estão nas extremidades da árvore, ou seja, não são nós folha nem raiz.

```c
typedef struct reg { //usamos o nome alternativo reg por conta da autorreferencia que a estrutura faz a si mesma internamente
	int conteudo;
	no *esq;
	no *dir;
}no;
```

Um ponteiro-para-arvore `r` é uma árvore binária se
1. `r` é `NULL` ou
2. `r->esq` e `r->dir ` são arvores binárias

### Tipos
- Estritamente Binária: Os nós tem 0 ou 2 filhos
- Binária Quase Completa: todas as folhas estão no nível "d" ou "d-1"
	- Distância de, no máximo, 1 nível entre as folhas
- Binária Completa: todas as folhas estão em um mesmo nível
- Binária Cheia: árvore estritamente binária e completa

### Propriedades
- Se há $N$ nós internos, então há $N+1$ nós externos
- Se a altura é $h$, então a árvore:
	- tem no mínimo $h$ nós internos (a árvore pode ser apenas um tronco sem galhos)
	- Tem, no máximo, $2^{h}-1$ nós internos 
- Se a árvore tem $n>=1$ nós, então a altura:
	- é, no mínimo, $\lceil \log{(n+1)} \rceil$ quando a árvore é completa
		- já que o máximo de nós internos de uma árvore binária é $2^h-1$ , somando ambos os lados por $1$ e aplicando $\log$ em ambos os lados, temos que $log(n+1) = h$. 
	- é, no máximo, $n$: quando cada nó interno tem apenas um filho

## Implementações
#### Criar árvore
```c
typedef struct node no;
struct node{
	Item *item;
	no *pai;
	no *esq, *dir;
}

no *criar_arvore(Item x, no *p, no *esq, no *dir){
	no *raiz = malloc(sizeof(no));
	raiz->pai = pai
	raiz->esq = esq;
	raiz->dir = dir;
	raiz->item = x;
	
	return raix;
}
```

# Varredura da árvore
## Percurso em largura
A árvore é visitada por nível. Todos os elementos de um mesmo nível são visitados antes de descer o nível

## Percurso em profundidade
Cada subárvore é visitada uma de cada vez. O percurso é feito recursivamente (da esquerda para a direita). Há algumas ordens de processamento que podem ser seguidas:
### Em-Ordem (inordem)
*7 + - 3 - 9 / 3 x 9 ^2*
Ocorre na ordem esquerda-raiz-direita, e todas as subárvores dessa árvore também são varridas dessa maneira.

Essa varredura pode ser feita por meio de uma função recursiva
```c
//Recebe a raiz de uma árvore binária e imprime os conteúdos dos seus nós em ordem e-r-d

void erd(no *raiz){
	if (raiz != NULL){
		erd(raiz->esq);
		printf("%d\n", raiz->conteudo);
		erd(r->dir);
	}
}
```

Também há a versão iterativa, que utiliza o conceito de [[pilhas]]
```c
void erd_i(node *raiz){
	criapilha(); //cria uma pilha de nós
	empilha(raiz); //empilha o nó mais acima
	while(true){
		x = desempilha();
		if (x != NULL){
			empilha(x);
			empilha(x->esq);
		}
		else{
			if (pilhavazia()) break;
			x = desempilha();
			printf("%d\n", x->conteudo);
			empilha(x->dir);
		}
	}
	liberapilha();
}
```

## Pré-Ordem
*Notação: / + 7 - - 3 9 ^ x 3 9 2

Ocorre da raiz-esquerda-direita (ex.: notacao polonesa)
- Primeiro visita/processa a raiz
- Visita/processa a subárvore à esquerda
- Visita/processa subárvore à direita

```c
void preordem(no *raiz){
	if (raiz!=NULL){
		printf("%d", raiz->dado);
		preordem(raiz->esq);
		preordem(raiz->dir);
	}
}
```

Também é possível implementar com pilhas
```c
void pre_ordem(no *raiz){
	cabeca *p;
	p = criar_pilha();

	empilha(p, raiz);

	while (!vazia(p)){
		raiz = (desempilha(p));

		if (raiz != NULL){
			printf("%d", raiz->dado);

			empilha(p, raiz->dir);
			empilha(p, raiz->esq);
		}
	}
	free(p);
}
```

## Pós-Ordem
*Notação: 7 3 - 9 - + 3 9 x 2 ^ /*

Primeiro processa subárvore à esquerda, depois à direita, e depois a raiz

```c
void posordem(no *raiz){
	if (raiz != NULL){
		posordem(raiz->esq);
		posordem(raiz->dir);
		printf("%d", raiz->conteudo);
	}
}
```