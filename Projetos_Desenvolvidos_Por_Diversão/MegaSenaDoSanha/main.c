/*
Contextualização:
/*
    Devem-se marcar de 6 a 15 números entre 60 disponíveis em um ÚNICO cartão.
    Neste único cartão, temos valores que vão de 1 até 60.
    
    O sistema deve ser capaz de escolher os números para o usuário, SURPRESINHA,
    e/ou concorrer a 2, 4 ou 8 concursos consecutivos com o mesmo cartão.
    
    O prêmio bruto corresponde a 46% da arrecadação, já com o adicional destinado
    à outra instituição. Dessa porcentagem, ????:
    
    35% são distribuídos entre os acertadores dos 6 números sorteados.
    20% entre os acertadores de 5 números.
    20% entre os de 4 números.
    25% restantes são acumulados e dado ao governo.
    
    IMPORTANTE:
    Não havendo acertador em qualquer faixa, o valor acumula para o concurso
    seguinte.
*/

//////////////////////////////////////////////////////////////////////

/*
Objetivo e Necessidades:
/*
    É interessante planejar a quantidade de números a se jogar assim como a quantidade
    de apostas a se fazer, de tal maneira que seja adequado à situação financeira e
    à crença da vitória.
    
    O sistema deve ter como entrada:
        -> O valor da arrecadação do concurso.
        -> Para cada jogador do concurso:
            -> Quantidade de Cartões: Min 1 e Max 5
            -> Quantidade de Números de Cada Cartão: Min 6 e Max 10
            -> Números de Cada Cartão
            
        Deve haver verificações dentro da entrada a fim de que os valores estejam
        no intervalo correto.
        
    O sistema deve ser capaz de:
        -> Calcular o sorteio de 6 números para cada concurso
        -> Permitir que o concurso seja válido enquanto houver jogadores interessados: Max 5
            -> Criar flag para indicar que não há mais jogadores interessados.
        -> Permitir que cada jogador possa jogar com vários cartões e vários números por cartão.
        -> Os números apostados e sorteados devem ser inteiros entre 1 e 60, SEM REPETIÇÕES.
        -> Informar a quantidade de vencedores e seus respectivos prêmios.
        -> Permitir que o usuário jogue a surpresinha, definindo a seu critério a quantidade de números do cartão.
        -> Permitir que o jogador jogue a Teimosinham, jogando com os mesmos cartões por jogos consecutivos.
*/

//////////////////////////////////////////////////////////////////////

/*
Obrigações:
/*
    Possuir as seguintes Funções:
        -> exibe_arrecadacao()
            * Exibir valor total do concurso
            
        -> exibe_numeros_sorteio()
            * Exibir números sorteados
            
        -> recebe_apostas()
            * Receber apostas até que não haja mais jogadores ou atinja o máximo
            
        -> exibe_apostas()
            * Exibir apostas de todos os jogadores
        
        -> exibe_vencedores()
            * Exibir vencedores e respectivos premios
            
        -> sorteio_manual()
            * Utilizada para inserir manualmente os números do sorteio.
            
    Deve haver pelo menos uma estrutura, struct, a qual deve conter um atributo inteiro
    para armazenar a quantidade de cartões de um jogador e um atributo do tipo array 
    para armazenar todos os números de todos os cartões da aposta do mesmo jogador.
*/

//////////////////////////////////////////////////////////////////////

/*
Considerações Finais e Padronizações:
/*
    -> Opinião:
        Acredito que a forma com que o software é descrito e pedido no pdf da atividade
        é um tanto como confuso e/ou abrangente, não sendo muito específico em como se 
        deseja o resultado final.
        
    -> Padronizações:
        * Documentação de Funções:
            Utilização do DESCRIÇÃO-PARÂMETROS-RETORNO em cada uma das funções.
        
        * Definição de Constantes 'Fixas'
            Utilização do #define e ordenação pela prioridade.
            
        * Alocação Dinâmica
            Utilização do calloc. Em variáveis simples não usaremos a notação do * para 
            o ponteiro, usaremos a notação de array.
            
        * Alocação de Memória
            Utilização máxima possível de alocação dinâmica a fim de aumentar eficiência.
            
        * Forma de Codação
            Preferencialmente vertical.
    


*/

//////////////////////////////////////////////////////////////////////

/*
Versionamento
/*
    v0 -> Início
        
        v0.1 -> Criação de Sistemas de Cores e de Estilização
        
        v0.2 -> Criação de Algumas Funções Base
        
        v0.3 -> Criação dos Sorteios Manual e Automático
    
    v1 -> Desenvolvimento do Recebimento das Apostas
        
        v1.1 -> Função de Receber Jogadores
        
        v1.2 -> Função de Receber Cartões de Cada Jogador
        
        v1.3 -> Função de Receber Números de cada Cartão de cada Jogador
        
        v1.4 -> Função de Visualizar Apostas Feitas pelos jogadores
        
    v2 -> Desenvolvimento da Surpresinha
        
        ...
        
        
        

*/

