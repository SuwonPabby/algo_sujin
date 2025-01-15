import sys
from collections import deque
import copy

input = sys.stdin.readline

dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]


def bfs(s_r, s_c, board, visited, new_board):
    total = 0
    nations = 0
    queue = deque()
    union_list = []
    queue.append((s_r, s_c))
    union_list.append((s_r, s_c))
    visited[s_r][s_c] = 1
    total += board[s_r][s_c]
    nations += 1

    while queue:
        r, c = queue.popleft()

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if nr < 0 or nr >= N or nc < 0 or nc >= N:
                continue

            if visited[nr][nc]:
                continue

            if L <= abs(board[nr][nc] - board[r][c]) <= R:
                queue.append((nr, nc))
                visited[nr][nc] = 1
                union_list.append((nr, nc))
                total += board[nr][nc]
                nations += 1

    new_population = total // nations
    for u in union_list:
        new_board[u[0]][u[1]] = new_population


N, L, R = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

cnt = 0
while True:
    visited = [[0] * N for _ in range(N)]
    new_board = copy.deepcopy(board)
    flag = False
    for r in range(N):
        for c in range(N):
            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]

                if visited[r][c]:
                    continue

                if nr < 0 or nr >= N or nc < 0 or nc >= N:
                    continue

                if L <= abs(board[nr][nc] - board[r][c]) <= R:
                    bfs(r, c, board, visited, new_board)
                    flag = True

    if not flag:
        break
    board = copy.deepcopy(new_board)
    cnt += 1

print(cnt)
