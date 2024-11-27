#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int interacoes = 0;

void apresentacao(int lista[], int quant){
    for(int i = 0; i != quant; i++){
        if (i == 0){
            printf("[%d, ", lista[i]);
        }
        else{
            if (i == (quant - 1)){
                printf("%d]", lista[i]);
            }
            else{
                printf("%d, ", lista[i]);
            }
        }
    }
}

int se_nao_existe(int lista[], int quant, int alvo, int devemos_considerar_interacoes){
    
    for(int i = 0; i != quant; i++){
        if (devemos_considerar_interacoes){
            interacoes = interacoes + 2;
        }
        
        if (lista[i] == alvo){
            // Afinal, existe.
            return 0;
        }
    }
    
    // Afinal, percorremos e não estava de fato
    return 1;
}

int* Criando_Lista(int quantidade){
    
    int valor_maximo = quantidade + 1;
    
    int* valores = (int*) malloc( quantidade * sizeof(int) );
    
    for(int i = 0; i < quantidade; i++){
        
        int valor = rand() % valor_maximo;
        
        if (se_nao_existe(valores, i, valor, 0)){
            valores[i] = valor;
        }
        else{
            i--;
        }
        
    }
    
    
    return valores;
}


int algoritmo_1(int lista_de_numeros[], int quantidade){
    /*
    Vamos varrer cada elemento da lista que compoem todos os números e verificar
    se eles estão na lista que nos foi dada, se não estiver é o nosso número.
    */
    
    int* Criar_Lista_Completa(int quantidade1){
        int* lista_completa = (int*) malloc( quantidade1 * sizeof(int) );
        
        for(int j = 0; j < quantidade1; j++){
            interacoes++;
            lista_completa[j] = j;
        }
        
        return lista_completa;
    }
    
    // Obtendo nossa lista completa de números.
    int* lista_completa = Criar_Lista_Completa( quantidade + 1 );
    
    // Agora, devemos fazer as comparações.
    // Vamos percorrer a grande
    for(int i = 0; i < (quantidade + 1); i++){
        interacoes++;
        
        // E verificando se eles estão dentro da lista que nos foi dada.
        interacoes++;
        if (se_nao_existe(lista_de_numeros, quantidade, lista_completa[i], 1)){
            // Como não está presente
            int numero_nao_presente = lista_completa[i];
            
            free(lista_completa);
            
            return numero_nao_presente;
        }
        
    }
    
    // Observe que devido à verificação, temos O(n^2)
    
}

int algoritmo_2(int lista_de_numeros[], int quantidade){
    /*
    Vamos basicamente construir as somas.
    */
    
    int Obtendo_Soma_Total(){
        int soma = 0;
        
        for(int i = 1; i != (quantidade + 1); i++){
            interacoes++;
            soma = soma + i;
        }
        
        return soma;
    }
    
    int Obtendo_Soma_Dada(){
        int soma = 0;
        
        for(int i = 0; i < quantidade; i++){
            interacoes++;
            soma = soma + lista_de_numeros[i];
        }
        return soma;
    }
    
    return (Obtendo_Soma_Total() - Obtendo_Soma_Dada());
    
}

int algoritmo_3(int lista_de_numeros[], int quantidade){
    /* Vamos apenas usar soma de Gauss */
    
    int soma_total = ( (quantidade) * (quantidade + 1)  ) / 2;
    
    int Obtendo_Soma_Dada(){
        int soma = 0;
        
        for(int i = 0; i < quantidade; i++){
            interacoes++;
            soma = soma + lista_de_numeros[i];
        }
        return soma;
    }
    
    
    
    return soma_total - Obtendo_Soma_Dada();
}


void testando_individualmente(int (*funcao)(int*, int), int total){
    
    int* Lista = Criando_Lista(total);
    printf("A lista de numeros ate %d ->  ", total);
    apresentacao(Lista, total);
    
    int numero_nao_presente = funcao(Lista, total);
    
    printf("\nO numero que nao esta presente e %d", numero_nao_presente);
    
    printf("\n\nTotal de Interacoes: %d", interacoes);
}

void testando_coletivo(int (*funcao)(int*, int), int total, int vezes){
    
    
    for(int m = 0; m < vezes; m = m + 1){
        printf("Teste %d\n", m + 1);
        
        testando_individualmente(funcao, total);
        
        interacoes = 0;
        
        printf("\n\n");
    }
    
}

int main()
{
    /*
    Vai nos ser dado uma lista de inteiros, de 0 até o valor n.
    Há um número faltante, o qual devemos descobrir qual é.
    */
    
    srand(time(NULL));
    
    testando_coletivo(algoritmo_1, 1000, 10);
    
    


    return 0;
}


