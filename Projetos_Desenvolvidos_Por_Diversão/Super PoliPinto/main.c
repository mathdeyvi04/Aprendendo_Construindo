#include <stdio.h>
#include <stdlib.h>		//Para usarmos system("clear")
#include <unistd.h>
#include <string.h>
#include <math.h>

void cabecalho (char *frase, char a)
{
  /* Aqui teremos nossa 
     funC'C#ode cabeC'alho padrC#o */

#include <string.h>

  int tamanho = strlen (frase);

  //TESTE
  //printf("%s\n", frase);
  // printf("%c\n", a);
  // printf("%d", tamanho)

  int i;

  for (i = 0; i < tamanho + 20; i = i + 1)
    {

      printf ("%c", a);

    }

  printf ("\n");

  int espaco = 10;

  printf ("%*s %s", espaco, "", frase);

  printf ("%*s\n", espaco - 1, "");

  for (i = 0; i < tamanho + 20; i = i + 1)
    {

      printf ("%c", a);

    }

  printf ("\n");
}


int ver_polinomio (float polinomio[], int n)
{


  for (int i = 0; i <= n; i++)
    {
      if (i == 0 && n != 0)
	{
	  printf ("P(x) = ");

	  printf ("%.2f*x^(%d)+", polinomio[n - i], n - i);

	}
      else
	{
	  if (i == n)
	    {
	      if (n == 0)
		{
		  printf ("P(x) = ");
		}
	      printf ("%.2f", polinomio[n - i]);
	      break;


	    }
	  printf ("%.2f*x^(%d)+", polinomio[n - i], n - i);
	}
    }


  return 0;
}


float calcular_p (float poli[], int n, float x)
{

  float valor = 0;

  for (int i = n; i >= 0; i--)
    {
      valor = valor + poli[i] * (pow (x, i));

    }



  return valor;
}


float teor_racionais(float poli[], int n)
{
    
    
    //ISSO É GENIAL DEMAIS
    int determinar_se_inteiro(float num){
        int i = 0;
        float num_mod = sqrt(num*num);
        
        while(i<=num_mod){
            i++;
            if ( i == num_mod){
                //printf("É inteiro");
                return 1;
            }
        }
        //printf("Nao é inteiro");
        return 0;
        
    }
    

            
    if(determinar_se_inteiro(poli[n]) && determinar_se_inteiro(poli[0])){
        
        
        int an = abs(poli[n]);
        int a0 = abs(poli[0]);
        
        //printf("Temos an=%d e a0=%d", an, a0);
        
        //Achando divisores de a0
        
        int div_0[3*a0];
        int p =0; //paramrtro de controle
        for(int i=1; i<=a0; i++){
            if(a0%i==0){
                div_0[p]=i;
                div_0[p+1]=-i;
                p=p+2;
            }
        }
        
        
        
        /*
        //Mostrando os divisores de a0
        for(int m=0; m<p; m =m +2){
            printf("%d, %d\n", div_0[m], div_0[m+1]);
        }
        //Atençao a esse < unico
        
        */

        //Achando divisores de an
        int div_n[3*an];
        int q=0;
        for(int i=1; i<= an;i++){
            if(an%i==0){
                div_n[q]=i;
                div_n[q+1]=-i;
                q= q+2;
            }
        }
        
        
        // Agora vamos fazer as possiveis raizes
        for(int j=0; j<q; j++){
            //printf("\n%d", div_n[j]);
            
            for(int i=0; i<p; i++){
               //printf("\n%d", div_0[i]);
               
               float pos_raiz= div_0[i]/div_n[j];
               if (calcular_p(poli, n, pos_raiz)==0){
                   //printf("\nD0=%d e tbm Dn=%d gera %f\n", div_0[i], div_n[j], pos_raiz);
                   return pos_raiz;
               }
               
            }
               
            
        }
        
          
        
    }
    else{
        //Quer dizer que não são inteiros 
        printf("\033[0m\033[33m\033[7m\033[1m");
        printf("\n\nOs coeficientes não são inteiros, atente-se!\n\n");
        printf("\033[0m\033[7m\033[1m");
        
    }
    
        
    
    printf("\033[0m\033[33m\033[7m\033[1m");
    printf("\n\nNão ha raizes racionais...\n\n");
    printf("\033[0m\033[7m\033[1m");
        
    
}


