#include <stdio.h>
#include <unistd.h>

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

int menu(){
    printf("\n");
    printf("\nDgt 1 para Informar Novos Dados");
    printf("\nDgt 2 para obter Diametro Ramal Predial");
    printf("\nDgt 3 para sair");
    
    
    return 0;
}

int tabela(int u_a, int j, int g){
    int c_a=200*2*u_a;
    float c_j=1.5*j;
    int c_g=50*g;
    float consumo= c_a+c_j+c_g;
    
    printf("\n=====================================");
    printf("\nInstalacão      Unidades   Consumo");
    printf("\nApartamentos        %d         %d   ", u_a, c_a);
    printf("\nJardins             %d        %.1f ", j, c_j);
    printf("\nGaragem             %d        %d   ", g, c_g);
    printf("\n  %*s \n", 34, "");
    printf("Consumo Total Diario(L): %.1f %*s ", consumo, 10, "");
    printf("\n=====================================");
    
    return consumo;
}


int main(){

    int opcao=0;
    int u_a=0;
    int j=0;
    int g=0;
    
    printf("\033[7m\033[1m");
    while (1){
        
        printf("\n\n\n\n");
        cabecalho("Sistema Hidraulico", '*');
        float consumo = tabela(u_a,j,g);
        menu();
        printf("\n\nDigite sua opcao:");
        scanf("%d", &opcao);
        
        if(opcao==1){
            printf("\nInforme a quantidade de apartamentos:");
            scanf("%d", &u_a);
            printf("\nInforme a area de jardim:");
            scanf("%d", &j);
            printf("\nInforme a quantidade de automoveis:");
            scanf("%d", &g);
            printf("\n");
            
        }
        
        
        if (opcao==2){
            float con=0.001*consumo;
            int diam;
            if (con<=5){
                diam=15;
            }
            else if(con>5 && con<=10){
                diam=20;
            }
            else if(con>10 && con <=22){
                diam=25;
            }
            else if(con>22 && con <=60){
                diam=40;
            }
            else if(con>60 && con <=140){
                diam =50;
            }
            else if(con>140 && con <= 300){
                diam=75;
            }
            else{
                diam = 100;
            }
            
            
            printf("\nO diametro necessario é %d", diam);
            
            
            
        }
        
        
        if (opcao==3){
            
            break;
        }
        
        
        
        sleep(3);
        
    }
    











    printf("\n\nSaindo Imediatamente...");
    printf("\033[0m");
    
    return 0;
}






