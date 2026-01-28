#include <iostream>
#include <string>
#include <algorithm>


int
main(){

	// ---- Receber, contar, substituir e inverter
	std::string frase;
    std::cout << "Digite uma frase: ";
    std::getline(std::cin, frase);

    std::cout << "A letra 'a' aparece " 
              << std::count(frase.begin(), frase.end(), 'a') 
              << " vezes.\n";

    std::replace(frase.begin(), frase.end(), ' ', '_');
    std::cout << "Espacos substituidos: " << frase << "\n";

    std::reverse(frase.begin(), frase.end());
    std::cout << "String invertida: " << frase << "\n\n";

    // ------------ Análise de mensagem 
    std::string msg;
    std::cout << "Digite uma mensagem (ex: SRC=NODE1;DST=NODE3;DATA=HELLO): ";
    std::getline(std::cin, msg);

    size_t srcPos = msg.find("SRC=") + 4;
    size_t dstPos = msg.find("DST=");
    size_t dataPos = msg.find("DATA=");

    std::string origem = msg.substr(srcPos, dstPos - srcPos - 1);
    std::string destino = msg.substr(dstPos + 4, dataPos - dstPos - 5);
    std::string dados = msg.substr(dataPos + 5);

    std::cout << "Origem: " << origem << "\n";
    std::cout << "Destino: " << destino << "\n";
    std::cout << "Dados: " << dados << "\n\n";

    // ---------- Relatório
    std::string operador;
    double V, A;
    std::cout << "Nome do operador: ";
    std::getline(std::cin, operador);
    std::cout << "Tensao (V): ";
    std::cin >> V;
    std::cout << "Corrente (A): ";
    std::cin >> A;

    double P = V * A;
    std::cout << "\nMedição de " << operador << ": "
              << V << " V, " << A << " A -> Potência = "
              << P << " W\n";



	return 0;
}
