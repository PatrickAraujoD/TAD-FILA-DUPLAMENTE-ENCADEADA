#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dllist.h"

void printar_elementos(Comida *comida){
  if(comida == NULL){
    printf("\nComida não encontrada\n");
  }else{
    printf("Nome: %s, gramas: %d, preço: %.2f", comida->nome, comida->gramas, comida->preco);
  }
  printf("\n");
}

int compareComidas(void *a, void *b) {

  Comida *comidaA = (Comida *)a;
  Comida *comidaB = (Comida *)b;

  return strcmp(comidaA->nome, comidaB->nome) == 0;
}

int main(void){
  DLList *lista = NULL;
  int opcao;

  do{
    printf("\n\t============== MENU ==============\n");
    printf("\t\t1 - Criar Lista \n");
    printf("\t\t2 - Inserir uma comida \n");
    printf("\t\t3 - Remover uma comida \n");
    printf("\t\t4 - Listar todas as comidas \n");
    printf("\t\t5 - Consultar comida \n");
    printf("\t\t6 - Esvaziar lista \n");
    printf("\t\t7 - Destruir lista\n");
    printf("\t\t8 - Sair \n");
    printf("\t==================================\n");

    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        if(lista == NULL){
          lista = criar_lista();
          if(lista != NULL){
            printf("\nLista criada com sucesso!\n");
          }else{
            printf("\nnão foi possível criar a lista\n");
          }
        }else{
          printf("\nVocê já tem uma lista criada\n");
        }
        break;
      case 2:
        if(lista != NULL){
          Comida *comida = (Comida*)malloc(sizeof(Comida));
          if(comida != NULL){
            printf("\nDigite o nome da comida: ");
            scanf(" %s", comida->nome);

            printf("Digite o valor da comida: ");
            scanf(" %f", &comida->preco);

            printf("Digite as gramas da comida: ");
            scanf(" %d", &comida->gramas);

            if(inserir_elemento(lista, comida)){
              printf("\nComida inserida com sucesso\n\n");
            }else{
              printf("\nNão foi possivel inserir a comida\n\n");
            }
          }
        }else{
          printf("\nCrie a lista primeiro\n");
        }
        break;
      case 3:
        if(lista != NULL){
          if(lista_vazia(lista) == false){
            Comida chave;
            printf("\nDigite o nome da comida que deseja remover: ");
            scanf(" %s", chave.nome);

            if(remover_elemento(lista, &chave, compareComidas)){
              printf("\nComida removida com sucesso!\n");
            }else{
              printf("\nNão foi possivel achar a comida na lista\n");
            }
          }else{
            printf("\nInsira uma comida antes de tentar remover\n");
          }
        }else{
          printf("\nCrie a lista antes de tentar remover algo\n");
        }
        break;
      case 4:
        if(lista != NULL){
          if(lista_vazia(lista) == false){
            printf("\nComidas que estão na lista:\n");
            listar_elementos(lista);
          }else{
            printf("\nAdicione primeiro antes de procurar\n");
          }
        }else{
          printf("\nCrie a lista antes de tentar procurar algo\n");
        }
        break;
      case 5:
        if(lista != NULL){
          if(lista_vazia(lista)==false){
            Comida chave;
            printf("\nDigite o nome da comida que você deseja procurar: ");
            scanf("%s", chave.nome);
            printf("\n");
            Comida *resultado = (Comida*)buscar_elemento(lista, &chave, compareComidas);
            printar_elementos(resultado);
          }else{
             printf("\nAdicione primeiro antes de procurar\n");
          }
        }else{
            printf("\nCrie a lista antes de tentar procurar algo\n");
        }
        break;
      case 6:
        if(lista != NULL){
          if(lista_vazia(lista) == false){
            if(remover_todos_elementos(lista)){
              printf("\nTodos os elementos foram removidos com sucesso\n");
            }else{
              printf("\nNão foi possivel remover todas as comidas\n");
            }
          }else{
            printf("\nA lista não tem nenhuma comida dentro dela\n");
          }
        }else{
          printf("\nCrie a lista antes de tentar esvaziar ela\n");
        }
        break;
      case 7:
        if(lista != NULL){
          if(lista_vazia(lista) == false){
            printf("\nA lista não pode ser destruida, pois existem elementos nela\n");
          }else{
            if(destruir_lista(lista)){
              printf("\nLista destruida com sucesso!\n");
              lista = NULL;
            }
          }
        }else{
            printf("\nCrie a lista antes de tentar destruir ela\n");
        }
        break;
      case 8:
        printf("Programa finalizado!");
        exit(0);
        break;
      default:
        printf("\n opção inválida");
        break;
    }
    
  }while(1);
  
  return 0;
}

