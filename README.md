# FISI2029-201920
Laboratorio Métodos Computacionales - Segundo Semestre 2019
[![Binder](http://mybinder.org/badge_logo.svg)](http://beta.mybinder.org/v2/gh/ComputoCienciasUniandes/FISI2029-201920/master)

### Respuesta a las preguntas

1. Con lambda igual a 1, se obtiene la ecuación para un oscilador armónico.

2. Se esperan resultados de las formas de seno y cosenos.

3. Se encuentra dentro del archivo .cpp y guardados en euler.dat. 

4. La función tiene un comportamiento similar al del seno, sin embargo, la amplitud va aumentando a medida que el tiempo avanza, lo cual no es congruente con un modelo de oscilador armónico.

5. Con el método de Rk4, las amplitudes de la gráfica de posición contra el tiempo permanecen constantes, y la variación de la velocidad debe ser ciclica, regresar siempre a los mismos valores. Es un comportamiento sinoidal perfecto, mientras que con el método de Euler ambas amplitudes varian, dando como resultado una mala e incongruente solución a la ODE, ya que la velocidad disminuye hasta llegar a 0 mientras que la posicion incrementa al infinito. Por lo tanto, el método de Rk4 es mucho más preciso que el método de Euler.

6. Se espera obtener un comportamiento invariante por parte de ambas gráficas, ya que este es el comportamiento para un oscilador armónico. Es decir, para la gráfica de posicion vs tiempo la gráfica debe tener una amplitud constante y repetirse infinitamente en el tiempo, y para la gráfica de velocidad vs posicion, se debe tener una figura simetrica y cerrada, con un radio constante, ya que la velocidad debe ser ciclica en un oscilador armonico. Todo esto lo cumple el método de Rk4, demostrando que es muy preciso, mientras que el método de euler no cumple ninguna de las dos condiciones, la posición incremente y se sale de lo que se esperaria de un armonico, ya que debería siempre hacer un recorrido ciclico y recorrer las mismas distancias, y la velocidad disminuye, creando una espiral.

7. Al agregar una fuerza de fricción espero obtener un comportamiento de oscilador armónico amortiguado, que con el pasar del tiempo la posición llegará a ser cero, debido a que su velocidad disminuye hasta llegar a 0 por efecto de la friccion. Esto se evidencia en las graficas de OsciladorRk4Friccion donde la posicion disminuye con el tiempo, y la velocidad disminuye hasta llegar a 0 en forma de espira.

8. Al incrementar el valor de lambda se pierde la posibilidad de ser resuelta por estos métodos, ya que son para ODE, por lo cuál los datos obtenidos con lambdas mayores a 1 no son congruentes y no deberían ser soluciones reales.
