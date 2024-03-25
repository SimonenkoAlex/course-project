#include <Windows.h>
#include <locale.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <mmsystem.h>
#include "Handbook.h"
#include "SoundSynth.h"
#include "SeaBattle.h"
#include "MusicBox.h"
#include "SearchGivenArea.h"

using namespace std;

const int startPosX = 10, startPosY = 5;
FILE *DB;

void splashScreen() { // заставка круги на воде
	system("cls");
	HWND hwn = GetConsoleWindow();
	HDC hdc = GetDC(hwn);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HPEN PEN; HBRUSH BRUSH;
	int x, y, R, G, B, radius[] = {10, 30, 50, 70, 90, 110, 130, 150};
	while (!_kbhit()) {
		x = random(800); y = random(800); 
		R = random(256); G = random(256); B = random(256);
		PEN = CreatePen(PS_SOLID, 5, RGB(R, G, B));
		BRUSH = CreateSolidBrush(RGB(0, 0, 0)); 
		SelectObject(hdc, PEN); SelectObject(hdc, BRUSH);
		PlaySound("voda-kaplya.wav", 0, SND_ASYNC | SND_NOWAIT);
		for (int i = 0; i < 7; i++) {
			Ellipse(hdc, x - radius[i], y - radius[i], x + radius[i], y + radius[i]);
			Sleep(200);
			PlaySound("malenkie-vspleski-vodyi.wav", 0, SND_ASYNC | SND_NOSTOP);
			Ellipse(hdc, x - radius[i + 1], y - radius[i + 1], x + radius[i + 1], y + radius[i + 1]);
			Sleep(150);
			SystemClear();
		}
		PlaySound(0, 0, SND_PURGE);
	}
	//DeleteObject(PEN); DeleteObject(BRUSH);
	ReleaseDC(hwn, hdc);
	_getch();
}

void aboutAuthor() {
	system("cls"); 
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE); 
	WORD colorPrimaryText = FOREGROUND_RED | FOREGROUND_INTENSITY;
	WORD colorAccentText = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	char textSignature[][50] = {"Выполнил (ФИО автора): ", "Факультет: ", "Группа: ", "Кафедра: "};
	char textRecord[][50] = { "Симоненко Александр Евгеньевич", 
		"Информационных Технологий и Компьютерных Систем", 
		"ИВТ-172", "Информатика и Вычислительная Техника" };
	COORD position; 
	for (int i = 0; i < 4; i++) {
		position.X = startPosX; position.Y = startPosY + i * 2; 
		SetConsoleCursorPosition(hstdout, position); 
		SetConsoleTextAttribute(hstdout, colorPrimaryText);
		cout << textSignature[i] << " "; 
		SetConsoleTextAttribute(hstdout, colorAccentText);
		cout << textRecord[i] << endl;
		cout << "\t------------------------------------------------------------";
	}
	_getch();
}

void functions() {
	system("cls");
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD colorMinimum = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	WORD colorMaximum = FOREGROUND_GREEN | FOREGROUND_BLUE;
	WORD colorPrimaryText = FOREGROUND_RED | FOREGROUND_INTENSITY;
	WORD colorAccentText = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	COORD position;	
	int n, i; 
	double a = 2, b = 4, x[21], F1[21], F2[21];
	position.X = startPosX; position.Y = startPosY;
	SetConsoleCursorPosition(hstdout, position);
	SetConsoleTextAttribute(hstdout, colorPrimaryText);
	printf("Введите число интервалов табулирования: "); 
	SetConsoleTextAttribute(hstdout, colorAccentText);
	scanf_s("%d", &n); // n = 20
	long double dx = fabs(b - a) / (n - 1);
	x[0] = a; // начало отсчёта - левая граница интервала
	printf("\t-------------------------------------------------\n"); 
	printf("\t| I |\tX[i]\t|\tF1[i]\t|\tF2[i]\t|\n"); 
	printf("\t|   |\t    \t|\t     \t|\t     \t|\n");
	for (i = 0; i < n; ++i) { 
		F1[i] = x[i] * cos(x[i] / 2); 
		F2[i] = pow(x[i], 1.0 / 3.0) + sqrt(2.0) * exp(-x[i]); 
		x[i + 1] = x[i] + dx; 
	}
	double maxF1 = F1[0], maxF2 = F2[0], minF1 = F1[0], minF2 = F2[0];
	for (i = 0; i < n; ++i) {
		if (maxF1 < F1[i]) maxF1 = F1[i];
		if (maxF2 < F2[i]) maxF2 = F2[i];
		if (minF1 > F1[i]) minF1 = F1[i];
		if (minF2 > F2[i]) minF2 = F2[i];
	}
	for (i = 0; i < n; ++i) { 
		printf("\t|%3d|%11.3f|", i + 1, x[i]); 
		if (minF1 == F1[i]) 
			SetConsoleTextAttribute(hstdout, colorMinimum);
		if (maxF1 == F1[i])
			SetConsoleTextAttribute(hstdout, colorMaximum);
		printf("%15.3f", F1[i]); 
		SetConsoleTextAttribute(hstdout, colorAccentText);
		printf("|"); 
		if (minF2 == F2[i]) 
			SetConsoleTextAttribute(hstdout, colorMinimum);
		if (maxF2 == F2[i])
			SetConsoleTextAttribute(hstdout, colorMaximum);
		printf("%15.3f", F2[i]); 
		SetConsoleTextAttribute(hstdout, colorAccentText);
		printf("|\n"); 
	}
	printf("\t-------------------------------------------------\n");
	_getch();
}

