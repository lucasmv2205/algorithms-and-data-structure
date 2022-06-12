// Nome: ListaNaoOrdenada
// Dados: nome(char), volume(inteiro)[ml], preco(float)
// Lista das operações: inicializa_lista, lista_vazia, lista_cheia, insere_elemento, remove_ultimo, libera_lista, imprime_tabela
typedef struct lista Lista;

// Entradas: nenhuma
// Pre-condicao: nenhuma
// Processo: criar uma Lista sem valores definidos e aloca espaco na memoria
// Saida: endereço de uma Lista criada
// Pos-condicao: nenhuma
Lista *inicializa_lista();

// Entradas: endereco de uma Lista
// Pre-condicao: nenhuma
// Processo: Verifica se existe algum elemento na lista ou se ela nao possui elementos
// Saida: 1 caso lista esteja vazia, 0 se nao houver elementos ou lista for nula
// Pos-condicao: nenhuma
int lista_vazia(Lista *lst);

// Entradas: endereco de uma Lista
// Pre-condicao: lista ser valida
// Processo: Verifica se a quantidade maxima, 20 elementos, foi atingida
// Saida: 1 caso lista esteja cheia, 0 se quantidade maxima nao foi atingida, ou seja, lista nao cheia
// Pos-condicao: nenhuma
int lista_cheia(Lista *lst);

// Entradas: endereco da lista, nome do elemento, seu volume e preco
// Pre-condicao: lista ser valida e nao estar cheia
// Processo: inserir registro(nome, volume e preco) no final da lista
// Saida: 1 se sucesso ou 0 se falha
// Pos-condicao: lista de entrada com registro a mais
int insere_elemento(Lista *lst, char *nome, int volume, float preco);

// Entradas: endereco de uma lista
// Pre-condicao: lista ser valida e nao estar vazia
// Processo: remover o ultimo elemento da lista e decrementar quantidade de elementos da lista
// Saida: 1 se sucesso ou 0 se falha
// Pos-condicao: lista de entrada com um elemento a menos(sem o ultimo elemento)
int remove_ultimo(Lista *lst);

// Entradas: endereco de memoria do endereco de memoria de uma Lista
// Pre-condicao: nenhuma
// Processo: limpar a memoria utilizada pela Lista e limpar seu endereco de memoria tambem
// Saida: nenhuma
// Pos-condicao: endereco da lista liberado
void libera_lista(Lista **lst);

// Entradas: endereco da lista
// Pre-condicao: lista ser valida e nao estar vazia
// Processo: percorrer a lista e printar cada elemento.
// Saida: nenhuma
// Pos-condicao: nenhuma
void imprime_tabela(Lista *lst);