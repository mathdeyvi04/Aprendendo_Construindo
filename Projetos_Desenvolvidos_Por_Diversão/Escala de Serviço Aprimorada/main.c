#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*Levando em consideração a seriedade da lista de alunos, vamos fazê-la
imutável, a não ser por um agente externo*/
const int quantidade = 47;
///////////////////////////////



//Criando a estrutura que guardará cada aluno
typedef struct alunos{
    char nome[50];
    int servi_ala;
    int servi_3;
    int servi_senti;
    int baixado;
    int condições;
}ALUNO;



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


int menu_baixados(){
    //Para vermos muita coisa dos baixados.
   
    system("clear");
    cabecalho("MENU DE BAIXADOS", '=');
    
    printf("\033[32m");
    printf("\n\nBAIXADOS------INICIO------------MOTIVO-------------FIM--\n");
    
    //Apresentação
    {
        FILE *baixinhos;
        
        baixinhos = fopen("baixados.txt", "r");
        
        char linha[100];
        while(!feof(baixinhos)){
            fgets(linha, 100, baixinhos);
            
            if(linha[0] != '/'){
                
                int i = 0;
                int pos = 0;
                while(linha[i] != '{'){
                    
                    printf("%c", linha[i]);
                    pos++;
                    i++;
                }
                
                
                //agora linha[i] = '{'
                i++;
                int num = 16 - i;
                for(int j = 0; j<=num;j++){
                    printf("-");
                    pos++;
                }
                
                while(linha[i] != '='){
                    
                    printf("%c", linha[i]);
                    pos++;
                    i++;
                }
                
                
                //linha[i] = '='
                i++;
                
                
                int m = i; //Para guardarmos a posição da data
                while(linha[i] != '}'){
                    i++;
                    
                }
                //Resolvemos voltar devido à problemas em relação ao tamanho
                
                
                //linha[i] = '}'
                i++;
                num = 28 - pos;
                for(int j = 0; j<=num; j++){
                    printf("-");
                    pos++;
                }
                
                
                while(linha[i] != '-'){
                    printf("%c", linha[i]);
                    pos++;
                    i++;
                }
                
                
                num = 51 - pos;
                for(int j = 0; j<=num;j++){
                    printf("-");
                }
                
                //Voltando para a data
                while(linha[m] != '}'){
                    printf("%c", linha[m]);
                    m++;
                }
                
                
                
                printf("\n");
            }
            
        }
        
        
        fclose(baixinhos);
    }
    
    printf("\n\033[0m\033[7m\033[1m");
    
    
    while(1){
        int p;
        printf("Pressione qualquer numero");
        scanf("%d", &p);
        if(p != 999){
            system("clear");
            break;
        }
    }
    
    
    
    
    
    return 0;
}


int desbaixou(int dia, int mes){
    
    //A partir disso, vamos abrir o arquivo de baixados e verificar se alguem
    //desbaixou no dia. Caso, não, nada ocorre. Caso sim, há mudanças na lista dos 
    //dos alunos e um aviso
    
    {
        FILE *desbaixando;
    
        desbaixando = fopen("baixados.txt", "r");
        
        
        char linha[50];
        char nome[15];
        int dia_baix;
        int mes_baix;
        
        while(!feof(desbaixando)){
            fgets(linha, 50, desbaixando);
            
            if(linha[0] != '/'){
                //Apenas para pularmos 
                
                
                for(int i = 0; linha[i] != '\0'; i++){
                if(linha[i] == '{'){
                    //Vamos iniciar a ver a data final de baixada
                    
                    int j = 1;
                    while(linha[i+j] != '='){
                        j++;
                    }
                    //Ja sabemos que linha[i+j] = '='
                    
                    if(linha[i+j+2] == '/'){
                        //Ja sabemos que a data é do tipo '...=4/...}'
                        dia_baix = linha[i+j+1] - 48;
                        j+=2;
                    }
                    else{
                        //ja sabemos '...=12/'
                        char dia_cart[2];
                        dia_cart[0] = linha[i+j+1];
                        dia_cart[1] = linha[i+j+2];
                        dia_baix = atoi(dia_cart);
                        j+=3;
                    }
                    
                    //Agora, linha[i+j] = '/'
                    
                    if(linha[i+j+2] == '}'){
                        //Ja sabemos que a data é do tipo '...=4/...}'
                        mes_baix = linha[i+j+1] - 48;
                        j+=2;
                    }
                    else{
                        //ja sabemos '...=12/'
                        char mes_cart[2];
                        mes_cart[0] = linha[i+j+1];
                        mes_cart[1] = linha[i+j+2];
                        mes_baix = atoi(mes_cart);
                        j+=3;
                    }
                    
                    break;
                    
                }
                else{
                    //Obtendo o nome
                    nome[i] = linha[i];
                    if(linha[i+1] == '{'){
                        //nome acabou
                        //printf("coloquei nulo");
                        nome[i+1] = '\0';
                        
                    }
                }
            }
                
                //printf("Militar: %s    Baixado até %d/%d\n", nome, dia_baix, mes_baix);
            }
            
            //De  posse das informações dessa pessoa baixada, devemos analisar
            //se a data max de baixado ja passou
            
            if(mes_baix < mes){
                //ja deixou de ser baixada com certeza
            }
            else{
                if(mes_baix > mes){
                    //longe ainda
                    
                }
                else{
                    //mes_baix == mes
                    if(dia_baix == dia-1){
                        
                        //printf("Vamos desbaixar alguem");
                        //Precisamos desbaixar a pessoa
                        
                        char LINHA[quantidade+1][100];
                        char pessoas[quantidade+1][15];
                        {
                            FILE *alterando;
                            
                            alterando = fopen("alunos.txt", "r");
                            
                            for(int i = 0; i<quantidade; i++){
                                fgets(LINHA[i], 100, alterando);
                                
                                int p = 0;
                                while(LINHA[i][p] != ','){
                                    
                                    pessoas[i][p] = LINHA[i][p];
                                    if(LINHA[i][p+1]){
                                        
                                        pessoas[i][p+1] = '\0';
                                    }
                                    
                                    p++;
                                }
                                
                                
                                
                            }
                            
                            
                            fclose(alterando);
                        }
                        
                        
                        
                        
                        //De posse das informações, devemos entrar, modificar e avisar
                        {
                            FILE *alteracoes;
                            
                            alteracoes = fopen("alunos.txt", "w+");
                            
                            for(int j = 0;j<quantidade;j++){
                                //printf("Estou comparando %s e %s\n", nome, pessoas[j]);
                                
                                
                                
                                if(!strcmp(nome, pessoas[j])){
                                    //Achamos a pessoa que desbaixou
                                    
                                    int tam = strlen(LINHA[j]) - 2; //Para ficarmos no ultimo caractere
                                    
                                    
                                    if(LINHA[j][tam-2] == '1'){
                                        
                                        LINHA[j][tam-2] = '0'; // Desbaixando
                                        printf("\033[7m\033[1m\033[32m Militar: %s desbaixou hoje.\a\n\n\033[0m", nome);
                                    }
                                    
                                    
                                    
                                    //Antes tava colocando so = 0 e isso gerou problemas
                                    // 0 não é um carctere
                                    
                                    fprintf(alteracoes, "%s", LINHA[j]);
                                    
                                }
                                else{
                                    //printf("Estou escrevendo a linha de %s(%d) e comparei com %s(%d)\n", pessoas[j],(int)strlen(pessoas[j]), nome, (int)strlen(nome));
                                    
                                    
                                    
                                    fprintf(alteracoes, "%s", LINHA[j]);
                                }
                            }
                            
                            
                            
                            
                            
                            fclose(alteracoes);
                        }
                        
                        
                        
                        
                        
                        
                    }
                }
            }
            
            
            
            
        }
        
        
        fclose(desbaixando);
    }
    
    
    return 0;
}

