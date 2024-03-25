""""Desarrollar un algoritmo y luego codificarlo en Python que permita
ingresar números enteros mayores a cero. Calcular y mostrar el promedio
de los números pares y la cantidad de números divisibles por 3. Además,
deberán compartir en el muro colaborativo el código y ver las distintas resoluciones."""


def cargar(arreglo):
    """Carga en un arrelgo los numeros ingresados"""

    num = validar()

    while num != 0:
        arreglo.append(num)
        num = validar()


def validar():
    """Valida y retorna el numero entero mayor a 0"""

    num = int(input("Ingresar numero entero mayor a 0: "))
    while num < 0:
        print("El numero entero debe ser mayor a 0")
        num = int(input("Ingresar numero entero mayor a 0: "))
    return num


def calc_prom_pares(arreglo):
    """Calcula y retorna el promedio de los numeros pares"""

    cont = 0
    acum = 0
    for i in range(len(arreglo)):
        if arreglo[i] % 2 == 0:
            cont += 1
            acum = acum + arreglo[i]

    return acum / cont


def calc_divisibles(arreglo):
    """Calcula y retorna la cantidad de numeros divisibles por 3"""

    cont = 0
    for i in range(len(arreglo)):
        if arreglo[i] % 3 == 0:
            cont += 1

    return cont


# Programa Principal

arreglo_enteros = []

cargar(arreglo_enteros)

if len(arreglo_enteros) > 0:
    print(f"El promedio de numeros pares es {calc_prom_pares(arreglo_enteros)}")
    print(
        f"La cantidad de numeros divisibles por 3 es {calc_divisibles(arreglo_enteros)}"
    )
