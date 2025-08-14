from collections import deque

# Adjacency list for the graph
adj_list = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': [],
    'F': []
}

# Initialize node status
# 1: Ready (Unvisited)
# 2: Waiting (In Queue)
# 3: Visited (Dequeued from Queue)
def initialize_status(adj_list):
    return {node: 1 for node in adj_list}

# BFS function  
def bfs_search(start, dest, adj_list):
    queue = deque()
    final_path = []
    status = initialize_status(adj_list)

    queue.append(start)
    status[start] = 2  # Waiting

    while queue:
        current = queue.popleft()
        final_path.append(current)
        status[current] = 3  # Visited

        if current == dest:
            break

        for neighbor in adj_list[current]:
            if status[neighbor] == 1:  # Ready
                queue.append(neighbor)
                status[neighbor] = 2  # Waiting

    return final_path

# Main program
if __name__ == "__main__":
    start = input("Enter start node: ").upper()
    destination = input("Enter destination node: ").upper()
    
    path = bfs_search(start, destination, adj_list)
    print(f"Path from {start} to {destination}: {' -> '.join(path)}")
