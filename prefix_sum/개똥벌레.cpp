#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long
#define FOR(i, M) for (int i = 0; i < M; i++)

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, H;

  cin >> N >> H;

  vector<int> group1(N / 2);
  vector<int> group2(N / 2);

  FOR(i, N / 2) {
    cin >> group1[i];
    cin >> group2[i];
  }

  vector<int> prefix1(H + 1);
  vector<int> prefix2(H + 1);
  vector<int> arr1(H);
  vector<int> arr2(H);

  prefix1[0] = 0;
  prefix2[0] = 0;

  for (auto item : group1) {
    arr1[H - item] += 1;
  }

  for (auto item : group2) {
    arr2[H - item] += 1;
  }

  int i = 1;
  for (auto item : arr1) {
    prefix1[i] = prefix1[i - 1] + item;
    i++;
  }

  i = 1;
  for (auto item : arr2) {
    prefix2[i] = prefix2[i - 1] + item;
    i++;
  }

  vector<int> result(H);

  for (int i = 1; i < H + 1; i++) {
    result[H - i] += prefix1[i];
  }
  for (int i = 1; i < H + 1; i++) {
    result[i - 1] += prefix2[i];
  }

  //   for (auto item : result) {
  //     cout << item << " ";
  //   }

  int ans = result[0];
  int cnt = 1;
  for (int i = 1; i < H; i++) {
    if (ans > result[i]) {
      ans = result[i];
      cnt = 1;
    } else if (ans == result[i]) {
      cnt += 1;
    }
  }

  cout << ans << " " << cnt;
}
