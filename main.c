#include <stdio.h>
#include "dllist.c"

void printar_elementos(Comida *novaComida){
  novaComida = (Comida*)malloc(sizeof(Comida));
  if(novaComida != NULL)
      printf("Nome: %s, Preço: %.2f, Gramas: %i", novaComida->nome, novaComida->preco, novaComida->gramas);
}

