#include <stdio.h>





int main(){
    int L=1;
    int u=1;
    //Entrada
    while ((L%6) != 0){
        printf("Digite a altura que vc quer, deve ser múltipla de 6:");
        scanf("%d",&L);
        if ((L%6)!= 0){
            printf("\033[31m\033[1m\nOpcao Invalida\033[0m\n");
        }
    }
    
    printf("\n\n\033[7m\033[1m");

    
    
    
    float n=L/3;
    
    for ( int i=1; i<=L; i++){
        // Vai dizer qual linha estamos
        // cada loop trabalharemos 1 linha 
        
        if (n >= i){
            
            // Os respectivos espaços vazios
            for (int i_1=n-i;i_1>0;i_1--){
                printf(" ");
            }
            //Imprimir as linhas
            for (int i_2=L-(n-i); i_2>0;i_2--){
                printf("*");
            }
            printf("\n");
            
            
        }
        
        
        if ((n < i)&&(2*n>=i)){
            //Fara as impressoes medianas
            for( int i_3=1; i_3<=L/2;i_3++){
                printf("*");
            }
            printf("\n");
        }
        
        
        if ((2*n < i)&&(i <=L)){
            //ISSO AQUI DEU MT TRABALHO
            //vazios
            for(int i_4=i-2*n-(u-1); ((u!=1)&&(i_4<=u-1));i_4++){
                printf(" ");
                //printf("%d", u);
                
            
            }
            
            
            u++;
            
            // Preenchendo
            for(int i_5=i-2*n; i_5<L+1; i_5++){
                printf("*");
            }
           
            
            
            
            printf("\n");
            
        }
        
        
        
    }
    printf("\033[0m");
    
    return 0;
}







