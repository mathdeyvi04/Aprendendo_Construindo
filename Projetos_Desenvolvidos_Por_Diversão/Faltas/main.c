#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define limite 105  

//Lembre-se de mudar
char arquivo[] = "turmaalpha.txt";


/*//////////////////////////////////////////////////////////////////////

Não mexe no codigo meu consagrado ou consagrada

ATENÇÃO COM NOMES COM INICIAIS IGUAIS, VOCE DEVE DIGITAR ATE 
A DIFERENÇA SAFAMENTE.

*///////////////////////////////////////////////////////////////////////



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


int verificando(char *nome, char *pessoa){
    //vamos precisar comparada cada caractere
    
    
    if(nome[0] == '\0'){
        //printf("safei");
        return 0;
    }
    
    
    int i = 0;
    
    while(1){
        char c1 = tolower(nome[i]);
        char c2 = tolower(pessoa[i]);
        
        
        if(c1 == '\0'){
            //chegamos ate o final da carteada sem dar erro, logo fim
            return 1;
        }
        
        
        
        
        if(c1 != c2){
            return 0; //são diferentes
        }
        
        i++;
    }

}

int primeiravez(){
    
    //vamos criar o arquivo
    
    char nome[30];
    printf("Informe o nome que deseja para a lista(COLOQUE .txt no final): ");
    scanf("%[^\n]", nome); getchar();
    
    //vamos confiar no usuário
    FILE *abrindo;
    
    abrindo = fopen(nome, "a+");
    
    int a = 0;
    char final[10] = "fim";
    printf("\n(Digite 'fim' para Encerrar, após isso, apenas mudanças diretas no arquivo.txt serão aceitas.\n");
    while(1){
        //Pegando um nome
        char militar[20];
        printf("\nDigite um militar: ");
        scanf("%[^\n]", militar);getchar();
        //printf("\nEstou compreendendo %s", militar);
        
        
        if(!strcmp(militar, final)){
            //printf("acaebeiu");
            break;
        }
        else{
            
            int opc;
            printf("Deseja realmente adicionar este(0-não): ");
            scanf("%d", &opc); getchar();
            
            if(opc){
                //vamos adicionar o nome
                if(a == 0){ //quer dizer que será o primeiro
                    fprintf(abrindo, "%s", militar);
                    a++;
                }
                else{
                    fprintf(abrindo, "\n%s", militar);
                }
            }
        }
        
        
    }
    
    
    printf("\n\nPronto, agora faça a mudança no nome da variável arquivo no inicio do codigo");
    
    
    
    return 0;
}


