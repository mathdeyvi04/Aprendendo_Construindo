#include <stdio.h>

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
    /*Vamos considerar que há apenas esses 5 times disputando a brincadeira*/
    char times[5] = {'A', 'B', 'C', 'D', 'E'};
    FILE *partidas;
    partidas = fopen("dados.txt", "r");
    
    
    int resultados[5][3];
    //Precisamos zerar cada um desses espaços
    int *p;
    p = resultados[0];
    for(int i=0; i<15; i++){
        *p=0;
        p++;
    }
    
    //Usando ponteiros pondemos mdar matrizes facilmente
    

    while(!feof(partidas)){
        /*A cada linha, temos uma partida, percebeu? Vamos precisar guardar as 
        informações. Vamos guardar os pontos totais, o numero de vitorias, e o average.
        Desse jeito, 
        resultados = {[Time A], [Time B], [Total_pontos, Vitorias, average(media de sets)] ...}
        
        Ex:
        resultados[2][1] = numero de vitorias
        */
        
        char Linha[100];
        fgets(Linha, 100, partidas);
        
        int time1 = Linha[0] - 65;
        int time2 = Linha[4] - 65;
        
        
        int p_1 = Linha[2] - 48;
        int p_2 = Linha[6] - 48;
        
        
        if(p_1 > p_2){
            //printf("O time %c venceu\n", Linha[0]);
            //time 1 venceu a bagaça, 
            resultados[time1][1]++; 
            
            resultados[time1][2] += p_1;
            resultados[time2][2] += p_2;
            
            int d = p_1-p_2;
            
            if(d==3 || d ==2){
                
                resultados[time1][0] += 3;
            }
            else{
                //Houve vitoria de 3x2
                
                resultados[time1][0] += 2;
                resultados[time2][0] += 1;
            }
            
            
        }
        else{
            //printf("O time %c venceu.\n", Linha[4]);
            //Time dois venceu
            resultados[time2][1]++;
            
            resultados[time1][2] += p_1;
            resultados[time2][2] += p_2;
            
            int d = p_2-p_1;
            
            if(d==3 || d ==2){
                
                resultados[time2][0] += 3;
                
            }
            else{
                //Houve vitoria de 3x2
                resultados[time2][0] += 2;
                resultados[time1][0] += 1;
                
                
            }
            
        }
        
        
        
       
    }
    
    
    
    
    fclose(partidas);
    
    
    
    
    
    float creditos_nao_ord[5];
    float creditos[5];
    for(int m=0; m<5; m++){
        creditos[m] = (resultados[m][0]*0.7 + resultados[m][1]*0.2 + ((float)resultados[m][2]/4)*0.1);
        //printf("time %c com %f credito\n", times[m], creditos[m]);
        creditos_nao_ord[m] = (resultados[m][0]*0.7 + resultados[m][1]*0.2 + ((float)resultados[m][2]/4)*0.1);
    }
    
    
    
    
    //Como vamos colocar os 5 numeros em ordem....?
    void ordenando(float arr[], int n) {
        int i, j;
        float temp;
        for (i = 0; i < n-1; i++) {
            for (j = 0; j < n-i-1; j++) {
                if (arr[j] < arr[j+1]) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    
    ordenando(creditos, 5);
    
    
    int ordem[5];
    
    for(int k=0; k<5; k++){
        //Esse for é para varrermos os creditos ja ordenados
        for(int k_=0; k_<5; k_++){
            //Esse for é para sabermos em qual posição da lista tradicional cada classficado estao
            if(creditos[k] == creditos_nao_ord[k_]){
                ordem[k] = k_;
            }
                
        }
    }
    
    //De posse das classificações, podemos tabelar
    
    
    
    //Prompt
    {
    printf("\033[7m\033[1m");
    
    cabecalho("Classificação", '=');
    
    printf("\nTimes --- Final --- Pont --- Vit --- Aver\n");
    
    for(int j=0; j<5; j++){
        printf("  %c       %.2f       %d        %d      %.2f\n", times[ordem[j]],
                                                                creditos[j], 
                                                                resultados[ordem[j]][0],
                                                                resultados[ordem[j]][1], 
                                                                (float)resultados[ordem[j]][2]/4);
    }
    
    
    printf("\033[0m");
    }
    
    
    
    //Classificação.txt
    
    {
        FILE *class;
        
        class = fopen("classificacao.txt", "w+");
            
        fprintf(class, "Times --- Final --- Pont --- Vit --- Aver\n");
        
        for(int j=0; j<5; j++){
        fprintf(class, "  %c       %.2f       %d        %d      %.2f\n", times[ordem[j]],
                                                                creditos[j], 
                                                                resultados[ordem[j]][0],
                                                                resultados[ordem[j]][1], 
                                                                (float)resultados[ordem[j]][2]/4);
        }
        
    
    
    
    
    
    
    
    
        fclose(class);
    }
    
    
    
    return 0;
}
