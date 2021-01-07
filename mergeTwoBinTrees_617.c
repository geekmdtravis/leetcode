#include <stdio.h>
#include <stdlib.h>
#include "mergeTwoBinTrees_617.h"

int main() {
    struct TreeNode *t1head = newNode(1, newNode(2, NULL, NULL), newNode(3, NULL, newNode(5, NULL, NULL)));
    struct TreeNode *t2head = newNode(2, newNode(3, newNode(7, NULL, NULL), NULL), newNode(1, newNode(4, NULL, NULL), NULL));
    struct TreeNode *mergedHead = mergeTrees(t1head, t2head);

    return 0;
}

struct TreeNode *mergeTrees(struct TreeNode *t1, struct TreeNode *t2){
    struct TreeNode *merged = newNode(NULL, NULL, NULL);

    // implement here

    return NULL;
}

struct TreeNode *newNode(int val, struct TreeNode *left, struct TreeNode *right) {
    struct TreeNode *new = malloc(sizeof(struct TreeNode));
    new->val = val;
    new->left = left;
    new->right = right;

    return new;
}