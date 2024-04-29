#include "pch.h"
#include "iostream"
#include "cstdlib"
#include "ctime"
#include "conio.h"

using namespace System;
using namespace std;

const int hand_size = 8; //this is a constant that determines the size of a hand into OUITE

void ventana() {
	Console::SetWindowSize(80, 40);
}

void cursor(int x, int y) {
	Console::SetCursorPosition(x, y);
}

void presentacion() {
	int x = 20;
	int y = 8;
	cursor(x, y);
	cout << " ..|''||   '||'  '|' '||' |''||''| '||''''|" << endl;
	cursor(x, y + 1);
	cout << ".|'    ||   ||    |   ||     ||     ||  ." << endl;
	cursor(x, y + 2);
	cout << "||      ||  ||    |   ||     ||     ||''|" << endl;
	cursor(x, y + 3);
	cout << "'|.     ||  ||    |   ||     ||     ||" << endl;
	cursor(x, y + 4);
	cout << "''|...|'    '|..'    .||.   .||.   .||.....|" << endl;
	cursor(x + 3, y + 5);
	cout << "Presione I para iniciar" << endl;

	cursor(18, y + 1); cout << "*" << endl;
	cursor(18, y + 2); cout << "I" << endl;
	cursor(18, y + 3); cout << "*" << endl;


	cursor(65, y + 1); cout << "*" << endl;
	cursor(65, y + 2); cout << "I" << endl;
	cursor(65, y + 3); cout << "*" << endl;

	cursor(0, 1); for (int i = 0; i < 79; i++) cout << "=";
	cursor(0, 22); for (int i = 0; i < 79; i++) cout << "=";

	char tecla;

	int transicion = 0;

	while (transicion < 1) {
		if (kbhit()) {
			tecla = getch();
			if (tecla == 'i' || tecla == 'I') {
				system("cls");
				transicion++;
			}
		}

	}

}



/*
  The function edsondealer() represents the dealer in a game of cards
  which generate 8 values, this values are cards, the values can be
  from 1 to 13 and those are generate it randomly
 */



void edsondealer(int hand[]) {
	for (int i = 0; i < hand_size; ++i) {
		hand[i] = rand() % 13 + 1;
	}
}

/*
  The function deleteCard() is used for delete a card from the playerHand[]
  each card is represented by a int value into the array, when this function is called
  this turns a determined int value of this array to 0, which means that the card
  does not exist in the player hand anymore.
*/

void deleteCard(int playerHand[], int value) {
	for (int i = 0; i < hand_size; i++) {
		if (playerHand[i] == value) {
			playerHand[i] = 0;
			break;
		}
	}
}


//limpiar la pantalla
void clearConsole() {
#ifdef _WIN32 
	system("cls");
#endif
}

int getRandomCard() {
	return(rand() % 13) + 1;
}

//Impresion de cartas de valores de 1 digito
void cardNum(int x, int y, int card) {

	Console::SetCursorPosition(x, y); cout << "*"; for (int i = 1; i <= 7; i++) cout << (char)196; cout << (char)191;
	Console::SetCursorPosition(x, y + 1); cout << (char)179; for (int i = 1; i <= 7; i++) cout << " "; cout << (char)179;
	Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 7; i++) cout << " "; cout << (char)179;
	Console::SetCursorPosition(x, y + 3); cout << (char)197; for (int i = 1; i <= 3; i++) cout << " "; cout << card; for (int i = 1; i <= 3; i++) cout << " "; cout << (char)197;
	Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 7; i++) cout << " "; cout << (char)179;
	Console::SetCursorPosition(x, y + 5); cout << (char)179; for (int i = 1; i <= 7; i++) cout << " "; cout << (char)179;
	Console::SetCursorPosition(x, y + 6); cout << (char)192; for (int i = 1; i <= 7; i++) cout << (char)196; cout << "*";

}

