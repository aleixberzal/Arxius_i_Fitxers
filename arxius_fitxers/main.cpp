#include <iostream>+
#include <fstream>
#include <string>
#include <vector>
using namespace std;


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
	


void SaveSentences(vector<string>& sentences, string& fileName) {
	ofstream outFile(fileName, ios::binary | ios::trunc);

	if (!outFile.is_open()) return;

	size_t vectorSize = sentences.size();
	if (vectorSize == 0) return;

	outFile.write(reinterpret_cast<char*>(&vectorSize), sizeof(size_t));

	for (size_t i = 0; i < vectorSize; i++) {
		size_t stringSize = sentences[i].size();
		outFile.write(reinterpret_cast<char*>(&stringSize), sizeof(size_t));
		outFile.write(sentences[i].c_str(), stringSize);
	}

	outFile.close();
}

void recoverSentences(vector<string>& sentences, string& fileName) {
	ifstream inFile(fileName, ios::binary);

	if (!inFile.is_open()) return;

	size_t vectorSize = 0;
	inFile.read(reinterpret_cast<char*>(&vectorSize), sizeof(size_t));

	for (size_t i = 0; i < vectorSize; i++) {
		size_t stringSize;
		inFile.read(reinterpret_cast<char*>(&stringSize), sizeof(size_t));

		char* arrTmp = new char[stringSize + 1];
		inFile.read(arrTmp, sizeof(char) * stringSize);

		arrTmp[stringSize] = '\0';
		string sentence = arrTmp;

		delete[] arrTmp;
		sentences.push_back(sentence);
	}
	inFile.close();
}

int main() {
	vector<string> sentences;
	string fileName = "frases.dat";
	string userSentence;

	do {
		cout << "Dame una frase (o escribe 'fin' para terminar): " << endl;
		getline(cin, userSentence);

		if (userSentence != "fin") {
			sentences.push_back(userSentence);
		}
	} while (userSentence != "fin");

	// Guardar las frases en el archivo binario
	SaveSentences(sentences, fileName);

	// Vaciar el vector para simular la lectura desde un archivo
	sentences.clear();

	// Recuperar las frases del archivo binario
	recoverSentences(sentences, fileName);

	// Imprimir las frases recuperadas
	cout << "\nFrases recuperadas del archivo:\n";
	for (const string& sentence : sentences) {
		cout << sentence << endl;
	}

	return 0;
}
