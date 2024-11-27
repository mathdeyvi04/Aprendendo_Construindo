#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Aqui realizaremos o simulado em nosso tempo recorde*/


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
    printf("\033[7m\033[1m");
    cabecalho("DUNGEONS AND DRAGONS", '*');
    const int min = 10;
    
    int opc;
    while(1){
        //Menu carteado
        
        printf("\n\nInforme a quantidade de jogadas: ");
        scanf("%d", &opc);
        
        if(opc < min){
            printf("\n\033[31mQuantidade de jogadas muito pequena!\033[0m");
            return 0;
        }
        else{
            
            break;
            
        }
        
        
        
    }
    //Ja temos a quantidade de jogadas
    
    
    
    
    int esco;
    while(1){
        printf("\n\n(1-Cubos)(2-Dodecaedro)");
        printf("\nInforme a forma de sortear do jog A: ");
        scanf("%d", &esco);
        
        if(esco==1){
            //A fica com dois dados e B com o dodecaedro
            break;
        }
        else{
            
            if(esco==2){
                //A com o dodecaedro e B fica com cubos
                break;
            }
            else{
                printf("\n\033[31mInvalido!\033[0m\033[7m\033[1m");
            }
            
        }
    }
    //Temos a forma de cada um
    
    
    srand(time(NULL)); //Aqui mudamos a semente da função aleatoria
    
    //Agora devemos executar as rodadas
    
    int total_A = 0;
    int total_B = 0;
    int rodada = 1;
    int vit_A=0;
    int vit_B=0;
    while(rodada<=opc){
        
        //Rodadas
        printf("\n\nRodada %d", rodada);
        
        if(esco == 1){
            //A esta com cubos e B com dode
            
            int A_1 = rand()%6 ;
            int A_2 = rand()%6 ;
            int somaA = A_1 + A_2;
            
            int somaB = rand()%12;
            
            if(somaA > somaB){
                printf("\nO jogador A venceu essa rodada, pois A(%d) > B(%d)", somaA, somaB);
                vit_A++;
                
            }
            else{
                if(somaB> somaA){
                    printf("\nO jogador B venceu essa rodada, pois B(%d) > A(%d)", somaB, somaA);
                    vit_B++;
                }
                else{
                    //Houve empate
                    printf("\nHouve um \033[32mempate\033[0m\033[7m\033[1m entre os jogadores");
                }
            }
            
            total_A += somaA;
            total_B += somaB;
            
            
            
            
        }
        
        if(esco == 2){
            //A esta com dode e B com cubos
            
            int B_1 = rand()%6 ;
            int B_2 = rand()%6 ;
            int somaA = rand()%12;
            
            int somaB = B_1 + B_2;
            
            if(somaA > somaB){
                printf("\nO jogador A venceu essa rodada, pois A(%d) > B(%d)", somaA, somaB);
                vit_A++;
                
            }
            else{
                if(somaB> somaA){
                    printf("\nO jogador B venceu essa rodada, pois B(%d) > A(%d)", somaB, somaA);
                    vit_B++;
                }
                else{
                    //Houve empate
                    printf("\nHouve um \033[32mempate\033[0m\033[7m\033[1m entre os jogadores");
                }
            }
            
            total_A += somaA;
            total_B += somaB;
            
            
            
            
        }
        
        
        
        
        
        rodada++;
    }
    
    
    
    //Aqui vamos colocar o placar
    printf("\033[35m");
    if(esco==1){
        //A esta com cubos
        
        if(total_A > total_B){
            printf("\n\nO jogador A(cubos) venceu o jogador B(dodecaedro)\n");
            printf("A_vitorias = %d e Total_A = %d\n", vit_A, total_A);
            printf("B_vitorias = %d e Total_B = %d", vit_B, total_B);
        }
        else{
            printf("\n\nO jogador A(cubos) perdeu para o jogador B(dodecaedro)\n");
            printf("B_vitorias = %d e Total_B = %d\n", vit_B, total_B);
            printf("A_vitorias = %d e Total_A = %d", vit_A, total_A);
            
        }
    }
    else{
        //A esta com dodecaedro
        if(total_A > total_B){
            printf("\n\nO jogador A(dodecaedro) venceu o jogador B(cubos)\n");
            printf("A_vitorias = %d e Total_A = %d\n", vit_A, total_A);
            printf("B_vitorias = %d e Total_B = %d", vit_B, total_B);
        }
        else{
            printf("\n\nO jogador A(dodecaedro) perdeu para o jogador B(cubos)\n");
            printf("B_vitorias = %d e Total_B = %d\n", vit_B, total_B);
            printf("A_vitorias = %d e Total_A = %d", vit_A, total_A);
            
        }
        
    }
    
    
    
    
    
    
    
    
    
    
    
    printf("\033[0m");
    return 0;
}









