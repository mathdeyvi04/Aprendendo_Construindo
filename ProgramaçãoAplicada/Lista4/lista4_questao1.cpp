#include <iostream>

class Veiculo {
public: 

	std::string placa, cor;

	Veiculo(
		const std::string& placa_ = "",
		const std::string& cor_ = ""
	) : placa(placa_),
		cor(cor_)
	{}

	virtual double 
	vagasOcupadas() = 0;

	virtual 
	~Veiculo() = default;
};

class Carro : public Veiculo {
public:

	using Veiculo::Veiculo;

	double 
	vagasOcupadas(){

		return 1.0;
	}
};

class Moto : public Veiculo {
public:

	using Veiculo::Veiculo;

	double 
	vagasOcupadas(){

		return 0.5;
	}
};

class Caminhao : public Veiculo { 
public:

	using Veiculo::Veiculo;

	double
	vagasOcupadas(){

		return 2.0;
	}
};

class Estacionamento {
private:

	int idx_veiculo = 0; // Sempre iniciamos com estacionamento vazio.
	int quantidade_total_de_vagas;
	double quantidade_de_vagas_livres; 
	Veiculo** array_de_veiculos;

public:

	Estacionamento(
		int numero_de_vagas_do_estacionamento
	) : quantidade_de_vagas_livres(numero_de_vagas_do_estacionamento),
		quantidade_total_de_vagas(numero_de_vagas_do_estacionamento)
	{

		// "Tamanho suficiente para acomodar todos os veículos possíveis"
		// Devemos considerar o pior caso, em que há todo o estacionamento
		// está preenchido com motos.

		array_de_veiculos = new Veiculo*[
											      // É sabido que as motos ocupam metade do espaço
												  // Logo, haverá o dobro de motos no estacionamento no pior caso
												  numero_de_vagas_do_estacionamento * 2
												  ];
	}

	/**
	 * @brief Destrutor da classe estacionamento.
	 * @details
	 * 
	 * Completamente responsável pelas desalocações dos veículos e de si.	
	 */
	~Estacionamento(){
		for(
			int i = 0;
				i < idx_veiculo;
				i++
		){

			delete array_de_veiculos[i];
			array_de_veiculos[i] = nullptr;
		}
		delete[] array_de_veiculos;
	} // Devemos verificar isso corretamente.

	bool
	entrar(
		Veiculo* veiculo_tentando_entrar
	){

		if(
			// Caso a quantidade de vagas livres seja menor que a quantidade
			// de vagas que o veiculo ocupa, devemos impedir
			(quantidade_de_vagas_livres - veiculo_tentando_entrar->vagasOcupadas()) < 0
		){

			return false;
		}

		// Considerando que há espaço livre
		array_de_veiculos[
			idx_veiculo++
		] = veiculo_tentando_entrar;

		// Implementamos a chamada polimórfica
		quantidade_de_vagas_livres -= veiculo_tentando_entrar->vagasOcupadas();

		return true;
	}

	void 
	listar(){

		printf("----------------------------------");
		printf("\nVeículos Estacionados: ");

		if(idx_veiculo == 0){ printf("Não há veículos estacionados."); }

		printf("\n----------------------------------");
		for(
			int i = 0;
				i < idx_veiculo;
				i++
		){

			double ocup = array_de_veiculos[i]->vagasOcupadas();
			printf("\nVeiculo[%d]: %s\t-> %.1lf",
				                                i,
				                                (ocup == 1) ? "Carro" : ((ocup == 2) ? "Caminhão" : "Moto"),
				                                array_de_veiculos[i]->vagasOcupadas()
				                                );
		}

		printf("\n\nVagas Totais: %d | Vagas Livres: %.1lf\n", quantidade_total_de_vagas, quantidade_de_vagas_livres);
		printf("----------------------------------\n\n\n");
	}
};


int main() {

    int N;
    std::cout << "Informe o numero de vagas do estacionamento: ";
    if (!(std::cin >> N) || N <= 0) {
        std::cout << "Entrada invalida.\n";
        return 1;
    }

    Estacionamento est(N);

    // Estado inicial
    est.listar();

    // Entradas 
    Veiculo* v1 = new Carro("ABC-1234", "Prata");
    if (!est.entrar(v1)) { std::cout << "Sem espaco para " << v1->placa << "\n";}

    Veiculo* v2 = new Moto("MOT-0001", "Vermelha");
    if (!est.entrar(v2)) { std::cout << "Sem espaco para " << v2->placa << "\n";}

    Veiculo* v3 = new Caminhao("TRK-9A77", "Branco");
    if (!est.entrar(v3)) { std::cout << "Sem espaco para " << v3->placa << "\n";}

    est.listar();

    // Saídas
    //std::cout << (est.sair("ABC-1234") ? "Saiu ABC-1234\n" : "Nao achou ABC-1234\n");
    //std::cout << (est.sair("ZZZ-9999") ? "Saiu ZZZ-9999\n" : "Nao achou ZZZ-9999\n");

    //est.listar();


    return 0;
}




