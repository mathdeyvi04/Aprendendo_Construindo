#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

int
gerar_int_random(
	int min,
	int max
){

	return min + rand() % (max - min - 1);
}

float
gerar_float_random(
	int min,
	int max
){

	return min + (static_cast<float>(rand()) / RAND_MAX) * (max - min);
}

int
main(){

	srand(time(NULL));

	std::vector<int> vector_example(10);

	// ------------------- Preenche, exibe e ordena, exibindo ao final novamente

	std::cout << "original = [";
	for(
		int i = 0;
			i < 10;
			i++
	){

		vector_example[i] = gerar_int_random(0, 100);
		std::cout << vector_example[i] << ",";
	}
	std::cout << "\b]" << std::endl;

	std::sort(vector_example.begin(), vector_example.end());

	std::cout << "ordenado = [";
	for(
		int i = 0;
			i < 10;
			i++
	){

		std::cout << vector_example[i] << ",";
	}
	std::cout << "\b]" << std::endl;

	// ------------------- Calcula e exibe a média

	int sum = 0;
	for(
		int i = 0;
			i < 10;
			i++
	){

		sum += vector_example[i];
	}
	std::cout << "Média: " 
			  << sum / 10 
			  << std::endl;

	// ------------------ Obtém o valor máximo e mínimo da sequência

	std::cout << "Máx: " 
			  << *std::max_element(
			  					  vector_example.begin(),
			  					  vector_example.end()
			  					  ) 
			  << std::endl;

	std::cout << "Mín: " 
			  << *std::min_element(
			  					  vector_example.begin(),
			  					  vector_example.end()
			  					  ) 
			  << std::endl;

	// ------------------ Filtro de Ruído Simples

	std::vector<float> seno_com_ruido(20);
	std::cout << "A ser filtrado = [";
	for(
		int i = 0;
			i < 20;
			i++
	){

		seno_com_ruido[i] = gerar_float_random(-2, 2);
		std::cout << seno_com_ruido[i] << ",";
	}
	std::cout << "\b]" << std::endl;

	seno_com_ruido.erase(
						std::remove_if(
									  seno_com_ruido.begin(),
									  seno_com_ruido.end(),
									  [](int x) { return x > 1.5; }
									  ),
						seno_com_ruido.end()
						);

	std::cout << "Filtrado = [";
	for(
		int i = 0;
			i < 10;
			i++
	){

		std::cout << seno_com_ruido[i] << ",";
	}
	std::cout << "\b]" << std::endl;

	return 0;
}
