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
        struct no* temp = lista->cabeca;
        newNo->prox = lista->cabeca;
        lista->cabeca = newNo;
    }
    lista->qtdade++;
}

void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao) {

    if(posicao>=0 && posicao <=lista->qtdade){
        
        struct no* newNo = alocarNovoNo(valor);
        
        if(lista->qtdade == 0){
          lista->cabeca = newNo;
          lista->qtdade = lista->qtdade+1;  
        }
        
        else{
           
            if(posicao == 0){
                inserirElementoNoInicio(lista,valor);
            }
           
            else{
                struct no* temp = lista->cabeca;
                int i = 1;
           
                while(i < posicao){
                    temp = temp->prox;
                    i++;
                }
           
                if(temp->prox != NULL){
                    struct no* nextNo = temp->prox;
                    temp->prox = newNo;
                    newNo->prox = nextNo;
                    lista->qtdade =lista->qtdade+1;
                }
                else{   
                    temp->prox = newNo;
                    lista->qtdade =lista->qtdade+1;
                }
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
    if(posicao == 0 && lista->cabeca != NULL && lista->cabeca->prox != NULL){
        struct no* temp = lista->cabeca->prox;
        lista->cabeca = temp;
        lista->qtdade = lista->qtdade-1;
    }

    else{

        if(posicao>=0 && posicao < lista->qtdade){
            struct no* temp = lista->cabeca;    
            
            for(int i=1;i<posicao;i++){
                temp = temp->prox;
            }

            if(temp->prox == NULL){
                temp = NULL;
            }

            else{
                struct no* nextNo = temp->prox;
            
                if(nextNo->prox != NULL){
                    struct no*temp = nextNo->prox;
                    temp->prox = nextNo->prox;
                }

                else{
                    temp->prox = NULL;
                }

            }
            lista->qtdade = lista->qtdade-1;
        }
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