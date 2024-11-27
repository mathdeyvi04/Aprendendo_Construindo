#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int interacoes = 0;

void apresentacao(int lista[], int quantidade){
    for(int i = 0; i < quantidade; i = i + 1){
        printf("%d,", lista[i]);
    }
}


int* montando_lista(int quantidade, int maximo){
    
    int* lista = (int*) malloc(quantidade * sizeof(int));
    
    for(int i = 0; i < quantidade; i++){
        int novo_numero = (rand() % maximo) + 1;
        
        lista[i] = novo_numero;
        
    }
    
    return lista;
    
}


void apropriacao(int sanhudos[], int a, int b, int c){
    sanhudos[0] = a;
    sanhudos[1] = b;
    sanhudos[2] = c;
}


int positivando(int valor){
        
    interacoes++;
    if (valor > 0){
        return valor;
    }
    else{
        return -valor;
    }
}


int menor_valor(int a, int b){
    
    interacoes++;
    if (a > b){
        return b;
    }
    else{
        return a;
    }
}


int* algoritmo_pessimo(int lista[], int quantidade){
    
    // Para guardarmos todas as informações possíveis, fique muito atento a isso.
    int* armazenamento = (int*) malloc( 3 * sizeof(int) );
    int index = 0;
    
    // Primeiro, criar uma forma de guardar as informações da lista 
    for(int i = 0; i < quantidade; i =  i + 1){
        // Para cada elemento, vamos varrer e obter outras informações
        interacoes++;
        
        for(int j = 0; j < quantidade; j++){
            // Note que vamos varrer toda a lista de novo.
            interacoes++;
            
            // Vamos guardar as informações possíveis.
            
            armazenamento[index] = menor_valor( lista[i], lista[j] ) * ( positivando( i - j ) );
            index++;
            armazenamento[index] = i;
            index++;
            armazenamento[index] = j;
            index++;
            
            // Criando mais espaço para colocar os sanhas.
            armazenamento = (int*) realloc(armazenamento, (index + 3) * sizeof(int));
            
            // Note que como varremos a lista inteira em cada elemento que estamos vendo,
            // Esse algoritmo possui O(n^2).
            
        }
        
        
    }
    
    // Devemos descobrir qual é a area dentro das possíveis.
    int* resultado = (int*) malloc( 3 * sizeof(int) );
    
    apropriacao(resultado, 0, 0, 0);
    
    // Aqui, ainda temos mais um O(n).
    for(int p = 0; p < index; p = p + 3){
        
        interacoes++;
        if (armazenamento[p] > resultado[0]){
            
            apropriacao( resultado, armazenamento[ p ], armazenamento[ p + 1 ], armazenamento[ p + 2 ] );
            
        }
        
    }
    
    free(armazenamento);
    
    return resultado;
}


int* algoritmo_melhor(int lista[], int quantidade){
    
    // Vamos sanhar
    int* resultado = (int*) malloc( 3 * sizeof(int) );
    apropriacao(resultado, 0, 0, 0);
    
    // Vamos procurar na lista de forma correta.
    
    for(int i = 0; i < quantidade; i++){
        interacoes++;
        
        // Já temos um elemento, vamos buscar o outro.
        for(int j = i + 1; j < quantidade; j++){
            interacoes++;
            
            int area = menor_valor( lista[i], lista[j] ) * ( positivando( i - j ) );
            
            interacoes++;
            if (area > resultado[0]){
                apropriacao(resultado, area, i, j);
            }
            
            
        }
        
    }
    
    return resultado;
}


void testando_individualmente(int* (*funcao)(int*, int), int quantidade, int maximo){
    // Criando nossa lista.
    
    int* lista_de_alturas = montando_lista(quantidade, maximo);
    //int lista_de_alturas[10] = {2, 3, 9, 12, 3, 13, 20, 21, 9, 10};
    printf("A lista de alturas: ");
    apresentacao(lista_de_alturas, quantidade);
    
    
    // Executando o sanha.
    
    int* resultado = funcao(lista_de_alturas, quantidade);
    printf("\nResultado: ");
    apresentacao(resultado, 3);
    
    
    printf("\nTotal de %d interações executadas.", interacoes);
    
    
    free(lista_de_alturas);
    free(resultado);
}


void testando_coletivo(int* (*funcao)(int*, int), int quantidade, int maximo, int vezes){
    
    for(int i = 0; i < vezes; i++){
        testando_individualmente(funcao, quantidade, maximo);
    
        printf("\n\n");
        interacoes = 0;
    }
}


int main()
{
    /*
    Vamos receber uma lista de n elementos representando alturas de cada pilar.
    A distância entre os indexs representam o comprimento.
    
    Daí, queremos o maior volume, no caso 2D: área.
    Na verdade, é mais interessante que retornemos as informações dos dois pilares.
    
    Vamos fazer o algoritmo ruim e outro bom.
    
    */
    
    //testando_individualmente(algoritmo_melhor, 10, 100);
    
    srand(time(NULL));

    testando_coletivo(algoritmo_melhor, 100, 200, 10);
    
    /*
    
    Nota-se que a melhor função usa menos memória e tem menos interações. 
    Apesar de que ela também escala com O(n^2).
    
    Como haviamos previsto, reduzimos em metade o valor das interações apenas com 
    essa mudança.
    
    */
    
    
    

    return 0;
}
