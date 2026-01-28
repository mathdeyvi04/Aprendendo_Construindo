#pragma once

#include "CaesarCypher.hpp"
#include "FileManager.hpp"
#include "HeaderAndChecksum.hpp"
#include <iostream>

/**
 * A classe SecureFileProcessor é o núcleo integrador do sistema.
 * Seu papel é coordenar todas as etapas do processo — leitura, criptografia, adição de
 * cabeçalho e checksum, gravação, validação e descriptografia.
 */
class SecureFileProcessor : public CaesarCypher, FileManager, HeaderAndChecksum {
public:
	void 
	encryptFile(
		const std::string& input, const std::string& output, int key
	){
        std::string content = readFile(input);
        std::string encrypted;
        encrypted.resize(content.size()); // Vamos apenas pegar uma quantidade de reserva para ser mais eficiente
        for(int i = 0; i < content.size(); ++i){ encrypted[i] = encryptChar(content[i], key); }

        std::string finalData = addHeaderAndChecksum(encrypted);
        writeFile(output, finalData);
    }

    void decryptFile(const std::string& input, const std::string& output, int key) {
        std::string rawContent = readFile(input);
        
        std::string validated = removeHeaderAndValidate(rawContent);
        
        std::string decrypted;
        decrypted.resize(validated.size());
        for(int i = 0; i < validated.size(); ++i){ decrypted[i] = decryptChar(validated[i], key); }

        writeFile(output, decrypted);
    }
};