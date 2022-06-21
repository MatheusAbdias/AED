#include <stdlib.h>
#include <stdio.h>

struct nodeBst{
    struct branch* source;
    int size;
};

struct branch{
    int value;
    struct branch* left;
    struct branch* right;
};

struct nodeBst* assignNodeBst(){
    struct nodeBst* nodeBst = (struct nodeBst*)malloc(sizeof(struct nodeBst));
    nodeBst->source = NULL;
    nodeBst->size = 0;

    return nodeBst;
}

struct branch* assignBranch(int value){
    struct branch* branch = (struct branch*)malloc(sizeof(struct branch));
    branch->left = NULL;
    branch->right = NULL;
    branch->value = value;

    return branch;
}

void pushBranch(struct branch* source,struct branch* newBranch){
    if(source->value < newBranch->value){
        
        if(source->right == NULL){
            source->right = newBranch;
        }
        else{
            pushBranch(source->right,newBranch);
        }
    }
    else{
         
         if(source->left == NULL){
            source->left = newBranch;
        }
        else{
            pushBranch(source->left,newBranch);
        }
    }
}

void push(struct nodeBst* nodeBst, int value){
    struct branch* newBranch = assignBranch(value);
    if(nodeBst->source == NULL){
        nodeBst->source = newBranch;
    }
    else{
        pushBranch(nodeBst->source,newBranch);
    }

    nodeBst->size++;
}

void search(struct nodeBst* nodeBst, int value)