#include <stack>
#include <queue>
#include <iostream>

struct node;
struct node
{
    int data;
    node* left;
    node* right;
};


int getHeight(node *root) {
  if (root == NULL) {
   return -1;
  }
  int leftheight = getHeight(root->left) + 1;
  int rightheight = getHeight(root->right) + 1;

  int height = leftheight > rightheight ? leftheight : reightheight;
}

bool isBalanced(node *root) {
   if 
}

int main() {
  top_view(NULL);
}
