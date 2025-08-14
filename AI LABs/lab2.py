# Depth First Search Implementation in Python
# Lab 2 - Followed exactly as per given pseudocode

# Define adjacency list
adj_list = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': [],
    'F': []
}

# Status codes:
# 1 = Ready (Unvisited)
# 2 = Waiting (In Stack)
# 3 = Visited (Popped from Stack)

def initialize_status(adj_list):
    status = {}
    for node in adj_list:
        status[node] = 1
    return status

def dfs_search(start, dest, adj_list):
    stack = []
    final_path = []
    status = initialize_status(adj_list)

    # Push start node onto stack
    stack.append(start)
    status[start] = 2

    while True:
        # Pop the top node from the stack
        current = stack.pop()
        final_path.append(current)
        status[current] = 3

        # If destination found, break
        if current == dest:
            break

        # Push all unvisited neighbors
        for neighbor in adj_list[current]:
            if status[neighbor] == 1:
                stack.append(neighbor)
                status[neighbor] = 2

        # If stack is empty, break (no path)
        if not stack:
            break

    return final_path

def display_adjacency_list(adj_list):
    print("Adjacency List:")
    for key, value in adj_list.items():
        print(key, "-->", value)
  
def main():
    display_adjacency_list(adj_list)

    # Input start and destination nodes
    start = input("Enter the start node: ").upper()
    dest = input("Enter the destination node: ").upper()

    path = dfs_search(start, dest, adj_list)

    print("Path from", start, "to", dest, ":")
    for node in path:
        print(node, "->", end=" ")
    print("End")

if __name__ == "__main__":
    main()
