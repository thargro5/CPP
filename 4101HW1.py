import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Load the dataset from GitHub
url = "https://raw.githubusercontent.com/HamedTabkhi/Intro-to-ML/main/Dataset/D3.csv"
data = pd.read_csv(url)

# access elements in table by rows/cols rather than labels
x1 = data.iloc[:, 0].values
x2 = data.iloc[:, 1].values
x3 = data.iloc[:, 2].values
y = data.iloc[:, 3].values

# Add ones for intercept (theta0)
x1 = np.c_[np.ones(x1.shape[0]), x1]
x2 = np.c_[np.ones(x2.shape[0]), x2]
x3 = np.c_[np.ones(x3.shape[0]), x3]

def gradientDescent(x, y, learnRate, iterations):
    m = len(y)  # Number of samples
    theta = np.zeros(x.shape[1])  # Initialize theta to zeros
    lossHistory = []  # To store the cost/loss at each iteration

    for i in range(iterations):
        # Predict using current theta
        prediction = np.dot(x, theta)
        
        # Compute the loss (Mean Squared Error)
        loss = (1/(2*m)) * np.sum((prediction - y)**2)
        lossHistory.append(loss)
        
        # Update theta using the gradient
        gradient = (1/m) * np.dot(x.T, (prediction - y))
        theta -= learnRate * gradient

    return theta, lossHistory

# Settings
iterations = 1000  # Number of iterations for gradient descent
learnRate = 0.01  # You can experiment with different values

# Train for x1
theta_x1, loss_x1 = gradientDescent(x1, y, learnRate, iterations)

# Train for x2
theta_x2, loss_x2 = gradientDescent(x2, y, learnRate, iterations)

# Train for x3
theta_x3, loss_x3 = gradientDescent(x3, y, learnRate, iterations)

# Print the final models (theta values)
print(f"Model for x1: y = {theta_x1[0]:.4f} + {theta_x1[1]:.4f}*x1")
print(f"Model for x2: y = {theta_x2[0]:.4f} + {theta_x2[1]:.4f}*x2")
print(f"Model for x3: y = {theta_x3[0]:.4f} + {theta_x3[1]:.4f}*x3")

# Function to plot the regression model and loss
def plot_results(x, y, theta, loss, feature_name):
    plt.figure(figsize=(14,5))

    # Plot regression line
    plt.subplot(1, 2, 1)
    plt.scatter(x[:, 1], y, color='green', label='Data')
    plt.plot(x[:, 1], np.dot(x, theta), color='red', label='Regression line')
    plt.title(f'Regression Line for {feature_name}')
    plt.xlabel(f'{feature_name}')
    plt.ylabel('Y')
    plt.legend()

    # Plot loss over iterations
    plt.subplot(1, 2, 2)
    plt.plot(range(len(loss)), loss, color='blue')
    plt.title(f'Loss over Iterations for {feature_name}')
    plt.xlabel('Iterations')
    plt.ylabel('Loss')
    
    plt.tight_layout()
    plt.show()

# Plot for x1
plot_results(x1, y, theta_x1, loss_x1, 'x1')

# Plot for x2
plot_results(x2, y, theta_x2, loss_x2, 'x2')

# Plot for x3
plot_results(x3, y, theta_x3, loss_x3, 'x3')