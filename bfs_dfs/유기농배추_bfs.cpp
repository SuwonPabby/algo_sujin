#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#define REP(i, n) for (int i=0; i < n; i++)
using namespace std;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void bfs(int r, int c, vector<vector<int>>& board, vector<vector<int>>& visited){
  queue<vector<int>> queue;
  queue.push({r, c});
  visited[r][c] = 1;

  while (!queue.empty()) {
    vector<int> value = queue.front();
    queue.pop();
    int row = value[0];
    int col = value[1];

    REP(i, 4) {
      int nr = row + dr[i];
      int nc = col + dc[i];

      if (nr < 0 || nc < 0 || nr >= board.size() || nc >= board[0].size()) {
        continue;
      }

      if (visited[nr][nc] == 1) continue;

      if (board[nr][nc] == 0) continue;

      queue.push({nr, nc});
      visited[nr][nc] = 1;

    }
  }
}

int main(){
  int T;
  cin >> T;
  REP(i, T) {
    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));

    REP(i, K) {
      int c, r;
      cin >> c >> r;
      board[r][c] = 1;
    }

    int answer = 0;
    REP(row, N) {
      REP(col, M) {
        if (board[row][col] == 1 && visited[row][col] == 0) {
          bfs(row, col, board, visited);
          answer += 1;
        }
      }
    }
    cout << answer << endl;
  }
}
