import numpy as np 
import matplotlib.pyplot as plt
import os


os.system("g++ incomplete.cpp")
os.system("./a.out")

kuta = np.loadtxt("rk4.dat")
euler = np.loadtxt("euler.dat")
rana = np.loadtxt("leapfrog.dat")


plt.figure(figsize=(50,30))
fig, axs = plt.subplots(3,3)

#euler vertical

axs[0, 0].plot(euler[:,0],euler[:,1])
axs[0, 0].set_title('Euler')
axs[0, 0].set_ylabel('Position')
axs[0, 0].set_xlim([0,4*np.pi])
axs[0, 0].set_ylim([-1.5,1.5])



axs[1, 0].plot(euler[:,0],euler[:,2])
axs[1, 0].set_title('Time')
axs[1, 0].set_ylabel('Velocity')
axs[1, 0].set_xlim([0,4*np.pi])
axs[1, 0].set_ylim([-1.5,1.5])


axs[2, 0].plot(euler[:,1],euler[:,2])
axs[2, 0].set_title('Time')
axs[2, 0].set_ylabel('Velocity')
axs[2, 0].set_xlabel('Position')
axs[2, 0].set_xlim([-2,2])
axs[2, 0].set_ylim([-2,2])

#rk vertical

axs[0, 1].plot(kuta[:,0],kuta[:,1])
axs[0, 1].set_title('RK')
axs[0, 1].set_xlim([0,4*np.pi])
axs[0, 1].set_ylim([-1.5,1.5])

axs[1, 1].plot(kuta[:,0],kuta[:,2])
axs[1, 1].set_title('Time')
axs[1, 1].set_xlim([0,4*np.pi])
axs[1, 1].set_ylim([-1.5,1.5])

axs[2, 1].plot(kuta[:,1],kuta[:,2])
axs[2, 1].set_title('Time')
axs[2, 1].set_xlabel('Position')
axs[2, 1].set_xlim([-2,2])
axs[2, 1].set_ylim([-2,2])

#leapfroc vertical
axs[0, 2].plot(rana[:,0],rana[:,1])
axs[0, 2].set_title('Leap Frog')
axs[0, 2].set_xlim([0,4*np.pi])
axs[0, 2].set_ylim([-1.5,1.5])

axs[1, 2].plot(rana[:,0],rana[:,2])
axs[1, 2].set_title('Time')
axs[1, 2].set_xlim([0,4*np.pi])
axs[1, 2].set_ylim([-1.5,1.5])

axs[2, 2].plot(rana[:,1],rana[:,2])
axs[2, 2].set_title('Time')
axs[2, 2].set_xlabel('Position')
axs[2, 2].set_xlim([-2,2])
axs[2, 2].set_ylim([-2,2])

plt.savefig("graficas.png")




