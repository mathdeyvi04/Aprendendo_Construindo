#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    //FASE INICIAL: RECEBENDO INFORMAÇAO
    char nome[100];
    printf("Digite a frase(COLOQUE '/' ONDE QUISER ESPACO) que deseja criptografar: ");
    scanf("%s", nome);
    
    //Configuraçoes 
    for(int i=0; nome[i]!='\0';i++){
        //Colocando Espaços
        if (nome[i] == '/'){
            nome[i] = ' ';
        }
        
        
        //Transformando para seguinte
        if (nome[i] >= 'a' && nome[i] <= 'y'){
            nome[i]=nome[i]+1;
        }
        else{
            //precisamos ver se a letra è maiuscu
            if (isupper(nome[i])){
                nome[i] = tolower(nome[i]);
                if (nome[i] >= 'a' && nome[i] <= 'y'){
                   nome[i]=nome[i]+1;
                   
                }
                else if(nome[i]=='z'){
                    nome[i]='a';
                }
                
                nome[i] = toupper(nome[i]);
              
                
            }
            
            if (nome[i]=='z'){
                nome[i]='a';
            }
        }

        
        //Invertendo Tamanho
        if (isupper(nome[i])){
            nome[i] = tolower(nome[i]);
        }
        else if(islower(nome[i])){
            nome[i] = toupper(nome[i]);
        }
        
        
    
        

        
    }
    
    
    int tam=strlen(nome);
    if (tam%2==0){
        
        for(int i=0;nome[i]!='\0'; i =i +2){
            if (nome[i]!=' ' && nome[i+1]!=' '){
                char p1=nome[i];
                nome[i]=nome[i+1];
                nome[i+1]=p1;
            }
        }
    }
    else{
        for(int i=0;nome[i+1]!='\0'; i =i +2){
            if (nome[i]!=' ' && nome[i+1]!=' '){
               char p1=nome[i];
               nome[i]=nome[i+1];
               nome[i+1]=p1;
            }
        }
    }
    
    
    
    
    printf("\nA palavra criptografada é %s",nome);
    
    
    
    return 0;
}



