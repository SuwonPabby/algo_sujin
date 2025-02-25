#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long
#define FOR(i, M) for (int i = 0; i < M; i++)

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  vector<vector<int>> dp(N, vector<int>(3, 0));
  dp[0][0] = 1;
  dp[0][1] = 1;
  dp[0][2] = 1;

  FOR(i, N - 1) {
    int idx = i + 1;
    dp[idx][0] = (dp[idx - 1][0] + dp[idx - 1][1] + dp[idx - 1][2]) % 9901;
    dp[idx][1] = (dp[idx - 1][0] + dp[idx - 1][2]) % 9901;
    dp[idx][2] = (dp[idx - 1][0] + dp[idx - 1][1]) % 9901;
  }
  cout << (dp[N - 1][0] + dp[N - 1][1] + dp[N - 1][2]) % 9901;
}