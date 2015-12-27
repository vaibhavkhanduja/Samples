#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define PANGRAM 0x3FFFFFF

using namespace std;

bool isPangram(string &input) {
 union {
  unsigned int value:26;
 }number;
  for (int i = 0; i < input.length(); i++) {
     if (input.at(i) == ' ') continue;
     else {
      number.value |= 1  << (int)((tolower(input.at(i)) - 97));
      if (number.value == PANGRAM) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  string input;
  getline(cin, input);
  if (isPangram(input)) {
    cout << "pangram" << endl;
  } else {
    cout << "not pangram" << endl;
  }
  return 0;
}
