from typing import Callable
from math import tan

def calcular_soma(
    funcao: Callable[[float], float],
    indice: int
) -> float:
    
    soma = 0
    
    for k in range(1, indice + 1):
        soma += funcao(
            k / float(indice * indice)    
        )
        
    return soma
    
    
for n in range(1, 1001, 10):
    print(
        calcular_soma(
            lambda x: tan(x),
            n
        )    
    )