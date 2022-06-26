#include <stdlib.h>
#include <stdio.h>

struct bst
{
    struct noBst *raiz;
    int tam;
};

struct noBst
{
    int value;
    struct noBst *esq;
    struct noBst *dir;
};

struct bst *alocarBst()
{
    struct bst *nodeBst = (struct bst *)malloc(sizeof(struct bst));
    nodeBst->raiz = NULL;
    nodeBst->tam = 0;

    return nodeBst;
}

struct noBst *alocarBranch(int value)
{
    struct noBst *branch = (struct noBst *)malloc(sizeof(struct noBst));
    branch->esq = NULL;
    branch->dir = NULL;
    branch->value = value;

    return branch;
}

void pushBranch(struct noBst *raiz, struct noBst *newBranch)
{
    if (raiz->value < newBranch->value)
    {

        if (raiz->dir == NULL)
        {
            raiz->dir = newBranch;
        }
        else
        {
            pushBranch(raiz->dir, newBranch);
        }
    }
    else
    {

        if (raiz->esq == NULL)
        {
            raiz->esq = newBranch;
        }
        else
        {
            pushBranch(raiz->esq, newBranch);
        }
    }
}

void pushBranchInter(struct noBst *raiz, struct noBst *newBranch)
{
    struct noBst *branch = raiz;
    struct noBst *aux = NULL;
    while (branch != NULL)
    {
        aux = branch;
        if (branch->value < newBranch->value)
        {
            branch = branch->dir;
        }
        else
        {
            branch = branch->esq;
        }
    }

    if (aux->value < newBranch->value)
    {
        aux->dir = newBranch;
    }
    else
    {
        aux->esq = newBranch;
    }
}

void inserir(struct bst *nodeBst, int value, bool rec)
{
    struct noBst *newBranch = alocarBranch(value);
    if (nodeBst->raiz == NULL)
    {
        nodeBst->raiz = newBranch;
    }
    else
    {

        if (rec)
        {
            pushBranch(nodeBst->raiz, newBranch);
        }
        else
        {
            pushBranchInter(nodeBst->raiz, newBranch);
        }
    }
    nodeBst->tam++;
}

bool buscarRec(struct noBst *branch, int value)
{
    if (branch->value == value)
    {
        return true;
    }
    else
    {

        if (branch->value < value && branch->dir != NULL)
        {
            buscarRec(branch->dir, value);
        }
        else
        {

            if (branch->value > value && branch->esq != NULL)
            {
                buscarRec(branch->esq, value);
            }
            else
            {
                return false;
            }
        }
    }
}

bool buscarInt(struct noBst *raiz, int value)
{
    struct noBst *branch = raiz;
    struct noBst *aux = NULL;
    while (branch != NULL)
    {
        aux = branch;
        if (branch->value == value)
        {
            return true;
        }
        else
        {

            if (branch->value < value)
            {
                branch = branch->dir;
            }
            else
            {
                branch = branch->esq;
            }
        }
    }

    return false;
}

bool buscar(struct bst *nodeBst, int value, bool rec)
{
    if (nodeBst->raiz == NULL)
    {
        return false;
    }
    if (rec)
    {
        return buscarRec(nodeBst->raiz, value);
    }
    else
    {
        return buscarInt(nodeBst->raiz, value);
    }
}

void navPreOrdem(struct noBst *raiz)
{
    if (raiz != NULL)
    {
        printf("\n%i", raiz->value);
        navPreOrdem(raiz->esq);
        navPreOrdem(raiz->dir);
    }
}

void navEmOrdem(struct noBst *raiz)
{
    if (raiz != NULL)
    {
        navEmOrdem(raiz->esq);
        printf("\n%i", raiz->value);
        navEmOrdem(raiz->dir);
    }
}

void navPosOrdem(struct noBst *raiz)
{
    if (raiz != NULL)
    {
        navPosOrdem(raiz->esq);
        navPosOrdem(raiz->dir);
        printf("\n%i", raiz->value);
    }
}

int min(struct noBst *raiz)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (raiz->esq != NULL)
    {
        min(raiz->esq);
    }
    else
    {
        return raiz->value;
    }
}

int max(struct noBst *raiz)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (raiz->dir != NULL)
    {
        max(raiz->dir);
    }
    else
    {
        return raiz->value;
    }
}

int altura(struct noBst *raiz)
{
    int alturaEsq, alturaDir;
    if (raiz == NULL)
    {
        return -1;
    }

    alturaEsq = altura(raiz->esq);
    alturaDir = altura(raiz->dir);

    if (alturaEsq > alturaDir)
    {
        return alturaEsq + 1;
    }

    return alturaDir + 1;
}
struct noBst *removeBranch(struct noBst *raiz, int value)
{
    if (raiz == NULL)
    {
        return raiz;
    }
    else
    {
        if (raiz->value == value)
        {

            if (raiz->esq == NULL && raiz->dir == NULL)
            {
                free(raiz);

                return NULL;
            }
            else
            {
                if (raiz->dir != NULL && raiz->esq != NULL)
                {
                    struct noBst *aux = raiz->esq;

                    while (aux->dir != NULL)
                    {
                        aux = aux->dir;
                    }

                    raiz->value = aux->value;
                    aux->value = value;

                    raiz->esq = removeBranch(raiz->esq, value);

                    return raiz;
                }
                else
                {

                    struct noBst *aux;
                    if (raiz->esq != NULL)
                    {
                        aux = raiz->esq;
                    }
                    else
                    {
                        aux = raiz->dir;
                    }
                    free(raiz);

                    return aux;
                }
            }
        }
        else
        {
            if (raiz->value > value)
            {
                raiz->esq = removeBranch(raiz->esq, value);
            }
            else
            {
                raiz->dir = removeBranch(raiz->dir, value);
            }

            return raiz;
        }
    }
}

void remover(struct bst *nodeBst, int value)
{
    if (nodeBst != NULL)
    {
        removeBranch(nodeBst->raiz, value);
        nodeBst->tam--;
    }
}