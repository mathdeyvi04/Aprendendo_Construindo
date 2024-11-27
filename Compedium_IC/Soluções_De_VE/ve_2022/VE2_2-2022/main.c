#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcula_interativa(double x);

void calcula_recursiva(double x);

int fatorial(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    else{
        return n*fatorial(n-1);
    }
}


int main()
{
    double x;
    printf("\033[32m\033[7mDigite o valor de X da integral: ");
    scanf("%lf", &x);
    
    int i = 0;
    while(1){
        if(i){
            printf("\nOpção Invalida\n");
        }
        int opc;
        printf("Informe a forma com que voce deseja resolver: \n");
        printf("0 - Interativa\n");
        printf("1 - Recursiva\n");
        printf("2 - Sair\n  ");
        scanf("%d", &opc);
        
        if(opc == 0){
            calcula_interativa(x);
        }
        else{
            if(opc == 1){
                calcula_recursiva(x);
            }
            else{
                if(opc == 2){
                    return 0;
                }
                else{
                    i++;
                    printf("\nOPCAO INVALIDA\n");
                }
            }
        }
        
        
    }

    return 0;
}

void calcula_interativa(double x){
    double soma = 0;
    
    int n = 1;
    while(1){
        if(abs(n/x) > 1){
            break;
        }
        
        soma += (pow(-1, n-1))*(fatorial(n-1)/pow(x, n));
        
        n++;
    }
    
    
    printf("O valor de f(%.2lf) = %.4lf\n\n\n", x, soma);
    
}

void calcula_recursiva(double x){
    double total(int n, double x){
        if(n == 1){
            return (1/x);
        }
        else{
            double valor = (pow(-1, n-1))*(fatorial(n-1)/pow(x, n));
            
            return (valor + total(n-1, x));
        }
    }
    
    int n = 1;
    while(1){
        if(abs(n/x) > 1){
            break;
        } 
        n++;
    }
    n++;
    
    double soma = total(n, x);
    
    printf("O valor de f(%.2lf) = %.4lf\n\n\n", x, soma);
}
