#include <stdio.h>

int main()
{
    float A,B;
    printf("Informe o x do ponto mais alto:");
    scanf("%f", &A);
    printf("\nInforme o y do ponto mais alto:");
    scanf("%f", &B);
    
    
    float a;
    printf("\nSabendo que o projetil atingiu (0,0) e que");
    printf(" precisamos de um chute para o x da atilharia:");
    scanf("%f",&a);
    
    printf("\n");
    
    float m=-B/(A*A);
    float n= (2*B)/A;
    
    printf("\n\n A funcao que descreve a trajetoria é:");
    printf("\nf(x)= %.3fx^2 + %.3fx", m,n);
    printf("\n\n\nAlem disso, a artilharia inimiga esta em (%.2f,%.2f)",a,m*(a*a)+n*a);
    
    
    return 0;
}
