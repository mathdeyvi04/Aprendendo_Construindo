#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define Q_ 15 //LEMBRE DE ATUALIZAR O NUMERO DE ALUNOS CASO VC AUMENTE

/*O proposito deste projeto é iniciar um prototipo de um software capaz de automatizar a escala de serviços
do Instituto Militar de Engenharia.*/

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

int transf(char num){
        int q = num-48;
        return q;
        
    }
    
int aumentar_serviço(int p1, int p2, int p3){
    //Daqui, vamos alterar a escala de serviço
    
    FILE *escala;
    char Linha[Q_+2][100];
    char pessoas_esc[3][20];
    int serviço_amais[3];
    
    {
    escala = fopen("escala_semanal.txt", "r");
    
    int i =1;
    
    //Devemos ter uma maneira de analisar as divergencias de quantidade
    
    
    while(!feof(escala)){
        
        char nome[20] = "";
        fgets(Linha[i-1], 100, escala);  
	    
	    
	    if(i!=1){
	        //Vamos ignorar a primeira linha e trabalhar individualmente com cada 
	        
	        int quant;
	        
	        for(int m=0; Linha[i-1][m]!='\n'; m++){
	            if(Linha[i-1][m] == ','){
	                quant = transf(Linha[i-1][m+1]);
	                break;
	            }
	            nome[m] = Linha[i-1][m];
	            
	        }
	        
	        
	        //precisamos pegar as pessoas escolhidas
	        
	        if(i == p1+2){
	            
	            
	            int controle_de_nome = 0;
	            
	            for(int mp = 0; nome[mp] !='\0';mp++){
	                controle_de_nome++;
	                pessoas_esc[0][mp] = nome[mp];
	            }
	            
	            //ESSE CONTROLE DE NOME CONSERTOU UM BUG INSANO QUE EU ESTAVA TENDO COM 
	            //O FINAL DAS PALAVRAS
	            
	            pessoas_esc[0][controle_de_nome] = '\0';
	            
	            serviço_amais[0] = quant;
	        }
	        
	        if(i == p2+2){
	            int controle_de_nome = 0;
	            
	            for(int mp = 0; nome[mp] !='\0';mp++){
	               controle_de_nome++;
    	           pessoas_esc[1][mp] = nome[mp];
    	        }
    	        
    	        pessoas_esc[1][controle_de_nome] = '\0';
    	        
    	        serviço_amais[1] = quant;
    	        
	        }
    	            
	        
	        
	        if(i == p3+2){
	            int controle_de_nome = 0;
	            for(int mp = 0; nome[mp] !='\0';mp++){
	                controle_de_nome++;
	                pessoas_esc[2][mp] = nome[mp];
	            }
	            
	            pessoas_esc[2][controle_de_nome] = '\0';
	            
	            serviço_amais[2] = quant;
	        }
	        
	        
	        
	        //Querermos apenas que ele copie
	        //printf("%s ------------- %d\n", nome, quant); //EU SOU MUITO BOM, RESOLVI O BUG QUE TAVA TENDO COM OS NOMES
	        //Com isso, já temos as informações sobre o nome e a quantidade de serviços.
	        
	        
	    }
	    else{
	        //printf("Militares ------ ServiçosTirados\n");
	    }
	    
	    
	    
        i++;
    }
    
    
    fclose(escala);
    
    }
    
    
    
    
    {
        //Ja copiamos todas as linhas, agora vamos apagar o anterior e reescreve-lo 
        // com as alterações
        
        FILE *escala_nova;
        escala_nova = fopen("escala_semanal.txt", "w");
        
        int cont = 1;
        
        while(cont<=Q_+1){
            //Vamos varrer as linhas 
            
            if(cont==1){
                //primeira Linha
                fprintf(escala_nova, "PESSOAS,Quantidades\n");
            }
            else{
                //Nao esta mais na primeira linha
                
                if(cont-1 == p1+1 || cont-1 == p2+1 || cont-1 == p3+1){
                    //Temos nossos escolhidos para o Serviços
                    if(cont-1 == p1+1){
                        //A pessoa escolhida
                        fprintf(escala_nova, "%s,%d\n", pessoas_esc[0], serviço_amais[0]+1 );
                    }
                    else{
                        if(cont-1 == p2+1){
                            //Segunda pessoa
                            
                            fprintf(escala_nova, "%s,%d\n", pessoas_esc[1], serviço_amais[1]+1 );
                        }
                        else{
                            //Terceira pessoa
                            fprintf(escala_nova, "%s,%d\n", pessoas_esc[2], serviço_amais[2]+1 );
                            
                        }
                        
                    }
                    
                    
                    
                }
                else{
                    //Todos os outros
                    fprintf(escala_nova, "%s", Linha[cont-1]);
                    
                }
                
                
                
                
                
                
                
                
                
                
                
                
                
            }
            
            
            cont++;
        }
        
        fclose(escala_nova);
    }
    
    
    
    
    
    
    
    return 0;
}

