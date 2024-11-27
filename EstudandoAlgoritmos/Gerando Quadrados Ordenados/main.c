#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int interacoes = 0;


void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleSort(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        interacoes++;
        for (int j = 0; j < tamanho - i - 1; j++) {
            interacoes++;
            // Compara elementos adjacentes e troca se estiverem na ordem errada
            interacoes++;
            if (array[j] > array[j + 1]) {
                trocar(&array[j], &array[j + 1]);
            }
        }
    }
}


void apresentacao(int lista[], int quant){
    for(int j = 0; j < quant; j++){
        if(j == 0){
            printf("[ %d,", lista[j]);
        }
        else{
            if(j == (quant - 1)){
                printf(" %d ]", lista[j]);
            }
            else{
                printf(" %d,", lista[j]);
            }
        }
    }
}


int* BuscaBinariaModif(int lista[], int tamanho_ate_agora, int alvo){
        
    /*
    O ponto aqui é que vamos precisar da informação se ele está ou não presente.
    Caso não esteja, onde colocá-lo mantendo a lista ordenada.
    */
    
    int* result = (int*) malloc( 2 * sizeof(int) );
    result[0] = 0;  // Começamos supondo que ele não está dentro
    
    interacoes++;
    if (alvo < lista[0] || tamanho_ate_agora == 0){
        result[1] = 0;
        return result;
    }
    
    // Criando os ponteiros
    int inicio = 0;
    int final = tamanho_ate_agora - 1;
    int meio = 0;
    
    while (inicio <= final){
        interacoes++;
        
        meio = (inicio + final) / 2;
        //printf("\nO numero é %d", lista[meio]);
        interacoes++;
        if(lista[meio] == alvo){
            // Achamos o cara.
            result[0] = 1;
            result[1] = meio;
            return result;
        }
        else{
            interacoes++;
            if (lista[meio] > alvo){
                //printf("\nVi que o alvo é menor que esse");
                final = meio - 1;
            }
            else{
                //printf("\nVi que o alvo é maior que esse");
                inicio = meio + 1;
            }
        }
    }
    
    // Se chegamos aqui, temos a certeza que é porque não achamos o alvo.
    result[1] = ((inicio + final) / 2) + 1;
    
    // Note que não usamos o meio pois se o alvo não está presente, a ultima
    // coisa que vai ser executada dentro do while 
    
    return result;
}


int* refatorando(int lista[], int quantidade_antiga, int valor_a_ser_adicionado, int posicao_a_ser_adicionado){
    
    // Como estamos em array, sempre vamos ter O(n)
    int variaveis_de_controle[2] = {0, valor_a_ser_adicionado};
    int percursor = 0;
    
    for(int i = posicao_a_ser_adicionado; i != quantidade_antiga + 1; i++){ // Note que o tamanho_ate_agora + 1, vai ser o novo tamanho da lista
        
        // Vamos sanhar até o talo.
        interacoes++;
        
        variaveis_de_controle[ percursor % 2 ] = lista[ i ];  // Salvando o valor na posição.
        percursor++;
        
        lista[ i ] = variaveis_de_controle[ percursor % 2 ];  // Trocando na lista.
        //printf("\nNa posicao %d temos agora %d", i, lista[i]);
    }
}


