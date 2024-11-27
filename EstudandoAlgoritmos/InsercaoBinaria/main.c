#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int interacoes = 0;

void imprimindo(int lista[], int tamanho){
    
    FILE *p = fopen("sanha.txt", "a");
    
    for(int i = 0; i < tamanho; i++){
        if (i == 0){
            fprintf(p, "{%d,", lista[i]);
        }
        else{
            if (i == tamanho - 1){
                fprintf(p, "%d}\n", lista[i]);
            }
            else{
                fprintf(p, "%d,", lista[i]);
            }
        }
    }
    
    fclose(p);
}

void apresentacao(int lista[], int tamanho){
    for(int p = 0; p < tamanho; p = p + 1){
        printf("%d,", lista[p]);
    }
}

void construindo_normal(int tamanho){
    
    // Vamos construir uma lista de números distintos e ordená-los.
    
    void trocar(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void BubbleSort(int array[], int tamanho) {
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
    
    int* lista_completa(int tamanho, int maximo){
        
        int esta_dentro(int numero, int lista_numeros[], int tamanho_ate_agora){
            // Note que temos um O(n)
            
            for(int j = 0; j < tamanho_ate_agora; j = j + 1){
                interacoes++;
                
                interacoes++;
                if (lista_numeros[j] == numero){
                    // Está dentro
                    return 1;
                }
            }
            
            // Não está dentro
            return 0;
        }
        
        
        int* lista = (int*) malloc(tamanho * sizeof(int));
        
        // Note que estamos construindo a lista e, enquanto isso, estamos fazendo buscas nela
        // Temos um O(n^2)
        
        for(int i = 0; i < tamanho; i = i + 1){
            interacoes++;
            int novo_numero = rand() % maximo;
            
            interacoes++;
            if (!esta_dentro(novo_numero, lista, i)){
                // Se não estiver dentro, vamos colocá-lo.
                lista[i] = novo_numero;
                
                
                /*
                Observe que quando esse if não é satisfeito, um local não é preenchido pelo programa
                Entretanto, o indice avança para posteriores.
                */
                
            }
            else{
                // Para que continuemos no mesmo.
                i = i - 1;
            }
            
        }
        
        return lista;
        
    }
    
    ////////////////////////////////////////////////////////////////////////
    
    //Obtendo a lista completa
    
    int* lista_numeros_nao_ordenados_distintos = lista_completa(tamanho, 150);
    
    printf("A lista: ");
    apresentacao(lista_numeros_nao_ordenados_distintos, tamanho);
    
    //imprimindo(lista_numeros_nao_ordenados_distintos, tamanho);
    
    // Ordenando a lista, vamos usar Bubble Sort, o qual tem O(n^2)
    
    BubbleSort(lista_numeros_nao_ordenados_distintos, tamanho);
    
    printf("\n\nA lista ordenada: ");
    apresentacao(lista_numeros_nao_ordenados_distintos, tamanho);
    
    
    
    
    free(lista_numeros_nao_ordenados_distintos);
    
    
    printf("\n\nTotal de Interações: %d", interacoes);
}

void construindo_binaria(int tamanho){
    
    /*
    Aqui, vamos construir a lista de forma já ordenada e vamos usar sempre 
    a grande Busca Binaria.
    */
    
    // Essa busca já tem O(log n)
    int* BuscaBinariaModif(int lista[], int tamanho_ate_agora, int valor_a_ser_buscado){
        
        int* resultado = (int *) malloc(2 * sizeof(int));
        
        /*
        resultado[0] -- Posicao do sanhudo
        resultado[1] -- Se ele está presente ou não
        
        Note que vamos obter 2 informações ao mesmo tempo
        
        */
        
        // Definindo ponteiros
        int inicio = 0;
        int final = tamanho_ate_agora - 1;
        
        
        while (inicio <= final){
            interacoes++;
            
            //printf("O inicio: %d e o final: %d,", inicio, final);
            
            int meio = (inicio + final) / 2;
            //printf("O meio é %d\n", meio);
            
            interacoes++;
            if (lista[meio] == valor_a_ser_buscado){
                resultado[1] = meio;
                resultado[0] = 1;
                return resultado;
            }
            else{
                
                interacoes++;
                if (lista[meio] > valor_a_ser_buscado){
                    final = meio - 1;    
                }
                else{
                    inicio = meio + 1;
                }
                
            }
            
        }
        
        // Vai retornar a posição que esse não adicionado deve estar.
        interacoes++;
        if (valor_a_ser_buscado < lista[0] || tamanho_ate_agora == 0){
            // Ele é o novo menor
            resultado[1] = 0;
            resultado[0] = 0;
        }
        else{
            resultado[1] = ((inicio + final) / 2) + 1;
            resultado[0] = 0;
        }
        
        return resultado;
        
    }
    
    int inserindo_numero(int lista[], int tamanho_ate_agora, int valor_a_ser_adicionado, int posicao_a_ser_adicionado){
        
        // Como estamos em array, sempre vamos ter O(n)
        int variaveis_de_controle[2] = {0, valor_a_ser_adicionado};
        int percursor = 0;
        
        for(int i = posicao_a_ser_adicionado; i != tamanho_ate_agora + 2; i++){ // Note que o tamanho_ate_agora + 1, vai ser o novo tamanho da lista
            
            // Vamos sanhar até o talo.
            interacoes++;
            
            variaveis_de_controle[ percursor % 2 ] = lista[ i ];  // Salvando o valor na posição.
            percursor++;
            
            lista[ i ] = variaveis_de_controle[ percursor % 2 ];  // Trocando na lista.
            
        }
        
        return 0;
        
    }
    
    int* obtendo_lista_de_numeros(int maximo){
        
        int* lista = (int*) malloc(tamanho * sizeof(int));
        
        // Vamos partir do principio que ela já está ordenada.
        for(int i = 0; i < tamanho; i = i + 1){
            interacoes++;
            
            int novo_numero = rand() % maximo;
            
            int* resultado_obtido = BuscaBinariaModif(lista, i, novo_numero);
            
            interacoes++;
            if (resultado_obtido[0] == 0){
                // Quer dizer que esse numero não está presente.
                
                // Então devemos adicioná-lo a lista de forma que ela continue ordenada.
                
                /*
                printf("\nAté agora a lista: ");
                apresentacao(lista, i);
                
                printf("\n Vou adicionar %d na posicao %d", novo_numero, resultado_obtido[1]);
                */
                
                inserindo_numero(lista, i, novo_numero, resultado_obtido[1]);
                
            }
            else{
                // Quer dizer que ele está presente.
                
                // Se ele já está dentro, vamos apenas pular.
                i = i - 1;
                
            }
            
        }
        
        return lista;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    /*
    // Ambiente de teste
    
    int numeros[5] = {1, 5};
    int tamanho_ate_agora = 2;
    
    
    int novo = -1;
    int* resultado = BuscaBinariaModif(numeros, tamanho_ate_agora, novo);
    printf("Se está presente: %d e o resultado %d\n", resultado[0], resultado[1]);
    
    inserindo_numero(numeros, tamanho_ate_agora, novo, resultado[1]);
    
    apresentacao(numeros, tamanho_ate_agora + 1);
    
    free(resultado);
    */
    
    
    int* lista_ordenada = obtendo_lista_de_numeros(150);
    
    printf("\nA lista final: ");
    apresentacao(lista_ordenada, tamanho);
    
    free(lista_ordenada);
    
    printf("\n\nTotal de interacoes: %d", interacoes);
    
}

void reproduzindo_testes(void (*funcao)(int), int vezes, int tamanho){
    
    
    for(int i = 0; i < vezes; i++){
        funcao(tamanho);
        printf("\n\n");
        interacoes = 0;
    }
    
}

int main(){
    
    srand(time(NULL));
    
    int comprimento = 50;
    
    int vezes = 5;
    
    reproduzindo_testes(construindo_binaria, vezes, comprimento);
    
    //construindo_binaria(10);
    
    /*
    
    Nota-se uma evolução muito significativa. 
    A formação da lista trata-se ESSENCIALMENTE de um algoritmo O(n).
    
    Entretanto, com o normal, fazemos uma ordenação padrão com BubbleSort, sendo portanto
    O(n^2).
    
    Concluimos então que o valor é O(n^2).
    
    Agora, com o novo algoritmo, o sanha se torna outro. Temos o padrão de O(n)
    para a formação da lista, mas como já estamos construindo ela de forma ordenada,
    podemos usar uma busca binaria para inserir o numero no canto exato para que 
    a lista continue ordenada, sendo portanto O(log n). O processo de mudar os indexs
    de cada valor também é O(n). O código resultante de ordenação trata-se de um O(n).
    
    */
    
    return 0;
}






