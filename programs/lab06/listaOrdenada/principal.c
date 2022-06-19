#include <stdio.h>
#include <stdlib.h>
#include "listaOrdenada.h"

int main()
{
  int op;
  Lista lst;

  do
  {
    do
    {
      printf("\n --- LISTAS DINAMICA ENCADEADA --- \n\n");
      printf(" Escolha uma opcao\n");
      printf(" 1. Criar lista\n");
      printf(" 2. Verificar lista vazia\n");
      printf(" 3. Verificar lista cheia\n");
      printf(" 4. Inserir elemento\n");
      printf(" 5. Remover elemento\n");
      printf(" 6. Liberar lista\n");
      printf(" 7. Obter valor de um elemento\n");
      printf(" 8. Imprimir lista\n");
      printf(" 9. SAIR\n");
      printf(" Opcao: ");
      scanf("%d", &op);
      if ((op < 1) || (op > 9))
      {

        printf("\n\n Opcao Invalida! Tente novamente...");
        system("CLS || clear");
      }
    } while ((op < 1) || (op > 9));

    switch (op)
    {
    case 1:
      printf("\n\n Criar lista");
      lst = inicializa_lista();
      break;

    case 2:
      printf("\n\n Ver se lista esta vazia");
      int flag = lista_vazia(lst);
      if (flag == 1)
      {
        printf("\nLista vazia");
      }
      if (flag == 0)
      {
        printf("\nLista nao vazia");
      }
      break;

    case 3:
      printf("\n\n Ver se lista esta cheia");
      // int flag2 = lista_cheia(lst);
      int flag2 = 0;
      if (flag2 == 1)
      {
        printf("\nLista cheia");
      }
      if (flag2 == 0)
      {
        printf("\nLista nao cheia");
      }
      break;

    case 4:
      printf("\n\n Inserir elemento");
      int elem;
      printf("\n Qual elemento deseja inserir: ");
      scanf("%d", &elem);
      int flag3 = insere_ord(&lst, elem);
      if (flag3 == 1)
      {
        printf("\n Elemento inserido com sucesso");
      }
      if (flag3 == 0)
      {
        printf("\nFalha na insercao");
      }
      break;

    case 5:
      printf("\n\n Qual elemento deseja remover: ");
      int elem2;
      scanf("%d", &elem2);
      int flag4 = remove_ord(&lst, elem2);
      if (flag4 == 1)
      {
        printf("\n Elemento removido com sucesso");
      }
      if (flag4 == 0)
      {
        printf("\nFalha na remocao");
      }
      break;

    case 6:
      printf("\n\n Liberar lista");
      libera_lista(&lst);
      break;

    case 7:
      printf("\n\n Qual posicao do elemento que deseja: ");
      int pos;
      scanf("%d", &pos);
      int elemento_desejado = obtem_valor_elemento(lst, pos);
      printf("elemento desejado: %d", elemento_desejado);
      break;

    case 8:
      printf("\n\n Imprimir lista");
      imprime_lista(lst);
      break;

    default:
      printf("\n\n Pressione qualquer tecla para FINALIZAR...");
    }
  } while (op != 9);

  return 0;
}