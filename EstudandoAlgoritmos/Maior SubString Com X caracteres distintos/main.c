#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int interacoes = 0;


void apresentacao(char lista[], int quantidade){
    for(int i = 0; i < quantidade; i++){
        printf("%c", lista[i]);
    }
}


char* stringando_corretamente(int quantidade){
    char* string = (char*) malloc( 1 * sizeof(char) );
    
    int index = 0;
    while (index < quantidade){
        
        // Obtendo um caractere aleatorio.
        char novo = (rand() % 26) + 65;
        
        // Obtendo a quantidade aleatoria que ele vai estar
        int vezes = (rand() % 3) + 1;
        
        for(int i = 0; i < vezes; i++){
            string[ index ] = novo;
            index++;
            
            string = (char*) realloc(string, (index + 1) * sizeof(char) );
            
            if(index == quantidade){
                return string;
            }
        }
    }
}


char* montando_string(int quantidade){
    
    char* conjunto = (char*) malloc( quantidade * sizeof(char) );
    
    for(int i = 0; i < quantidade; i++){
        
        conjunto[i] = (rand() % 26) + 65;
        
    }
    
    return conjunto;
}


int algoritmo_(char string[], int quantidade, int carac_distintos){
    
    int nao_esta_presente(char novo_carac, char lista_de_carac[], int quant){
        
        for(int m = 0; m < quant; m++){
            interacoes++;
            
            interacoes++;
            if (lista_de_carac[m] == novo_carac){
                //printf("\nVisualizei que %c já está presente, não vamos adicionar como novo caractere\n", novo_carac);
                return 0;
            }
        }
        
        // Como ele não está presente.
        //printf("\nVisualizei que %c não está presente, vamos adicionar como novo caractere\n", novo_carac);
        return 1;
    }
    
    // Basicamente vamos ter um O(n^2).
    
    int resultado = 0;
    
    // Vamos ter um index para significar o inicio da string que estamos procurando.
    int maior_string = 0;  // Afinal, queremos a maior.
    for(int index1 = 0; index1 < quantidade; index1++){
        interacoes++;
        
        // Vamos precisar criar uma string vazia para que tenhamos noção da string
        // que estamos criando.
        int quant_carac_distintos = 0;
        char* conjunto = (char*) malloc( 1 * sizeof(char) );
        
        // Como não sabemos o final, devemos ir até o talo.
        int index2 = index1;  // Já é nossa forma de saber o tamanho da nossa string.
        //printf("\n--Vamos iniciar a visualização de uma nova string na posicao %d", index2);
        while (1){
            interacoes++;
            
            char carac_atual = string[ index2 ];
            //printf("\n O tamanho da string é: %d", index2 - index1);
            interacoes++;
            if ( (quant_carac_distintos == 0) || nao_esta_presente(carac_atual, conjunto, quant_carac_distintos) ){
                // Se ele não está presente, ou a lista está vazia, vamos preenchê-la com ele.
                
                // Ou seja, temos um novo caractere dentro da substring.
                
                conjunto[ quant_carac_distintos ] = carac_atual;
                
                // Vamos alocar mais memoria.
                
                conjunto = (char*) realloc(conjunto, (quant_carac_distintos + 2) * sizeof(char) );
                
                quant_carac_distintos++;
                
            }
            
            // Caso esse caractere já exista, vamos apenas continuar visualizando eles.
            interacoes++;
            if ( (index2 - index1) > maior_string ){
                maior_string = index2 - index1;
                resultado = index1;
            }
            
            // Verificar o final
            interacoes++;
            if (quant_carac_distintos > carac_distintos || index2 > quantidade){
                // A lista já chegou no limite.
                free(conjunto);
                break;
            }
            
            index2++;
        }
        
    }
    
    
    
    return resultado;
    
}


