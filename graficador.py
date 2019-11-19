import numpy as np
import matplotlib.pylab as plt

euler = np.loadtxt("euler.dat")
eulert = euler[:,0]
eulery = euler[:,1]
eulervy = euler[:,2]

plt.figure(1)
plt.figure(figsize=(10,4))
##Para el metodo de euler.
plt.subplot(1,2,1)
plt.plot(eulert,eulery)
plt.grid()
plt.xlabel("Tiempo(s)")
plt.ylabel("Posicion(m)")
plt.title("Oscilador armonico, Posicion vs Tiempo")

plt.subplot(1,2,2)
plt.plot(eulery,eulervy)
plt.grid()
plt.xlabel("Posicion(m)")
plt.ylabel("Velocidad(m/s)")
plt.title("Oscilador armonico, velocidad vs tiempo")
plt.savefig("OsciladorEuler.png")

data = np.loadtxt("datos.dat")
tiempo = data[:,0]
y = data[:,1]
vy = data[:,2]
## Para el método de Rk4.
plt.figure(2)
plt.figure(figsize=(10,4))
plt.subplot(1,2,1)
plt.plot(tiempo,y)
plt.grid()
plt.xlabel("Tiempo(s)")
plt.ylabel("Posicion(m)")
plt.title("Oscilador armonico, Posicion vs Tiempo")

plt.subplot(1,2,2)
plt.plot(y,vy)
plt.grid()
plt.xlabel("Posicion(m)")
plt.ylabel("Velocidad(m/s)")
plt.title("Oscilador armonico, Velocidad vs Tiempo")

plt.savefig("OsciladorRk4.png")

## Para el Rk4 con friccion.
yfriccion = data[:,3]
vyfriccion = data[:,4]
plt.figure(3)
plt.figure(figsize=(10,4))

plt.subplot(1,2,1)
plt.plot(tiempo,yfriccion)
plt.xlabel("Tiempo(s)")
plt.ylabel("Posicion(m)")
plt.grid()
plt.title("Oscilador armonico, Posicion vs Tiempo")

plt.subplot(1,2,2)
plt.plot(yfriccion,vyfriccion)
plt.grid()
plt.xlabel("Posicion(m)")
plt.ylabel("Velocidad(m/s)")
plt.title("Oscilador armonico, Velocidad vs Tiempo")

plt.savefig("OsciladorRk4Friccion.png")