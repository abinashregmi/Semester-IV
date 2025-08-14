from collections import deque

# Define the capacities of the two jugs
MAX_A = 5  # Jug A capacity
MAX_B = 3  # Jug B capacity

def is_goal(state):
    """
    Checks if the current state satisfies the goal condition.
    The goal is to have exactly 1 gallon in jug A.

    Args:
        state (tuple): A tuple (a, b) representing the water in jug A and jug B.

    Returns:
        bool: True if the goal is met, False otherwise.
    """
    return state[0] == 1

def get_next_states(state):
    """
    Generates all possible next states from the current state based on allowed actions.
    
    Args:
        state (tuple): The current state (a, b) of the jugs.

    Returns:
        list: A list of tuples, where each tuple is a valid next state.
    """
    a, b = state
    successors = []

    # 1. Fill Jug A
    successors.append((MAX_A, b))

    # 2. Fill Jug B
    successors.append((a, MAX_B))

    # 3. Empty Jug A
    successors.append((0, b))

    # 4. Empty Jug B
    successors.append((a, 0))

    # 5. Pour from A to B
    pour_amount = min(a, MAX_B - b)
    successors.append((a - pour_amount, b + pour_amount))

    # 6. Pour from B to A
    pour_amount = min(b, MAX_A - a)
    successors.append((a + pour_amount, b - pour_amount))
    
    return successors

def water_jug_bfs(start_state):
    """
    Solves the water jug problem using Breadth-First Search.

    Args:
        start_state (tuple): The initial state of the jugs, typically (0, 0).

    Returns:
        list: A list of states representing the solution path, or None if no solution exists.
    """
    visited_set = set()
    # Queue stores tuples of (current_state, path_to_current_state)
    queue = deque([(start_state, [start_state])])
    visited_set.add(start_state)

    while queue:
        current_state, path = queue.popleft()

        if is_goal(current_state):
            return path

        for next_state in get_next_states(current_state):
            if next_state not in visited_set:
                visited_set.add(next_state)
                new_path = path + [next_state]
                queue.append((next_state, new_path))
    
    return None

# --- Main Execution ---
if __name__ == "__main__":
    start_state = (0, 0)
    solution_path = water_jug_bfs(start_state)

    if solution_path:
        print("Solution found! Here is the step-by-step path:")
        for step, state in enumerate(solution_path):
            print(f"Step {step}: Jug A = {state[0]} | Jug B = {state[1]}")
    else:
        print("No solution found for the given goal.")