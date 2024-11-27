#include <stdio.h>

const int N = 4; //Alunos

const int D = 5; //Disciplinas




void bubble_sort (double vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        printf("\n[%d] ", k);

        for (j = 0; j < n - 1; j++) {
            printf("%d, ", j);

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}


int main()
{
    
    char alunos[N][50] = {"Ciclano Sem Sal", 
                      "Fulano de Tal",
                      "Deltrano Default",
                      "Beltrana Radical"};

    //Esse sera nosso trunfo. A cada notas_disciplinas[i] vamos acessar as notas de cada aluno
    //naquela disciplina, dai vamos selecionar de novo, notas_disciplinas[i][j] para pegar a de 
    //um aluno especifico
    
    double notas_disciplinas[D][N] = {
        {9.5, 7.2, 5.6, 4.5}, //Disciplina 1
        {8.2, 7.1, 8.0, 7.9}, //...
        {5.4, 6.8, 9.5, 5.2},
        {2.3, 4.8, 10.0,4.1}, 
        {7.8, 5.7, 7.4, 9.0}
    //Al 0     1    2    3
    };
    
    double gerais[N];
    
    for(int i = 0; i < N; i++){
        gerais[i] = (notas_disciplinas[0][i]*2 + 
                     notas_disciplinas[1][i]*3 + 
                     notas_disciplinas[2][i]*3 + 
                     notas_disciplinas[3][i]*4 + 
                     notas_disciplinas[4][i]*2)/14;
        //safando a nota geral de cada aluno
        
    }
    
    double gerais_ordenados[N];
    
    for(int i = 0; i < N; i++){
        gerais_ordenados[i] = gerais[i];
        
    }
    
    bubble_sort(gerais_ordenados, N);
    
    //Vamos formar a classificação
    
    int obter_pos(double nota_ordenada){
        for(int i = 0; i < N; i++){
            if(gerais[i] == nota_ordenada){
                return i;
            }
        }
    }
    
    printf("\033[32mClassificação Geral do curso:\n");
    
    //Ai continua o problema C é uma pessima linguagem
    
    
    
    

    return 0;
}


