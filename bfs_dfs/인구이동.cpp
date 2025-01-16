#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define VV(T) vector<vector<T>>
#define V(T) vector<T>
#define FOR(i, m) for (int i = 0; i < m; i++)
using namespace std;

int N, L, R;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void bfs(int sr, int sc, VV(int) & board, VV(int) & visited,
         VV(int) & newBoard) {
  int total = 0;
  int nations = 0;
  queue<pair<int, int>> queue;
  vector<pair<int, int>> unionVector;

  queue.push({sr, sc});
  unionVector.push_back({sr, sc});
  visited[sr][sc] = 1;
  total += board[sr][sc];
  nations++;

  while (!queue.empty()) {
    int r, c;
    r = queue.front().first;
    c = queue.front().second;
    queue.pop();

    FOR(i, 4) {
      int nr = r + dr[i];
      int nc = c + dc[i];

      if (nr < 0 || nr == N || nc < 0 || nc == N) {
        continue;
      }

      if (visited[nr][nc]) {
        continue;
      }

      int diff = abs(board[nr][nc] - board[r][c]);
      if (L <= diff & diff <= R) {
        queue.push({nr, nc});
        visited[nr][nc] = 1;
        unionVector.push_back({nr, nc});
        total += board[nr][nc];
        nations += 1;
      }
    }
  }
  int newPopulation = total / nations;
  for (auto u : unionVector) {
    newBoard[u.first][u.second] = newPopulation;
  }
}

int main() {

  cin >> N >> L >> R;

  VV(int) board(N, V(int)(N, 0));

  FOR(i, N) {
    FOR(j, N) { cin >> board[i][j]; }
  }

  int cnt = 0;
  while (true) {
    VV(int) visited(N, V(int)(N, 0));
    VV(int) newBoard = board;
    bool flag = false;

    FOR(r, N) {
      FOR(c, N) {
        FOR(i, 4) {
          int nr = r + dr[i];
          int nc = c + dc[i];

          if (visited[r][c]) {
            continue;
          }

          if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
            continue;
          }

          int diff = abs(board[nr][nc] - board[r][c]);
          if (L <= diff && diff <= R) {
            bfs(r, c, board, visited, newBoard);
            flag = true;
          }
        }
      }
    }
    if (!flag) {
      break;
    }

    board = newBoard;
    cnt++;
  }
  cout << cnt;
}