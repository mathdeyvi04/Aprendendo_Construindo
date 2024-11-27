#include <stdio.h>
#include <stdlib.h>
#include "Back.h"

// Vamos criar uma struct que basicamente uma lista da string e seu tamanho
// Para carregarmos a informação melhor ao invés de tentar usar obter tamanho.




void cabecalho(
    char* frase_titulo,
    char caract
){
    /*
    Descrição:
        Função responsável por limpar a tela de prompt e apresentar um 
        cabeçalho estilizado.
    
    Parâmetros:
        char* frase_titulo:
            Vetor de caracteres.
        char caract:
            Caractere que será usado para o cabeçalho.
    */
    
    int tamanho = obter_tamanho(frase_titulo);
    int padding = 15;  // Espaçamento dentro do cabeçalho
    
    // Colocando Cor
    printf("\033[1m\033[32m");
    
    // Colocando os caracteres
    {
        for(
            int i = 0;    
            i < tamanho + 2 * padding;
            i++
        ){
            printf("%c", caract);
        }
    }
    
    printf("\n");
    
    // Preenchendo o titulo
    {
        for(
            int i = 0;
            i < padding;
            i++
        ){
            printf(" ");
        }
        
        printf("%s", frase_titulo);
        
        for(
            int i = 0;
            i < padding;
            i++
        ){
            printf(" ");
        }
    }
    
    printf("\n");
    
    // Colocando os caracteres
    {
        for(
            int i = 0;    
            i < tamanho + 2 * padding;
            i++
        ){
            printf("%c", caract);
        }
    }
}


void apagando_tela(){
    /*
    Descrição:
        Função responsável por pular diversas linhas e permitir que a tela
        não fique poluída.
        
    Parâmetros:
        Nenhum.
        
    Retorno:
        Nenhum.
    */
    
    int PULADAS_DE_LINHA = 15;
    
    for(
        int i = 0;
        i < PULADAS_DE_LINHA;
        i++
    ){
        printf("\n");
    }
    
}


int apresentando_menu_principal(){
    /*
    Descrição:
        Função responsável por apresentar as formas de cripto e decripto.
        Permitindo que o usuário avance em um novo menu mais preparado.
        
    Parâmetros:
        Nenhum.
        
    Retorno:
        Menu em condições.
    */
    
    printf("\n1 - Sair do Sistema\n");
    printf("2 - Método da Inversão\n");
    printf("3 - Método da Grade\n");
    printf("4 - Método do Quadro Simples\n");
    printf("5 - Método da Quadro Duplo\n");
    printf("6 - Ver Registro");
    printf("\nEscolha a opção desejada: ");
    
    int* se_deu_certo = (int*)calloc(1, sizeof(int));
    int desejo = 0;
    while(1){
        *se_deu_certo = scanf(
            "%d",
            &desejo    
        );
        
        if (
            // Caso a função scanf receba algo estranho.
            *se_deu_certo != 1    
        ){
            avisando_erro("\nOpção Não Válida\n");
            // Limpando o buffer da merda que foi digitada
            while (getchar() != '\n');
            printf("Escolha a opção desejada: ");
            
            continue;
        }
        
        
        // Vamos sair daqui e realizar apenas se:
        if (
            (desejo >= 1) & (desejo <= 6)    
        ){
            // Então uma opção válida foi escolhida.
            free(se_deu_certo);
            return desejo;
        }
        else{
            avisando_erro("\nOpção Não Válida.\n");
        }
        
    }
    
    
}


int menu_de_inversao(){
    /*
    Descrição:
        Função responsável por apresentar um menu específico para este método e
        pelo tratamento de erros de entrada.
    
    Parâmetros:
        Nenhum.
        
    Retorno:
        Nenhum.
    */
    
    char* obtendo_entrada(){
        printf("\nEntre com a frase:\n");
        printf("->");
        // Variáveis de Entrada
        int* tamanho = (int*) calloc(1, sizeof(int));
        char* caract = (char*) malloc(1 * sizeof(char));
        char* frase_digitada = (char*) malloc(1 * sizeof(char));
        if (
            frase_digitada == NULL    
        ){
            avisando_erro(
                "Erro de Alocação de Memória na criação da variável."    
            );
            
        }
        
        
        // Variáveis de Confirmação de Êxito
        int* se_deu_certo = (int*) calloc(1, sizeof(int));
        int* confirmacao = (int*) calloc(1, sizeof(int));
        // Limpar Buffer
        while(getchar() != '\n'); 
        while(1){
            
            // Pegando os caracteres desejados.
            *caract = getchar();
            
            // Deu ruim.
            if (
                *caract == EOF    
            ){
                avisando_erro(
                    "Caractere digitado inválido."
                );
                printf("Continue sem dar espaços:\n");
                printf("->");
                continue;
                
            }
            
            if (
                *caract == '\n'    
            ){
                
                // Devemos confirmar
                while(1){
                    
                    printf("Deseja mesmo essa frase?(1 - Sim):");
                    *se_deu_certo = scanf(
                        "%d",
                        confirmacao
                    );
                    
                    if(
                        *se_deu_certo != 1    
                    ){
                        avisando_erro(
                            "Opção Inválida"    
                        );
                        continue;
                    }
                    
                    if(
                        *confirmacao == 1    
                    ){
                        // Então desejamos essa frase.
                        free(confirmacao);
                        free(se_deu_certo);
                        free(tamanho);
                        free(caract);
                        
                        
                        return 0;
                        
                    }
                    else{
                        // Então não desejamos essa frase
                        frase_digitada = (char*) realloc(frase_digitada, 1 * sizeof(char));
                        *tamanho = 0;
                        break;
                    }
                    
                }
                
                // Limpar o buffer
                while(getchar() != '\n');
                
                continue;
                
            }
            
            // Como ainda estamos digitando, vamos colocar na frase
            frase_digitada[*tamanho] = *caract;
            *tamanho = *tamanho + 1;
            // E aumentamos o tamanho do vetor
            frase_digitada = (char*)realloc(frase_digitada, (*tamanho + 1) * sizeof(char));
            
        }
    }
    
    
    
}