void graphics() {
	system("cls");
	HWND hwn = GetConsoleWindow(); 
	HDC hdc = GetDC(hwn);
	HPEN pen = CreatePen(PS_DASH, 3, RGB(140, 90, 10));
	HPEN penF1 = CreatePen(PS_DASHDOT, 2, RGB(113, 47, 38));
	HPEN penF2 = CreatePen(PS_DASHDOT, 2, RGB(213, 48, 50));
	RECT rect;
	GetClientRect(hwn, &rect);
	// параметры и коэффициент интерполяции
	const int width = rect.right, height = rect.bottom;
	const int c = width / 2, d = height / 2, k = 50;
	double x, F1, F2, h = 0.001, a = 2, b = 4;
	int x0 = c, y0 = d;
	WORD nSize;
	TCHAR str[100];
	while (!_kbhit()) {
		bool first = true, second = true;
		SetBkColor(hdc, RGB(0, 0, 0));
		SetTextColor(hdc, RGB(255, 255, 0));
		SelectObject(hdc, pen);
		nSize = wsprintf(str, TEXT("%s"), "X");
		TextOut(hdc, width - 10, d, str, nSize);
		MoveToEx(hdc, 0, d, NULL);
		LineTo(hdc, c * k, d);		// ось X
		nSize = wsprintf(str, TEXT("%s"), "Y");
		TextOut(hdc, c + 10, 0, str, nSize);
		MoveToEx(hdc, c, 0, NULL);
		LineTo(hdc, c, k * d);		// ось Y
		//GetClientRect(hwn, &rect);
		for (int i = 0; i < 8; i++) {
			MoveToEx(hdc, x0 - 10, y0 - k * i, NULL); //засечки на оси У 
			LineTo(hdc, x0 + 10, y0 - k * i);
			MoveToEx(hdc, x0 - 10, y0 + k * i, NULL);
			LineTo(hdc, x0 + 10, y0 + k * i);
			MoveToEx(hdc, x0 + k * i, y0 - 10, NULL); //засечки на оси Х 
			LineTo(hdc, x0 + k * i, y0 + 10);
			MoveToEx(hdc, x0 - k * i, y0 - 10, NULL);
			LineTo(hdc, x0 - k * i, y0 + 10);
			if (i == 0) {
				nSize = wsprintf(str, TEXT("%d"), i);
				TextOut(hdc, x0 - 10, y0 - k * i, str, nSize);
			}
			else {
				nSize = wsprintf(str, TEXT("%d"), i);
				TextOut(hdc, x0 - 15, y0 - k * i, str, nSize);
				TextOut(hdc, x0 + k * i, y0 + 15, str, nSize);
				nSize = wsprintf(str, TEXT("-%d"), i);
				TextOut(hdc, x0 - 15, y0 + k * i, str, nSize);
				TextOut(hdc, x0 - k * i, y0 + 15, str, nSize);
			}
		}
		for (x = a; x < b; x += h) {
			F1 = x * cos(x / 2);
			if (first) {
				SelectObject(hdc, penF1);
				MoveToEx(hdc, c + k * x, d - k * F1, NULL);
				first = false;
			}
			else LineTo(hdc, c + k * x, d - k * F1);
		}
		SetTextColor(hdc, RGB(113, 47, 38));
		nSize = wsprintf(str, TEXT("%s"), "y = x * cos(x / 2)");
		TextOut(hdc, c + k * x, d - k * F1, str, nSize);
		for (x = a; x < b; x += h) {
			F2 = pow(x, 1.0 / 3.0) + sqrt(2.0) * exp(-x);
			if (second) {
				SelectObject(hdc, penF2);
				MoveToEx(hdc, c + k * x, d - k * F2, NULL);
				second = false;
			}
			else LineTo(hdc, c + k * x, d - k * F2);
		}
		SetTextColor(hdc, RGB(213, 48, 50));
		nSize = wsprintf(str, TEXT("%s"), "y = x^(1/3) + 2^(1/2) * e^(-x)");
		TextOut(hdc, c + k * x, d - k * F2, str, nSize);
	}
	_getch();
}