int algoritmo_1(char string[], int quantidade, int carac_distintos){
    
    /*
    Vamos usar uma quantidade significativa de memória a mais. Em teoria.
    
    Salvando as informações de caracteres novos, podemos fazer o nosso slow ir até 
    essa nova posição e vamos ter a nova string. 
    Note que isso é melhor que ficar varrendo o sanhas, entende?
    
    Observe também a lista vai estar ordenada cara, ou seja, BUSCA BINÁRIA.
     
    */
    
    //printf("\n");
    
    char* refatorando(char lista[], int nova_quantidade){
    
        // Estamos eliminando o primeiro elemento.
        for(int p = 1; p < (nova_quantidade + 1); p++){
            interacoes++;
            lista[p - 1] = lista[p];
        }
        
        lista[ nova_quantidade ] = ' ';
        
        lista = (char*) realloc(lista, nova_quantidade * sizeof(char) );
        
        return lista;
    }
    
    int nao_esta_presente(char novo, char lista[], int quant){
        
        for(int m = 0; m < quant; m++){
            interacoes++;
            
            interacoes++;
            if(lista[m] == novo){
                return 0;
            }
        }
        return 1;
    }
    
    int nova_posicao_do_slow(int lista_de_posicoes[], int quantidade_preenchida, int posicao_slow){
        
        int busca_binaria(){
            int inicio = 0;
            int final = quantidade_preenchida - 1;
            
            while (inicio <= final){
                interacoes++;
                
                int meio = (inicio + final) / 2;
                
                interacoes++;
                if (lista_de_posicoes[ meio ] == posicao_slow){
                    return meio;
                }
                else{
                    
                    interacoes++;
                    if (lista_de_posicoes[ meio ] > posicao_slow){
                        final = meio - 1;
                    }
                    else{
                        inicio = meio + 1;
                    }
                    
                }
                
            }
            
            return -1;
        }
        
        /*
        Devemos achar o slow dentro dessa lista? 
        
        Veja o seguinte exemplo: AAAB. Observe que pela definição, a posição do primeiro A e do B será salva
        na lista. Mas e se o slow estiver em um dos outros A's possíveis, o que vai se proceder? Não vai ser encontrado.
        
        Mas ai eu pergunto para você, é possível mesmo que o slow esteja nessas posições?
        Não.
        
        Note que pela forma que estamos implementando a lista e o slow, é impossível que o cenário anterior ocorra.
        Então, o slow sempre está no início de um caractere distintos dos outros.
        
        */
        
        // A lista contém a posição de cada caractere distinto do anterior dentro da string mãe.
        
        // Vamos providenciar uma busca binaria.
        
        int index_slow_na_lista_de_posicoes = busca_binaria();
        
        int index_prox_slow_na_lista_de_posicoes = index_slow_na_lista_de_posicoes + 1;
        // Afinal, queremos a proxima possível.
        
        return lista_de_posicoes[index_prox_slow_na_lista_de_posicoes];
    }
    
    // Nosso resultado, afinal queremos a maior string possível.
    int resultado = 0;
    
    // Vamos criar os ponteiros para indicar cada elemento da lista de caracteres.
    int maior = 0;
    int slow = 0;
    int fast = 0;
    int quant_carac_distintos = 0;
    char* string_de_carac_distintos = (char*) malloc( 1 * sizeof(char) );
    
    
    // Vamos criar uma forma de salvar as informações de quando um caractere novo surge.
    int* lista_posicao_do_prox_carac_distinto = (int*) malloc( 1 * sizeof(int) );
    int posicao_preenchido_ate_agora = 0;
    
    // Dessa forma, vamos precisar varrer a lista apenas uma vez, de uma única forma.
    while (1){
        interacoes++;
        
        char carac_atual = string[ fast ];
        
        interacoes++;
        if ( (quant_carac_distintos == 0) || nao_esta_presente(carac_atual, string_de_carac_distintos, quant_carac_distintos)){
            //printf("Notei que %c não estava dentro e vou adicioná-lo.\n", carac_atual);
            
            // Temos um novo caractere.
            quant_carac_distintos++;
            
            // Devemos checar se chegou no limite da quantidade.
            if (quant_carac_distintos == carac_distintos + 1){
                //printf("Percebi que já chegamos no limite de caracteres diferentes, então, vou mudar o slow.\n");
                // Como chegamos em um novo caractere apesar de já estarmos no limite permitido
                // Devemos diminuir em uma unidade o limite.
                quant_carac_distintos--;
                
                // Devemos também passar o slow para a frente.
                slow = nova_posicao_do_slow(lista_posicao_do_prox_carac_distinto, posicao_preenchido_ate_agora, slow);
                //printf("A nova posicao do slow é %d\n", slow);
                
                //printf("A string de carac diferentes que não devemos mais olhar é %s\n", string_de_carac_distintos);
                // E finalmente refatorar a nossa string sanhuda.
                string_de_carac_distintos = refatorando(string_de_carac_distintos, quant_carac_distintos);
                //printf("A nova string refatorada de carac diferentes é %s\n", string_de_carac_distintos);
                
                
            }
            
            //printf("Vamos adicionar esse novo caractere.\n");
                
            // Independente se estamos no limite, um caractere novo é absoluto,
            // estamos apenas construindo nossa string de caracteres distintos
            string_de_carac_distintos[ quant_carac_distintos - 1 ] = carac_atual;
            
            // E vamos alocar mais memória
            string_de_carac_distintos = (char*) realloc(string_de_carac_distintos, (quant_carac_distintos + 1) * sizeof(char) );
            //printf("A string de carac diferentes é %s.\n", string_de_carac_distintos);
            
        }
        else{
            //printf("Notei que %c estava dentro e vou passar.\n", carac_atual);
        }
        
        interacoes++;
        if ( (posicao_preenchido_ate_agora == 0) || (carac_atual != string[ fast - 1 ]) ){
            //printf("Notei que esse caractere é diferente do anterior, então vou salvar a posicao dele, %d\n", fast);
            // Vamos salvar a posição dele dentro da super lista ordenada que vai ter
            // o index de cada um dos caracteres distintos do anterior.
            
            lista_posicao_do_prox_carac_distinto[ posicao_preenchido_ate_agora ] = fast;
            
            // Vamos alocar mais memória.
            lista_posicao_do_prox_carac_distinto = (int*) realloc(lista_posicao_do_prox_carac_distinto, (posicao_preenchido_ate_agora + 2) * sizeof(int));
            
            posicao_preenchido_ate_agora++;
        }
        
        interacoes++;
        if ((fast - slow) > maior){
            
            maior = fast - slow;
            resultado = slow;
        }
        
        fast++;
        
        interacoes++;
        if (fast == quantidade){
            break;
        }
        
        //printf("\n\n");
    }
    
    // Liberando Memória
    free(string_de_carac_distintos);
    free(lista_posicao_do_prox_carac_distinto);
    
    return resultado;
}