int ver_escala(){    
    
        
    FILE *escala;
    char Linha[100];
    
    escala = fopen("escala_semanal.txt", "r");
    
    int i =1;
    
    //Devemos ter uma maneira de analisar as divergencias de quantidade
    
    
    while(!feof(escala)){
        
        char nome[20] = "";
        fgets(Linha, 100, escala);  
	    
	    
	    if(i!=1){
	        //Vamos ignorar a primeira linha e trabalhar individualmente com cada 
	        
	        int quant;
	        
	        for(int m=0; Linha[m]!='\n'; m++){
	            if(Linha[m] == ','){
	                quant = transf(Linha[m+1]);
	                break;
	            }
	            nome[m] = Linha[m];
	            
	        }
	        printf("%s ------------- %d\n", nome, quant); //EU SOU MUITO BOM, RESOLVI O BUG QUE TAVA TENDO COM OS NOMES
	        //Com isso, já temos as informações sobre o nome e a quantidade de serviços.
	        
	        
	    }
	    else{
	        printf("Militares ------ ServiçosTirados\n");
	    }
	    
	    
	    
        i++;
    }
    
    
    fclose(escala);
    return 0;
}

int escolher(int Q){
    
    FILE *escala;
    char Linha[100]; //Daqui, obtemos acesso a cada linha
    
    escala = fopen("escala_semanal.txt", "r+");
    
    int i =1;
    
    //Devemos ter uma maneira de analisar as divergencias de quantidade
    char pessoas[Q][20];
	int serviços[Q];
    while(!feof(escala)){
        
        char nome[20] = "";
        fgets(Linha, 100, escala);  
	    
	    
	    if(i!=1){
	        //Vamos ignorar a primeira linha e trabalhar individualmente com cada 
	        
	        int quant;
	        
	        
	        for(int m=0; Linha[m]!='\n'; m++){
	            if(Linha[m] == ','){
	                quant = transf(Linha[m+1]);
	                serviços[i-2] = quant;
	                pessoas[i-2][m] = '\0';
	                break;
	            }
	            nome[m] = Linha[m];
	            pessoas[i-2][m] = nome[m];
	            
	        }
	        //printf("%s ------------- %d\n", nome, quant); //EU SOU MUITO BOM, RESOLVI O BUG QUE TAVA TENDO COM OS NOMES
	        
	        //Com isso, já temos as informações sobre o nome e a quantidade de serviços.
	        
	        
	        
	        
	        
	        
	    }
	    
	    
	    
        i++;
    }
    fclose(escala);
    /* Comprovando que conseguimos salvar o nome de cada pessoa 
    for(int p=0; pessoas[11][p]!='\0';p++){
        printf("%c", pessoas[11][p]);
    }
    */
    /* Comprovando que conseguimos salvar a quantidade de serviços de cada pessoa
    for(int p=0; p<Q;p++){
        printf("%d\n", serviços[p]);
    }
    */
    
    //Agora devemos escolher as pessoas que vão entrar em serviço
    //Devemos priorizar os que possuem menor quantidade de serviço e os que estão na frente
    int controle = 0;
    int escolhidos[3];
    
    for(int menor = 0; menor<5; menor++){
        for(int p=0; p<Q; p++){
            if(controle<3){
                //Consertei o bug que estava tendo com as verficações
                //printf("Estou comparando a %d\n", menor);
                if(serviços[p]==menor){
                    escolhidos[controle] = p;
                    //printf("%s\n", pessoas[p]);
                    controle++;
                }
            }
        
        }
    }
    
    
    //Ja temos os nossos escolhidos para o serviço
    int opc;
    printf("\n\n\033[31mOs guerreiros para serviço são:\n");
    printf("%s \n", pessoas[escolhidos[0]] );
    printf("%s \n", pessoas[escolhidos[1]]);
    printf("%s \n\033[0m\033[7m\033[1m", pessoas[escolhidos[2]]);
    printf("\n Deseja REALMENTE colocá-los de serviço?(0-nao):  ");
    scanf("%d", &opc);
    
    
    if(opc){
        //Vai executar tudo que deve ser executado
        //A partir das pessoas escolhidas, devemos aumentar em uma unidade a quantidade de serviço.
        
        //aumentar_serviço(escolhidos[0], escolhidos[1], escolhidos[2]);
        int opc_;
        printf("\n Deseja REALMENTE, REALMENTE, REALMENTE colocá-los de serviço?(0-nao)(ATENÇÃO):  ");
        scanf("%d", &opc_);
        if(opc_){
            sleep(1);
            printf("\n\nAtualizando a escala..........\n\n\n");
            system("clear");
            aumentar_serviço(escolhidos[0], escolhidos[1], escolhidos[2]);
        }
        else{
            printf("\nExcelente, safou todos.\n\n");
            sleep(1);
        }
        
    }
    else{
        //Não vai coloca-los de serviço
        printf("\nExcelente, safou todos.\n\n");
        sleep(1);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}


int main()
{
    
    //Obtendo a matrix de pessoas e de serviços
    
    
    
    printf("\033[7m\033[1m");
    while(1){
        //printf("Vlotamos ao inicio");
        cabecalho("Escala de Serviço", '*');
        int a;
        
        ver_escala();
        
        printf ("\n1- Obter Escolhidos");
        printf ("\n0- Sair");

        printf ("\n\nDigite sua opcao:");
        scanf ("%d", &a);
        
        
        if (a==0){
            printf("\n\nF supremo para os guerreiros\n");
            break;
        }
        else{
            if(a==1){
                //A partir da matriz de pessoas e de serviços, vamos ver as divergencias
                //ou não e analisar quem vai ser escolhido
                
                //Só podemos ter 3 pessoas de serviços
                escolher(Q_);
                
                
                
            }
        }
    }
    
    
    
    
    printf("\033[0m");
    return 0;
}
