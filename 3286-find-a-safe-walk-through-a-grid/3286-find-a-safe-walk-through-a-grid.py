class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m, n = len(grid), len(grid[0])

        size = [[float('inf')] * n for _ in range(m)]

        q = deque([(0, 0)])
        size[0][0] = grid[0][0]

        direc = [(0, 1), (1,0), (0,-1), (-1, 0)]

        while q:
            r, c = q.popleft()

            if r == m - 1 and c == n - 1:
                continue
            
            for dr, dc in direc:
                nr, nc = r + dr, c + dc

                if 0 <= nr < m and 0 <= nc < n:
                    n_size = size[r][c] + grid[nr][nc]

                    if n_size < size[nr][nc]:
                        size[nr][nc] = n_size

                        if grid[nr][nc] == 0:
                            q.appendleft((nr, nc))

                        else :
                            q.append((nr, nc))

        return health - size[m-1][n-1] > 0
        