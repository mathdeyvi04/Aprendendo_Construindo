#pragma once

#include <cstdint>

/**
 * Esta classe trata da integridade e estruturação do arquivo. Ela é responsável por
 * adicionar e validar informações de controle que garantem que o arquivo não foi corrompido
 * durante a transmissão ou armazenamento. 
 */
class HeaderAndChecksum {
public:
    static std::string 
    addHeaderAndChecksum(
    	const std::string& content
    ){
        uint32_t size = static_cast<uint32_t>(content.size());
        
        // Adicionaremos cabeçalho
        std::string result(4, '\0');
        for(int i = 0; i < 4; ++i){ result[i] = static_cast<char>((size >> (8 * i)) & 0xFF); } // Observe que fazemos operação entre bits
        
        // Calculamos o checksum
        uint8_t checksum = 0;
        for(unsigned char c : content){ checksum += c; }
        
        // Adicionamos o conteúdo e finalmente o checksum
        result += content;
        result.push_back(static_cast<char>(checksum));
        return result;
    }

    static std::string 
    removeHeaderAndValidate(
    	const std::string& rawContent
    ){
    	// Verificamos se é válido
        if(rawContent.size() < 5){ throw std::runtime_error("Arquivo corrompido"); }
        
        // Com operações bit a bit, verificamos se está de acordo
        uint32_t size = 0;
        for(int i = 0; i < 4; ++i){ size |= (static_cast<uint8_t>(rawContent[i]) << (8 * i)); } 
        if(rawContent.size() != size + 5){ throw std::runtime_error("Tamanho inconsistente"); }

    	// Retiramos o cabeçalho para verificar conteúdo
        std::string content = rawContent.substr(4, size);
        uint8_t expected = 0;
        for(unsigned char c : content){ expected += c; }
        if(expected != static_cast<uint8_t>(rawContent.back())){ throw std::runtime_error("Checksum inválido"); }
        
        // Caso tenha passado pelas verificações, é válida.
        return content;
    }
};