int menu_calculos (float polinomio[], int n)
{

  system ("clear");
  sleep (1);

  while (1)
    {
      cabecalho ("PoliPinto", '*');

      printf ("\n");
      ver_polinomio (polinomio, n);
      printf ("\n\n");

      printf ("1- Calcular P(x)");
      printf ("\n2- Derivar");
      printf ("\n3- Integrar");
      printf ("\n4- Somas de Newton");
      printf ("\n5- Sair");

      int opcao_cal;
      printf ("\n\nInforme a sua opcao:");
      scanf ("%d", &opcao_cal);


      if (opcao_cal == 5)
	{
	  system ("clear");
	  break;
	}
      else
	{
	  if (opcao_cal == 1)
	    {
	      //Calculando P(x)
	      float x;
	      printf ("\nDiga o argumento que deseja:");
	      scanf ("%f", &x);

	      float p_x = calcular_p (polinomio, n, x);
	      printf ("\n\nP(%.2f) = %.2f\n\n", x, p_x);
	    }
	  else
	    {
	      if (opcao_cal == 2)
		{
		  printf ("\033[0m\033[33m\033[7m\033[1m");
		  printf ("\n\nDerivando...\n\n");
		  printf ("\033[0m\033[7m\033[1m");
		  sleep (1);

		  // Vamos Derivar

		  int derivado_[50];

		  for (int i = n; i >= 0; i--)
		    {
		      derivado_[i] = polinomio[i] * i;

		      //Apenas para a verificacao
		      //printf("Original=%d    derivado=%d    indice=%d\n",polinomio[i], derivado[i], i);

		    }

		  //Devemos mudar os indices
		  float derivado[50];
		  for (int m = 0; m <= n - 1; m++)
		    {
		      derivado[m] = derivado_[m + 1];
		    }



		  printf ("\033[0m\033[33m\033[7m\033[1m");
		  ver_polinomio (derivado, n - 1);
		  printf ("\033[0m\033[7m\033[1m");
		  printf ("\n");
		  
		  //Não foi possivel a mudança devido à forma bizonha de isso ocorrer em C


          printf ("\n");
		}

	      if (opcao_cal == 3)
		{
		  //Devemos Integrar
		  printf ("\033[0m\033[33m\033[7m\033[1m");
		  printf ("\n\nIntegrando...\n\n");
		  printf ("\033[0m\033[7m\033[1m");
		  sleep (1);

		  float integrado_[50];
		  float coef_inicial = 0;
		  int deci;
		  printf("Informe se voce deseja uma integral definida ou indefinida(1 para sim e 0 para nao): ");
		  
		  scanf("%d", &deci);
		  printf ("\n\n");
		  
		  for (int i = 0; i <= n; i++)
    		    {
    		      coef_inicial = polinomio[i];
    
    		      integrado_[i] = coef_inicial / (i + 1);
    		      //Apenas para a verificacao
    		      //printf("Original=%d    integrado_=%f    indice=%d\n",polinomio[i], integrado_[i], i);
    		    }
    
    		  //MUdando
    		  float integrado[50];
    		  integrado[0] = 0;
    		  for (int m = 0; m <= n; m++)
    		    {
    		      integrado[m + 1] = integrado_[m];
    		    }
		  
          
          if(deci==1){
              // definida
              
              float lim_inf, lim_sup;
              printf("Diga para mim os limites inferior e superior:\n");
              
              printf("Inferior: ");
              scanf("%f", &lim_inf);
              printf ("\n");
              printf("Superior: ");
              scanf("%f", &lim_sup);
              printf ("\n");
              
              float valor = calcular_p(integrado, n+1, lim_sup) - calcular_p(integrado, n+1, lim_inf);
              
              printf ("\033[0m\033[33m\033[7m\033[1m");
		      printf ("\n\nO valor da integral definida eh: %.3f\n\n", valor);
		      printf ("\033[0m\033[7m\033[1m");
              
          }
          else{
                
    
    		  printf ("\033[0m\033[33m\033[7m\033[1m");
    		  ver_polinomio (integrado, n + 1);
    		  printf("+C");
    		  printf ("\n\n");
    		  printf ("\033[0m\033[7m\033[1m");
          }
          
          
          
          
          
          
          
          
		  


		}

	      if (opcao_cal == 4)
		{
		  //Somas de Newton
		  printf ("\033[0m\033[33m\033[7m\033[1m");

		  printf ("\n\nRecorrencia de Somas de Newtons\n\n");



		  //Devemos apresentar a recorrencia

		  for (int j = n; j >= 0; j--)
		    {
		      if (j == n)
			{
			  printf ("%.2f*S(m) +", polinomio[j]);
			}
		      else
			{
			  if (j == 0)
			    {
			      printf ("%.2f*S(m-%d) = 0\n", polinomio[j], n);

			      printf ("\nS(0) = %d", n);
			      if (n % 2 == 0)
				{
				  printf ("\nS(1) = %.2f\n\n", -polinomio[n-1] / polinomio[n]);
				}
			      else
				{
                    printf("\nS(1) = %.2f\n\n", polinomio[n-1]/polinomio[n]);
				}





			    }
			  else
			    {
			      printf ("%.2f*S(m-%d)+ ", polinomio[j], j);
			    }



			}


		    }

		  printf ("\033[0m\033[7m\033[1m");
		}



	    }


	}


    }

  return 0;
}


