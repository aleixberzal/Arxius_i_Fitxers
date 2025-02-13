#include <iostream>+
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#define ROW_SIZE 6
#define COLS_SIZE 5

	/*12. Fes un programa que demani diverses frases a l’usuari, les desi a “frases.dat” en format
binari i finalment les llegeixi per imprimir-les per consola.
*/

	/*string s;

	cout << "Introduce una frase!" << endl;
	cin >> s;

	ofstream out("test.bin", ios::out | ios::binary);
	if (!out) {
		cerr << "Error al abrir el archivo para escritura";
			return 1;
	}

	size_t size = s.size();
	out.write(reinterpret_cast<char*>(&size), sizeof(size_t));
	out.write(s.c_str(), size);
	out.close();

	ifstream in("test.bin", ios::out | ios::binary);
	if (!in) {
		cerr << "Error al abrir archivo de lectura";
		return 1;
	}

	size_t readSize;
	in.read(reinterpret_cast<char*>(&readSize), sizeof(size_t));

	char* temp = new char[readSize + 1];
	in.read(temp, readSize);
	temp[size] = '\0';

	string readString = temp;
	delete[] temp;
	in.close();

	cout << "String read!" << readString << endl;
	return 0;*/

	/*vector<string> myVector;
	string frase;
	cout << "Introduce una frase!" << endl;
	cin >> frase;

	ofstream out("testVec.bin", ios::out | ios::binary);
	if (!out) {
		cerr << "Error al abrir el archivo para escritura";
		return 1;
	}

	int size = myVector.size();
	out.write(reinterpret_cast<char*>(&size), sizeof(int));
	out.write(reinterpret_cast<char*>(myVector.data()), sizeof(char) * myVector.size());

	out.close();

	ifstream in("testVec.bin", ios::out | ios::binary);
	if (!in) {
		cerr << "Error al abrir archivo de lectura";
		return 1;
	}

	int readSize;
	vector<string> inputVector;
	in.read(reinterpret_cast<char*>(&readSize), sizeof(int));

	inputVector.resize(readSize);
	in.read(reinterpret_cast<char*>(&readSize), sizeof(int) * readSize);

	in.close();

	
	return 0;*/
	


	//void SaveSentences(vector<string>& sentences, string& fileName) {
	//	/*Opening the file in binary mode*/
	//ofstream outFile(fileName, ios::binary | ios::trunc);
	///*Cheking if the file is open*/
	//if (!outFile.is_open()) return;
	///*getting the vector size*/
	//size_t vectorSize = sentences.size();
	///*Handling empty vector*/
	//if (vectorSize == 0) return;
	//outFile.write(reinterpret_cast<char*>(&vectorSize), sizeof(size_t));
	///*Cicle for to write all the strings and go through them, the size of the string is written
	//	The sentence itself is weitten to the file using outfile.write, c-string representation of the sentence
	//	and string size tells us how many char to write*/
	//for (size_t i = 0; i < vectorSize; i++) {
	//	size_t stringSize = sentences[i].size();
	//	outFile.write(reinterpret_cast<char*>(&stringSize), sizeof(size_t));
	//	outFile.write(sentences[i].c_str(), stringSize);
	//}

	//outFile.close();
	//}

	//void recoverSentences(vector<string>& sentences, string& fileName) {
	//	/*Open in binary mode*/
	//	ifstream inFile(fileName, ios::binary);

	//	if (!inFile.is_open()) return;
	//	/*Reading the vector size*/
	//	size_t vectorSize = 0;
	//	inFile.read(reinterpret_cast<char*>(&vectorSize), sizeof(size_t));

	//	/*The size of the string is read stringsize
	//	a temporary array is created to store the string, the array size
	//	is +1 for the null terminator
	//	the sentence is read from the file into arrtmp
	//	the arrtmp array is converted into a string object which is pushed into the
	//	sentences vector
	//	And the dynamically allocated memory for arrTmp is deleted to prevent memory leaks*/

	//	for (size_t i = 0; i < vectorSize; i++) {
	//		/*We create a string size*/
	//		size_t stringSize;
	//		inFile.read(reinterpret_cast<char*>(&stringSize), sizeof(size_t));
	//		/*Temporary array*/
	//		char* arrTmp = new char[stringSize + 1];
	//		inFile.read(arrTmp, sizeof(char) * stringSize);

	//		arrTmp[stringSize] = '\0';
	//		string sentence = arrTmp;

	//		delete[] arrTmp;
	//		sentences.push_back(sentence);
	//	}
	//	inFile.close();
	//}

	//int main() {
	//	vector<string> sentences;
	//	string fileName = "frases.dat";
	//	string userSentence;
	//	/*Do while to get sentences from the user until it is fin, and while it is not, we push them back*/
	//	do {
	//		cout << "Dame una frase (o escribe 'fin' para terminar): " << endl;
	//		getline(cin, userSentence);

	//		if (userSentence != "fin") {
	//			sentences.push_back(userSentence);
	//		}
	//	} while (userSentence != "fin");

	//	// Guardar las frases en el archivo binario
	//	SaveSentences(sentences, fileName);


	//	// Vaciar el vector para simular la lectura desde un archivo
	//	sentences.clear();

	//	// Recuperar las frases del archivo binario
	//	recoverSentences(sentences, fileName);

	//	// Imprimir las frases recuperadas
	//	cout << "\nFrases recuperadas del archivo:\n";
	//	/*Cicle for to run through all the sentences written by the user*/
	//	for (const string& sentence : sentences) {
	//		cout << sentence << endl;
	//	}

	//	return 0;
	//}

