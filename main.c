#include <stdio.h>
#include <stdlib.h>


typedef struct box{
    char conteudo;
    struct box *prox;

}Box;


Box* insereInicio(Box* lista, char conteudo){
    Box* novo = (Box*)malloc(sizeof(Box));
    novo->conteudo = conteudo;
    novo->prox = lista;
    return novo;
}
void mostraLista(Box* lista){
    Box *p;
    printf("\n\n--- Lista ---\n\n");
    for(p = lista; p != NULL; p = p->prox){
        printf("%c\n", p->conteudo);
    }
}
void insereFinal(Box *lista, char conteudo){
    Box *p = lista;
    for(p = lista; p->prox != NULL; p = p->prox){}
    p->prox = (Box*)malloc(sizeof(Box));
    p->prox->prox = NULL;
    p->prox->conteudo = conteudo;
}
void insereEntreDois(Box*lista, char anterior, char posterior, char conteudo){
    Box *novo;
    Box *p = lista;
    while(p != NULL){
        if(p->prox == NULL) break;
        if(p->conteudo == anterior && p->prox->conteudo == posterior){
            novo = (Box*)malloc(sizeof(Box));
            novo->prox = p->prox;
            novo->conteudo = conteudo;
            p->prox = novo;
        }
        p = p->prox;
    }
}


Box* eliminarBusca(Box*lista, char conteudo){
    Box *p, *anterior;
    anterior = lista;
    if(anterior->conteudo == conteudo){
        p = anterior->prox;
        free(anterior);
        return p;
    }
    p = anterior->prox;
    while( p != NULL){
        if(p->conteudo == conteudo){
            anterior->prox = p->prox;
            free(p);
            return lista;
        }
        anterior = anterior->prox;
        p = p->prox;
    }
    return lista;
}
Box* excluir_primeiro(Box*lista){
    Box*excluido;
    excluido = lista;
    lista = lista->prox;
    free(excluido);
    return lista;
}
void removeFinal(Box *lista){
    Box *p = lista;
    Box *anterior;
    while(p != NULL){
        anterior = p;
        p = p->prox;
        if(p->prox == NULL) break;
    }
    anterior->prox = NULL;
    free(p);
}


int main()
{
    Box *lista = NULL;
    lista = insereInicio(lista, 'R');

    //1
    insereFinal(lista, 'A');
    mostraLista(lista);

    //2
    lista = insereInicio(lista, 'B');
    mostraLista(lista);

    //3
    insereFinal(lista, 'C');
    mostraLista(lista);

    //4
    insereFinal(lista, 'D');
    mostraLista(lista);

    //5
    insereEntreDois(lista, 'A', 'C', 'E');
    mostraLista(lista);

    //6
    lista = eliminarBusca(lista, 'C');
    mostraLista(lista);

    //7
    insereFinal(lista, 'F');
    mostraLista(lista);

    //8
    lista = insereInicio(lista, 'G');
    mostraLista(lista);

    //9
    removeFinal(lista);
    lista = excluir_primeiro(lista);
    mostraLista(lista);

    //10
    insereEntreDois(lista, 'A', 'E', 'H');
    mostraLista(lista);

    //11
    lista = eliminarBusca(lista, 'a');
    mostraLista(lista);

    //12
    insereEntreDois(lista, 'E', 'D', 'I');
    mostraLista(lista);

    //13
    insereFinal(lista, 'J');
    mostraLista(lista);

    //14
    insereEntreDois(lista, 'B', 'H', 'K');
    mostraLista(lista);

    //15
    lista = eliminarBusca(lista, 'D');
    lista = eliminarBusca(lista, 'K');
    lista = eliminarBusca(lista, 'I');
    lista = eliminarBusca(lista, 'B');
    mostraLista(lista);

    //16
    insereFinal(lista, 'L');
    mostraLista(lista);
    mostraLista(lista);

    return 0;
}