int menu_solucoes (float polinomio[], int n)
{
    
      system ("clear");
      sleep (1);
    
      while(1){
          cabecalho ("PoliPinto", '*');
          
          printf ("\n");
          ver_polinomio (polinomio, n);
          printf ("\n\n");

          int a;
     

          printf ("\n0- Teorema das Raizes Racionais");
          printf ("\n1- Briot-Rufini");
          printf ("\n2- Resolver Quadratica");
          printf ("\n3- Sair");
    
          printf ("\n\nDigite sua opcao:");
          scanf ("%d", &a);
    
        
          if (a==3){
              system("clear");
              break;
          }
          else{
              
              if(a==0){
                  //Teo. Raizes Racionais
                  
                  
                  float raiz_racional = teor_racionais(polinomio, n);
                  
                  
                  printf("\033[0m\033[33m\033[7m\033[1m");
        	      printf("\n\nA raiz racional é: %.2f\n\n", raiz_racional);
        	      printf("\033[0m\033[7m\033[1m");
            
              }
              else{
                  if(a==1){
                      //Briot Rufini
                      
                      float alpha;
                      printf("\nInforme a raiz ja conhecida: ");
                      scanf("%f", &alpha);
                      
                      if(calcular_p(polinomio, n, alpha)==0){
                          printf("\033[0m\033[33m\033[7m\033[1m");
        	              printf("\n\nAplicando o dispositivo pratico de Briot-Rufini...\n\n");
        	              printf("\033[0m\033[7m\033[1m");
        	              sleep(2);
        	              
        	              float subpoli[50];
        	              float valor = polinomio[n];
        	              
        	              for(int m=n; m>=1; m--){
        	                  //printf("%f*%f + %f\n", valor, alpha, polinomio[m-1]);
        	                  subpoli[m-1]=valor;
        	                  valor = valor*alpha + polinomio[m-1];
        	                  
    	              }
    	              
                      
                      printf("\033[0m\033[33m\033[7m\033[1m");
    	              ver_polinomio(subpoli, n-1);
    	              printf("\033[0m\033[7m\033[1m");
    	              printf("\n\n\n");
                      
                       
                  }
                      
                      else{
                          printf("\033[0m\033[31m\033[7m\033[1m");
        	              printf("\n\nEsta nao eh uma raiz do polinomio hein!\n\n");
        	              printf("\033[0m\033[7m\033[1m");
                          
                      
                          
                      }
                  }  
                  else{
                      if(a==2){
                          //Resolver MultiQuadratica
                          
                          
                          if(n==2){
                            // AX² + BX + C = 0 
                            float A = polinomio[2];
                            float B = polinomio[1];
                            float C = polinomio[0];
                            
                            float delta = (B*B) - 4*A*C;
                            
                            if(delta>0){
                                //Temos duas Raizes
                                
                                float x1 = (-B + sqrt(delta))/(2*A);
                                float x2 = (-B - sqrt(delta))/(2*A);
                                
                                printf ("\033[0m\033[33m\033[7m\033[1m");
		                        printf ("\n\nAs duas raizes do polinomio são: %.3f e %.3f\n\n", x1, x2);
		                        printf ("\033[0m\033[7m\033[1m");
                                
                                
                            }
                            else{
                                if(delta == 0){
                                    float x_ = (-B)/(2*A);
                                    printf ("\033[0m\033[33m\033[7m\033[1m");
		                            printf ("\n\nA única raiz do polinomio é: %.3f\n\n", x_);
		                            printf ("\033[0m\033[7m\033[1m");
                                    
                                }
                                else{
                                    // Raizes Complexas
                                    
                                    float x1_real = (-B)/(2*A);
                                    float x1_iman = sqrt(-delta)/(2*A);
                                    
                                    float x2_real = (-B)/(2*A);
                                    float x2_iman =  -sqrt(-delta)/(2*A);
                                    
                                    printf ("\033[0m\033[33m\033[7m\033[1m");
		                            printf ("\n\nAs duas raizes são complexas e são: (%.3f + %.3fi) e (%.3f + %.3fi)\n\n", x1_real, x1_iman, x2_real, x2_iman);
		                            printf ("\033[0m\033[7m\033[1m");
                                    
                                    
                                }
                            }
                            
                            
                             
                            
                          }
                          else{
                              printf ("\033[0m\033[33m\033[7m\033[1m");
    	                	  printf ("\n\nNão é possível, pois o grau não é 2.\n\n");
    	                	  printf ("\033[0m\033[7m\033[1m");
                           
                          }
                          
                          
 
                      }
                      
                  }
              }
          }
          }
        
        
    
    
    return 0;
}


