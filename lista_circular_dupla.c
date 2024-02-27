#include <stdlib.h>
#include "lista_circular_dupla.h"

void novaListaCircularDupla (ListaCircularDupla* ls) {
    ls->primeiro = NULL;
    ls->ultimo = NULL;
}

static ponteiroListaCircularDupla novoNoListaCircularDupla (Elemento i, ponteiroListaCircularDupla p, ponteiroListaCircularDupla a) {
    ponteiroListaCircularDupla novo = (ponteiroListaCircularDupla) malloc(sizeof(NoListaCircularDupla));

    novo->informacao = i;
    novo->proximo = p;
    novo->anterior = a;

    return novo;
}

void insiraInicioListaCircularDupla (ListaCircularDupla* l, Elemento i) {
    l->primeiro = novoNoListaCircularDupla (i, l->primeiro, l->ultimo);

    if (l->ultimo == NULL) {
        l->ultimo = l->primeiro;
    } else {
        l->primeiro->proximo->anterior = l->primeiro;
        l->ultimo->proximo = l->primeiro;
    }
}

void insiraFinalListaCircularDupla (ListaCircularDupla* l, Elemento i) {
    if (l->primeiro == NULL /* && l->ultimo==NULL*/)
        insiraInicioListaCircularDupla(l, i);
    else {
        l->ultimo->proximo = novoNoListaCircularDupla(i, l->primeiro, l->ultimo);
        l->ultimo = l->ultimo->proximo;
        l->primeiro->anterior = l->ultimo;
    }
}

boolean recupereInicioListaCircularDupla (ListaCircularDupla l,Elemento* i) {
    if (l.primeiro == NULL /* && l.ultimo==NULL */) return false;
    
    *i = l.primeiro->informacao;
    return true;
}

boolean recupereFinalListaCircularDupla (ListaCircularDupla l, Elemento* i) {
    if (l.primeiro == NULL /* && l.ultimo==NULL */) return false;
    
    *i = l.ultimo->informacao;
    return true;
}

boolean removaInicioListaCircularDupla (ListaCircularDupla* l) {
    if (l->primeiro == NULL /* && l.ultimo==NULL */) return false; 

    ponteiroListaCircularDupla antigo_primeiro = l->primeiro;
    l->primeiro = l->primeiro->proximo;

    // Verifique se o próximo nó existe e ajuste o anterior dele, se necessário.
    if (l->primeiro != NULL) {
        l->ultimo->proximo = l->primeiro;
        l->primeiro->anterior = l->ultimo;
    } else {
        // Se l->primeiro se tornou nulo, a lista agora está vazia.
        l->ultimo = NULL;
    }

    free(antigo_primeiro->informacao);
    free(antigo_primeiro);

    return true;
}

boolean removaFinalListaCircularDupla (ListaCircularDupla* l) {
    if (l->primeiro == NULL /* && l->ultimo==NULL */) return false;
    
    if (l->primeiro->proximo == NULL){
        free(l->primeiro->informacao);
        free(l->primeiro);
        l->primeiro = l->ultimo = NULL;
        return true;
    }
    
    ponteiroListaCircularDupla penultimo = l->primeiro;
    
    while (penultimo->proximo->proximo!=l->primeiro) penultimo = penultimo->proximo;
    
    free(l->ultimo->informacao);
    free(l->ultimo);
    
    penultimo->proximo = l->primeiro;
    l->ultimo = penultimo;
    l->primeiro->anterior = l->ultimo;
    
    return true;
}

boolean estaVaziaListaCircularDupla (ListaCircularDupla l) {
    return l.primeiro==NULL /* && l.ultimo==NULL */;
}

boolean freeListaCircularDupla (ListaCircularDupla* l) {
    if (l->primeiro==NULL /* && l->ultimo==NULL */) return false;
    
    ponteiroListaCircularDupla atual=l->primeiro;
    
    do {
        ponteiroListaCircularDupla proximo = atual->proximo; // Salva o próximo nó antes de liberar o atual.
        free(atual->informacao);
        free(atual);
        atual = proximo;
    } while (atual != l->primeiro);
    
    l->primeiro = l->ultimo = NULL;
    return true;
}





