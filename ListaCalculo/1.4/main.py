from math import log


def calcular_soma(
    n: int
) -> float:
    
    soma = 0
    for k in range(1, n + 1):
        soma += 1.0 / k
    
    return soma

for indice in range(2, 1001, 10):
    
    print(
        f"{calcular_soma(indice) - log(indice)}"    
    )
    
    