#include <stdio.h>
#include <string.h>

#define opcoes 4  //Pois ha short, camisa, tenis, bone
#define caracteristicas 3  //Ha caracteristicas em cada tipo de roupa


int menu();

void cabecalho(char *frase, char a); 

void aviso(char *frase);

void estoque_atual(int estoque[opcoes][caracteristicas]);

int retirar(int estoque[opcoes][caracteristicas]);

int repor(int estoque[opcoes][caracteristicas]);


int main(){
	
	int estoque[opcoes][caracteristicas] = {
		{11, 50, 10},
		{12, 100, 10},
		{13, 200, 10},
		{14, 50, 10}
	};
	
	//////////////////////////////////////////////////////////
	
	printf("\033[7m\033[1m");
		
	
	while(1){
		
		int opc = menu();
		
		if(opc == 4){
			//Vamos sair
			break;
		}
		else{
			if(opc == 1){
				estoque_atual(estoque);
			}
			else{
				if(opc == 2){
					retirar(estoque);
				}
				else{
					if(opc == 3){
						repor(estoque);
						
					}
					else{
						//opcao invalida
						aviso("Opcao Invalida\n");
						
					}
				}
			}
			
		}
		
		
		printf("\n\n");
	}



	printf("\033[0m");
return 0;
}


//Funções de manipulação:
void estoque_atual(int estoque[opcoes][caracteristicas]){
	//Com isso, devemos ler o estoque
	
	char roupas[opcoes][15] = { "Short", 
								"Camisa", 
								"Tenis", 
								"Bone"};
	
	
	
	printf("\n\nProduto---Codigo-----Preco-----Quantidade\n");
	for(int i = 0; i < opcoes; i++){
		//Vamos varrer os tipos de roupas
		
		int pos = 0; //Usaremos esse pos para formatar adequadamente nossa tabela
		
		int j = 0;
		while(roupas[i][j] != '\0'){
			printf("%c", roupas[i][j]);
			j++;
			pos++;
			
		}
		
		//Para resolver um bug de formatação usei essa variavel
		int uma_vez = 1;
		for(int p = 0; p < (19 - pos); p++){
			if( i == 1 && uma_vez){
				p++;
				uma_vez--;

			}
			printf("-");
			pos++;
		}
		
		
		printf("%d", estoque[i][0]);
		pos += 2;
		
		
		for(int p = 0; p < (30 - pos); p++){
			printf("-");
			pos++;
		}
		
		printf("%d", estoque[i][1]);
		//Afinal, a peça de roupa pode valer qualquer coisa coisa e dai precisamos aumentar na formatação
		if(estoque[i][1] > 100){
			pos += 3;
		}
		else{
			if(estoque[i][1] > 10){
				pos += 2;
			}
			else{
				pos++;
			}
		}
		
		//Para resolver um bug de formatação usei essa variavel
		uma_vez = 1;
		for(int p = 0; p < (50 - pos); p++){
			if( (i == 1 || i == 2) && uma_vez){
				if(i == 1){
					p++;
				}
				uma_vez--;
				pos++;
			}
			printf("-");
			pos++;
		}
		
		
		
		printf("%d", estoque[i][2]);
		
		
		
		printf("\n");
	}	
	
	
	
	
	
	
}

int retirar(int estoque[opcoes][caracteristicas]){
	//Primeiro, precisamos saber que produto tirar
	
	
	int tipo = 0;
	int quant = 0;
	
	printf("\nInforme o codigo do produto seguido de sua quantidade: ");
	scanf("%d %d", &tipo, &quant);
	
	//Dai, bastara procurar no estoque o produto com o mesmo codigo
	for(int i = 0; i < opcoes; i++){
		if(estoque[i][0] == tipo){
			if(estoque[i][2] > quant){
				estoque[i][2] -= quant;
			}
			else{
				if(estoque[i][2] == quant){
					estoque[i][2] -= quant;
					printf("\033[31mProduto %d ZERADO! REPOR ESTOQUE\033[0m\033[7m\033[1m", tipo);
				}
				else{
					aviso("ATENCAO! REPOR O ESTOQUE, quantidade pedida eh maior que a existente");
				}
			}
			
			estoque_atual(estoque);
			return 0;
		}
	}
		
	
	aviso("ATENCAO! CODIGO ERRADO");
	retirar(estoque);
	
	return 1;
	
}

int repor(int estoque[opcoes][caracteristicas]){
	
	int tipo = 0;
	int quant = 0;
	
	printf("\nInforme o codigo do produto seguido de sua quantidade: ");
	scanf("%d %d", &tipo, &quant);
	
	//Dai, bastara procurar no estoque o produto com o mesmo codigo
	for(int i = 0; i < opcoes; i++){
		if(estoque[i][0] == tipo){
			estoque[i][2] += quant;
			estoque_atual(estoque);
			return 0;
		}
	}
		
	
	aviso("ATENCAO! CODIGO ERRADO");
	repor(estoque);
	
	return 1;
	
}
	
	
	




//Funções de Apresentação
int menu(){
	
	cabecalho("Controle de Vendas", '-');
	
	int opc = 0;
	printf("\n1 - Listar Produtos");
	printf("\n2 - Registrar Saida de Produto");
	printf("\n3 - Repor o Estoque");
	printf("\n4 - Sair do Sistema");
	printf("\n\nEscolha uma opcao: ");
	scanf("%d", &opc);
	
	
	return opc;
}

void aviso(char *frase){
	printf("\033[31m%s\033[0m\033[7m\033[1m", frase);
}

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