// Fazendo as devidas importações
#include <stdio.h>  // Básico
#include <stdlib.h>  // Para alocação dinâmica e random
#include <time.h>  // Para utilizarmos o time(NULL)

//////////////////////// Constantes Base //////////////////////////////////////////////

#define QUANTIDADE_DE_NUMEROS_A_SEREM_SORTEADOS 6
#define VALOR_MAXIMO_DE_INTEIRO 60

#define MIN_VALOR_A_SER_SORTEADO 1
#define MAX_VALOR_A_SER_SORTEADO 60

#define MAX_DE_JOGADORES 5
#define MAX_DE_CARTOES 5
#define MIN_QUANT_DE_NUMEROS_NO_CARTAO 6
#define MAX_QUANT_DE_NUMEROS_NO_CARTAO 10

//////////////////////// Estilização de Avisos e de Informações ///////////////////////

typedef struct {
    char tipo_definidor_da_cor;
    char string_representante_da_cor[16];
} Cor;

#define QUANTIDADE_DE_CORES_DISPONÍVEIS 6

Cor ARRAY_DE_CORES[
    QUANTIDADE_DE_CORES_DISPONÍVEIS
] = {
    /*
    Descrição:
        Estrutura que representará as cores disponíveis para avisos.
        Infelizmente, devido à dificuldade de implementação de um hashmap,
        vamos criar apenas algoritmos de busca linear para as cores.
        
    Parâmetros:
        tipo_definidor_da_cor -> Abreviação do nome da cor
        string_representante_da_cor -> Cor em Código ASCII
    */
    {
        // Vermelho
        'r',
        "\033[41m\033[1m"
    },
    {
        // Verde
        'v',
        "\033[42m\033[1m"
    },
    {
        // Amarelo
        'a',
        "\033[43m\033[1m"
    },
    {
        // Ciano
        'c',
        "\033[46m\033[1m"
    },
    {
        // Branco
        'b',
        "\033[7m\033[1m"
    },
    {
        // Nulo
        'n',
        "\033[0m\0"
    }
};

//////////////////////// Características de Cada Jogador //////////////////////////////

typedef struct {
    /*
    Descrição:
        Estrutura que representará as características de cada jogador.
        
    Parâmetros:
        interessado -> Flag indicando se o jogador está interessado em jogar.
            1 - Jogador Interessado
            0 - Jogador Não Interessado
            -1 - Jogador inexistente
        quantidade_de_cartoes -> Total de Cartões que o jogador quer jogar
        array_de_quantidade_de_numeros_em_cada_cartao -> Total de números em cada cartão
        matriz_de_numeros_em_cada_cartao -> Números apostados em cada cartão
    */
    int interessado;
    int quantidade_de_cartoes;
    int* array_de_quantidade_de_numeros_em_cada_cartao;
    int** matriz_de_numeros_em_cada_cartao;
} Jogador;

//////////////////////// Funções Base /////////////////////////////////////////////////

int* inicializando_array_de_inteiros(
    int quantidade_a_ser_inicializada
){
    /* 
    Descrição:
        Função de atalho para não precisarmos inicializar sempre um novo array.
        
    Parâmetros:
        Autoexplicativo.
        
    Retorno:
        Ponteiro para a lista já inicializada.
    */
    
    return (int*) calloc(
        quantidade_a_ser_inicializada,
        sizeof(int)
    );
    
}


int numero_aleatorio(
    int menor_possivel,
    int maior_possivel
){
    /*
    Descrição:
        Função responsável por sortear um número dentro de um intervalo.
    
    Parâmetros:
        Autoexplicativo.
        
    Retorno:
        O número sorteado.
    */
    
    return (
        rand() % (maior_possivel - menor_possivel + 1) + menor_possivel
    );
}

int se_esta_presente(
    int lista_de_numeros[],
    int quantidade_instantanea,
    int valor_alvo
){
    /*
    Descrição: 
        Função responsável por automatizar as verificações de existência.
        Note que como estaremos lidando com uma quantidade pequena de elementos,
        um algoritmo de busca O(n) não será tão destrutivo assim.
        
    Parâmetros:
        int quantidade_instantanea -> Tamanho do array no momento da verificação.
        int valor_alvo -> Alvo a ser verificado existência dentro da lista.
        
    Retorno:
        Booleano representando se está ou não está presente na lista.
    */
    
    int* index = (int*) calloc(
        1,
        sizeof( int )
    );
    
    for(
        index[ 0 ] = 0;
        index[ 0 ] < quantidade_instantanea;
        index[ 0 ]++
    ){
        
        if (
            lista_de_numeros[
                index[ 0 ]    
            ] == valor_alvo
        ){
            // O valor está de fato dentro da lista
            
            free(index);
            
            return 1;
        }
        
        
    }
    
    // Caso finalizemos o loop e não tenhamos achado o alvo
    free(index);
    
    return 0;
    
}

