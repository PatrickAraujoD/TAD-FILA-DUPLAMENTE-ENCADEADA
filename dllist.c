#include "dllist.h"
#include <stdlib.h>
#include <stdio.h>

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

int lista_vazia(DLList *ld){
  if(ld != NULL){
    if(ld->first == NULL){
      return true;
    }
  }
  return false;
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

int inserir_elemento(DLList *dl, void *data){
  DLNode *newnode, *last;
  if(dl!=NULL){
    if(dl->first == NULL){
      last = NULL;
    }else{
      last = dl->first;
      while(last->next != NULL){
        last = last->next;
      }
    }

    newnode = (DLNode*)malloc(sizeof(DLNode));
    if(newnode != NULL){
      newnode->next = NULL;
      newnode->data = data;
      newnode->prev = last;
    }

    if(last == NULL){
      dl->first = newnode;
    }else{
      last->next = newnode;
    }
    return true;
  }
  return false;
}

int remover_todos_elementos(DLList *ld){
  DLNode *spec;
  if(ld != NULL){
    if(ld->first != NULL){
      while(ld->first != NULL){
        spec = ld->first;
        ld->first = spec->next;
        if(spec->next != NULL){
          spec->next->prev = NULL;
        }
        free(spec);
      }
      return true;
    }
  }
  return false;
}

int remover_elemento(DLList * dl, void * key, int(cmp)(void*, void*)){
  DLNode *spec, *nextspec, *prevspec; int stat = false; void *data;
  if(dl != NULL){
    if(dl->first != NULL){
      spec = dl->first;
      stat = cmp(key, spec->data);
      while(stat != true && spec->next != NULL){
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

void listar_elementos(DLList * dl){
  DLNode *spec; void *data;
  if(dl != NULL){
    if(dl->first != NULL){
      spec = dl->first;
      while(spec != NULL){
        printar_elementos(spec->data);
        spec = spec->next;
      }
    }
  }
}

void *buscar_elemento(DLList * dl, void * key, int(cmp)(void*, void*)){
  DLNode *spec; int stat; void *data;
  if(dl != NULL){
    if(dl->first != NULL){
      spec = dl->first;
      stat = cmp(key, spec->data);
      while(stat != true && spec->next != NULL){
        spec = spec->next;
        stat = cmp(key, spec->data);
      }

      if(stat == true){
        return spec->data;
      }
    }
  }
  return NULL;
}


