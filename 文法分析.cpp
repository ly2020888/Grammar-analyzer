
#include <iostream>
#include <fstream>
using namespace std;
int a, b, c;
char nEnd[20];
char _end[20];
char _produce[20][10];
char start;
ifstream scrFile("testA.txt");
ofstream dstFile("testB.txt");
int main()
{
    // 首先接受非终结符集
	scrFile >> a;
	for (int i = 0; i < a; i++) {
		scrFile >> nEnd[i];
	}
	//接受终结符集
	scrFile >> b;
	for (int i = 0; i < b; i++) {
		scrFile >> _end[i];
	}
	//接受产生式集
	scrFile >> c;
	for (int i = 0; i < c; i++) {
		scrFile >> _produce[i][0];
		int x;
		scrFile >> x;
		for (int j = 1; j <= x; j++) {
			scrFile >> _produce[i][j];
		}
	}
	scrFile >> start;

	dstFile << "非终结符集:" << endl;
	for (int i = 0; i < a; i++) {
		dstFile << nEnd[i] << " ";
	}
	dstFile << "\n";

	dstFile << "终结符集:" << endl;
	for (int i = 0; i < b; i++) {
		dstFile << _end[i] << " ";
	}
	dstFile << "\n";

	dstFile << "产生式集:" << endl;
	for (int i = 0; i < c; i++) {
		dstFile <<i<<": "<< _produce[i][0]<<"->";
		for (int j = 1; j <= strlen(_produce[i]); j++) {
			dstFile << _produce[i][j];
		}
		dstFile << "\n";
	}
	dstFile << "开始符号:" << endl;
	dstFile << start;
	scrFile.close();
	dstFile.close();
	return 0;
}

