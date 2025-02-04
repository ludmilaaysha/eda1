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