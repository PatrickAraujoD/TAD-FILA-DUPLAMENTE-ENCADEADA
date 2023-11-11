#include "dllist.h"
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

DLList *criar_lista(){
  DLList *dl;
  dl = (DLList*)malloc(sizeof(DLList));
  if(dl != NULL){
    dl->first = NULL;
    dl->cur = NULL;
    return dl;
  }
  return NULL;
}

int destruir_lista(DLList *dl){
  if(dl != NULL){
    if(dl->first == NULL){
      free(dl);
      return true;
    }
  }
  return false;
}

void inserir_elemento(DLList *dl, void *data){
  SLNode *newnode, *spec;
  if(dl != NULL){
    newnode = (SLNode*)malloc(sizeof(SLNode));
    if(newnode != NULL){
      newnode->data = data;
      newnode->next = NULL;
      if(dl->first == NULL){
        newnode->prev = NULL;
        dl->first = newnode;
      }else{
        spec = dl->first;
        while(spec->next != NULL){
          spec = spec->next;
        }
        newnode->prev = spec;
        spec->next = newnode;
      }
    }
  }
}

int remover_elemento(DLList * dl, void * key, int(cmp)(void*, void*)){
  SLNode *spec, *nextspec, *prevspec; int stat = false; void *data;
  if(dl != NULL){
    if(dl->first != NULL){
      spec = dl->first;
      stat = cmp(key, spec ->data);
      while(stat != true && spec ->next != NULL){
        spec = spec->next;
        stat = cmp(key, spec->data);
      }

      if(stat == true){
        prevspec = spec->prev;
        nextspec = spec->next;
        data = spec->data;
        if(prevspec != NULL){
          prevspec->next = nextspec;
        }
        if(nextspec != NULL){
           nextspec->prev = prevspec;
        }
        if(dl->first == spec){
          dl->first = nextspec;
        }
        free(spec);
        return true;
      }
    }
  }
  return false;
}

void *buscar_elemento(DLList * dl, void * key, int(cmp)(void*, void*)){
  SLNode *spec; int stat = false; void *data;
  if(dl != NULL){
    if(dl->first != NULL){
      spec = dl->first;
      stat = cmp(key, spec->next);
      while(stat != true && spec->next != NULL){
        spec = spec->next;
        stat = cmp(key, spec->data);
      }

      if(stat == true){
        data = spec->data;
        return data;
      }
    }
  }
  return NULL;
}

void listar_elementos(DLList * dl){
  SLNode *spec; void *data;
  if(dl != NULL){
    if(dl->first != NULL){
      spec = dl->first;
      while(spec->next != NULL){
        data = spec->data;
          printar_elementos((Comida*) data);
      }
    }
  }
}

int compareComidas(void *a, void *b) {

  Comida *comidaA = (Comida *)a;
  Comida *comidaB = (Comida *)b;

  return strcmp(comidaA->nome, comidaB->nome) == 0 &&
         comidaA->gramas == comidaB->gramas &&
         comidaA->preco == comidaB->preco;
}