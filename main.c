#include <stdio.h>
#include <stdlib.h>
#include "lista_duplamente_ligada.h"
#include "lista_circular.h"
#include "lista_circular_dupla.h"

unsigned char eh_lc (ListaCircular l)
{
    if (l.primeiro==NULL) return 1/*true*/;
     
    ponteiroListaCircular atual = l.primeiro;
    while (atual->proximo!=l.primeiro)
        atual = atual->proximo;

    return atual==l.ultimo;
}

unsigned char eh_ldl (ListaDupla l)
{
    if (l.primeiro==NULL) return 1/*true*/;
     
    ponteiroListaDupla atual = l.primeiro;
    while (atual->proximo!=NULL)
        atual = atual->proximo;

    if (atual!=l.ultimo) return 0/*false*/;
 
    atual=l.ultimo;
    while (atual->anterior!=NULL)
        atual = atual->anterior;

    return atual==l.primeiro;
}

unsigned char eh_lcdl (ListaCircularDupla l)
{
    if (l.primeiro==NULL) return 1/*true*/;
     
    ponteiroListaCircularDupla atual = l.primeiro;
    while (atual->proximo!=l.primeiro)
        atual = atual->proximo;

    if (atual!=l.ultimo) return 0/*false*/;
 
    atual=l.ultimo;
    while (atual->anterior!=l.ultimo)
        atual = atual->anterior;

    return atual==l.primeiro;
}


void imprimeListaDuplaDoUltimoParaOPrimeiro(ListaDupla l) {
    ponteiroListaDupla no = l.ultimo;
    printf("Lista do ultimo para o primeiro:\n");
    while (no != NULL) {
        int* valor = (int*) no->informacao;
        printf("%d\n", *valor);
        no = no->anterior;
    }
    printf("FIM\n\n");
}

void imprimeListaDuplaDoPrimeiroParaOUltimo(ListaDupla l) {
    ponteiroListaDupla no = l.primeiro;
    printf("Lista do primeiro para o ultimo:\n");
    while (no != NULL) {
        int* valor = (int*) no->informacao;
        printf("%d\n", *valor);
        no = no->proximo;
    }
    printf("FIM\n\n");
}

void imprimeListaCircular(ListaCircular l, int vezes) {
    ponteiroListaCircular no = l.primeiro;
    int contador = 0;
    printf("Lista toda a lista %dx:\n", vezes);
    while (contador < vezes) {
        int* valor = (int*) no->informacao;
        printf("%d\n", *valor);
        no = no->proximo;
        
        if (no == l.primeiro){
            contador++;
            printf("\n\n");
        }
    }
    printf("FIM\n\n");
}

void imprimeListaCircularDuplaProximo(ListaCircularDupla l, int vezes) {
    ponteiroListaCircularDupla no = l.primeiro;
    int contador = 0;
    printf("Lista toda a lista do primeiro ao ultimo %dx vezes:\n", vezes);
    while (contador < vezes) {
        int* valor = (int*) no->informacao;
        printf("%d\n", *valor);
        no = no->proximo;
        
        if (no == l.primeiro){
            contador++;
            printf("\n\n");
        }
    }
    printf("FIM\n\n");
}

void imprimeListaCircularDuplaDeTrasParaFrenteUltimo(ListaCircularDupla l, int vezes) {
    ponteiroListaCircularDupla no = l.ultimo;
    int contador = 0;
    printf("Lista toda a lista de tras para frente comecando pelo ultimo %dx vezes:\n", vezes);
    while (contador < vezes) {
        int* valor = (int*) no->informacao;
        printf("%d\n", *valor);
        no = no->anterior;
        
        if (no == l.ultimo){
            contador++;
            printf("\n\n");
        }
    }
    printf("FIM\n\n");
}

void imprimeListaCircularDuplaDeTrasParaFrentePrimeiro(ListaCircularDupla l, int vezes) {
    ponteiroListaCircularDupla no = l.primeiro;
    int contador = 0;
    printf("Lista toda a lista de tras para frente comecando pelo primeiro %dx vezes:\n", vezes);
    while (contador < vezes) {
        int* valor = (int*) no->informacao;
        printf("%d\n", *valor);
        no = no->anterior;
        
        if (no == l.primeiro){
            contador++;
            printf("\n\n");
        }
    }
    printf("FIM\n\n");
}


void testaListaDupla() {
    ListaDupla lstDupla;
    novaListaDupla(&lstDupla);
    
    printf("LISTA DUPLA: \n\n");
    
    int* inteiro = (int*) malloc(sizeof(int));
    *inteiro = 5;
    insiraInicioListaDupla(&lstDupla, (Elemento)inteiro);
    inteiro = NULL;

    inteiro = (int*) malloc(sizeof(int));
    *inteiro = 3;
    insiraInicioListaDupla(&lstDupla, (Elemento)inteiro);
    inteiro = NULL;
    
    inteiro = (int*) malloc(sizeof(int));
    *inteiro = 2;
    insiraInicioListaDupla(&lstDupla, (Elemento)inteiro);
    inteiro = NULL;
    
    inteiro = (int*) malloc(sizeof(int));
    *inteiro = 7;
    insiraFinalListaDupla(&lstDupla, (Elemento)inteiro);
    inteiro = NULL;
    
    printf("%hhu", eh_ldl(lstDupla));
    
    imprimeListaDuplaDoUltimoParaOPrimeiro(lstDupla);
    imprimeListaDuplaDoPrimeiroParaOUltimo(lstDupla);
    
    recupereInicioListaDupla(lstDupla,(Elemento*)&inteiro);
    printf("INICIO: %d ",*inteiro); // 2
    
    recupereFinalListaDupla(lstDupla,(Elemento*)&inteiro);
    printf("FINAL: %d\n",*inteiro); // 7

    removaInicioListaDupla(&lstDupla);
    removaFinalListaDupla(&lstDupla);
    
    printf("%hhu", eh_ldl(lstDupla));
    
    recupereInicioListaDupla(lstDupla,(Elemento*)&inteiro);
    printf("INICIO: %d ",*inteiro); // 3
    
    recupereFinalListaDupla(lstDupla,(Elemento*)&inteiro);
    printf("FINAL: %d\n",*inteiro); // 5

    imprimeListaDuplaDoUltimoParaOPrimeiro(lstDupla);
    imprimeListaDuplaDoPrimeiroParaOUltimo(lstDupla);

    freeListaDupla(&lstDupla);
    printf("FIM LISTA DUPLA\n\n");
}