void saveStreak(int streak) {
	/*We first save the player name, then we load the file where we are going to store the data
	Then we check if the file is open
	We save the length of the characters with size_t
	We write the reinterpret 
	we write the cstr
	we write the reinterpret but with the streak
	And finally close the file*/
	std::string playerName;
	std::cout << "Enter your name to save your streak: ";
	std::cin >> playerName;

	std::ofstream file("victories.dat", std::ios::binary | std::ios::app);
	if (!file) {
		std::cerr << "Error opening file!\n";
		return;
	}

	// Save name length first to handle different name sizes
	size_t nameLength = playerName.size();
	file.write(reinterpret_cast<const char*>(&nameLength), sizeof(size_t));
	file.write(playerName.c_str(), nameLength);
	file.write(reinterpret_cast<const char*>(&streak), sizeof(int));

	file.close();
	std::cout << "Streak saved!\n";
}
//With this I can open the file with normal char
void loadStreaks() {
	// We load the file with ifstream, then check if its open. Later, we 
	std::ifstream file("victories.dat", std::ios::binary);
	if (!file) {
		std::cerr << "No saved streaks found!\n";
		return;
	}

	std::cout << "Saved Streaks:\n";
	while (!file.eof()) {
		size_t nameLength;
		if (!file.read(reinterpret_cast<char*>(&nameLength), sizeof(size_t))) break;

		std::string name(nameLength, '\0');
		file.read(&name[0], nameLength);

		int streak;
		file.read(reinterpret_cast<char*>(&streak), sizeof(int));

		std::cout << "Player: " << name << " - Streak: " << streak << "\n";
	}

	file.close();
}

int main() {

	srand(time(NULL));

	/*Leer un archivo txt con la siguiente informacion:
	-----
	-...-
	-..E-
	-.P.-
	-...-
	-----

	E --> Enemy
	P --> Player
	- --> Muro
	. --> Casilla Vacia

	2. Gameplay: el jugador puede moverse con W, A, S, D dentro de la sala
		- Si choca con el enemigo 50% de probabilidades de ganar
		- Si gana, win y gameover (se le vuelve a preguntar de jugar)

	3 En cualquier momento puedo guardar la racha de victorias que llevo en un archivo binario. Antes me pide el nombre y se tiene que guardar el nombre y la racha de victorias.

	*/

	/*We declare a vector within another one to be able to modify the table from the files later on*/

	std::vector<std::vector<char>> table(ROW_SIZE, std::vector<char>(COLS_SIZE));

	/*We fill it with our values*/
	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COLS_SIZE; j++) {
			if (i == 0 || i == 5) {
				table[i][j] = '-';
			}
			else if (j == 0 || j == 4) {
				table[i][j] = '-';
			}
			else {
				table[i][j] = '~';
			}
		}
	}

	int playerRow = 3, playerCol = 2;
	int enemyRow = 2, enemyCol = 3;

	table[playerRow][playerCol] = 'P';
	table[enemyRow][enemyCol] = 'E';

	bool gameOver = false;
	int streak = 0;
	while (!gameOver) {

		/*We print it*/
		for (int row = 0; row < ROW_SIZE; row++) {
			for (int col = 0; col < COLS_SIZE; col++) {
				std::cout << table[row][col];
			}
			std::cout << std::endl;
		}

		char userInput;
		std::cout << "Pulsa una tecla para moverte (W-A-S-D): ";
		std::cin >> userInput;

		if (userInput == 'X' || userInput == 'x') {
			saveStreak(streak);
			continue;
		}

		int oldRow = playerRow;
		int oldCol = playerCol;

		/*Depending on the input we decide to move a direction*/

		switch (userInput) {

		case 'W': playerRow--; break;
		case 'A': playerCol--; break;
		case 'S': playerRow++; break;
		case 'D': playerCol++; break;

		default:
			std::cout << "Not valid" << std::endl;
			return 1;


		}
		// OPTIONAL: Check if the new position is valid (within bounds and not a wall)
		if (playerRow < 0 || playerRow >= ROW_SIZE || playerCol < 0 || playerCol >= COLS_SIZE ||
			table[playerRow][playerCol] == '-') {
			std::cout << "Movimiento no válido. Inténtalo de nuevo.\n";
			playerRow = oldRow;
			playerCol = oldCol;
			continue;
		}

		// Clear the old player position
		table[oldRow][oldCol] = '~';
		// Place the player in the new position
		table[playerRow][playerCol] = 'P';

		int win_prob;
		int rand_row;
		int rand_col;

		if (playerRow == enemyRow && playerCol == enemyCol) {
			win_prob = rand() % 2;
			if (win_prob == 1) {
				std::cout << "Has ganado la partida" << std::endl;
				gameOver = true;
				streak++;
			}
			else {
				std::cout << "Keep playing boy!" << std::endl;
				
				do
				{
					enemyRow = rand() % (ROW_SIZE - 2) + 1;
					enemyCol = rand() % (COLS_SIZE - 2) + 1;
				} while (table[enemyRow][enemyCol] == 'P');

				table[enemyRow][enemyCol] = 'E';

			}
		
		}
	}

	return 0;
	}
