import numpy as np
import matplotlib.pyplot as plt

def slope(m):
    m1 = np.array([1, 2])  # direction vector of 1st line
    m2 = np.array([1, m])  # direction 2nd line
    cos_theta = np.dot(m1, m2) / (np.linalg.norm(m1) * np.linalg.norm(m2))
    return cos_theta


m1 = 2  #slp of 1st line
theta = np.deg2rad(60)  # Angle 


m2_1 = (-16 + np.sqrt(16 ** 2 - 4 * 11 * (-1))) / (2 * 11)  # slopes of lines
m2_2 = (-16 - np.sqrt(16 ** 2 - 4 * 11 * (-1))) / (2 * 11)


print("Slope of the first line: ", m1)  # results
print("Slope of the second line (Case 1): ", m2_1)
print("Slope of the second line (Case 2): ", m2_2)


A = np.array([2, 3])

def line_equation(point, slope):  # Func equation
    x = np.linspace(-10, 10, 100)
    y = slope * (x - point[0]) + point[1]
    return x, y

# Line passing through point A with slope m1
x1, y1 = line_equation(A, m1)
plt.plot(x1, y1, label='Line 1: 2x - y + 1 = 0')

# Line passing through point A with slope m2_1
x2_1, y2_1 = line_equation(A, m2_1)
plt.plot(x2_1, y2_1, label='Line 2 (Case 1): 5√3x + 11y = 49 - 10√3')


# Line passing through point A with slope m2_2
x2_2, y2_2 = line_equation(A, m2_2)
plt.plot(x2_2, y2_2, label='Line 2 (Case 2): 5√3x + 11y = 49 + 10√3')
plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend()
plt.grid(True)
plt.title('Line Equations')
plt.xlim(-10, 10)
plt.ylim(-10, 10)
plt.gca().set_aspect('equal', adjustable='box')
plt.show()
