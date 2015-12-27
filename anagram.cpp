#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main() {
    unsigned int t = 0;
    cin >> t;
    int i = 0;
    while (i < t) {
       string input_string;
       unsigned int length = 0;
       unsigned int num1[26] = {0}, num2[26] = {0};
       int z = 0;
       cin >> input_string;
       length = input_string.length();
       if (length % 2 != 0) {
         cout << -1 << endl;
       } else {
           for (int j = 0; j < length/2;j++) {
              num1[(int)(input_string[j]) - 97]++;
          }
          for (int j = length/2; j< length;j++) {
              num2[(int)(input_string[j]) - 97]++;
          }
          for (int j = 0; j < 26;j++) {
            if (num1[j] < num2[j]) {
              z = z + (num2[j] - num1[j]);
           }
          }
         cout << z << endl;
       }
      i++;
      }
    return 0;
}
