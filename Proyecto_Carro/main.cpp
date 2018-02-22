#include "windows.h"  
#include <iostream>
#include <ctime> 
using namespace std;

//Variables extra
int contador1 = 0;
int contador2 = 0;
int contador3 = 0;

//Vida
int vidas = 4;

//Nivel
int Nivel = 0;

//Velocidad
int velocidad = 100;
int velocidad2 = 100;

//score
int score = 0;

//Color
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//color

//Tamano de la pantalla
int matrix[15][20];

//Tamano de consola
int matrix2[50][50];


//Funcion para moverse a esa coordenada

void moverXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//Funcion para poner un 1 en esa parte del arreglo y asi cuando se llame en el startgame() se pondra como 0 en esa posicion

void ponerP(int x, int y) {

	//Poner punto at x,y  
	if (y < 20 && y >= -0) {
		matrix[x][y] = 1;
	}

}

//Funcion que resetea la pantalla

void resetpantalla() {

	/*Limpia la pantalla poniendo  0's en la matriz, asi cuando vuelva a correr ya no se podran imprimir mas 0 y se pondaran los espacios en 0
	con la condicion else*/

	for (int j = 0; j < 20; j++) {

		for (int i = 1; i < 15; i++) {

			matrix[i][j] = 0;

		}

	}

}

//Funcion que resetea el menu

void resetMenu() {

	//Limpia la pantalla poniendo  0's en la matriz, asi cuando vuelva a correr ya no se podran imprimir mas 0 y se pondaran los espacios en 0 
	//con la condicion else
	
	for (int j = 0; j < 50; j++) {

		for (int i = 1; i < 50; i++) {

			matrix2[i][j] = 0;
			moverXY(i, j);
			cout << "";

		}

	}

}

//Clase enemigo 

class CarroEnemigo_class {

public:
	//Declaracion de constructor que inicializa a las variables x y Y

	CarroEnemigo_class() {
		X = 5;
		Y = -3;
	}

	//Declaracion de varaibles publicas que indican la direccion en X y Y

	int X;
	int Y;

	//Funcion que indica donde va a aparecer el auto

	void poner() {
		if (Y == 20) {

			int numrandom = rand() % 3;

			if (numrandom == 0) {
				X = 2;
			}
			else if (numrandom == 2) {
				X = 5;
			}
			else {
				X = 8;

			}
			if (Nivel == 1) {
				score = score + 20;
			}
			else if (Nivel == 2) {
				score = score + 40;
			}
			else if (Nivel == 3) {
				score = score + 60;
			}

			else if (Nivel == 4) {
				score = score + 80;
			}

			else if (Nivel == 5) {
				score = score + 100;
			}

			else if (Nivel == 6) {
				score = score + 130;
			}
			else if (Nivel == 7) {
				score = score + 170;
			}

			else if (Nivel == 8) {
				score = score + 220;
			}

			else if (Nivel == 9) {
				score = score + 250;
			}

			else if (Nivel == 10) {
				score = score + 280;
			}



			Y = -3;
		}
	}

	//Funcion que Dibuja el auto enemigo

	void figura_enemiga() {
		ponerP(X, Y);
		ponerP(X - 1, Y + 1);
		ponerP(X + 1, Y + 1);
		ponerP(X, Y + 1);
		ponerP(X, Y + 2);
		ponerP(X - 1, Y + 3);
		ponerP(X + 1, Y + 3);
		ponerP(X, Y + 3);
	}



	void quitar_figura_enemiga() {
		moverXY(X, Y);
		cout << " ";
		moverXY(X - 1, Y + 1);
		cout << " ";
		moverXY(X + 1, Y + 1);
		cout << " ";
		moverXY(X, Y + 1);
		cout << " ";
		moverXY(X, Y + 2);
		cout << " ";
		moverXY(X - 1, Y + 3);
		cout << " ";
		moverXY(X + 1, Y + 3);
		cout << " ";
		moverXY(X, Y + 3);
		cout << " ";
	}



	//Mueve el auto en esa direccion
	void mover() {
		Y = Y + 1;


	}

};


//Clase carro

class car {

public:
	//Declaracion de varaibles publicas que indican la direccion en X y Y

	int X;
	int Y;

	//Declaracion del construcor

	car() {
		//Inicializa las variables de posicion X y Y

		X = 2;
		Y = 16;
	}

	//Funcion que crea el carro 

