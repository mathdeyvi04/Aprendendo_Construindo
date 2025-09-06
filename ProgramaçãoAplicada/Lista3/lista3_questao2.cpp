#include <iostream>
#include <chrono>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <locale>
#include <codecvt>
#include <cctype> 
#include <cstdio>

/**
 * @brief Representará a entidade aluno.
 */
class Aluno {
private:

	int id;
	std::string nome, cpf;

public:

	/**
	 * @brief Construtor Default
	 * @param id_ ID do aluno
	 * @param nome_ NOME do aluno
	 * @param cpf_ CPF do aluno
	 */
	Aluno(
		int id_,
		std::string nome_,
		std::string cpf_
	) : id(id_),
		nome(nome_),
		cpf(cpf_)
	{}

	/**
	 * @brief Construtor para facilitar inserção no vetor.	
	 * @param param Vetor de parâmetros: ID, NOME, CPF
	 */
	Aluno(
		const std::vector<std::string>& param
	){

		id   = std::stoi(param[0]);
		nome = param[1];
		cpf  = param[2];
	}

	/**
	 * @brief Retornará uma informação do aluno baseado em um índice.	
	 */
	std::string
	get_info(
		int idx
	) const {

		if     (idx == 0){

			return std::to_string(id);
		}
		else if(idx == 1){

			return nome;
		}
		else if(idx == 2){

			return cpf;
		}
		else{

			throw std::invalid_argument("Não é possível aceitar este índice.");
		}
	}
};

/**
 * @brief Representará a entidade disciplina. 
 */
class Disciplina {
private:

	int credit, id;
	std::string nome, professor;

public:

	/**
	 * @brief Construtor Default 
	 * @param id_ ID da disciplina
	 * @param nome_ NOME da disciplina
	 * @param professor_ PROFESSOR da disciplina
	 * @param credit_ CREDITO quantidade de créditos da disciplina (?)
	 */
	Disciplina(
		int id_,
		std::string nome_,
		std::string professor_,
		int credit_
	) : id(id_),
		nome(nome_),
		professor(professor_),
		credit(credit_)
	{}

	/**
	 * @brief Construtor para facilitar inserção dentro do vetor.	
	 * @param param Vetor de parâmetros, ID, NOME, PROFESSOR, CREDITO.
	 */
	Disciplina(
		std::vector<std::string> param
	){

		id        = std::stoi(param[0]);
		nome      = param[1];
		professor = param[2];
		credit    = std::stoi(param[3]);
	}

	/**
	 * @brief Retornará uma informação do aluno baseado em um índice.	
	 */
	std::string
	get_info(
		int idx
	) const {

		if     (idx == 0){

			return std::to_string(id);
		}
		else if(idx == 1){

			return nome;
		}
		else if(idx == 2){

			return professor;
		}
		else if(idx == 3){

			return std::to_string(credit);
		}
		else{

			throw std::invalid_argument("Não é possível aceitar este índice.");
		}
	}
};

/**
 * @brief Respresentará o sistema educacional.
 * @details
 * 
 * Amazenará e manipulará listas de alunos matriculados e disciplinas ofertadas por período.
 * Fornecerá um menu capaz de:
 * - Inserção e remoção em todas as listas, de alunos, disciplinas e matrículas.
 * - Consultas:
 *     - A partir de informações de aluno e de período, listar as displinas que está matriculado.
 *     - A partir de informações de uma disciplina e um período, listar os alunos matriculados na mesma.
 * - Atualização de Banco de Dados
 * 
 * ###############################################################
 * Mais explicações:
 * 
 * Em cada período, há uma quantidade de alunos e de disciplinas. 
 * Além disso, para cada disciplina, dependendo do período, há uma determinada quantidade de alunos
 * matriculados na mesma.
 * 
 * Sendo assim, como a ideia é simularmos um sistema educacional, construiremos de forma análoga
 * ao sistema do IME.
 * 
 * O sistema deve focar no período atual, sendo capaz de obter essa informação automaticamente, ou
 * focar em um período específico forçado pelo usuário.
 * 
 * ##############################################################
 * Limitações:
 * 
 * - Não há um conjunto de verificações eficiente para as entradas do usuário, apenas verificamos 
 * o clássico de 'se é inteiro', 'se é digito', etc. Apesar disso, acredito que verificações de existência e de dualidade
 * são essenciais em um sistema como este.
 * 
 * - Estrutura de dados escolhida para este problema é horrível, seria extremamente mais eficiente escolhermos
 * algo como o dicionário do python, um map ou unorderned_map.
 * 
 */
