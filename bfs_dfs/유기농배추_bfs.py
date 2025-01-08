import sys
from collections import deque

input = sys.stdin.readline

T = int(input())

dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]


def bfs(s_row, s_col):
    queue = deque()
    queue.append((s_row, s_col))
    visited[s_row][s_col] = 1

    while queue:
        r, c = queue.popleft()

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if nr < 0 or nc < 0 or nr >= len(board) or nc >= len(board[0]):
                continue

            if visited[nr][nc] == 1:
                continue

            if board[nr][nc] == 0:
                continue

            queue.append((nr, nc))
            visited[nr][nc] = 1


for _ in range(T):
    M, N, K = map(int, input().split())
    board = [[0] * M for _ in range(N)]
    visited = [[0] * M for _ in range(N)]

    for _ in range(K):
        c, r = map(int, input().split())
        board[r][c] = 1

    answer = 0
    for row in range(len(board)):
        for col in range(len(board[0])):
            if board[row][col] == 1 and visited[row][col] == 0:
                bfs(row, col)
                answer += 1

    print(answer)
