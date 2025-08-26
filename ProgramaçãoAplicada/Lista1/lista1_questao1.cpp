#include <iostream>

/*
Questão 1

Uma fila é um tipo de estrutura de dados utilizado em computação que funciona como
uma fila de objetos do nosso dia a dia: o primeiro elemento a ser inserido é o primeiro a
ser retirado. Por causa da forma como os dados são guardados e acessados, essa estrutura
também é chamada de FIFO (first-in first-out, o último a entrar é o último a sair).

A implementação de uma estrutura de dados do tipo fila pode ser feita através de uma
classe. Esta classe deve permitir que sejam inseridos e retirados elementos da fila e manter
o controle da quantidade de elementos disponíveis na fila. Assim bloqueando operações
inválidas, como por exemplo, retirar elementos de uma fila vazia.

a) Desenhar fluxograma explicando como seria uma possível estratégia de implementação da
classe.

b) Declarar a classe fila especificando quais métodos e atributos seriam necessários e
suficientes para implementá-la.
*/

//--------------------------------------------------------------------------------------------
	
/**
 * @brief Responsável por representar a estrutura de dados FIFO.
 * @details 
 * 
 * Conforme explicitado no enunciado, apenas focaremos na implementação básica de inserção e 
 * remoção.
 */
template <typename T_class>
class Fila {
private:

	T_class* _fifo = nullptr; ///< Ponteiro para estrutura de armazenamento
	size_t _full_length;     ///< Valor positivo indicando quantidade total de possível armazenamento
	size_t _front;           ///< Valor positivo indicando índice do primeiro elemento
	size_t _back;            ///< Valor positivo indicando índice do último elemento
	size_t _length;          ///< Valor positivo indicando quantidade instântanea de elementos

public:

		/**
		 * @brief Construtor da Classe Fila
		 * @details
		 * 
		 * Observe que alocamos um array que representará nossa estrutura 
		 * na memória.	
		 */
		explicit Fila(
			size_t full_len
		) : 
			_full_length(full_len),
			_front(0),	
			_back(full_len - 1),
			_length(0)
		{

			_fifo = new T_class[_full_length];
		}

	/**
	 * @brief Destrutor da Classe Fila
	 * @details
	 * 
	 * Obviamente, desalocamos da maneira correta.
	 */
	~Fila(){

		if( !_fifo ){ delete[] _fifo; }
	}

	/**
	 * @brief Responsável por verificar se a fila está cheia.	
	 */
	bool
	is_full()  const { return _length == _full_length; }

	/**
	 * @brief Responsável por verificar se a fila está vazia.	
	 */
	bool
	is_empty() const { return _length ==            0; }

	/**
	 * @brief Responsável por inserir um elemento no final da fila.	
	 * @details
	 * 
	 * Retornará True se foi bem sucedido. False, caso contrário.
	 */
	bool
	insert(
		const T_class& elemento
	){

		// Garantimos que há espaço.
		if( is_full() ){ return false; }

		// Aumentamos o índice garantindo que não ultrapasse o total.
		_back = (_back + 1) % _full_length;

		// Inserimos
		_fifo[_back] = elemento;
		_length++;

		return true;
	}

	/**
	 * @brief Responsável por remover um elemento do início da fila, retornando-o.
	 * @details
	 * 
	 * Retornará o elemento caso bem sucedido. Error, caso contrário.
	 */
	T_class
	pop(){
		
		if( is_empty() ){ throw std::underflow_error("Fila está vazia."); }

		T_class elem = _fifo[_front];
		_front = (_front + 1) % _full_length;
		_length--;

		return elem;
	}

	/**
	 * @brief Retornará o elemento da frente, sem removê-lo.
	 * @details
	 * 
	 * Caso esteja vazia, haverá error.	
	 */
	T_class
	get() const {

		if( is_empty() ){ throw std::underflow_error("Fila está vazia"); }

		return _fifo[_front];
	}

	/**
	 * @brief Retornará a quantidade de elementos.	
	 */
	size_t
	size() const { return _length; }


	/**
	 * @brief Sobrecarga do operador `<<`, responsável por apresentar a fila.
	 * @details
	 * 
	 * A lógica da função respeita o funcionamento da estrutura FIFO.	
	 */
	friend std::ostream&
	operator<<(
			std::ostream& os,
			const Fila& other_fifo
	){

		os << "[";
		for(
			size_t i = 0;
						 i < other_fifo._length;
						 i++
		){

			size_t idx = (other_fifo._front + i) % other_fifo._full_length;

			os << other_fifo._fifo[idx];
			
			if( i < (other_fifo._length - 1)){

				os << ", ";
			}
		}

		os << "]";
		return os;
	}

	/**
	 * @brief Apresentará o fluxo de funcionamento básico da classe. Solução item A.
	 * @details 
	 * 
	 * Como esta função não acessa elementos ou chama outras funções de classe, 
	 * caracterizasse como uma função estática.	
	 */ 
	static void
	print_flux(){
		std::cout <<
R"(               
                                                    +----------+                                         
                                                    |Criar Fila|                                         
                                                    +-----+----+                                         
                                                          |                                              
         +----------------------------+-------------------+---------+----------------------------+       
         |                            |                             |                            |       
         v                            v                             v                            v       
       +---+                      +------+                        +---+                       +----+     
       |get|                      |insert|                        |pop|                       |size|     
       +-+-+                      +---+--+                        +-+-+                       +--+-+     
         |                            |                             |                            |       
         v                            v                             v                            v       
   +-----------+                +-----------+                 +-----------+                +------------+
   |Está Vazia?|                |Está Cheia?|                 |Está Vazia?|                |Retorna     |
   +-----+-----+                +-----+-----+                 +-----+-----+                |quantidade  |
         |                            |                             |                      |de elementos|
   +-----+-----+                +-----+-----+                 +-----+-----+                +------------+
   |           |                |           |                 |           |                              
   v           v                v           v                 v           v                              
 +---+       +---+            +---+       +---+             +---+       +---+                            
 |sim|       |não|            |sim|       |não|             |sim|       |não|                            
 +-+-+       +-+-+            +-+-+       +-+-+             +-+-+       +-+-+                            
   |           |                |           |                 |           |                              
   v           v                v           v                 v           v                              
+-----+   +---------+        +-------+  +--------+         +-----+   +---------+                         
|Error|   |Retorna  |        |Retorna|  |Aloca   |         |Error|   |Retira   |                         
+-----+   |primeiro |        |False  |  |elemento|         +-----+   |elemento |                         
          |elemento |        +-------+  |no final|                   +----+----+                         
          +---------+                   +---+----+                        |                              
                                            |                             |                              
                                            v                             v                              
                                         +-------+                   +--------+                          
                                         |Retorna|                   |Retorna |                          
                                         |True   |                   |Elemento|                          
                                         +-------+                   +--------+                                                                                 
)";
	}
};

int main(){

	Fila<int> exemplo(4);

	std::cout << "Solução item a):\n";
	exemplo.print_flux();

	std::cout << "Solução item b):\n-------------\n"
						<< "Criação de Fila:";

	std::cout << "\n\nInserindo elementos: \n"
						<< exemplo  
						<< std::endl;
	exemplo.insert(1);
	std::cout << exemplo << std::endl;
	exemplo.insert(2);
	std::cout << exemplo << std::endl;
	exemplo.insert(3);
	std::cout << exemplo
						<< "\n\nRemovendo elementos:\n";
	exemplo.pop();
	std::cout << exemplo << std::endl;



	for(
		int i = 0;
				i < 3;
				i++
	){

		printf("\n");
	}
	return 0;
}
