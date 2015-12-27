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



void top_view(node * root)
{
   std::stack<int> leftnodes;
   std::queue<int> rightnodes;

   if (root != NULL) {
     node *treeleft = root->left;
     node *treeright = root->right;
     while (treeleft != NULL) {
      leftnodes.push(treeleft->data);
      treeleft = treeleft->left;
     }
    while (treeright != NULL) {
     rightnodes.push(treeright->data);
     treeright = treeright->right;
    }
    while (!leftnodes.empty()) {
      std::cout << leftnodes.top();
      leftnodes.pop();
    }
    std::cout << std::endl;
    while (!rightnodes.empty()) {
      std::cout << rightnodes.front();
      rightnodes.pop();
    }
    std::cout << std::endl;
   }
}

int main() {
  top_view(NULL);
}
