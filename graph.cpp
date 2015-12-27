#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int minDistance(int **&a, int s, int d, int nodes)
{
  int distance = -1;
  bool visited[nodes + 1][nodes + 1];
  for (int i = 0; i <=nodes; i++) {
   for (int j = 0; j <=nodes; j++) {
     visited[i][j] = false;
   }
  }
  for (int i = s; i <=nodes; i++) {
    for (int k = 0; k <=nodes; k++) {
      
    }
  }
  
  return distance;
}

void deallocateMemory(int **&a, int n) 
{
  for (int i = 0; i <= n; i++) {
     delete a[i];
  }
  delete [] a;
}

void allocateMemory(int **&a, int n) 
{
  a = new int*[n + 1];
  for (int i = 0; i <= n; i++) {
    a[i] = new int[n + 1];
  }
}

void initialize(int **&a, int n)
{
  for (int i = 0; i <= n; i++) {
      for (int k = 0; k <= n; k++) {
        a[i][k] = 0;
      }
   }
}

int main() {
    int t = 0;
    int edges, nodes;
    int **a = NULL;
    cin >> t;
    for (int i = 0; i < t; i++) {
      cin >> nodes;
      cin >> edges;
      allocateMemory(a, nodes);
      initialize(a, nodes);
      for (int i = 0; i < edges; i++) {
       int x, y;
       cin >> x >> y;
       a[x][y] = 6;
       a[y][x] = 6;
      }
      int s;
      cin >> s;
      for (int i=1; i <= nodes; i++) {
        int distance = -1;
        if (i == s) {
         continue;
        } else if ((a[s][i] == 6) ||
                   (a[i][s] == 6)) {
           distance += 7;
          } else if ((a[s][i] == -1) || 
                    (a[i][s] == -1 )) {
            distance += minDistance(a, s, i, nodes);
          }
         cout << distance << " ";
       }
      deallocateMemory(a, nodes);
      cout << endl;
      }
    return 0;
}
