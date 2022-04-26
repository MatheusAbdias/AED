#include <stdlib.h>
#include <stdio.h>

struct no{
    struct no *ant;
    int val;
    struct no *prox;
};

struct doublylinkedlist {
    struct no* cabeca;
    struct no* cauda;
    int qtdade;
};

struct doublylinkedlist* inicializar() {
   struct doublylinkedlist* lista = (struct doublylinkedlist*)malloc(sizeof(struct doublylinkedlist));
   lista->cabeca =NULL;
   lista->cauda=NULL;
   lista->qtdade = 0;

    return lista;
}

struct no* alocarNovoNo(int valor){
    struct no* no = (struct no*)malloc(sizeof(struct no));
    no->prox = NULL;
    no->ant = NULL;
    no->val = valor;
    
    return no;
}

void inserirElementoNoInicio(struct doublylinkedlist* lista, int valor){
    struct no* newNo = alocarNovoNo(valor);
    if(lista->cabeca == NULL && lista->cauda == NULL){
        
        lista->cabeca = newNo;
        lista->cauda = newNo;
        newNo->ant = lista->cabeca;
   
    }
    else{
        
        struct no* temp = lista->cabeca;
        temp->ant = newNo;
        lista->cabeca = newNo;
        newNo->prox = temp;

    }
}

void inserirElementoNoFim(struct doublylinkedlist* lista, int valor){
    struct no* newNo = alocarNovoNo(valor);

    if(lista->cabeca == NULL && lista->cauda == NULL){
    
        lista->cabeca = newNo;
        lista->cauda = newNo;
        newNo->ant = lista->cabeca;
        lista->qtdade = lista->qtdade+1;

    }
    else{

        struct no* temp = lista->cauda;
        temp->prox = newNo;
        lista->cauda = newNo;
        newNo->ant=temp;
        lista->qtdade = lista->qtdade+1;
    }
}

void inserirElementoEmPosicao(struct doublylinkedlist* lista, int valor, int posicao){
    if(posicao ==0 && lista->cabeca == NULL && lista->cauda == NULL){
        struct no* newNo = alocarNovoNo(valor);
        lista->cabeca = newNo;
        lista->cauda = newNo;
        newNo->ant = lista->cabeca;
        lista->qtdade = lista->qtdade+1;

    }
    else{
        if(posicao>=0 && posicao<lista->qtdade){
            struct no* temp = lista->cabeca;
            struct no* newNo = alocarNovoNo(valor);
            
            for(int i = 0;i<posicao;i++){
                temp = temp->prox;
            }
            
            if(temp->prox != NULL){ 
                struct no* nextNo = temp->prox;
                temp->prox = newNo;
                newNo->prox = nextNo;
                newNo->ant = temp;
                nextNo->ant = newNo;
            }
            else{
                temp->prox = newNo;
                newNo->ant = temp;
                lista->qtdade = lista->qtdade+1;
            }
        }

    }
}

int obterElementoEmPosicao(struct doublylinkedlist* lista, int posicao){
    if(posicao>=0 && posicao<=lista->qtdade && lista->cabeca !=NULL){
        struct no* temp = lista->cabeca;
        
        for(int i=0;i<posicao;i++){
            temp=temp->prox;
        }

        return temp->val;
    }
}

void removerElementoEmPosicao(struct doublylinkedlist* lista, int posicao){
    if(posicao == 0 && posicao <= lista->qtdade && lista->cabeca != NULL & lista->cabeca->prox != NULL){
        
        struct no* temp = lista->cabeca->prox;
        lista->cabeca = temp;
        temp->ant = lista->cabeca;
        lista->qtdade = lista->qtdade-1;
    
    }
    else{
        if(posicao >=0 && posicao <= lista->qtdade){
            struct no* temp = lista->cabeca;
            
            for(int i =0;i<posicao;i++){
                temp = temp->prox;
            }

            if(temp->prox == NULL){
                temp = NULL;
            }
            else{
                
                struct no* nextNo = temp->prox;
                temp->prox = nextNo->prox;
                nextNo->prox->ant = temp;
            }
            lista->qtdade = lista->qtdade-1;
        }
    }
}

void imprimirLista(struct no** cabeca) {
    //usamos o aux para percorrer a lista
    if ((*cabeca) != NULL) {
        struct no* aux = (*cabeca);
        //navega partindo da cabeça até chegar NULL
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
        printf("A lista está vazia!");
    }
}