class Sistema {
private:

	int ano, periodo = 0;

	std::string database_name = "";

	bool houve_altera = false; // Flag para Salvarmos banco de dados
	std::vector<Aluno> list_alunos;
	std::vector<Disciplina> list_disciplinas;
	// Organizará a relação entre os alunos e disciplinas.
	// Para cada vetor presente, ele estará organizado da seguinte forma:
	// [0] - ÍD da disciplina
	// [1, ...] - ID dos alunos matriculados
	std::vector<std::vector<int>> list_relations;

public:

	/**
	 * @brief Função auxiliadora para fatiar a string.	
	 */
	static std::vector<std::string>
	split(
		const std::string& str, 
		char delimitador=','
	){

		std::vector<std::string> list_string_splited;

		// A fim de manter a perfomance, vamos alocar inicialmente.
		list_string_splited.reserve(
									std::count(
												str.begin(),
												str.end(),
												','
										      ) + 1
			                       );

		std::stringstream ss(str);
		std::string fatia;

		while(
			std::getline(ss, fatia, delimitador)
		){

			list_string_splited.push_back(
										  fatia
									     );
		}

		return list_string_splited;
	}

	/**
	 * @brief Retornará uma referência para uso interno	
	 */


	/**
	 * @brief Construtor da classe
	 * @details 
	 * 
	 * - Inicializa o sistema;
	 * - Obtém valores de ano e de período;
	 */
	Sistema(){

		set_ano_periodo();

		ensure_database();

		get_data();
	}

	/**
	 * @brief Desconstrutor da classe
	 * @details
	 * 
	 * Se responsabilizará por atualizar o banco de dados, caso haja alguma mudança.	
	 */
	~Sistema(){

		if(!houve_altera){ return; }

		// Então houve mudança

		// Removemos o banco existente.
		::remove(database_name.c_str());

		// E o recriamos zerado.
		std::ofstream database(database_name);

		// Adicionamos as informações dos alunos
		database << list_alunos.size() << std::endl;
		for(
			const auto& aluno : list_alunos
		){

			for(
				int i = 0;
					i < 3;
					i++
			){

				if( i == 0 ){

					database << aluno.get_info(i);
					continue;
				}

				database << "," << aluno.get_info(i);
			}

			database << std::endl;
		}

		// Adicionamos informações de disciplinas
		database << list_disciplinas.size() << std::endl;
		for(
			const auto& disciplina : list_disciplinas
		){

			for(
				int i = 0;
					i < 4;
					i++
			){

				if(i == 0){

					database << disciplina.get_info(i);
					continue;
				}

				database << "," << disciplina.get_info(i);
			}

			database << std::endl;
		}

		// Adicionamos informações de relações
		database << list_disciplinas.size() << std::endl;
		for(
			const auto& relations : list_relations
		){

			bool is_first = true;
			for(
				const auto& numero : relations
			){
				if(
					is_first
				){

					database << numero;
					is_first = false;
					continue;
				}

				database << "," << numero; 
			}

			database << std::endl;
		}

		database.close();
	}

	/**
	 * @brief Seta os valores de ano e de período, seja automaticamente ou pelo usuário.
	 * @param automatico Flag para sabermos se o usuário deseja inserir manualmente.
	 * @details
	 * 
	 * Caso seja forçado pelo usuário, se responsabilizará pela obtenção dos novos valores.
	 */
	void
	set_ano_periodo(
		bool automatico = true
	){

		if(automatico){

			time_t agora = std::chrono::system_clock::to_time_t(
				                                               std::chrono::system_clock::now()
				                                               );

			struct tm *local_time = localtime(&agora);

			ano     = local_time->tm_year + 1900;
			periodo = (local_time->tm_mon + 1) / 6 + 1;
		}
		else{

		}
	}

