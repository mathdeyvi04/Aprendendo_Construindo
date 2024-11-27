#include <stdio.h>
#include <math.h>



/*

SALVE O GRANDE MATHDEYVI

*/



void
cabecalho (char *frase, char a)
{
  /* Aqui teremos nossa 
     funC'C#ode cabeC'alho padrC#o */

#include <string.h>
  printf ("\033[7m\033[1m");
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

  printf ("\033[0m\n");
}

int
menu ()
{

  printf ("\n\033[7m\033[1mDigite 1 para Soma-los");
  printf ("\nDigite 2 para Subtrai-los");
  printf ("\nDigite 3 para Multiplica-los");
  printf ("\nDigite 4 para Dividi-los");
  printf ("\nDigite 5 para obter conjugados");
  printf ("\nDigite 6 para obter modulos");
  printf ("\nDigite 7 para obter argumentos(rad)");
  printf ("\nDigite 8 para enviar novos complexos");
  printf ("\nDigite 9 para sair");
  printf ("\033[0m");

  return 0;
}

int
sleep_ (int a)
{
#include <unistd.h>
  sleep (a);
  return 0;
}

int
main ()
{
  float a = 0.5;
  float b = 0.866;
  float c = 5;
  float d = 7;



  while (1)
    {
      // system("clear");
      int opcao = 0;
      //printf("\n\n\n\n\n\n\n\n");

      cabecalho ("Calculadora de Complexos", '*');
      printf ("\nOs complexos atuais sao:\n");
      printf ("z1 = %.3f + %.3fi\n", a, b);
      printf ("z2 = %.3f + %.3fi\n", c, d);


      menu ();
      printf ("\n\nO que vc deseja fazer: ");
      scanf ("%d", &opcao);

      if (opcao == 1)
	{
	  //Somando
	  float soma_r = a + c;
	  float soma_i = b + d;
	  printf ("\n\033[7m\033[1m z1 + z2 = %.3f + %.3fi\033[0m", soma_r,
		  soma_i);


	}

      if (opcao == 2)
	{
	  //Subtraindo

	  float sub_r = a - c;
	  float sub_i = b - d;
	  printf ("\n\033[7m\033[1m z1 - z2 = %.3f + %.3fi\033[0m", sub_r,
		  sub_i);



	}

      if (opcao == 3)
	{
	  //Multiplicando

	  float mult_r = a * c - b * d;
	  float mult_i = a * d + c * d;

	  printf ("\n\033[7m\033[1m z1*z2 = %.3f + %.3fi\033[0m", mult_r,
		  mult_i);

	}

      if (opcao == 4)
	{
	  //Dividindo
	  if ((c == 0) && (d == 0))
	    {

	      printf
		("\n\033[31m\033[1mNao se pode dividir por um complexo nulo\033[0m");

	    }
	  else
	    {
	      //normalmente
	      float div_r = (a * c + b * d) / (c * c + d * d);
	      float div_i = (b * c - a * d) / (c * c + d * d);


	      printf ("\n\033[7m\033[1m z1/z2 = %.3f + %.3fi\033[0m", div_r,
		      div_i);
	    }


	}

      if (opcao == 5)
	{
	  //Obtendo os conjugados

	  printf ("\n\033[7m\033[1m O conjugado de z1 = %.3f + %.3fi\n", a,
		  b * (-1));
	  printf (" O conjugado de z2 = %.3f + %.3fi \033[0m", c, d * (-1));



	}

      if (opcao == 6)
	{
	  //Pegando o Modulo
	  float mod1 = sqrt (a * a + b * b);
	  float mod2 = sqrt (c * c + d * d);


	  printf ("\033[7m\033[1mO modulo de z1 = %.3f", mod1);
	  printf ("\nO modulo de z2 = %.3f\033[0m", mod2);
	}

      if (opcao == 7)
	{
	  //Argumentos
	  float o1 = atan (b / a);
	  float o2 = atan (d / c);

	  printf ("\033[7m\033[1mO argumento de z1 pode ser %.3f ou %.3f", o1,
		  o1 + 3.141);
	  printf ("\nO argumento de z2 pode ser %.3f ou %.3f\033[0m", o2,
		  o2 + 3.141);

	}


      if (opcao == 8)
	{
	  //Obtendo novos complexos

	  printf ("\n\033[7m\033[1mDigite a parte real de z1: ");
	  scanf ("%f", &a);
	  printf ("\nDigite a parte imaginaria de z1: ");
	  scanf ("%f", &b);

	  printf ("\n\nDigite a parte real de z2: ");
	  scanf ("%f", &c);
	  printf ("\nDigite a parte imaginaria de z2: \033[0m");
	  scanf ("%f", &d);



	}


      if (opcao == 9)
	{
	  printf ("\033[7m\033[1mObrigado pelos testes!\033[0m");
	  break;

	}



      printf ("\n\nEm instantes resetaremos");
      sleep_ (3);


      // 
      printf ("\n\n\n\n\n\n\n\n");
      //  break;
    }



  // system("clear");




  return 0;
}
