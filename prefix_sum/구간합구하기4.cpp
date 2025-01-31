#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long
#define FOR(i, M) for (int i = 0; i < M; i++)

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<int> arr(N);

  FOR(i, N) { cin >> arr[i]; }
  vector<int> prefixSum(N + 1);
  prefixSum[0] = 0;
  int i = 1;
  for (auto item : arr) {
    prefixSum[i] = (prefixSum[i - 1] + item);
    i++;
    // cout << prefixSum[i - 1] << endl;
  }

  FOR(i, M) {
    int start, end;
    cin >> start >> end;
    cout << prefixSum[end] - prefixSum[start - 1] << "\n";
  }
}
