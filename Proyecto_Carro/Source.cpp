//#include "windows.h"  
//#include <iostream>
//#include <thread>  
//
//using namespace std;
//
//
////Variables extra
//int contador1 = 0;
//int contador2 = 0;
//
////Vida
//int ceros = 0;
//int vidas = 4;
//
////Color
//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//color
//
////Tamano de la pantalla
//int matrix[15][20];
//
////Tamano de consola
//int matrix2[50][50];
//
//
////Funcion para moverse a esa coordenada
//void moverXY(int x, int y) {
//	COORD coord;
//	coord.X = x;
//	coord.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//
//
//
////Funcion para poner un 1 en esa parte del arreglo y asi cuando se llame en el startgame() se pondra como 0 en esa posicion
//void ponerP(int x, int y) {
//
//	//Poner punto at x,y  
//	if (y < 20 && y >= -0) {
//		matrix[x][y] = 1;
//	}
//
//}
//
////Funcion que resetea la pantalla
//
//void resetpantalla() {
//
///*Limpia la pantalla poniendo  0's en la matriz, asi cuando vuelva a correr ya no se podran imprimir mas 0 y se pondaran los espacios en 0 
//con la condicion else*/
//
//	for (int j = 0; j < 20; j++) {
//
//		for (int i = 1; i < 15; i++) {
//
//			matrix[i][j] = 0;
//
//		}
//
//	}
//
//}
//
////Funcion que resetea el menu
//
//void resetMenu() {
//	//Limpia la pantalla poniendo  0's en la matriz, asi cuando vuelva a correr ya no se podran imprimir mas 0 y se pondaran los espacios en 0 
//	//con la condicion else
//	for (int j = 0; j < 50; j++) {
//
//		for (int i = 1; i < 50; i++) {
//
//			matrix2[i][j] = 0;
//			moverXY(i, j);
//			cout << "";
//
//		}
//
//	}
//
//}
//
////Clase enemigo 
//
//class CarroEnemigo_class {
//
//public:
//	//Declaracion de constructor que inicializa a las variables x y Y
//
//	CarroEnemigo_class() {
//		X = 5;
//		Y = -3;
//	}
//
//	//Declaracion de varaibles publicas que indican la direccion en X y Y
//
//	int X;
//	int Y;
//
//	//Funcion que indica donde va a aparecer el auto
//
//	void appear() {
//		if (Y == 20) {
//			int randomNo = rand() % 3;
//			if (randomNo == 0) {
//				X = 2;
//			}
//			else if (randomNo == 2) {
//				X = 5;
//			}
//			else {
//				X = 8;
//			}
//			Y = -3;
//		}
//	}
//
//	//Funcion que Dibuja el auto enemigo
//
//	void figura_enemiga() {
//		ponerP(X, Y);
//		ponerP(X - 1, Y + 1);
//		ponerP(X + 1, Y + 1);
//		ponerP(X, Y + 1);
//		ponerP(X, Y + 2);
//		ponerP(X - 1, Y + 3);
//		ponerP(X + 1, Y + 3);
//		ponerP(X, Y + 3);
//	}
//
//	//Mueve el auto en esa direccion
//	void move() {
//		Y++;
//	}
//
//};
//
//
////Clase carro
//
//class car {
//
//public:
//	//Declaracion de varaibles publicas que indican la direccion en X y Y
//
//	int X;
//	int Y;
//
//	//Declaracion del construcor
//
//	car() {
//		//Inicializa las variables de posicion X y Y
//		X = 2;
//		Y = 16;
//	}
//
//	//Funcion que crea el carro 
//
//	void figura_carro() {
//		//Llama a la funcion ponerP para que en las coordenadas X y Y ponga un "0"
//		ponerP(X, Y);
//		ponerP(X - 1, Y + 1);
//		ponerP(X + 1, Y + 1);
//		ponerP(X, Y + 1);
//		ponerP(X, Y + 2);
//		ponerP(X - 1, Y + 3);
//		ponerP(X + 1, Y + 3);
//		ponerP(X, Y + 3);
//		//Todas las veces que llama a la funcion agrega un "0", lo que hace que se forme un carro
//	}
//
//	//Funcion que mueve los "0" osea el auto, al presionar las teclas de direccion
//
//	//Izquierda
//	void moveLeft() {
//		if (X == 2 || X == 5)
//			X = 2;
//		if (X == 8)
//			X = 5;
//		contador1 = 0;
//
//	}
//
//	//Derecha
//	void moveRight() {
//		if (contador1 == 1) {
//			X = 8;
//		}
//		else {
//			X = 5;
//			contador1 = 1;
//
//		}
//	}
//
//	//Arriba
//	void moveUp() {
//		if (contador2 == 0) {
//			Y = 11;
//			contador2 = 1;
//
//		}
//		else if (contador2 == 1) {
//			Y = 6;
//			contador2 = 2;
//		}
//		else if (contador2 == 2) {
//			Y = 1;
//			contador2 = 3;
//		}
//	}
//
//	//Abajo
//	void moveDown() {
//		if (Y == 11 || Y == 16)
//			Y = 16;
//		if (Y == 6) {
//			Y = 11;
//			contador2 = 0;
//		}
//		if (Y == 1) {
//			Y = 6;
//			contador2 = 2;
//		}
//	}
//
//	//Verifica si choco o no
//
//	void choque(CarroEnemigo_class *EC, bool *juego_corriendo) {
//
//		//Si el auto enemigo esta en la posicion X la igual que el carro y la posicion en Y es mayor a 13, osea el limite de la punta del auto bueno, se cumple
//		if (EC->X == X && EC->Y > 13 && vidas == 0) {
//			*juego_corriendo = false;
//		}
//		else if (EC->X == X && EC->Y > 13 && vidas > 0) {
//			ceros++; // La cantidad de ceros que tiene el auto, ya que lo atraviesa
//
//		}
//	}
//
//
//};
//
//
////Obtener el movimiento del auto
//
////Se le manda de parametro una variable apuntador de tipo carro
//void obtenerMov(car *c) {
//
//	while (true) {
//
//
//			//Si presiona la tecla izquierda entra
//			if (GetAsyncKeyState(VK_LEFT) & (0x8000 != 0)) {
//				c->moveLeft();
//
//			}
//			//Si presiona la tecla derecha entra
//			else if (GetAsyncKeyState(VK_RIGHT) & (0x8000 != 1)) {
//				c->moveRight();
//
//			}
//			//Si presiona la tecla arriba entra
//			else if (GetAsyncKeyState(VK_UP) & (0x8000 != 1)) {
//				c->moveUp();
//
//			}
//			//Si presiona la tecla abajo entra
//			else if (GetAsyncKeyState(VK_DOWN) & (0x8000 != 1)) {
//				c->moveDown();
//
//			}
//
//		
//	}
//}
//
////Funcion para darle comienzo al juego
//void startGame() {
//
//	//Instrucciones del juego
//	cout << "Instrucciones" << endl;
//	cout << "1)Esquiva los autos" << endl;
//	cout << "2)Puedes moverte hacia arriba, abajo, a la izquierda o a la derecha usando las teclas de direccion" << endl;
//	cout << "3)Cada 20 segundos sube la velocidad!!!" << endl;
//	cout << "4)Tienes (3) oportunidades para chocar sin ser penalizado a la (4) pierdes " << endl;
//	cout << "Buena Suerte" << endl;
//
//	//Cambio el color
//	SetConsoleTextAttribute(hConsole, 13);
//
//	cout << "Cargando..." << endl;
//
//	//Cambio el color
//	SetConsoleTextAttribute(hConsole, 15);
//
//	//El tiempo de espera para que el jeugo comience
//	Sleep(11);
//
//	//Limpia la pantalla
//	system("CLS");
//
//	//Objetos de tipo carro y carro enemigo
//	car carrito = car();
//	CarroEnemigo_class miCarroEne = CarroEnemigo_class();
//
//	// Loop del juego
//	bool juego_corriendo = true;
//
//	// thread (movimiento detectar )  
//	thread Thread(obtenerMov, &carrito);
//	while (juego_corriendo) {
//
//	//Limpia la pantalla donde esta el carro y al pista
//	resetpantalla();
//
//	//Muestra las vidas, el puntaje y el nivel
//
//	//se mueve en esa direccion para imprimir luego
//	moverXY(20, 20);
//
//	cout << "Vidas: " << vidas;
//	cout << "Ceros: " << ceros;
//
//	//Los ceros del auto enemigo que tocan al carro bueno
//	if (ceros == 7)
//	vidas = 3;
//	if (ceros == 14)
//	vidas = 2;
//	if (ceros == 21)
//	vidas = 1;
//	if (ceros > 21)
//	vidas = 0;
//
//
//		//Funciones para que salgan los autos enemgios
//		miCarroEne.appear();
//		miCarroEne.figura_enemiga();
//		miCarroEne.move();
//
//		//Funcion para que salga el auto bueno
//		carrito.figura_carro();
//
//		//Funcion que verifica si choco
//		carrito.choque(&miCarroEne, &juego_corriendo);
//
//		//Spawnea la carretera
//		for (int j = 0; j < 20; j++)
//		{
//			for (int i = 0; i < 16; i++)
//			{
//				if (i == 0 || i == 10) {
//					moverXY(i, j);
//					cout << "|";
//				}
//				//Spawnea los "0" de los autos
//				if (matrix[i][j] == 1) {
//					moverXY(i, j);//Pone en esa posicion un 0
//					cout << "0";
//				}
//				else {
//					cout << " ";
//				}
//			}
//		}
//		Sleep(50);
//	}
//
//	//The game ended
//
//	////Show the Game Over
//	//Sleep(1000);
//	//system("cls");
//	//moverXY(5, 4);
//	//cout << "GAME OVER!!!";
//	//moverXY(5, 5);
//	//cout << "By:Mubarak Hason";
//	//moverXY(5, 6);
//	//cout << "HasonHex";
//	//moverXY(0, 0);
//	//Sleep(10000);
//
//	// Kills the second thread
//	Thread.detach();
//}
//
//
//int main()
//{
//
//	//Cambio el color
//	SetConsoleTextAttribute(hConsole, 15);
//	cout << "DEATH RACE";
//
//	//Cambio el color
//	SetConsoleTextAttribute(hConsole, 13);
//	cout << " BLOOD DRAGON EDITION!" << endl;
//
//	//Cambio el color
//	SetConsoleTextAttribute(hConsole, 15);
//
//	//Variable que guarda la opcion del usuario
//	int opcion = 0;
//	cout << "" << endl;
//	cout << "                        MENU                             " << endl;
//	cout << " 1) Jugar!!!\n 2) Mostrar estadisticas de Juego\n 3) Salir\n";
//
//	//Cambio el color
//	SetConsoleTextAttribute(hConsole, 11);
//
//	cout << "" << endl;
//	cout << "Hecho por : Michael Sanchez";
//
//	//Cambio el color
//	SetConsoleTextAttribute(hConsole, 15);
//
//	//La opcion que escoge el usuario
//	cin >> opcion;
//
//	//Switch, cambia dependiendo de lo que el usuario escoga
//	switch (opcion) {
//
//	case 1://Para emepzar el juego
//		system("CLS");
//		startGame();
//
//		break;
//
//	case 2://Para ver el puntaje
//
//		break;
//
//	case 3://Para salirse
//		return 0;
//		break;
//	}
//
//	return 0;
//
//}
//
//
//
//
//
//
//
//
//
