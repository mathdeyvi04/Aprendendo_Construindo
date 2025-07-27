#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    
    float* vetor_de_inputs = (float*) malloc(1 * sizeof(float));
    int quantidade = 0;
    
    // Obtendo vetor de inputs
    {   
        int i = 0;
        while (1){
            printf("\n\nInsira um input(-1 -> encerrar): ");
            scanf("%f", &vetor_de_inputs[i]);
            
            if(vetor_de_inputs[i] > 0){
                // Então deu certo
                i++;
                
                // Devemos alocar mais memoria
                vetor_de_inputs = (float*) realloc(vetor_de_inputs, (i + 1) * sizeof(float));
                
            }else{
                if(vetor_de_inputs[i] == -1){
                    break;
                }
                printf("\nValor de Input deve ser maior que 0.");
            }
        }
        
        // Vamos apresentar o vetor até agora
        printf("Vetor de Input até agora: [");
        
        for(
            int j = 0;
            j < i;
            j++
        ){
            printf("%.1f, ", vetor_de_inputs[j]);
        }
        printf("]");
        
        quantidade = i;
        
    }
    
    // Vamos aplicar o sanha
    double resultado = 0;
    int N = 1000;
    
    for(
        int j = 0;
        j <= quantidade;
        j++
    ){
        resultado = resultado + pow(vetor_de_inputs[j], N);
    }
    
    
    free(vetor_de_inputs);
    return 0;
}
