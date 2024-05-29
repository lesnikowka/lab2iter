from matplotlib import pyplot as plt
import numpy as np
import sys
import os    

x = []
y = []
z = []

m = 0
n = 0

def load_data():
    global m, n
    dir = sys.argv[1]
    file = open(dir)
    data = file.read()
    list_data = list(data.split())
    m = int(list_data[0])
    n = int(list_data[1])

    for i in range(m):
        y_ = []
        for j in range(n):
            y_.append(float(list_data[i * n + j + 2]))
        z.append(y_)

load_data()

z = np.array(z)
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

#print(x)
#print(y)
#print(z)

#print(x.shape)
#print(y.shape)
#print(z.shape)

#print(x)
#print()
#print(y)
#print()
#print(z)
#print()

#print(z)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(y, x, z, cmap='inferno')
plt.show()

#fig.savefig("plane.png")