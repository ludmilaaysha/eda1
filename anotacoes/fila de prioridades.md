é uma árvore heap binária
- quase completa (folhas estao ou no último ou penúltimo nível). todos, exceto o último nível, estão cheios
- os nós do último nível estão o mais à esquerda possível

A raiz é o nó de maior ou menor prioridade, a depender do tipo de prioridade da árvore

- a ordenação não é como de uma árvore binária. a ordenação é feita com a condição de que os filhos de uma raiz sejam menores/maiores que o nó pai

##### Representada por um vetor
- Preenchimento por largura facilita a deixá-la completa
- Primeiro índice do vetor é 1 por questões de contas matemáticas
	- Os filhos de um nó de índice k são representador por 2k e 2k+1
	- Já o pai de um nó é representado pela função chão de 2k/2


## Operações com filas de prioridades
#### Inserção
![[Pasted image 20250123234152.png]]
N é uma variável auxiliar para indicar o numero de elementos da fila
Criamos a fila com maxN+1 de tamanho poruqe nao usamos o indice 0

Para inserir um item à fila, inserimos na ultima posição (após incrementar N) e chamamos a função fixUp para comparar com o nó pai e fazer swap enquanto conserta
- Complexidade dessa operação é O(logn) por conta da altura da arvore e inserção é sempre feita no fim

### Remoção
Usamoa o fixDown
O nó a ser retirado é sempre a raiz. Trocamos a raiz com o menor nó de todos através de um swap.
Com isso, comparamos essa nova raiz aos seus filhos e fazemos as trocas até chegar a um nó folha ou até a ordenação dos filhos serem menores for satisfeita.

Custo da remoção é 2logn e a complexidade é logn
![[Pasted image 20250124000020.png]]

![[Pasted image 20250124000010.png]]


## Várias filas
Além de passar o item que se quer adicionar e realizar as demais operações, temos que identificar também a fila que está sendo operada, então usamos ponteiros para realizar essas referências

### Trocar prioridade


# Algoritmos de Ordenação Eficientes
## Heap Sort
Ordenar vetores da forma **Heap Sort**
- Cria-se uma fila de prioridades
- Faz-se fizUp e depois retira o de maior prioridade

Esse método utiliza espaço extra para ordenar um vetor e substituir no original. Para solucionar esse problema, basta ordenar o vetor original com esse algoritmo, sem precisar de espaço auxiliar.

Consertamos de baixo para cima.

## Intro Sort
Pode ser uma combinação entre:
- Quick + merge(mais espaço) + insertion
- Quick + heap(maior constante) + insertion
![[Pasted image 20250128000130.png]]