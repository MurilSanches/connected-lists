#ifndef LISTA_CIRCULAR
#define LISTA_CIRCULAR
#include "lista_duplamente_ligada.h"

typedef void* Elemento;

typedef struct NoListaCircular {
    Elemento informacao;
    struct NoListaCircular* proximo;
} NoListaCircular;

typedef NoListaCircular* ponteiroListaCircular;

typedef struct {
    ponteiroListaCircular primeiro, ultimo;
} ListaCircular;

void novaListaCircular (ListaCircular* ls);
void insiraInicioListaCircular (ListaCircular* l, Elemento i);
void insiraFinalListaCircular (ListaCircular* l, Elemento i);
boolean recupereInicioListaCircular (ListaCircular l, Elemento* i);
boolean recupereFinalListaCircular (ListaCircular l, Elemento* i);
boolean removaInicioListaCircular (ListaCircular* l);
boolean removaFinalListaCircular (ListaCircular* l);
boolean estaVaziaListaCircular (ListaCircular l);
boolean freeListaCircular (ListaCircular* l);

#endif