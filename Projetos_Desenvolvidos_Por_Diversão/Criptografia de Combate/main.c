#include "Front.h"
#include "Back.h"

/*
Descrição:
    A partir da excelentíssima aula de instrução do então TEN Lemes, nasceu no 
    mesmo que vos escreve a necessidade da criação deste código.
    
    Início: 202131PAGO24
    By: AL DEYVISSON 23054
    
Objetivos:
    -> Desenvolver meios de cripto e decriptografar mensagens.
    -> Aprender com diversão.
    -> Tentar entender como aplicar isso em tecnologia de combate.
    
Comentários e Padronizações:
    Sobre alocação:
        Variáveis inúteis e temporárias serão alocadas sempre que possível.
        Salvo quando totalmente necessário, evitaremos.
*/


int main()
{
    
    // Apresentando Menu
    while(1){
        
        cabecalho(
            "I E COM ELT",
            '=' // Caractere a ser disposto
        );
        
        int opc = apresentando_menu_principal();
        
        switch(opc){
            
            case 1:
                // Opção de Saída.
                
                avisando_erro(
                    "\n\nVolte logo...\n\n"    
                );
                
                return 0;
                
            case 2:
                // Método por Inversão
                
                menu_de_inversao();
                
                break;
                
            case 3: 
                // Método por Grade
                
                break;
                
            case 4:
                // Método por Chave Simples
                break;
                
            case 5:
                // Método por Chave Dupla
                break;
                
            case 6:
                // Vendo Registro.
                break;
                
            default:
                
                break;
            
            
        }
        
        apagando_tela();
        
    }
    
    
    
    
    
    

    return 0;
}