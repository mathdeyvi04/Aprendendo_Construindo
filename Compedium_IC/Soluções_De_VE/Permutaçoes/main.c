#include <stdio.h>


int contadordefrequencia(int a, int b){
    // b deve ser 0<b<9
    if (b<=0 || b>=9){
        return -999;
    }
    
    int count=0;
    
    while (a!=0){
        if (a%10==b){
            count++;
        }
        
        a/=10;
    }

    return count;
}

int fatorial(int a){
    int fat =1;
    for(int i =1; i<=a; i++){
        fat *= i;
    }
    
    
    return fat;
}





int main()
{
    // printf("Aparece %d", contadordefrequencia(111,1));
    // printf("Aparece %d", fatorial(6));
    int m,n;
    printf("\033[7m\033[1mDiga um numero:");
    scanf("%d",&m);
    printf("\nDiga outro numero:");
    scanf("%d",&n);
    
    int dig=0;
    
    int k=m;
    while (k>0){
        k /=10;
        dig++;
    }
    
    
    
    for (int i=0; i<=9; i++){
        int found = 0;
        int m_=m;
        int n_=n;
       
        while (m_>0){
            if (m_%10==i){
                found++;
            }
            m_ /=10;
            
        }
        
        
        while (n_>0){
            if (n_%10==i){
                found--;
            }
            n_ /=10;
            
        }
        
        
        if (found!=0){
            printf("\nOs numeros nao sao permutacoes entre si");
            printf("\033[0m");
            return 0;
        }
        
        
    }
    
    printf("\nEles sao permutacoes entre si");
    printf("\n\nO total de permutaçoes possiveis é: %d", fatorial(dig));
    
    
    
    
    
    
    
    
    
    printf("\033[0m");
    return 0;
}


