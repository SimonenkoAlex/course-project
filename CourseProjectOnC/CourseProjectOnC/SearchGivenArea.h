#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>

HANDLE hstdinput;
DWORD len, actlen;
BOOL rci;
INPUT_RECORD  inputbuf;
CONSOLE_SCREEN_BUFFER_INFO ScreenBufInfo;
const int k = 10, radius = 10;

int readingMouseMovement(HANDLE hstdout, int randCoordX, int randCoordY) {
	hstdinput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleScreenBufferInfo(hstdout, &ScreenBufInfo);
	char mouseButtonText[] = "Mouse event detected";
	int x = 0, y = 0, x1 = 0 , y1 = 0;
	SetConsoleMode(hstdinput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	int x2 = (int) 1400 * randCoordX / 200;
	int y2 = (int) 900 * randCoordY / 75;
	int differenceX = labs(x1 - x2);
	int differenceY = labs(y1 - y2);

	HWND hwn = GetConsoleWindow();
	HDC hdc = GetDC(hwn);
	RECT rect; // прямоугольник клиентской области

	HPEN pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
	HBRUSH BRUSH = CreateSolidBrush(RGB(0, 0, 255));

	while (differenceX != 0 || differenceY != 0)
	{
		rci = ReadConsoleInput(hstdinput, &inputbuf, 1, &actlen);
		if (inputbuf.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			GetConsoleScreenBufferInfo(hstdout, &ScreenBufInfo);
			SetConsoleCursorPosition(hstdout, inputbuf.Event.MouseEvent.dwMousePosition);
			WriteFile(hstdout, mouseButtonText, sizeof(mouseButtonText), &actlen, NULL);
			char c[4];
			itoa(x, c, 10);
			WriteFile(hstdout, " X: ", 4, &actlen, NULL);
			WriteFile(hstdout, c, 3, &actlen, NULL);
			itoa(y, c, 10);
			WriteFile(hstdout, " Y: ", 4, &actlen, NULL);
			WriteFile(hstdout, c, 3, &actlen, NULL);
		}
		if (inputbuf.Event.MouseEvent.dwEventFlags == MOUSE_MOVED) 
		{
			SetConsoleCursorPosition(hstdout, inputbuf.Event.MouseEvent.dwMousePosition);
			x = inputbuf.Event.MouseEvent.dwMousePosition.X;
			y = inputbuf.Event.MouseEvent.dwMousePosition.Y;
			x1 = (int) 1400 * x / 200;
			y1 = (int) 900 * y / 75;
			Ellipse(hdc, x1 - radius, y1 - radius, x1 + radius, y1 + radius);
			GetClientRect(hwn, &rect);
			differenceX = labs(x1 - x2);
			differenceY = labs(y1 - y2);
			if (differenceX < 100 && differenceY < 100) {
				if (differenceX < 50 && differenceY < 50) {
					if (differenceX < 25 && differenceY < 25) {
						if (differenceX < 10 && differenceY < 10) {
							pen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
							BRUSH = CreateSolidBrush(RGB(255, 0, 0));
							Beep(392, 250);
						}
						else {
							pen = CreatePen(PS_SOLID, 5, RGB(225, 0, 100));
							BRUSH = CreateSolidBrush(RGB(225, 0, 100));
							Beep(349, 250);
						}
					}
					else {
						pen = CreatePen(PS_SOLID, 5, RGB(200, 0, 200));
						BRUSH = CreateSolidBrush(RGB(200, 0, 200));
						Beep(330, 250);
					}
				}
				else {
					pen = CreatePen(PS_SOLID, 5, RGB(100, 0, 225));
					BRUSH = CreateSolidBrush(RGB(100, 0, 225));
					Beep(294, 250);
				}
			}
			else {
				pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
				BRUSH = CreateSolidBrush(RGB(0, 0, 255));
				Beep(262, 250);
			}
			SelectObject(hdc, pen); SelectObject(hdc, BRUSH);
		}
	}
	DeleteObject(pen); DeleteObject(BRUSH);
	ReleaseDC(hwn, hdc);
	cout << "Область НАЙДЕНА !!!";
	return 0;
}