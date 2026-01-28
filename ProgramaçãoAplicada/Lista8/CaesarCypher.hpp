#pragma once

#include <string>
#include "Cypher.hpp"
/**
 * A classe CaesarCypher implementa a lógica da Cifra de César, 
 */
class CaesarCypher : public Cypher {
private:
	inline static std::string alfabeto_circular = "ABCDEFGHIJKLMNOPQRSTUVWXYZ#$ &*@().:,!?[]=+-%abcdefghijklmnopqrstuvwxyz";

public:

	char
	encryptChar(
		char c,
		int key
	) override {

		int idx = alfabeto_circular.find(c);

		return (idx == std::string::npos) ? c : alfabeto_circular[(idx + key) % alfabeto_circular.size()]; 
	}

	char
	decryptChar(
		char c,
		int key
	) override {
		
		int idx = alfabeto_circular.find(c);

		// Devemos fazer uma correção para indices negativos, é trivial
		// É garantido que é menor que o comprimento total, logo podemos retirar o % no final
		return (idx == std::string::npos) ? c : alfabeto_circular[(((idx - key) < 0) ? idx - key + alfabeto_circular.size() : idx - key)]; 
	}
};