void apresentando_array(
    int lista_de_numeros[],
    int quantidade_de_elementos
){
    /*
    Descrição:
        Função responsável por apresentar um array de números de forma compreensível.
        
    Parâmetros:
        Autoexplicativo.
        
    Retorno:
        Nenhum.
    */
    
    int* index = (int*) calloc(
        1,
        sizeof( int )
    );
    
    for(
        index[ 0 ] = 0;
        index[ 0 ] < quantidade_de_elementos;
        index[ 0 ] = index[ 0 ] + 1
    ){  
        
        if (
            index[ 0 ] == 0
        ){
            // Primeiro valor
            printf(
                "[ %d,",
                lista_de_numeros[index[ 0 ]]
            );
            
        }else{
            
            if (
                index[ 0 ] == (quantidade_de_elementos - 1)    
            ){
                // Último valor
                printf(
                    " %d ]",
                    lista_de_numeros[index[ 0 ]]
                );
                
            }else{
                // Valor intermediário
                printf(
                    " %d,",
                    lista_de_numeros[index[ 0 ]]
                );
                
            }
            
        }
        
    }
    
    free(index);
    
}

int avisando(
    char cor_do_aviso,
    char texto_do_aviso[]
){
    /*
    Descrição:
        Função responsável por, mediante tipo inserido pelo usuário, apresentar
        um aviso ao usuário.
        
    Parâmetros:
        char cor_do_aviso -> letra representando a cor que será apresentada no aviso.
        char texto_do_aviso[] -> o texto do aviso.
        
    Retorno:
        Nenhum, apesar de que adicionamos a notação de return 0 para que ela seja finalizada
        sem ir para outra área do código.
    */
    
    int* index = (int*) calloc(
        1,
        sizeof( int )
    );
    
    for(
        index[ 0 ] = 0;
        index[ 0 ] < QUANTIDADE_DE_CORES_DISPONÍVEIS;
        index[ 0 ] = index[ 0 ] + 1
    ){
        
        // Vamos procurar qual a cor do aviso bate com o primeiro atributo da Cor
        
        if (
            cor_do_aviso == ARRAY_DE_CORES[ index[ 0 ] ].tipo_definidor_da_cor
        ){
            // Se achamos a cor correspondente.
            
            printf(
                "%s",
                ARRAY_DE_CORES[ index[ 0 ] ].string_representante_da_cor
            );
            
            printf(
                "%s",
                texto_do_aviso
            );
            
            printf("\033[0m");
            
            free(index);
            
            // Sem necessidade de continuar o loop
            return 0;
            
        }
        
    }
    
    free(index);
    
    // Caso não tenhamos achado a cor correspondente, devemos avisar o erro
    avisando(
        'r',
        " Não foi possível confirmar a cor. "
    );
    
}

int inserindo_cor(
    char tipo_de_cor    
){
    /*
    Descrição:
        Função responsável por apenas setar uma cor específica na tela.
        
    Parâmetros:
        tipo_de_cor -> abreviação da cor
    
    Retorno:
        Nenhum.
    */
    
    int* index = (int*) calloc(
        1, 
        sizeof( int )
    );
    
    for(
        index[ 0 ] = 0;
        index[ 0 ] < QUANTIDADE_DE_CORES_DISPONÍVEIS;
        index[ 0 ]++
    ){
        if(
            ARRAY_DE_CORES[
                index[ 0 ]
            ].tipo_definidor_da_cor == tipo_de_cor
        ){
            printf(
                "%s",
                ARRAY_DE_CORES[
                    index[ 0 ]    
                ].string_representante_da_cor
            );
            
            free(index);
            
            return 0;
        }    
    }
    
    free(index);
    
    avisando(
        'r',
        "Não foi possível confirmar a cor."
    );
    
}

//////////////////////// Funções Ligadas Ao Sistema ///////////////////////////////////

