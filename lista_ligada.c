#include <stdlib.h>
#include "lista_ligada.h"

void nova_lista_simples (Lista_simples* ls)
{
    ls->primeiro=NULL;
    ls->ultimo  =NULL;
}

static Ptr_de_no_de_lista_simples novo_no_de_lista_simples (Elemento_de_lista_simples i, Ptr_de_no_de_lista_simples p)
{
    Ptr_de_no_de_lista_simples novo = (Ptr_de_no_de_lista_simples)malloc(sizeof(Struct_do_no_de_lista_simples));

    novo->informacao=i;
    novo->proximo   =p;

    return novo;
}

void insira_no_inicio_da_lista_simples (Lista_simples* l, Elemento_de_lista_simples i)
{
    l->primeiro=novo_no_de_lista_simples (i,l->primeiro);
    if (l->ultimo==NULL) l->ultimo=l->primeiro;
}

void insira_no_final_da_lista_simples (Lista_simples* l, Elemento_de_lista_simples i)
{
    if (l->primeiro==NULL /* && l->ultimo==NULL*/)
        insira_no_inicio_da_lista_simples(l,i);
    else
    {
        l->ultimo->proximo=novo_no_de_lista_simples(i,NULL);
        l->ultimo=l->ultimo->proximo;
    }
}

boolean recupere_elemento_do_inicio (Lista_simples l,Elemento_de_lista_simples* i)
{
    if (l.primeiro==NULL /* && l.ultimo==NULL */) return false;
    
    *i = l.primeiro->informacao;
    return true;
}

boolean recupere_elemento_do_final (Lista_simples l, Elemento_de_lista_simples* i)
{
    if (l.primeiro==NULL /* && l.ultimo==NULL */) return false;
    
    *i = l.ultimo->informacao;
    return true;
}

boolean remova_elemento_do_inicio (Lista_simples* l)
{
    if (l->primeiro==NULL /* && l->ultimo==NULL */) return false;
    
    Ptr_de_no_de_lista_simples antigo_primeiro = l->primeiro;
    l->primeiro=l->primeiro->proximo;
    if (l->primeiro==NULL) l->ultimo=NULL;
    
    free(antigo_primeiro->informacao);
    free(antigo_primeiro);
    
    return true;
}

boolean remova_elemento_do_final (Lista_simples* l)
{
    if (l->primeiro==NULL /* && l->ultimo==NULL */) return false;
    
    if (l->primeiro->proximo==NULL)
    {
        free(l->primeiro->informacao);
        free(l->primeiro);
        l->primeiro=l->ultimo=NULL;
        return true;
    }
    
    Ptr_de_no_de_lista_simples penultimo=l->primeiro;
    
    while (penultimo->proximo->proximo!=NULL) penultimo=penultimo->proximo;
    
    free(l->ultimo->informacao);
    free(l->ultimo);
    
    penultimo->proximo=NULL;
    l->ultimo=penultimo;
    
    return true;
}

boolean lista_simples_vazia (Lista_simples l)
{
    return l.primeiro==NULL /* && l.ultimo==NULL */;
}

boolean free_lista_simples (Lista_simples* l)
{
    if (l->primeiro==NULL /* && l->ultimo==NULL */) return false;
    
    Ptr_de_no_de_lista_simples atual=l->primeiro;
    
    while (atual!=NULL)
    {
        l->primeiro=l->primeiro->proximo;
        free(atual->informacao);
        free(atual);
        atual=l->primeiro;
    }
    
    l->ultimo=NULL;
    return true;
}






