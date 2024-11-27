#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Apenas recapitulando
/*
crianças:   5 a 7 anos
codigos: 0001 a 9999 ----> necessario uso de strings

Apos validar o cartao e se ja existe, solicita altura e idade na mesma linha
caso idade fora da faixa, volta para receber outro cartão

altura: 1,00 a 1,40  caso não esteja na faixa, repete pedindo outra altura apenas ALTURA INVALIDA
A = 1.00 - 1.10
B = 1.11 - 1.20
C = 1.21 - 1.30
D = 1.31 - 1.35
E = 1,36 - 1,40

--Usar um vetor para armazenar a quantidade de cada tipo de faixa
--usar uma matriz para armazenar o max e min em cada tipo de faixa
--O relatorio deve vir como uma função, estando prototipada
--DEve-se ter uma função pegando a menor e a maior altura



encerramento por meio de 50 leituras ou de -1
emissão de um relatorio: 

*percentual que cada faixa obteve daquela amostra populacional (com
precisão de uma casa decimal);

*a menor e a maior alturas do dia (com duas casas decimais);

*estatura média (com duas casas decimais).


*/

const int limite = 50;
const int alg_max = 4; // 0001 ate 9999

const int idade_min = 5;
const int idade_max = 7;

//AS FAIXAS DE ALTURA VÃO SER NO SANHA MESMO
char faixas[5] = {'A', 'B', 'C', 'D', 'E'};

void aviso(char *frase);

void cabecalho(char *frase, char a);

int validar(char *cartao); //vamos apenas ver se op cartão possui o formato adequado

int validar_idade(int idade);

int validar_altura(int altura);

double vendo_faixa(int tam, double *alturas, double *quant_faixa, double min_max_faixa[5][2]);

double maior_menor(int tam, double *alturas_possiveis, int decisao);

void imprimir(double media, double *quant_faixa, double maior, double menor);

//Fazer por struct seria muito mais facil

int main()
{
    printf("\033[7m\033[1m");
    
    //Nossas Bibliotecas
    char cartoes[limite][alg_max];
    double alturas[limite];
    
    int i = 0; //Vai representar a criança!! Isso aqui é de extrema importancia
    
    while(1){
        cabecalho("Cadastramento de Crianças", '*');
        
        fflush(stdin);
        char cartao[alg_max];
        printf("\nPor favor, insira o cartão da crianca: ");
        scanf("%s", cartao);
        
        if(!strcmp(cartao, "-1")){
            //Condição de parada
            break;
        }
        
        
        if(validar(cartao)){
            //devemos verificar se o cartão esta inserido dentro da lista
            
            int inserido(){
                
                for(int j = 0; j != i; j++){
                    //vamos varrer a lista de cartoes a fim de achar nosso cartão
                    //printf("%s  ", cartao);
                    //printf("%s\n", cartoes[j]);
                    if(!strcmp(cartao, cartoes[j])){
                        
                        return 1; //ja esta dentro
                    }
                }
                
                return 0; //não esta na lista
            }
            
            
            
            if(!inserido()){
                //Como não esta inserido, vamos adicionar a criança
                
                int idade;
                double altura;
                printf("\n\nInsira a idade e a altura(usando ponto) da crianca apenas espaçando: \n");
                scanf("%d %lf", &idade, &altura);
                
                //Devemos fazer as verificações insanas
                
                if(validar_idade(idade)){
                    //agora com a altura
                    
                    if(validar_altura(altura)){
                        //Deu tudo bem, agora faremos todos os processos de cadastramentos
                        
                        //vamos adicionar o cartão da criança
                        for(int k = 0; cartao[k] != '\0'; k++){
                            //printf("%c ", cartao[k]);
                            cartoes[i][k] = cartao[k];
                            if(cartao[k+1] == '\0'){
                                cartoes[i][k+1] = '\0';
                            }
                        }
                        //printf("cartao cadastrado %s", cartoes[i]);
                        
                        
                        //Por agora, vamos so adicionar as alturas
                        alturas[i] = altura;
                        
                        i++; //So agora devemos adicionar a criança, pois o cadastramento deu certo
                        
                    }
                    else{
                        
                        do{
                            aviso("ALTURA INVALIDA");
                            printf("\nInsira novamente a altura correta: ");
                            scanf("%lf", &altura);
                        }while(!validar_altura);
                        
                    }
                    
                    
                }
                else{
                    system("clear");
                    aviso("IDADE INVALIDA");
                    continue;
                }
                
                
            }
            else{
                aviso("CARTAO JA CADASTRADO");
            }
            
            
            
        }
        else{
            system("clear");
            aviso("CARTAO INVALIDO");
        }
        
        //Não adicionamos i++ para a prox criança pois pode ser que em um dos if
        //aconteça um erro, compreende?
        //refara o pedido do cartão
        system("clear");
    }
    
    
    //Acabamos com o expediente, devemos preparar o relatorio.
    
    double quantidadefaixa[5] = {0, 0, 0, 0, 0}; //vai representar a nossa querida faixa
    double faixas_min_max[5][2]; 
    //Pode dar erro, o negocio é serio
    
    // faixas_min_max[x][0] -- menor altura da faixa x
    // faixas_min_max[x][1] -- maior altura da faixa x
    
    
    
    //Fazendo o tratamento de dados
    double media_alturas = vendo_faixa(i, alturas, quantidadefaixa, faixas_min_max);
    
    double maior_altura = maior_menor(i, alturas, 1);
    double menor_altura = maior_menor(i, alturas, 0);
    
    //Vamos deixar em porcentagem
    //i representa o total de Crianças
    if(i == 0){
        return 0; //Nada deve ocorrer
    }
    else{
        for(int p = 0; p < 5; p++){
            //printf("Temos %lf como quantidade de crianças da faixa %c e o total é %d\n", quantidadefaixa[p], faixas[p], i);
            quantidadefaixa[p] = (double)(quantidadefaixa[p]/i)*100;
        }
    }    
    
    //Com isso, ja temos a media das alturas, quantidades de faixas e min e max de cada uma
    //Basta imprimir os dados
    
    imprimir(media_alturas, quantidadefaixa, maior_altura, menor_altura);
    
    
    printf("\033[0m");
    return 0;
}

