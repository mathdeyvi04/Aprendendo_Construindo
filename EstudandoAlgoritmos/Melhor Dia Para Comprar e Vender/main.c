#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int interacoes = 0;

void apresentacao(int lista[], int quantidade){
    for(int i = 0; i < quantidade; i = i + 1){
        printf("%d,", lista[i]);
    }
}


void apropriacao(int lista[], int a, int b, int c){
    lista[0] = a;
    lista[1] = b;
    lista[2] = c;
}


int* montando_lista_aleatoria(int quantidade, int maximo){
    
    int* sanha = (int*) malloc( quantidade * sizeof(int) );
    
    for(int i = 0; i < quantidade; i = i + 1){
        sanha[i] = (rand() % maximo) + 1;
    }
    
    return sanha;
}


int* algoritmo_errado(int lista[], int quantidade){
    
    int* resultado = (int*) malloc( 3 * sizeof(int) );
    apropriacao(resultado, 0, 0, 0);
    
    // Varrendo a lista a fim de obter o dia que tem o menor valor.
    int dia_que_comprei = 0;
    int menor = 100000000;
    for(int i = 0; i < quantidade; i = i + 1){
        interacoes++;
        
        // Obviamente, vamos comprar no dia que estiver mais barato.
        interacoes++;
        if (lista[i] < menor){
            menor = lista[i];
            dia_que_comprei = i;
        }
        
    }
    
    int maior = 0;
    int dia_que_vendi = 0;
    // Afinal, não é possível vender nos dias anteriores ao que foi comprado.
    for(int j = dia_que_comprei + 1; j < quantidade; j = j + 1){
        interacoes++;
        
        interacoes++;
        if (lista[j] > maior){
            maior = lista[j];
            dia_que_vendi = j;
        }
        
    }
    
    apropriacao( resultado, maior - menor, dia_que_comprei, dia_que_vendi);
    
    return resultado;
}


int* algoritmo_certo(int lista[], int quantidade){
    
    int* resultado = (int*) malloc( 3 * sizeof(int) );
    apropriacao(resultado, 0, 0, 0);
    
    /* Antes, haviamos procurado os dias com menor e maior valores. Mas pense:
    E se o dia que vier com menor valor for o último? Não vamos vender em momento algum.
    O que está obviamente errado.
    */
    
    // Dessa vez, vamos nos basear somente no lucro maximo
    for(int dia_que_comprei = 0; dia_que_comprei < quantidade; dia_que_comprei++){
        interacoes++;
        
        // Dessa forma, vamos ter um O(n^2) ?
        for(int dia_que_vendi = dia_que_comprei + 1; dia_que_vendi < quantidade; dia_que_vendi++){
            interacoes++;
            
            // Sendo assim, vamos fazer as verificacoes.
            // Nessa configuração,
            int lucro = lista[ dia_que_vendi ] - lista[ dia_que_comprei ];
            
            interacoes++;
            if (lucro > resultado[0]){
                apropriacao( resultado, lucro, dia_que_comprei, dia_que_vendi );
            }
            
        }
        
    }
    
    return resultado;
}



void testando_individualmente(int* (*funcao)(int*, int), int quantidade, int maximo){
    printf("A lista de ações: ");
    int* lista_de_acoes = montando_lista_aleatoria(quantidade, maximo);
    apresentacao(lista_de_acoes, quantidade);
    
    int* resultado = funcao(lista_de_acoes, quantidade);
    
    printf("\nResultado:\n Lucro Obtido: %d\n Comprar -> Dia %d\n Vender -> Dia %d", resultado[0], resultado[1], resultado[2]);
    
    printf("\nTotal de %d interações.", interacoes);
    
    free(resultado);
    free(lista_de_acoes);
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
    Dados uma lista de elementos, [x0, x1, x2, ...], onde cada elemento representa
    o valor de uma ação.
    
    Devemos obter o index do dia que devemos comprar e do dia que devemos vender, 
    a fim de obter o maior lucro possível.
    
    Lembre-se que não da para comprar em um dia x e vender em um dia y tal que y < x.
    Em outras palavras, não da para voltar no tempo.
    
    */
    
    srand(time(NULL));
    
    //testando_individualmente( algoritmo, 10, 100 );
    
    testando_coletivo( algoritmo_certo , 100, 100, 100);
    
    /*
    
    Observe o ÁPICE DA PROGRAMAÇÃO:
    
    No algoritmo errado, nós temos uma complexidade O(n). Ponto. Pois apenas varremos
    a lista de uma vez. 
    Entretanto, ele está errado. Note que ele busca o menor valor na lista e procura o 
    maior valor na lista que sobra ao retirarmos os elementos anteriores.
    Mas e se o menor valor estiver exatamente no último local? Não vai sobrar uma 
    lista para se obter o maior valor possível. Compreende?
    
    Devido à esse erro, precisamos reestruturar o código e de fato conseguimos. 
    Entretanto, este possui complexidade O(n^2) e escala muito conforme aumentamos.
    
    Note então que o algoritmo 'errado' só resultado em um erro em um caso muito especifico.
    Então a melhor solução seria uma junção desses.
    
    
    
    
    
    
    
    
    */
    
    
    return 0;
}
