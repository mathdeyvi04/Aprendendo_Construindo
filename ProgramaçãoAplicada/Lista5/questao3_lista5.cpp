#include <iostream>
#include <map>

int main(){


	// ------------- Criação e exibição
	std::map<std::string, int> names_to_age;

	names_to_age["Segfem1"] = 18;
	names_to_age["Segfem2"] = 19;
	names_to_age["Segfem3"] = 20;

	std::cout << "Map Completo: " << std::endl;
	for(
		const auto& [chave, valor] : names_to_age
	){

		std::cout << "["
				  << chave 
				  << "] = "
				  << valor
				  << std::endl;
	}
	std::cout << std::endl;


	// ------------ Entrada de Usuário

	std::cout << "Insira um novo nome ou um nome a ser buscado: ";
	std::string name_from_user;
	std::getline(std::cin, name_from_user);

	if(
		names_to_age.find(name_from_user) != names_to_age.end()
	){

		std::cout << name_from_user 
				  << " existe e tem idade: "
				  << names_to_age[name_from_user]
				  << std::endl;
	}
	else{

		std::cout << "Este nome não está registrado. Porém, será adicionado com idade 0." << std::endl;
		names_to_age[name_from_user] = 0;
	}

	// ------------- Tabela de Calibração de Sensor

	std::map<int, double> sensores = {
        {101, 1.25},
        {102, 0.98},
        {103, 1.10}
    };

    std::cout << "Apresentando tabela de calibração de sensor: " << std::endl;
	for(
		const auto& [id, gain] : sensores
	){

		std::cout << "[" 
    			  << id
    			  << "] = "
    			  << gain 
    			  << std::endl;		
	}

    std::cout << "Insira o ID do sensor desejado:";
    std::string sensor_from_user;
    std::getline(std::cin, sensor_from_user);

    if(
    	sensores.find(std::stoi(sensor_from_user)) != sensores.end()
    ){
        std::cout << "Sensor dado encontrado. Ganho atual: " << sensores[std::stoi(sensor_from_user)] << '\n';

        double new_gain;
        std::cout << "Novo ganho: ";
        std::cin >> new_gain;

        // Alteração
        sensores[std::stoi(sensor_from_user)] = new_gain;
    }
    else{

        std::cout << "Sensor não encontrado.\n";
    }
    std::cout << std::endl;

    for(
    	const auto& [id, gain] : sensores
    ){

    	std::cout << "[" 
    			  << id
    			  << "] = "
    			  << gain 
    			  << std::endl;
    }
    std::cout << std::endl;

    // ---------------- Contador de Pacotes por Nó

    std::map<std::string, int> counter_node;
    std::string node;

    std::cout << "Insira o número do nó que recebeu o pacote, digite 0 para sair:\n\n" << std::endl;
    while (true) {
        std::cout << "ID Node: ";
        std::getline(std::cin, node);

        if(
        	node == "0"
        ){

        	break;
        }

        // Incrementa o contador de pacotes do nó
        counter_node[node]++;
    }

    std::cout << "\nTotal de pacotes recebidos por nó:\n";
    for(
    	const auto& [nome, total] : counter_node
    ){

        std::cout << "NODE" << nome << " -> " << total << " pacotes\n";
    }

	return 0;
}