//Impresion de cartas en caso de valores de 2 digitos
void cardLetra(int x, int y, char letra) {

	Console::SetCursorPosition(x, y); cout << "*"; for (int i = 1; i <= 7; i++) cout << (char)196; cout << (char)191;
	Console::SetCursorPosition(x, y + 1); cout << (char)179; for (int i = 1; i <= 7; i++) cout << " "; cout << (char)179;
	Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 7; i++) cout << " "; cout << (char)179;
	Console::SetCursorPosition(x, y + 3); cout << (char)197; for (int i = 1; i <= 3; i++) cout << " "; cout << letra; for (int i = 1; i <= 3; i++) cout << " "; cout << (char)197;
	Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 7; i++) cout << " "; cout << (char)179;
	Console::SetCursorPosition(x, y + 5); cout << (char)179; for (int i = 1; i <= 7; i++) cout << " "; cout << (char)179;
	Console::SetCursorPosition(x, y + 6); cout << (char)192; for (int i = 1; i <= 7; i++) cout << (char)196; cout << "*";
}

//Eliminacion de cartas
void voidCard(int x, int y) {
	Console::SetCursorPosition(x, y); cout << " "; for (int i = 1; i <= 7; i++) cout << " "; cout << " ";
	Console::SetCursorPosition(x, y + 1); cout << " "; for (int i = 1; i <= 7; i++) cout << " "; cout << " ";
	Console::SetCursorPosition(x, y + 2); cout << " "; for (int i = 1; i <= 7; i++) cout << " "; cout << " ";
	Console::SetCursorPosition(x, y + 3); cout << " "; for (int i = 1; i <= 3; i++) cout << " "; cout << " "; for (int i = 1; i <= 3; i++) cout << " "; cout << " ";
	Console::SetCursorPosition(x, y + 4); cout << " "; for (int i = 1; i <= 7; i++) cout << " "; cout << " ";
	Console::SetCursorPosition(x, y + 5); cout << " "; for (int i = 1; i <= 7; i++) cout << " "; cout << " ";
	Console::SetCursorPosition(x, y + 6); cout << " "; for (int i = 1; i <= 7; i++) cout << " "; cout << " ";
}


void displayHand(int playerHand[], string playerName) {
	int x = 0;
	int y = 5;
	for (int i = 0; i < hand_size; i++) {
		Console::SetCursorPosition(x, 5);
		if (playerHand[i] == 13) {
			cardLetra(x, y, 'K');
		}
		else if (playerHand[i] == 12) {
			cardLetra(x, y, 'Q');
		}
		else if (playerHand[i] == 11) {
			cardLetra(x, y, 'J');
		}
		else if (playerHand[i] == 10) {
			cardLetra(x, y, 'X');
		}
		else if (playerHand[i] == 0) {
			voidCard(x, y);
		}
		else {
			cardNum(x, y, playerHand[i]);
		}
		x = x + 9;
		_sleep(50);
	}
}

void displayHand2(int playerHand[], string playerName) {
	int x = 0;
	int y = 15;
	for (int i = 0; i < hand_size; i++) {
		Console::SetCursorPosition(x, 5);
		if (playerHand[i] == 13) {
			cardLetra(x, y, 'K');
		}
		else if (playerHand[i] == 12) {
			cardLetra(x, y, 'Q');
		}
		else if (playerHand[i] == 11) {
			cardLetra(x, y, 'J');
		}
		else if (playerHand[i] == 10) {
			cardLetra(x, y, 'X');
		}
		else if (playerHand[i] == 0) {
			voidCard(x, y);
		}
		else {
			cardNum(x, y, playerHand[i]);
		}
		x = x + 9;
		_sleep(50);
	}
}



//Carta aleatoria
void CartaRandom(int random) {
	int y = 10;
	int x = 75;
	if (random == 13) {
		cardLetra(x, y, 'K');
	}
	else if (random == 12) {
		cardLetra(x, y, 'Q');
	}
	else if (random == 11) {
		cardLetra(x, y, 'J');
	}
	else if (random == 10) {
		cardLetra(x, y, 'X');
	}
	else {
		cardNum(x, y, random);
	}

}



