#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define REP(i, n) for (int i = 0; i < n; i++)
using namespace std;

struct MinCompare {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
      return a.second > b.second; // 1번 요소가 작은 것이 우선
    }
    return a.first > b.first; // 0번 요소가 작은 것이 우선
  }
};

struct MaxCompare {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
      return a.second < b.second; // 1번 요소가 작은 것이 우선
    }
    return a.first < b.first; // 0번 요소가 작은 것이 우선
  }
};

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  unordered_set<string> solvedSet;
  unordered_map<int, int> P2L;
  priority_queue<pair<int, int>, vector<pair<int, int>>, MinCompare> minHeap;
  priority_queue<pair<int, int>, vector<pair<int, int>>, MaxCompare> maxHeap;

  cin >> N;

  for (int i = 0; i < N; i++) {
    int P, L;
    cin >> P >> L;
    minHeap.push({L, P});
    maxHeap.push({L, P});
    P2L[P] = L;
  }

  int M;
  cin >> M;

  REP(i, M) {
    string cmd;
    int Pc;
    int Lc;

    cin >> cmd;

    if (cmd[0] == 'a') {
      cin >> Pc >> Lc;
      minHeap.push({Lc, Pc});
      maxHeap.push({Lc, Pc});
      P2L[Pc] = Lc;

    } else if (cmd[0] == 'r') {
      int x;
      cin >> x;

      if (x == 1) {
        while (true) {
          auto top = maxHeap.top();
          string key = to_string(top.second) + "," + to_string(top.first);
          if (solvedSet.count(key)) {
            maxHeap.pop();
          } else {
            break;
          }
        }
        cout << maxHeap.top().second << "\n";
      } else {
        while (true) {
          auto top = minHeap.top();
          string key = to_string(top.second) + "," + to_string(top.first);
          if (solvedSet.count(key)) {
            minHeap.pop();
          } else {
            break;
          }
        }
        cout << minHeap.top().second << "\n";
      }

    } else {
      cin >> Pc;
      solvedSet.insert(to_string(Pc) + "," + to_string(P2L[Pc]));
    }
  }
}