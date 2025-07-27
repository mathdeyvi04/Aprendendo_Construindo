#include <stdio.h>
#include <math.h>

unsigned int fatorial(
    int n    
){
    unsigned int res = 1;
    
    for(int i = 1; i <= n; i++){
        res = res * i;
    }
    
    return res;
}

int main()
{
    int N = 100;
    
    printf("%lf", N / (pow(fatorial(N), 1.0/N)));

    return 0;
}
