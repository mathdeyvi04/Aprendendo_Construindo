#pragma once

#include <fstream>
#include <sstream>
#include <stdexcept>
/**
 * Esta classe é responsável por toda a manipulação de arquivos, tanto de leitura quanto
 * de gravação. Seu propósito é isolar o acesso a arquivos do restante da lógica de criptografia,
 * garantindo a clareza do código e facilitando testes unitários.
 */
class FileManager {
public:
    static std::string 
    readFile(
    	const std::string& filename
    ){
        
        std::ifstream file(filename, std::ios::in | std::ios::binary); // Tenta abrir seja binário ou ascii
        if(!file.is_open()){ throw std::runtime_error("Falha ao abrir arquivo para leitura"); }

        // Lemos
        std::ostringstream buffer;
        buffer << file.rdbuf();
		if(file.fail()){ throw std::runtime_error("Erro ao ler arquivo"); }

        return buffer.str();
    }

    static void 
    writeFile(
    	const std::string& filename,
    	const std::string& content
    ){
    	// Tentamos abrir para escrever em binário ou ascii
        std::ofstream file(filename, std::ios::out | std::ios::binary | std::ios::trunc);
        if(!file.is_open()){ throw std::runtime_error("Falha ao abrir arquivo para escrita"); }

        file.write(content.data(), static_cast<std::streamsize>(content.size()));
        if(!file.good()){throw std::runtime_error("Erro ao gravar arquivo"); }
    }
};