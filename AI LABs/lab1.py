import random
import time # Import the 'time' module for delays

A = 1  # Corrected: Booleans are capitalized in Python
B = 0 # Corrected: Booleans are capitalized in Python

# Represents a simple environment with two rooms, A and B
# True means dirty, False means clean
# We'll use a dictionary for better room management
# Initial state: Both rooms are dirty
environment_state = {"A": True, "B": True}

def vacuum_cleaner_action():
    """
    Simulates the vacuum cleaner's action (e.g., deciding where to go).
    In this simplified example, it might randomly pick a room.
    """
    # Let's say it randomly picks one of the rooms to be its current location
    return random.choice(list(environment_state.keys()))

def random_dirty_state():
    """
    Generates a random dirty state for the rooms.
    For this program, we'll keep a persistent 'environment_state'
    that the agent interacts with directly.
    If you wanted to *reset* to a random dirty state, you could do:
    for room in environment_state:
        environment_state[room] = random.choice([True, False])
    """
    return environment_state # We'll work with the global environment_state

def clean_room(room_index, env_state_dict):
    """
    Cleans a specified room.
    Args:
        room_index (str): The name of the room (e.g., "A", "B").
        env_state_dict (dict): The dictionary representing the environment's state.
    """
    print(f"Cleaning room {room_index}") # Corrected: f-string for easy formatting
    env_state_dict[room_index] = False # Corrected: Accessing dictionary element
    time.sleep(1) # Corrected: Use time.sleep() for delays
    return env_state_dict # Return the updated state, though it's modified in place

def simple_reflex_agent():
    """
    Implements a simple reflex agent for the vacuum cleaner.
    """
    print("I am a vacuum cleaner!")
    global environment_state # Declare intent to modify global variable
    cleaned_room_count = 0

    # The agent will continue until all rooms are clean
    while cleaned_room_count < len(environment_state):
        current_vacuum_location = vacuum_cleaner_action() # Get the current focus room

        print(f"\nCurrent vacuum location: {current_vacuum_location}")
        print(f"Environment dirty state: {environment_state}")

        if environment_state[current_vacuum_location] == True: # Check if the current room is dirty
            clean_room(current_vacuum_location, environment_state)
            print(f"Room {current_vacuum_location} is now clean.")
            cleaned_room_count = sum(1 for dirty in environment_state.values() if not dirty)
        else:
            print(f"Room {current_vacuum_location} is already clean.")
            # If the room is already clean, the agent might decide to move to another
            # For this simple agent, we'll just let it continue its random choice for demonstration.
            time.sleep(0.5) # Short pause if already clean

        # You might want more sophisticated logic for checking all rooms
        # For this simple agent, it will keep trying rooms until all are clean.

    print("\nAll rooms are clean. Task completed.")


# Main part of the program
if __name__ == "__main__":

    simple_reflex_agent()