int* sorteio_manual(){
    /*
    Descrição: 
        Função utilizada para que o usuário insira, portanto, de forma manual
        os números do sorteio.
        
    Parâmetros:
        Nenhum.
        
    Retorno:
        Ponteiro que aponta para o início da lista de inteiros inserida pelo usuário
        e que o sistema usará como se fosse a lista sorteada de forma automática.
    */
    
    // Criando a lista de números
    int* lista_sorteados = inicializando_array_de_inteiros(
        QUANTIDADE_DE_NUMEROS_A_SEREM_SORTEADOS
    );
    
    // Preenchendo com números dados pelo usuário
    int* index = (int*) calloc(
        1,
        sizeof( int )
    );
    
    for(
        index[ 0 ] = 0;
        index[ 0 ] < QUANTIDADE_DE_NUMEROS_A_SEREM_SORTEADOS;
        index[ 0 ]++
    ){
        
        // Variável que irá guardar o número inserido
        int* numero_inserido = (int*) calloc(
            1,
            sizeof( int )
        );
        
        printf(
            "\nInsira o %d° número 'sorteado': ",
            index[ 0 ] + 1
        );
        scanf(
            "%d",
            numero_inserido
        );
        getchar(); // Para evitar o loop infinito que ocorre quando uma letra é digitada.
        
        // Vamos verificar se está no intervalo dos números possíveis.
        if (
            (
                numero_inserido[ 0 ] < MIN_VALOR_A_SER_SORTEADO
            ) || (
                numero_inserido[ 0 ] > MAX_VALOR_A_SER_SORTEADO   
            )
        ){
            // Quer dizer que o número é inválido.
            // Logo, devemos pedir para que seja reinserido o número.
            avisando(
                'a',
                "Número Inválido. Escolha dentro do intervalo."
            );
            
            index[ 0 ]--;
            
            free(numero_inserido);
            
            // Dessa forma, daqui o sistema já reinicia o loop.    
            continue;
        }
        
        // Devemos verificar se o número já está contido dentro da lista.
        if(se_esta_presente(
            lista_sorteados,
            index[ 0 ],
            numero_inserido[ 0 ]
        )){
            // Então como já está presente, não devemos considerá-lo.
            avisando(
                'a',
                "Número Repetido. Insira outro."
            );
            
            index[ 0 ]--;
            
            free(numero_inserido);
            
            continue;
        }
        
        // Caso tenha passado das verificações, vamos adicioná-lo.
        lista_sorteados[
            index[ 0 ]    
        ] = numero_inserido[ 0 ];
        
        // Finalmente liberá-lo
        free(numero_inserido);
        
    }
    
    // Fim do Loop
    free(index);
    
    // Com isso, temos nossa lista criada de forma manual.
    return lista_sorteados;
    
}

int* sorteio_automatico(){
    /*
    Descrição:
        Função responsável por realizar o sorteio real dos números.
    
    Parâmetros:
        Nenhum.
        
    Retorno:
        Ponteiro que iniciará a lista.
    */
    
    int* lista_sorteados = inicializando_array_de_inteiros(
        QUANTIDADE_DE_NUMEROS_A_SEREM_SORTEADOS    
    );
    
    int* index = (int*) calloc(
        1,
        sizeof( int )
    );
    
    for(
        index[ 0 ] = 0;
        index[ 0 ] < QUANTIDADE_DE_NUMEROS_A_SEREM_SORTEADOS;
        index[ 0 ]++
    ){
        
        int* numero_a_ser_colocado = (int*) calloc(
            1,
            sizeof( int )
        );
        
        numero_a_ser_colocado[ 0 ] = numero_aleatorio(
            MIN_VALOR_A_SER_SORTEADO,
            MAX_VALOR_A_SER_SORTEADO
        );
        
        // Devemos verificar apenas se já está incluso.
        if (se_esta_presente(
            lista_sorteados,
            index[ 0 ],
            numero_a_ser_colocado[ 0 ]
        )){
            // Caso já esteja.
            
            index[ 0 ]--;
            
            free(numero_a_ser_colocado);
            
            continue;
        }
        
        // Caso não esteja, vamos inserir
        lista_sorteados[
            index[ 0 ]    
        ] = numero_a_ser_colocado[ 0 ];
        
        free(numero_a_ser_colocado);
        
    }
    
    free(index);
    
    return lista_sorteados;
    
}

void exibindo_numeros_de_sorteio(
    int numeros_sorteados[]
){
    /*
    Descrição:
        Função responsável por exibir de forma mais específica os números sorteados.
        
    Parâmetros:
        Autoexplicativo.
        
    Retorno:
        Nenhum.
    */
    
    avisando(
        'b',
        "Os números sorteados são:"
    );
    
    apresentando_array(
        numeros_sorteados,
        QUANTIDADE_DE_NUMEROS_A_SEREM_SORTEADOS
    );
    
    printf("\n\n");
    
}

