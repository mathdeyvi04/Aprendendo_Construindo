#include <stdio.h>


int LIM = 10000;
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
    
    printf("%*s %s", espaco, "", frase);
    
    printf("%*s\n", espaco-1, "");
    
    for (i=0 ;i < tamanho+20; i=i+1) {
    
        printf("%c", a);
        
    }
    
    printf("\n");
}



int eh_primo(int a){
    //Vai dizer se e primo ou nao
    for (int i=2; i<a;i++){
        if(a%i==0){
            //printf("Nao e primo, seu primeiro divisor eh %d", i);
            return 0;
        }
    }
    
    //printf("E primo");
    return 1;
}

int exibe_pa(int a, int k, int n){
    
    int pa[50];
    
    // termo inicial
    pa[0] = a;
    
    // adicionando 
    for(int i=1; i<=n; i++){
        if (i==1){
            printf("[");
        }
        if (i==n){
            pa[i]=a + i*k;
            printf("%d", pa[i-1]);
            break;
        
            
        }
        pa[i]=a + i*k;
        printf("%d,", pa[i-1]);
        
        
    }
    
    printf("]\n");
    
    return 0;
}

int max_num_primos(int a, int k){
    
    if (!eh_primo(a)){
        //printf("O primeiro nao é primo");
        return 0;
    }
    else{
        int pa[50];
        int quant=0;
        
        for (int i=0;i<50;i++ ){
            if(eh_primo(a+k*i)){
                pa[i]=a+k*i;
                quant ++;
                
            }
            else{
                break;
                
            }
            
        }
        
        /*
        for(int m=0; pa[m]!='\0'; m++){
            printf("%d\n",pa[m]);
        }
        */
        
        //exibe_pa(a, k, quant);
        //printf("Podemos escrever %d assim", quant);
    
        return quant;
        
        
    }
    
    
    
    
    
    
    
}





int main()
{
    printf("\033[7m\033[1m");
    cabecalho("Achando P.A de primos", '*');
    int quant=0;
    int n=0;
    printf("\nIndique uma quantidade de numeros que deseja na P.A:");
    scanf("%d", &n);
    printf("\nA seguir, todas as PA's de primos que possuem a1 e razao menores que %d:\n\n", LIM);
    
    for(int a1=1; a1<=LIM;a1++){
        // Variando o termo inicial
        
        for(int k=1; k<=LIM; k++){
            //Variando a razao
            if(max_num_primos(a1, k)==n){
                //Achamos uma P.A. que inicia com a1, tem razao k e tem n elementos
                
                exibe_pa(a1, k, n);
                printf("De razao %d",k);
                printf("\n\n");
                quant++;
            }
            
            
            
        }
        
        
        
        
        
        
        
        
    }
    
    
    
    
    
    printf("\n\nNo total, há %d PA's", quant);
    
    printf("\033[0m");
    return 0;
}





