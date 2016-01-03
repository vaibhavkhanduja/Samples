#include <iostream>

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;


node createMinimalBST(int arr[], int start, int end)
{
 if (end < start) {
   return null;
 }
 int mid = (start + end)/2;
 node* n = new node;
 n.data = mid;
 n.left = createMinimalBST(arr, start, mid - 1);
 n.right = createMinimalBST(arr, mid + 1, end);
 return n;
}

int main() {
 node *n = createMinimalBST(arr);
  
}
