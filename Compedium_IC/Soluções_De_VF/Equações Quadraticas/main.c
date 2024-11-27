#include <stdio.h>
#include <stdlib.h>




int main()
{
    //Primeiro devemos ser capazes de ler as equações
    
    FILE *entrada;
    
    entrada = fopen("registro.txt", "r");

    int resultados[50]; //Vamos guardar os resultados de 2, 1, 0; 
    //Que é o que desejamos, SÓ VAMOS PODER TER ATÉ A 50º linha
    int total_2 = 0;
    int total_1 = 0;
    int total_0 = 0;
    
    
    
    int identificador = 0; //O qual vamos definir como a posição dos resultados, ele é literalmente a linha
    
    
    while(!feof(entrada)){
        char Linha[100];
        fgets(Linha, 100, entrada); //Pegamos cada linha de forma integral
        
        /*Note que se fossem apenas algarismos, poderiamos prever trivialmente e 
        nosso problema acabaria facilmente, mas não é isso que queremos não é?*/
        
        
        
        //printf("Estou na linha %d     ", identificador+1);
        int p0 = 0; //Para nos ambientarmos a linha com base os espaços
        //Não sabemos o tamanho dos numeros então usaremos while
        
        
        char inden[5]; //Significa que poderemos ler até a linha 99999(Teoricamente)
        int cont = p0;
        while(1){
            if(Linha[cont] == ' '){
                p0 += cont + 1; //Vamos começar da prox vez apos o espaço
                inden[cont-p0] = '\0';
                break;
            }
            inden[cont-p0] = Linha[cont];
            cont++;
        }

        //Agora, sabemos pular o identiicador e partir para os coeficientes
        
        
        
        
        char coef_A[5];
        
        cont = p0;
        while(1){
            if(Linha[cont] == ' '){
                coef_A[cont-p0] = '\0';
                //printf("Na pos %d eu coloquei o nulo", cont-p0);
                p0 += cont-p0 + 1; //Vamos começar da prox vez apos o espaço
                
                break;
            }
            
            coef_A[cont-p0] = Linha[cont];
            //printf("O numero %c foi guardado na pos %d\n ",Linha[cont], cont-p0);
            cont++;
        }
        int A = atoi(coef_A); //Ja temos nosso coeficiente Lider
        
        
        
        
        
        char coef_B[5];
        cont = p0;
        while(1){
            if(Linha[cont] == ' '){
                coef_B[cont-p0] = '\0';
                //printf("Na pos %d eu coloquei o nulo", cont-p0);
                p0 += cont-p0 + 1; //Vamos começar da prox vez apos o espaço
                
                break;
            }
            
            coef_B[cont-p0] = Linha[cont];
            //printf("O numero %c foi guardado na pos %d\n ",Linha[cont], cont-p0);
            cont++;
        }
        int B = atoi(coef_B); //Outro coeficiente
        
        
        
        
        
        char coef_C[5];
        cont = p0;
        while(1){
            if(Linha[cont] == '\n' || Linha[cont] == '\0'){ //Isso aqui foi insano pra perceber o bug
                coef_C[cont-p0] = '\0';
                //printf("Na pos %d eu coloquei o nulo", cont-p0);
                p0 += cont-p0 + 1; //Vamos começar da prox vez apos o espaço
                break;
            }
            
            coef_C[cont-p0] = Linha[cont];
            //printf("O numero %c foi guardado na pos %d\n ",Linha[cont], cont-p0);
            cont++;
        }
        int C = atoi(coef_C); //Já temos o coeficiente independente
        
        
        
        
        //Já temos tudo que precisamos para avançar e calcular o delta
        
        
        float delta = B*B - 4*A*C;
        //printf("linha %d temos delta = %f\n",identificador, delta);
        
        if(delta>0){
            //Teremos 2 raizes reais
            resultados[identificador] = 2;
            total_2++;
        }
        else{
            if(delta == 0){
                //Temos somente uma raiz real
                resultados[identificador] = 1;
                total_1++;
                
            }
            else{
                //Não teremos raizes reais
                resultados[identificador] = 0;
                total_0++;
            }
        }
        
        
        //De posse de tudo que precisavamos, podemos iniciar a segunda parte!
        
        
        
        identificador++;
    }
    
    
    fclose(entrada);
    
    
    //////////////////////////////////////////////////////////////////////////////////////////
    
    
    FILE *saida;
    
    saida = fopen("resultados.txt", "w+");
    
    
    printf("\033[7m\033[1m");
    fprintf(saida, "_______________________________________________________________\n");
    printf("___________________________________________________________________\n");
    fprintf(saida, "_______________________________________________________________\n");
    printf("___________________________________________________________________\n");

    
    
    for(int p=1;p<=identificador;p++){
        printf("%*c", 9, ' ');
        fprintf(saida, "%*c", 9, ' ');
        
        
        
        
        
        printf("Identificador %d - Número de Raizes Reais: %d", p, resultados[p-1]);
        fprintf(saida, "Identificador %d - Número de Raizes Reais: %d", p, resultados[p-1]);
        
        
        
        
        
        
        
        
        printf("%*c", 14, ' ');
        
        printf("\n");
        fprintf(saida, "\n");
    }
    
    printf("%*c", 9, ' ');
    fprintf(saida, "%*c", 9, ' ');
    fprintf(saida, "Total de equacoes com 2 raizes reais: %d\n", total_2);
    printf("Total de equacoes com 2 raizes reais: %d\n", total_2);
    
    
    printf("%*c", 9, ' ');
    fprintf(saida, "%*c", 9, ' ');
    printf("Total de equacoes com 1 raizes reais: %d\n", total_1);
    fprintf(saida,"Total de equacoes com 1 raizes reais: %d\n", total_1);
    
    printf("%*c", 9, ' ');
    fprintf(saida, "%*c", 9, ' ');
    printf("Total de equacoes sem raizes: %d\n", total_0);
    fprintf(saida,"Total de equacoes sem raizes: %d\n", total_0);
    
    
    
    
    
    fprintf(saida, "_______________________________________________________________\n");
    printf("___________________________________________________________________\n");
    fprintf(saida, "_______________________________________________________________\n");
    printf("___________________________________________________________________\n");
    
    
    
    
    
    
    
    fclose(saida);
    
    
    printf("\033[0m");

    return 0;
}