	void figura_carro() {

		//Llama a la funcion ponerP para que en las coordenadas X y Y ponga un "0"

		ponerP(X, Y);
		ponerP(X - 1, Y + 1);
		ponerP(X + 1, Y + 1);
		ponerP(X, Y + 1);
		ponerP(X, Y + 2);
		ponerP(X - 1, Y + 3);
		ponerP(X + 1, Y + 3);
		ponerP(X, Y + 3);

		//Todas las veces que llama a la funcion agrega un "0", lo que hace que se forme un carro
	}

	//Funcion que mueve los "0" osea el auto, al presionar las teclas de direccion

	//Izquierda
	void moveLeft() {

		if (X == 2 || X == 5)
			X = 2;
		if (X == 8)
			X = 5;
		contador1 = 0;

	}

	//Derecha
	void moveRight() {

		if (contador1 == 1) {
			X = 8;
		}
		else {
			X = 5;
			contador1 = 1;

		}
	}

	//Arriba
	void moveUp() {

		velocidad = 10;

	}
	void stopmoveUp() {
		velocidad = velocidad2;
	}

	void obtenerMov() {
		bool verify = false;

		//Si presiona la tecla izquierda entra
		if (GetAsyncKeyState(VK_LEFT) & (0x8000 != 0)) {
			moveLeft();

		}
		//Si presiona la tecla derecha entra
		else if (GetAsyncKeyState(VK_RIGHT) & (0x8000 != 1)) {
			moveRight();

		}
		//Si presiona la tecla arriba entra
		else if (GetAsyncKeyState(VK_UP) & (0x8000 != 1)) {
			moveUp();


		}

		else if (GetAsyncKeyState(VK_DOWN) & (0x8000 != 1)) {
			stopmoveUp();

		}
		else if (GetAsyncKeyState(VK_ESCAPE)) {
			system("pause");

		}



	}


	//Verifica si choco o no

	bool choque(CarroEnemigo_class *EC, bool *juego_corriendo) {

		//Si el auto enemigo esta en la posicion X la igual que el carro y la posicion en Y es mayor a 13, osea el limite de la punta del auto bueno, se cumple
		if (EC->X == X && EC->Y > 13 && vidas == 0) {
			*juego_corriendo = false;
		}
		else if (EC->X == X && EC->Y > 13 && vidas > 0) {
			EC->Y = 0;
			vidas--;
			Sleep(50);
			return true;
		}
		else {
			return false;
		}
	}


};


//Obtener el movimiento del auto

//Se le manda de parametro una variable apuntador de tipo carro

//Funcion para darle comienzo al juego
void startGame() {
	int segundos = 0;
	int t = 1;
	clock_t time = clock();

	//Instrucciones del juego

	cout << "Instrucciones" << endl;
	cout << "1)Esquiva los autos" << endl;
	cout << "2)Puedes moverte hacia arriba o hacia abajo, usando las teclas de direccion" << endl;
	cout << "3)Cada 10 niveles sube la velocidad!!!" << endl;
	cout << "4)Tienes (3) oportunidades para chocar sin ser penalizado a la (4) pierdes " << endl;
	cout << "5)Puedes aumentar la velocidad con la tecla de direccion arriba y bajar la velocidad con la tecla de direccion abajo  " << endl;
	cout << "Buena Suerte" << endl;

	//Cambio el color
	SetConsoleTextAttribute(hConsole, 13);

	cout << "Cargando..." << endl;

	//Cambio el color
	SetConsoleTextAttribute(hConsole, 15);

	//El tiempo de espera para que el juego comience
	Sleep(8000);

	//Limpia la pantalla
	system("CLS");

	//Objetos de tipo carro y carro enemigo
	car carrito = car();
	CarroEnemigo_class miCarroEne = CarroEnemigo_class();

	// Loop del juego
	bool juego_corriendo = true;
	
	//Aqui esta el corazon del juego

	while (juego_corriendo) {



		//Tiempo del juego

		time = clock() - time;
		segundos = time / (int)CLOCKS_PER_SEC;
		if (segundos / 10 == 1 * t) {
			++Nivel;
			++t;
		}
		if (Nivel == 10) {
			Nivel = 0;
			velocidad = velocidad2 - 10;
		}


		//Obtiene el movimiento del carro
		carrito.obtenerMov();

		//Limpia la pantalla donde esta el carro y al pista
		resetpantalla();

		//Muestra las vidas, el puntaje y el nivel

		moverXY(20, 7);
		cout << "Vidas: " << vidas << endl;
		moverXY(20, 8);
		cout << "Nivel: " << Nivel << endl;
		moverXY(20, 9);
		cout << "Velocidad: " << velocidad << endl;
		moverXY(20, 10);
		cout << "Puntuacion: " << score << endl;
		moverXY(20, 11);
		cout << "Presiona " << " ESC " << " para pausar el jeugo " << endl;

		//Funciones para que salgan los autos enemgios
		miCarroEne.poner();
		miCarroEne.figura_enemiga();
		miCarroEne.mover();


		//Funcion para que salga el auto bueno
		carrito.figura_carro();

		//Funcion que verifica si choco
		bool choco = carrito.choque(&miCarroEne, &juego_corriendo);

		//Spawnea la carretera
		for (int j = 0; j < 20; j++)
		{
			for (int i = 0; i < 16; i++)
			{
				if (i == 0 || i == 10) {
					moverXY(i, j);
					cout << "|";
				}
				//Spawnea los "0" de los autos
				if (matrix[i][j] == 1) {
					moverXY(i, j);//Pone en esa posicion un 0
					cout << "O";
				}
				else {
					cout << " ";
				}
			}
		}

		Sleep(velocidad);
	}

	//termina

	cout << "Has perdido" << endl;
	Sleep(500);


}


