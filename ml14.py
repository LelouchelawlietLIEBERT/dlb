import numpy as np
import matplotlib.pyplot as plt

# Environment settings
grid_size = 4
actions = ['up', 'down', 'left', 'right']
action_map = {0: (-1,0), 1: (1,0), 2: (0,-1), 3: (0,1)}

# Hyperparameters
alpha = 0.1        # Learning rate
gamma = 0.9        # Discount factor
epsilon = 0.1      # Exploration rate
episodes = 500

# Initialize Q-table
Q = np.zeros((grid_size, grid_size, len(actions)))

goal = (3, 3)

# Training
for ep in range(episodes):
    state = (0, 0)
    while state != goal:
        if np.random.rand() < epsilon:
            action = np.random.randint(4)
        else:
            action = np.argmax(Q[state[0], state[1]])

        move = action_map[action]
        next_state = (state[0] + move[0], state[1] + move[1])

        # Boundary check
        if (0 <= next_state[0] < grid_size and
            0 <= next_state[1] < grid_size):
            reward = 10 if next_state == goal else -1
        else:
            next_state = state
            reward = -1

        # Q-learning update
        Q[state[0], state[1], action] += alpha * (
            reward + gamma * np.max(Q[next_state[0], next_state[1]]) -
            Q[state[0], state[1], action]
        )

        state = next_state

# Display final Q-table
print("Final Q-Table:")
print(np.round(Q, 2))

# Extract optimal path
state = (0, 0)
path = [state]

while state != goal:
    action = np.argmax(Q[state[0], state[1]])
    move = action_map[action]
    next_state = (state[0] + move[0], state[1] + move[1])
    if next_state == state:
        break
    state = next_state
    path.append(state)

# Visualization
grid = np.zeros((grid_size, grid_size))
for p in path:
    grid[p] = 1

plt.imshow(grid, cmap='Blues')
plt.scatter(0, 0, c='green', s=200, label='Start')
plt.scatter(3, 3, c='red', s=200, label='Goal')
plt.title("Optimal Path Learned using Q-Learning")
plt.legend()
plt.show()

# import pandas as pd
# import numpy as np
# import matplotlib.pyplot as plt

# # 1. Load given dataset
# data = pd.read_csv("dataset.csv")

# # 2. Extract components
# states = data['state'].unique()
# actions = data['action'].unique()

# num_states = len(states)
# num_actions = len(actions)

# # Map states to indices
# state_map = {s: i for i, s in enumerate(states)}

# # 3. Initialize Q-table with zeros
# Q = np.zeros((num_states, num_actions))

# # Hyperparameters
# alpha = 0.1      # learning rate
# gamma = 0.9      # discount factor
# episodes = 500

# # 4. Q-Learning training using dataset
# for _ in range(episodes):
#     for _, row in data.iterrows():
#         s = state_map[row['state']]
#         a = row['action']
#         r = row['reward']
#         s_next = state_map[row['next_state']]

#         Q[s, a] = Q[s, a] + alpha * (
#             r + gamma * np.max(Q[s_next]) - Q[s, a]
#         )

# # 5. Display final Q-table
# print("Final Q-Table:")
# print(np.round(Q, 2))

# # 6. Visualize learned policy
# policy = np.argmax(Q, axis=1)

# plt.figure(figsize=(8,4))
# plt.bar(range(num_states), policy)
# plt.xlabel("State")
# plt.ylabel("Best Action")
# plt.title("Optimal Policy Learned using Q-Learning")
# plt.show()
