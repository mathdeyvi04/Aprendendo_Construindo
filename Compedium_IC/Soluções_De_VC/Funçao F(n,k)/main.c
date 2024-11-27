#include <stdio.h>

// SEM USAR A MATH.H
void cabecalho(char *frase, char a) {
    /* Aqui teremos nossa 
    funçãode cabeçalho padrão */
    
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
    
    printf("%*s %s\n", espaco, "", frase);
    
    
    
    for (i=0 ;i < tamanho+20; i=i+1) {
    
        printf("%c", a);
        
    }
    
    printf("\n");
}

int calcu_poten_mais_prox(int m){
    
    int potencia(int base, int expo){
        int resul=1;
        
        for (int o=1; o<= expo; o++){
            resul *=base;
        }
        
        return resul;
    }
    // teste printf("%d",potencia(2,0));
    int i =0;
    int c=0;
    
    while (1){
        
        c=potencia(2, i);
        
        if (c==m){
            break;
        }
        else{
            
            if (potencia(2,i+1)>m){
                break;
            }
            
        }
        
        i++;
    }
    
    
    
    
    
    
    return c;
}

int main(){
    printf("\033[1m");
    cabecalho("Função F(n,k)", '*');
    int n,k;
    printf("\nDigite um numero NATURAL para n:");
    scanf("%d",&n);
    printf("\nDigite um numero NATURAL para k:");
    scanf("%d",&k);
    
    printf("\nEm instantes forneceremos o valor.\n");
    
    if (n==0){
        printf("\n\033[7mO resultado trivialmente é F(0,%d)=%d", k, 0);
    }
    else{
      //  printf("oi");
          int n_=n;
          int k_=k;
      
      while (1){
          
          
          if (k_==1){
                printf("\n\033[7mO resultado é F(%d,%d)=%d", n,k, calcu_poten_mais_prox(n_));
                break;
          }
          else{
              k_=k_-1;
              int f=calcu_poten_mais_prox(n_);
              n_=n_- f;
              //printf("%d e tbm %d", n_, k_);
              
              
          }
          
      }
        
        
    
        
    }
    
    printf("\033[0m");
    return 0;
}