Jogador* recebendo_apostas(){
    /*
    Descrição:
        Função responsável por gerenciar as apostas dos jogadores.
        Haverá 3 possibilidades:
            -> Entrada de apostas por arquivo .txt
            -> Entrada de apostas por random
            -> Entrada de apostas pelo usuário
        
    Parâmetros:
        Nenhum.
        
    Retorno:
        Array de jogadores
    */
    
    int se_deseja_surpresinha(){
        /*
        Descrição: 
            Função responsável por perguntar ao usuário se ele deseja sortear os números
            que serão seus.
        
        Parâmetros:
            Nenhum.
            
        Retorno:
            Booleano indicando a decisão.
        */
        
        int* decisao = (int*) calloc(
            1, 
            sizeof( int )
        );
        
        printf(
            "Deseja que seus números sejam sorteados? (1- Sim)(Qualquer Coisa - Não): "    
        );
        scanf(
            "%d",
            decisao
        );
        getchar();
        
        if (*decisao == 1){
            free(decisao);
            return 1;
        }else{
            free(decisao);
            return 0;
        }
        
    }
    
    void configurando_numeros_no_cartao(
        Jogador* lista_de_jogadores,
        int indice_do_jogador,
        int indice_do_cartao
    ){
        /*
        Descrição:
            Função responsável por gerenciar os números que estarão dentro de cada
            cartão.
            
        Parâmetros:
            ponteiro_indicador_da_quantidade_de_numeros -> local na memória em que devemos
                inserir a quantidade de números que foi inserida.
            lista_de_numeros_no_cartao -> array dos números do cartão
        
        Retorno: 
            Nenhum.
        */
        
        int verificando_se_deseja_surpresinha(){
            /*
            Descrição: Função responsável por descobrir */
        }
        
        // Variável temporária para indicar a posição do número no array.
        int* indice_do_numero = (int*) calloc(
            1,
            sizeof( int )
        );
        
        // Variável temporária para guardar o número inserido.
        int* numero_escolhido = (int*) calloc(
            1,
            sizeof( int )
        );
        // Variável temporária flag para indicar a partir de que momento o jogador pode encerrar.
        int* usuario_ja_pode_encerrar = (int*) calloc(
            1,
            sizeof( int )
        );
        
        // Vamos verificar se há a possibilidade de SURPRESINHA
        int* se_deseja_surpresinha = (int*) calloc(
            1,
            sizeof( int )
        );
        if(
            verificando_se_deseja_surpresinha() 
        ){
            se_deseja_surpresinha = 1;
        }
        
        
        
        
        while(1){
            
            printf(
                "\nAposte um número: "
            );
            scanf(
                "%d",
                numero_escolhido
            );
            getchar();
            
            // Verificando se está dentro do intervalo
            if (
                (
                    numero_escolhido[ 0 ] >= MIN_VALOR_A_SER_SORTEADO
                ) && (
                    numero_escolhido[ 0 ] <= MAX_VALOR_A_SER_SORTEADO    
                )
            ){
                // Como está dentro do intervalo, vamos adicionar e alocar mais memória
                
                // Adicionando
                lista_de_jogadores[
                    indice_do_jogador
                ].matriz_de_numeros_em_cada_cartao[
                    indice_do_cartao
                ][
                    indice_do_numero[ 0 ]    
                ] = numero_escolhido[ 0 ];
                
                // Alocando
                lista_de_jogadores[
                    indice_do_jogador
                ].matriz_de_numeros_em_cada_cartao[
                    indice_do_cartao    
                ] = (int*) realloc(
                    lista_de_jogadores[
                        indice_do_jogador
                    ].matriz_de_numeros_em_cada_cartao[
                        indice_do_cartao    
                    ],
                    (
                        indice_do_numero[ 0 ] + 2   
                    ) * sizeof( int )
                );
                
                indice_do_numero[ 0 ]++;
                
            }else{
                
                // Caso não esteja, há o caso de termos digitado 0 para encerrar
                if(
                    !(
                        (
                            numero_escolhido[ 0 ] == 0    
                        ) && (
                            usuario_ja_pode_encerrar[ 0 ]    
                        )
                    )
                ){
                    // Caso não seja no caso específico, podemos avisar sobre o erro.
                    
                    avisando(
                        'a',
                        "\nNúmero Inválido. Escolha dentro do intervalo."
                    );
                    
                    inserindo_cor(
                        'v'    
                    );
                    
                }
                
            }
            
            // Devemos verificar se já é possível encerramento, e caso seja, permitir.
            if(
                (
                    indice_do_numero[ 0 ] >= MIN_QUANT_DE_NUMEROS_NO_CARTAO
                ) && (
                    numero_escolhido[ 0 ] != 0
                )
            ){
                
                printf(
                    "\n(0 - Encerrar Apostas)"    
                );
                
                usuario_ja_pode_encerrar[ 0 ] = 1;
            }
            
            // Devemos fazer a verificação se ele desejou encerrar
            if(
                (
                    (
                        numero_escolhido[ 0 ] == 0    
                    ) && (
                        // Para caso o jogador pressione 0 sem poder encerrrar.
                        usuario_ja_pode_encerrar[ 0 ] == 1    
                    )    
                ) || (
                    indice_do_numero[ 0 ] == MAX_QUANT_DE_NUMEROS_NO_CARTAO    
                )
            ){
                // Vamos encerrar o loop
                
                printf(
                    "\nCartão Apostado.\n"    
                );
                
                break;
                
            }
            
        }
        
        free(numero_escolhido);
        free(usuario_ja_pode_encerrar);
        
        // Devemos setar a quantidade de números neste cartão
        lista_de_jogadores[
            indice_do_jogador    
        ].array_de_quantidade_de_numeros_em_cada_cartao[
            indice_do_cartao    
        ] = indice_do_numero[ 0 ];
        
        printf(
            "Confirmando Apostas: "    
        );
        apresentando_array(
            lista_de_jogadores[
                indice_do_jogador    
            ].matriz_de_numeros_em_cada_cartao[
                indice_do_cartao    
            ],
            indice_do_numero[ 0 ]
        );
        
        free(indice_do_numero);
            
            
        /*if (
                se_deseja_surpresinha()    
            ){
                // Vamos apenas sortear os números do garoto.
                
                int* aleatorio_atual = (int*) calloc(
                    1, 
                    sizeof( int )
                );
                
                while(
                    indice_do_numero[ 0 ] < MAX_QUANT_DE_NUMEROS_NO_CARTAO
                ){
                    
                    aleatorio_atual[ 0 ] = numero_aleatorio(
                        MIN_VALOR_A_SER_SORTEADO,
                        MAX_VALOR_A_SER_SORTEADO
                    );
                    
                    if (!(
                        se_esta_presente(
                            lista_de_numeros_no_cartao,
                            indice_do_numero[ 0 ],
                            aleatorio_atual[ 0 ]
                        )
                    )){
                        // Caso esteja presente, devemos pular este número e 
                        // ir para outro que não esteja.
                        
                        lista_de_numeros_no_cartao[
                            indice_do_numero[ 0 ]    
                        ] = numero_aleatorio(
                            MIN_VALOR_A_SER_SORTEADO,
                            MAX_VALOR_A_SER_SORTEADO
                        );
                        
                        // Alocando
                        lista_de_numeros_no_cartao = (int*) realloc(
                            lista_de_numeros_no_cartao,
                            (
                                indice_do_numero[ 0 ] + 2   
                            ) * sizeof( int )
                        );
                        
                        indice_do_numero[ 0 ]++;   
                        
                    }
                    
                }
                
                free(aleatorio_atual);
                
            }else{*/
            
    }
    
    void configurando_cartoes_de_cada_jogador(
        Jogador* lista_de_jogadores,
        int indice_do_jogador
    ){
        /*
        Descrição:
            Função responsável por gerenciar os cartões de cada jogador.
            
            Conforme o loop se reinicia, vamos preencher um novo cartão.
            
        Parâmetros:
            atual_jogador -> jogador o qual estamos configurando os cartões.
        
        Retorno:
            Nenhum.
        */
        
        int se_ainda_deseja_novo_cartao(){
            /*
            Descrição:
                Função responsável por descobrir se o jogador ainda deseja novos cartões.
            
            Parâmetros:
                Nenhum.
            
            Retorno:
                Booleano representando se deseja novos cartões.
            */
            
            int* deseja_novo_cartao = (int*) calloc(
                1,
                sizeof( int )
            );
            
            printf(
                "\n\nDeseja Novo Cartão? (0 - Não)(Qualquer - Sim)"
            );
            scanf(
                "%d",
                deseja_novo_cartao
            );
            getchar();
            
            if(
                deseja_novo_cartao[ 0 ] == 0    
            ){
                // Então não se deseja novos cartões
                
                free(deseja_novo_cartao);
                
                return 0;
                
            }else{
                
                // Deseja-se novo cartão.
                
                free(deseja_novo_cartao);
                
                return 1;
                
            }
            
        }
        
        void realizando_todas_as_inicializacoes_necessarias(){
            /*
            Descrição:
                Função responsável por fazer as devidas inicializações de maneira
                a não poluir o escopo geral.
                
            Parâmetros:
                Nenhum.
                
            Retorno:
                Nenhum.
            */
            
            // Inicializamos array de quantidades para evitar confusão de anulação.
            lista_de_jogadores[
              indice_do_jogador 
            ].array_de_quantidade_de_numeros_em_cada_cartao = inicializando_array_de_inteiros(
                1
            );
            // Neste momento, o array de quantidade é [0]
            
            
            // E também a matriz de números em cada cartão.
            lista_de_jogadores[
              indice_do_jogador 
            ].matriz_de_numeros_em_cada_cartao = (int**) calloc(
                1,
                sizeof( int* )
            );
            lista_de_jogadores[
              indice_do_jogador 
            ].matriz_de_numeros_em_cada_cartao[
                0
            ] = (int*) calloc(
                1,
                sizeof( int )
            );
            // Neste momento, a matriz está como [ [0] ]
        }
        
        void realizando_realocacao_de_memoria(
            int numero_do_cartao_atual    
        ){
            /*
            Descrição:
                Função responsável por realocar a memória dos ponteiros sem poluir
                o escopo geral.
                
            Parâmetros:
                numero_do_cartao_atual -> representa em qual cartão estamos.
                
            Retorno:
                Nenhum.
            */
            
            // Realocando o array de quantidades
            lista_de_jogadores[
              indice_do_jogador 
            ].array_de_quantidade_de_numeros_em_cada_cartao = (int*) realloc(
                lista_de_jogadores[
                  indice_do_jogador 
                ].array_de_quantidade_de_numeros_em_cada_cartao,
                (
                    numero_do_cartao_atual + 2
                ) * sizeof( int )
            );
            
            // Realocando matriz 
            lista_de_jogadores[
              indice_do_jogador 
            ].matriz_de_numeros_em_cada_cartao = (int**) realloc(
                lista_de_jogadores[
                  indice_do_jogador 
                ].matriz_de_numeros_em_cada_cartao,
                (
                    numero_do_cartao_atual + 2
                ) * sizeof( int* )
            );
            
            // TEMOS QUE PARAR DE DEIXAR A ABA ABERTA
            // PQ AI O CÓDIGO QUE ABRIMOS NÃO É O DO SERVIDOR E SIM O DA MÁQUINA
            // E QUANDO SALVAMOS ENVIAMOS UM NOVO CÓDIGO AO SERVIDOR.
            
            // Temos que alocar as linhas tbm
            lista_de_jogadores[
              indice_do_jogador 
            ].matriz_de_numeros_em_cada_cartao[
                numero_do_cartao_atual
            ] = (int*) realloc(
                lista_de_jogadores[
                  indice_do_jogador 
                ].matriz_de_numeros_em_cada_cartao[
                    numero_do_cartao_atual    
                ],
                (
                    numero_do_cartao_atual + 2
                ) * sizeof( int )
            );
            
        }
        
        realizando_todas_as_inicializacoes_necessarias();
        
        int* indice_do_cartao = (int*) calloc(
            1,
            sizeof( int )
        );
        while(1){
            
            // Vamos preencher informações de cada cartão do jogador.
            
            printf(
                "\nPreenchendo Cartão Número %d\n",
                indice_do_cartao[ 0 ] + 1
            );
            
            configurando_numeros_no_cartao(
                lista_de_jogadores,
                indice_do_jogador,
                indice_do_cartao[ 0 ]
            );
            
            printf(
                "\n"    
            );
            
            indice_do_cartao[ 0 ]++;
            
            // Vamos verificar se o jogador ainda deseja que novos cartões sejam 
            // preenchidos.
            if(
                (
                    !se_ainda_deseja_novo_cartao()    
                ) || (
                    indice_do_cartao[ 0 ] == MAX_DE_CARTOES    
                )
            ){
                
                // Não se deseja novo cartão, devemos encerrar o loop.
                
                break;
                
            }
            
            // Como deseja-se novo cartão, devemos realocar memória e reiniciar loop
            
            // Realocando para o array de quantidades
            realizando_realocacao_de_memoria(
                indice_do_cartao[ 0 ]    
            );
        }
        
        // Vamos setar a quantidade de cartões
        lista_de_jogadores[
          indice_do_jogador 
        ].quantidade_de_cartoes = indice_do_cartao[ 0 ];
        
        printf(
            "Confirmando quantidades"    
        );
        apresentando_array(
            lista_de_jogadores[
              indice_do_jogador 
            ].array_de_quantidade_de_numeros_em_cada_cartao,
            indice_do_cartao[ 0 ]
        );
        
        free(indice_do_cartao);
        
    }
    
    void configurando_jogadores(
        Jogador lista_de_jogadores[]
    ){
        /*
        Descrição:
            Função responsável por fazer a alocação e o gerenciamento de cada jogador.
            Essa função será executada apenas uma vez.
            
            Conforme o loop se reinicia, novos jogadores são implementados.
            Note que setamos o tamanho total do array de jogadores como sendo o MÁX.
            Fizemos isso para que evitemos gasto de memória, tempo e processamento em
            processos de eliminação e de preenchimento de desinsteressados.
            
            Ao sair do loop, não há mais jogadores interessados. O sistema vai verificar
            se a quantidade de jogadores é menor que a máxima e, caso seja, setará o 
            interesse como -1 para os jogadores inexistentes.
        
        Parâmetros:
            Autoexplicativo.
            
        Retorno:
            Nenhum.
        */
        
        int verificando_se_ainda_ha_jogadores_interessados(){
            /*
            Descrição:
                Função responsável por descobrir se ainda há jogadores interessados.
            
            Parâmetros:
                Nenhum.
            
            Retorno:
                Booleano representando se há interessados.
            */
            
            int* se_ainda_ha_interessados = (int*) calloc(
                1,
                sizeof( int )
            );
            
            printf(
                "\n\nAinda há interessados? (0 - Não)(Qualquer - Sim)"
            );
            scanf(
                "%d",
                se_ainda_ha_interessados
            );
            getchar();
            
            if(
                se_ainda_ha_interessados[ 0 ] == 0    
            ){
                // Então não há interessados.
                
                free(se_ainda_ha_interessados);
                
                return 0;
                
            }else{
                
                // Ainda há interessados.
                
                free(se_ainda_ha_interessados);
                
                return 1;
                
            }
            
        }
        
        int* indice_do_jogador = (int*) calloc(
            1,
            sizeof( int )
        );
        while(1){
            
            // Vamos preencher informações de cada jogador
            
            printf(
                "Apostas do Jogador Número %d\n",
                indice_do_jogador[ 0 ] + 1
            );
            
            lista_de_jogadores[
                indice_do_jogador[ 0 ]
            ].interessado = 1;
            
            configurando_cartoes_de_cada_jogador(
                lista_de_jogadores,
                indice_do_jogador[ 0 ]
            );
            
            printf("\n");
            
            indice_do_jogador[ 0 ]++;
            
            // Vamos verificar se ainda há jogadores interessados a entrar
            // Ou se chegamos no máximo.
            if(
                (
                    !verificando_se_ainda_ha_jogadores_interessados()
                ) || (
                    indice_do_jogador[ 0 ] == MAX_DE_JOGADORES
                )
            ){
                // Não há mais jogadores interessados. Saímos do loop.
                break;
            }
            
        }
        
        if(
            indice_do_jogador[ 0 ] < MAX_DE_JOGADORES    
        ){
            // Então vamos setar o interesse em -1.
            
            while(
                indice_do_jogador[ 0 ] != MAX_DE_JOGADORES
            ){
                
                lista_de_jogadores[
                    indice_do_jogador[ 0 ] 
                ].interessado = -1;
                
                indice_do_jogador[ 0 ]++;
                
            }
            
        }
        
        free(indice_do_jogador);
        
    }
    
    
    // Vamos tentar primeiro entrar com um arquivo de texto
    FILE *arquivo_de_entrada_de_apostas_em_texto = fopen(
        "entrada_de_apostas_de_jogadores.txt",
        "r"
    );
    
    if (
        arquivo_de_entrada_de_apostas_em_texto != NULL    
    ){
        
        // Vamos abrir o arquivo e fazer as análises
        
        
        
        fclose(
            arquivo_de_entrada_de_apostas_em_texto    
        );
    }
    
    // Caso a entrada por arquivo de texto não tenha funcionado
    // Devemos perguntar se o jogador deseja a surpresinha ou não.
    
    inserindo_cor(
        'v'    
    );
    
    Jogador* array_de_jogadores = (Jogador*) calloc(
        MAX_DE_JOGADORES, 
        sizeof(Jogador)
    );
    
    // Será feito dessa maneira pela facilidade de gestão durante a execução do sistema.
    configurando_jogadores(
        array_de_jogadores    
    );
    
    
    return array_de_jogadores;
}

