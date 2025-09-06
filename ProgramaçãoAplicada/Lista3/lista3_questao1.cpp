#include <iostream>
#include <cmath>  // Para importarmos o std::sqrt()

/**
 * @brief Representar o conjunto dos números complexos e suas propriedades.
 */
class Complex {
private:

	float _real, _img;

public:

	/**
	 * @brief Construtor da classe Complex
	 * @details
	 * Caso não sejam inseridos valores, inicializará com valores zerados.	
	 */
	Complex(float real = 0, float img = 0) : _real(real), _img(img) {}

	/**
	 * @brief Sobrecarga do operador <<, a fim de proporcionar apresentação do número.	
	 */
	friend std::ostream&
	operator<<(
		std::ostream& os,
		const Complex& cp
	){

		os << cp._real 
		   << ((cp._img >= 0) ? '+' : '-')
		   << ((cp._img >= 0) ? cp._img : -cp._img)
		   << "i";

		return os;
	}

	/**
	 * @brief Sobrecarga do operator SOMA
	 */
	Complex
	operator+(
		const Complex& other_cp
	){

		return Complex(
						this->_real + other_cp._real,
						this->_img  + other_cp._img
					  );
	}

	/**
	 * @brief Sobrecarga do operator DIFERENÇA
	 */
	Complex
	operator-(
		const Complex& other_cp
	){

		return Complex(
						this->_real - other_cp._real,
						this->_img  - other_cp._img
					  );
	}

	/**
	 * @brief Sobrecarga do operator MULTIPLICAÇÃO	
	 */
	Complex
	operator*(
		const Complex& other_cp
	){

		return Complex(
						this->_real * other_cp._real - this->_img * other_cp._img,
						this->_real * other_cp._img  + this->_img * other_cp._real
					  );
	}

	/**
	 * @brief Sobrecarga do operator DIVISÃO	
	 */
	Complex
	operator/(
		const Complex& other_cp
	){

		if(
			(other_cp._real * other_cp._real + other_cp._img * other_cp._img) == 0
		){

			throw std::invalid_argument("\033[1;31mDivisão por zero não permitida.\033[0m");
		}

		return Complex(
						(this->_real * other_cp._real + this->_img  * other_cp._img) / (other_cp._real * other_cp._real + other_cp._img * other_cp._img),
						(this->_img  * other_cp._real - this->_real * other_cp._img) / (other_cp._real * other_cp._real + other_cp._img * other_cp._img)
					  );
	}

	/**
	 * @brief Sobrecarga do operator IGUALDADE	
	 */
	bool
	operator==(
		const Complex& other_cp
	){

		return this->_real == other_cp._real && this->_img == other_cp._img;
	}

	/**
	 * @brief Retornará uma cópia da parte REAL
	 */
	float 
	get_real(){ return _real;}

	/**
	 * @brief Retornará uma cópia da parte IMAGINÁRIA	
	 */
	float
	get_img() { return _img; }

	/**
	 * @brief Retornará uma cópia do MÓDULO do complexo.	
	 */
	float
	get_abs() { return std::sqrt(_real * _real + _img * _img); }

	/**
	 * 	@brief Retornará o complexo conjugado.
	 */
	Complex
	get_conj() { return Complex(_real, - _img); }
};

int main(){

	Complex cp(1, -1);
	Complex a(0, 0);

	std::cout << cp / a << std::endl;
	return 0;
}
