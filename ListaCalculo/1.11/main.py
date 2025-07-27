# Como queremos calcular valores de Somas de Séries
from math import sqrt, pow

def function(n: int, m: int) -> float:
    """
        1/sqrt(n^2+m^2)
    """
    return 1 / sqrt(n * n + m)

interacoes = 0
somas = []
for i in range(0, 5):
    interacoes += 1
    n = int(pow(10, i))
    
    soma = 0
    
    for j in range(1, n+1):
        interacoes += 1
        
        soma += function( n , j )
        
    print(f"Para n = {n}, obtemos: {soma}")
    
    somas.append((n, soma))

with open("valores.txt", "w") as base:
    for valor_n, soma_total in somas:
        base.write(f"{valor_n}\t{soma_total}\n")
    
    
print(f"Total de {interacoes} interacoes")




