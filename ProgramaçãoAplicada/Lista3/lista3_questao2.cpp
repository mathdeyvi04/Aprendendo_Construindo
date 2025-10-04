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

#include <regex> // Utilizaremos regex para os padrões de entrada.

/**
 * @brief Representará a entidade aluno.
 */
class Aluno {
private:

	std::string ID, nome, cpf;

public:

	/**
	 * @brief Construção 
	 */
	Aluno() = default;

	/**
	 * @brief Construtor para facilitar inserção no vetor.	
	 * @param param Vetor de parâmetros: ID, NOME, CPF
	 */
	Aluno(
		const std::vector<std::string>& param
	){

		ID   = param[0];
		nome = param[1];
		cpf  = param[2];
		
	}

	/**	
	 * @brief Retornará uma referência constante do aluno baseado em um índice	
	 */
	const std::string&
	get_info(
		int idx
	) const {

		if     (idx == 0){

			return ID;
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

	/**
	 * @brief Fará as verificações necessárias e salvará o ID do aluno.	
	 */
	void
	set_ID(){

		std::string entrada;
		std::regex pattern_ID("^\\d{5}$");
		while(true){

			std::cout << "Informe o ID do aluno: ";
			std::getline(std::cin, entrada);

			if(
				!std::regex_match(entrada, pattern_ID)
			){

				std::cout << "Entrada inválida: ID deve conter apenas 5 dígitos." << std::endl;
				continue;
			}

			// ID válido
			ID = entrada;
			break;
		}
	}

	/**
	 * @brief Fará as verificações necessárias e salvará o NOME do aluno.	
	 * @details
	 * 
	 * Não há restrições de nomes.
	 */
	void
	set_NOME(){

		// Não há restrições de nomes.
		std::cout << "Insira NOME do aluno: ";
		std::getline(std::cin, nome);
	}

	/**
	 * @brief Fará as verificações necessárias e salvará o CPF do aluno.	
	 */
	void
	set_CPF(){

		std::string entrada;
		std::regex pattern_CPF("^\\d{11}$");
		while(true){

			std::cout << "Informe o CPF do aluno: ";
			std::getline(std::cin, entrada);

			if(
				!std::regex_match(entrada, pattern_CPF)
			){

				std::cout << "Entrada inválida: CPF deve conter apenas 11 dígitos." << std::endl;
				continue;
			}

			// CPF válido
			cpf = entrada;
			break;
		}
	}
};

/**
 * @brief Representará a entidade disciplina. 
 */
class Disciplina {
private:

	std::string ID, nome, professor, credito;

public:

	/**
	 * @brief Construtor Default	
	 */
	Disciplina() = default;

	/**
	 * @brief Construtor para facilitar inserção dentro do vetor.	
	 * @param param Vetor de parâmetros, ID, NOME, PROFESSOR, CREDITO.
	 */
	Disciplina(
		const std::vector<std::string>& param
	){

		ID        = param[0];
		nome      = param[1];
		professor = param[2];
		credito   = param[3];
	}

	/**
	 * @brief Retornará uma informação do aluno baseado em um índice.	
	 */
	const std::string&
	get_info(
		int idx
	) const {

		if     (idx == 0){

			return ID;
		}
		else if(idx == 1){

			return nome;
		}
		else if(idx == 2){

			return professor;
		}
		else if(idx == 3){

			return credito;
		}
		else{

			throw std::invalid_argument("Não é possível aceitar este índice.");
		}
	}

	/**
	 * @brief Fará as verificações necessárias e salvará o ID da disciplina.	
	 */
	void
	set_ID(){

		std::string entrada;
		std::regex pattern_ID("^\\d{4}$");
		while(true){

			std::cout << "Informe o ID da disciplina: ";
			std::getline(std::cin, entrada);

			if(
				!std::regex_match(entrada, pattern_ID)
			){

				std::cout << "Entrada inválida: ID deve conter apenas 4 dígitos." << std::endl;
				continue;
			}

			// ID válido
			ID = entrada;
			break;
		}
	}

	/**
	 * @brief Fará as verificações necessárias e salvará o NOME da disciplina.	
	 */
	void
	set_NOME(){

		// Não há restrições de nomes.
		std::cout << "Insira NOME da disciplina: ";
		std::getline(std::cin, nome);
	}

	/**
	 * @brief Fará as verificações necessárias e salvará o PROFESSOR da disciplina.	
	 */
	void
	set_PROFESSOR(){

		// Não há restrições de nomes.
		std::cout << "Insira PROFESSOR da disciplina: ";
		std::getline(std::cin, professor);
	}

	/**	
	 * @brief Fará as verificações necessárias e salvará o CRÉDITO da disciplina	
	 */
	void
	set_CREDITO(){

		std::string entrada;
		std::regex pattern_CREDITO("^\\d+$");
		while(true){

			std::cout << "Informe o CREDITO da disciplina: ";
			std::getline(std::cin, entrada);

			if(
				!std::regex_match(entrada, pattern_CREDITO)
			){

				std::cout << "Entrada inválida: CREDITO deve conter apenas dígitos." << std::endl;
				continue;
			}

			// CPF válido
			credito = entrada;
			break;
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
	std::vector<std::vector<std::string>> list_relations;

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
	 * @details
	 * 
	 * Caso seja forçado pelo usuário, se responsabilizará pela obtenção dos novos valores.
	 */
	void
	set_ano_periodo(
		bool automatico = true
	){

		time_t agora = std::chrono::system_clock::to_time_t(
			                                               std::chrono::system_clock::now()
			                                               );

		struct tm *local_time = localtime(&agora);

		ano     = local_time->tm_year + 1900;
		periodo = (local_time->tm_mon + 1) / 6 + 1;
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
			std::cout << "Banco de dados criado..." << std::endl;
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

					list_relations.emplace_back(
												std::move(split(linha))
											   );
				}
			}
		}

		database.close();
	}

	/**
	 * @brief Fornerá o nome do aluno ou da disciplina.	
	 */
	std::string
	get_name(const std::string& ID){

		// Sabemos que é disciplina
		if     (ID.size() == 4){

			for(
				const auto& disciplina : list_disciplinas
			){

				if(disciplina.get_info(0) == ID){ return disciplina.get_info(1); }
			}
		}
		// Sabemos que é aluno
		else if(ID.size() == 5){

			for(
				const auto& aluno : list_alunos
			){

				if(aluno.get_info(0) == ID){ return aluno.get_info(1); }
			}
		}
	
		return "";
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

		std::cout << "Visualizando em... " << ano << "." << periodo << std::endl;
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
				"0 - Voltar",
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
				"0 - Voltar",
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
	 * @brief Verificará se o ID de um aluno ou de uma disciplina já existe.
	 * @param ID String do ID da entidade.
	 * @param is_aluno Flag para indicar se estamos buscando aluno ou disciplina.
	 * @return True se existe. False, caso contrário.
	 */
	bool
	exists(const std::string& ID, bool is_aluno){

		if(is_aluno){

			// Devemos varrer no sistema e verificar se o aluno existe.
			for(
				const auto& aluno : list_alunos
			){

				if( aluno.get_info(0) == ID ){

					return true;
				}
			}
		}
		else{

			for(
				const auto& disciplina : list_disciplinas
			){

				if( disciplina.get_info(0) == ID ){

					return true;
				}
			}

		}

		return false;
	}

	/**
	 * @brief Fornecerá as ferramentas para inserção de um novo aluno ao sistema.
	 */
	void
	insert_aluno(){
		
		Aluno aluno_a_ser_adicionado; // Iniciamos um aluno default

		// Com isso, garantimos que não há aluno com mesmo ID.
		bool error_dualidade = false;
		while(
			// Se ele existir dentro da lista de alunos
			// Se o ID estiver vazio
			exists(aluno_a_ser_adicionado.get_info(0), true) || aluno_a_ser_adicionado.get_info(0).empty()
		){ 
			if(error_dualidade){ std::cout << "Já há um aluno com este ID." << std::endl; error_dualidade = true; }
			
			aluno_a_ser_adicionado.set_ID();
			error_dualidade = true;
		}

		aluno_a_ser_adicionado.set_NOME();

		aluno_a_ser_adicionado.set_CPF();

		list_alunos.push_back(aluno_a_ser_adicionado);

		// As matrículas são completamente responsabilidade do Sistema.
		std::regex pattern_relation_str("^\\d{4}(,\\d{4})*$");
		std::string relation_str;
		print(1);
		while(true){

			std::cout << "Informe os ID's das disciplinas que este aluno está matriculado separado por vírgulas: \n";
			std::getline(std::cin, relation_str);

			if(
				std::regex_match(relation_str, pattern_relation_str)
			){

				break;
			}
			else{

				std::cout << "Entrada inválida: Deve existir pelo menos uma vírgula." << std::endl;
			}
		}

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
					aluno_a_ser_adicionado.get_info(0) == list_relations[i][0]
				){

					// Achamos a disciplina na lista de relações.
					// Nela devemos adicionar o novo aluno matriculado
					list_relations[i].push_back(aluno_a_ser_adicionado.get_info(0)); // Adicionamos o id do aluno.

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

		Aluno aluno_a_ser_removido;

		// Garantimos o ID existe e não é vazio
		bool error_dualidade = false;
		while(
			!exists(aluno_a_ser_removido.get_info(0), true) || aluno_a_ser_removido.get_info(0).empty()
		){ 
			if(error_dualidade){ std::cout << "Não há aluno com este ID." << std::endl; error_dualidade = false; }
			aluno_a_ser_removido.set_ID(); 
			error_dualidade = true;
		}

		// Supondo que conseguimos, devemos removê-lo da lista de alunos.
		list_alunos.erase(
						 std::remove_if(
						 			   list_alunos.begin(),
						 			   list_alunos.end(),
						 			   // Utilizamos função anônima
						 			   [aluno_a_ser_removido](const Aluno& aluno){ return aluno.get_info(0) == aluno_a_ser_removido.get_info(0); }
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
 						   			  aluno_a_ser_removido.get_info(0)
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

			Aluno aluno_a_ser_consultado;

			// Devemos ter garantia que ele existe
			bool error_dualidade = false;
			while(
				!exists(aluno_a_ser_consultado.get_info(0), true) || aluno_a_ser_consultado.get_info(0).empty()
			){ 
				if(error_dualidade){ std::cout << "Não há aluno com este ID." << std::endl; error_dualidade = false; }
				aluno_a_ser_consultado.set_ID(); 
				error_dualidade = true;
			}

			// Garantido que o ano existe, o sistema pode buscá-lo.
			std::cout << "Aluno "
					  << aluno_a_ser_consultado.get_info(0)
					  << " matriculado em:"
					  << std::endl;
			for(
				const auto& relations : list_relations
			){

				// Devemos verificar em que disciplina esse ID existe.
				for(
					int i = 1; // O primeiro é o ID da disciplina
						i < (int)relations.size();
						i++
				){

					if(
						aluno_a_ser_consultado.get_info(0) == relations[i]
					){

						std::cout << "- "
						          << relations[0]
						          << " | "
						          << get_name(relations[0])
						          << std::endl;

						break; // Não precisamos mais guardar
					}
				}
			}

			// Devemos verificar se há necessidade de mais uma consulta
			std::string entrada;
			while(true){

				std::cout << "Mais uma consulta?(0 - Não)(1 - Sim): " << std::endl;
				std::getline(std::cin, entrada);

				if(entrada == "0"){

					return;
				}
				else if(entrada == "1"){

					break;
				}
				else{

					std::cout << "Entrada inválida" << std::endl;
				}
			}
		}

		// Não há alteração do banco de dados, logo não precisamos salvar algo
	}

	/**
	 * @brief Fornecerá as ferramentas necessárias para adição de uma nova disciplina.	
	 */
	void
	insert_disciplina(){

		Disciplina disciplina_a_ser_adicionada;

		bool error_dualidade = false;
		while(
			exists(disciplina_a_ser_adicionada.get_info(0), false) || disciplina_a_ser_adicionada.get_info(0).empty()
		){
			if(error_dualidade){ std::cout << "Já há uma disciplina com este ID." << std::endl; error_dualidade = false;}
			disciplina_a_ser_adicionada.set_ID();
			error_dualidade = true;
		}

		disciplina_a_ser_adicionada.set_NOME();

		disciplina_a_ser_adicionada.set_PROFESSOR();

		disciplina_a_ser_adicionada.set_CREDITO();

		list_disciplinas.push_back(disciplina_a_ser_adicionada);

		// Adicionaremos os alunos que estão matriculados nela.
		list_relations.emplace_back();
		list_relations.back().emplace_back(disciplina_a_ser_adicionada.get_info(0)); // Já colocamos o id da disciplina primeiro
		std::regex pattern_relation_str_("^\\d{5}(,\\d{5})*$");
		std::string entrada;
		while(true){

			std::cout << "Apresente os alunos matriculados na disciplina separados por vírgula(* - todos):" << std::endl;
			std::getline(std::cin, entrada);

			if(entrada == "*"){

				// Todos os alunos deverão ser adicionados.
				for(
					const auto& aluno : list_alunos
				){

					list_relations.back().emplace_back(aluno.get_info(0));
				}

				break;
			}
			else{

				if(std::regex_match(entrada, pattern_relation_str_)){

					// Há alguns que devemos adicionar
					for(
						const auto& string_id_aluno : split(entrada)
					){

						// Devemos salvar apenas os alunos que existem.

						if(
							exists(string_id_aluno, true)
						){

							list_relations.back().emplace_back(string_id_aluno);
						}
						else{

							std::cout << "Ignorando ID inexistente: " 
									  << string_id_aluno
									  << std::endl;
						}
					}

					break;
				}
			}

			std::cout << "Entrada inválida." << std::endl;
		}

		houve_altera = true;
	}

	/**
	 * @brief Fornecerá as ferramentas necessárias para remoção de uma disciplina.	
	 */
	void
	remove_disciplina(){

		Disciplina disciplina_a_ser_removida;

		bool error_dualidade = false;
		while(
			!exists(disciplina_a_ser_removida.get_info(0), false) || disciplina_a_ser_removida.get_info(0).empty()
		){

			if(error_dualidade){ std::cout << "Não há disciplina com este ID." << std::endl; error_dualidade = false; }
			disciplina_a_ser_removida.set_ID();
			error_dualidade = true;
		}

		list_disciplinas.erase(
							  std::remove_if(
							 			   list_disciplinas.begin(),
							 			   list_disciplinas.end(),
							 			   // Utilizamos função anônima
							 			   [disciplina_a_ser_removida](const Disciplina& disciplina){ return disciplina.get_info(0) == disciplina_a_ser_removida.get_info(0); }
							 			   ),
							  list_disciplinas.end()
							  );

		// Independente dos alunos matriculados, devemos remover a disciplina.
		list_relations.erase(
							std::remove_if(
							 			   list_relations.begin(),
							 			   list_relations.end(),
							 			   // Utilizamos função anônima
							 			   [disciplina_a_ser_removida](const std::vector<std::string>& relations){ return relations[0] == disciplina_a_ser_removida.get_info(0); }
							 			   ),
							list_relations.end()
							);

		houve_altera = true;
	}

	/**
	 * @brief Fornecerá a lista de alunos matriculados na disciplina	
	 */
	void
	consultar_disciplina(){

		while(true){

			Disciplina disciplina_a_ser_consultada;

			bool error_dualidade = false;
			while(
				!exists(disciplina_a_ser_consultada.get_info(0), false) || disciplina_a_ser_consultada.get_info(0).empty()
			){ 
				if(error_dualidade){ std::cout << "Não há disciplina com este ID." << std::endl; error_dualidade = false; }
				disciplina_a_ser_consultada.set_ID(); 
				error_dualidade = true;
			}

			// Temos confirmação de existência
			for(
				const auto& relations : list_relations
			){

				if( relations[0] == disciplina_a_ser_consultada.get_info(0) ){

					// Achamos a disciplina
					for(
						int i = 1;
							i < (int)relations.size();
							i++
					){

						std::cout << "- "
								  << relations[i]
								  << " | "
								  << get_name(relations[i])
								  << std::endl;
					}				
				}
			}

			// Devemos verificar se há necessidade de mais uma consulta
			std::string entrada;
			while(true){

				std::cout << "Mais uma consulta?(0 - Não)(1 - Sim): " << std::endl;
				std::getline(std::cin, entrada);

				if(entrada == "0"){

					return;
				}
				else if(entrada == "1"){

					break;
				}
				else{

					std::cout << "Entrada inválida" << std::endl;
				}
			}
		}
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
		int PULA_LINHAS = 30;
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

								remove_disciplina();
							}
							else if(decisao == 3){

								consultar_disciplina();
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
				else{

					there_is_a_error = true;
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