void scoreboard(int x, int y, string player1Name, string player2Name, int partida_actual, int num_partidas, int point1, int point2) {
	char key;

	Console::SetCursorPosition(x, y); cout << (char)201; for (int i = 1; i <= 30; i++) cout << (char)205; cout << (char)187;
	Console::SetCursorPosition(x, y + 1); cout << (char)206; for (int i = 1; i <= 10; i++) cout << (char)205; cout << (char)206; cout << "SCOREBOARD"; cout << (char)206; for (int i = 1; i <= 8; i++) cout << (char)205; cout << (char)206;
	Console::SetCursorPosition(x, y + 2); cout << (char)204; for (int i = 1; i <= 15; i++) cout << (char)205; cout << "P1"; for (int i = 1; i <= 13; i++) cout << (char)205; cout << (char)185;
	Console::SetCursorPosition(x, y + 3); cout << (char)186; for (int i = 1; i <= 1; i++) cout << "Partidas Ganadas:"; cout << point1; for (int i = 1; i <= 12; i++) cout << " "; cout << (char)186;
	Console::SetCursorPosition(x, y + 4); cout << (char)204; for (int i = 1; i <= 15; i++) cout << (char)205; cout << "P2"; for (int i = 1; i <= 13; i++) cout << (char)205; cout << (char)185;
	Console::SetCursorPosition(x, y + 5); cout << (char)186; for (int i = 1; i <= 1; i++) cout << "Partidas Ganadas:"; cout << point2; for (int i = 1; i <= 12; i++) cout << " "; cout << (char)186;
	Console::SetCursorPosition(x, y + 6); cout << (char)204; for (int i = 1; i <= 30; i++) cout << (char)205; cout << (char)185;
	Console::SetCursorPosition(x, y + 7); cout << (char)186; for (int i = 1; i <= 1; i++) cout << "      PARTIDAS JUGADAS:"; cout << partida_actual; for (int i = 1; i <= 6; i++) cout << " "; cout << (char)186;
	Console::SetCursorPosition(x, y + 8); cout << (char)200; for (int i = 1; i <= 30; i++) cout << (char)205; cout << (char)188;

	cursor(20, 20);
	cout << "pulse C para continuar_";

	int transicion = 0;
	while (transicion < 1) {
		if (kbhit()) {
			key = getch();
			if (key == 'C' || key == 'c') {
				clearConsole();
				transicion++;
			}
			
		}
	}

}

int getScore(int playerHand[]) {
	int points = 0;
	for (int i = 0; i < hand_size; ++i) {
		if (playerHand[i] != 0) {
			points++;
		}
	}
	return points;
}

void ganador(int score1, int score2) {
	int x = 30;
	int y = 10;
	if (score1 > score2) {
		cursor(x, y); cout << "+"; for (int i = 0; i < 30; i++) cout << "="; cout << "+";
		cursor(x, y + 1); cout << "|"; for (int i = 0; i < 30; i++) cout << " "; cout << "|";
		cursor(x, y + 2); cout << "|"; for (int i = 0; i < 4; i++) cout << ""; cout << "        Gana jugador 1!"; for (int i = 0; i < 7; i++) cout << " "; cout << "|";
		cursor(x, y + 3); cout << "|"; for (int i = 0; i < 30; i++) cout << " "; cout << "|";;
		cursor(x, y + 4); cout << "+"; for (int i = 0; i < 30; i++) cout << "="; cout << "+";
	}
	else if (score2 > score1) {
		cursor(x, y); cout << "+"; for (int i = 0; i < 30; i++) cout << "="; cout << "+";
		cursor(x, y + 1); cout << "|"; for (int i = 0; i < 30; i++) cout << " "; cout << "|";
		cursor(x, y + 2); cout << "|"; for (int i = 0; i < 4; i++) cout << ""; cout << "        Gana jugador 2!"; for (int i = 0; i < 7; i++) cout << " "; cout << "|";
		cursor(x, y + 3); cout << "|"; for (int i = 0; i < 30; i++) cout << " "; cout << "|";;
		cursor(x, y + 4); cout << "+"; for (int i = 0; i < 30; i++) cout << "="; cout << "+";
	}
	else {
		cursor(x, y); cout << "+"; for (int i = 0; i < 30; i++) cout << "="; cout << "+";
		cursor(x, y + 1); cout << "|"; for (int i = 0; i < 30; i++) cout << " "; cout << "|";
		cursor(x, y + 2); cout << "|"; for (int i = 0; i < 4; i++) cout << ""; cout << "        Empate..."; for (int i = 0; i < 13; i++) cout << " "; cout << "|";
		cursor(x, y + 3); cout << "|"; for (int i = 0; i < 30; i++) cout << " "; cout << "|";;
		cursor(x, y + 4); cout << "+"; for (int i = 0; i < 30; i++) cout << "="; cout << "+";
	}
}

