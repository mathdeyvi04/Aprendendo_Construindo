#include <iostream>
#include <vector>
#include <string.h>

class Livro {
// Alteramos posição para ter mais sentido
private:
	char* titulo;
	char* autor;
	int quantidade;

public:
	// Adicionamos const para permitir a leitura como string
	Livro(const char* titulo, const char* autor, const int qtd) {
		// Devemos primeiro alocar memória, pois estavamos copiando para nullptr
		this->titulo = new char[strlen(titulo) + 1];
		this->autor = new char[strlen(autor) + 1];

		strcpy(this->titulo, titulo);
		strcpy(this->autor, autor);
		this->quantidade = qtd;
	}

	// Com isso, liberamos memória corretamente
	~Livro(){ delete[] this->titulo; delete[] this->autor; }

	bool emprestar() {
		// Retiramos a igualdade, pois isso permitiria emprestarmos mesmo
		// com 0 livros
		if (quantidade > 0) {  
			quantidade--;
			return true;
		} else {
			return false;
		}
	}

	void imprimir() {
		std::cout << "Livro: " << titulo
				  << " | Autor: " << autor
				  << " | Quant.: " << quantidade << std::endl;
	}
};

class Biblioteca {
	// Implementamos com std::vector conforme enunciado pede
	std::vector<Livro*> livros;
	int total;

public:
	Biblioteca() {
		total = 0;
	}

	// A função agora chama por um ponteiro, pois antes ela pegava a memória
	// de uma cópia que era passada
	void adicionarLivro(Livro* l) { 
		// Evitamos ponteiros inválidos
		if(l != nullptr){ livros.push_back(l); total++; }
	}

	void listar() {
		for (int i = 0; i < total; i++) {
			livros[i]->imprimir();
		}
	}
};

int main() {
	Livro l1("1984", "George Orwell", 1);
	Biblioteca b;
	b.adicionarLivro(&l1);
	b.listar();

	l1.emprestar();  
	l1.emprestar();  
	b.listar();      
	return 0;
}
