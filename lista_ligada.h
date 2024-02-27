#ifndef LISTA_SIMPLES
#define LISTA_SIMPLES

typedef enum {
    false,
    true
} boolean;

typedef void* Elemento_de_lista_simples;

typedef struct Struct_do_no_de_lista_simples {
    Elemento_de_lista_simples informacao;
    struct Struct_do_no_de_lista_simples* proximo;
} Struct_do_no_de_lista_simples;

typedef Struct_do_no_de_lista_simples* Ptr_de_no_de_lista_simples;

typedef struct
{
    Ptr_de_no_de_lista_simples primeiro, ultimo;
} Lista_simples;

void nova_lista_simples (Lista_simples* ls);
void insira_no_inicio_da_lista_simples (Lista_simples* l, Elemento_de_lista_simples i);
void insira_no_final_da_lista_simples (Lista_simples* l, Elemento_de_lista_simples i);
boolean recupere_elemento_do_inicio (Lista_simples l,Elemento_de_lista_simples* i);
boolean recupere_elemento_do_final (Lista_simples l, Elemento_de_lista_simples* i);
boolean remova_elemento_do_inicio (Lista_simples* l);
boolean remova_elemento_do_final (Lista_simples* l);
boolean lista_simples_vazia (Lista_simples l);
boolean free_lista_simples (Lista_simples* l);

#endif