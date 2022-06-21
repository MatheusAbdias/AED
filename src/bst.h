#include <stdlib.h>
#include <stdio.h>

struct bst{
    struct noBst* raiz;
    int tam;
};

struct noBst{
    int value;
    struct noBst* esq;
    struct noBst* dir;
};

struct bst* alocarBst(){
    struct bst* nodeBst = (struct bst*)malloc(sizeof(struct bst));
    nodeBst->raiz = NULL;
    nodeBst->tam = 0;

    return nodeBst;
}

struct noBst* alocarBranch(int value){
    struct noBst* branch = (struct noBst*)malloc(sizeof(struct noBst));
    branch->esq = NULL;
    branch->dir = NULL;
    branch->value = value;

    return branch;
}

void pushBranch(struct noBst* raiz,struct noBst* newBranch){
    if(raiz->value < newBranch->value){
        
        if(raiz->dir == NULL){
            raiz->dir = newBranch;
        }
        else{
            pushBranch(raiz->dir,newBranch);
        }
    }
    else{
         
         if(raiz->esq == NULL){
            raiz->esq = newBranch;
        }
        else{
            pushBranch(raiz->esq,newBranch);
        }
    }
}

void pushBranchInter(struct noBst* raiz,struct noBst* newBranch){
    struct noBst* branch = raiz; 
    struct noBst* aux = NULL;
    while(branch != NULL){
        aux = branch;
        if(branch->value <newBranch->value){
            branch = branch->dir;
        }
        else{
            branch = branch->esq;
        }
    }

    if(aux->value < newBranch->value){
        aux->dir = newBranch;
    }
    else{
        aux->esq = newBranch;
    }

}

void inserir(struct bst* nodeBst, int value,bool rec){
    struct noBst* newBranch = alocarBranch(value);
    if(nodeBst->raiz == NULL){
        nodeBst->raiz = newBranch;
    }
    else{

        if(rec){
            pushBranch(nodeBst->raiz,newBranch);

        }
        else{
            pushBranchInter(nodeBst->raiz,newBranch);
        }

    }
    nodeBst->tam++;
}

bool buscarRec(struct noBst* branch, int value){
    if(branch->value == value){
        return true;
    }
    else{
        
        if(branch->value <value && branch->dir != NULL){
            buscarRec(branch->dir, value);   
        }
        else{

            if(branch->value > value && branch->esq != NULL){
                buscarRec(branch->esq, value);
            }
            else{
                return false;
            }
        }
    }
}

bool buscarInt(struct noBst* raiz, int value){
    struct noBst* branch = raiz;
    struct noBst* aux = NULL;
    while(branch != NULL){
        aux = branch;
        if(branch->value == value){
            return true;
        }
        else{

            if(branch->value < value){
                branch = branch->dir;
            }
            else{
                branch = branch->esq;
            }

        }
    }

    return false;
}

bool buscar(struct bst* nodeBst, int value,bool rec){
    if(nodeBst->raiz == NULL){
        return false;
    }
    if(rec){
        return buscarRec(nodeBst->raiz, value);
    }
    else{
        return buscarInt(nodeBst->raiz, value);
    }
}