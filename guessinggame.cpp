#include <iostream>
#include <ctime>
using namespace std;
int main () {
  int low = 1;
  int high = 10;
  int randNum;

  srand(1);
  randNum = rand() % (high - low + 1) + low;
  cout << "random number is " << randNum << endl;

  randNum = rand() % (high - low + 1) + low;
  cout << "random number is " << randNum << endl;
  system("pause");
  return 0;
}
