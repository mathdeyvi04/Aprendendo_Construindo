#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main(){

	std::vector<int> numeros = {1, 5, 2, 5, 3, 10, 1, 7, 5};

	// -------- Não modificadores 
    std::cout << "O numero 5 aparece " << std::count(numeros.begin(), numeros.end(), 5) << " vezes.\n";

    if(
    	std::find(numeros.begin(), numeros.end(), 10) != numeros.end()
    ){

    	std::cout << "O número 10 existe no vetor.\n";
    }
    else{

    	std::cout << "O número 10 não foi encontrado no vetor.\n";
    }

    // --------- Modificadores
    std::replace(numeros.begin(), numeros.end(), 1, 99);

    std::cout << "Vetor apos substituir 1 por 99: ";
    for (int n : numeros)
        std::cout << n << " ";
    std::cout << "\n";

    // ---- Ordenação e Conjuntos
    std::vector<int> v1 = {1, 3, 5, 7, 9};
    std::vector<int> v2 = {2, 4, 6, 8, 10};
    std::vector<int> v_merge(v1.size() + v2.size());

    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v_merge.begin());
    std::cout << "Vetor mesclado (merge): ";
    for (int n : v_merge) std::cout << n << " ";
    std::cout << "\n\n";

    std::set<int> A = {1, 2, 3, 5, 7};
    std::set<int> B = {3, 4, 5, 6, 7};
    std::vector<int> uniao, intersecao;

    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(uniao));
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(intersecao));

    std::cout << "Uniao: ";
    for (int n : uniao) std::cout << n << " ";
    std::cout << "\nIntersecao: ";
    for (int n : intersecao) std::cout << n << " ";
    std::cout << "\n\n";

    // ------- Medições ordenadas
    std::srand((unsigned)std::time(nullptr));
    std::vector<double> potencias(15);
    for (double &p : potencias)
        p = (std::rand() % 10001) / 100.0; // 0 a 100.00 W

    std::sort(potencias.begin(), potencias.end());
    std::cout << "Tres maiores potencias: ";
    for (int i = potencias.size() - 3; i < (int)potencias.size(); ++i)
        std::cout << potencias[i] << " ";
    std::cout << "W\n\n";

    // ----- Comparação de leituras
    std::vector<double> f1 = {98.5, 100.7, 98.5, 101.2, 99.3};
    std::vector<double> f2 = {97.1, 98.5, 99.3, 100.7, 102.0};
    std::vector<double> iguais;

    std::sort(f1.begin(), f1.end());
    std::sort(f2.begin(), f2.end());
    std::set_intersection(f1.begin(), f1.end(), f2.begin(), f2.end(), std::back_inserter(iguais));

    std::cout << "Leituras iguais: ";
    for(double f : iguais){ std::cout << f << " "; }
    std::cout << "Hz\n";

	return 0;
}
