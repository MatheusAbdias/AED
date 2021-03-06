/*
                                                                                                                    ,--,
                                                                                                                 ,---.'|
   ,---,                                                                               ,---,                     |   | :
  '  .' \                                                                             '  .' \              ,---. :   : |
 /  ;    '.       __  ,-.               ,---.     __  ,-.                            /  ;    '.           /__./| |   ' :
:  :       \    ,' ,'/ /|      .---.   '   ,'\  ,' ,'/ /|              .--.--.      :  :       \     ,---.;  ; | ;   ; '
:  |   /\   \   '  | |' |    /.  ./|  /   /   | '  | |' |    ,---.    /  /    '     :  |   /\   \   /___/ \  | | '   | |__
|  :  ' ;.   :  |  |   ,'  .-' . ' | .   ; ,. : |  |   ,'   /     \  |  :  /`./     |  :  ' ;.   :  \   ;  \ ' | |   | :.'|
|  |  ;/  \   \ '  :  /   /___/ \: | '   | |: : '  :  /    /    /  | |  :  ;_       |  |  ;/  \   \  \   \  \: | '   :    ;
'  :  | \  \ ,' |  | '    .   \  ' . '   | .; : |  | '    .    ' / |  \  \    `.    '  :  | \  \ ,'   ;   \  ' . |   |  ./
|  |  '  '--'   ;  : |     \   \   ' |   :    | ;  : |    '   ;   /|   `----.   \   |  |  '  '--'      \   \   ' ;   : ;
|  :  :         |  , ;      \   \     \   \  /  |  , ;    '   |  / |  /  /`--'  /   |  :  :             \   `  ; |   ,/
|  | ,'          ---'        \   \ |   `----'    ---'     |   :    | '--'.     /    |  | ,'              :   \ | '---'
`--''                         '---"                        \   \  /    `--'---'     `--''                 '---"
                                                            `----'
*/

#include <stdlib.h>
#include <stdbool.h>
#include <queue>
using namespace std;
void atualizar(struct noBst *no);
struct noBst *balancear(struct noBst *no);
struct noBst *rebalancearEsqEsq(struct noBst *no);
struct noBst *rebalancearEsqDir(struct noBst *no);
struct noBst *rebalancearDirDir(struct noBst *no);
struct noBst *rebalancearDirEsq(struct noBst *no);

struct noBst
{
    int val;
    int altura;
    int balanco;
    struct noBst *esq;
    struct noBst *dir;
};

struct noBst *alocarNovoNo(int val)
{
    struct noBst *nodeBst = (struct noBst *)malloc(sizeof(struct noBst));
    nodeBst->altura = 0;
    nodeBst->val = val;
    nodeBst->balanco = 0;
    nodeBst->dir = NULL;
    nodeBst->esq = NULL;

    return nodeBst;
}

struct noBst *rotacaoDireita(struct noBst *arvore)
{
    struct noBst *novaRaiz = arvore->esq;
    arvore->esq = novaRaiz->dir;
    novaRaiz->dir = arvore;

    atualizar(arvore);
    atualizar(novaRaiz);

    return novaRaiz;
}

struct noBst *rotacaoEsquerda(struct noBst *arvore)
{
    struct noBst *novaRaiz = arvore->dir;
    arvore->dir = novaRaiz->esq;
    novaRaiz->esq = arvore;

    atualizar(arvore);
    atualizar(novaRaiz);

    return novaRaiz;
}

/**
 * Funcao que recebe a raiz de uma BST, e
 * insere um novo valor na BST. Tamanho deve
 * ser incrementado.
 * Ambos tamanho e raiz s??o passados por refer??ncia.
 * Lembrar de atualizar altura e fator de balanco dos n??s
 * antecessores do n?? inserido, bem como balance??-los caso
 * seja necess??rio.
 * Dica: reutilizar a fun????o de inserir de BST, e lembrar
 * de como usar inteligentemente a recurs??o para conseguir
 * atualizar e balancear os n??s antecessores.
 **/
void inserir(struct noBst **raiz, int val, int *tamanho)
{
    if (*raiz == NULL)
    {
        *tamanho = *tamanho + 1;
        *raiz = alocarNovoNo(val);
    }
    else
    {

        if ((*raiz)->val > val)
        {
            inserir(&((*raiz)->esq), val, tamanho);
        }
        else
        {
            inserir(&((*raiz)->dir), val, tamanho);
        }
    }

    atualizar(*raiz);
    *raiz = balancear(*raiz);
}

