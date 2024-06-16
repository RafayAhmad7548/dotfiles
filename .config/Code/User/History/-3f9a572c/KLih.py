import numpy as np
import matplotlib.pyplot as plt

# Define the Langarian function
def langarian(x1, x2, x3, lmbda):
    c1, c2, c3 = 10, 20, 25
    m1, m2, m3 = 10, 20, 25
    return (c1*x1 + c2*x2 + c3*x3) - lmbda*(m1*x1 + m2*x2 + m3*x3 - 100)

# Define the constraint equation
def constraint(x1, x2):
    m1, m2, m3 = 10, 20, 25
    return (100 - m1*x1 - m2*x2) / m3

# Generate data for plotting
x1_range = np.linspace(0, 10, 100)
x2_range = np.linspace(0, 10, 100)
X1, X2 = np.meshgrid(x1_range, x2_range)
Z = langarian(X1, X2, constraint(X1, X2), 1)

# Plot the Langarian function
fig = plt.figure(figsize=(10, 6))
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X1, X2, Z, cmap='viridis', alpha=0.8)
ax.set_xlabel('x1')
ax.set_ylabel('x2')
ax.set_zlabel('L(x1, x2, x3)')

# Plot the constraint equation
x3_const = constraint(X1, X2)
ax.plot_wireframe(X1, X2, x3_const, color='r', linewidth=1, linestyle='--', alpha=0.6)
ax.scatter(0, 5, 0, color='r', marker='o')  # Highlight the optimal point
ax.text(0, 5, 0, "Optimal Point\n(0, 5, 0)", color='r')
ax.set_title('Langarian Function and Constraint Equation')
plt.show()