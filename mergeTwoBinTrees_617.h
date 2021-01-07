#ifndef MERGE_TWO_BIN_TREES_H_INCLUDED
#define MERGE_TWO_BIN_TREES_H_INCLUDED

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TreeNode *newNode(int val, struct TreeNode *left, struct TreeNode *right);
void addNodeLeft(struct TreeNode *base, int val);
void addNodeRight(struct TreeNode *base, int val);
struct TreeNode *mergeTrees(struct TreeNode *t1, struct TreeNode *t2);

#endif