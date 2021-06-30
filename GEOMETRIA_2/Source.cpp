#include <iostream>
#include<conio.h>
using namespace std;

//#define SQUARE
//#define TRIANGLE_1
//#define TRIANGLE_2
//#define TRIANGLE_3
//#define TRIANGLE_4
//#define RUM
//#define PLUS_MINUS
#define CHESS_BOARD    //д/з 22.06
//#define CHESS_BOARD_2 //вариант д/з
#define ASCII

#define CHESS_BOARD_3 //вариант шахматной доски в классе

#define UPPER_LEFT_ANGLE (char)218
#define UPPER_RIGHT_ANGLE (char)191
#define DOWN_LEFT_ANGLE (char)192
#define DOWN_RIGHT_ANGLE (char)217
#define VERT_LINE (char)179
#define HORIZ_LINE (char)196<<(char)196
#define WHITE_BOX "\xDB\xDB" //(char)219<<(char)219
#define BLACK_BOX "  "





void main()

{
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите длину стороны фигуры: "; cin >> n;
#ifdef SQUARE //выводим квадрат
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "* ";
		}
		cout << endl;

	}
	cout << endl;
#endif // SQUARE

#ifdef TRIANGLE_1 //выводим прямоугольный треугольник
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "* ";

		}
		cout << endl;
	}
	cout << endl;
#endif // TRIANGLE_1

#ifdef TRIANGLE_2 //выводим перевернутый прямоугольный треугольник - способ 2
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			cout << "* ";

		}
		cout << endl;
	}
	cout << endl;
#endif // TRIANGLE_2

#ifdef TRIANGLE_3 //выводим отражение прямоугольного треугольника через квадрат
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			/*if (j >=i) cout << "* ";
			else cout << "  ";*/
			cout << (j >= i ? "* " : "  ");
		}
		cout << endl;
	}
	cout << endl;
#endif // TRIANGLE_3

#ifdef TRIANGLE_4	//выводим перевернутое отражение прямоугольного треугольника через квадрат
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << (j >= n - i - 1 ? "* " : "  ");
		}
		cout << endl;
	}
	cout << endl;
#endif // TRIAGLE_4

#ifdef RUM //если считаем, что задаем половину диагонали ромба, принцип построения из 2 треугольников

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++) cout << " ";
		cout << "/";
		for (int j = 0; j < i * 2; j++)	cout << " ";
		cout << "\\";

		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++) cout << " ";
		cout << "\\";
		for (int j = i; j < n * 2 - i - 2; j++) cout << " ";
		cout << "/";
		cout << endl;

	}
	cout << endl;

#endif // RUM

#ifdef PLUS_MINUS //для четных строк + выводится в четных столбцах, для нечетных + выводится в нечетных
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ((j - i) % 2 == 0 ? "+ " : "- ");

		}
		cout << endl;
	}
	cout << endl;

#endif // PLUS_MINUS

#ifdef CHESS_BOARD_2
	setlocale(LC_ALL, "C");

	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)

		{
			/*if(i == 0) cout << char(196) << char(196);
			if (j == 0) cout << "| ";
			if (j == n + 1) cout << " |";
			if (i == n+1) cout << char(196) << char(196);*/ //вывести отдельно части рамки не получается

			if (i == 0 || i == n + 1 || j == 0 || j == n + 1) cout << "**";
			else
			{
				cout << ((j - i) % 2 == 0 ? "\x1b[37;47m  \x1b[0m" : "  ");
			}
		}
		cout << endl;
	}

	cout << endl;

#endif // CHESS_BOARD_2

#ifdef CHESS_BOARD_3
	setlocale(LC_ALL, "C");
	/*for (int i = 0; i < 256; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}*/
	n++;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 && j == 0) cout << UPPER_LEFT_ANGLE;
			else if (i == 0 && j == n) cout << UPPER_RIGHT_ANGLE;
			else if (i == n && j == 0) cout << DOWN_LEFT_ANGLE;
			else if (i == n && j == n) cout << DOWN_RIGHT_ANGLE;
			else if (i == 0 || i == n) cout << HORIZ_LINE;
			else if (j == 0 || j == n) cout << VERT_LINE;

			//else cout << ((j - i) % 2 == 0 ? "\x1b[37;47m  \x1b[0m" : "  ");
			else cout << ((j - i) % 2 == 0 ? WHITE_BOX : BLACK_BOX);

		}
		cout << endl;
	}
#endif // CHESS_BOARD_3

#ifdef CHESS_BOARD
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int l = 0; l < n; l++)
				{
					((j - i) % 2 == 0) ? cout << "* " : cout << "  ";
				}

			}
			cout << endl;
		}


	}

	cout << endl;
#endif // CHESS_BOARD

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++) cout << " ";
		cout << 1;
		for (int j = 1; j < i * 2 - 1; j++)
			cout << ((j - i) % 2 == 0 ? "." : " ");
		cout << 1;


		cout << endl;
	}

}