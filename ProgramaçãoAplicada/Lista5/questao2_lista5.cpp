#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>

int
gerar_int_random(
	int min,
	int max
){

	return min + rand() % (max - min - 1);
}

int 
main(){

	std::queue<std::string> queue_names;
	queue_names.push("Segfem1");
	queue_names.push("Segfem2");
	queue_names.push("Segfem3");

	// ------------------ Verificando primeiro, depois remover e exibir continuamente

	std::cout << "Frente da Fila: " 
			  << queue_names.front() 
			  << std::endl;
	while(
		!queue_names.empty()
	){

		std::cout << "Removendo: " 
				  << queue_names.front() 
				  << std::endl;
		queue_names.pop();
	}	

	// ------------------ Buffer de Medições

	std::queue<int> sensor_sample;
	for(
		int i = 0;
			i < 10; // -> faremos 10 iterações
			i++
	){

		int novo = gerar_int_random(0, 100);
		std::cout << i << "° iteração" << std::endl;
		std::cout << "Valor Adicionado: " << novo << std::endl;
		std::cout << "Valor Mais Antigo: " << sensor_sample.front() << std::endl;

		if(
			sensor_sample.size() > 5
		){

			sensor_sample.pop();
		}

		sensor_sample.push(novo);

		std::cout << std::endl;
	}

	return 0;
}
