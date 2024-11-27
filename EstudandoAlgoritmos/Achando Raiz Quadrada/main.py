
def obtendo_raiz_quadrada(numero_desejado):
    """
    Escolhemos fazer em python para evitar a forte tipagem que existe em C.
    
    Reconstruimos o código para aceitar modificações de precisão e para aceitar 
    numeros que não quadrados perfeitos.
    
    """
    
    left = 1 
    right = numero_desejado
    precisao = 0.0001
    
    while left <= right:
        
        meio = (left + right) / 2
        print(f'Achei o {meio}')
        
        valor_ao_quadrado = meio * meio
        
        if (numero_desejado - 100*precisao) < valor_ao_quadrado < (numero_desejado + 100*precisao):
            return meio
        else:
            
            print("Notei que não é a raiz quadrada")
            
            if valor_ao_quadrado > numero_desejado:
                right = meio - precisao
            else:
                left = meio + precisao
    
    
    return -1


if __name__ == "__main__":
    numero = 2
    
    print(f"A raiz quadrada é: {obtendo_raiz_quadrada(numero)}")

