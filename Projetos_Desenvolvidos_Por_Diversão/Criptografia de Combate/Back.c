#include <stdio.h>
#include <stdlib.h>

int obter_tamanho(
    char* string
){
    /*
    Descrição:
        Função responsável por varrer uma string obtendo o total de caracteres
        do mesmo
    
    Parâmetros:
        char* string:
            Vetor de Caracteres
            
    Retorno:
        Tamanho da string
    */
    
    int i = 0;
    while (
        string[i] != '\0'    
    ){
        i++;
    }
    
    return i;
}


void avisando_erro(
    char* string    
){
    /*
    Descrição:
        Função responsável por apresentar uma forma de avisar o usuário desta-
        cadamente.
        
    Parâmetros:
        char* string:
            Aviso a ser dado.
    
    Retorno:
        Aviso.
    */
    
    printf("\033[0m\033[43m\033[1m%s\033[0m\033[1m\033[32m", string);
}


char* aplicando_inversao(
    char* string_mae,
    int tamanho
){
    /*
    Descrição:
        Função responsável por gerenciar a criptografia e a descriptografia
        do método da inversão.
        
        Especialmente pela natureza deste método, não é necessário que recebamos
        um número definir do modo da função, dado criptografando ele invertirá e 
        descriptografando ele invertirá também.
        
        Exemplo:
            char string[] = "xxxxxxxxxxxxxxxxxxxx";
            
            nova_string = aplicando_inversao(string, NUMERO_DE_CARACTERES);
            ou
            nova_string = aplicando_inversao(string);
    
    Parâmetros:
        char* string_mae:
            texto que se deseja criptografar ou descriptografar.
            
        int tamanho:
            Caso receber menor ou igual a zero., utilizará a função de obter tamanho da string.
            Caso não e seja um valor válido, utilizará o dado.
    
    Retorno:
        String resultado.
    */
    
    // Vamos apenas girar a cada um dos valores da string
    int* intervalo = (int*) calloc(2, sizeof(int));
    intervalo[0] = 0;
    
    if (tamanho <= 0){
        intervalo[1] = obter_tamanho(string_mae) - 1;
    }{
        intervalo[1] = tamanho - 1;
    }
    
    char* intermediario = (char*) malloc(1 * sizeof(char));
    while(intervalo[0] < intervalo[1]){
        *intermediario = string_mae[intervalo[0]];
        
        string_mae[intervalo[0]] = string_mae[intervalo[0]];
        
        string_mae[intervalo[0]] = *intermediario;
        
        intervalo[0]++;
        intervalo[0]--;
    }
    
    // Afinal, toda string é um vetor de caracteres.
    free(intermediario);
    free(intervalo);
    return string_mae;
}