void imprimir(double media, double *quant_faixa, double maior, double menor){
    //Vamos imprimir
    system("clear");
    cabecalho("RELATORIO", '*');
    
    
    printf("\nEstatura Media: %.2lf\n\n", media);
    
    for(int i = 0; i < 5; i++){
        printf("\nFaixa %c: %.2lf%%", faixas[i], quant_faixa[i]);
    }
    printf("\n\nMenor: %.2lf\n", menor);
    printf("Maior: %.2lf", maior);
    
    
    
    
}


void cabecalho(char *frase, char a) {
    /* Aqui teremos nossa 
    função de cabecalho padrão */
    
    #include <string.h>
    
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

int validar(char *cartao){
    //vamos apenas ver se op cartão possui o formato adequado
    int tam = strlen(cartao);
    if(tam == alg_max){
        return 1;
    }
    else{
        return 0;
    }
}

int validar_idade(int idade){
    
    int op1 = idade < idade_min;
    
    int op2 = idade > idade_max;
    
    if(op1 || op2){
        return 0;
    }
    else{
        return 1;
    }
    
}

int validar_altura(int altura){
    
    int op1 = altura < 1.00;
    int op2 = altura > 1.40;
    
    if(op1 || op2){
        return 0;
    }
    else{
        return 1;
    }
    
    
}

void aviso(char *frase){
    printf("\033[0m\033[7m\033[31m%s\n\033[0m\033[7m\033[1m", frase);
}

double vendo_faixa(int tam, double *alturas, double *quant_faixa, double min_max_faixa[5][2]){
    /*
    
    Vamos, a partir do numero da faixa, selecionar em um switch as alturas que correspondem 
    a faixa, adicionando em uma unidade a quantidade da respectiva faixa.
    
    Apos ter varrido todas as alturas, vamos ver que é o menor e quem é o maior.
    
    Para a estatura media, vamos retornar ela por aqui mesmo
    
    */
    
    double media = 0;
    //Primeiro, adicionar 
    void registrando(int faixa, double alt, int pos){
        //independente do menor ou do maior
        quant_faixa[faixa]++;
        
        //Agora, o negocio fica muito mais dificil, maior e menor
        if(pos == 0){
            //quer dizer que é o inicial, portanto
            min_max_faixa[faixa][0] = alt; //menor
            min_max_faixa[faixa][1] = alt; //maior
            //printf("\nEstou definindo maior e menor como %.2lf inicialmente\n", alt);
            
            //Sera tanto o menor quanto o maior
        }
        else{
            //Ja que não é mais o primeiro, devemos fazer as comparações
            
            if(alt < min_max_faixa[faixa][0]){
                min_max_faixa[faixa][0] = alt; //Se torna o novo menor
            }
            
            if(alt > min_max_faixa[faixa][1]){
                min_max_faixa[faixa][1] = alt; //Se torna o novo maior
            }
            
            
        }
        
    }
    
    double altura;
    for(int j = 0; j < tam; j++){
        //vamos varrer a altura total
        
        altura = alturas[j];
        media += altura;
        
        
        if(altura >= 1.00 && altura <= 1.10){
            //faixa 0 -- A
            registrando(0, altura, j);
            
        }
        else{
            if(altura >= 1.11 && altura <= 1.20){
                registrando(1, altura, j);
            }
            else{
                if(altura >= 1.21 && altura <= 1.30){
                    registrando(2, altura, j);
                }
                else{
                    if(altura >= 1.31 && altura <= 1.35){
                        registrando(3, altura, j);
                    }
                    else{
                        if(altura >= 1.35 && altura <= 1.40){
                            registrando(4, altura, j);
                        }
                        else{
                            //aviso("CRIANÇA %s NÃO FOI REGISTRADA", cartoes[j]);
                        }
                    }
                }
            }
        }
        
        
        
        
    }
    
    media = media / tam;
    
    
    return media;
}

double maior_menor(int tam, double *alturas_possiveis, int decisao){
    double valor;
    double altura;
    for(int i = 0; i < tam; i++){
        
        altura = alturas_possiveis[i];
        
        if(i == 0){
            valor = altura; 
        }
        else{
            
            if(decisao){
                //queremos maior
                if(altura > valor){
                    valor = altura;
                }
            }
            else{
                //queremos o menor
                if(altura < valor){
                    valor = altura;
                }
            }
            
        }
        
        
    }
    
    return valor;
    
}