int* montando_lista_aleatoria(int quantidade, int maior, int menor){
    
    int nao_esta_presente(int lista[], int quantidade, int novo){
    
        for(int i = 0; i < quantidade; i++){
            if (novo == lista[i]){
                return 0;
            }
        }
        
        return 1;
    }
    
    int gerando_aleatorio(){
        int a = maior - menor + 1;
        int b = menor;
        
        return (rand() % a) + b;
    }
    
    int* lista = (int*) malloc( quantidade * sizeof(quantidade) );
    
    // Criando a lista, O(n)
    for(int i = 0; i < quantidade; i++){
        int novo = gerando_aleatorio();
        
        if (nao_esta_presente(lista, i, novo)){
            lista[i] = novo;
        }
        else{
            i--;
        }
    }
    
    // Depois, vamos ordenar ela usando bubbleSort, aqui eu caguei para isso cara.
    // O(n^2)
    bubbleSort(lista, quantidade);
    
    return lista;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////


int* algoritmo_ruim(int lista[], int quantidade){
    // Vamos obter os quadrados e ordená-los usando BubbleSort.
    
    int* quadrados = malloc( quantidade * sizeof(int) );
    
    // Construindo, O(n)
    for(int i = 0; i < quantidade; i = i + 1){
        interacoes++;
        quadrados[i] = lista[i] * lista[i];
    }

    // Ordenando agora, O(n^2)
    bubbleSort(quadrados, quantidade);
    
    // Note então que esse algoritmo é claramente O(n^2 + n), apesar de ser bem simples.
    
    return quadrados;
}


int* algoritmo_pouco_melhor(int lista[], int quantidade){
    // Vamos obter os quadrados e ordená-los usando inserção binária.
    
    int* resultante = (int*) malloc( 1 * sizeof(int) );
    
    // Vamos pegar os quadrados.
    for(int i = 0; i < quantidade; i++){
        interacoes++;
        int novo_quadrado = lista[i] * lista[i];
        
        int* busca = BuscaBinariaModif(resultante, i, novo_quadrado);
        //printf("\nO numero %d está presente: %d", novo_quadrado, busca[0]);
        
        interacoes++;
        if (busca[1] == i){
            // Vamos apenas adicionar
            resultante[i] = novo_quadrado;
            //printf("\nVou adicionar no final.");
            resultante = (int*) realloc(resultante, (i + 1) * sizeof(int) );
        }
        else{
            resultante = (int*) realloc(resultante, (i + 1) * sizeof(int) );
            refatorando(resultante, i, novo_quadrado, busca[1]);
            //printf("\nA nova lista é: ");
            //apresentacao(resultante, i + 1);
        }
        
        free(busca);
    }
    
    // Com isso, encerramos de uma vez e podemos analisar que possui O(n*logn)
    return resultante;
}


int* algoritmo_melhor(int lista[], int quantidade){
    // Copiando do cara lá
    
    int left = 0;
    int right = quantidade - 1;
    
    int* resultado = (int*) malloc(1 * sizeof(int));
    
    
    // Isso aqui tem O(n)
    int index = 0;
    while (left <= right){
        interacoes++;
        
        interacoes++;
        if (abs(lista[left]) > abs(lista[right])){
            resultado[ index ] = lista[ left ] * lista[ left ];
            left++;
        }
        else{
            resultado[ index ] = lista[ right ] * lista[ right ];
            right--;
        }
        
        // Alocando mais memória 
        resultado = (int*) realloc(resultado, (index + 2)*sizeof(int));
        
        index++;
    }
    
    // Vamos ter que reordenar.
    int* nova_lista = (int*) malloc( quantidade * sizeof(int) );
    index = 0;
    for(int j = quantidade - 1; j != -1; j--){
        interacoes++;
        nova_lista[index] = resultado[j];
        index++;
    }
    
    free(resultado);
    
    return nova_lista;
}


void testando_individualmente( int* (*funcao)(int*, int), int quantidade){
    
    interacoes = 0;
    
    int maior_valor = 2 * quantidade;
    int menor_valor = - 2 * quantidade;
    
    int* lista_mae = montando_lista_aleatoria(quantidade, maior_valor, menor_valor);
    printf("A lista ordenada de valores: ");
    apresentacao(lista_mae, quantidade);
    
    
    interacoes = 0; // Afinal, estamos medindo apenas os algoritmos
    int* lista_resultante = funcao(lista_mae, quantidade);
    
    printf("\n\nA lista resultante é: ");
    apresentacao(lista_resultante, quantidade);
    
    printf("\n\nTotal de %d interações", interacoes);
    
    free(lista_mae);
    free(lista_resultante);
}


void testando_coletivo(int* (*funcao)(int*, int), int quantidade, int vezes){
    
    for(int i = 0; i < vezes; i++){
        printf("\nTeste numero %d\n", i + 1);
        
        testando_individualmente(funcao, quantidade);
        
        printf("\n\n");
    }
    
    
    
}




int main()
{
    /* Vamos receber uma lista de números ordenados. E eles vão conter números 
    que alguns são negativos.
    
    Devemos obter um conjunto de números que são elevados ao quadrado e que também 
    estão ordenados.
    */
    
    srand(time(NULL));
    
    testando_individualmente(algoritmo_melhor, 5);
    
    //testando_coletivo(algoritmo_pouco_melhor, 20, 5);
    
    /*
    int* lista = (int*) malloc(2 * sizeof(int) );
    lista[0] = 1;
    lista[1] = 2;
    
    refatorando(lista, 2, -1, 2);
    
    printf("\n resultado: ");
    apresentacao(lista, 3);
    */
    
    
    return 0;
}



