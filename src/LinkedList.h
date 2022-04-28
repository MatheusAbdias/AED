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
    
        while(nextNo->prox != NULL){
            nextNo = nextNo->prox;
        }
        
        nextNo->prox = newNo;
    }
    lista->qtdade++;
}

void inserirElementoNoInicio(struct linkedlist* lista, int valor) {
    struct no* newNo = alocarNovoNo(valor);
    
    if(lista->cabeca == NULL){
        lista->cabeca=newNo;
    }
    
    else{

        newNo->prox = lista->cabeca;
        lista->cabeca = newNo;
    }
    lista->qtdade++;
}

void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao) {
    if(posicao>=0 && posicao<=lista->qtdade){
        if(posicao == 0){
            inserirElementoNoInicio(lista,valor);
        }
        else{

            if(posicao == lista->qtdade){
                inserirElementoNoFim(lista,valor);
            }
            else{
                struct no* newNo = alocarNovoNo(valor);
                struct no* temp = lista->cabeca;
    
                for(int index = 0; index<posicao-1; index++){
                    temp = temp->prox;
                }

                struct no* aux = temp->prox;

                temp->prox = newNo;
                newNo->prox = aux;
                lista->qtdade++;
            }
        }
    }           
}

int obterElementoEmPosicao(struct linkedlist* lista, int posicao) {

    if(posicao>=0 && posicao<=lista->qtdade && lista->cabeca !=NULL){
        struct no* temp = lista->cabeca;

        for(int i=0;i<posicao;i++){
            temp = temp->prox;
        }
        return temp->val;
    }
}


void removerElementoEmPosicao(struct linkedlist* lista, int posicao) {
    if(posicao>=0 && posicao<=lista->qtdade){
        
        if(posicao == 0 && lista->cabeca != NULL && lista->cabeca->prox != NULL){
            struct no* temp = lista->cabeca;
            lista->cabeca = temp->prox;
            temp = NULL;
        }
        else{

            if(lista->qtdade == 1){
                lista->cabeca = NULL;
            }
            else{
                struct no* temp = lista->cabeca;
                
                for(int index = 0; index<posicao-1; index++){
                    temp = temp->prox;
                }

                if(lista->qtdade == posicao){
                    temp->prox = NULL;
                }
                else{
                    struct no* aux = temp->prox;
                    temp->prox = aux->prox;
                }
      
            }
        }
        lista->qtdade--;
    }
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