	/**
	 * @brief Garantirá a existência do banco de dados.	
	 * @details
	 * 
	 * Retornará true caso exista um arquivo com o ano e período caracterizado.
	 * Retornará false caso não exista. Responsabilizará-se pela criação do arquivo.
	 */
	void
	ensure_database(){

		std::filesystem::path root(".");
		std::ostringstream oss;
		oss << ano
			<< "."
			<< periodo
			<< ".txt";

		database_name = oss.str();

		if(
			!std::filesystem::exists(database_name)
		){

			// Então não existe. Devemos criá-lo.
			std::ofstream db_criado;
			db_criado.open(database_name);
			db_criado.close();
		}

		std::cout << "Abrindo banco de dados: "
			      << database_name
			      << "...\n"
			      << std::endl;
	}

	/**
	 * @brief Obterá as informações do banco de dados.
	 * @details
	 * 
	 * Como essa função é executada apenas após `ensure_database`, garantimos
	 * que database_name é válido.
	 */
	void
	get_data(){
		
		std::ifstream database(database_name);
		std::string linha;

		int flag_container = 0;
		while(
			std::getline(database, linha)
		){
			// Devemos remover o pula linha para evitar problemas.
			if(linha.back() == 13){ linha.pop_back(); }

			int length_line = linha.size();

			if(
				length_line == 1
			){
				// Então estamos na linha para reservar.

				if     (flag_container == 0){

					list_alunos.reserve(std::stoi(linha));
				}
				else if(flag_container == 1){

					list_disciplinas.reserve(std::stoi(linha));
				}
				else if(flag_container == 2){

					list_relations.reserve(std::stoi(linha));
				}

				flag_container += 1; // Alteramos de lista assim.
			}
			else{

				// Então temos uma linha de dados.
				if     (flag_container == 1){


					list_alunos.emplace_back(
						split(linha)
					);
				}
				else if(flag_container == 2){

					list_disciplinas.emplace_back(
						split(linha)
					);
				}
				else if(flag_container == 3){

					auto line_splitted = split(linha);

					// Iniciamos um novo vetor zerado
					list_relations.emplace_back();

					// Reservamos o.
					list_relations.back().reserve(
												  line_splitted.size()
												 );

					for(
						const auto& string_in_line_splitted : line_splitted
					){

						list_relations.back().emplace_back( std::stoi(string_in_line_splitted) );
					}
				}
			}
		}

		database.close();
	}

	/**
	 * @brief Apresentador de Informações Cruas	
	 * @param flag_container Flag para identificarmos oq se deseja imprimir.
	 * @details
	 * 
	 * 0 - Alunos totais matriculados no período.
	 * 1 - Disciplinas registradas no período.
	 * 2 - Header de menu. 
	 */
	void
	print(
		int flag_container
	){

		if     (flag_container == 0){
			// Desejamos ver a lista de alunos completa.

			std::string list_titles[3] = {"ID", "Nome", "CPF"};
			int list_padding[3] = {8, 20, 15};


			for(
				int i = 0;
					i < 3;
					i++
			){

				std::cout << std::setfill('-')
						  << std::left
						  << std::setw(list_padding[i])
					  	  << list_titles[i];
			}
			std::cout << std::endl;

			for(
				const auto& aluno : list_alunos
			){

				for(
					int i = 0;
						i < 3;
						i++
				){

					std::cout << std::setfill(' ')
							  << std::left
							  << std::setw(list_padding[i])
						  	  << aluno.get_info(i);
				}

				std::cout << std::endl;
			}
		}
		else if(flag_container == 1){

			std::string list_titles[4] = {"ID", "Nome", "Professor", "Crédito"};
			int list_padding[4] = {8, 40, 20, 10};

			for(
				int i = 0;
					i < 4;
					i++
			){

				std::cout << std::setfill('-')
						  << std::left
						  << std::setw(list_padding[i])
					  	  << list_titles[i];
			}
			std::cout << std::endl;

			for(
				const auto& disciplina : list_disciplinas
			){

				for(
					int i = 0;
						i < 4;
						i++
				){

					std::cout << std::setfill(' ')
							  << std::left
							  << std::setw(list_padding[i])
						  	  << disciplina.get_info(i);
				}

				std::cout << std::endl;
			}
		}
		else if(flag_container == 2){

			printf("-----------------------------------------------\n");
			printf("Sistema Educacional IME\n");
			printf("-----------------------------------------------\n");

			// Vamos apresentar as funcionalidades de forma escalável:
			std::vector<std::string> list_funcionalities = {
				"0 - Encerrar",
				"1 - Menu de Alunos Matriculados",
				"2 - Menu de Disciplinas Registradas",
				"3 - Consultar"
			};

			for(
				size_t i = 0;
					   i < list_funcionalities.size();
					   i++
			){

				std::cout << list_funcionalities[i] << std::endl;
			}
		}	
		else if(flag_container == 3){

			printf("-----------------------------------------------\n");
			printf("Menu de Alunos Matriculados\n");
			printf("-----------------------------------------------\n");

			// Vamos apresentar as funcionalidades de forma escalável:
			std::vector<std::string> list_funcionalities = {
				"0 - Encerrar",
				"1 - Inserir novo Aluno",
				"2 - Remover Aluno",
				"3 - Consultar - Verifica disciplinas que aluno está matriculado"
			};

			for(
				size_t i = 0;
					   i < list_funcionalities.size();
					   i++
			){

				std::cout << list_funcionalities[i] << std::endl;
			}
		}
		else if(flag_container == 4){

			printf("-----------------------------------------------\n");
			printf("Menu de Disciplinas Registradas\n");
			printf("-----------------------------------------------\n");

			// Vamos apresentar as funcionalidades de forma escalável:
			std::vector<std::string> list_funcionalities = {
				"0 - Encerrar",
				"1 - Inserir nova disciplina",
				"2 - Remover Disciplina",
				"3 - Consultar - Verifica alunos matriculados na disciplina."
			};

			for(
				size_t i = 0;
					   i < list_funcionalities.size();
					   i++
			){

				std::cout << list_funcionalities[i] << std::endl;
			}
		}
		else{

			throw std::invalid_argument("Não há suporte para este índice.");
		}
	}