int main()
{
    int dia_atual;
    int mes_atual;
    int dia_semana;
    {
        time_t mytime;
        mytime = time(NULL);
        struct tm tm = *localtime(&mytime);
        
        dia_atual = tm.tm_mday;
        mes_atual = tm.tm_mon+1;
        dia_semana = tm.tm_wday; //Vamos usar na escala 
        
        //printf("Achei %d de %d, uma %d", dia_atual, mes_atual, dia_semana);
        
        //Funções Hodiernas
        desbaixou(dia_atual, mes_atual);
        
        
    }
    
    int sanha_insano = 0;
    while(1){
        
        printf("\033[7m\033[1m");
        cabecalho("Escala de Serviço v2.0", '*');
        
        
        //Primeiro, devemos pegar todas as informações dos alunos.
        ALUNO alunos[quantidade+1];
        {
            FILE *abrindo;
            
            abrindo = fopen("alunos.txt", "r");
            
            char linha[100];
            for(int i=0; i<quantidade; i++){
                //Vamos cada linha
                
                fgets(linha, 100, abrindo);
                //printf("%s\n", linha); verificando se funciona
                
                
                //Primeiro, o nome
                int p = 0;
                while(linha[p] != ',' ){
                    alunos[i].nome[p] = linha[p];
                    if(linha[p+1] == ','){
                        alunos[i].nome[p+1] = '\0';
                    }
                    p++;
                }
                //printf("Consegui entender %s e o proximo carac que lerei e %c\n", alunos[i].nome, linha[p]);
                //linha[p] está na primeira virgula da linha completa
                
                //Agora, as informações gerais
                
                p++; //Para vermos a quantidade de serviços na ala
                alunos[i].servi_ala =  linha[p] - 48;  
                
                
                p += 2; //Para vermos a quantidade de serviços no 3º
                alunos[i].servi_3 = linha[p] - 48;
                
                
                p += 2; //Para vermos a quantidade de serviços de sentinela
                alunos[i].servi_senti = linha[p] - 48;
                
                
                p += 2; //Para sabermos se esta baixado
                alunos[i].baixado = linha[p] - 48;
                
                p += 2; //Para sabermos se esta em condições
                alunos[i].condições = linha[p] - 48;
                
                
                /*
                printf("\nEu li %s", alunos[i].nome);
                printf(" que tem %d na ala,", alunos[i].servi_ala);
                printf(" %d no 3º",alunos[i].servi_3);
                printf(" %d de senti,", alunos[i].servi_senti);
                printf(" %d para baixado e", alunos[i].baixado);
                printf(" %d para condicoes\n", alunos[i].condições);
                */
            }
            
            fclose(abrindo);
        }
        
        //De posse das informações, podemos fazer muito mais coisas!
        
        //Vamos precisar verificar quem descansou
        {
            char pessoas_descansadas[7][15];
            int m = 0;
            
            FILE *descansado;
            
            descansado = fopen("descanso.txt", "r");
            char linha[20];
            char linhas_salvas[7][20];
            
            int k = 0;
            while(!feof(descansado)){
                fgets(linha, 20, descansado);
                
                char nome[15];
                int i;
                for(i = 0; linha[i] != ',';i++){
                    //printf("Estou vendo %c\n", linha[i]);
                    nome[i] = linha[i];
                    if(linha[i+1] == ','){
                        nome[i+1] = '\0';
                    }
                }
                //printf("\nCompreendi %s", nome);
                i++; //para sairmos da ,
                
                char num[2];
                int j = 0;
                while(linha[i] != '-'){
                    //printf("%c\n", linha[i]);
                    num[j] = linha[i];
                    i++;
                    j++;
                }
                num[j] = '\0';
                int descanso_ate = atoi(num);
                
                //printf("%d", descanso_ate);
                if(sanha_insano){
                    /*
                        Não FAÇO IDEIA do porque isso ocorre, mas em primeira vez,
                        o sistema diz o dia de descanso certo, por exemplo 2.
                        Mas dps que eu aperto a opçao 1, vai para 29.
                    */
                    descanso_ate = (descanso_ate-9)/10;
                    //printf("\nA pessoa %s descansa ate %d\n", nome, descanso_ate);
                    
                }
                //printf("\nA pessoa %s descansa ate %d\n", nome, descanso_ate);
                
                
                if(dia_atual-1 == descanso_ate){
                    //a pessoa ja chegou no fim de seu descanso, devemos fazer as
                    //Alterações
                    //printf("Hoje è %d e a pessoa esta ate %d\n", dia_atual, descanso_ate);
                    
                    for(int i = 0; nome[i] != '\0'; i++){
                        pessoas_descansadas[m][i] = nome[i];
                        if(nome[i+1] == '\0'){
                            pessoas_descansadas[m][i+1] = '\0';
                        }
                    }
                    m++;
                    
                }
                else{
                    //Pessoa não descansou ainda
                    strcat(linhas_salvas[k], linha);
                    k++;
                }
                
                
                
                
                
            }
            
            fclose(descansado);
            
            ////////////////////////////////////////////////
            
            for(int p = 0; p<m; p++){
                for(int j = 0; j<quantidade; j++){
                    if(!strcmp(alunos[j].nome, pessoas_descansadas[p])){
                        //printf("Achei %s na pos %d\n ", alunos[j].nome, j);
                        alunos[j].condições = 1;
                        //printf("Coloquei %s em condições.", alunos[j].nome);
                        
                    }
                }
            }
            
            ///////////////////////////////////////////////
            //printf("%d", m);
            if(m > 0){
                //printf("Exc pois %d", m);
                FILE *alterando_condi;
                
                alterando_condi = fopen("alunos.txt", "w+");
                
                for(int i = 0; i<quantidade; i++){
                    
                    fprintf(alterando_condi, "%s", alunos[i].nome);
                    fprintf(alterando_condi, ",%d", alunos[i].servi_ala);
                    fprintf(alterando_condi, ",%d", alunos[i].servi_3);
                    fprintf(alterando_condi, ",%d", alunos[i].servi_senti);
                    fprintf(alterando_condi, ",%d", alunos[i].baixado);
                    fprintf(alterando_condi,  ",%d\n", alunos[i].condições);
                }
                
                
                fclose(alterando_condi);
                
                
                FILE *mudando_descanso;
                
                mudando_descanso = fopen("descanso.txt", "w+");
                
                for(int i = 0; i<k; i++){
                    fprintf(mudando_descanso, "%s", linhas_salvas[i]);
                }
                
                fclose(mudando_descanso);
                }
            
        }
        
        //Devemos ter uma opção se o usuario realmente quer ver essa escala, pois ela é grande demais
        
        
        
        //Apresentação da lista
        printf("\nMilitares --- ALA --- 3º PISO --- SENTINELA\n");
        {
            int apresentar(int i){
                
                printf("%s", alunos[i].nome);
                
                //Apesar dos nomes terem diferentes tamanhos, devemos ser capazes de
                //ter uma formatação adequada
                int tam = strlen(alunos[i].nome);
                
                
                //Para ala
                int num = 16 - tam;
                for(int i_ = 1; i_ != num; i_++){
                    printf("-");
                }
                printf("%d", alunos[i].servi_ala);
                
                
                //Para 3º piso
                for(int i_ = 1; i_ != 11; i_++){
                    printf("-");
                }
                printf("%d", alunos[i].servi_3);
                
                
                for(int i_ = 1; i_ != 12; i_++){
                    printf("-");
                }
                printf("%d\n", alunos[i].servi_senti);
                
                return 0;
            }
            
            
            //Devemos saber se a pessoa esta de serviço hoje
            char pessoas_hoje[15][15];
            int quant_ = 0;
            int tipo[15]; //Para sabermos qual serviço é
            {
                FILE *hoje;
                
                char arquivo[12] = "escala_";
                
                char dia_atu[3];
                sprintf(dia_atu, "%d", dia_atual);
                
                strcat(arquivo, dia_atu);
                strcat(arquivo, ".txt");
                arquivo[(int)strlen(arquivo)] = '\0';
                
                hoje = fopen(arquivo, "r");
                
                if(hoje == NULL){
                    //nada a fazer
                }
                else{
                    
                    
                    char linha_[15];
                    int m = 0;
                    
                    int y = 1;
                    
                    while(!feof(hoje)){
                        fgets(linha_, 15, hoje);
                        linha_[(int)strlen(linha_)] = '\0';
                        //printf("%s", linha_);
                        
                        for(int i = 0; linha_[i] != '\n'; i++){
                            pessoas_hoje[m][i] = linha_[i];
                            if(linha_[i+1] == '\n'){
                                pessoas_hoje[m][i+1] = '\0';
                                tipo[m] = y;
                                m++;
                            }
                        }
                        
                        //printf("%s\n", pessoas_hoje[m-1]);
                        
                        if(linha_[0] <= 98 && linha_[0] >=65){
                            //Quer dizer que existe um nome
                        }
                        else{
                            //quando há pulo de linha_
                            y++;
                            
                        }
                        
                    }
                    quant_ = m;
                    
                    fclose(hoje);
                    
                    
                    
                    
                }
                
                
                
                
                
            }
            
            /*
            for(int g = 0; g<quant_; g++){
                printf("Militar %s no tipo %d\n", pessoas_hoje[g], tipo[g]);
            }
            */
            
            //Devemos colocar essas pessoas no descanso e nos dados
            {
                
                char ja_presentes[35][15];
                int n = 0;
                
                
                /////////////////////////////////////////
                FILE *vendo_descanso;
                
                vendo_descanso = fopen("descanso.txt", "r");
                char linha[20];
                char nome[20];
                char dia_final_[35][4];
                
                while(!feof(vendo_descanso)){
                    fflush(stdin);
                    fflush(stdout);
                    fgets(linha, 20, vendo_descanso);
                    
                    
                    int j = 0;
                    while(linha[j] != ','){
                        
                        nome[j] = linha[j];
                        
                        j++;
                        
                    }
                    
                    //linha[j] = ','
                    nome[j] = '\0';
                    
                    
                    
                    
                    j++;
                    int p = 0;
                    
                    while(linha[j] != '-'){
                        dia_final_[n][p] = linha[j];
                        p++;
                        //printf("%c",linha[j]);
                        j++;
                    }
                    dia_final_[n][p] = '\0';
                    
                    
                    //printf("eu obtive %s ate %s\n", nome, dia_final_[n]);
                    
                    
                    j = 0;
                    while(nome[j] != '\0'){
                        ja_presentes[n][j] = nome[j];
                        j++;
                    }
                    ja_presentes[n][j] = '\0';
                    
                    
                    n++;
                    
                    
                }
                
                fclose(vendo_descanso);
                
                /////////////////////////////////////////
                
                FILE *descansando;
                
                descansando = fopen("descanso.txt", "a");
                
                for(int i = 0; i < quant_;i++){
                    //vamos ver quem esta de serviço hoje
                    int o = 0;
                    //printf("A pessoa %s esta de serviço hoje\n", pessoas_hoje[i]);
                    for(int j = 0; j < n; j++){
                        //ver quem está na lista de descanso
                        
                        if(!strcmp(ja_presentes[j], pessoas_hoje[i])){
                            //printf("A pessoa %s esta na descanso e esta de serviço(%s)\n", pessoas_hoje[i], ja_presentes[j]);
                            
                            o++;
                            break;
                        }
                        
                        
                        
                    }
                    
                    if(o){
                        //achei a pessoa, 
                        //printf("A pessoa %s esta na listadd\n", pessoas_hoje[i]);
                        
                        continue;
                        
                    }
                    else{
                        //a pessoa não esta presente na lista de descanso
                        //printf("A pessoa %s(%d) NAO esta na lista\n", pessoas_hoje[i], (int)strlen(pessoas_hoje[i]));
                        
                        
                        //Devemos verificar se ha uma pessoa que não esta de serviço e esta no descanso
                        
                        //pois esse else é caso tenhamos alguem de serviço e não no descanso
                        
                        
                        int dia_ate = dia_atual + 3;
                        if(dia_ate > 31){
                            dia_ate -= 31;
                        }
                        
                        //Adicionando no descanso,
                        fprintf(descansando, "\n%s,%d-", pessoas_hoje[i], dia_ate);
                        
                        //Mudando na lista de alunos
                        
                        //Vamos adicionar em uma unidade os serviços.
                        if(tipo[i] == 1){
                            
                            //serviço na ala.
                            for(int g = 0; g < quantidade; g++){
                                //printf("Comparando %s com %s\n", pessoas_hoje[i], alunos[g].nome);
                                if(!strcmp(pessoas_hoje[i], alunos[g].nome)){
                                    //printf("Estou adicionando %s no tipo %d\n",alunos[g].nome, tipo[i]);
                                    alunos[g].servi_ala++;
                                    break;
                                }
                            }
                        }
                        else{
                            if(tipo[i] == 2){
                                
                                //serviço no 3
                                for(int g = 0; g< quantidade; g++){
                                    if(!strcmp(pessoas_hoje[i],alunos[g].nome)){
                                        //printf("Estou adicionando %s no tipo %d\n",alunos[g].nome, tipo[i]);
                                        alunos[g].servi_3++;
                                        break;
                                    }
                                }
                                
                            }
                            else{
                                if(tipo[i] == 3){
                                    
                                    //sentinela
                                    for(int g = 0; g< quantidade; g++){
                                        if(!strcmp(pessoas_hoje[i],alunos[g].nome)){
                                            //printf("Estou adicionando %s no tipo %d\n",alunos[g].nome, tipo[i]);
                                            alunos[g].servi_senti++;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        
                        FILE *tirando_condi;
                        
                        tirando_condi = fopen("alunos.txt", "w+");
                        
                        for(int g = 0; g< quantidade; g++){
                            if(!strcmp(alunos[g].nome, pessoas_hoje[i])){
                                alunos[g].condições = 0;
                                //printf("Estou tirando condiçpões de %s ", alunos[g].nome);
                            }
                            
                            fprintf(tirando_condi, "%s", alunos[g].nome);
                            fprintf(tirando_condi, ",%d", alunos[g].servi_ala);
                            fprintf(tirando_condi, ",%d", alunos[g].servi_3);
                            fprintf(tirando_condi, ",%d", alunos[g].servi_senti);
                            fprintf(tirando_condi, ",%d", alunos[g].baixado);
                            fprintf(tirando_condi,  ",%d\n", alunos[g].condições);
                            //printf("  Coloquei %d\n", alunos[g].condições);
                            
                        }
                        
                        fclose(tirando_condi); //Estava errando isso, parece que é importante
                        
                        
                        //////////////////////////////////////////////////////////
                        
                        
                        
                        
                        
                        
                        
                        
                        
                    }
                    
                    
                }
                
                fclose(descansando);
                
            }
            
            
            
            int esta_serviçohoje(char *militar){
                
                
                int m = 0;
                while(1){
                    if(m == 15){
                        //Se ja repetiu 16 vezes e nada, com certeza é pq não tem ninguem de serviço
                        break;
                    }
                    
                    //printf("%d: %s e %s\n", !strcmp(militar, pessoas_hoje[m]), militar, pessoas_hoje[m]);
                    
                    if(!strcmp(militar, pessoas_hoje[m])){
                        return 1;
                    }
                    
                    
                    
                    m++; //ESQUECEU ISSO
                }
                
                
                return 0;
            }
            
           
            //printf("%d", esta_serviçohoje("Naila"));
            
            for(int i = 0; i<quantidade; i++){
                if(alunos[i].baixado){
                    //Está baixado? Sim!
                    printf("\033[31m");
                    
                    apresentar(i);
                    
                    printf("\033[0m\033[7m\033[1m");
                }
                else{
                    //Está baixado? Não!
                    
                    if(alunos[i].condições){
                        //Está em condições?
                        apresentar(i);
                    }
                    else{
                        
                        if(esta_serviçohoje(alunos[i].nome)){
                            printf("\033[34m"); 
                        
                            apresentar(i);
                        
                             printf("\033[0m\033[7m\033[1m");
                        
                        }
                        else{
                            printf("\033[33m");
                        
                            apresentar(i);
                        
                            printf("\033[0m\033[7m\033[1m");
                        
                        }
                        
                        
                    }
                
                }
                
            }
            
            printf("\n\033[34mAzul - Servico_Hoje\n\033[0m\033[1m\033[7m");
            printf("\033[33mAmarelo - 48h\033[0m\033[7m\033[1m\n\033[31mVermelho - Baixado\033[0m\033[7m\033[1m");
        }
        
        
        //MENU
        int opcao;
        {
            printf("\n\n 0 - Alterações");
            printf("\n 1 - Escalar Militares");
            printf("\n 2 - Baixados");
            printf("\n 3 - Sair");
            printf("\n\nInforme a sua decisão: ");
            scanf("%d", &opcao);
            
            while(opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3){
                printf("\033[31mOpcao Invalida\033[0m\033[7m\033[1m");
                printf("\n\nInforme a sua decisão: ");
                scanf("%d", &opcao);
            }
            
        }
        
        
        //Operações
        //Devemos ter também a capacidade de criarmos um arquivo txt mostrando a escala
        if(opcao == 3){
            break;
        }
        else{
            if(opcao == 0){
                //Para fazermos Alterações
                
                /*Sempre que formos baixar alguem devemos vir aqui e colocá-lo.
                Porém, o programa deve ser capaz de tirar os baixados automaticamente
                e de colocar e tirar os de decanso.
                */
                
                system("clear");
                
                //Obtendo o nome do baixado
                char militar[20];
                {
                    printf("\nInforme o nome do baixado(digite sair para sair): ");
                    scanf("%s", militar);
                    militar[(int)strlen(militar)] = '\0';
                    if(militar[0] >= 97 && militar[0] <= 122){
                        //Quer dizer que a primeira letra esta pequena
                        militar[0] -= 32;
                        
                    }
                    
                    //De posse do nome, devemos fazer a verificação se ele existe
                    int ver_existe(){
                        
                        if(!strcmp(militar, "sair")){
                            return 1;
                        }
                        
                        for(int i = 0; i<quantidade; i++){
                            if(!strcmp(militar, alunos[i].nome)){
                                //printf("Achei uma correspondencia;");
                                return 1;
                            }
                        }
                        
                        return 0;
                    }
                    
                    while(!ver_existe() && strcmp(militar, "Sair")){
                        printf("\033[31mEssa pessoa não está registrada\033[0m\033[7m\033[1m\n\n");
                        printf("\nInforme o nome do baixado(digite sair para sair): ");
                        scanf("%s", militar);
                        militar[(int)strlen(militar)] = '\0';
                        if(militar[0] >= 97 && militar[0] <= 122){
                            //Quer dizer que a primeira letra esta pequena
                            militar[0] -= 32;
                        }
                    }
                }
                
                //Obtendo até que dia ficará baixada
                char data[5];
                int dia=1;
                int mes=1;
                {
                    int i_ = 0;
                    do{
                        if(i_){
                            printf("\033[31mData Não Existe\033[0m\033[7m\033[1m");
                        }
                        
                        
                        printf("\nInforme até que data(AB/XY) esta pessoa estara baixada: ");
                        scanf("%s", data);
                        fflush(stdin);
                        
                        if(data[0] == 0){
                            dia = data[1] - 48;
                        }
                        else{
                            char dia_[2];
                            dia_[0] = data[0];
                            dia_[1] = data[1];
                            dia_[2] = '\0';
                            dia = atoi(dia_);
                        }
                        //printf("Eu Consegui entender o dia %d", dia);
                        
                        
                        if(data[3] == 0){
                            mes = data[4] - 48;
                        }
                        else{
                            char mes_[2];
                            mes_[0] = data[3];
                            mes_[1] = data[4];
                            mes_[2] = '\0';
                            mes = atoi(mes_);
                        }
                        
                        //printf("A pessoa estara baixada ate %d do %d", dia, mes);
                        
                        i_++;
                    }while(((dia<1 || dia>31) || (mes<1 || mes>12)) || ((dia<dia_atual && mes == mes_atual) || (mes<mes_atual)));
                    
                    //Devemos analisar também se essa data esta no futuro ou no passado. 
                    //Deve dar problema so em Dezembro~Janeiro
                    
                    
                }
                
                
                //Obtendo o motivo
                char motivo[100];
                {
                    
                    printf("\nInforme o motivo do baixamento: ");
                    scanf(" %[^\n]", motivo);
                    motivo[(int)strlen(motivo)] = '\0';
                    
                }
                
                
                
                //Confirmado que ela existe,e tendo a informação, podemos fazer as alterações
                //Alem disso, apos ela ser registrada como baixada, devemos fazer uma verificação nas escalas que ja estão prontas 
                //para ver se estara de serviços nos proximos dias!
                
                //Adicionando ao sistema
                {
                    //Na escala
                    {
                        FILE *baixando;
                        
                        baixando = fopen("alunos.txt", "w+");
                        
                        for(int i = 0; i<quantidade; i++){
                            
                            if(!strcmp(alunos[i].nome, militar)){
                                alunos[i].baixado = 1;
                            }
                            
                            
                            fprintf(baixando, "%s", alunos[i].nome);
                            fprintf(baixando, ",%d", alunos[i].servi_ala);
                            fprintf(baixando, ",%d", alunos[i].servi_3);
                            fprintf(baixando, ",%d", alunos[i].servi_senti);
                            fprintf(baixando, ",%d", alunos[i].baixado);
                            fprintf(baixando,  ",%d\n", alunos[i].condições);
                        }
                        
                        
                        fclose(baixando);
                    }
                    
                    
                    //Nos dados
                    {
                        //Devemos fazer essa parte melhor, colocando a data que a pessoa entrou de serviço
                        
                        
                        FILE *registrando;
                        
                        registrando = fopen("baixados.txt", "a");
                        
                        fprintf(registrando, "\n%s{%d/%d=%d/%d}%s-", militar, dia_atual, mes_atual, dia, mes, motivo);
                        
                        
                        fclose(registrando);
                    }
                    
                }
                
                
                system("clear");
                
                //Sabendo do baixado, é de EXTREMA IMPORTANCIA verificarmos se essa pessoa está de serviço
                //pelos proximos dias. Sendo assim,
                
                int o = 0;
                //Verificando 
                {
                    
                    int dif_data(char *dia_futur){
                        //Verifiicanod se a pessoa está baixada nesse dia
                        
                        int dia_futuro = atoi(dia_futur);
                        
                        if(mes == mes_atual){
                            if(dia_futuro <= dia){
                                return 1;
                            }
                        }else{
                            return 1;
                        }
                       return 0;
                    }
                    
                    
                    for(int j = 1; 1 ; j++){
                        FILE *verificando;
                        
                        //Para conseguirmos varrer todas as escalas.
                        char arquivo[12] = "escala_";
                        char dia_futu[3];
                        
                        if(dia+j <= 31){
                            sprintf(dia_futu, "%d", dia_atual+j);
                        }
                        else{
                            sprintf(dia_futu, "%d", dia_atual+j - 31);
                        }
                        
                        
                        strcat(arquivo, dia_futu);
                        strcat(arquivo, ".txt");
                        arquivo[(int)strlen(arquivo)] = '\0';
                        
                        //PQP, cruzamento de datas são muito dificieis, por exemplo, fazer escalas de 25 ate 03 do mes seguinte!!!
                        
                        
                        verificando = fopen(arquivo, "r");
                        
                        if(verificando == NULL){
                            //printf("\nEu parei na interação %d e estava tentando abrir %s\n", j, arquivo);
                            //EU SOU MUITO FODA
                            
                            //Como chegamos no final, não há mais escalas pra se ver
                            
                            break;
                            
                            
                            
                        }
                        else{
                            //printf("Entrei em %s\n", arquivo);
                            
                            char linha[20];
                            
                            //Devemos varrer as linhas
                            while(!feof(verificando)){
                                fgets(linha, 20, verificando);
                                linha[(int)strlen(linha)] = '\0';
                                
                                
                                //ISSO AQUI FOI INSANO
                                for(int i = 0; linha[i] != '\0'; i++){
                                    if(linha[i+1] == '\0'){
                                        linha[i] = '\0';
                                        break;
                                    }
                                    //printf("Estou lendo %c\n", linha[i]);
                                    
                                }
                                
                                
                                
                                
                                
                                //Achamos a pessoa na escala, devemos ver se ela ja está desbaixada no dia
                                if(!strcmp(militar, linha) && dif_data(dia_futu)){
                                    //printf("cheguie");
                                    //O nome estava dando problema, mas é so fazê-lo de novo
                                    char arquivo[12] = "escala_";
                                    char dia_futu[3];
                                    sprintf(dia_futu, "%d", dia_atual+j);
                                    strcat(arquivo, dia_futu);
                                    //strcat(arquivo, ".txt"); Nao precisamos disso para esse proposito
                                    arquivo[(int)strlen(arquivo)] = '\0';
                                    
                                    o++;
                                    printf("\n\033[32mA pessoa baixada foi encontrada na %s\a\033[0m\033[7m\033[1m\n", arquivo);
                                    
                                    break; //Se a pessoa ja foi encontrada na escala, ela com certeza não estara dnv
                                    
                                }
                                
                                
                                
                            }
                            
                            //também devemos fazer uma verificação se a dta informada esta no futuro ou no passado
                            
                            
                        }
                        
                        
                    }
                    
                    printf("\n\n");
                }
                
                if(o > 0){
                    printf("\n\033[31mNecessaria Invertenção Nas Escalas!\033[0m\033[7m\033[1m\n\n");
                }
                
                
                
                //Agora, devemos automatizar sempre que abrirmos o programa, ele deve, a partir do dia atual, 
                //verificar se alguem desbaixou, como vamos usar essa função aqui e nas escalas do futuro
                //é bom que seja de fato uma função. Ela deve estar no inicio, pois ocorre no começo!
                
                
                
                
                
            }
            else{
                
                if(opcao == 1){
                    //Fazermos escala de um dia ou de 3 dias no futuro, levando em consideração que ngm baixe.
                    
                    //PQP, cruzamento de datas são muito dificieis, por exemplo, fazer escalas de 25 ate 03 do mes seguinte!!!
                
                    /*lembre do que o Borges falou, durante a criação de uma escala, não devemos colocar uma pessoa 
                    que está baixada, mesmo que ela desbaixe nos proximos dias, NÃO DEVEMOS CONTAR com a imprevisivel 
                    melhora da pessoa.*/
                    
                    
                    
                    //Precisamos de uma nova lista das pessoas que estão em condições e 
                    //não estão baixadas.
                    system("clear");
                    
                    cabecalho("Criando Escala", '*');
                    
                    printf("\nMilitares Prontos Para Serem Escalados: \n");
                    printf("\nMilitares ----- Total ----- Ala ----- 3ºPiso ----- Sentinela\n");
                    
                    //Vamos nos referenciar a cada aluno da seguinte forma:
                    int militares[quantidade*2];
                    int totais[quantidade*2];
                    int ala[quantidade*2];
                    int piso3[quantidade*2];
                    int senti[quantidade*2];
                    
                    int k = 0;
                    
                    
                    for(int j = 0; j<quantidade;j++){
                        int pos = 0;
                        if(alunos[j].condições && !alunos[j].baixado){
                            //printf("%s pronto\n", alunos[j].nome);
                            
                            militares[k] = j; 
                            totais[k] = (alunos[j].servi_ala+alunos[j].servi_3+alunos[j].servi_senti);
                            
                            
                            int m = strlen(alunos[j].nome);
                            pos += m;
                            printf("%s", alunos[j].nome);
                            
                            int num = 18 - m;
                            for(int p = 0; p<num; p++){
                                printf("-");
                                pos++;
                            }
                            
                            printf("%d", totais[k]);
                            
                            if(totais[k] < 10){
                                pos++;
                            }
                            else{
                                pos+=2;
                            }
                            
                            num = 29 - pos;
                            for(int p = 0; p<num; p++){
                                printf("-");
                                pos++;
                            }
                            
                            printf("%d",alunos[j].servi_ala);
                            ala[k] = alunos[j].servi_ala;
                            
                            
                            if(alunos[j].servi_ala < 10){
                                pos++;
                            }
                            else{
                                pos+=2;
                            }
                            
                            num = 40 - pos;
                            for(int p = 0; p<num;p++){
                                printf("-");
                                pos++;
                            }
                            
                            printf("%d", alunos[j].servi_3);
                            piso3[k] = alunos[j].servi_3;
                            
                            if(alunos[j].servi_3 < 10){
                                pos++;
                            }
                            else{
                                pos+=2;
                            }
                            
                            num = 55-pos;
                            for(int p = 0; p<num;p++){
                                printf("-");
                                pos++;
                            
                            }
                            
                            printf("%d\n", alunos[j].servi_senti);
                            senti[k] = alunos[j].servi_senti;
                            
                            k++;
                            
                        }
                    }
                    
                    
                    printf("\nTotal de Militares Prontos: %d\n", k);
                    
                    if(k < 29){
                        printf("\n\033[33mNão há um contingente minimo para que os postos\nfiquem seguros");
                        printf(" durante a semana\n\033[0m\033[1m\033[7m");
                    }
                    
                    
                    //Faça verificações para ver se o sistema esta salvando do jeito certo cada militar
                    
                    /*
                    for(int i = 0; i < k; i++){
                        printf("\nEstou vendo %s que tem %d no total e %d na ala", alunos[militares[i]].nome, totais[i], ala[i]);
                    }
                    Logo, 
                    
                    militares[i] representa a indexação da pessoa no banco de alunos.
                    
                    enquanto o i que tem dentro representa cada pessoa nesse no sistema.
                    
                    */
                    
                    int dia_final;
                    printf("\n\nDeseja fazer uma escala até que dia: ");
                    scanf("%d", &dia_final);
                    
                    int decisao_final;
                    printf("\n\nDesejara mostrar uma tabela com o nome dos militares");
                    printf(" e seus respectivos serviços até o momento no futuro?(1-sim)");
                    scanf("%d", &decisao_final);
                    
                    int tratar_data(int dia){
                        dia += 3;
                        if(dia>31){
                            dia -= 31;
                            return dia;
                        }
                        else{
                            return dia;
                        }
                    }
                    
                    
                    /*Vamos precisar pegar as pessoas prontas em cada dia, levando
                    em consideração as que estão em descanso e ai fazer uma escala do dia.*/
                    
                    //O que acontece aqui não deve mudar nada no geral, pois são escalas do futuro
                    int dia_futuro = dia_atual+1; //atual
                    int semana = dia_semana;
                    
                    //Vamos nos referir a cada pessoa com o index dela
                    if(dia_futuro >31){
                        dia_futuro -= 31;
                    }
                    
                    //printf("Estou comparando %d com %d", dia_futuro, dia_final+1);
                    
                    int con = 0;
                    int z = 0; //Para controlarmos a posição do descanso
                    int descanso[quantidade][2];
                    /*
                        Quando voce ver o nome bizarro, ele foi necessario para retirar as pessoas 
                        do descanso de forma forçada e deviamos colocar outra coisa no lugar...
                    
                    */
                    while(dia_futuro != dia_final+1){
                        
                        
                        //Tratamento das datas
                        {
                            
                            //Em condições ja
                            if(dia_futuro >31){
                                dia_futuro -= 31;
                            }
                            //printf("%d", dia_futuro);
                            
                            semana++;
                            
                            if(semana == 7){
                                semana = 0;
                            }
                            
                            
                        }
                        
                        
                        
                        //Vamos precisar saber que dia é no dia que estaremos trabalhando
                        int tam;
                        int tam_1;
                        int tam_2;
                        int tam_3;
                        char tipo_semana[7][20] = {
                            "Domingo",
                            "Segunda",
                            "Terça",
                            "Quarta",
                            "Quinta",
                            "Sexta",
                            "Sabado"
                            
                        };
                        {
                            //semana = 6; //Para treinarmos
                            if(semana == 6){
                                
                                
                                tam = 13;
                                tam_1 = 4;
                                tam_2 = 3;
                                tam_3 = 6;
                            }
                            else{
                                if(semana == 4 || semana == 0){
                                    //Quinta ou domingo
                                    tam = 9;
                                    tam_1 = 6;
                                    tam_2 = 3;
                                    tam_3 = 0;
                                }
                                else{
                                    tam = 7;
                                    tam_1 = 4;
                                    tam_2 = 3;
                                    tam_3 = 0;
                                }
                            }
                            
                            
                            
                        }
                        
                        printf("\nComecei a executar dia_%d, uma %s\n", dia_futuro, tipo_semana[semana]);
                        
                        
                        //printf("\nHoje é %d é do tipo %d", dia_futuro, semana);
                        //printf("  Vamos precisar de %d na ala, %d no 3 piso, %d em sentinela, total: %d\n\n", tam_1, tam_2, tam_3, tam);
                        
                        
                        //Vamos precisar fazer a escala
                        int escolhidos[tam][2]; //[0] -- Banco de Dados  [1] -- Sistema
                        int escala[tam][2]; 
                        int esta_escala(int identi, int tamanho){
                            
                            for(int i = 0; i < tamanho;i++){
                                //Vamos usar a identificação pelo Banco de Dados
                                if(escala[i][0] == identi){
                                    //achamos a pessoa 
                                    return 1;
                                }
                            }
                            
                            
                            
                            return 0;
                        }
                        int esta_descanso(int index_banco, int TAM){
                        
                            for(int i = 0; i < TAM; i++){
                                if(descanso[i][0] == index_banco){
                                    //achamos a pessoa na lista de descanso
                                    return 1;
                                }
                            }
                            
                            
                            return 0;
                        }
                        {
                            //Não queriamos fazer voltar cada linha entao carteamos
                            if(1){
                                
                                //primeira vez executando, não há pessoas no descanso.
                                
                                int y = 0;
                                int menor = 0;
                                int  p = 0;
                                //Primeiro, pessoas com menor serviço
                                while(1){
                                    if(p == tam){
                                        break;
                                    }
                                    
                                    for(int i = 0; i < k; i++){
                                        if(p == tam){
                                            break;
                                        }
                                        if(totais[i] == menor){
                                            //Achamos alguem com pouco
                                            
                                            if(con == 0){//Primeira execução sem se preocupar com descanso
                                                
                                                escolhidos[y][0] = militares[i]; //Indexação da pessoa no banco de dados;
                                                escolhidos[y][1] = i; //Indexação da pessoa em nosso sistema
                                                y++;
                                                p++;
                                                //printf("Estou escolhendo %s, pois tem %d, Seu (Banco):%d e Index:%d, ALA:%d\n", alunos[militares[i]].nome, totais[i], militares[i], i, ala[i]);
                                            }
                                            else{
                                                //Se nos garantirmos que essa pessoa daqui nao esta no descanso, teremos todos militares fora do descanso automaticamente
                                                
                                                if(!esta_descanso(militares[i], z)){
                                                    //printf("Pessoa %s não esta no descanso e atende as condições, ESCALA\n",alunos[militares[i]].nome);
                                                    escolhidos[y][0] = militares[i]; //Indexação da pessoa no banco de dados;
                                                    escolhidos[y][1] = i; //Indexação da pessoa em nosso sistema
                                                    y++;
                                                    p++;
                                                    
                                                    
                                                    
                                                    //VERIFICA BEM ISSO
                                                    
                                                }
                                                else{
                                                    //Não vai fazer nada
                                                    //printf("A pessoa %s ESTA na descanso\n", alunos[militares[i]].nome);
                                                }
                                                
                                                
                                                
                                                
                                            }
                                            
                                            
                                            
                                        }
                                    }
                                    
                                    
                                    menor++;
                                }
                                
                                /*
                                for(int i = 0; i < y; i++){
                                    //printf("\nMilitar:%s (Banco):%d Index:%d Total:%d Ala:%d\n", alunos[escolhidos[i][0]].nome, militares[escolhidos[i][1]], escolhidos[i][1], totais[escolhidos[i][1]], ala[escolhidos[i][1]]);
                                }
                                
                                */
                                
                                //Dessas pessoas escolhidas, devemos colocar em ordem de serviço
                                //Para tanto devemos colocar as que tem menor quant. em cada tipo.
                                
                                //ALA
                                p = 0;
                                menor = 0;
                                //printf("ALA\n");
                                while(1){
                                    if(p == tam_1){
                                        break;
                                    }
                                    
                                    for(int i = 0; i < y; i++){
                                        //vamos varrer a lista de escolhidos
                                        if(p == tam_1){
                                            break;
                                        }
                                        if(ala[escolhidos[i][1]] == menor){
                                            
                                            
                                            //Esse con == 0 era para não nos preocuparmos com o descanso, mas safamos no inicio
                                            if(1){ //primeira execução
                                                //pegamos a pessoa com menor quantidade de serviço na ala
                                                //printf("%s, Total: %d, Ala: %d\n", alunos[escolhidos[i][0]].nome,totais[escolhidos[i][1]], ala[escolhidos[i][1]]);
                                                escala[p][0] = escolhidos[i][0];
                                                escala[p][1] = escolhidos[i][1]; // devemos usar para os serviços
                                            }
                                            
                                            p++;
                                        }
                                        
                                        
                                    }
                                    
                                    menor++;
                                }
                                
                                
                                /*
                                for(int i = 0; i<tam_1;i++){
                                    printf("A pessoa %s esta na escala ja.\n", alunos[escala[i][0]].nome);
                                }
                                */
                                
                                //Vamos montar para piso3
                                //printf("\nPiso3\n");
                                /*
                                verificando se funciona
                                for(int i = 0; i < y; i++){
                                    //printf("%s esta na escala? %d\n", alunos[escolhidos[i][0]].nome, esta_escala(escolhidos[i][0],tam_1));
                                }
                                */
                                menor = 0; 
                                p = 0;
                                //printf("3 piso\n");
                                while(1){
                                    if( p == tam_2){
                                        break;
                                    }
                                    
                                    for(int i = 0; i < y; i++){
                                        if( p == tam_2){
                                            break;
                                        }
                                        
                                        if(piso3[escolhidos[i][1]] == menor){
                                            if(!esta_escala(escolhidos[i][0],tam_1)){
                                                if(1){
                                                    //Vamos verificar se essa pessoa ja esta na ala.
                                                    escala[p+tam_1][0] = escolhidos[i][0];
                                                    escala[p+tam_1][1] = escolhidos[i][1];
                                                   // printf("Estou escolhendo %s pois tem %d\n", alunos[escolhidos[i][0]].nome,piso3[escolhidos[i][1]]);
                                                }
                                                
                                                p++;
                                            }
                                        }
                                    }
                                    
                                    
                                    
                                    menor++;
                                }
                                
                                
                                
                                
                                
                                //Sentinel
                                //printf("\nSentinela\n");
                                menor = 0; 
                                p = 0;
                                while(1){
                                    if(p==tam_3){
                                        break;
                                    }
                                    
                                    
                                    for(int i = 0; i < y;i++){
                                        if(p==tam_3){
                                            break;
                                        }
                                        
                                        if(senti[escolhidos[i][1]]==menor){
                                            if(!esta_escala(escolhidos[i][0],tam_1+tam_2)){
                                                if(1){
                                                    escala[p+tam_1+tam_2][0] = escolhidos[i][0];
                                                    escala[p+tam_1+tam_2][1] = escolhidos[i][1];
                                                    //printf("Estou escolhendo %s pois tem %d\n", alunos[escolhidos[i][0]].nome,senti[escolhidos[i][1]]);
                                                
                                                }
                                                p++;
                                            }
                                        }
                                        
                                    }
                                    
                                    
                                    
                                    
                                    
                                    menor++;
                                }
                                
                                
                                
                            }
                            
                        }
                        
                        
                        for(int j = 0; j < tam; j++){
                            printf("A escala tem %s.\n", alunos[escala[j][0]].nome);
                        }
                        
                        
                        
                        
                        //Escala ja em condiçoes
                        printf("\n");
                        //Vamos criar a escala.txt do dia com essas pessoas
                        {
                            FILE *criando;
                            char arquivo[12] = "escala_";
                            char dia_f[3];
                            
                            sprintf(dia_f, "%d", dia_futuro);
                            strcat(arquivo,dia_f);
                            strcat(arquivo, ".txt");
                            
                            //printf("\n\n%s", arquivo);
                            
                            criando = fopen(arquivo, "w+");
                            
                            
                            
                            for(int i = 0; i < tam; i++){
                                //printf("  Estou escrevendo pela %d  ", i);
                                if(i == tam_1){
                                    //saindo da ala e indo para 3 piso
                                    fprintf(criando, "\n");
                                    //printf("Completei todos na ala %d\n", tam_1);
                                    
                                }
                                
                                if(i == tam_1 + tam_2){
                                    //saindo do 3 piso para sentinela
                                    fprintf(criando, "\n");
                                    //printf("Completei todos no piso 3%d\n", tam_2);
                                    
                                }
                                
                                fprintf(criando, "%s\n", alunos[escala[i][0]].nome);
                                //printf("Eu coloquei na escala %s\n", alunos[escala[i][0]].nome);
                            }
                            
                            
                            fclose(criando);
                        }
                        printf("\n");
                        
                        
                        //Vamos tratar a entrada e saida de pessoas no descanso
                        {
                            
                            //printf("\n\n");
                            if(con >= 2){
                                //Substituições
                                
                                int i_des = 0; //Vamos varrer a lista de descanso
                                int i_esc = 0; //Vamos varrer a lista de escala
                                while(1){
                                    
                                    if(i_des == z || i_esc == tam){
                                        //lista de descanso acaba
                                        //lista de de escala acaba
                                        break;
                                    }
                                    
                                    if(descanso[i_des][1]-1 == dia_futuro){
                                        //printf("\nA pessoa %s foi substituida por  ", alunos[descanso[i_des][0]].nome);
                                        
                                        descanso[i_des][0] = escala[i_esc][0];
                                        descanso[i_des][1] = tratar_data(dia_futuro);
                                        
                                        //printf("%s e este saira %d\n", alunos[descanso[i_des][0]].nome, descanso[i_esc][1]);
                                        i_esc++;
                                        
                                    }
                                    
                                    
                                    
                                    i_des++;
                                }
                                
                                //pode ser que ainda falte alunos da escala a serem acrescentados
                                int i_cart = 0;
                                if(i_esc < tam){
                                    //Como so fizemos subsituições não alteramos o tamanho, Logo
                                    
                                    while(1){
                                        if(i_esc == tam){
                                            break;
                                        }
                                        
                                        descanso[z+i_cart][0] = escala[i_esc][0];
                                        descanso[z+i_cart][1] = tratar_data(dia_futuro);
                                        //printf("Adicionei %s em %d\n",alunos[descanso[z+i_cart][0]].nome, z+i_cart);
                                        i_cart++;
                                        i_esc++;
                                    }
                                    
                                    z += i_cart;
                                    
                                }
                                
                                //Pode ser que ainda falte militares no descanso para sair, 
                                //mesmo com a escala ja toda dentro
                                //printf("\ni_des = %d e o tamanho do descanso %d\n", i_des+=i_cart, z);
                                if(i_des+=i_cart < z){
                                    
                                    for(int i_ = 0; i_ < z; i_++){
                                        if(descanso[i_][1]-1 == dia_futuro){
                                            //printf(" %s para saiu forçadamente para %d\n", alunos[descanso[i_][0]].nome, dia_futuro+1);
                                            descanso[i_][0] = -1;
                                            descanso[i_][1] = dia_futuro+1;
                                            
                                        }
                                    }
                                    
                                    
                                }
                                
                                
                                
                                
                            }
                            else{
                                //So adicionar ate talo 
                                for(int  i = 0; i < tam; i++){
                                    //vamos varrer a escala feita e adicionar ao descanso
                                    descanso[z+i][0] = escala[i][0];
                                    descanso[z+i][1] = tratar_data(dia_futuro);
                                    
                                    
                                    
                                    //printf("Na pos(%d) do descanso: adiciono %s e saira %d\n", z+i, alunos[escala[i][0]].nome, descanso[z+i][1]);
                                    
                                    
                                }
                                
                                z += tam;
                                
                            }
                            //printf("\n\n\n");
                        }
                        
                        
                        //Teste do descanso
                        /*
                        printf("\n\nTemos %d militares no descanso.\n", z);
                        for(int j = 0; j < z; j++){
                            printf("(%d)Militar: %s descansando ate %d\n",j, alunos[descanso[j][0]].nome, descanso[j][1]);
                        }
                        printf("\n\n");
                        */
                        
                        
                        //Vamos precisar adicionar em uma unidade os serviços!
                        //Vamos fazer aqui por fora pois estava dando problema
                        {
                            for(int i = 0; i < tam; i++){
                                //printf("  Estou escrevendo pela %d  ", i);
                                totais[escala[i][1]]++;
                                if(i < tam_1){
                                    //printf("%s esta na ALA\n", alunos[escala[i][0]].nome);
                                    ala[escala[i][1]]++;
                                    
                                }
                                else{
                                    if(i < tam_2+tam_1){
                                        //printf("%s esta no 3 piso\n",alunos[escala[i][0]].nome );
                                        piso3[escala[i][1]]++;
                                    }
                                    else{
                                        //printf("%s esta na sentinela\n",alunos[escala[i][0]].nome );
                                        senti[escala[i][1]]++;
                                    }
                                }
                            }
                        }
                        
                        
                        
                        con++;
                        dia_futuro++;
                        
                        
                    }
                    
                    
                    if(decisao_final){
                        printf("\n\nMilitares ----- Total ----- Ala ----- 3ºPiso ----- Sentinela\n");
                        
                        
                        for(int m = 0; m < k; m++){
                            int pos = 0;
                            
                            int tamanho_nome = strlen(alunos[militares[m]].nome);
                            pos += tamanho_nome;
                            printf("%s",alunos[militares[m]].nome);
                            
                            int num = 18 - tamanho_nome;
                            for(int i = 0; i < num; i++){
                                printf("-");
                                pos++;
                            }
                            
                            
                            printf("%d", totais[m]);
                            if(totais[m] < 10){
                                pos++;
                            }
                            else{
                                pos += 2;
                            }
                            
                            
                            num = 29 - pos;
                            for(int i = 0; i < num; i++){
                                printf("-");
                                pos++;
                            }
                            
                            printf("%d", ala[m]);
                            if(ala[m] < 10){
                                pos++;
                            }
                            else{
                                pos += 2;
                            }
                            
                            
                            num = 40 - pos;
                            for(int i = 0; i < num; i++){
                                printf("-");
                                pos++;
                            }
                            
                            printf("%d", piso3[m]);
                            if(piso3[m] < 10){
                                pos++;
                            }
                            else{
                                pos += 2;
                            }
                            
                            
                            num = 55-pos;
                            for(int p = 0; p<num;p++){
                                printf("-");
                                pos++;
                            
                            }
                            
                            printf("%d\n", senti[m]);
                            
                        }
                    }
                    
                    
                
                
                
            }
        
                else{
                    if(opcao == 2){
                        //Mostrar uma planilha de baixados
                        
                        menu_baixados();
                    }
                    
                }
        
            }
        
        sanha_insano++;
        }
    
    }
    
    
    printf("\033[0m");
    return 0;
}
//fim