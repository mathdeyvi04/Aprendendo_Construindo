#pragma once

/**
 * Ela define a interface genérica que deve ser implementada 
 * por qualquer algoritmo de cifra.
 */
class Cypher {
public:
	virtual char encryptChar(char c, int key) = 0;
	virtual char decryptChar(char c, int key) = 0;
	virtual ~Cypher() = default;
};