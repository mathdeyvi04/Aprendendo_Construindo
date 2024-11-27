#include <stdio.h>

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

int verificao(int d, int m, int a){
    
    
    int meses[10]={31, 30, 31, 30, 31, 31, 30, 31,30,31};
    
    
    if(d<=0 || d>31){
        printf("\n\n\033[31m Data inválida!!");
        return 0;
        
    }
    
    if(m<=0 || m>12){
        printf("\n\n\033[31m Data inválida!!");
        return 0;
        
    }
    
    if(a<1900 || a>1999){
        printf("\n\n\033[31m Data inválida!!");
        return 0;
        
    }
    
    //Quer dizer que as datas nao sao absurdas
    
    if (a%4==0){
        //ano e bissexto
        if (m==2){
            //Mes de Fev
            if (d>29){
                printf("\n\n\033[31m Data inválida!!O ano é bissexto, logo d<=29");
                return 0;
        
                
            }
        }
        else{
            if(m==1){
                if(d>32){
                    printf("\n\n\033[31m Data inválida!!");
                    return 0;
        
                }
                
            }else if(d>meses[m-3]){
                printf("\n\n\033[31m Data inválida!! Esse mes nao tem essa quantidade de dias");
                return 0;
        
            
        
            
        }
            
            
        }
    }
        

    else{
        if (m==2){
            //Mes de Fev
            if (d>28){
                printf("\n\n\033[31m Data inválida!!O ano é nao bissexto, logo d<=29");
                return 0;
        
                
            }
        }
        else{
            if(m==1){
                if (d>31){
                
                    printf("\n\n\033[31m Data inválida!!");
                    return 0;
        
            
                }
            }
            
            if (d>meses[m-3]){
                printf("\n\n\033[31m Data inválida!! Esse mes nao tem essa quantidade de dias");
                return 0;
        
            }
        }
    }
        
    
    
    
    
    return 1;
}

int contador(int d, int m, int a){
    
    int d_=1;
    int m_=1;
    int a_=1900;
    int Total=0;
    
    //Anos
    while (a_!=a){
        //vai varrer os anos
        if (a_%4==0){
            //bissexto
            Total+=365;
            
        }
        else{
            //nao bissexto
            Total+=364;
        }
        a_++;
    }
    
    //meses
    while (m_!=m){
        if(a%4==0){
            int meses_b[12]={31,29,31,30,31,30,31,31,30,31,30,31};
            //Aqui esta dando erro, F MathDeyvi
            Total+=meses_b[m_-1]-1;
        }
        else{
            int meses_b[12]={31,28,31,30,31,30,31,31,30,31,30,31};
            //Aqui esta dando erro, F MathDeyvi
            Total+=meses_b[m_-1]-1;
        }
            
        
        
        
        m_++;
    }
    
    //dias
    Total+=d-d_+1;
    
    //printf("\n%d", Total);
    
    
    
    return Total;
}








int main()
{
    printf("\033[7m\033[1m");
    cabecalho("Datas",'*');
    
    int d,m,a;
    
    printf("\nDigite o dia:");
    scanf("%d",&d);
    printf("\nDigite o mes:");
    scanf("%d", &m);
    printf("\nDigite o ano:");
    scanf("%d",&a);
    
    int k= verificao(d,m,a);
    
    if (k){
        
        //Deu tudo certo
        int dia_total= contador(d, m, a)-1;
        
        char *semana[7]={"Domingo","Segunda", "Terça", "Quarta", "Quinta","Sexta", "Sabado"};
        
        
        for(int i=0; i<7; i++){
            if (dia_total%7==i){
              
                //Achamos
                printf("\n\n A data é %s - %d / %d / %d", semana[i], d, m,a);
                return 0;
            }
        }
        
        
        
    }
    else{
        //ruim, ja tem a mensagem na funcao
        return 0;
    }
    
    
    
    
    
    
    
    
    
    
    printf("\033[0m");
    return 0;
}






