#include <iostream>
#include <set>
#include <vector>
using namespace std;

void func(vector<vector<int>> &a) {
  cout << a[0][0] << endl;
  a[0][0] = 1;
}

int main() {
  vector<vector<int>> a(3, vector<int>(3, 0));
  func(a);
  cout << a[0][0] << endl;
}