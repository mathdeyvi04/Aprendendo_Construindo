#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int interacoes = 0;

void apresentacao(int lista[], int quant){
    for(int i = 0; i < quant; i++){
        if (i == 0){
            printf("[ %d,", lista[i]);
        }
        else{
            if (i == (quant - 1)){
                printf(" %d ]", lista[i]);
            }
            else{
                printf(" %d,", lista[i]);
            }
        }
    }
}


int* montando_lista(int quantidade){
    
    int gerando_aleatorio(int maior, int menor){
        int a = maior - menor + 1;
        int b = menor;
        
        return (rand() % a) + b;
    }
    
    int nao_esta_presente(int lista[], int tam, int alvo){
        for(int j = 0; j < tam; j++){
            if(lista[j] == alvo){
                return 0;
            }
        }
        return 1;
    }
    
    int* lista = (int*) malloc( quantidade * sizeof(int) );
    
    // Necessariamente deve haver apenas um duplicado
    int index = 0;
    int posicao_duplicata = gerando_aleatorio(quantidade - 1, 2);
    while (index != quantidade){
        
        if (index == posicao_duplicata){
            
            lista[index] = lista[gerando_aleatorio(index - 1, 0)];
        }
        else{
            int novo = gerando_aleatorio(2 * quantidade, 0);
            
            if (nao_esta_presente(lista, index, novo)){
                
                lista[index] = novo;
            }
            else{
                
                index--;
            }
            
        }
        
        index++;
    }
    
    
    
    
    
    return lista;
}


void apropria(int numeros[], int a, int b, int c){
    numeros[0] = a;
    numeros[1] = b;
    numeros[2] = c;
}


///////////////////////////////////////////////////////////////


int* algoritmo_0(int lista[], int quantidade){
    
    int nao_esta_presente(int numeros[], int tam, int alvo){
        for(int j = 0; j < tam; j++){
            interacoes++;
            
            interacoes++;
            if (numeros[j] == alvo){
                return 0;
            }
        }
        
        return 1;
    }
    
    int* obtendo_ordenada(int lista_nao_[], int quant){
        
        // Separando mais memória para criar outra lista 
        int* lista_nao_ordenada = (int*) malloc( quant * sizeof(int) );
        for(int i = 0; i < quant; i++){
            interacoes++;
            lista_nao_ordenada[i] = lista_nao_[i];
        }
        
        int* ordenada = (int*) malloc(quant * sizeof(int));
        
        // Vamos construir ela 
        int index_na_ordenada = 0;
        while (index_na_ordenada != quant){
            interacoes++;
            
            int maior = -1;
            int index_do_maior = 0;
            interacoes++;
            for(int i = 0; i < quant; i++){
                interacoes++;
                
                interacoes++;
                if (lista_nao_ordenada[i] > maior){
                    maior = lista_nao_ordenada[i];
                    index_do_maior = i;
                }
            }
            
            ordenada[index_na_ordenada] = maior;
            lista_nao_ordenada[index_do_maior] = -1;
            
            index_na_ordenada++;
        }
        
        free(lista_nao_ordenada);
        
        return ordenada;
    }
    
    int* obtendo_indexs_duplicados(int alvo){
        int* posicoes = (int*) malloc(2 * sizeof(int) );
        
        int p = 0;
        for(int i = 0; i < quantidade; i++){
            interacoes++;
            
            interacoes++;
            if (lista[i] == alvo){
                 
                posicoes[p] = i;
                p++;
                
                interacoes++;
                if (p == 2){
                    break;
                }
            }
        }
        
        return posicoes;
    }
    
    /////////////////////////////////////////////////////////////////////////
    
    int* resultado = (int*) malloc( 3 * sizeof(int) );
    
    // Devemos criar uma nova lista ordenada a partir dessa entrada
    int* lista_ordenada = obtendo_ordenada(lista, quantidade);

    // Daí, sabemos com certeza é que o elemento duplicado estará ao lado do outro
    for(int i = 0; i < quantidade; i++){
        interacoes++;
        
        interacoes++;
        if (i != 0 && (lista_ordenada[i] == lista_ordenada[i - 1])){
            // Achamos o duplicado.
            
            // Obtendo os indices deles na lista anterior.
            int* index_duplicados = obtendo_indexs_duplicados(lista_ordenada[i]);
            
            apropria(resultado, lista_ordenada[i], index_duplicados[0], index_duplicados[1]);
            
            break;
        }
    }
    
    free(lista_ordenada);
    
    return resultado;
}


