Filas são estruturas de dados que respeitam o FIFO (First In First Out), em que, como o próprio nome diz, o primeiro elemento que foi inserido é também o que é processado primeiro.

#### Como funciona?
Uma fila pode ser um vetor ou até uma lista encadeada. Além da estrutura com tamanho n fixo, essa técnica conta com duas variáveis auxiliares, que indicam o início e o fim da fila
- São n posições, enumeradas de 0..n-1
- A variável p marca o início da fila
- A variável u marca o fim da fila, e sempre guarda uma posição vazia
- Se p=u, então a fila está vazia

## Criar fila
Você define um array com N posições e, para inicializar a fila, você define as variáveis p e u como 0, pois a fila é criada vazia.
```c
#define N 7

int fila[N];
int p, u;

void criar_fila (){
	p = u = 0;
}
```

## Verificar fila vazia
Para operar com as filas, precisamos fazer algumas verificações, como se ela está vazia. Para verificar isso, basta saber se o índice p e u são iguais.
```c
int verifica_vazia (){
	return p == u;
}
// se p e u indicarem a mesma posição, a função retornará 1
```


## Remover um elemento
O primeiro elemento é o que será sempre removido. Para isso, devemos retorná-lo para a função que o chamou e atualizar o primeiro elemento, que será o próximo.
```c
int desenfileira (){
	return fila[p++];
	// ou seja, primeiro ele retorna o primeiro elemento e depois incrementa a posição
}
```

## Inserir um elemento
A inserção de um elemento na fila é sempre feita no final dela, ou seja, na posição u. Para isso, é necessário inserir e incrementar u, para que aponte para a próxima posição vazia.
```c
int enfileira (int y){
	fila[u++] = y;
}
```


## Redimensionamento de filas estáticas
Se uma fila estática precisa ser redimensionada, o ideal é sempre dobrar seu tamanho para evitar novos redimensionamentos. Fazemos isso com `realloc`

# Filas circulares
Como uma lista possui um tamanho limitado `N` e as posições de início vão sendo liberadas a cada desenfileiramento, é possível implementar o conceito de **filas circulares**, em que, após o `u` atingir a posição `N-1`, ele vai passa para a posição `0` no próximo enfileiramento, caso a fila não esteja vazia.
Para esse tipo de fila, também precisamos fazer algumas verificações:
- **Fila vazia**: se `p == u`
- **Fila cheia**: se `u+1 == p`   ou  ` u+1 == N && p == 0`   (ou seja, se (u+1) % N == p).

As operações com filas circulares são:

## Verificar fila vazia
Novamente, a fila está vazia se os índices `p` e `u` são iguais.

## Verificar fila cheia
A fila está cheia se  `u++ == p` ou se `p == 0 && u == N-1`.  Ou seja,
- se `(u+1) % N == p`, a lista está cheia.
Assim, fazemos a verificação:
```c
int vazia (){
	return (u++)%N == p;
}
```


<p style="background: rgba(153, 0, 173, 0.20);"><b>Decisão de projeto</b>: a posição anterior à p sempre fica vazia para diferenciar uma lista cheia de uma vazia, pois a lista cheia tem <code>u+1 == p</code> e a lista vazia tem <code>p == u</code>.</p>
## Remover um elemento
Basta guardar o valor do primeiro elemento e atualizar o índice `p`. Se o próximo índice for o `N`, então `p` deve voltar para o começo, ou seja, ter valor 0 atribuído a ele. Aí sim que retornamos o primeiro elemento.
```c
int desenfileira (){
	int x = fila[p++];
	if (p == N) p = 0;
	return x;
}
```
Esse código é válido apenas para caso da fila não estar vazia.

## Inserir elemento
Colocamos na fila inserindo na posição `u` e atualizando ela. Por ser circular, também devemos encaminhá-la para a posição inicial se chegar ao fim.
```c
void enfileira (int y){
	fila[u++] = y;
	if (u == N) u = 0;
}
```
Este código é válido apenas para o caso da fila não estar cheia, pois senão sobrescreverá o primeiro elemento.

# Lista encadeada
É possível implementar todas as funções também em listas encadeadas, como desenfileira e enfileira, além de verificações como saber se a fila está vazia.

O acesso ao primeiro elemento é constante a todos os tipos de listas, pois a informação está na cabeça ou no apontador do primeiro elemento da lista.

O acesso ao último elemento pode mudar de acordo com o tipo de lista
- **Simplesmente/duplamente encadeada com cabeça**:
	- metadados: `lista->ultimo;`

- **Duplamente encadeada circular**: Basta acessar o anterior do primeiro nó, pois estão ligados
	- `*no ultimo = lista->prox->ant`

- **Simplesmente encadeada circular modificada**: 
	- como só se tem informação do próximo elemento, insere-se o elemento na cabeça, pois o penúltimo elemento continuará apontando para o último elemento sem precisar percorrer toda a lista.  
	- Cria-se uma nova cabeça, para a qual o novo último elemento apontará.
	- A nova cabeça aponta para o próximo da antiga cabeça

- **Simplesmente encadeada com cauda**: há um apontador direto para a cauda
- **Simplesmente encadeada**: Cauda aponta para o último e a inserção ocorre a partir dela

## Verificar lista vazia
A fila está vazia quando o `prox` da cabeça aponta para ela mesma ou para `null`, a depender da escolha de projeto.

## Inserir elemento
```c
void enfileira(cabeca *lista, Item x){
	*no novo = criar_no(x)
	if (novo){
		if (vazia(lista)) lista->prox = x;
		else lista->ultimo->prox = novo;

		lista->ultimo = novo;
		novo->prox = NULL;

		lista->tam++
	}
}
```
 
## Remover elemento
```c
Item desenfileira(cabeca *lista){
	no *lixo = lista->prox;
	lista->prox = lixo->prox;

	lista->tam--

	Item x = lixo->item;
	free(lixo);
	return x;
}
```









Make a note of something, [[create a link]], or try [the Importer](https://help.obsidian.md/Plugins/Importer)!

When you're ready, delete this note and make the vault your own.