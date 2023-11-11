#ifndef __DLLIST__
#define __DLLIST__

typedef struct __comida__{
  int gramas;
  char nome[30];
  float preco;
}Comida;

typedef struct __slnode__ {
  struct __slnode__ *next, *prev;
  void *data;
}SLNode;

typedef struct __dllist__ {
  SLNode *first;
  SLNode *cur;
}DLList;


DLList *criar_lista();
void inserir_elemento(DLList *dl, void *data);
int remover_elemento(DLList * dl, void * key, int(cmp)(void*, void*));
void *buscar_elemento(DLList * dl, void * key, int(cmp)(void*, void*));
void listar_elementos(DLList * dl);
int destruir_lista(DLList *ld);
int compareComidas(void *a, void *b);
void printar_elementos(Comida *novaComida);

#endif