int main()
{
    
    //Para caso seja a primeira vez de execução
    {
        FILE *testando;
        
        
        testando = fopen(arquivo, "r");
        
        //Não usa fclose pois se ele não existe não tem como fechar
        
        if(testando == NULL){
            //printf("Executando pela primeira vez então");
            
            primeiravez();
            
            return 0;
            
        }
        else{
            //printf("abriu");
            
            
        }
        
        
    }

    
    

    char totais[limite][30];  //Armazem de 500 slots
    int Q = 0;
    {
        printf("\033[7m\033[1m\033[35m");
        
        FILE *militares;
            
        militares = fopen(arquivo, "r");
        
        int i = 0;
        char pessoa[30];
        
        void comparar(char *nome){
                
                for(int p = 0; p < i; p++){
                    //com isso vamos variar cada nome que ja esta incluido
                    
                    int count = 0;
                    int x = 0;
                    
                    while(1){
                        
                        
                        char c1 = tolower(nome[x]);
                        char c2 = tolower(totais[p][x]);
                        
                        if(c1 == c2){
                            count++;
                        }
                        else{
                            break;
                        }
                        
                        x++;
                    }
                    
                    if(count >= 3){
                        printf("Os militares %s e %s possuem nomes muito parecidos.\nTente mudar a letra inicial deles, Ou tome cuidado\n", nome, totais[p]);
                    }
                    
                    
                }
                
                
            }
        
        
        while(!feof(militares)){
                fgets(pessoa, 30, militares);
                
                //printf("%s", pessoa);
                
                //queremos facilitar a vida do subchefe/subxerife
                //sendo assim:
                
                //Eu sou muito foda serio
                int p = 0;
                while(pessoa[p] != '\n'){
                    totais[i][p] = pessoa[p];
                    p++;
                }
                totais[i][p] = '\0';
                
                //Ja fizemos o tratamento dos nomes.
                
                
                //Vendo para avisar que tem dois com nomes parecidos
                comparar(totais[i]);
                
                
                i++;
                
            }
        
        Q = i;
        
        fclose(militares);
        /*
        printf("\n");
        for(int j = 0; j < i; j++){
            printf("%s\n", totais[j]);
        }
        */
    }
    
    printf("\033[0m\033[1m\033[7m");
    
    
    //Primeiro, vamos precisar de um menu mostrando o nome das pessoas
    //que faltam chegar!
    
    char chegaram[Q][20];
    char serviços[15][20];
    
    int i_chega = 0; //Apenas para controle e ficar safo
    int i_ser = 0; 
    int primeiro = 1;
    
    while(1){
        
        cabecalho("Faltas", '*');
        printf("\n");
        
        int falta(char *militar){
            //devemos ver ele chegou a forma ou não
            
            
            for(int j = 0; j < i_chega; j++){
                
                if(!strcmp(militar, chegaram[j])){
                    
                    //se acharmos a pessoa na lista dos que chegaram
                    
                    return 0; //ela não esta em falta
                    
                }
            }
            
            
            return 1; //sim esta faltando
        }
        
        int serviço(char *militar){
            //devemos ver se esta de serviço
            
            for(int j = 0; j < i_ser; j++){
                
                if(!strcmp(militar, serviços[j])){
                    
                    
                    return 1; //ele esta no serviço
                    
                }
            }
            
            
            
            
            return 0; //não estara em serviço
        }
        
        int achando(char *pessoa){
            for(int j = 0; j < Q; j++){
                if(verificando(pessoa, totais[j])){
                    //quer dizer que eu achei a pessoa na lista total
                        
                    //daqui deveremos inserir a pessoa na lista de serviço
                    return j;
                        
                }
            }
                
            return -1; //pessoa não existe
        }
        
        
        //vamos precisar mostrar o nome dos militares que não foram citados e 
        //colorir os de serviço
        {
            //Vamos varrer a lista das pessos e verificar se elas estao
            //ou faltando ou de serviço
            printf("\033[32m");
            for(int p = 0; p < Q; p++){
                
                if(falta(totais[p])){
                    if(serviço(totais[p])){
                        printf("\033[33m%s\n\033[0m\033[1m\033[7m\033[32m", totais[p]);
                    }
                    else{
                        printf("%s\n", totais[p]);
                    }
                }
                
                
            }
            printf("\033[33m\nAmarelo - Serviço\033[0m\033[1m\033[7m");
            
            
            
            
        }
        
        
        
        
        if(primeiro){
            //devemos pegar primeiro o nome de quem esta de serviço
            
            
            printf("\n\nInsira o nome das pessoas de serviço!!\n");
            printf("Digite ime para encerrar\n\n");
            
            char nome[20];
            int i = 0; //para controle de erro
            char fim[20] = "ime";
            
            while(1){
                
                if(i){
                    //devemos mandar o erro
                    printf("\033[31mPESSOA NÃO REGISTRADA\n\n\033[0m\033[1m\033[7m");
                    i--;
                }
                
                
                scanf("%[^\n]", nome); getchar();
                fflush(stdin);
                
                if(!strcmp(nome, fim)){
                    
                    break;
                }
                
                
                //devemos ver se o nome digitado existe
                int indice = achando(nome);
                
                if(indice != -1){
                    //vamos adicionar o nome ao serviços
                    
                    int p = 0;
                    while(totais[indice][p] != '\0'){
                        serviços[i_ser][p] = totais[indice][p];
                        p++;
                    }
                    
                    serviços[i_ser][p] = '\0';
                    
                    printf("Pessoa Encontrada Como %s\n\n", totais[indice]);
                    
                    i_ser++;
                    
                }
                else{
                    //a pessoa não foi achada
                    i++;
                }
                
                
                
            }
            
            
            primeiro--;
        }
        else{
            //apos isso apenas vamos nos preocupar com os que chegam
            
            char nome[20];
            printf("\nDigite o nome que chegou: ");
            scanf("%[^\n]", nome); getchar();
            fflush(stdin);
            
            nome[(int)strlen(nome)] = '\0';
            
            int indice = achando(nome);
            
            if(indice != -1){
                //achamos a pessoa
                
                int p = 0;
                while(totais[indice][p] != '\0'){
                    chegaram[i_chega][p] = totais[indice][p];
                    p++;
                }
                
                chegaram[i_chega][p] = '\0';
                
                printf("%s chegou\n", chegaram[i_chega]);
                
                
                i_chega++;
            }
            else{
                //não achamos 
                printf("\033[31mPESSOA NÃO REGISTRADA\n\033[0m\033[1m\033[7m");
                
            }
            
        }
        
        
        
        //Tava dando pau em algum computador ae
        system("clear");
        
        
    }
    
    
    
    
    
    printf("\033[0m");

    return 0;
}


