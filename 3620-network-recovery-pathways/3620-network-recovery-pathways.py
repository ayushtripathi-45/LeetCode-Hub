class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        n = len(online)

        adj = [[] for _ in range(n)]
        low, high = float('inf'), -1

        for u,v, cost in edges:
            adj[u].append((v, cost))
            low = min(low, cost)
            high = max(high, cost)


        def check(mid: int)-> bool:
            priqu = [(0,0)]
            dist = {0: 0}

            while priqu:
                curr_c , u = heapq.heappop(priqu)

                if u == n-1:
                    return curr_c <= k

                if curr_c > dist.get(u, float('inf')):
                    continue

                for v, edg_c in adj[u]:
                    if online[v] and edg_c >= mid:
                        new_c = curr_c + edg_c
                        if new_c < dist.get(v, float('inf')):
                            dist[v] = new_c
                            heapq.heappush(priqu, (new_c, v))

            return ( n - 1) in dist and dist[n-1] <= k

        ans = -1
        while low <= high:
            mid = low+(high-low)//2

            if check(mid):
                ans = mid
                low = mid + 1

            else:
                high = mid - 1

        return ans