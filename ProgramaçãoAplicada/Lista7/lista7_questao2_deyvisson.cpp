#include <iostream>

class Sensor {
// Alteramos de local para que faça sentido
protected:
    float valor;
public:
    Sensor(float v) {
        valor = v;
    }

    float getTemperatura() {
        return valor;
    }

    // Fazemos a função ser virtual para permitir polimorfismo
    virtual void calibrar(float erro) {
        valor = valor - erro;
    }
};

// Fazemos a herança pública, para manter as classificações
class SensorCompensado : public Sensor {
// Adicionamos atributos de instância
private:
    float coeficiente;
public:
    // Consertamos o construtor
    SensorCompensado(float v, float c) : Sensor(v), coeficiente(c) {}

    void calibrar(float erro) override {
        valor = valor - (erro * coeficiente);
    }
};

int main() {
    Sensor* s = new SensorCompensado(25.0, 1.2);
    s->calibrar(2.0);
    std::cout << "Temp: " << s->getTemperatura() << std::endl;
    return 0;
}