int* algoritmo_1(int lista[], int quantidade){
    
    int* resultado = (int*) malloc( 3 * sizeof(int) );
    
    
    for(int i = 0; i < quantidade; i++){
        interacoes++;
        
        for(int j = i; j < quantidade; j++){
            interacoes++;
            
            interacoes++;
            if( (lista[i] == lista[j]) && (i != j) ){
                apropria(resultado, lista[i], i, j);
                
                return resultado;
            }
        }
    }
    
    return NULL;
}


int* algoritmo_2(int lista[], int quantidade){
    
    int* resultado = (int*) malloc( 3 * sizeof(int) );
    
    // Vamos usar o super algoritmo do coelho e da tartaruga, COMO ALGUEM PENSOU NISSO CARA
    int tartaruga = 0;
    int coelho = 0;
    int index_tartaruga = 0;
    int index_coelho = 0;
    
    while(tartaruga != 20){
        interacoes++;
        
        /*
        Se liga nessa porra, queremos que o coelho e a tartaruga percorram valores em um intervalo.
        Logo, é inteligente que usemos o %, mod, para fazer esse intervalo cara, INSANO.
        Vamos eliminar a necessidade de outro if e outras interações.
        
        Queremos que:
        
        A tartaruga percorra apenas por 0, ..., quantidade - 1.
        Logo, vamos ter um index infinito no qual vamos retornar a posicao da tartaruga
        como sendo apenas  = index % quantidade.
        
        O coelho deve percorrer apenas pelos mesmos locais, mas de forma a ficar
        pulando de dois em dois.
        */
        
        printf("\ntartaruga está na pos %d e vale %d", index_tartaruga, lista[index_tartaruga]);
        printf("\ncoelho está na pos %d e vale %d\n", index_coelho, lista[index_coelho]);
        
        int se_apontam_ao_mesmo = lista[index_tartaruga] == lista[index_coelho];
        int se_posicoes_diferentes = index_tartaruga != index_coelho;
        
        interacoes++;
        if (se_posicoes_diferentes && se_apontam_ao_mesmo){
            apropria(resultado, lista[index_tartaruga], index_tartaruga, index_coelho);
            
            return resultado;
        }
        
        
        tartaruga = tartaruga + 1;
        coelho = coelho + 2;
        
        index_coelho = coelho % quantidade;
        index_tartaruga = tartaruga % quantidade;
    }
    
    // SIMPLISMENTE INSANO, mas ainda há um erro. Basicamente, esse algoirtmo tem a chance de 
    // entrar em loop e nunca obter o resultado correto.

    return resultado;
}


void testando_individualmente(int* (*funcao)(int*, int), int quant){
    
    int* lista = montando_lista(quant);
    printf(" A lista é: ");
    apresentacao(lista, quant);
    
    int* resultado = funcao(lista, quant);
    printf("\n O número duplicado é %d.\n Está na posicao %d e na posicao %d.", resultado[0], resultado[1], resultado[2]);
    
    printf("\n\n Total de %d interações.", interacoes);
    
    free(lista);
    free(resultado);
}


void testando_coletivamente(int* (*funcao)(int*, int), int quant, int vezes){
    
    for(int p = 0; p < vezes; p++){
        
        interacoes = 0;
        
        printf("\nTeste Numero %d\n", p + 1);
        
        testando_individualmente(funcao, quant);
        
        printf("\n\n");
        
    }
    
    
    
}


int main()
{
    /*
    Dado uma lista de números aleatórios e que contém um elemento duplicado, obtenha o elemento duplicado
    */
    srand(time(NULL));
    
    //testando_coletivamente(algoritmo_2, 10, 5);
    
    testando_individualmente(algoritmo_2, 10);
    
    /*
    Analise a cada uma das soluções e veja com seus próprios olhos.
    
    Como pior, o algoritmo_0 possui o (2 * n^2 ) e acumula MUITA memória, absurdo.
    
    Note que no algoritmo_1 a solução pode ser muito boa, por pura sorte, mas no pior caso
    o crescimento é muito alto, com O(n^2).
    
    Todos até agora tendem a ser O(n^2), pois vamos a lista em cada elemento, 
    ou temos algoritmos de sorteamento.
    
    // A ideia do algoritmo_2 é brilhante, mas incerta.
    
    */

    return 0;
}


