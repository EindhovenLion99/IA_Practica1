# Practica 1: Busqueda

## Guion

# OBJETIVO

El objetivo del desarrollo de la actividad práctica es la utilización de estrategias de búsqueda como
propuesta de resolución en la determinación de la planificación de trayectorias para coches autónomos.

# DESCRIPCIÓN DEL PROBLEMA

El entorno del coche autónomo se puede suponer rectangular de dimensiones M x N y constituido por
celdas libres y ocupadas, donde el coche puede efectuar acciones de movimiento, una cada vez, desde la
casilla actual a una de las 4-vecinas (Norte, Sur, Este u Oeste) que no se encuentre ocupada. Las casillas
ocupadas corresponden a obstáculos. Las casillas libres corresponden con celdas libres de obstáculos.

El coche dispone de un vector de percepción, constituido por:

* El estado de un sensor de proximidad (SN, SO, SS, SE) por cada una de las direcciones de
movimiento, que detecta si el vecino correspondiente está ocupado por algún obstáculo
(Si=1).

El desarrollo de la práctica, consiste en:

1. Diseño de un simulador de entorno: se debe realizar un simulador de entorno que permita:
(1) Definición de celdas de dimensiones variables M x N; (2) Definir de manera cómoda la
posición de los obstáculos, de forma aleatoria y manual y (3) permitir una visualización de
la trayectoria determinada.

2. Planificación del camino usando estrategias heurísticas: Suponiendo un único coche
autónomo según el escenario definido en el apartado anterior, se deberá determinar la
trayectoria óptima partiendo desde una posición inicial hasta alcanzar una posición final.
Ambas posiciones son definidas por el usuario, en el entorno de simulación desarrollado
previamente. Se puede disponer de un mapa topológico que contenga la descripción del
entorno.

3. Evaluación Experimental: se evaluará los resultados obtenidos para la estrategia
implementada utilizando como mínimo dos funciones heurísticas diferentes y tres tipos de
tamaños diferentes de escenarios.


# ENTREGA DEL TRABAJO PRÁCTICO

Se habilitarán dos tareas virtuales en el campus virtual para subir: (1) el software de la práctica (código
fuente y ejecutable) y (2) una memoria del trabajo realizado (informe de prácticas) con una extensión
máxima de 15 páginas. El formato del fichero es pdf.

*Nota*: la fecha de entrega del código fuente y ejecutable para todo el alumnado será el domingo 15 de
noviembre. La semana siguiente (16-20 noviembre) se realizará la presentación y defensa de la misma,
junto con la entrega del informe de prácticas.

