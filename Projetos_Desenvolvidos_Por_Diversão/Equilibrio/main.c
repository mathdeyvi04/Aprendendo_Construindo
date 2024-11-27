#include <stdio.h>

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

//                 VE1, VC, VE2, VF
double fisica[4] = {4.3, 7.4, 0, 0};
double alglin[4] = {6.8, 6.2, 0, 0};
double calculo[4]= {5.8, 5, 0, 0};
double quimica[4]= {8.3, 4.5, 0, 0};
double GD[4]     = {8.3, 6.8, 0, 0};

const int num_mat = 5;

/*
Essas são carteadas

double C[3] = { 0, 0, 0}; 
double lab_fis[5];
double lab_quim[5];

*/


int
main ()
{
    printf ("\033[1m\033[7m");
    
    
    //Apresentação
    {
        cabecalho("Equilibrio de Notas", '*');
        
        
        printf("\nMATERIAS-----VE1-----VC-----VE2-----VF-----MEDIA\n");
        printf("\n");
        
        printf("\nFisica");
        {
            for(int i = 0; i < (13 - 6); i++){
                printf("-");
            }
            printf("%.1lf", fisica[0]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            printf("%.1lf", fisica[1]);
            
            for(int i = 0; i < (4); i++){
                printf("-");
            }
            printf("%.1lf", fisica[2]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            printf("%.1lf", fisica[3]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            double media = (0.125)*fisica[0] + (0.25)*fisica[1] + (0.125)*fisica[2] + (0.5)*fisica[3];
            printf("%.1lf", media);
            
            
            
            
            
            
            printf("\n");
        }
        
        printf("\nALgLin");
        {
            for(int i = 0; i < (13 - 6); i++){
                printf("-");
            }
            printf("%.1lf", alglin[0]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            printf("%.1lf", alglin[1]);
            
            for(int i = 0; i < (4); i++){
                printf("-");
            }
            printf("%.1lf", alglin[2]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            printf("%.1lf", alglin[3]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            double media = (0.125)*alglin[0] + (0.25)*alglin[1] + (0.125)*alglin[2] + (0.5)*alglin[3];
            printf("%.1lf", media);
            
            printf("\n");
        }
        
        printf("\nCalculo");
        {
            for(int i = 0; i < (12 - 6); i++){
                printf("-");
            }
            printf("%.1lf", calculo[0]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            printf("%.1lf", calculo[1]);
            
            for(int i = 0; i < (4); i++){
                printf("-");
            }
            printf("%.1lf", calculo[2]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            printf("%.1lf", calculo[3]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            double media = (0.125)*calculo[0] + (0.25)*calculo[1] + (0.125)*calculo[2] + (0.5)*calculo[3];
            printf("%.1lf", media);
            
            printf("\n");
        }
        
        printf("\nQuimica");
        {
            for(int i = 0; i < (12 - 6); i++){
                printf("-");
            }
            printf("%.1lf", quimica[0]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            printf("%.1lf", quimica[1]);
            
            for(int i = 0; i < (4); i++){
                printf("-");
            }
            printf("%.1lf", quimica[2]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            printf("%.1lf", quimica[3]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            double media = (0.125)*quimica[0] + (0.25)*quimica[1] + (0.125)*quimica[2] + (0.5)*quimica[3];
            printf("%.1lf", media);
            
            printf("\n");
        }
        
        printf("\nGD");
        {
            for(int i = 0; i < (17 - 6); i++){
                printf("-");
            }
            printf("%.1lf", GD[0]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            printf("%.1lf", GD[1]);
            
            for(int i = 0; i < (4); i++){
                printf("-");
            }
            printf("%.1lf", GD[2]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            printf("%.1lf", GD[3]);
            
            for(int i = 0; i < (5); i++){
                printf("-");
            }
            double media = (0.125)*GD[0] + (0.25)*GD[1] + (0.125)*GD[2] + (0.5)*GD[3];
            printf("%.1lf", media);
            
            printf("\n");
        }
        
    }
    
    
    






    printf ("\033[0m");
    return 0;
}


