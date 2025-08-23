
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Load dataset
df = pd.read_csv('housing_prices.csv')

# Features (Area, Num_rooms)
X = df[['area_sqft', 'num_rooms']].values
y = df['price'].values

# Normalize features for stability
X = (X - X.mean(axis=0)) / X.std(axis=0)



# Normalize target to range (0,1) for sigmoid output
y_min, y_max = y.min(), y.max()
y_norm = (y - y_min) / (y_max - y_min)

# Sigmoid activation
def sigmoid(z):
    return 1 / (1 + np.exp(-z))



# Initialize weights randomly, bias = 0
weights = np.random.randn(2)
bias = 0

# Hyperparameters
lr = 0.1
epochs = 1000

for epoch in range(epochs):
    # Forward pass
    z = np.dot(X, weights) + bias
    y_pred = sigmoid(z)

    # Loss (MSE for monitoring)
    mse_loss = np.mean((y_pred - y_norm) ** 2)
    if((epoch+1)%50==0):
      print(f"Epoch:{epoch+1}, loss= {mse_loss}")

    # Gradients (explicit chain rule)
    dE_dy = (y_pred - y_norm)                         # derivative of error w.r.t sigmoid output
    dy_dz = sigmoid(z) * (1 - sigmoid(z))             # derivative of sigmoid output w.r.t z
    dz_dw = X                                         # derivative of z w.r.t weights
    dz_db = 1                                         # derivative of z w.r.t bias

    grad_w = np.dot(dz_dw.T, dE_dy * dy_dz) / len(X)   # combine chain rule for weights
    grad_b = np.sum(dE_dy * dy_dz * dz_db) / len(X)    # combine chain rule for bias

    # Update weights and bias
    weights -= lr * grad_w
    bias -= lr * grad_b

weights

bias

# Input values
test_area = 2135
test_rooms = 4

# Normalize features using training data statistics
test_X = np.array([test_area, test_rooms])
test_X_norm = (test_X - df[['area_sqft', 'num_rooms']].mean().values) / df[['area_sqft', 'num_rooms']].std().values

# Predict (sigmoid output)
z_test = np.dot(test_X_norm, weights) + bias
pred_norm = sigmoid(z_test)

# Denormalize to original price range
pred_price = pred_norm * (y_max - y_min) + y_min

print(f"Predicted Price for area={test_area} sq ft and rooms={test_rooms}: {pred_price:.2f}")

"""
another project
"""


import pandas as pd
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
import matplotlib.pyplot as plt

# Load dataset
df = pd.read_csv('housing_prices.csv')

# Features (Area, Num_rooms)
X = df[['area_sqft', 'num_rooms']].values
y = df['price'].values

# Normalize features for stability
X_mean = X.mean(axis=0)
X_std = X.std(axis=0)
X_norm = (X - X_mean) / X_std

# Normalize target to (0, 1) for sigmoid output
y_min, y_max = y.min(), y.max()
y_norm = (y - y_min) / (y_max - y_min)

# Convert NumPy arrays to torch tensors
X_tensor = torch.tensor(X_norm, dtype=torch.float32)
y_tensor = torch.tensor(y_norm.reshape(-1, 1), dtype=torch.float32)

# Define a custom model
class SingleLayerModel(nn.Module):
    def __init__(self):
        super(SingleLayerModel, self).__init__()
        self.linear = nn.Linear(2, 1)  # 2 inputs -> 1 output

    def forward(self, x):
        z = self.linear(x)
        return torch.sigmoid(z)

# Initialize model
model = SingleLayerModel()

# Loss function
criterion = nn.MSELoss()

# Optimizer
optimizer = optim.SGD(model.parameters(), lr=0.01)

# Training loop
epochs = 10000
for epoch in range(epochs):
    # Forward pass
    y_pred = model(X_tensor)

    # Compute loss
    loss = criterion(y_pred, y_tensor)
    print(f"Epoch: {epoch+1}, loss:{loss}")
    # Backward pass
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

# Get predictions and denormalize
with torch.no_grad():
    final_preds_torch = model(X_tensor).numpy().flatten()

final_preds_denorm = final_preds_torch * (y_max - y_min) + y_min

# Plot results
plt.scatter(df['area_sqft'], df['price'], label="Data points")
plt.plot(df['area_sqft'], final_preds_denorm, color='red', label="Best Fit Line (PyTorch)")
plt.xlabel("Area (sq ft)")
plt.ylabel("Price")
plt.title("Area vs Price (Custom nn.Module + SGD)")
plt.legend()
plt.show()

# Print learned parameters
for name, param in model.named_parameters():
    print(f"{name}: {param.data.numpy()}")
print("Final MSE Loss:", loss.item())

# ---- Predict for area=2135, rooms=4 ----
test_input = np.array([[2135, 4]], dtype=np.float32)
test_input_norm = (test_input - X_mean) / X_std
test_tensor = torch.tensor(test_input_norm, dtype=torch.float32)

with torch.no_grad():
    pred_norm = model(test_tensor).item()

pred_price = pred_norm * (y_max - y_min) + y_min
print(f"Predicted Price for area=2135 sq ft and rooms=4: {pred_price:.2f}")

