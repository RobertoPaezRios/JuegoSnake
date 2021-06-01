#include "Librerias.h"
//-----------------------------CONSTANTES-----------------------//
#pragma region Constantes
#define ARRIBA 'w'
#define ABAJO 's'
#define DERECHA 'd'
#define IZQUIERDA 'a'
#define SALIR 27
#define VOLVER 'y'
#pragma endregion
//-----------------------------FUNCIONES------------------------//
#pragma region Funciones
void gotoxy(int x, int y);
void cursor(bool mostrar);
void pintarBordes();
void pintarSnake();
void guardarPos();
void borrarSnake();
void movimiento();
void Funcionesfruta();
bool morir();
void guardarPuntos();
void cambiosVelocidad();
void pintarVueltas();
void introduccion();
bool final();
#pragma endregion 
//-----------------------------GLOBAL---------------------------//
#pragma region Global
cSnake* snake = new cSnake();
cFruta* fruta = new cFruta();
int aux = 1;
int cantCola = 5;
int direccion = 3;
int puntos = 0;
int cont = 1;
#pragma endregion
//-----------------------------MAIN-----------------------------//
int main() {
    srand(time(NULL));
    cursor(false);
    introduccion();

    snake->setTecla(NULL);

    while (snake->getTecla() != SALIR && morir() == false) {
        system("cls");
        borrarSnake();
        guardarPos();
        pintarVueltas();
        Funcionesfruta();

        if (_kbhit()) { movimiento(); }
        if (direccion == 1) { snake->setY(snake->getY() - 1); }
        if (direccion == 2) { snake->setY(snake->getY() + 1); }
        if (direccion == 3) { snake->setX(snake->getX() + 1); }
        if (direccion == 4) { snake->setX(snake->getX() - 1); }

        Sleep(snake->getVelocidad());
    }
    Beep(900, 700);
    Beep(1000, 700);
    Beep(800, 1000);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    guardarPuntos();
    system("cls");
    final();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    system("pause>null");
    return 0;
}
//------------------------------GOTOXY---------------------------//
void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
	
}
//------------------------------CURSOR---------------------------//
void cursor(bool mostrar) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 50;
    cci.bVisible = mostrar;

    SetConsoleCursorInfo(hCon, &cci);
}
//----------------------------PINTAR BORDES----------------------//
void pintarBordes() {
    for (int i = 2; i < 78; i++) {
        gotoxy(i, 3);
        cout << char(205);
        gotoxy(i, 23);
        cout << char(205);
    }
    for (int i = 3; i < 23; i++) {
        gotoxy(2, i);
        cout << char(186);
        gotoxy(77, i);
        cout << char(186);
    }
    gotoxy(2, 3);
    cout << char(201);
    gotoxy(2, 23);
    cout << char(200);
    gotoxy(77, 3);
    cout << char(187);
    gotoxy(77, 23);
    cout << char(188);
}
//----------------------------GUARDAR POSICION-------------------//
void guardarPos() {
    snake->setCola(aux, 0, snake->getX());
    snake->setCola(aux, 1, snake->getY());
    aux++;
    if (aux == cantCola) { aux = 1; }
}
//----------------------------PINTAR SNAKE-----------------------//
void pintarSnake() {
    for (int i = 1; i < cantCola; i++) {
        gotoxy(snake->getCola(i, 0), snake->getCola(i, 1));
        cout << snake->getFigura();
    }
}
//----------------------------BORRAR SNAKE-----------------------//
void borrarSnake() {
    gotoxy(snake->getCola(aux, 0), snake->getCola(aux, 1));
    cout << " ";
}
//----------------------------MOVIMIENTO-------------------------//
void movimiento() {
    snake->setTecla(_getch());
    if (snake->getTecla() == ARRIBA && direccion != 2) { direccion = 1; }
    if (snake->getTecla() == ABAJO && direccion != 1) { direccion = 2; }
    if (snake->getTecla() == DERECHA && direccion != 4) { direccion = 3; }
    if (snake->getTecla() == IZQUIERDA && direccion != 3) { direccion = 4; }
}
//----------------------------FRUTA-------------------------------//
void Funcionesfruta() {
    if (snake->getX() == fruta->getX() && snake->getY() == fruta->getY()) {
        fruta->setX(4 + rand() % (73 + 1 - 4));
        fruta->setY(4 + rand() % (19 + 1 - 4));
        cantCola++;
        gotoxy(fruta->getX(), fruta->getY());
        cout << fruta->getFigura();
        puntos += 10;
        cambiosVelocidad();
        Beep(1700, 100);
    }
}
//----------------------------MORIR-------------------------------//
bool morir() {
    if (snake->getY() == 3 || snake->getY() == 23 || snake->getX() == 2 || snake->getX() == 77) {
        return true;
    }
    for (int i = cantCola - 1; i > 0; i--) {
        if (snake->getCola(i, 0) == snake->getX() && snake->getCola(i, 1) == snake->getY())
            return true;
    }
}
//--------------------GUARDAR PUNTOS------------------------------//
void guardarPuntos() {
    ofstream escribir;
    ifstream leer;
    string nombre;
    string ranking;

    while (!leer.eof()) {
        leer >> ranking;
        gotoxy(80, 1);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        cout << "RANKING: " << ranking << endl;
    }

    if (puntos >= 100 && puntos < 210) {
        system("cls");
        cursor(true);
        pintarBordes();
        gotoxy(20, 12);
        cout << "HAS ENTRADO AL RANKING DE LOS MEJORES!!!";
        gotoxy(20, 13);
        cout << "Introduce tu nombre: ";
        cin >> nombre;

        escribir.open("Puntuaciones.txt", ios::app);
        escribir << nombre << puntos << endl;
        escribir.close();

    }
    else if(puntos >= 210) {
        system("cls");
        cursor(true);
        pintarBordes();
        gotoxy(20, 12);
        cout << "HAS ENTRADO AL RANKING DE LOS MEJORES!!!";
        gotoxy(20, 13);
        cout << "Introduce tu nombre: ";
        cin >> nombre;

        escribir.open("WorldRecords.txt", ios::app);
        escribir << nombre << puntos << endl;
        escribir.close();


    }
    else {
        system("cls");
        gotoxy(20, 12);
        pintarBordes();
        cout << "No has conseguido el minimo de puntos para entrar en el ranking :("; 
        exit(0);
    }

}
//---------------------CAMBIOS VELOCIDAD--------------------------//
void cambiosVelocidad() {
    if (puntos == cont * 20 && snake->getVelocidad() > 0) {
        snake->setVelocidad(snake->getVelocidad()- 10);
        cont++;
    }
}
//---------------------PINTAR VUELTA------------------------------//
void pintarVueltas() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    pintarSnake();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    gotoxy(fruta->getX(), fruta->getY());
    cout << fruta->getFigura();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    gotoxy(70, 1);
    cout << "PUNTOS: " << puntos;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    gotoxy(50, 1);
    cout << "VELOCIDAD: " << snake->getVelocidad();
    cambiosVelocidad();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    pintarBordes();
}
//---------------------INTRODUCCION-------------------------------//
void introduccion() {
    gotoxy(40, 12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "SNAKE";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    pintarBordes();
    gotoxy(38, 20);
    cout << "Pulsa cualquier tecla para comenzar...";
    snake->setTecla(_getch());
}
//---------------------FINAL--------------------------------------//
bool final() {
    gotoxy(40, 12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "HAS PERDIDO!, TU PUNTUACION HA SIDO DE : " << puntos;
    gotoxy(40, 13);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "Quieres volver a jugar [y][n] : ";
    snake->setTecla(_getch());
    if (snake->getTecla() == VOLVER) return true;
    else return false;
}