from matplotlib import pyplot as plt
import numpy as np
import sys
import os    

x = []
y = []

m = 0
n = 0

dir = "planeVals"
dir2 = "planeValsTrue"
dir3 = "planeValsSub"

def load_data(dir_):
    global m, n
    #dir = sys.argv[1]

    z = []
    
    file = open(dir_)
    data = file.read()
    list_data = list(data.split())
    m = int(list_data[0])
    n = int(list_data[1])

    for i in range(m):
        y_ = []
        for j in range(n):
            y_.append(float(list_data[i * n + j + 2]))
        z.append(y_)

    return z

z1 = np.array(load_data(dir))
z2 = np.array(load_data(dir2))
z3 = np.array(load_data(dir3))

y = np.linspace(0, 2, m)
x = np.linspace(0, 1, n)



y = [_y for _y in y]
x = [_x for _x in x]

y = [y] * n 
x = [x] * m

new_y = []

for i in range(m):
    y_ = []
    for j in range(n):
        y_.append(y[j][i])
    new_y.append(y_)

y = new_y


y = np.array(y)
x = np.array(x)

fig = plt.figure()
ax = fig.add_subplot(131, projection='3d')
ax.plot_surface(y, x, z1, cmap='inferno')
ax2 = fig.add_subplot(132, projection='3d')
ax2.plot_surface(y, x, z2, cmap='inferno')
ax3 = fig.add_subplot(133, projection='3d')
ax3.plot_surface(y, x, z3, cmap='inferno')
plt.show()

fig.savefig("plane.png")