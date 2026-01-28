#include <iostream>
#include <map>

class Medidor {
private:
	float current, voltage, consumption;

public:

	Medidor(
		float current,
		float voltage,
		float consumption
	): current(current), voltage(voltage), consumption(consumption) {}

	float
	get_current() const { return current; }

	float
	get_voltage() const { return voltage; }

	/**
	 * @brief Não precisamos calcular o consumo, podemos apenas retorná-lo.	
	 */
	float
	get_consumption() const { return consumption; }
};

/**
 * @brief Gerenciará uma lista de medidores
 */
class Sistema {
private:
	std::map<int, Medidor*> map_of_medidores;

public:

	/**
	 * @brief Soma dos consumos acumulados de cada medidor	
	 */
	float
	get_total_consumption(){

		float sum = 0;
		for(
			const auto& [chave, valor] : map_of_medidores
		){

			sum += valor->get_consumption();
		}

		return sum;
	}

	/**
	 * @brief Calcular valor monetário do consumo seguindo a métrica dada.
	 */
	float
	get_total_consumption_value(){

		float sum = get_total_consumption();
		return 10 + (sum > 50) * (0.2 * std::min(50.0, sum - 50.0)) + (sum > 100) * (0.25 * std::min(100.0, sum - 100.0)) + (sum > 200) * (0.35 * (sum - 200));
	}

	/**
	 * @brief Inclusão de um novo medidor	
	 */
	bool
	add_medidor(
		Medidor* new_medidor
	){

		map_of_medidores[map_of_medidores.size()] = new_medidor;
		
		return true;
	}

	/**
	 * @brief Printar informações do medidor	
	 */
	void
	print_medidor(
		int id
	){

		if(
			map_of_medidores.count(id)
		){

			// Então existe
			printf(
				"Medidor %d \t corrent=%f \t tensão=%f \t consumo=%f\n",
				id,
				map_of_medidores[id]->get_current(),
				map_of_medidores[id]->get_voltage(),
				map_of_medidores[id]->get_consumption()
			);
		}
	}


};

int
main(){

	Sistema sys;
	Medidor m1(10, 10, 50);
	Medidor m2(10, 10, 50);
	Medidor m3(10, 10, 30);

	sys.add_medidor(&m1);
	sys.add_medidor(&m2);
	sys.add_medidor(&m3);

	printf("\nValor total de Consumo = %f\n", sys.get_total_consumption_value());
	return 0;
}