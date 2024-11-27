#include <stdio.h>
#include <math.h>

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





int main()
{
    printf("\033[7m\033[1m");
    cabecalho("Controle Anti-Aereo",'*');
    
    //Condicoes do Inimigo
    float h,u;
    printf("\033[0m\033[31m\033[1m");
    printf("\nAltura do AeroInimigo:");
    scanf("%f", &h);
    printf("\nVelocidade do AeroInimigo:");
    scanf("%f", &u);
    printf("\033[0m");
    printf("\033[7m\033[1m");
    
    //Condiçoes do Projetil
    float v;
    float g=9.8;
    printf("\nVelocidade do Projetil:");
    scanf("%f", &v);
    
    printf("\n\n");
    
    // Obtendo angulo de tiro 
    float k = acos(u/v);
    float k_graus=180*(k/3.1415);
    
    
    // Obtendo o tempo ate impacto
    float vy=v*sin(k);
    float T=(vy-sqrt((vy*vy)-2*g*h))/g;
    
    //Obtendo a distancia ate o impacto
    float dist = u*T;
    
    if(T>0){
        printf("\nO INIMIGO PODE SER ABATIDO\n");
        printf("\nProjetil deve ter uma angulacao de %.1f g", k_graus);
        printf("\nDemorará um tempo de %.2f seg", T);
        printf("\nAs coordenadas de impacto: (%.2f,%.2f)", dist, h);
    }
    else{
        float H=((vy*vy)/(2*g));
        float Temp= vy/g;
        printf("\nNao sera possivel neutralizar o inimigo nessas condicoes\n");
        printf("\nEntretanto, a maxima altura é (%.2f,%.2f) e ocorre em %.2fs", u*Temp,H, Temp);
    }
    
    
    
    
    
    
    printf("\033[0m");
    return 0;
}



