#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


const float min_A = 100.00;
const float min_B = 1000.00;
const float min_C = 10000.00;


//Funções que usaremos

void cabecalho(char *frase, char a){
	//Apenas para estetica do prompt
	
	int tamanho = strlen(frase);
	
	for(int i=0; i<tamanho+20; i++){
		printf("%c", a);
	}
	
	printf("\n");
	int espaco = 10;
	
	
	//personalizando o centro
	printf("%*s %s", espaco, "", frase);
	printf("%*s\n", espaco-1, "");
	
	
	for(int j=0; j<tamanho+20; j++){
		printf("%c", a);
	}
	
	printf("\n");

}

int menu(){
	//Vamos criar uma função paran que possa imprimir o menu sem muitas 
	//dificuldades
	
	cabecalho("Red Beach Enterprise Funds", '*');
	
	printf("\n\nSelecione a opcao de carreira");
	
	printf("\nA - Conservadora  [Investimento Minimo  = R$100.00]  ");
	printf("\nB - Arrojada      [Investimento Minimo  = R$1000.00] ");
	printf("\nC - Insana        [Investimento Minimo  = R$10000.00]");
	
	return 0;
}

double minimo(double valor, char opc){
	//Apenas para validarmos se o valor minimo foi atingido 
	//em cada caso possivel
	
	
	
	
	//Faremos essa verificao usando vetores para podermos reduzir a 
	//quantidade de decisões e de linhas
	
	char opcoes[3] = {'A', 'B', 'C'};
	double minimos[3] = {min_A, min_B, min_C};
	
	for(int i=0; i<2; i++){
		if(opc==opcoes[i]){
			//Opção Conservadora
			while(valor<minimos[i]){
				printf("\n\033[31mInvestimento Inicial Nao Atinge o Minimo da Modalidade!\033[0m\033[7m\033[1m");
				printf("\n\nPor favor, informe o seu montante inicial(R$): ");
				scanf("%lf", &valor);
			}
		}
	}
	
	
	return valor;
}

double taxa_mensal(char opc){
	//Aqui ja não temos o que fazer devemos recorrer ao if, ou switch
	
	

	double taxa = 0;
	
	if(opc == 'A'){
		//Faixa de valores 1 a 5;
		
		taxa = ((rand()%41) + 10)*0.1 ;
		
	}
	else{
	
		if(opc == 'B'){
			
			
			//Faixa de valores -2 a 10;
			
			//Infelizmente, so consegui pensar em fazer de -1.9 ate 11.9
			
			taxa = ((rand()%13) - 1) + (rand()%19 - 9)*0.1 ;
			
			//Parte inteira e parte decimal somadas
			
			
		}
		else{
			//Se não é A nem B, so pode ser C
			
			//Faixa de valores -20 a 20
			
			taxa = (rand()%401 - 200)*0.1 ;
			
		}
		
	
	}
	

	return taxa;
}

char verificacao(char m){

	if(m == 'a'){
		m = 'A';
	}
	else{
		if(m == 'b'){
			m = 'B';
		}
		else{
			if(m == 'c'){
				m = 'C';
			}
		}
		
	}



	return m;
}




int main(){
	while(1){
		printf("\033[7m\033[1m");
	
	menu();
	
	
	//Obtendo escolha do usuário
	char opc[2];
	printf("\n\nInforme a sua decisao: ");
	scanf("%s", &opc[0]);
	opc[1] = '\0';
	
	/*Resolvendo Bug
	 Foi neecessario essa reestruturacao usando vetores(String)
	devido ao problema do buffer */
	
	char opcao = opc[0];
	
	opcao = verificacao(opcao);
	
	
	
	int nao_a = opcao!='A';
	int nao_b = opcao!='B';
	int nao_c = opcao!='C';
	
	
	
	while(nao_a && nao_b && nao_c){
		printf("\n\033[31mEscolha Invalida!!\033[0m\033[7m\033[1m");
		printf("\n\nInforme a sua decisao: ");
		scanf("%s", &opc[0]);
		opc[1] = '\0';
		
		opcao = opc[0];
		
		opcao = verificacao(opcao);
		
		//Como o valor de opc mudou devido a esse scanf
		//necessario mudança nesses operadores tambem
		nao_a = opcao!='A';
		nao_b = opcao!='B';
		nao_c = opcao!='C';
	}	
	
	//Daqui já temos a opção do usuario, devemos agir!
	
	
	double montante; //Se todo float já vai para double, porquê não?
	printf("\n\nPor favor, informe o seu montante inicial(R$): ");
	scanf("%lf", &montante);
	
	
	montante = minimo(montante, opcao);
	
	//Daqui ja temos nosso montante inicial padronizado
	
	//Devemos imprimir o desejado!
	

	printf("\n\nMes         Taxa(%%)      Montante(R$)\n");
	
	
	double taxa;
	srand(time(NULL)); //Mudando a semente sempre
	
	for(int mes = 1; mes<=12; mes++){
		taxa = taxa_mensal(opcao);
		montante = montante*(1+(taxa/100));
		if(mes <= 9){
			//Usaremos o caractere pois não é possivel colocarmos o 0 a esquerda
			//De forma numerica
			printf("0%c          %.1lf       %.2lf\n", mes+48, taxa, montante);
		}
		else{
			
			printf("%d          %.1lf       %.2lf\n", mes, taxa, montante);
			
		}
		
		
	}
	
	
	
	
	//Aqui, vamos analisar se o usuario deseja usar novamente a simulação
	
	char decisao;
	
	do{
		char escolha[2];
		printf("\n\nRealizar nova simulação? (S/N) :  ");
		scanf("%s", &escolha[0]);
		escolha[1] = '\0';
	
		decisao = escolha[0];
		
	}while(decisao != 'S' && decisao != 's' && decisao != 'N' && decisao != 'n');
	
	if(decisao=='S'){
		//Não faremos nada
		
		printf("\n\n\n\n\n\n\n\n\n");
		
		//Apenas 'limparemos' a tela
	}
	else{
		printf("\n\nObrigado por ter me usado");
		break;
	}
	
	
}
	
	
	
	
	printf("\033[0m");
	return 0;
}