void exibindo_apostas(
    Jogador* array_de_jogadores
){
    /*
    Descrição:
        Função responsável por apresentar as informações de cada jogador interessado.
    
    Parâmetros:
        Autoexplicativo.
        
    Retorno:
        Nenhum.
    */
    
    
    avisando(
        'c',
        "Jogadores\tCartões Apostados"
    );
    
    int* index = (int*) calloc(
        1,
        sizeof( int )
    );
    
    for(
        index[ 0 ] = 0;
        index[ 0 ] < MAX_DE_JOGADORES;
        index[ 0 ]++
    ){
        
        if(
            // Se for exatamente 1, significa que há interesse.
            array_de_jogadores[
                index[ 0 ]    
            ].interessado == 1
        ){
            
            inserindo_cor(
                'c'    
            );
            
            // Vamos apresentar as informações.
            printf(
                "Jogador Número: %d\t",
                index[ 0 ] + 1
            );
            
            int* indice_do_cartao = (int*) calloc(
                1,
                sizeof( int )
            );
            
            for(
                indice_do_cartao[ 0 ] = 0;
                indice_do_cartao[ 0 ] < array_de_jogadores[
                    index[0]
                ].quantidade_de_cartoes;
                indice_do_cartao[ 0 ]++
            ){
                apresentando_array(
                    array_de_jogadores[
                        index[ 0 ]    
                    ].matriz_de_numeros_em_cada_cartao[
                        indice_do_cartao[ 0 ]    
                    ],
                    array_de_jogadores[
                        index[ 0 ]    
                    ].array_de_quantidade_de_numeros_em_cada_cartao[
                        indice_do_cartao[ 0 ]   
                    ]
                );
                
                printf("\t");
            }
            
            free(indice_do_cartao);
            
            inserindo_cor(
                'n'    
            );
            
            printf("\n");
            
        }
        
    }

    free(index);
    
}

int main()
{
    // Para nossas ações randômicas.
    srand(time(NULL));
    
    Jogador* conjunto_de_jogadores = recebendo_apostas();
    
    exibindo_apostas(
        conjunto_de_jogadores    
    );
    
    printf("Encerramento OK");
    
    return 0;
}