void testando_individualmente(int (*funcao)(char*, int, int), int quantidade, char string_teste[], int carac_distintos){
    
    char* lista_de_caracteres = (char*) malloc( quantidade * sizeof(char) );
    
    // Vamos inserir um string prória, ou vamos querer gerar ela de forma aleatoria.
    if (string_teste[0] == ' '){
        // Não demos nada para ela testar inicialmente.
        
        char* substituta = montando_string(quantidade);
        
        for(int j = 0; j < quantidade; j++){
            lista_de_caracteres[j] = substituta[j];
        }
        
        free(substituta);
        
    }
    else{
        // Vamos usar o que foi dado.
        
        for(int j = 0; j < quantidade; j++){
            lista_de_caracteres[j] = string_teste[j];
        }

    }
    
    printf("A lista de caracteres é: ");
    apresentacao(lista_de_caracteres, quantidade);
    
    
    int resultado = funcao(lista_de_caracteres, quantidade, carac_distintos);
    printf("\nResultado: %d", resultado);
    
    printf("\nTotal de %d interações.", interacoes);
    
    free(lista_de_caracteres);
}


void testando_coletivo_com_string_correta(int (*funcao)(char*, int, int), int quantidade, int carac_distintos, int vezes){
    
    for(int i = 0; i < vezes; i++){
        
        printf("Teste Numero: %d\n", i + 1);
        
        char* string_result = stringando_corretamente(quantidade);
        printf("A string mãe é: %s\n", string_result);
        
        int resultado = funcao(string_result, quantidade, carac_distintos);
        
        printf("Resultado: %d\n", resultado);
        printf("Total de %d interações.\n", interacoes);
        
        interacoes = 0;
        free(string_result);
        printf("\n\n");
        
    }
    
}


void testando_coletivo(int (*funcao)(char*, int, int), int quantidade, char string_teste[], int carac_distintos, int vezes){
    
    for(int i = 0; i < vezes; i++){
        
        printf("Teste Numero: %d\n", i + 1);
        
        testando_individualmente(funcao, quantidade, string_teste, carac_distintos);
        
        printf("\n\n");
        interacoes = 0;

    }
    
}


int main()
{
    /*
    Dado uma string de tamanho aleatorio, devemos implementar um código capaz de
    obter o index inicial da maior substring com apenas x caracteres distintos.
    
    Ex: CCAABBB. Temos x = 2.
    Isto é, o index inicial é 2.
    
    */
    
    srand(time(NULL));
    
    // Lembre-se de quando for colocar uma string, coloque a quantidade correspondente a ela.
    //testando_individualmente(algoritmo_1, 10, "CCAAXBBBAAPP", 2);
    
    //testando_coletivo(algoritmo_1, 100, " ", 2, 10);
    
    testando_coletivo_com_string_correta(algoritmo_, 100, 2, 5);
    
    
    /*
    É interessantissmo verificar que para determinado conjunto de inputs, um algoritmo é muito melhor
    que o outro.
    
    Para strings completamente aleatorias, ambos algoritmos convergem para o mesmo resultado.
        É fato que em strings de tamanho reduzido, o algoritmo_1 ainda sim possui um resultado bem melhor.
        Entretanto, para valores que em teoria tbm são pequenos, mas já são maiores que os anteriores, ambos
        algoritmos tendem a valores muito próximos. 
        
        É fato também que no algoritmo_, ruim, em teoria, teriamos um código O(n^2), mas note que não chegamos a varrer
        a lista completamente em cada elemento, varremos apenas alguns elementos para frente. Sendo assim, a função tende
        a um comportamento de O(n) ~ O(n^2).
        
    Para strings ainda aleatorias, mas com um certo padrão de repetição, há um resultado totalmente diferente.
        O algoritmo_1, bom, não vai precisar mover tanto o slow do nada, pois agora as strings tem caracteres
        que se repetem mais. Daí, interações desnecessárias não serão feitas.
        
        Enquanto o algoritmo_, ruim, ainda fará a mesma coisa que antes.
        
        Assim, o algoritmo_1, bom, finaliza tendo menos da metade de interações do ruim.
        
        Concluimos que as situações dependem bastante do conjunto de entrada.
    */
    
    
    
    

    return 0;
}


