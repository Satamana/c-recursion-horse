#include<iostream>
#include<iomanip>
using namespace std;
const int Size = 8;
int masx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int masy[8] = { 2,1,-1,-2,-2,-1,1,2 };
void outp(int mas[][Size])
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			cout << setw(3) << mas[i][j];
		}
		cout << endl;
	}
}
void horse(int mas[][Size], int num, int i0, int j0)
{
	static int attempt = 0;
	attempt++;
	mas[i0][j0] = num++;
	for (int i = 0; i < 8; i++)
	{
		int inew = i0 + masy[i];
		int jnew = j0 + masx[i];
		if (num > Size*Size)
		{
			cout << "Вызовов ф-ии: " << attempt << endl;
			outp(mas);
			exit(0);
		}
		if (inew < 0 || inew > Size - 1 || jnew < 0 || jnew > Size - 1 || mas[inew][jnew] != 0) continue;
		horse(mas, num, inew, jnew);
		mas[inew][jnew] = 0;
	}
}
void main()
{
	setlocale(LC_ALL, "RUS");
	int desk[Size][Size] = {};
	horse(desk, 1, 7, 0);
}