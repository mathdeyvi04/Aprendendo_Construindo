#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


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

int agora(){
    
    
    struct tm *p;
    time_t seconds;

    while(1){
        system("clear");
        time(&seconds);
        p = localtime(&seconds);
        
        printf("\n\n\n\t\t\t\t\t\t\t\t\t%d/%d/%d %d:%d:%d   ", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900, (p->tm_hour)-3, p->tm_min, p->tm_sec);
        sleep(1);
    }
    return 0;
}



int crono(){
    
    int seg = 0;
    int min = 0;
    int hour = 0;
    
    while(hour!=1){
        system("clear");
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t%d :%d: %d\r", hour, min, seg);
        
        seg++;
        
        
        if(seg == 60){
            seg = 0;
            min++;
        }
        if(min == 60){
            min = 0;
            hour++;
        }
        
        if(hour==1){
            printf("\a");
        }
        
        fflush(stdout);
        sleep(1);
    }
    
    
    
    
    return 0;
}

int temporiz(){
    int tempo;
    printf("\nInforme o tempo que deseja transcorrer(em min): ");
    scanf("%d", &tempo);
    
    int hour = 0;
    int min = 0;
    int i = 1;
    while(1){
        //Primeiro transformando o tempo dado em uma forma visivel
        if(tempo-(60*i) <= 0){
            hour = (i-1);
            min = tempo - 60*hour;
            break;
        }
        
        i++;
    }

    //printf("%d %d", hour, min);
    
    int seg=0;
    while(1){
        
        system("clear");
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t%d :%d: %d\r", hour, min, seg);
        seg--;
        
        if(seg<0){
            seg = 59;
            min--;
            
        }
        
        if(min==0 && hour!=0){
            hour--;
            min = 59;
        }
        
        if(hour == 0 && min == 0 && seg == 0){
            printf("\n\n\n\t\t\t\t\t\t\t\t\t\t%d :%d: %d\a", hour, min, seg);
            break;
        }
        
        fflush(stdout);
        sleep(1);
        
    }
    
    system("clear");
    
    
    return 0;
}

int alarme(){
    int hour, min, seg;
    printf("Informe separando em ponto duplo a hora, min e seg respectivamente: ");
    scanf("%d:%d:%d", &hour, &min, &seg);
    //printf("EU consigo ver %d, %d, %d", hour, min, seg);
    
    struct tm *p;
    time_t seconds;

    
    while(1){
        system("clear");
        time(&seconds);
        p = localtime(&seconds);
        
        
        int hour_ = (p->tm_hour)-3;
        int min_ = p->tm_min;
        int seg_ = p->tm_sec;
        
        
        //printf("Estou comparando %d:%d:%d com o atual %d;%d;%d", hour, min,seg, hour_, min_,seg_);
        
        
        int ver_1 = seg == seg_;
        int ver_2 = min == min_;
        int ver_3 = hour == hour_;
        
        if(ver_1 && ver_2 && ver_3){
            printf("\a");
            break;
        }
        else{
            printf("Esperando.\n");
        }
        
        if(hour-hour_<0){
            printf("\033[31m Impossivel");
            break;
        }
        else{
            if(min-min_<0 && hour==hour_){
                printf("\033[31m Impossivel");
                break;
            }
            else{
                if(seg<seg_ && min == min_){
                    printf("\033[31m Impossivel");
                    break;
                    
                }
            }
        }
        
        
        fflush(stdout);
        sleep(1);
    }
    
    
    
    
    
    system("clear");
    return 0;
}



int main()
{
    
    while(1){
        printf("\033[0m\033[1m\033[7m");
        cabecalho("Relogio", '*');
        
        printf("\n\n 0 - Viver o agora");
        printf("\n 1 - Cronometro");
        printf("\n 2 - Temporizador");
        printf("\n 3 - Alarme");
        
        int opc;
        printf("\n\n\nInforme sua opção: ");
        scanf("%d", &opc);
        
        if(opc == 0){
            agora();
        }
        else{
            if(opc==1){
                crono();
            }
            else{
                if(opc==2){
                    temporiz();
                }
                else{
                    if(opc==3){
                        alarme();
                    }
                    else{
                        printf("\033[31m\n\n Opção Invalida\n\n\033[0m\033[1m\033[7m");
                    }
                }
            }
        }
        
        
        
        
        
    }
    
    
    
    
    
    
    
    
    printf("\033[0m");
    return 0;
}









