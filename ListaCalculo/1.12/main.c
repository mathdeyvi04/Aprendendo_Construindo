#include <stdio.h>
#include <math.h>

/*

lim (log 1 + log2 + ... + log n) / (n * log n)
n -> inf

Suponhamos que seja o neperiano

*/

double calculando_somatorio(int N){
    double soma_resultante = 0;
        
    for(
        int i = 1;
        i <= N;
        i++
    ){
        
        soma_resultante = soma_resultante + (log(i))/(N * log(N));
        
    }
    
    return soma_resultante;
}

int main()
{
    
    FILE *arquivo = fopen("convergencia.txt", "w");
    
    for(
        int N = 2;
        N < 1000000;
        N = N + 1000
    ){
        
        double soma_resultante = calculando_somatorio(N);
        
        fprintf(arquivo, "%d -> %lf\n", N, soma_resultante);
    }
    
    fclose(arquivo);

    return 0;
}