#ifndef LISTA_DUPLA_LIGADA
#define LISTA_DUPLA_LIGADA

typedef enum {
    false,
    true
} boolean;

typedef void* Elemento;

typedef struct NoListaDupla {
    Elemento informacao;
    struct NoListaDupla* proximo;
    struct NoListaDupla* anterior;
} NoListaDupla;

typedef NoListaDupla* ponteiroListaDupla;

typedef struct {
    ponteiroListaDupla primeiro, ultimo;
} ListaDupla;

void novaListaDupla (ListaDupla* ls);
void insiraInicioListaDupla (ListaDupla* l, Elemento i);
void insiraFinalListaDupla (ListaDupla* l, Elemento i);
boolean recupereInicioListaDupla (ListaDupla l, Elemento* i);
boolean recupereFinalListaDupla (ListaDupla l, Elemento* i);
boolean removaInicioListaDupla (ListaDupla* l);
boolean removaFinalListaDupla (ListaDupla* l);
boolean estaVaziaListaDupla (ListaDupla l);
boolean freeListaDupla (ListaDupla* l);

#endif