void integral() {
	system("cls");
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD colorSignatureText = FOREGROUND_GREEN;
	WORD colorPrimaryText = FOREGROUND_RED | FOREGROUND_INTENSITY;
	WORD colorAccentText = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	COORD position;
	int n, i; 
	double a, b, h, Sum = 0, Integ = 1;
	position.X = startPosX;
	do {
		system("cls");
		position.Y = startPosY;
		SetConsoleCursorPosition(hstdout, position);
		SetConsoleTextAttribute(hstdout, colorSignatureText);
		printf("Введите кол-во отрезков разбиения: ");
		position.Y = startPosY + 2;
		SetConsoleCursorPosition(hstdout, position);
		printf("N = ");
		SetConsoleTextAttribute(hstdout, colorAccentText);
		cin >> n;
	} while (n < 50);
	double *x = new double[n];
	double *F = new double[n];
	position.Y = startPosY + 4;
	SetConsoleCursorPosition(hstdout, position);
	SetConsoleTextAttribute(hstdout, colorSignatureText);
	printf("Введите границы интегрирования [a, b]: ");
	position.Y = startPosY + 6;
	SetConsoleCursorPosition(hstdout, position);
	printf("a = ");
	SetConsoleTextAttribute(hstdout, colorAccentText);
	cin >> a;
	position.Y = startPosY + 8;
	SetConsoleCursorPosition(hstdout, position);
	SetConsoleTextAttribute(hstdout, colorSignatureText);
	printf("b = ");
	SetConsoleTextAttribute(hstdout, colorAccentText);
	cin >> b;
	position.Y = startPosY + 10;
	SetConsoleCursorPosition(hstdout, position);
	SetConsoleTextAttribute(hstdout, colorPrimaryText);
	printf("1) Метод прямоугольников");
	h = fabs(b - a) / n; x[1] = a;
	for (i = 1; i <= n; ++i) { 
		F[i] = pow(x[i], 2) * log(x[i]); 
		x[i + 1] = x[i] + (i - 0.5) * h;
		Sum = (float)Sum + F[i]; 
	} 
	position.Y = startPosY + 12;
	SetConsoleCursorPosition(hstdout, position);
	SetConsoleTextAttribute(hstdout, colorSignatureText);
	Integ = h * Sum; 
	cout << "Приближенное значение определенного интеграла: J = " << Integ;

	position.Y = startPosY + 14;
	SetConsoleCursorPosition(hstdout, position);
	SetConsoleTextAttribute(hstdout, colorPrimaryText);
	printf("2) Метод трапеции");
	h = fabs(b - a) / n; x[1] = a;
	for (i = 1; i <= n - 1; ++i) {
		F[i] = pow(x[i], 2) * log(x[i]);
		x[i + 1] = x[i] + h;
		Sum = (float)Sum + F[i];
	}
	position.Y = startPosY + 16;
	SetConsoleCursorPosition(hstdout, position);
	SetConsoleTextAttribute(hstdout, colorSignatureText);
	Sum = Sum + (F[(int)a] + F[(int)b]) / h;
	Integ = h * Sum;
	cout << "Приближенное значение определенного интеграла: J = " << Integ;
	_getch();
}

double f(double x) { return x * exp(x) - 2 * pow(x, 2.0) - 1; }

