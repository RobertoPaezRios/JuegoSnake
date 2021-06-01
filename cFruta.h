#include <iostream>
#include <stdlib.h>

class cFruta {
private:
	int x, y;
	char figura;
public:
	//CONSTRUCTOR//
	cFruta() {
		this->x = 30;
		this->y = 15;
		this->figura = char(207);
	}
	//SETS//
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setFigura(char figura) { this->figura = figura; }
	//GETS//
	int getX() { return x; }
	int getY() { return y; }
	char getFigura() { return figura; }
	//METODOS//
};