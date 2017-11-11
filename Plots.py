import numpy as np
import matplotlib.pyplot as plt

#definiendo un array para el tiempo y asi calcular el periodo T
t=np.linspace(0,1,129)
T=t[1]-[0]
t1=t[0]
t2=1/(8*T)
t3=1/(4*T)
t4=1/(2*T)

#Para el primer caso
a=np.loadtxt("puntos.txt")
fin=a[:,2]

fig = plt.figure()
plt.subplot(221)
plt.plot(t/t1,fin)
plt.legend()
plt.xlabel("tiempo [s]")
plt.ylabel("Amplitud")

plt.subplot(222)
plt.plot(t/t2,fin)
plt.legend()
plt.xlabel("tiempo [s]")
plt.ylabel("Amplitud")

plt.subplot(223)
plt.plot(t/t3,fin)
plt.legend()
plt.xlabel("tiempo [s]")
plt.ylabel("Amplitud")

plt.subplot(224)
plt.plot(t/t4,fin)
plt.legend()
plt.xlabel("tiempo [s]")
plt.ylabel("Amplitud")
plt.savefig("Caso1.png")

#para el caso 2
b=np.loadtxt("puntos2.txt")
fin2=b[:,2]

fig = plt.figure()
plt.subplot(221)
plt.plot(t/t1,fin2)
plt.legend()
plt.xlabel("tiempo [s]")
plt.ylabel("Amplitud")

plt.subplot(222)
plt.plot(t/t2,fin2)
plt.legend()
plt.xlabel("tiempo [s]")
plt.ylabel("Amplitud")

plt.subplot(223)
plt.plot(t/t3,fin2)
plt.legend()
plt.xlabel("tiempo [s]")
plt.ylabel("Amplitud")

plt.subplot(224)
plt.plot(t/t4,fin2)
plt.legend()
plt.xlabel("tiempo [s]")
plt.ylabel("Amplitud")
plt.savefig("Caso2.png")
