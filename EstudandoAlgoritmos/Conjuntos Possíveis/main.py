from random import randint

"""
Vamos criar um set de números aleatorios, dado que não podemos repetir um único.

Vamos montar uma forma de montar conjunto de elementos, todos os possíveis.
Note que não podemos ter conjunto repetivos, então o que vamos fazer é usar
outro set, entendeu?

"""

def montando_lista_aleatoria(quantidade):
    
    numeros_nao_duplicados = set()
    
    while len(numeros_nao_duplicados) != quantidade:
        numeros_nao_duplicados.add(randint(0, 20))
        
    return list(numeros_nao_duplicados)


# Desistimos do que iamos fazer, pois eu acho que é melhor entendermos o que isso significa
def solucionando(lista_de_numeros):
    """
    Você deve pensar no conjunto como uma arvore, pense nisso! 
    Onde o backtracking vai para um lado e dps volta para ir para o outro lado, compreeende?
    """
    
    tam = len(lista_de_numeros)
    path = []
    res = []
    
    def backtrack(indice):
        # print(f'Vou executar o backtrack no lugar {indice}')
        
        if indice == tam:
            # print('Cheguei no final da linha')
            return res.append(path[:])
        
        prox_numero = lista_de_numeros[indice]
        
        # Caso não formos usar esse número para criar nosso conjunto
        # print(f"Não vou usar o numero do indice {indice}")
        backtrack(indice + 1)  # Vamos para o proximo numeros
        
        # print(f'Vou usar o numero do indice {indice}')
        # Caso formos usar
        path.append(prox_numero)
        """
        É aqui que acontece a mágica. Note que ele adiciona algo no path aqui e inicia outro backtrack
        Sendo assim, outrobacktrack se inicia com um novo path, compreende?
        E veja que logo dps apagamos o numero do path cara. Justamente porque já usamos ele.
        """
        # E ai puxamos de novo
        backtrack(indice + 1)
        path.pop()
        
        return res
    
    return backtrack(0)  # Afinal, devemos iniciar pelo 0
    



if __name__ == '__main__':
    # Esse programa tem uma complexidade maior que O(n!), dado que estamos vendo todas 
    # as combinações possíveis.
    print(solucionando([1,2,3]))





