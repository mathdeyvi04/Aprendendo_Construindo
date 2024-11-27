#include <stdio.h>
#include <stdlib.h>

// Devemos criar nossa classe de Nó, impressionantemente.
typedef struct Node{
    int valor;
    struct Node *esquerda;
    struct Node *direita;
}Node;
// Note que há os valores de struct justamente para esquerda ou direita, porque 
// não é possível definirmos como um Node, afinal estamos definindo no momento ainda.
// Muito louco irmão.


// As coisas não são tão simples como em python.
Node* CriandoNode(int value){
    
    /*
    Devemos alocar para retornar um Nó.
    Em python faríamos node1.left = node2
    Só em C pai, o sanha é outro.
    
    */
    Node* novo_sanha = (Node*) malloc( 1 * sizeof(Node) );
    
    // Definimos as variáveis para os atributos de um nó.
    (*novo_sanha).valor = value;
    (*novo_sanha).esquerda = NULL;
    (*novo_sanha).direita = NULL;
    
    return novo_sanha;
}

// Nem a limpeza dessa porra é simples, é sanha
void limpando_tudo(Node *no){
    
    if (no != NULL){
        // Se ele existir mesmo, devemos apagar as suas raizes primeiro
        
        limpando_tudo((*no).esquerda);
        
        limpando_tudo((*no).direita);
        
        free(no);
        
        // Note a recursividade
    }
}


void Visualizando_Recursivamente(Node *no){
    
    if (no != NULL){
        
        // A função vai buscar o último valor a direita e depois vai voltando
        // e verificando os valores da esquerda de cada ponto, compreende?
        
        Visualizando_Recursivamente((*no).direita);
        
        // logo depois de verificar o lado direito, ele printa o valor do seu próprio nó.
        printf("%d,", (*no).valor);
        
        // E então faz uma nova busca por outro ramo
        Visualizando_Recursivamente((*no).esquerda);
        
    }
    
}


int main(){
    
    /*
    Resolvi fazer em C porque o BAGULHO É MUITO LOUCO.
    
    Devemos obter uma forma recursiva e outra iterativa para visualizar os elementos
    da binary tree.
    
    */
    
    Node *raiz = CriandoNode(5);
    // Preenchendo
    {
        (*raiz).esquerda = CriandoNode(10);
        
        (*raiz).direita = CriandoNode(9);
        
        (*(*raiz).direita).esquerda = CriandoNode(8);
        
        (*(*raiz).direita).direita = CriandoNode(12);
        
        // Criamos a árvore de forma manual mesmo
        /*
        
                    5
                10          9
                        8       12
        */
    }
    
    // Vamos criar uma forma de visualizar cada um dos nós de forma recursiva, usando
    // backtracking papai.
    Visualizando_Recursivamente(raiz);
    
    
    // Agora seu monstro, vamos verificar a mesma coisa com iteratividade
    
    // Não tankei fazer iterativamente
    
    
    
    
    
    
    
    
    limpando_tudo(raiz);
    
    return 0;
}








