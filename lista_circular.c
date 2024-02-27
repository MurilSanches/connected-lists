#include <stdlib.h>
#include "lista_circular.h"

void novaListaCircular (ListaCircular* ls) {
    ls->primeiro = NULL;
    ls->ultimo = NULL;
}

static ponteiroListaCircular novoNoListaCircular (Elemento i, ponteiroListaCircular p) {
    ponteiroListaCircular novo = (ponteiroListaCircular) malloc(sizeof(NoListaCircular));

    novo->informacao = i;
    novo->proximo = p;

    return novo;
}

void insiraInicioListaCircular (ListaCircular* l, Elemento i) {
    l->primeiro = novoNoListaCircular (i, l->primeiro);

    if (l->ultimo == NULL) {
        l->ultimo = l->primeiro;
    }
    
    l->ultimo->proximo = l->primeiro;
}

void insiraFinalListaCircular (ListaCircular* l, Elemento i) {
    if (l->primeiro == NULL /* && l->ultimo==NULL*/)
        insiraInicioListaCircular(l,i);
    else {
        l->ultimo->proximo = novoNoListaCircular(i, l->primeiro);
        l->ultimo = l->ultimo->proximo;
    }
}

boolean recupereInicioListaCircular (ListaCircular l,Elemento* i) {
    if (l.primeiro == NULL /* && l.ultimo==NULL */) return false;
    
    *i = l.primeiro->informacao;
    return true;
}

boolean recupereFinalListaCircular (ListaCircular l, Elemento* i) {
    if (l.primeiro == NULL /* && l.ultimo==NULL */) return false;
    
    *i = l.ultimo->informacao;
    return true;
}

boolean removaInicioListaCircular (ListaCircular* l) {
    if (l->primeiro == NULL /* && l.ultimo==NULL */) return false; 

    ponteiroListaCircular antigo_primeiro = l->primeiro;
    l->primeiro = l->primeiro->proximo;

    if (l->primeiro == NULL) {
        l->ultimo = NULL;
    } else {
        l->ultimo->proximo = l->primeiro;
    }

    free(antigo_primeiro->informacao);
    free(antigo_primeiro);

    return true;
}

boolean removaFinalListaCircular (ListaCircular* l) {
    if (l->primeiro == NULL /* && l->ultimo==NULL */) return false;
    
    if (l->primeiro->proximo == NULL){
        free(l->primeiro->informacao);
        free(l->primeiro);
        l->primeiro = l->ultimo = NULL;
        return true;
    }
    
    ponteiroListaCircular penultimo = l->primeiro;
    
    while (penultimo->proximo->proximo!=l->primeiro) penultimo = penultimo->proximo;
    
    free(l->ultimo->informacao);
    free(l->ultimo);
    
    penultimo->proximo = l->primeiro;
    l->ultimo = penultimo;
    
    return true;
}

boolean estaVaziaListaCircular (ListaCircular l) {
    return l.primeiro==NULL /* && l.ultimo==NULL */;
}

boolean freeListaCircular (ListaCircular* l) {
    if (l->primeiro==NULL /* && l->ultimo==NULL */) return false;
    
    ponteiroListaCircular atual=l->primeiro;
    
    do {
        ponteiroListaCircular proximo = atual->proximo; 
        free(atual->informacao);
        free(atual);
        atual = proximo;
    } while (atual != l->primeiro);
    
    l->primeiro = l->ultimo = NULL;
    return true;
}






