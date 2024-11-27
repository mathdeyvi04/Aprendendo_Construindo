#include <stdio.h>
#include <string.h>

/*
Vamos fazer um software para o estacionamento da guarda

vamos iniciar com a placa, responsavel e caracteristicas do carro.

sempre que surgir um carro novo, vamos colocá-lo no historico e da prox vez
bastara digitar a placa como se fosse novo, mas o sistema mostrara no historico

Lembre que devemos ter uma tabela mostrando os carros que estão em disposição no estacionamento
no momento e retirá-los quando sair

MODELO DE PLACA = qualquer um com maximo de 5 letras

*/

const int vagas = 50;


typedef struct carro_{
    char placa[5];
    char responsavel[20];
    char caracteristicas[100];
    
}carro;






void cabecalho(char *frase, char a); 


int main()
{
    
    printf("\033[32m\033[7m");
    
    carro carros[vagas];
    int quant = 0; //para organizar quantos carros tem
    carro presentes[vagas];
    
    
    //devemos pegar as informações do historico 
    int hist = 0;
    {
        FILE *historico;
        
        historico = fopen("historico.txt", "r");
        
        char linha[100];
        int j = 0;
        while(!feof(historico)){
            fgets(linha, 100, historico);
            
            int i = 0;
            int m = 0;
            while(linha[i] != ','){
                carros[j].placa[m] = linha[i];
                if(linha[i+1] == ','){
                    carros[j].placa[m+1] = '\0';
                }
                i++;
                m++;
            }
            i++;
            //printf("%s\n", carros[j].placa);
            
            m = 0;
            while(linha[i] != ','){
                carros[j].responsavel[m] = linha[i];
                if(linha[i+1] == ','){
                    carros[j].responsavel[m+1] = '\0';
                }
                m++;
                i++;
            }
            i++;
            //printf("%s\n", carros[j].responsavel);
            
            
            m = 0;
            while(linha[i] != '.'){
                carros[j].caracteristicas[m] = linha[i];
                if(linha[i+1] == ','){
                    carros[j].caracteristicas[m+1] = '\0';
                }
                m++;
                i++;
            }
            //printf("%s\n", carros[j].caracteristicas);
            
            j++;
            hist++;
        }
        
        
        fclose(historico);
    }
    
    void apresentação(int n){
        printf("Placa ----- Responsavel ----- caracteristicas");
        
        for(int i = 0; i < n; i++){
            printf("%s", presentes[i].placa);
            printf("%s", presentes[i].responsavel);
            printf("%s", presentes[i].caracteristicas);
            
            
            
            
        }
        
        printf("\n\n");
        
    }
    
    int menu(){
        
        printf("\n1 - Adicionar novo carro");
        printf("\n2 - Retirar carro");
        
        
        int opc = 0;
        do{
            if(opc != 0){
                printf("\033[31mOpção Invalida\033[0m\033[32m\033[7m");
            }
            printf("\nDecida-se: ");
            scanf("%d", &opc);
        }while(opc != 1 && opc != 2);
        
        
        return opc;
    }
    
    //pra consertar bug
    for(int i = 0; i < hist; i++){
        carros[i].placa[5] = '\0';   
    }
    
    
    
    
    while(1){
        //Abrimos nosso MENU
        
        
        cabecalho("Estacionamento", '*');
        printf("\n");
        
        apresentação(quant); //Vamos usar essa função para pegar a lista de carros e apresentar em tabela
        
        
        int opc = menu();
        
        if(opc == 1){
            //vamos adicionar um novo carro ao historico e ao sistema
            
            char placa[5];
            printf("\nInforme a placa do carro: ");
            scanf("%s", placa);
            
            int o = 1;
            //devemos ver se o carro ja esteve no lugar
            for(int i = 0; i < hist; i++){
                //printf("O carro %d tem\n placa = %s\n resp = %s\n carac = %s\n", i, carros[i].placa, carros[i].responsavel, carros[i].caracteristicas);
                if(!strcmp(placa, carros[i].placa)){
                    printf("\nEste carro ja veio aqui\n");
                    int j = 0;
                    while(j < 5){
                        presentes[quant].placa[j] = carros[i].placa[j];
                        j++;
                    }
                    presentes[quant].placa[j] = '\0';
                    
                    
                    j = 0;
                    while(carros[i].responsavel[j] != '\0'){
                        presentes[quant].responsavel[j] = carros[i].responsavel[j];
                        j++;
                    }
                    presentes[quant].responsavel[j] = '\0';
                    
                    
                    j = 0;
                    while(carros[i].caracteristicas[j] != '\0'){
                        presentes[quant].caracteristicas[j] = carros[i].caracteristicas[j];
                        j++;
                    }
                    presentes[quant].caracteristicas[j] = '\0';
                    
                    o--;
                    
                    break;
                    
                    
                }
            }
            
            if(o){
                //ele nao esta no historico
            }
            
            
            //se der certo 
            quant++;
        }
        
        
        
        
        
        
        
        
        
        
        quant++;
    }
    
    
    
    
    
    
    

    return 0;
}


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
};
