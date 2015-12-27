#include <iostream>

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;



node * lca(node * root, int v1,int v2)
{
  if (root == NULL) return NULL;
  if ((root->data == v1) || (root->data == v2)) return root;
  node *L = lca(root->left, v1, v2);
  node *R = lca(root->right, v1, v2);
  if (L && R) return root;
  return L ? L : R;
}
