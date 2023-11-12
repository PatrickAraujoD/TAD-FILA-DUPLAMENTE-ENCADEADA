#ifndef __DLLIST__
#define __DLLIST__
#define true 1
#define false 0

typedef struct __comida__{
  int gramas;
  char nome[30];
  float preco;
}Comida;

typedef struct __slnode__ {
  struct __slnode__ *next, *prev;
  void *data;
}DLNode;

typedef struct __dllist__ {
  DLNode *first;
  DLNode *cur;
}DLList;


DLList *criar_lista();
int inserir_elemento(DLList *dl, void *data);
int remover_elemento(DLList * dl, void * key, int(cmp)(void*, void*));
int remover_todos_elementos(DLList *ld);
void *buscar_elemento(DLList * dl, void * key, int(cmp)(void*, void*));
void listar_elementos(DLList * dl);
int destruir_lista(DLList *ld);
int compareComidas(void *a, void *b);
void printar_elementos(Comida *novaComida);
int lista_vazia(DLList *ld);

#endif