int main() {
	srand(time(nullptr));
	int player1Hand[hand_size];
	int player2Hand[hand_size];

	int numero_de_partidas; // Number of games to play
	int partida_actual = 0;

	int score1 = 0;
	int score2 = 0;

	presentacion();

	string player1Name;
	string player2Name;

	do {
		cursor(25, 8);
		cout << "Ingrese el numero de partidas a jugar: ";
		cin >> numero_de_partidas;

	} while (numero_de_partidas < 7 || numero_de_partidas > 10);
	clearConsole();
	cursor(25, 8);
	cout << "Ingrese el nombre del jugador 1: ";
	cin >> player1Name;
	clearConsole();
	cursor(25, 8);
	clearConsole();
	cursor(25, 8);
	cout << "Ingrese el nombre del jugador 2: ";
	cin >> player2Name;

	int counter = 0;
	int cardtodelete1;
	int cardtodelete2;

	clearConsole();

	int partidas = 0;

	//inicio de juego
	while (partidas < numero_de_partidas) {

		edsondealer(player1Hand);
		edsondealer(player2Hand);

		cursor(0, 4);
		cout << "|===============================" << player1Name << "==============================|" << endl;
		cursor(0, 14);
		cout << "|===============================" << player2Name << "==============================|" << endl;
		cursor(74, 9);
		cout << "|=dealer=|";


		do {
			int randomcard;
			randomcard = getRandomCard();
			int cardtodelete1;
			int cardtodelete2;

			cursor(0, 0);
			CartaRandom(randomcard);
			displayHand(player1Hand, player1Name);
			displayHand2(player2Hand, player2Name);
			cursor(0, 22);


			cout << player1Name << " elija la carta a eliminar: " << endl;
			int transicion = 0;
			char tecla;


			//input directo p1
			while (transicion < 1) {
				if (_kbhit()) {
					tecla = getch();
					if (tecla == '1') {
						cardtodelete1 = 1;
						transicion++;
					}
					else if (tecla == '2') {
						cardtodelete1 = 2;
						transicion++;
					}
					else if (tecla == '3') {
						cardtodelete1 = 3;
						transicion++;
					}
					else if (tecla == '4') {
						cardtodelete1 = 4;
						transicion++;
					}
					else if (tecla == '5') {
						cardtodelete1 = 5;
						transicion++;
					}
					else if (tecla == '6') {
						cardtodelete1 = 6;
						transicion++;
					}
					else if (tecla == '7') {
						cardtodelete1 = 7;
						transicion++;
					}
					else if (tecla == '8') {
						cardtodelete1 = 8;
						transicion++;
					}
					else if (tecla == '9') {
						cardtodelete1 = 9;
						transicion++;
					}
					else if (tecla == 'X' || tecla == 'x') {
						cardtodelete1 = 10;
						transicion++;
					}
					else if (tecla == 'J' || tecla == 'j') {
						cardtodelete1 = 11;
						transicion++;
					}
					else if (tecla == 'Q' || tecla == 'q') {
						cardtodelete1 = 12;
						transicion++;
					}
					else if (tecla == 'K' || tecla == 'k') {
						cardtodelete1 = 13;
						transicion++;
					}
					//skipeo de turno p1
					else if (tecla == 'p' || tecla == 'P') {
						clearConsole();
						cursor(0, 4);
						cardtodelete1 = 14;
						cout << player1Name << " salta su turno!";
						transicion++;
					}

				}

			}

			transicion = 0;

			//validacion de la baraja de cartas
			bool validChoice = false;
			for (int i = 0; i < hand_size; i++) {
				if (player1Hand[i] == cardtodelete1) {
					validChoice = true;

				}
				else if (cardtodelete1 == 14) {
					cursor(0, 2);
					cout << player1Name << " salta su turno!";
				}

				else {
					clearConsole();

					cursor(0, 2);
					cout << player1Name << " no tiene la carta";
				}

			}



			if (validChoice)
			{
				if (cardtodelete1 == randomcard) {
					clearConsole();
					cursor(0, 1);
					deleteCard(player1Hand, cardtodelete1);
					cout << "Carta " << cardtodelete1 << " eliminada satisfactoriamente!" << endl;
				}
				else {
					clearConsole();
					cursor(0, 1);
					cout << "La carta a eliminar es invalida" << endl;
				}

			}
			cursor(0, 4);
			cout << "|===============================" << player1Name << "==============================|" << endl;
			cursor(0, 14);
			cout << "|===============================" << player2Name << "==============================|" << endl;
			cursor(74, 9);
			cout << "|=dealer=|";

			CartaRandom(randomcard);

			displayHand(player1Hand, player1Name);
			displayHand2(player2Hand, player2Name);
			cursor(0, 22);
			cout << player2Name << " elija la carta a eliminar: ";

			//input directo p2
			int transicion1 = 0;
			while (transicion1 < 1) {
				if (_kbhit()) {
					tecla = getch();
					if (tecla == '1') {
						cardtodelete2 = 1;
						transicion1++;
					}
					else if (tecla == '2') {
						cardtodelete2 = 2;
						transicion1++;
					}
					else if (tecla == '3') {
						cardtodelete2 = 3;
						transicion1++;
					}
					else if (tecla == '4') {
						cardtodelete2 = 4;
						transicion1++;
					}
					else if (tecla == '5') {
						cardtodelete2 = 5;
						transicion1++;
					}
					else if (tecla == '6') {
						cardtodelete2 = 6;
						transicion1++;
					}
					else if (tecla == '7') {
						cardtodelete2 = 7;
						transicion1++;
					}
					else if (tecla == '8') {
						cardtodelete2 = 8;
						transicion1++;
					}
					else if (tecla == '9') {
						cardtodelete2 = 9;
						transicion1++;
					}
					else if (tecla == 'X' || tecla == 'x') {
						cardtodelete2 = 10;
						transicion1++;
					}
					else if (tecla == 'J' || tecla == 'j') {
						cardtodelete2 = 11;
						transicion1++;
					}
					else if (tecla == 'Q' || tecla == 'q') {
						cardtodelete2 = 12;
						transicion1++;
					}
					else if (tecla == 'K' || tecla == 'k') {
						cardtodelete2 = 13;
						transicion1++;
					}
					//skipeo de turno p2
					else if (tecla == 'p' || tecla == 'P') {
						clearConsole();
						cardtodelete2 = 14;
						transicion1++;
					}

				}

			}
			transicion1 = 0;



			validChoice = false;
			for (int i = 0; i < hand_size; i++) {
				if (player2Hand[i] == cardtodelete2) {
					validChoice = true;
				}
				else if (cardtodelete2 == 14) {
					cursor(0, 2);
					cout << player2Name << " salta su turno!";
				}
				else {
					clearConsole();
					cursor(0, 2);
					cout << player2Name << " no tiene la carta";
				}
			}

			if (validChoice)
			{
				if (cardtodelete2 == randomcard) {
					clearConsole();
					cursor(0, 1);
					deleteCard(player2Hand, cardtodelete2);
					cout << "Carta " << cardtodelete2 << " eliminada satisfactoriamente!" << endl;

				}
				else {
					clearConsole();
					cursor(0, 1);
					cout << "La carta a eliminar es invalida" << endl;

				}


			}

			counter++;
			cursor(0, 4);
			cout << "|===============================" << player1Name << "==============================|" << endl;
			cursor(0, 14);
			cout << "|===============================" << player2Name << "==============================|" << endl;
			cursor(74, 9);
			cout << "|=dealer=|";


		} while (counter < 8);

		int point1 = getScore(player1Hand);
		int point2 = getScore(player2Hand);

		if (point1 == point2) {
			score1 + 0;
			score2 + 0;
		}
		else if (point1 < point2) {
			score1++;
		}
		else {
			score2++;
		}

		partidas++;
		partida_actual++;

		clearConsole();
		scoreboard(31, 8, player1Name, player2Name, partida_actual, partidas, score1, score2);
		clearConsole();

		counter = 0;

	}
	ganador(score1, score2);
	system("pause > 0");
	clearConsole();
}
