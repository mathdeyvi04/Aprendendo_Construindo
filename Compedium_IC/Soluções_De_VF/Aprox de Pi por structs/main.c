#include <stdio.h>

void cabecalho(char *frase, char a) {
    /* Aqui teremos nossa 
    função de cabeçalho padrão */
    
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

int elevar(int a){
    int res=1;
    
    for(int i=0; i < a; i++){
        res *= -1;
    }
    return res;
}

//Namoral, acho que dava pra fazer isso sem usar struct, apenas com vetores[2]



//Dados da Questao

//Definindo o novo tipo de variavel
typedef struct Rac{
    int num;
    int den;
} Racional;


Racional cria(int n, int d){
    
    Racional r;
    
    r.num = n;
    r.den = d;
    
    return r;
}


void exibe_rac(Racional r){
    printf("%d/%d", r.num, r.den);
}

////////////////////////////////////////////////

Racional reduz(Racional r){
    
    //Assim como na realidade, procuramos ver o menor e se há divisores do menor
    // no maior, a fim de dividir ambos e reduzir a fração
    
    //Simplesmente, incrivel
    
    if(r.num == r.den){
        r = cria(1,1);
    }else{
        //Caso não sejam iguais
        
        int menor = r.num;
        int maior = r.den;
        
        if(r.den < menor){
            menor = r.den;
            maior = r.num;
        }
        
        //Ja temos o menor dentro eles, devemos procurar o maior divisor de menor,
        //que tbm divide o maior.
        
        int maior_div = 1;
        
        for(int i = 1; i <= menor; i++){
            if(menor % i == 0){
                //Achamos os divisores do menor
                //Devemos verificar se também divide o outro maior
                if(maior % i == 0){
                    if( i > maior_div){
                        maior_div = i;
                    }
                }
            }
            
        }
        
        //printf("O maior divisor é %d", maior_div);
        
        r.num = r.num/maior_div;
        r.den = r.den/maior_div;
        
    }
    
    return r;
}


Racional rac_soma(Racional r1, Racional r2){
    
    Racional soma;
    
    //Procedimento padrao
    
    soma.num = r1.num*r2.den + r2.num*r1.den;
    soma.den = r1.den*r2.den;
    
    
    return reduz(soma);
}




int main()
{
    printf("\033[7m\033[1m");
    cabecalho("Aproximacao de PI", '*');
    
    int precisão = 0;
    //printf("%d", (4*elevar(2+2)));
    //exibe_rac(rac_soma(cria(0,3), cria(3,4)));
    
    
    do{
        printf("\n\nInforme até qual precisao voce deseja: ");
        scanf("%d", &precisão);
    }while(precisão<=0);
    
    printf("PI = \n");
    Racional pi_aprox = cria(0, 1);
    
    for(int i=0; i<precisão; i++){
        exibe_rac(cria((4*elevar(i+2)), 2*i+1));
        printf("+ ");
        pi_aprox = rac_soma(pi_aprox, cria(   (4*elevar(i+2))  , (2*i+1)   ));
        
        
        
    }
    printf("\n= ");
    exibe_rac(pi_aprox);
    
    printf("\n\nE temos %.4lf", (double)pi_aprox.num/pi_aprox.den);
    
    
    printf("\033[0m");
    return 0;
}


