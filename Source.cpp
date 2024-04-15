#define _CRT_SECURE_NO_WARNINGS
#define dX dP[d][0]
#define dY dP[d][1]

#include <windows.h>
#include <stdio.h>

const int N = 16, M = 16;
const int S = N * M;
int a[N][M];

int main() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);

	int X = 0, Y = 0;
	int nX, nY;
	int d = 0;

	int dP[4][2] = {
		{ 0,  1 },
		{ 1,  0 },
		{ 0, -1 },
		{ -1 ,0 }
	};

	system("cls");
	for (int i = 0; i < S; i++) {
		a[X][Y] = i;
		nX = X + dX;
		nY = Y + dY;
		printf("\033[%d;%dH\033[48;2;%d;%d;%dm  \033[0m", X + 1, 2 * Y + 1, a[X][Y], a[X][Y], a[X][Y]);
		Sleep(50);
		if (a[nX][nY] != 0 || nX == N || nY == M || (nX == 0 && nY == 0)) {
			d = (d + 1) % 4;
		}
		X += dX;
		Y += dY;
	}
}