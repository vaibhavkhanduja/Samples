#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

int main() {
  string input;
  getline(cin, input);
  char *start = const_cast<char *>(input.c_str());
  char *end = start;
  while (*end) {
    end++;
  }
  --end;
  while (start < end) {
    char tmp = *start;
    *start = *end;
    *end = tmp;
    end--;
    start++;
  }
  cout << input << endl;
    
  return 0;
}
