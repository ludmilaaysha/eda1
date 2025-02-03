As pilhas (stack) utilizam o comportamento LIFO (Last In, First Out), ou seja, o primeiro elemento a entrar é também o primeiro a sair.

Pilhas tem algumas operações básicas, assim como as filas:
- **criar**: cria uma pilha vazia
- **vazia**: verifica se a pilha está vazia
- **empilhar**: insere novo item no topo
- **desempilhar**: retira item que está no topo
- **espiar**: devolver item do topo sem fazer nenhuma operação

**⚠️Buscas em profundidade utilizam conceitos de pilha para operar**

# Listas estáticas
Tendo um vetor de tamanho N, ele pode ser representado por `pilha[0..N-1]`. O espaço que a pilha ocupa é `pilha[0..t-1]`, em que a variável `t` representa o topo.

Inserções e remoções são sempre feitas pelo topo, e a posição `pilha[t]` está sempre vazia para armazenar o próximo topo.

