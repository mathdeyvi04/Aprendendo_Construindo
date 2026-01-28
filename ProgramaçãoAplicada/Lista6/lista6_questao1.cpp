#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

int
main(){

	std::vector<uint8_t> pacote = {
		0x01 , 0x00 , 0x23 , 0x14 , 0x33 , 0x39 , 0x35 ,
		0x36 , 0x3B , 0x29 , 0x60 , 0x7A , 0x12 , 0x3B ,
		0x2C , 0x3F , 0x28 , 0x3B , 0x7A , 0x2F , 0x37 ,
		0x3B , 0x7A , 0x0C , 0x1F , 0x7A , 0x34 , 0x35 ,
		0x7A , 0x3E , 0x33 , 0x3B , 0x7A , 0x6A , 0x6F ,
		0x75 , 0x6B , 0x6B , 0x01 , 0x00 , 0x12 , 0x14 ,
		0x33 , 0x39 , 0x35 , 0x36 , 0x3B , 0x29 , 0x60 ,
		0x7A , 0x18 , 0x35 , 0x3B , 0x7A , 0x29 , 0x35 ,
		0x28 , 0x2E , 0x3F
	};

	uint8_t chave= 0x00;

	int idx = 0;
	while(
		true
	){

		// Primeiro, tentar obter o tipo de algoritmo
		if(
			pacote[idx] == 0x01
		){
			// Algoritmo Simples

			// Os dois próximos bytes possuem informações de tamanho de mensagem
			int tamanho_de_mensagem = pacote[++idx] << 8 | pacote[++idx];

			// Conforme dito, há 7 bytes para o nome Nicolas.
			// Como já é sabido que cada caractere equivale a 1 byte, fica trivial

			chave = pacote[++idx] ^ static_cast<uint8_t>('N');

			// Consideremos que essa é chave mesmo.
			std::string mensagem = "";
			int idx_ = 0;
			while(
				idx_ < tamanho_de_mensagem
			){

				mensagem += pacote[idx] ^ chave;

				idx_++;
				idx++;
			}
			std::cout << "Mensagem: " << mensagem << std::endl;
			idx--;

		}
		else{
			// Algoritmo Desconhecido

		}

		if(
			idx > pacote.size()
		){

			break;
		}
		idx++;
	}

	// Já passamos pelo processo de decripto
	// Vamos enviar agora.
	// Deyvisson=10, Salgado=10
	std::string string_a_ser_enviada = "Deyvisson=10, Salgado=10"; 
	std::vector<uint8_t> mensagem_a_ser_enviada = {0x01, 0x00, 0x10};

	for(
		const auto& char_a_ser_cripto : string_a_ser_enviada
	){

		mensagem_a_ser_enviada.push_back(char_a_ser_cripto ^ chave);
	}

	printf("Pacote_a_ser_enviado: {");
	for(
		int i = 0;
		    i < mensagem_a_ser_enviada.size();
		  ++i
	){

	    printf("0x%02X", mensagem_a_ser_enviada[i]);

	    if(i < mensagem_a_ser_enviada.size() - 1){
	    	printf(", ");
	    } 
	}
	printf("}");

	return 0;
}