	/**
	 * @brief Fornecerá as ferramentas para inserção de um novo aluno ao sistema.
	 */
	void
	insert_aluno(){

		int id;
		// Vamos usar a string de cpf para receber as informações
		std::string nome, cpf, relation_str;

		// Obtendo informações necessárias.
		while(true){

			std::cout << "Informe o ID do aluno: ";
			std::getline(std::cin, cpf);

			try {

				if(cpf.size() != 5){
					throw std::invalid_argument("");
				}

				id = std::stoi(cpf);
				break;
			}
			catch(const std::invalid_argument&){

				std::cout << "Entrada inválida" << std::endl;
			}
		}

		// Para o nome, não há como colocarmos restrições.
		while(true){

			std::cout << "Informe o NOME do aluno: ";
			std::getline(std::cin, nome);

			break;
		}

		while(true){

			std::cout << "Informe o CPF do aluno: ";
			std::getline(std::cin, cpf);

			if(
				std::all_of(cpf.begin(), cpf.end(), ::isdigit)
			){

				break;
			}
			else{

				std::cout << "Entrada inválida" << std::endl;
			}
		}

		// Devemos obter informações de matrícula.
		while(true){

			print(1);
			std::cout << "Informe os ID's das disciplinas que este aluno está matriculado separado por vírgulas: \n";
			std::getline(std::cin, relation_str);

			if(
				relation_str.find(',')
			){

				break;
			}
			else{

				std::cout << "Deve existir pelo menos uma vírgula." << std::endl;
			}
		}

		// Devemos adicionar o novo aluno ao sistema.
		list_alunos.emplace_back(
								id,
								nome,
								cpf
			                    );

		// Adicionar relações do aluno
		for(
			const auto& id_de_disciplina : split(relation_str)
		){

			// Devemos buscar essa disciplina na lista de disciplinas
			for(
				int i = 0;
					i < (int)list_relations.size();
					i++
			){

				if(
					std::stoi(id_de_disciplina) == list_relations[i][0]
				){

					// Achamos a disciplina na lista de relações.
					// Nela devemos adicionar o novo aluno matriculado
					list_relations[i].emplace_back(id); // Adicionamos o id do aluno.

					// E saímos, já que já o adicionamos nesta disciplina.
					break;
				}
			}
		}

		// Modificar flag de alteração
		houve_altera = true;
	}