int main()
{
	int contadordedatos = 0;
	int datar[10];
	do {

		//Cambio el color
		SetConsoleTextAttribute(hConsole, 15);
		cout << "DEATH RACE";

		//Cambio el color
		SetConsoleTextAttribute(hConsole, 13);
		cout << " BLOOD DRAGON EDITION!" << endl;

		//Cambio el color
		SetConsoleTextAttribute(hConsole, 15);

		//Variable que guarda la opcion del usuario
		int opcion = 0;
		cout << "" << endl;
		cout << "                        MENU                             " << endl;
		cout << " 1) Jugar!!!\n 2) Mostrar estadisticas de Juego\n 3) Salir\n";

		//Cambio el color
		SetConsoleTextAttribute(hConsole, 11);

		cout << " " << endl;
		cout << "Hecho por : Michael Sanchez";

		//Cambio el color
		SetConsoleTextAttribute(hConsole, 15);
		cout << " " << endl;
		//La opcion que escoge el usuario
		cout << "Escribe el numero aqui: ";
		cin >> opcion;

		//Switch, cambia dependiendo de lo que el usuario escoga
		switch (opcion) {

		case 1://Para emepzar el juego
			system("CLS");
			cout << " " << endl;
			startGame();
			datar[contadordedatos] = score;
			contadordedatos++;

			contador1 = 0;
			contador2 = 0;
			contador3 = 0;


			//Vida
			vidas = 4;

			//Nivel
			Nivel = 0;

			//Velocidad
			velocidad = 100;
			velocidad2 = 100;
			//score
			score = 0;

			//time
			system("CLS");
			break;

		case 2://Para ver el puntaje
			cout << "Score" << endl;
			if (datar[0] >= 0)
				cout << "Partida 1 " << ".........." << datar[0] << ".........." << " Puntos " << endl;
			if (datar[1] >= 0)
				cout << "Partida 2 " << ".........." << datar[1] << ".........." << " Puntos " << endl;
			if (datar[2] >= 0)
				cout << "Partida 3 " << ".........." << datar[2] << ".........." << " Puntos " << endl;
			if (datar[3] >= 0)
				cout << "Partida 4 " << ".........." << datar[3] << ".........." << " Puntos " << endl;
			if (datar[4] >= 0)
				cout << "Partida 5 " << ".........." << datar[4] << ".........." << " Puntos " << endl;
			if (datar[5] >= 0)
				cout << "Partida 6 " << ".........." << datar[5] << ".........." << " Puntos " << endl;
			if (datar[6] >= 0)
				cout << "Partida 7 " << ".........." << datar[6] << ".........." << " Puntos " << endl;
			if (datar[7] >= 0)
				cout << "Partida 8 " << ".........." << datar[7] << ".........." << " Puntos " << endl;
			if (datar[8] >= 0)
				cout << "Partida 9 " << ".........." << datar[8] << ".........." << " Puntos " << endl;
			if (datar[9] >= 0)
				cout << "Partida 10 " << ".........." << datar[9] << ".........." << " Puntos " << endl;

			break;

		case 3://Para salirse
			return 0;
			break;

		}


	} while (true);
}









