def valid_connection(
    graph: list[list[int]], next_ver: int, curr_ind: int, path: list[int]
) -> bool:

    # 1. Validate that path exists between current and next vertices
    if graph[path[curr_ind - 1]][next_ver] == 0:
        return False

    # 2. Validate that next vertex is not already in path
    return not any(vertex == next_ver for vertex in path)


def util_hamilton_cycle(graph: list[list[int]], path: list[int], curr_ind: int) -> bool:

    # Base Case
    if curr_ind == len(graph):
        # return whether path exists between current and starting vertices
        return graph[path[curr_ind - 1]][path[0]] == 1

    # Recursive Step
    for next in range(0, len(graph)):
        if valid_connection(graph, next, curr_ind, path):
            # Insert current vertex  into path as next transition
            path[curr_ind] = next
            # Validate created path
            if util_hamilton_cycle(graph, path, curr_ind + 1):
                return True
            # Backtrack
            path[curr_ind] = -1
    return False


def hamilton_cycle(graph: list[list[int]], start_index: int = 0) -> list[int]:
    

    # Initialize path with -1, indicating that we have not visited them yet
    path = [-1] * (len(graph) + 1)
    # initialize start and end of path with starting index
    path[0] = path[-1] = start_index
    # evaluate and if we find answer return path either return empty array
    return path if util_hamilton_cycle(graph, path, 1) else []
