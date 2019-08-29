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


float funcao(float x, float y, float z) { //  calcula o valor da funcao para entradas x, y e z
	return pow(z, 2) + pow(sqrt(pow(x, 2) + pow(y, 2)) - 3, 2);
}

bool isToroide(float resultado) { //verifica se o resultado da funcao esta dentro do toroide
	return resultado <= 1;
}

int main() {
	int numeros = 100000; //define variaveis auxiliares 
	int contador = 0;
	float total = 0;
	float f2 = 0;
	float f = 0;

	//define intervalos de integracao
	float x1 = 1;
	float x2 = 4;

	float y1 = -3;
	float y2 = 4;

	float z1 = -1;
	float z2 = 1;

	for (; contador <= numeros; contador++) { //calcula n numeros de amostras com entradas x y e x randomicas e verifica se esta no toroide
		float x = random(x1, x2);
		float y = random(y1, y2);
		float z = random(z1, z2);

		float resultado = funcao(x, y, z);

		if (isToroide(resultado)) // se estiver no toroide soma 1 no total
			total += 1;
			f2 += pow(1, 2);
	}

	f2 = f2 / numeros; // calcula media das amostras quadradas
	f = total / numeros; // calcula media de acertos dentro do toroide das amostras
	float V = (x2 - x1) * (y2 - y1) * (z2 - z1); //calcula volume de integracao
	float erro = V * sqrt((f2 - (float)pow(f, 2)) / numeros); // calcula erro estimado
	//mostra na tela taxa de acerto dentro do toroide, resultado da integracao e erro estimado
	cout << "Taxa de acerto no toroide: "<< f << " Resultado: " << V * (total / numeros) << endl;
	cout << "Erro: " << erro << endl;
	cin.get();
}