int main ()
{

  printf ("\033[7m\033[1m");
  float poli[50];

  while (1)
    {

      cabecalho ("PoliPinto", '*');

      int a;
      int n;

      printf ("\n0- Apresentar/Alterar Polinomio");
      printf ("\n1- Menu de Solucoes");
      printf ("\n2- Menu de Calculos");
      printf ("\n3- Sair");

      printf ("\n\nDigite sua opcao:");
      scanf ("%d", &a);

      if (a == 0)
	{
	  //Vamos receber um Polinomio



	  printf ("\nInforme o grau:");
	  scanf ("%d", &n);

	  for (int i = 0; i <= n; i++)
	    {
	      printf ("\nInforme o coeficiente da %d° posicao: ", i);
	      scanf ("%f", &poli[i]);
	    }
	  printf ("\nPolinomio Adicionado! Entre em um Menu\n\n");

	}
      else
	{
	  if (a > 3)
	    {
	      printf ("\n\033[0m\n\033[31m\033[1mOpcao Invalida\n\033[0m");
	      printf ("\033[7m\033[1m");
	      continue;
	    }
	  else
	    {
	      if (a == 1)
		{
		  //Entrando no Menu das Solucoes
		  menu_solucoes(poli, n);
		  
		}
	      else
		{
		  if (a == 2)
		    {
		      //Entrando no Menu de Calculos
		      menu_calculos (poli, n);

		    }
		  else
		    {
		      printf
			("\n\033[0m\n\033[31m\033[1mDesligando...\033[0m");
		      break;
		    }
		}
	    }

	}
    }

  printf ("\033[0m");
  return 0;
  //Fim

}