void equation() {
	system("cls");
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD colorSignatureText = FOREGROUND_GREEN;
	WORD colorPrimaryText = FOREGROUND_RED | FOREGROUND_INTENSITY;
	WORD colorAccentText = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	COORD position;
	double a, b, c, e = 0.001;
	position.X = startPosX; position.Y = startPosY;
	SetConsoleCursorPosition(hstdout, position);
	SetConsoleTextAttribute(hstdout, colorSignatureText);
	printf("Введите интервал поиска корня [a, b]: ");
	position.Y = startPosY + 2;
	SetConsoleCursorPosition(hstdout, position);
	printf("a = ");
	SetConsoleTextAttribute(hstdout, colorAccentText);
	cin >> a;
	position.Y = startPosY + 4;
	SetConsoleCursorPosition(hstdout, position);
	SetConsoleTextAttribute(hstdout, colorSignatureText);
	printf("b = ");
	SetConsoleTextAttribute(hstdout, colorAccentText);
	cin >> b;
	position.Y = startPosY + 6;
	SetConsoleCursorPosition(hstdout, position);
	SetConsoleTextAttribute(hstdout, colorPrimaryText);
	printf("1) Метод биссекции");
	do { 
		c = (b + a) / 2; 
		if (f(a) * f(c) < 0) 
			b = c; 
		else a = c; 
	} while ((b - a) > e);
	position.Y = startPosY + 8;
	SetConsoleCursorPosition(hstdout, position);
	SetConsoleTextAttribute(hstdout, colorSignatureText);
	cout << "Корень: x = " << c;

	position.Y = startPosY + 10;
	SetConsoleCursorPosition(hstdout, position);
	SetConsoleTextAttribute(hstdout, colorPrimaryText);
	printf("2) Метод хорд");
	do { 
		c = (b * f(a) - a * f(b)) / (f(a) - f(b)); 
		if (f(a) * f(c) < 0) 
			b = c; 
		else a = c; 
	} while (fabs(f(c)) > e);
	position.Y = startPosY + 12;
	SetConsoleCursorPosition(hstdout, position);
	SetConsoleTextAttribute(hstdout, colorSignatureText);
	cout << "Корень: x = " << c;
	_getch();
}

void resizeConsoleWindow(HANDLE handle, int width, int height);

void selectRGR(int position) {
	switch (position) {
	case 0: aboutAuthor(); system("cls"); break; 
	case 1: splashScreen(); system("cls"); break;
	case 2: functions(); system("cls"); break; 
	case 3: graphics(); SystemClear(); break;
	case 4: equation(); system("cls"); break; 
	case 5: integral(); system("cls"); break; 
	case 6: exit(0);
	}
}

void selectCP(int position) {
	switch (position) {
	case 0: aboutAuthor(); system("cls"); break;
	case 1: splashScreen(); system("cls"); break;
	case 2: toGameMenu(); system("cls"); break;
	case 3: menuHandbook(); system("cls"); break;
	case 4: musicBox(); system("cls"); break;
	case 5: drawingSynthesizer(); system("cls"); break;
	case 6: exit(0);
	}
}

void resizeConsoleWindow(HANDLE handle, int width, int height) {
	COORD newWindow = { width, height };
	SMALL_RECT srcWindow = { 0, 0, newWindow.X - 1, newWindow.Y - 1 };
	SMALL_RECT minWindow = { 0, 0, 0, 0 };
	SetConsoleWindowInfo(handle, true, &minWindow);
	SetConsoleScreenBufferSize(handle, newWindow);
	SetConsoleWindowInfo(handle, true, &srcWindow);
}

int main() {
	setlocale(LC_CTYPE, "rus");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	resizeConsoleWindow(handle, 100, 50);
	WORD active = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	WORD noActive = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	//char linesRGR[][20] = { "Автор", "Заставка", "Таблица", "Графики", "Уравнение", "Интеграл", "Выход" };
	char linesCP[][25] = { "Автор", "Заставка", "Морской бой", "Справочник", "Музыкальная шкатулка", "Синтезатор", "Выход" };
	COORD coordinate;
	int position = 0, lastItemMenu = 7;
	char code;
	while (true) {
		system("cls");
		for (int i = 0; i < lastItemMenu; i++) {
			if (position == i)
				SetConsoleTextAttribute(handle, active);
			else
				SetConsoleTextAttribute(handle, noActive);
			coordinate.X = 25; coordinate.Y = 5 + i * 2;
			SetConsoleCursorPosition(handle, coordinate);
			//cout << i + 1 << ") " << linesRGR[i] << endl;
			cout << i + 1 << ") " << linesCP[i] << endl;
		}
		code = _getch();
		if (code == 72) {
			if (position == 0) position = lastItemMenu - 1;
			else position--;
		}
		if (code == 80) {
			if (position == lastItemMenu - 1) position = 0;
			else position++;
		}
		if (code == 13) 
			//selectRGR(position);
			selectCP(position);
	}
	return 0;
}