	/**
	 * @brief Fornecerá as ferramentas para remoção de um aluno a partir de seu ID.
	 */
	void
	remove_aluno(){

		int id = 0;
		while(true){

			std::string entrada;
			while(true){

				std::cout << "Informe o ID do aluno: ";
				std::getline(std::cin, entrada);

				try {
					if(entrada.size() != 5){
						throw std::invalid_argument("");
					}

					id = std::stoi(entrada);
					break;
				}
				catch(const std::invalid_argument&){

					std::cout << "Entrada inválida" << std::endl;
				}
			}

			// Precisamos verificar se o aluno existe
			bool aluno_existis = false;
			for(
				const auto& aluno : list_alunos
			){

				if(
					std::stoi(aluno.get_info(0)) == id
				){

					aluno_existis = true;
					break;
				}
			}
			if(!aluno_existis){

				std::cout << "Aluno não existe!" << std::endl;
				aluno_existis = false;
				continue;
			}
			else{

				break;
			}
		}


		// Supondo que conseguimos, devemos removê-lo da lista de alunos.
		list_alunos.erase(
						 std::remove_if(
						 			   list_alunos.begin(),
						 			   list_alunos.end(),
						 			   // Utilizamos função anônima
						 			   [id](const Aluno& aluno){ return std::stoi(aluno.get_info(0)) == id; }
						 			   ),
						 list_alunos.end()
						 );

		// Devemos eliminar o aluno das matrículas também
		for(
			auto& relations : list_relations
		){

			relations.erase(
 						   std::remove(
 						   			  relations.begin(),
 						   			  relations.end(),
 						   			  id
 									  ),
 						   relations.end()
						   );
		}

		houve_altera = true;
	}

	/**
	 * @brief Forncerá a lista de disciplinas que o aluno está matriculado	
	 */
	void
	consultar_aluno(){

		while(true){

			// Devemos obter o ID do aluno a ser consultado.
			std::string entrada;
			int id;
			while(true){

				std::cout << "Forneça o ID do aluno: ";
				std::getline(std::cin, entrada);

				try {

					if(entrada.size() != 5){
						throw std::invalid_argument("");
					}

					id = std::stoi(entrada);
					break;
				}
				catch(const std::invalid_argument&){

					std::cout << "Entrada inválida" << std::endl;
				}
			}

			// O ideal é ver se esse aluno existe.
			bool aluno_existis = false;
			for(
				const auto& aluno : list_alunos
			){

				if(
					std::stoi(aluno.get_info(0)) == id
				){

					aluno_existis = true;
					break;
				}
			}
			if(!aluno_existis){

				std::cout << "Aluno não existe!" << std::endl;
				aluno_existis = false;
				continue;
			}

			// De posse do id do aluno, podemos verificar em quais disciplinas ele está matriculado.
			std::cout << "Aluno " 
				      << entrada 
				      << " matriculado em: "
				      << std::endl;
			for(
				const auto& relations : list_relations
			){

				for(
					int i = 1;  // Afinal, apenas a partir do segundo há os id's de alunos.
						i < (int)relations.size();
						i++
				){

					if(
						// Assim que o encontrarmos
						id == relations[i]
					){

						std::cout << "- " 
								  << relations[0]
								  << std::endl;

						// Seria interessante informarmos mais dados sobre a disciplina, mas...

						break;
					}
				}
			}


			std::cout << "Mais uma consulta?(0 - Não): ";
			std::getline(std::cin, entrada);
			try {

				if(
					std::stoi(entrada) == 0
				){

					break;
				}
			}
			catch(const std::invalid_argument&){ /*Não faremos nada*/ }
			printf("\n");
		}

		// Não há alteração do banco de dados, logo não precisamos salvar algo
	}

