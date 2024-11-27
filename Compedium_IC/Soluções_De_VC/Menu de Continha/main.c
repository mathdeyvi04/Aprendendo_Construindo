#include <stdio.h>
#include <math.h>  // para potenciar
#include <stdlib.h>  //para usar o system clear
#include <unistd.h>  //para usar o time

void cabecalho(char *frase, char a) {
    /* Aqui teremos nossa 
    função de cabeçalho padrão */
    
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
    int p,q;
    char opc;
    p = q = 0;
    int contr = 0;
    while(1){
        //Vamos iniciar nosso MENU aqui
        
        
        printf("\033[7m\033[1m");
        cabecalho("Menu de Continhas", '=');
        
        printf("\nP = %d", p);
        printf("\nQ = %d\n\n", q);
        
        printf("\n");
        printf("I - Inserir\n");
        printf("A - adição p+q\n");
        printf("M - multiplicacao p*q\n");
        printf("P - potencializacao p^q\n");
        printf("S - sair\n");
        printf("L - Limpa Tela\n");
        printf("\n");
        printf("Informe a sua decisão: ");
        scanf("%c", &opc);
        
        
        
        
        if(opc == 'S' || opc == 's'){
            //VAmos sair
            printf("\n\n\033[31mSaindo gracinha\033[0m");
            break;
        }
        else{
                if(opc ==  'I' || opc == 'i'){
                    while(p==0 || p<0){
                        printf("\n\nDigite o seu p: ");
                        scanf("%d", &p);
                        if(p==0 || p<0){
                            printf("\n\033[31mDigite um numero maior que zero!\33[0m\033[7m\033[1m");
                        }
                    }
                    
                    while(q==0 || q<0){
                        printf("\n\nDigite o seu q: ");
                        scanf("%d", &q);
                        if(q==0 || q<0){
                            printf("\n\033[31mDigite um numero maior que zero!\33[0m\033[7m\033[1m");
                        }
                    }
                    
                }
                else{
                    if(opc == 'A' || opc == 'a'){
                        //somando
                        printf("\n\nA soma dos dois numeros é %d", p+q);
                        sleep(2);
                    }
                    else{
                        if(opc == 'M' || opc == 'm'){
                            //multiplicação
                            printf("\n\nA multiplicação dos dois numeros é %d", p*q);
                            
                            sleep(2);
                            
                        }
                        else{
                            if(opc == 'P' || opc == 'p'){
                            //potencialização
                                printf("\n\nA potencialização dos dois numeros é %d", (int)pow(p, q));
                                sleep(2);
                            }
                            else{
                                if(opc == 'L' || opc == 'l'){
                                    //somando
                                    system("clear");
                                    
                                }
                                else{
                                    printf("\n\033[31mDigite opção valida!\33[0m\033[7m\033[1m");
                                }
                                
                            }
                            
                        }
                    
                    }
                
                
                
                }
            
        

        }
        
        
        
        printf("\n\n\n\n Terminei a execção %d", contr);
        contr++;
        
    }

    return 0;
}






