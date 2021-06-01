#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

class cSnake {
private:
	int cola[200][2];
	char tecla;
	int x, y;
	char figura;
	int velocidad;
public:
	//CONSTRUCTOR//
	cSnake() {
		this->x = 10;
		this->y = 12;
		this->tecla = NULL;
		this->figura = 'O';
		this->velocidad = 100;
	}
	//SETS//
	void setCola(int x, int y, int valor) { this->cola[x][y] = valor; }
	void setTecla(char tecla) { this->tecla = tecla; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setFigura(char figura) { this->figura = figura; }
	void setVelocidad(int velocidad) { this->velocidad = velocidad; }
	//GETS//
	int getCola(int x, int y) { return cola[x][y]; }
	char getTecla() { return tecla; }
	int getX() { return x; }
	int getY() { return y; }
	char getFigura() { return figura; }
	int getVelocidad() { return velocidad; }
	//METODOS//
};
