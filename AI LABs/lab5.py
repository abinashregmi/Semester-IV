import heapq

# Define the graph as an adjacency list with costs
# Format: node -> [(neighbor, cost), ...]
graph = {
    'A': [('B', 1), ('C', 4), ('D', 3)],
    'B': [('E', 2)],
    'C': [('E', 1), ('F', 5)],
    'D': [('F', 6)],
    'E': [('F', 1)],
    'F': []
}

# Define the heuristic estimates from each node to the goal 'F'
heuristic = {
    'A': 7,
    'B': 6,
    'C': 2,
    'D': 4,
    'E': 1,
    'F': 0
}

def a_star_search(start, goal):
    """
    Performs A* search to find the shortest path from start to goal.

    Args:
        start (str): The starting node.
        goal (str): The goal node.

    Returns:
        list: The path from start to goal as a list of nodes, or None if no path exists.
    """
    # The priority queue stores tuples: (f_cost, g_cost, current_node, path)
    # The f_cost is the sum of g_cost (cost from start) and the heuristic.
    open_set = [(heuristic[start], 0, start, [start])]
    
    # A set to keep track of visited nodes to avoid cycles and redundant work.
    visited = set()

    while open_set:
        # Pop the node with the smallest f_cost
        f_cost, g_cost, current_node, path = heapq.heappop(open_set)

        # If the current node is the goal, we have found the path
        if current_node == goal:
            return path
        
        # If we've already visited this node, skip it
        if current_node in visited:
            continue
        
        # Mark the current node as visited
        visited.add(current_node)
        
        # Explore neighbors
        for neighbor, cost in graph.get(current_node, []):
            if neighbor not in visited:
                # Calculate the costs for the neighbor
                new_g_cost = g_cost + cost
                new_f_cost = new_g_cost + heuristic[neighbor]
                
                # Push the neighbor to the priority queue
                new_path = path + [neighbor]
                heapq.heappush(open_set, (new_f_cost, new_g_cost, neighbor, new_path))
    
    # If the loop finishes, no path was found
    return None

def main():
    """
    Main function to run the A* search and display the result.
    """
    print("Graph adjacency list with costs:")
    for node, neighbors in graph.items():
        print(f"{node} -> {neighbors}")

    start_node = 'A'
    goal_node = 'F'
    print(f"\nSearching for shortest path from '{start_node}' to '{goal_node}'...")

    path = a_star_search(start_node, goal_node)

    if path:
        print(f"\nShortest path found: {' -> '.join(path)}")
        print(f"Total cost: {sum(graph[path[i]][j][1] for i in range(len(path)-1) for j in range(len(graph[path[i]])) if graph[path[i]][j][0] == path[i+1])}")
    else:
        print("\nNo path found.")

if __name__ == "__main__":
    main()