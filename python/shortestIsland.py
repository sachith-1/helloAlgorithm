def explore(grid, r, c, visited):
	rowInbound = 0 <= r < len(grid)
	colInbound = 0 <= c < len(grid[0])

	if (not(rowInbound) or not(colInbound)): return 0

	if grid[r][c] == 0: return 0
	elem = str(r) + ',' + str(c)
	if visited.__contains__(elem): return 0
	visited.add(elem)

	count = 1
	count += explore(grid, r+1, c, visited)
	count += explore(grid, r-1, c, visited)
	count += explore(grid, r, c-1, visited)
	count += explore(grid, r, c+1, visited)

	return count


def shortestIsland(grid):
	visited = set()
	min_count = 10000000000
	for i in range(len(grid)):
		for j in range(len(grid[0])):
			count = explore(grid,i,j,visited)
			if count != 0:
				min_count = min(min_count,count)
	return min_count


grid = [
	[0,1,0,0,0],
	[0,1,0,0,0],
	[0,0,0,1,0],
	[0,0,1,1,0],
	[1,0,0,1,1],
	[1,1,0,0,0],
] # 2

print(shortestIsland(grid))


