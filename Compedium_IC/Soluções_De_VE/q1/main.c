#include <stdio.h>
#include <string.h>


void cabecalho(char *frase, char a) {
	
	
	
	
    /* Aqui teremos nossa 
    função de cabecalho padrão */
    
    
    
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

    
int menu(){
	int opc = 0;
	
	cabecalho("Definição da Função Logaritmo", '*');
	printf("\n1 - Calcular por Interacao");
	printf("\n2 - Calcular por Recursao");
	printf("\n3 - Sair");
	printf("\n\nDigite sua opcao: ");
	scanf("%d", &opc);


	return opc;
}
	
double pegando(int decisao){

	if(decisao == 1){
		double valor = 0;
		printf("\nDigite o argumento da função logaritmo: ");
		scanf("%lf", &valor);
		
		if(valor < 1){
			printf("\033[31m\n O valor deve ser maior que 1!!\n\033[0m\033[7m\033[1m");
			pegando(decisao);
		}
		
		return valor;
	}
	else{
		double valor = 0;
		printf("\nDigite o numero de intervalos de discretização: ");
		scanf("%lf", &valor);
		
		if(valor < 1){
			printf("\033[31m\n O valor deve ser maior que 1!!\n\033[0m\033[7m\033[1m");
			pegando(decisao);
		}
		
		return valor;
		
	}
	
	
	return 0;
}

float reciproco(float numero){
	return (1/numero);
}

double obtendo_interativa(double argu, int intervalos){
	double valor = 0;
	for(int i = 1; i <= intervalos; i++){
		valor += (reciproco(1 + ((i - 1)*(argu - 1))/intervalos) + reciproco(1 + ((i)*(argu - 1))/intervalos))*((argu - 1)/(2*intervalos));
	}
	return valor;
}

double obtendo_recursiva(double argu, int intervalos){
	//Não conseguimos fazer a forma recursiva....
	return 0;
}


int main(){
	
	
	printf("\033[7m\033[1m");
	
	while(1){
		
		
		int opc = menu();
		
		
		if(opc == 3){
			break;
		}
		else{
			if(opc == 1){
				//interação
				double arg = pegando(1);
				
				int intervalos = (int)pegando(2);
				
				double resultado = obtendo_interativa(arg, intervalos);
				
				printf("\n\nO resultado da integral por este metodo %lf", resultado);
				
			}
			else{
				if(opc == 2){
					//recursao
					
					double arg = pegando(1);
				
					int intervalos = (int)pegando(2);
					
					double resultado = obtendo_recursiva(arg, intervalos);
					
					//Não conseguimos fazer a forma recursiva....
					
					
					printf("\n\nO resultado da integral por este metodo %lf", resultado);
				}
				else{
					printf("\033[31mOPCAO INVALIDA\033[0m\033[7m\033[1m");
				}
			}
			
		}
		
		printf("\n\n");
		
	}
	
	
	
	
	return 0;
}
