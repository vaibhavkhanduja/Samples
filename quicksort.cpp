#include <bits/stdc++.h>
using namespace std;

void quickSortA(vector <int> &arr, int l, int h)
{
   if (l < h) 
   {
      int p = partition(arr, l , h);
      quickSortA(arr, l, p - 1);
      quickSortA(arr, p + 1, h);
   }
  
}
void quickSort(vector <int> &arr) {
   quickSortA(arr, 0, arr.size());
}

int main() {
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
