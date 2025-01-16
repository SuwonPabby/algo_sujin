#include <iostream>
#include <set>
using namespace std;

int main() {
  set<int> s;
  s.insert(1);
  for (auto a : s) {
    cout << a << "\n";
  }
  cout << "-----" << endl;
  s.insert(3);
  for (auto a : s) {
    cout << a << "\n";
  }
  cout << "-----" << endl;
  s.insert(5);
  s.insert(10);
  for (auto a : s) {
    cout << a << "\n";
  }
  cout << "-----" << endl;

  cout << *prev(s.end());
}