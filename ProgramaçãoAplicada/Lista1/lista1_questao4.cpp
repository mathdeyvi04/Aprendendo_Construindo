#include <iostream>
	
/**
 * @brief Responsável por representar o aluno da academia.
 */
class Aluno {
private:

	// Autoexplicativos
    std::string _nome;
    double    _altura; 
    double      _peso;   

public:

	/**
	 * @brief Construtor default	
	 */
    Aluno(
    	std::string n = "", 
    	double a = 0.0, 
    	double p = 0.0
    ) : _nome(n),
    	_altura(a),
    	_peso(p)
    {}

	/**
	 * @brief Setter de nome
	 * @details
	 * 
	 * Verifica se o nome é vazia, retornando False caso sim.
	 * Caso contrário, True.  
	 */
    bool
    set_nome(
    	const std::string& n
    ){
        if( n.empty() ){ return false; }

        _nome = n;
        return true;
    }

	/**
	 * @brief Setter de altura
	 * @details
	 * 
	 * Retorna false caso altura seja inválida.
	 * Caso contrário, true.    
	 */
    bool
    set_altura(
    	double a
    ){
        if(a <= 0){ return false; }

        _altura = a;
        return true;
    }

	/**
	 * @brief Setter de peso
	 * @details
	 * 
	 * Retorna false caso peso seja inválido.
	 * Caso contrário, false.   
	 */
    bool
    set_peso(
    	double p
    ){
        if(p <= 0){ return false; }

        _peso = p;
        return true;
    }

    std::string get_nome()   const { return _nome;   }  ///< Getter de Nome
    double      get_altura() const { return _altura; }  ///< Getter de Altura
    double      get_peso()   const { return _peso;   }  ///< Getter de Peso

	/**
	 * @brief Responsável por obter o IMC do aluno.    
	 */
    double 
    calcular_IMC() const {
        
        // É possível que o usuário tente acessar IMC sem que o aluno
        // esteja em condições
        if(
        	_peso == 0 || _altura == 0
        ){

        	std::cout << "Aluno ainda não setado.\n";
        	return 0.0;
        }

        return _peso / (_altura * _altura);
    }
};

int main(){

	Aluno aluno; 
    std::string nome, altura, peso;

    while(true){

        std::cout << "Digite o nome completo do aluno: ";

    	std::getline(std::cin, nome);

    	if( aluno.set_nome(nome) ){ break; }

    	std::cout << "Nome Inválido.\n";
    }

    while(true){

        std::cout << "Digite a altura completo do aluno: ";
        
        std::getline(std::cin, altura);

        try {
            if( aluno.set_altura(std::stod(altura)) ){ break; }
        }
        catch ( const std::invalid_argument& ) {

        }

        std::cout << "Altura Inválida.\n";
    }

    while(true){

        std::cout << "Digite o peso completo do aluno: ";
        
        std::getline(std::cin, peso);

        try {
            if( aluno.set_peso(std::stod(peso)) ){ break; }
        }
        catch ( const std::invalid_argument& ) {

        }

        std::cout << "Peso Inválido.\n";
    }

    std::cout << "O aluno " 
              << aluno.get_nome()
              << " possui IMC = "
              << aluno.calcular_IMC();

    printf("\n");
	return 0;
}