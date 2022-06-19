#include <stdio.h>
#include <stdlib.h>
#include "listaNaoOrdenada.h"

struct no
{
  int info;
  struct no *prox;
};
typedef struct no *Lista;

Lista inicializa_lista()
{
  return NULL;
}

int lista_vazia(Lista *lst)
{
  if (lst == NULL)
  {
    return 1; // lista vazia
  }
  else
  {
    return 0; // lista nao vazia
  }
}
/*
int lista_cheia(Lista lst)
{
  if (lst->fim == MAX)
  {
    return 1; // lista cheia
  }
  else
  {
    return 0; // lista nao cheia
  }
}
*/
int insere_elemento(Lista *lst, int elemento)
{
  Lista N = (Lista)malloc(sizeof(struct no));
  if (N == NULL)
  {
    return 0; // Falha: Nó nao alocado
  }
  N->info = elemento;
  N->prox = *lst;
  *lst = N;
  return 1;
}

int remove_elemento(Lista *lst, int elemento)
{
  if (lista_vazia(lst) == 1)
  {
    return 0; // falha
  }
  Lista aux = *lst;
  if (elemento == (*lst)->info)
  {
    *lst = aux->prox;
    free(aux);
    return 1;
  }

  while (aux->prox != NULL && aux->prox->info != elemento)
  {
    aux = aux->prox;
  }
  if (aux->prox == NULL)
  {
    return 0;
  }
  Lista aux2 = aux->prox;
  aux->prox = aux2->prox;
  free(aux2);
  return 1;
}

int obtem_valor_elemento(Lista *lst, int pos_elemento)
{
  if (lista_vazia(lst) == 1)
  {
    return 0; // falha
  }
  Lista aux = *lst;
  if (pos_elemento == (*lst)->info)
  {
    *lst = aux->prox;
    free(aux);
    return 1;
  }

  while (aux->prox != NULL && aux->prox != pos_elemento)
  {
    aux = aux->prox;
  }

  return aux->prox->info;
}

void imprime_lista(Lista *lst)
{
  if (lista_vazia(lst) == 1)
  {
    printf("Lista vazia ou nao existe");
  }
  else
  {
    while ((*lst)->prox != NULL)
    {
      printf("\n%d", (*lst)->info);
    }
  }
}

void libera_lista(Lista **lst)
{
  free(*lst);
  *lst = NULL;
}