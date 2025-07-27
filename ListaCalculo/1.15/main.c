#include <stdio.h>
#include <math.h>

/*

lim sum_{1}^{n}(1 / sqrt(n^2 + k^2))
n -> inf

*/



double calcular(
    int N    
){
    
    double soma = 0;
    
    for(
        int k = 1;
        k <= N;
        k++
    ){
        soma = soma + 1.0 / sqrt(N * N + k * k);
    }
    
    return soma;
}

int main()
{
    FILE *arq = fopen("convergencia.txt", "w");
    
    for(
        int N = 1;
        N  <= 10000;
        N = N + 100
    ){
        fprintf(arq, "%d -> %lf\n", N, calcular(N));
    }
    
    fclose(arq);

    return 0;
}
