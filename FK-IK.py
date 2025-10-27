import numpy as np
import matplotlib.pyplot as plt

L1 = float(input("Masukkan panjang Temur: "))
L2 = float(input("Masukkan panjang Tibia: "))
theta1 = float(input("Masukkan sudut servo 1 (derajat): "))
theta2 = float(input("Masukkan sudut servo 2 (derajat): "))

t1 = np.radians(theta1)
t2 = np.radians(theta2)

x = L1 * np.cos(t1) + L2 * np.cos(t1 + t2)
y = L1 * np.sin(t1) + L2 * np.sin(t1 + t2)

xt = [0, L1 * np.cos(t1), x]
yt = [0, L1 * np.sin(t1), y]

plt.figure()
plt.plot(xt, yt, '-o', linewidth=3)
plt.title("Forward Kinematics 2 Robotic Arm")
plt.xlabel("Sumbu X")
plt.ylabel("Sumbu Y")
plt.grid(True)
plt.axis('equal')
plt.show()