void atualizar(struct noBst *no)
{
    if (no->dir != NULL && no->esq != NULL)
    {

        if (no->dir->altura > no->esq->altura)
        {
            no->altura = no->dir->altura + 1;
        }
        else
        {
            no->altura = no->esq->altura + 1;
        }

        no->balanco = no->dir->altura - no->esq->altura;
    }
    else
    {

        if (no->dir != NULL)
        {
            no->altura = no->dir->altura + 1;
            no->balanco = no->dir->altura;
        }
        else
        {

            if (no->esq != NULL)
            {
                no->altura = no->esq->altura + 1;
                no->balanco = -no->esq->altura;
            }
            else
            {
                no->balanco = 0;
                no->altura = 0;
            }
        }
    }
}

/**
 * Funcao que recebe a raiz de uma BST e identifica em qual caso
 * ela se encaixa para executar os procedimentos de balanceamento
 * corretos:
 *      - Caso 1: esquerda-esquerda e esquerda-cheio
 *      - Caso 2: esquerda-direita
 *      - Caso 3: direita-direita e direita-cheio
 *      - Caso 4: direita-esquerda
 * Dica: usar fator de balan??o do n?? e de uma de suas sub-??rvores
 * para descobrir qual ?? o caso.
 **/
struct noBst *balancear(struct noBst *no)
{
    if (no->esq == NULL && no->dir == NULL)
    {
        return no;
    }
    else
    {
        if (no->balanco == -2)
        {
            if (no->esq->balanco == -1)
            {
                return rebalancearEsqEsq(no);
            }

            return rebalancearEsqDir(no);
        }
        if (no->balanco == 2)
        {
            if (no->dir->balanco == 1)
            {
                return rebalancearDirDir(no);
            }
            return rebalancearDirEsq(no);
        }
    }

    return no;
}

struct noBst *rebalancearEsqEsq(struct noBst *no)
{
    struct noBst *novaRaiz = rotacaoDireita(no);

    return novaRaiz;
}

struct noBst *rebalancearEsqDir(struct noBst *no)
{
    struct noBst *novaRaiz = no;
    novaRaiz->esq = rotacaoEsquerda(novaRaiz->esq);
    novaRaiz = rotacaoDireita(novaRaiz);

    return novaRaiz;
}

struct noBst *rebalancearDirDir(struct noBst *no)
{
    struct noBst *novaRaiz = rotacaoEsquerda(no);

    return novaRaiz;
}

struct noBst *rebalancearDirEsq(struct noBst *no)
{
    struct noBst *novaRaiz = no;
    novaRaiz->dir = rotacaoDireita(novaRaiz->dir);
    novaRaiz = rotacaoEsquerda(novaRaiz);

    return novaRaiz;
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
        return raiz->val;
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
        return raiz->val;
    }
}

int altura(struct noBst *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }

    int alturaEsq = altura(raiz->esq);
    int alturaDir = altura(raiz->dir);

    if (alturaEsq > alturaDir)
    {
        return alturaEsq + 1;
    }

    return alturaDir + 1;
}

/**
 * Funcao que recebe a raiz de uma ??rvore, e
 * remove o n?? que contem o valor passado como
 * argumento. Tamanho deve ser decrementado.
 * Tamanho ?? passado por refer??ncia.
 * Lembrar de atualizar altura e fator de balanco dos n??s
 * antecessores do n?? removido, bem como balance??-los caso
 * seja necess??rio.
 * Dica: reutilizar a fun????o de remover de BST, e lembrar
 * de como usar inteligentemente a recurs??o para conseguir
 * atualizar e balancear os n??s antecessores.
 **/
struct noBst *remover(struct noBst *raiz, int val, int *tamanho)
{
    if (raiz == NULL)
    {
        return raiz;
    }

    if (raiz->val == val)
    {

        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            free(raiz);
            *tamanho = *tamanho - 1;
            return NULL;
        }

        if (raiz->dir != NULL && raiz->esq != NULL)
        {
            struct noBst *aux = raiz->esq;
            while (aux->dir != NULL)
            {
                aux = aux->dir;
            }

            raiz->val = aux->val;
            aux->val = val;

            raiz->esq = remover(raiz->esq, val, tamanho);

            if (raiz->esq != NULL)
            {
                atualizar(raiz->esq);
                raiz->esq = balancear(raiz->esq);
            }

            return raiz;
        }

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
        *tamanho = *tamanho - 1;
        return aux;
    }
    if (raiz->val > val)
    {
        raiz->esq = remover(raiz->esq, val, tamanho);

        if (raiz->esq != NULL)
        {
            atualizar(raiz->esq);
            raiz->esq = balancear(raiz->esq);
        }
    }
    else
    {
        raiz->dir = remover(raiz->dir, val, tamanho);
        if (raiz->dir != NULL)
        {
            atualizar(raiz->dir);
            raiz->dir = balancear(raiz->dir);
        }
    }

    return raiz;
}