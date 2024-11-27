#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int intervalos_tempo = 0;


void apresentacao_janela(char janela[], int tamanho){
    for(int i = 0; i < tamanho; i = i + 1){
        printf("%c", janela[i]);
    }
}


char* criando_string(int tamanho){
    
    // Vamos criar a string de forma dinamica, afinal queremos retornar
    
    char* string = (char*) malloc(1 * sizeof(char));
    
    for(int i = 0; i < tamanho; i = i + 1){
        string[i] = 'a' + (rand() % 26);
        string = (char*) realloc(string, (i + 2) * sizeof(char));
    }
    
    return string;
}


void imprimindo(char string[]){
    // Apenas para termos como fazer comparações melhores entre os dois códigos.
    
    
    FILE *p = fopen("aleatorios.txt", "a");
    
    fprintf(p, "%s\n", string);
    
    fclose(p);
}

// Péssimo.
int algoritmo1(char string[], int tamanho,  int faixa){
    // Vamos percorrer a string em janelas do tamanho da faixa
    /*
    
    char janela[faixa + 1] = {'\0'};
    
    // Você não vai acreditar. Em teoria, o C não aceita que arrays sejam iniciadas
    // com variáveis assim. Então vamos precisar alocar tudo...
    
    */
    
    char* janela = (char*) malloc((faixa + 1) * sizeof(char));
    
    
    
    for(int i = 0; i < tamanho; i = i + 1){
        intervalos_tempo++;
        // Para cada caractere da string, vamos ter uma janela
        
        // Construindo a janela
        for(int j = 0; j < faixa; j = j + 1){
            intervalos_tempo++;
            // Se já tivermos passado da ultima janela possivel.
            if ((i + j + 1) > tamanho){
                intervalos_tempo++;
                free(janela);
                return -1;
            }
            
            janela[j] = string[i + j];
            
        }
        
        //Vamos verificar se está se procedendo corretamente
        //printf("\n");
        //apresentacao_janela(janela, faixa);
        
        int e_essa_janela = 1;  // Para descobrirmos a informação se é ou não a janela
        
        // Com cada janela, devemos verificar se existe caracteres diferentes dentro da janela.
        for(int j = 0; j < faixa; j = j + 1){
            intervalos_tempo++;
            // Dai comparando
            for(int k = 0; k < faixa; k = k + 1){
                intervalos_tempo++;
                if (j != k){
                    intervalos_tempo++;
                    if (janela[j] == janela[k]){
                        intervalos_tempo++;
                        // Temos dois caracteres iguais em posições diferentes 
                        // na janela, logo, ela deve ser descartada.
                        e_essa_janela = 0;  // False
                    }
                }
            }
        }
        
        if (e_essa_janela){
            intervalos_tempo++;
            free(janela);
            
            // Afinal de contas, a mensagem começa a partir disso.
            return i + faixa;
        }
        
    }
    
    free(janela);
    return -1;
}

// Um pouco melhor?
int algoritmo2(char string[], int tamanho, int faixa){
    
    int verificando_se_ja_existe_dentro(
        char faixa_de_caracteres[],
        int tamanho_ate_agora, 
        char carac
        ){
        
        for(int m = 0; m < tamanho_ate_agora; m = m + 1){
            intervalos_tempo++;
            if (faixa_de_caracteres[m] == carac){
                intervalos_tempo++;
                return 1;
            }
        }
        
        return 0;
    }
    
    // Percorrendo a string completa
    for(int i = 0; i < tamanho; i = i + 1){
        intervalos_tempo++;
        
        char* janela = (char*) malloc((faixa + 1) * sizeof(char));
        
        if (i - 1 == tamanho - faixa){
            intervalos_tempo++;
            free(janela);
            return -1;
        }
        
        // Construindo a janela
        for(int j = 0; j < faixa; j = j + 1){
            intervalos_tempo++;
            
            intervalos_tempo++;
            if (verificando_se_ja_existe_dentro(janela, j, string[i + j])){
                // Quer dizer que esse caractere já está dentro da janela, então
                // devemos parar de criar essa janela
                break;
            }
            else{
                // Se esse caractere não existe dentro dela, podemos colocá-lo.
                janela[j] = string[i + j];
                
                if (j == faixa - 1){
                    // Condição de termino meu patrão.
                    intervalos_tempo++;
                    
                    free(janela);
                    return i + faixa;
                }
                
                
            }
            
        }
        
        free(janela);
    }

    return -1;
}





void testando_algoritmos(int (*funcao)(char string[], int tamanho,  int faixa), int vezes, int tamanho, int faixa){
    // LITERALMENTE PASSANDO UMA FUNÇÃO COMO ARGUMENTO PORRA
    srand(time(NULL));
    
    for(int i = 0; i < vezes; i = i + 1){
        // Primeiro, criar a string completa que vamos usar
        clock_t inicio = clock();
        
        //int tamanho = 100;
        
        char* frase_criptografada = criando_string(tamanho);
        //printf("%s", frase_criptografada);
        
        // Devemos ser capazes de verificar as faixas de janela
        //int faixa = 10;
        int index_inicio_mensagem = funcao(frase_criptografada, tamanho, faixa);
        //printf("\n%d", index_inicio_mensagem);
        
        imprimindo(frase_criptografada);
        
        clock_t fim = clock();
        float tempo_total = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        free(frase_criptografada);
        //printf("\n\nApenas para comparações, %d interações foram feitas.\n", intervalos_tempo);
        //printf("Tempo Decorrido: %fs", ((double)(fim - inicio)) / CLOCKS_PER_SEC);
        
        printf("\n %d°-Teste Finalizado:\n %d interações\n Resultado: %d\n", i + 1,  intervalos_tempo, index_inicio_mensagem);
        
        //Ja que finalizamos um teste, vamos zerar por favor 
        intervalos_tempo = 0;
        
    }
    
}


void testando_individualmente(char frase_criptografada[], int tamanho, int faixa){
    
    int index_inicio_mensagem = algoritmo2(frase_criptografada, tamanho, faixa);
    
    printf("\n %d interações foram feitas, resultado: %d\n", intervalos_tempo, index_inicio_mensagem);
    
    
}

int main()
{
    
    //testando_individualmente("nmfbffluvxeiyqtbwdou", 20, 5);
    
    testando_algoritmos(algoritmo2, 10, 1000, 10);

    
    return 0;
}