void testaListaCircular () {
    printf("LISTA CIRCULAR: \n\n");
    
    ListaCircular lstCircular;
    novaListaCircular(&lstCircular);

    int* inteiro = (int*) malloc(sizeof(int));
    *inteiro = 5;
    insiraInicioListaCircular(&lstCircular, (Elemento)inteiro);
    inteiro = NULL;

    inteiro = (int*) malloc(sizeof(int));
    *inteiro = 3;
    insiraInicioListaCircular(&lstCircular, (Elemento)inteiro);
    inteiro = NULL;
    
    inteiro = (int*) malloc(sizeof(int));
    *inteiro = 2;
    insiraInicioListaCircular(&lstCircular, (Elemento)inteiro);
    inteiro = NULL;
    
    inteiro = (int*) malloc(sizeof(int));
    *inteiro = 7;
    insiraFinalListaCircular(&lstCircular, (Elemento)inteiro);
    inteiro = NULL;
    
    printf("%hhu\n", eh_lc(lstCircular));
    
    //imprimeListaCircular(lstCircular, 2);
    
    recupereInicioListaCircular(lstCircular,(Elemento*)&inteiro);
    printf("INICIO: %d ",*inteiro); // 2
    
    recupereFinalListaCircular(lstCircular,(Elemento*)&inteiro);
    printf("FINAL: %d\n",*inteiro); // 7

    removaInicioListaCircular(&lstCircular);
    removaFinalListaCircular(&lstCircular);
    
    printf("%hhu\n", eh_lc(lstCircular));
    
    recupereInicioListaCircular(lstCircular,(Elemento*)&inteiro);
    printf("INICIO: %d ",*inteiro); // 3
    
    recupereFinalListaCircular(lstCircular,(Elemento*)&inteiro);
    printf("FINAL: %d\n",*inteiro); // 5
    
    //imprimeListaCircular(lstCircular, 2);

    freeListaCircular(&lstCircular);
    printf("FIM LISTA CIRCULAR\n\n");
}

void testaListaCirucularDupla () {
    printf("LISTA CIRCULAR DUPLA: \n\n");
    ListaCircularDupla lstCircularDupla;
    novaListaCircularDupla(&lstCircularDupla);

    int* inteiro = (int*) malloc(sizeof(int));
    *inteiro = 5;
    insiraInicioListaCircularDupla(&lstCircularDupla, (Elemento)inteiro);
    inteiro = NULL;

    inteiro = (int*) malloc(sizeof(int));
    *inteiro = 3;
    insiraInicioListaCircularDupla(&lstCircularDupla, (Elemento)inteiro);
    inteiro = NULL;
    
    inteiro = (int*) malloc(sizeof(int));
    *inteiro = 2;
    insiraInicioListaCircularDupla(&lstCircularDupla, (Elemento)inteiro);
    inteiro = NULL;
    
    inteiro = (int*) malloc(sizeof(int));
    *inteiro = 7;
    insiraFinalListaCircularDupla(&lstCircularDupla, (Elemento)inteiro);
    inteiro = NULL;
    
    printf("%hhu\n", eh_lcdl(lstCircularDupla));
    
    //imprimeListaCircularDuplaProximo(lstCircularDupla, 2);
    //imprimeListaCircularDuplaDeTrasParaFrenteUltimo(lstCircularDupla, 2);
    //imprimeListaCircularDuplaDeTrasParaFrentePrimeiro(lstCircularDupla, 2);
    
    recupereInicioListaCircularDupla(lstCircularDupla,(Elemento*)&inteiro);
    printf("INICIO: %d ",*inteiro); // 2
    
    recupereFinalListaCircularDupla(lstCircularDupla,(Elemento*)&inteiro);
    printf("FINAL: %d\n",*inteiro); // 7
    
    removaInicioListaCircularDupla(&lstCircularDupla);
    removaFinalListaCircularDupla(&lstCircularDupla);
    
    printf("%hhu\n", eh_lcdl(lstCircularDupla));

    recupereInicioListaCircularDupla(lstCircularDupla,(Elemento*)&inteiro);
    printf("INICIO: %d ",*inteiro); // 3
    
    recupereFinalListaCircularDupla(lstCircularDupla,(Elemento*)&inteiro);
    printf("FINAL: %d\n",*inteiro); // 5
    
    //imprimeListaCircularDuplaProximo(lstCircularDupla, 2);
    //imprimeListaCircularDuplaDeTrasParaFrenteUltimo(lstCircularDupla, 2);
    //imprimeListaCircularDuplaDeTrasParaFrentePrimeiro(lstCircularDupla, 2);

    freeListaCircularDupla(&lstCircularDupla);
    printf("FIM LISTA DUPLA\n\n");
}

int main () {
    testaListaDupla();
    //testaListaCircular();
    //testaListaCirucularDupla();
    return 0;
}