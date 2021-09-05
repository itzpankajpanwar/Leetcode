class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        visited = set()
        def dfs(node):
            if node in visited:
                return 0
            visited.add(node)
            secs = 0
            for child in adj[node]:
                secs += dfs(child)
            if secs > 0:
                return secs + 2
            return 2 if hasApple[node] else 0

        return max(dfs(0) - 2, 0)
        