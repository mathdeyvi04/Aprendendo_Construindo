// ======================================================================
// Demonstração simples no main (chamadas diretas)
//    - Lê número de vagas.
//    - Tenta inserir Moto/Carro/Caminhao diretamente.
// ======================================================================
int main() {
    int N;
    std::cout << "Informe o numero de vagas do estacionamento: ";
    if (!(std::cin >> N) || N <= 0) {
        std::cout << "Entrada invalida.\n";
        return 1;
    }

    Estacionamento est(N);

    // Estado inicial
    est.listar();

    // Entradas 
    Veiculo* v1 = new Carro("ABC-1234", "Prata");
    if (!est.entrar(v1)) { std::cout << "Sem espaco para " << v1->placa << "\n";}

    Veiculo* v2 = new Moto("MOT-0001", "Vermelha");
    if (!est.entrar(v2)) { std::cout << "Sem espaco para " << v2->placa << "\n";}

    Veiculo* v3 = new Caminhao("TRK-9A77", "Branco");
    if (!est.entrar(v3)) { std::cout << "Sem espaco para " << v3->placa << "\n";}

    est.listar();

    // Saídas
    //std::cout << (est.sair("ABC-1234") ? "Saiu ABC-1234\n" : "Nao achou ABC-1234\n");
    //std::cout << (est.sair("ZZZ-9999") ? "Saiu ZZZ-9999\n" : "Nao achou ZZZ-9999\n");

    est.listar();

    delete v1;
    delete v2;
    delete v3;

    return 0;
}