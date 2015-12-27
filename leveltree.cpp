#include <queue>
#include <iostream>

struct node;
struct node
{
  int data;
  node* left;
  node* right;
};

void LevelOrder(node *root)
{
  std::queue<node *> q; 
  q.push(root);
  while (!q.empty()) {
     node *temp = q.front();
     q.pop();
     if (temp) {
      std::cout << temp->data << " ";
      q.push(temp->left);
      q.push(temp->right);
     }
  }
}
