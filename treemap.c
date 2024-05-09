#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {
    TreeMap * new = (TreeMap *)malloc(sizeof(TreeMap));
    new->root = NULL;
    new->current = NULL;
    new->lower_than = lower_than;
    return new;

}


void insertTreeMap(TreeMap * tree, void* key, void * value) {
    if (tree == NULL || tree->root == NULL) {
        tree->root = createTreeNode(key, value);
        return;
    }

    TreeNode * aux = tree->root;
   

    while (aux != NULL) {
        if (is_equal(tree, key, aux->pair->key)) {
            
            return;
        } else {
            if (tree->lower_than(key, aux->pair->key) == 1) {
                if (aux->left == NULL) {
                    TreeNode *new_node = createTreeNode(key, value);
                    aux->left = new_node;
                    
                    new_node->parent = aux;




                    

void removeNode(TreeMap * tree, TreeNode* node) {
    if (node == NULL) return;
    if (node->left == NULL && node->right == NULL){
        if (node->parent == NULL){
            tree->root = NULL;
        }
        
    }
    if (node->left == NULL && node->right != NULL){
        if (node->parent->left == node){
            node->parent->left = node->right;
            
        }
        
    }
    
}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair * searchTreeMap(TreeMap * tree, void* key) {
    if (tree == NULL || tree->root == NULL) return NULL;
    TreeNode * node = tree->root;
    while (node != NULL){
        if (is_equal(tree,node->pair->key,key)){
            tree->current = node;
            return node->pair;
        }
        if (tree->lower_than(node->pair->key,key)){
            node = node->right;
            
        }
        else{
            node = node->left;
            
        } 
        
    }
    
    return NULL;
}


Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
    return NULL;
}
