#include <stdlib.h>
#include <stdio.h>

struct no {
    int val;
    struct no* prox;
};

struct linkedlist {
    struct no* cabeca;
    int qtdade;
};

struct linkedlist* inicializar() {
    struct linkedlist* lista = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    lista->cabeca = NULL;
    lista->qtdade = 0;
    return lista;
}

struct no* alocarNovoNo(int valor) {
    struct no* no =(struct no*)malloc(sizeof(struct no));
    no->prox = NULL;
    no->val=valor;
    return no;
}

void inserirElementoNoFim(struct linkedlist* lista, int valor) {
    struct no* newNo = alocarNovoNo(valor);
    if(lista->qtdade == 0){
        lista->cabeca=newNo;
    }
    else{
        struct no* nextNo = lista->cabeca;
        for(int i=1;i<=lista->qtdade;i++){
            nextNo =nextNo->prox;
        }
        nextNo->prox = newNo;
        free(nextNo);
    }
    lista->qtdade++;
}

void inserirElementoNoInicio(struct linkedlist* lista, int valor) {
    struct no* newNo = alocarNovoNo(valor);
    if(lista->qtdade == 0){
        lista->cabeca=newNo;
    }
    else{
        struct no* temp = lista->cabeca;
        lista->cabeca = newNo;
        newNo->prox = temp;
        free(temp);
    }
    lista->qtdade++;
}

void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao) {
    if(posicao>=0 && posicao <= lista->qtdade){
        struct no* newNo =alocarNovoNo(valor);
        if(lista->qtdade ==0)lista->cabeca=newNo;
        else{
            struct no* temp =lista->cabeca;
            for(int i =1;i<posicao;i++){
                temp=temp->prox;
            }
            struct no* lastNo = temp->prox;
            temp->prox =newNo;
            newNo->prox=lastNo;
            lastNo->prox = NULL;
        }
    lista->qtdade++;
    }
}

int obterElementoEmPosicao(struct linkedlist* lista, int posicao) {
    //TODO
}

void removerElementoEmPosicao(struct linkedlist* lista, int posicao) {
    //TODO
}

void imprimirLista(struct linkedlist* lista) {
    //usamos o aux para percorrer a lista
    if (lista->cabeca != NULL) {
        struct no* aux = lista->cabeca;
        //navega partindo da cabe�a at� chegar NULL
        printf("[");
        do {
            printf("%d", aux->val);
            aux = aux->prox;
            if (aux != NULL) {
                printf(", ");
            }
        } while (aux != NULL);
        printf("]");
    }
    else {
        printf("A lista est� vazia!");
    }
}