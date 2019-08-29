#include <iostream>
#include <random>
#include <chrono>
using namespace std;

float random(float init, float max) { //utiliza o mersenne twister 19937 para gerar numeros pseudo randomicos
	unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed1);
	double random = (double)generator() / generator.max();
	return init + (double)random * (max - init);
}

float funcao(float x) { //calcula valor da funcao para a entrada x
	/*return 4 / (1 + pow(x, 2));*/
	return sqrt(x);
}


int main() {

	int numeros = 10000; // Define as variaveis a serem utilizadas: numeros de amostras, contador parcial de amostras, total da soma das amostras e total quadrados das amostras
	int contador = 0;
	float total = 0;
	float totalquad = 0;

	float a = 0; // Define intervalo de integracao
	float b = 4;

	for (; contador <= numeros; contador++) { // calcula amostras e soma nos acumuladores
		float fx = funcao(random(a, b));
		total += fx;
		totalquad += pow(fx, 2);
	}

	float f = total / numeros; //calcula amostra média
	float f2 = totalquad / numeros; // calcula amostra quadrada média


	float erro = (b - a) * sqrt((f2 - (float)pow(f, 2)) / numeros); //calcula erro estimado
	//mostra na tela valor da integral e erro estimado
	cout << "Resultado: " << (b - a) * f << endl;
	cout << "Erro: " << erro << endl;
	cin.get();
}
