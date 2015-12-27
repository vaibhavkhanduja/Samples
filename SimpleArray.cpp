#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;


int main() {

#if 0
	unsigned int n = 0;
	
	cin >> n;
    for (int i = 0; i <= n;i++) {
		cout.width(n - i + 1);
		for (int j = 0; j < i; j++) {
			cout << "#";
		}
	   cout << endl;
    }
#endif

  string input_time_br[3];
  string input_time;
  int i = 0;
  string output_time;
  char *p = NULL;
  
  cin >> input_time;
  p = strtok(const_cast<char *>(input_time.data()), ":");
  while (p != NULL) {
	  input_time_br[i++] = p;
  }
  if (input_time_br[2].find("PM")) {
	  input_time_br[0] = stoi(input_time_br[0]) + 12;
  }
  
  cout << input_time_br[0] << ":" << input_time_br[1] << ":"<< input_time_br[2] << endl;
  
}
