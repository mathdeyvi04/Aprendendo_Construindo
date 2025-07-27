#include <stdio.h>
#include <math.h>

double calculando(
    int N,
    float p
){
    
    double soma = 0;
    
    for(
        int i = 1;
        i <= N;
        i++
    ){
        soma = soma + ((pow(i, p)) / pow(N, p + 1));
    }
    
    return soma;
    
}


int main()
{
    FILE *arquivo = fopen("convergencia.txt", "w");
    
    for(
        int N = 1;
        N <= 10000;
        N = N + 100
    ){
        int p = 4;
        
        fprintf(arquivo, "%d, %d -> %lf\n", N, p, calculando(N, p));
    }
    
    
    fclose(arquivo);
    

    return 0;
}
