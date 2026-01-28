#include <iostream>
#include "SecureFileProcessor.hpp"

int main() {
	SecureFileProcessor sfp;
    while(true){
        std::cout << "\n1 - Criptografar arquivo\n2 - Descriptografar arquivo\n0 - Sair\n> ";
        int opcao; 
        std::cin >> opcao;

        if(opcao == 0){ break; } 

        std::string input("exemplo.txt");
        std::string output("teste.txt");
        int key = 10;
        // std::cout << "Arquivo de entrada: "; std::cin >> input;
        // std::cout << "Arquivo de saída: "; 	 std::cin >> output;
        // std::cout << "Chave da cifra: ";     std::cin >> key;

       	if (opcao == 1){
            sfp.encryptFile(input, output, key);
       	}
        else if (opcao == 2){
            sfp.decryptFile(input, output, key);
        }
        else{
            std::cout << "Opção inválida.\n";
        }

        break; 
    }

    return 0;
}