#include <stdlib.h>
#include "lista_duplamente_ligada.h"

void novaListaDupla (ListaDupla* ls) {
    ls->primeiro = NULL;
    ls->ultimo = NULL;
}

static ponteiroListaDupla novoNoListaDupla (Elemento i, ponteiroListaDupla p, ponteiroListaDupla a) {
    ponteiroListaDupla novo = (ponteiroListaDupla) malloc(sizeof(NoListaDupla));

    novo->informacao = i;
    novo->proximo = p;
    novo->anterior = a;

    return novo;
}

void insiraInicioListaDupla (ListaDupla* l, Elemento i) {
    l->primeiro = novoNoListaDupla (i, l->primeiro, NULL);

    if (l->ultimo == NULL) {
        l->ultimo = l->primeiro;
    } else {
        l->primeiro->proximo->anterior = l->primeiro;
    }
}

void insiraFinalListaDupla (ListaDupla* l, Elemento i) {
    if (l->primeiro == NULL /* && l->ultimo==NULL*/)
        insiraInicioListaDupla(l,i);
    else {
        l->ultimo->proximo = novoNoListaDupla(i, NULL, l->ultimo);
        l->ultimo = l->ultimo->proximo;
    }
}

boolean recupereInicioListaDupla (ListaDupla l,Elemento* i) {
    return l.primeiro ? (*i = l.primeiro->informacao, true) : false;
}

boolean recupereFinalListaDupla (ListaDupla l, Elemento* i) {
    return l.ultimo ? (*i = l.ultimo->informacao, true) : false;
}

boolean removaInicioListaDupla (ListaDupla* l) {
    if (l->primeiro == NULL /* && l.ultimo==NULL */) return false; 

    ponteiroListaDupla antigo_primeiro = l->primeiro;
    l->primeiro = l->primeiro->proximo;

    if (l->primeiro != NULL) {
        l->primeiro->anterior = NULL;
    } else {
        l->ultimo = NULL;
    }

    free(antigo_primeiro->informacao);
    free(antigo_primeiro);

    return true;
}

boolean removaFinalListaDupla (ListaDupla* l) {
    if (l->primeiro == NULL /* && l->ultimo==NULL */) return false;
    
    if (l->primeiro->proximo == NULL){
        free(l->primeiro->informacao);
        free(l->primeiro);
        l->primeiro = l->ultimo = NULL;
        return true;
    }
    
    ponteiroListaDupla penultimo = l->primeiro;
    
    while (penultimo->proximo->proximo!=NULL) penultimo = penultimo->proximo;
    
    free(l->ultimo->informacao);
    free(l->ultimo);
    
    penultimo->proximo = NULL;
    l->ultimo = penultimo;
    
    return true;
}

boolean estaVaziaListaDupla (ListaDupla l) {
    return l.primeiro==NULL /* && l.ultimo==NULL */;
}

boolean freeListaDupla (ListaDupla* l) {
    if (l->primeiro==NULL /* && l->ultimo==NULL */) return false;
    
    ponteiroListaDupla atual=l->primeiro;
    
    while (atual != NULL) {
        l->primeiro = l->primeiro->proximo;
        free(atual->informacao);
        free(atual);
        atual = l->primeiro;
    }
    
    l->ultimo = NULL;
    return true;
}






