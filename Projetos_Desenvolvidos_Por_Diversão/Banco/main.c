#include <stdio.h>
#include <math.h>
#include <stdlib.h>  
#include <string.h>

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

int menu_cliente(){
    
    int op;
    printf("\n\n 1 - Depósito");
    printf("\n 2 - Saque");
    printf("\n 3 - Consulta");
    printf("\n 4 - Sair");
    
    
    printf("\n\n Informe a sua escolha: ");
    scanf("%d", &op);
    
    return op;
}

int menu_adm(){
    
    int op;
    printf("\n\n 1 - Clientes");
    printf("\n 2 - Adicionar Novo Cliente");
    printf("\n 3 - Remover Cliente");
    printf("\n 4 - Sair");
    
    
    printf("\n\n Informe a sua escolha: ");
    scanf("%d", &op);
    
    return op;
}


/*Devemos criar uma forma inteligente de guardar todas as informações*/
typedef struct Banco{
    int numero;
    int senha;
    char nome[50];
    double saldo;
    char historico[50];
    
} banco;


int main()
{
    while(1){
        //Primeiro menu de entrada que NUNCA tem saida
        
        
        
        //Para que sejamos possibilitados de inserir um sistema de adm, devemos 
        //verificar a nova lista sempre que o sistema reiniciar
        int q = 0;
        {
            FILE *pp;
            
            pp = fopen("banco.txt", "r");
            char op[100];
            
            while(!feof(pp)){
                fgets(op, 100, pp);
                q++;
            }
        
        }
        
        int quantidade = q; //Quantidade de Contas
        banco dados[quantidade];
            
        //Vamos fazer apenas uma abertura para pegar todos os dados:
        {
            FILE *registros;
            
            registros = fopen("banco.txt", "r");
            char Linha[100];
            int nm = 0;
            
            //Estava dando um bug com relação a leitura, ae com certei com nm.
            while(!feof(registros) && nm <= quantidade){
                //Vamos ler linha a linha
                fgets(Linha, 100, registros);
                
                //printf("%s\n", Linha); Apenas para testar visualização
                dados[nm].numero = 0;
                dados[nm].senha = 0;
                dados[nm].saldo = 0;
                
                //Para termos o nome direito
                int p = 0;
                int c1 = 0;
                int c2 = 0;
                
                //Não sabemos o valor total de cada pessoa, então vamos precisar
                //montar uma string do saldo e convertÊ-la para double dps
                char saldo_cart[30];
                
                
                for(int m=0; Linha[m] != '\n' && Linha[m]; m++){
                    //Lendo cada carctere
                    
                    if(m<=4){
                        //Nessa seção, vamos ler o numero da conta
                        dados[nm].numero += (Linha[m]-48)*((int)pow(10, 4-m));
                        
                    }else{
                        if(m>=6 && m<=9){
                            //Vamos ler a senha
                            //printf("%c", Linha[m]);
                            
                            
                            dados[nm].senha += (Linha[m]-48)*((int)pow(10, 9-m));
                        }
                        else{
                            //Como não sabemos o tamanho do nome de cada usuario,
                            //vamos ter que apelar
                            
                            if(m>=11 && c1==0){
                                //lendo o nome
                                int maius = Linha[m] >= 65 && Linha[m] <= 90;
                                int minus = Linha[m] >= 97 && Linha[m] <= 122;
                                
                                if(maius || minus){
                                    //printf("%c", Linha[m]);
                                    dados[nm].nome[p] = Linha[m];
                                    p++;
                                }else{
                                    
                                    c1++;
                                    dados[nm].nome[p] = '\0'; //Evitar bugs
                                    p = 0; //reiniciando para lermos o saldo
                                    
                                }
                                
                            }
                            else{
                                
                                if(m>=11 && c2 == 0){
                                    //agora precisamos ler o saldo, temos a garantia 
                                    //de que o nome ja foi lido
                                    
                                    if(Linha[m] != ' '){
                                        saldo_cart[p] = Linha[m];
                                        p++;
                                        
                                    }
                                    else{
                                        saldo_cart[p+1] = '\0';
                                        dados[nm].saldo = atof(saldo_cart);
                                        p=0;
                                        c2++;
                                        
                                    }
                                    
                                }else{
                                    //Vendo o historico
                                    if(m>12){
                                        
                                        //Maior Sanhaço Para resolver esse
                                        
                                        int veri(int o){
                                            int d_ = Linha[o] == 'D';
                                            int s_ = Linha[o] == 'S';
                                            int c_ = Linha[o] == 'C';
                                            
                                            int res1 = d_ || s_ || c_; 
                                            
                                            int res2 = Linha[o+1] == '\0' || Linha[o+1] == '\n'; 
                                            //printf("%d", !(res1 && res2));
                                            
                                            return !(res1 && res2) ;
                                        }
                                        
                                        if(veri(m)){
                                            dados[nm].historico[p] = Linha[m];
                                            p++;
                                        }
                                        else{
                                            dados[nm].historico[p] = Linha[m];
                                            dados[nm].historico[p+1] = '\0';
                                            
                                        }
                                        
                                    }
                                    
                                    
                                }
                                
                                
                            }
                            
                            
                            
                            
                        }
                        
                        
                        
                    }
                    
                    
                }
                
                //Para analise rapida
                /*
                printf("%s\n", dados[nm].nome);
                printf("%d\n", dados[nm].numero);
                printf("%d\n", dados[nm].senha);
                printf("%lf\n", dados[nm].saldo);
                printf("%s\n", dados[nm].historico);
                */
                
                
                nm++;
            }
            
            fclose(registros);
        }
        
        printf("\033[7m\033[1m");
        
        cabecalho("Banco IME", '*');
                       
        
        int conta;
        printf("\nPor favor, informe a sua conta: ");
        scanf("%d", &conta);
        
        int cliente = -1;
        int verificar(int conta){
            for(int i = 0; i< quantidade; i++){
                if(conta == dados[i].numero){
                    //Achamos a pessoa!
                    cliente = i;
                    return 1;
                }
            }
            
            return 0;
        }
        
        //Conta existe ou não
        while(!verificar(conta)){
            printf("\n\033[31mConta Não Existe!\033[0m\033[7m\033[1m\n");
            printf("\nPor favor, informe a sua conta corretamente: ");
            scanf("%d", &conta);
        }
        
        system("clear");
        
        if(cliente == 0){
            //Cliente na real é o adm
            
            while(1){
                
                cabecalho("ADM IME", '=');
                
                int opc = menu_adm();
                
                
                if(opc==4){
                    system("clear");
                    break;
                }
                else{
                    if(opc == 1){
                        //Vamos varrer todos os clientes e mostrar os dados
                        //OU MOSTRAR APENAS UMMMMM, pois e se tivessemos centenas
                        
                        printf("\nDeseja ver a lista COMPLETA de clientes(Digite 1)\n");
                        printf("Deseja ver alguem em especifico          (Digite 2)");
                        
                        int opcao;
                        printf("\n\nInforme: ");
                        scanf("%d", &opcao);
                        
                        if(opcao==1){
                            //Vamos ler tudo
                            //k =1 para nao ler o adm
                            double soma=0;
                            printf("\033[36m");
                            
                            for(int k =1; k<quantidade; k++){
                                printf("\nCliente %d: %s\n", k, dados[k].nome);
                                printf("Conta: %d\n", dados[k].numero);
                                printf("Saldo: %.2lf\n", dados[k].saldo);
                                printf("Historico: %s\n\n", dados[k].historico);
                                soma += dados[k].saldo;
                                
                            }
                            
                            printf("Total de %d clientes e R$%.2lf investido\n\n", quantidade-1, soma);
                            printf("\033[0m\033[7m\033[1m");
                        }
                        else{
                            
                            if(opcao == 2){
                                printf("\nDeseja procurar por nome(1) ou por conta(2): ");
                                scanf("%d", &opcao);
                                
                                if(opcao==1){
                                    
                                    char nome[20];
                                    printf("\nDigite o nome: ");
                                    scanf("%s", nome);
                                    
                                    
                                    nome[(int)strlen(nome)] = '\0';
                                    
                                    
                                    int verifica_nome(char *nome_pes){
                                        int con = 0;
                                        for(int p1 = 0; p1<=quantidade-1; p1++){
                                            //Varrendo cada Pessoa
                                            
                                            dados[p1].nome[(int)strlen(dados[p1].nome)] = '\0';
                                            int  tam = strlen(dados[p1].nome);
                                            
                                            for(int p2=0; nome[p2] != '\0';p2++){
                                                //Vamos varrer cada caractere
                                                
                                                if(nome[p2] == dados[p1].nome[p2]){
                                                    //Há igualdade de caracteres
                                                    con++;
                                                    
                                                    if(nome[p2+1]=='\0' && con==tam){
                                                        printf("\033[36m");
                                                        printf("\nCliente %d: %s\n", p1, dados[p1].nome);
                                                        printf("Conta: %d\n", dados[p1].numero);
                                                        printf("Saldo: %.2lf\n", dados[p1].saldo);
                                                        printf("Historico: %s\n\n", dados[p1].historico);
                                                        printf("\033[0m\033[7m\033[1m");
                                                        
                                                        return 1;
                                                    }
                                                    
                                                    
                                                    
                                                }
                                                
                                                
                                            }
                                            
                                            
                                            con = 0;
                                            
                                            
                                            
                                        }
                                        
                                        
                                        
                                        
                                        printf("\n\033[31m\nUsuário Não Encontrado\n\033[0m\033[7m\033[1m\n");
                                        
                                        return 0;
                                        
                                    }
                                    
                                    verifica_nome(nome);
                                    
                                    
                                }
                                else{
                                    if(opcao == 2){
                                        //Vamos procurar por conta
                                        int conta;
                                        printf("\nInforme a conta:");
                                        scanf("%d", &conta);
                                        
                                        int verifica_Conta(){
                                            for(int p1=0;p1<=quantidade-1;p1++){
                                                if(dados[p1].numero == conta){
                                                    printf("\033[36m");
                                                    printf("\nCliente %d: %s\n", p1, dados[p1].nome);
                                                    printf("Conta: %d\n", dados[p1].numero);
                                                    printf("Saldo: %.2lf\n", dados[p1].saldo);
                                                    printf("Historico: %s\n\n", dados[p1].historico);
                                                    printf("\033[0m\033[7m\033[1m");   
                                                    return 1;
                                                }
                                            }
                                            
                                            
                                            printf("\n\033[31m\nUsuário Não Encontrado\n\033[0m\033[7m\033[1m\n");
                                            return 0;
                                        }
                                        
                                        verifica_Conta();
                                    }
                                    else{
                                        printf("\nInválido\n");
                                    }
                                    
                                    
                                }
                                
                                
                            }
                            else{
                                printf("\nInválido\n");
                            }
                        
                            
                        }
                        
                        
                    }
                    else{
                        if(opc == 2){
                            //Vamos adicionar uma nova pessoa ao sistema;
                            printf("\n\n");
                            
                            int senha;
                            printf("\nPara adicionar uma pessoa do sistema, voce precisará da senha de ADM\n");
                            printf("Informe a senha: ");
                            scanf("%d", &senha);
                            
                            while(senha != 9999 && senha != 99){
                                
                                printf("\n\033[31mVoce errou, se não sabe digite 99\033[0m\033[7m\033[1m\n");
                                printf("Informe a senha: ");
                                scanf("%d", &senha);
                                
                                
                            }
                            
                            if(senha == 99){
                                continue;
                            }
                            else{
                                {
                                printf("\033[36m");
                                char clie[50];
                                printf("\nDiga o nome do cliente: ");
                                scanf("%s", clie);
                                
                                while(strlen(clie)<2){
                                    printf("\n\033[31mVoce deve colocar um nome maior!\033[0m\033[1m\033[7m\033[36m\n");
                                    printf("\nDiga o nome: ");
                                    scanf("%s", clie);
                                }
                                clie[(int)strlen(clie)] = '\0';
                                
                                
                                int resu = 1;
                                while(1){
                                    //Fazendo Verificação
                                    for(int p=0;p<quantidade;p++){
                                        if(strcmp(dados[p].nome, clie) == 0){
                                            //Achamos alguem com mesmo nome 
                                            printf("\n\033[31mVoce deve colocar um nome diferente!\033[0m\033[1m\033[7m\033[36m\n");
                                            printf("\nDiga o nome: ");
                                            scanf("%s", clie);
                                            clie[(int)strlen(clie)] = '\0';
                                            resu = 0;
                                        }
                                    }
                                    
                                    if(resu){
                                        break;
                                    }
                                    else{
                                        resu = 1;
                                    }
                                }
                                
                                
                                
                                
                                int conta_;
                                printf("\nInforme um numero de conta: ");
                                scanf("%d", &conta_);
                                while(conta_<10000){
                                    printf("\n\033[31mVoce deve colocar um numero de 5 algarismos!\033[0m\033[1m\033[7m\033[36m\n");
                                    printf("\nInforme um numero de conta: ");
                                    scanf("%d", &conta_);
                                }
                                
                                
                                
                                
                                int senha_;
                                printf("\nInforme uma senha: ");
                                scanf("%d", &senha_);
                                while(senha_<1000){
                                    printf("\n\033[31mVoce deve colocar um numero de 4 algarismos!\033[0m\033[36m\n");
                                    printf("\nInforme uma senha: ");
                                    scanf("%d", &senha_);
                                }
                                
                                
                                
                                for(int p1=0; clie[p1] != '\0'; p1++){
                                    dados[quantidade].nome[p1] = clie[p1];
                                    //printf("Estou lendo: %c\n", clie[p1]);
                                    
                                }
                                
                                dados[quantidade].numero = conta_;
                                dados[quantidade].senha = senha_;
                                dados[quantidade].saldo = 0.00;
                                dados[quantidade].historico[0] = 'C';
                                dados[quantidade].historico[1] = '\0';
                                
                                
                                //Verificação
                                printf("\nNome: %s\n", dados[quantidade].nome);
                                printf("Numero: %d\n", dados[quantidade].numero);
                                printf("Senha: %d\n", dados[quantidade].senha);
                                printf("Saldo: %.2lf\n", dados[quantidade].saldo);
                                printf("Historico: %s\n", dados[quantidade].historico);
                                printf("\033[0m\033[7m\033[1m");
                                
                                printf("\nConfirme os dados e informe sim ou não para confirmação: ");
                                scanf("%d", &opc);
                                printf("\n");
                                if(opc){
                                    //qualquer valor para sim
                                    
                                    FILE *adicionando;
                                    
                                    adicionando = fopen("banco.txt", "a");
                                    
                                    fprintf(adicionando, "\n%d ", dados[quantidade].numero);
                                    fprintf(adicionando, "%d ", dados[quantidade].senha);
                                    fprintf(adicionando, "%s ", dados[quantidade].nome);
                                    fprintf(adicionando, "%.2lf ", dados[quantidade].saldo);
                                    fprintf(adicionando, "%s", dados[quantidade].historico);
                                    
                                    quantidade++;
                                    
                                    
                                    fclose(adicionando);
                                    
                                    printf("\nCadastro Concluido!\n\n");
                                }
                                else{
                                    printf("\nOperação Cancelada\n\n");
                                }
                                
                            }
                            }
                            
                            
                            
                            
                            
                            
                            
                        }
                        else{
                            if(opc==3){
                                //Vamos remover uma pessoa!
                                int senha;
                                printf("\nPara remover uma pessoa do sistema, voce precisará da senha de ADM\n");
                                printf("Informe a senha: ");
                                scanf("%d", &senha);
                                
                                while(senha != 9999 && senha != 99){
                                    
                                    printf("\n\033[31mVoce errou, se não sabe digite 99\033[0m\033[7m\033[1m\n");
                                    printf("Informe a senha: ");
                                    scanf("%d", &senha);
                                    
                                    
                                }
                                
                                if(senha==99){
                                    continue;
                                }else{
                                    int conta_elim;
                                    printf("\nInforme, necessariamente, o numero de conta: ");
                                    scanf("%d", &conta_elim);
                                    
                                    int verifica_Conta(){
                                        for(int p1=0;p1<=quantidade-1;p1++){
                                            if(dados[p1].numero == conta_elim){
                                                //Achamos a pessoa
                                                return (p1);
                                            }
                                        }
                                            
                                            
                                        printf("\n\033[31m\nUsuário Não Encontrado\n\033[0m\033[7m\033[1m\n");
                                        return 0;
                                    }
                                    
                                    int pes = verifica_Conta();
                                    
                                    if(pes!=0){
                                        //Vamos eliminar!
                                        
                                        
                                        
                                        FILE *eliminando;
                                        
                                        eliminando = fopen("banco.txt", "w+");
                                        
                                        for(int linha=0; linha<=quantidade-1; linha++){
                                            if(linha != pes){
                                                //printf("\nEstou escrevendo o %s", dados[linha].nome);
                                                
                                                if(linha == quantidade-1){
                                                    fprintf(eliminando, "%d ", dados[linha].numero);
                                                    fprintf(eliminando, "%d ", dados[linha].senha);
                                                    fprintf(eliminando, "%s ", dados[linha].nome);
                                                    fprintf(eliminando, "%.2lf ", dados[linha].saldo);
                                                    fprintf(eliminando, "%s", dados[linha].historico);
                                                }
                                                else{
                                                    if(linha+1 == pes){
                                                        fprintf(eliminando, "%d ", dados[linha].numero);
                                                        fprintf(eliminando, "%d ", dados[linha].senha);
                                                        fprintf(eliminando, "%s ", dados[linha].nome);
                                                        fprintf(eliminando, "%.2lf ", dados[linha].saldo);
                                                        fprintf(eliminando, "%s", dados[linha].historico);
                                                    }
                                                    else{
                                                        fprintf(eliminando, "%d ", dados[linha].numero);
                                                        fprintf(eliminando, "%d ", dados[linha].senha);
                                                        fprintf(eliminando, "%s ", dados[linha].nome);
                                                        fprintf(eliminando, "%.2lf ", dados[linha].saldo);
                                                        fprintf(eliminando, "%s\n", dados[linha].historico);
                                                    }
                                                }
                                                
                                            }
                                        }
                                        
                                        
                                        fclose(eliminando);
                                        
                                        quantidade--;
                                        
                                        printf("\n\nCliente Eliminado\n\n");
                                        
                                    }
                                    
                                    
                                    
                                    
                                    
                                }
                                
                                
                                
                                
                            }
                            else{
                                printf("\nInválido\n");
                            }
                        }
                    }
                    
                }
                
            }
            
            
        }
        else{
            //Menu dos Clientes
            
            char registro[100];
            int i = 0;
            while(1){
                
                cabecalho("Cliente IME", '*');
                
                printf("\033[36m\nBom dia %s\033[0m\033[7m\033[1m\n", dados[cliente].nome);
                
                
                int opc = menu_cliente();
                
                
                if(opc==1){
                    //Deposito, vamos adicionar dinheiro a conta!
                    registro[i] = 'D';
                    
                    double valor;
                    printf("\nInforme o valor que voce deseja depositar: ");
                    scanf("%lf", &valor);
                    
                    printf("\033[35m\nDepositando... pronto!\033[0m\033[7m\033[1m\n\n\n");
                    
                    dados[cliente].saldo += valor;
                    
                    
                }
                else{
                    
                    if(opc == 2){
                        //Para sacar devemos usar SENHA
                        
                        int senha;
                        printf("\nAntes informe a senha da conta: \033[0m\033[7m\033[30m\033[40m");
                        scanf("%d", &senha);
                        
                        int p = 0;
                        while(senha != dados[cliente].senha && senha !=99){
                            if(p>=5){
                                printf("\n\033[0m\033[7m\033[1m\033[31mDigite 99 para desistir!\033[0m\033[7m\033[1m");
                            }
                            printf("\n\033[0m\033[7m\033[1m\033[31mSENHA INCORRETA!\033[0m\033[7m\033[1m\n");
                            printf("\nAntes informe a senha da conta: \033[0m\033[7m\033[30m\033[40m");
                            scanf("%d", &senha);
                            
                            p++;
                        }
                        printf("\033[0m\033[7m\033[1m");
                        
                        //Desistencia
                        if(senha == 99){
                            
                            system("clear");
                            continue;
                        }
                        
                        registro[i] = 'S'; //Salvando registro
                        
                        double valor;
                        //Pessoa está com senha certa
                        printf("\nInforme o valor de saque: ");
                        scanf("%lf", &valor);
                        
                        printf("\033[34m\nEnviando... Safou!\033[0m\033[7m\033[1m\n\n\n");
                        
                        dados[cliente].saldo -= valor;
                        
                        
                    }
                    else{
                        if(opc == 3){
                            //Consulta
                        
                            int senha;
                            printf("\nAntes informe a senha da conta: \033[0m\033[7m\033[30m\033[40m");
                            scanf("%d", &senha);
                            
                            int p = 0;
                            while(senha != dados[cliente].senha && senha !=99){
                                if(p>=5){
                                    printf("\n\033[0m\033[7m\033[1m\033[31mDigite 99 para desistir!\033[0m\033[7m\033[1m");
                                }
                                printf("\n\033[0m\033[7m\033[1m\033[31mSENHA INCORRETA!\033[0m\033[7m\033[1m\n");
                                printf("\nAntes informe a senha da conta: \033[0m\033[7m\033[30m\033[40m");
                                scanf("%d", &senha);
                                
                                p++;
                            }
                            printf("\033[0m\033[7m\033[1m");
                            
                            //Desistencia
                            if(senha == 99){
                                system("clear");
                                continue;
                            }
                            
                            registro[i] = 'C';
                            
                            printf("\033[34m\nO seu saldo eh de %.2lf\033[0m\033[7m\033[1m\n\n\n", dados[cliente].saldo);
                        }
                        else{
                            if(opc == 4){
                                //Saindo
                                registro[i] = '\0'; //Me deixou no sanha
                                system("clear");
                                
                                break;
                            }
                            else{
                                //Qualquer outro
                                printf("\n\033[0m\033[7m\033[1m\033[31mInvalido!\n\033[0m\033[7m\033[1m\n");
                            }
                        }
                        
                        
                        
                    }
                    
                }
                
                i++;
            }
            
            //Após todos esses fatos, devemos ser capazes de mudar os dados da conta no banco.
            
            //Como já safamos tudo nos dados de cada cliente, basta que criemos
            //um novo arquivo e escrevamos nele tudo
            
            
            //Primeiro, registrar o historico 
            int tam = strlen(dados[cliente].historico);
            
            //printf("%d", tam); verificação
            
            for(int k = 0; k<=i; k++){
                dados[cliente].historico[tam+k] = registro[k];
                if(k==i){
                    dados[cliente].historico[tam+k+1] = '\0';
                    //printf("executei");
                }
            }
            
            //Vamos agora copiar tudo
            
            {
                
                FILE *alterações;
                
                alterações = fopen("banco.txt", "w+");
                
                
                int j = 0;
                while(j<quantidade){
                    
                    
                    if(j==quantidade-1){
                        //ultimo
                        fprintf(alterações, "%d ", dados[j].numero);
                        fprintf(alterações, "%d ", dados[j].senha);
                        fprintf(alterações, "%s ", dados[j].nome);
                        fprintf(alterações, "%.2lf ", dados[j].saldo);
                        fprintf(alterações, "%s", dados[j].historico);
                    }
                    else{
                        fprintf(alterações, "%d ", dados[j].numero);
                        fprintf(alterações, "%d ", dados[j].senha);
                        fprintf(alterações, "%s ", dados[j].nome);
                        fprintf(alterações, "%.2lf ", dados[j].saldo);
                        fprintf(alterações, "%s\n", dados[j].historico);
                    }
                    
                    
                    j++;
                }
                
                fclose(alterações);
                
            }
            
            //Safou
            
            
        }
        
    }
    
    
    

    return 0;
}
