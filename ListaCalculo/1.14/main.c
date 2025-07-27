#include <stdio.h>

/*

lim (1 / (n + 1) + 1 / (n + 2) + ... + 1 / (n + n))
n -> inf

*/


double calcular(
    int N    
){
    double soma = 0;
    
    for(
        int i = 1;
        i <= N;
        i++
    ){
        soma = soma + 1.0 / (N + i);
    }
    
    return soma;
    
}


int main()
{
    
    FILE *arq = fopen("convergencia.txt", "w");
    
    for(
        int N = 1;
        N <= 1000000;
        N = N + 100
    ){
        fprintf(arq, "%d -> %lf\n", N, calcular(N));
    }
    
    fclose(arq);

    return 0;
}
