#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaBebidas.h"

struct registro
{
  char nome[20];
  int volume;
  int info;
  float preco;
};
typedef struct registro Registro;

struct no
{
  Registro Registro;
  struct no *prox;
};
typedef struct no *Lista;

Lista cria_lista()
{
  Lista cab;
  cab = (Lista)malloc(sizeof(struct no));
  if (cab != NULL)
  {
    cab->prox = NULL;
    cab->Registro.info = 0;
    // cab->info = 0;
  }
  return cab;
}

int lista_vazia(Lista lst)
{
  if (lst->prox == NULL)
  {
    return 1; // lista vazia
  }
  else
  {
    return 0;
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
int insere_elemento(Lista *lst, char *nome, int volume, float preco)
{
  Lista N = (Lista)malloc(sizeof(struct no));
  if (N == NULL)
  {
    return 0; // Falha: No nao alocado
  }
  N->Registro.preco = preco;
  N->Registro.volume = volume;
  strcpy(N->Registro.nome, nome);
  N->prox = (*lst)->prox;
  (*lst)->prox = N;
  (*lst)->Registro.info++;
  // (*lst)->info++;
  return 1;
}

int remove_ultimo(Lista *lst)
{
  if (lista_vazia(*lst) == 1)
  {
    return 0; // falha
  }
  Lista aux = *lst;
  int i = 0;

  while (i != ((*lst)->Registro.info - 1))
  {
    aux = aux->prox;
    i++;
  }
  if (aux->prox == NULL)
  {
    return 0;
  }
  Lista aux2 = aux->prox;
  aux->prox = aux2->prox;
  free(aux2);
  (*lst)->Registro.info--;
  return 1;
}

void imprime_lista(Lista lst)
{
  if (lista_vazia(lst) == 1)
  {
    printf("Lista vazia ou nao existe");
  }
  else
  {
    lst = lst->prox;
    for (lst; lst != NULL; lst = lst->prox)
    {
      printf("\n%s", lst->Registro.nome);
      printf("\n%f", lst->Registro.preco);
      printf("\n%d", lst->Registro.volume);
    }
  }
}

void libera_lista(Lista **lst)
{
  free(*lst);
  *lst = NULL;
}
