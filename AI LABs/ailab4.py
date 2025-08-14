import heapq

# --- Define the Graph and Heuristic Values ---
# Adjacency list representing the graph connections
adj_list = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': [],
    'F': []
}

# Heuristic values for each node, estimating the distance to the goal 'F'
heuristic_values = {
    'A': 5,
    'B': 2,
    'C': 3,
    'D': 4,
    'E': 1,
    'F': 0
}

# --- Greedy Best-First Search Function ---
def gbfs(start, goal):
    """
    Performs Greedy Best-First Search (GBFS) from a start node to a goal node.
    This algorithm prioritizes nodes based on their heuristic value,
    always expanding the node that appears closest to the goal.

    Args:
        start (str): The starting node.
        goal (str): The goal node.

    Returns:
        list: A list representing the path found from start to goal.
              Returns None if the goal is not reachable.
    """
    visited = set()
    # The priority queue stores tuples of (heuristic_value, node)
    # The heapq module implements a min-heap, so the node with the
    # smallest heuristic value will always be at the top.
    priority_queue = [(heuristic_values[start], start)]
    path = []

    while priority_queue:
        # Pop the node with the lowest heuristic value
        heuristic_value, current_node = heapq.heappop(priority_queue)

        if current_node in visited:
            continue

        path.append(current_node)
        visited.add(current_node)

        # Check if the current node is the goal
        if current_node == goal:
            return path

        # Explore neighbors
        for neighbor in adj_list.get(current_node, []):
            if neighbor not in visited:
                # Add the neighbor to the priority queue with its heuristic value
                heapq.heappush(priority_queue, (heuristic_values[neighbor], neighbor))

    return None

# --- Utility and Main Functions ---
def display_adjacency_list():
    """
    Prints the adjacency list of the graph.
    """
    print("Adjacency List:")
    for node, neighbors in adj_list.items():
        print(f"{node} -> {neighbors}")

def main():
    """
    Main function to run the Greedy Best-First Search.
    """
    display_adjacency_list()

    while True:
        try:
            start_node = input("\nEnter the start node: ").upper()
            destination_node = input("Enter the destination node: ").upper()

            if start_node not in adj_list or destination_node not in adj_list:
                print("Error: One or both of the nodes are not in the graph. Please try again.")
                continue

            break
        except (ValueError, KeyError):
            print("Invalid input. Please enter a valid node.")
    
    # Execute the GBFS algorithm
    path = gbfs(start_node, destination_node)

    # Print the result
    if path:
        print(f"\nPath from {start_node} to {destination_node}:")
        print(" -> ".join(path))
    else:
        print(f"\nNo path found from {start_node} to {destination_node}.")

if __name__ == "__main__":
    main()