#ifndef LISTA_CIRCULAR_DUPLA
#define LISTA_CIRCULAR_DUPLA
#include "lista_duplamente_ligada.h"

typedef void* Elemento;

typedef struct NoListaCircularDupla {
    Elemento informacao;
    struct NoListaCircularDupla* proximo;
    struct NoListaCircularDupla* anterior;
} NoListaCircularDupla;

typedef NoListaCircularDupla* ponteiroListaCircularDupla;

typedef struct {
    ponteiroListaCircularDupla primeiro, ultimo;
} ListaCircularDupla;

void novaListaCircularDupla (ListaCircularDupla* ls);
void insiraInicioListaCircularDupla (ListaCircularDupla* l, Elemento i);
void insiraFinalListaCircularDupla (ListaCircularDupla* l, Elemento i);
boolean recupereInicioListaCircularDupla (ListaCircularDupla l, Elemento* i);
boolean recupereFinalListaCircularDupla (ListaCircularDupla l, Elemento* i);
boolean removaInicioListaCircularDupla (ListaCircularDupla* l);
boolean removaFinalListaCircularDupla (ListaCircularDupla* l);
boolean estaVaziaListaCircularDupla (ListaCircularDupla l);
boolean freeListaCircularDupla (ListaCircularDupla* l);

#endif