#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long
#define FOR(i, M) for (int i = 0; i < M; i++)

using namespace std;
int N, M;
vector<int> trees;

bool test(int mid) {
  ll gain = 0;
  for (auto tree : trees) {
    gain += max(tree - mid, 0);
  }

  return (gain >= M);
}

int main() {

  cin >> N >> M;

  int temp;

  FOR(i, N) {
    cin >> temp;
    trees.push_back(temp);
  }

  int start = 0;
  int end = *max_element(trees.begin(), trees.end());

  while (start <= end) {
    int mid = (start + end) / 2;
    if (test(mid)) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  cout << max(end, 0);
}