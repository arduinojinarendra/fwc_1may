import numpy as np
import mpmath as mp
import math as ma
import matplotlib.pyplot as plt
from numpy import linalg as LA


#if using termux
import subprocess
import shlex
#end if



def slope(m):
    m1 = np.array([1, 2])  # direction vector of 1st line
    m2 = np.array([1, m])  # direction 2nd line
    cos_theta = np.dot(m1, m2) / (np.linalg.norm(m1) * np.linalg.norm(m2))
    return cos_theta


m1 = 2  # slope of the 1st line
theta = np.deg2rad(60)  # Angle


m2_1 = (-16 + np.sqrt(16 ** 2 - 4 * 11 * (-1))) / (2 * 11)  # slope of the 2nd line
m2_2 = (-16 - np.sqrt(16 ** 2 - 4 * 11 * (-1))) / (2 * 11)

print("Slope of the first line: ", m1)  # results
print("Slope of the second line (Case 1): ", m2_1)
print("Slope of the second line (Case 2): ", m2_2)


def line_dir_pt(m, P, k1, k2):
    length = 10
    dimensions = P.shape[0]
    x_AB = np.zeros((dimensions, length))
    lam_1 = np.linspace(k1, k2, length)
    for i in range(length):
        temp1 = P + lam_1[i] * m
        x_AB[:, i] = temp1.T
    return x_AB


# Input parameters
P = np.array([2, 3])

# Generating the lines
k1 = -10
k2 = 6
x_m1P = line_dir_pt(np.array([1, m1]), P, k1, k2)
x_m2_1P = line_dir_pt(np.array([1, m2_1]), P, k1, k2)
x_m2_2P = line_dir_pt(np.array([1, m2_2]), P, k1, k2)

# Plotting the lines
plt.plot(x_m1P[0, :], x_m1P[1, :], label='Line 1: 2x - y + 1 = 0')
plt.plot(x_m2_1P[0, :], x_m2_1P[1, :], label='Line 2 (Case 1): 5√3-8x + 11y = 49 - 10√3')
plt.plot(x_m2_2P[0, :], x_m2_2P[1, :], label='Line 2 (Case 2): 5√3+8x + 11y = 49 + 10√3')

# Labeling the coordinates
#Labeling the coordinates
tri_coords = np.vstack((P,)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['P']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(0,10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center


plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend()
plt.grid(True)
plt.title('Line Equations')
plt.xlim(-10, 10)
plt.ylim(-10, 10)
plt.gca().set_aspect('equal', adjustable='box')
plt.show()