	/**
	 * @brief Fornecerá as ferramentas necessárias para adição de uma nova disciplina.	
	 */
	void
	insert_disciplina(){

		// Primeiro, as informações da mesma.
		int id, credito;
		std::string nome, professor, entrada;
		while(true){
			std::cout << "Informe o ID da disciplina: ";
			std::getline(std::cin, entrada);
			
			try {

				if(entrada.size() != 4){
					throw std::invalid_argument("");
				}

				id = std::stoi(entrada);
				break;
			}
			catch(const std::invalid_argument&){

				std::cout << "Entrada inválida" << std::endl;
			}			
		}

		std::cout << "Informe o NOME da disciplina: ";
		std::getline(std::cin, nome);

		std::cout << "Informe o PROFESSOR da disciplina: ";
		std::getline(std::cin, professor);

		while(true){
			std::cout << "Informe o CRÉDITO da disciplina: ";
			std::getline(std::cin, entrada);
			
			try {

				credito = std::stoi(entrada);
				break;
			}
			catch(const std::invalid_argument&){

				std::cout << "Entrada inválida" << std::endl;
			}			
		}
		
		// De posse de todas as informações
		list_disciplinas.emplace_back(
									 id,
									 nome,
									 professor,
									 credito
									 );

		list_relations.emplace_back(); // Iniciamos um vetor default
		list_relations.back().emplace_back(id); // Já colocamos o id da disciplina primeiro
		while(true){

			std::cout << "Apresente os alunos matriculados na disciplina separados por vírgula(* - todos):" << std::endl;
			std::getline(std::cin, entrada);

			if(entrada.size() && entrada[0] == '*'){

				// Todos os alunos deverão ser adicionados.
				for(
					const auto& aluno : list_alunos
				){

					list_relations.back().emplace_back(aluno.get_info(0));
				}

				break;
			}
			else{

				if(entrada.find(",")){ std::cout << "Entrada inválida, separe com ','" << std::endl; continue;}
				// Apenas alguns serão matriculados

				for(
					const auto& string_id : split(entrada)
				){

					list_relations.back().emplace_back(std::stoi(string_id));
				}

				break;
			}
		}

		houve_altera = true;
	}

	/**
	 * @brief Menu de apresentação, inserção, remoção e de busca.
	 * @details
	 * 
	 * Deve fornecer ao usuário diversas funcionalidades do sistema.
	 */
	void
	mainloop(){

		bool there_is_a_error = false;
		int PULA_LINHAS = 40;
		while(true){
			for(int i = 0; i < PULA_LINHAS; i++){ printf("\n"); }

			if(there_is_a_error){ std::cout << "--> Entrada inválida." << std::endl; there_is_a_error = false; }
			print(2);
			std::cout << "\nEscolha uma opção: ";
			std::string entrada;
			std::getline(std::cin, entrada);

			try {

				int decisao = std::stoi(entrada);

				if(
					decisao == 0
				){

					// Aqui devemos ter a dinâmica de encerramento. Salvando as informações necessárias.
					break;
				}
				else if(decisao == 1){

					// Devemos apresentar outro menu.
					there_is_a_error = false;
					while(true){
						for(int i = 0; i < PULA_LINHAS; i++){ printf("\n"); }

						if(there_is_a_error){ std::cout << "--> Entrada inválida." << std::endl; there_is_a_error = false; }
						print(3);
						print(0);

						std::cout << "\nEscolha uma opção: ";
						std::getline(std::cin, entrada);

						try {

							decisao = std::stoi(entrada);

							if(decisao == 0){

								break;
							}
							else if(decisao == 1){

								// Devemos adicionar um aluno ao banco de alunos.
								// Basta que peçamos um conjunto de entradas e estaremos em condições de adicionar o novo aluno.
								printf("\n");
								insert_aluno();
							}
							else if(decisao == 2){

								printf("\n");
								remove_aluno();
							}
							else if(decisao == 3){	

								printf("\n");
								consultar_aluno();
							}
							else{

								there_is_a_error = true;
							}
						}
						catch(const std::invalid_argument&) {
							there_is_a_error = true;
						}
					}
				}
				else if(decisao == 2){

					there_is_a_error = false;
					while(true){
						for(int i = 0; i < PULA_LINHAS; i++){ printf("\n"); }

						print(4);
						print(1);

						std::cout << "\nEscolha uma opção: ";
						std::getline(std::cin, entrada);

						try {

							int decisao = std::stoi(entrada);

							if(decisao == 0){

								break;
							} 
							else if(decisao == 1){

								// Desejamos adicionar uma nova disciplina.
								insert_disciplina();
							}
							else if(decisao == 2){


							}
							else if(decisao == 3){


							}
							else{

								there_is_a_error = true;
							}
						}
						catch(const std::invalid_argument&){

							there_is_a_error = true;
						}
					}
				}
			}
			catch(const std::invalid_argument&){

				there_is_a_error = true;
			}

		}
	}
};

int main(){

	Sistema sis;

	sis.mainloop();

	return 0;
}