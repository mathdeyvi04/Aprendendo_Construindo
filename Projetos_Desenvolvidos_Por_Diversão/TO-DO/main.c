#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

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




typedef struct afazer{
    int numero;
    char tarefa[100];
    
} tarefas;



int main()
{
    
    
    while(1){
        //Devemos sempre pegar as informações para impedir que não possamos atualizá-las
        
        //Primeiro pegando a quantidade
        int quantidade = 0;
        {
            FILE *pp;
            int q = 1;
            pp = fopen("fazeres.txt", "r");
            char op[5];
            
            while(!feof(pp)){
                fgets(op, 5, pp);
                if(op[0] == '{'){
                    quantidade++;
                }
            }
            //printf("%d", quantidade);
            fclose(pp);
        }
        
        tarefas lista[quantidade];
        {
            FILE *abrindo;
            
            abrindo = fopen("fazeres.txt", "r");
            
            char linha[100];
            
            int i = 0;
            int controle = 0;
            while(!feof(abrindo)){
                fgets(linha, 100, abrindo);
                if(linha[0] == '{'){
                    //Já achamos uma nova tarefa
                    lista[i].numero = i+1;
                    
                    controle = 1;
                }
                
                if(controle){
                    int j = 0;
                    //Quer dizer que estamos vendo uma tarefa agora!
                    if(linha[0] != '}' && linha[0] != '{'){
                        //Vamos ter que igualar cada caractere para Adicionar
                        for(int p=0;linha[p]!='\0' && linha[p] != '\n'; p++){
                            lista[i].tarefa[p] = linha[p];
                            
                            
                            
                            if(linha[p+1] == '\0' || linha[p+1] == '\n'){
                                //printf("Cheguei no fim e a ultima letra é %c\n", lista[i].tarefa[p]);
                                lista[i].tarefa[p+1] = '\0';
                            }
                        }
                        
                    }
                }
                
                if(linha[0] == '}'){
                    //quer dizer fim
                    controle = 0;
                    //printf("%s e também %d\n", lista[i].tarefa,(int)strlen(lista[i].tarefa) );
                    i++;
                }
                
            }
            
            fclose(abrindo);
            
        }
        
        
        
        
        //O app vai rodar aqui 
        
        
        //Primeiro um menu
    
        printf("\033[1m\033[7m\033[36m");
        
        cabecalho("App To-Do", '*');
        
        //Apresentando 
        {
            //Precisamos implementar o \n aqui, logo devemos ver de caractere emc arcatere
            int o=0;
            for(int i=0;i<quantidade;i++){
                printf("\nTarefa %i\n", i+1);
                for(int h=0;lista[i].tarefa[h] != '\0'; h++){
                    printf("%c", lista[i].tarefa[h]);
                    if(lista[i].tarefa[h] == ' '){
                        o++;
                        
                        if(o==6){
                            o = 0;
                            printf("\n");
                        }
                    }
                }
                o = 0;
                printf("\n");
            }
        }
        
        printf("\n\n1 - Adicionar uma nova Tarefa");
        printf("\n\n2 - Remover uma Tarefa");
        
        
        int opc;
        printf("\n\nInforme sua opção: ");
        scanf("%d", &opc);
        __fpurge(stdin);
        
        if(opc == 1){
            //adicionando
            
            {
                char frase[100];
                int i = 0;
                char c = ' ';
                __fpurge(stdin);
                printf("Informe a nova tarefa: ");
               
                /* Lê a entrada caractere por caractere */
                while ((c = getchar()) != '\n') {
                   frase[i] = c;
                   i++;
                }
               
                frase[i] = '\0';
                //printf("%s", frase);
                
                FILE *adicionando;
                
                adicionando = fopen("fazeres.txt", "a+");
                
                i = 1;
                while(1){
                    if(i==1){
                        fprintf(adicionando, "\n{\n");
                        //continue; ESSE AQUI ESTÁ AMODIÇOALDO
                    }
                    if(i==2){
                        fprintf(adicionando, " %s", frase);
                    }
                    if(i==3){
                        fprintf(adicionando, "\n}");
                        break;
                        
                    }
                    
                    
                    
                    i++;
                }
                
                fclose(adicionando);
                
                
            }
            
            
        }
        else{
            if(opc == 2){
                //removendo
                
                {
                    
                    printf("Informe o numero da tarefa que deseja retirar: ");
                    scanf("%d", &opc);
                    
                    
                    
                    
                    
                    //printf("Voce quer que eu exclua %d", opc);
                    
                    FILE *removendo;
                    
                    removendo = fopen("fazeres.txt", "w+");
                    
                    int i = 1;
                    while(1){
                        //Vamos varrer as tarefas
                        if(i == quantidade){
                            break;
                        }
                        if(i!=opc){
                            fprintf(removendo, "{\n%s\n}\n", lista[i-1].tarefa);
                            
                        }
                        
                        i++;
                    }
                    fclose(removendo);
                    
                    
                }
                
                
                
                
                
            }
            else{
                printf("\033[31m\nOpção Inválida\033[36m");
                system("clear");
            }
        }
        
        
        
        
        
        system("clear");
    
    
    
    
    
    }
    
    
    
    
    
    
    printf("\033[0m");
    return 0;
}
