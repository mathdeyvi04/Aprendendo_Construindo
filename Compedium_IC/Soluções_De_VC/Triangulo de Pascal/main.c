#include <stdio.h>

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


int fatorial(int a){
    int fat =1;
    for(int i =1; i<=a; i++){
        fat *= i;
    }
    
    // testeprintf("%d", fat);
    return fat;
}


int binomio(int n, int p){
    int b;
    
    b=(fatorial(n))/((fatorial(p))*fatorial(n-p));
    //printf("%d", b);
    return b;
    
}






int main(){
    
    int L;
    printf("\033[7m\033[1m");
    cabecalho("Triangulo de Pascal", '*');
    
    printf("\nDigite ate qual linha vc quer: ");
    scanf("%d", &L);
    printf("\n");
    
    for(int n=0; n<=L; n++){
        //Variando a linha
        for(int p=0;p<=n;p++){
            //Variando coluna
            printf("%d ", binomio(n,p));
            
            
            
            
            
        }
        
        
    printf("\n");
        
        
        
        
    }

    
    
    
    
    
    
    
    
    
    
    printf("\033[0m");
    return 0;
}




