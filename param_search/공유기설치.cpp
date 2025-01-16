#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long
#define FOR(i, M) for (int i = 0; i < M; i++)

using namespace std;

int N, C;
vector<int> houses;

bool test(int mid) {
  int now = C - 1;
  int acc = 0;
  FOR(i, N - 1) {
    acc += houses[i + 1] - houses[i];
    if (acc >= mid) {
      now -= 1;
      acc = 0;
    }
  }

  return !(now > 0);
}

int main() {
  cin >> N >> C;
  FOR(i, N) {
    int temp;
    cin >> temp;
    houses.push_back(temp);
  }
  sort(houses.begin(), houses.end());

  int start = 0;
  int end = houses[N - 1];

  while (start <= end) {
    int mid = (start + end) / 2;
    if (test(mid)) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  cout << end;
}