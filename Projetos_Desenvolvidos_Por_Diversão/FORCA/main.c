#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cabecalho(char *frase, char a) {
    /* Aqui teremos nossa 
    função de cabecalho padrão */
    
    #include <string.h>
    
    int tamanho = strlen(frase);
   
    //TESTE
    //printf("%s\n", frase);
    // printf("%c\n", a);
    // printf("%d", tamanho)
    
    int i;
    
    for (i=0 ;i < tamanho+20; i=i+1) {
    
        printf("%c", a);
        
    }
    
    printf("\n");
    
    int espaco = 10;
    
    printf("%*s %s", espaco, "", frase);
    
    printf("%*s\n", espaco-1, "");
    
    for (i=0 ;i < tamanho+20; i=i+1) {
    
        printf("%c", a);
        
    }
    
    printf("\n");
}

int main()
{
    
    printf("\033[1m\033[7m");
    cabecalho("FORCA", '*');
    
    char palavra[20];
    printf("\nDigite a palavra que será o centro: ");
    scanf("%s", palavra);
    
    while(1){
        int opc;
        printf("\n\nVoce realmente deseja que seja essa palavra? ");
        scanf("%d", &opc);
        if(!opc){
            printf("\nDigite a palavra que será o centro: ");
            scanf("%s", palavra);
        }
        else{
            break;
        }
    }
    
    while(1){
        if(strlen(palavra)>20){
            printf("O tamanho da palavra é grande demais.");
            printf("Digite a palavra que será o centro: ");
            scanf("%s", palavra);
        }
        else{
            break;
        }
    }
    
    
    
    palavra[(int)strlen(palavra)] = '\0';
    
    system("clear");
    
    int erros = 5;
    char historico[50] = {' '};
    int p = 0;
    int co = 1;
    
    while(1){
        cabecalho("FORCA", '*');
        printf("\n");
        
        //Verificando se está na palavra
        char letra = ' ';
        
        for(int i = 0; i<(int)strlen(palavra);i++){
            int c = 0;
            for(int i_ = 0; i_<(int)strlen(historico);i_++){
                //Vamos pegar um caractere da palavra e ver se é igual á cada do historico
                if(palavra[i] == historico[i_]){
                    printf("%c", palavra[i]);
                    c = 1;
                    break; // Precisamos garantir que não há duas letras iguais no historico
                }
                
            }
            if(c!=1){
                
                printf("_");
            }
            
        }
        
        printf("\n\nErros Permitidos: %d", erros);
        printf("\n\nLetras Digitadas: %s", historico);
        
        
        printf("\n\nDigite uma letra: ");
        scanf(" %c", &letra);
        
        int con=0;
        while(1){
            for(int i_ = 0; i_<(int)strlen(historico);i_++){
                if(letra==historico[i_]){
                    printf("Voce já digitou essa letra!");
                    printf("\n\n\aDigite uma letra: ");
                    scanf(" %c", &letra);
                    con = 1;
                }
            }
            if(con){
                //Letra já foi digitada
                con = 0;
            }else{
                break;
            }
        }
        
        
        
        historico[p] = letra;
        historico[p+1] = '-';
        
        if(letra != ' '){
            //Quer dizer que que já colocamos pelo menos uma letra
            int veri(){
                for(int i = 0; i<(int)strlen(palavra);i++){
                    if(letra == palavra[i]){
                        //quer dizer que há uma correspodencia
                        //printf("Achei correspodencia");
                        co++;
                        return 0;
                    }
                }
                printf("\a");
                return 1;
            }
            
            erros = erros - veri();
            
        }
        
        if(co == (int)strlen(palavra)){
            //palavra completa
            printf("\n\nPARABENS VOCE SAFOU");
            break;
        }
        
        if(erros == 0){
            printf("\n\nBARROOOO para voce!");
            break;
        }
        
        p = p + 2;
        system("clear");
    }
    
    
    
    printf("\033[0m");
    return 0;
}




