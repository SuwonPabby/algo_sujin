#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#define REP(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  unordered_set<string> names;
  string name;
  string cmd;
  REP(i, n) {
    cin >> name >> cmd;
    if (cmd == "enter") {
      names.insert(name);
    } else {
      names.erase(name);
    }
  }

  vector<string> answer;
  for (auto n : names) {
    answer.push_back(n);
  }

  sort(answer.begin(), answer.end(), greater<>());

  for (auto n : answer) {
    cout << n << "\n";
  }
}
