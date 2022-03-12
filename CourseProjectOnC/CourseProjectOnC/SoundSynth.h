#include <conio.h>
#include <windows.h>

struct octave { DWORD Do, Re, Mi, Fa, Sol, La, Si; };

void drawingSynthesizer();
void notActiveKeyDo(HBRUSH brush);
void notActiveKeyRe(HBRUSH brush);
void notActiveKeyMi(HBRUSH brush);
void notActiveKeyFa(HBRUSH brush);
void notActiveKeySol(HBRUSH brush);
void notActiveKeyLa(HBRUSH brush);
void notActiveKeySi(HBRUSH brush);
void notActiveKeyDodies(HBRUSH brush);
void notActiveKeyRedies(HBRUSH brush);
void notActiveKeyFadies(HBRUSH brush);
void notActiveKeySoldies(HBRUSH brush);
void notActiveKeyLadies(HBRUSH brush);

void keyPressSynth() {
	HBRUSH brushBlack11 = CreateSolidBrush(RGB(50, 50, 50));
	HBRUSH brushBlack21 = CreateSolidBrush(RGB(25, 25, 25));
	HBRUSH brushWhite1 = CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH brushBlack12 = CreateSolidBrush(RGB(70, 70, 70));
	HBRUSH brushBlack22 = CreateSolidBrush(RGB(50, 50, 50));
	HBRUSH brushWhite2 = CreateSolidBrush(RGB(230, 230, 230));

	octave smalloct = { 131, 147, 165, 175, 196, 220, 247 };
	octave first = { 262, 294, 330, 349, 392, 440, 494 };
	while (1)
	{
		if (_kbhit())
		{
			char code = _getch();
			//cout << (int) code << endl;
			switch (code)
			{
			case 97: case -28:
				Beep(first.Do, 250);
				notActiveKeyDo(brushWhite2);
				notActiveKeyDodies(brushBlack21);
				Sleep(500);
				break;
			case 115: case -21:
				Beep(first.Re, 250);
				notActiveKeyRe(brushBlack12);
				notActiveKeyDodies(brushBlack21);
				notActiveKeyRedies(brushBlack21);
				Sleep(500);
				break;
			case 100: case -94:
				Beep(first.Mi, 250);
				notActiveKeyMi(brushWhite2);
				notActiveKeyRedies(brushBlack21);
				Sleep(500);
				break;
			case 102: case -96:
				Beep(first.Fa, 250);
				notActiveKeyFa(brushBlack12);
				notActiveKeyFadies(brushBlack21);
				Sleep(500);
				break;
			case 103: case -81:
				Beep(first.Sol, 250);
				notActiveKeySol(brushWhite2);
				notActiveKeyFadies(brushBlack21);
				notActiveKeySoldies(brushBlack21);
				Sleep(500);
				break;
			case 104: case -32:
				Beep(first.La, 250);
				notActiveKeyLa(brushBlack12);
				notActiveKeySoldies(brushBlack21);
				notActiveKeyLadies(brushBlack21);
				Sleep(500);
				break;
			case 106: case -82:
				Beep(first.Si, 250);
				notActiveKeySi(brushWhite2);
				notActiveKeyLadies(brushBlack21);
				Sleep(500);
				break;
			case 107: case -85:
				Beep(smalloct.Do, 250);
				Sleep(500);
				break;
			case 108: case -92:
				Beep(smalloct.Re, 250);
				Sleep(500);
				break;
			}
			if (code == 27) exit(1);
			drawingSynthesizer();
		}
	}
	//_getch();
}

void drawingSynthesizer() {
	HBRUSH brushBlack1 = CreateSolidBrush(RGB(50, 50, 50));
	HBRUSH brushBlack2 = CreateSolidBrush(RGB(25, 25, 25));
	HBRUSH brushWhite = CreateSolidBrush(RGB(255, 255, 255));

	notActiveKeyDo(brushWhite);
	notActiveKeyRe(brushBlack1);
	notActiveKeyDodies(brushBlack2);
	notActiveKeyMi(brushWhite);
	notActiveKeyFa(brushBlack1);
	notActiveKeyRedies(brushBlack2);
	notActiveKeySol(brushWhite);
	notActiveKeyLa(brushBlack1);
	notActiveKeyFadies(brushBlack2);
	notActiveKeySoldies(brushBlack2);
	notActiveKeySi(brushWhite);
	notActiveKeyLadies(brushBlack2);

	keyPressSynth();
}

HFONT setFont() {
	LOGFONT font;
	font.lfHeight = 25;		// Устанавливает высоту шрифта или символа
	font.lfWidth = 25;		// Устанавливает среднюю ширину символов в шрифте
	font.lfEscapement = 0;	// Устанавливает угол, между вектором наклона и осью X устройства
	font.lfItalic = 0;		// Устанавливает курсивный шрифт
	font.lfUnderline = 0;	// Устанавливает подчеркнутый шрифт
	font.lfStrikeOut = 0;	// Устанавливает зачеркнутый шрифт
	HFONT hfont;
	hfont = ::CreateFontIndirect(&font);
	return hfont;
}

void notActiveKeyDo(HBRUSH brush) {
	HDC hdc = GetDC(GetConsoleWindow());
	WORD nSize;	TCHAR str[100];

	HFONT hfont = setFont();
	SelectObject(hdc, hfont);

	SelectObject(hdc, brush);
	Rectangle(hdc, 0, 0, 90, 1000);

	nSize = wsprintf(str, TEXT("%c"), 'a');
	SetTextColor(hdc, RGB(0, 0, 0));		// цвет текста
	SetBkColor(hdc, RGB(255, 255, 255));	// цвет фона
	TextOut(hdc, 20, 250, str, nSize);
}

void notActiveKeyRe(HBRUSH brush) {
	HDC hdc = GetDC(GetConsoleWindow());
	WORD nSize;	TCHAR str[100];

	HFONT hfont = setFont();
	SelectObject(hdc, hfont);

	SelectObject(hdc, brush);
	Rectangle(hdc, 90, 0, 180, 1000);

	nSize = wsprintf(str, TEXT("%c"), 's');
	SetTextColor(hdc, RGB(255, 255, 255));	// цвет текста
	SetBkColor(hdc, RGB(50, 50, 50));		// цвет фона
	TextOut(hdc, 110, 250, str, nSize);
}

void notActiveKeyMi(HBRUSH brush) {
	HDC hdc = GetDC(GetConsoleWindow());
	WORD nSize;	TCHAR str[100];

	HFONT hfont = setFont();
	SelectObject(hdc, hfont);

	SelectObject(hdc, brush);
	Rectangle(hdc, 180, 0, 270, 1000);

	nSize = wsprintf(str, TEXT("%c"), 'd');
	SetTextColor(hdc, RGB(0, 0, 0));		// цвет текста
	SetBkColor(hdc, RGB(255, 255, 255));	// цвет фона
	TextOut(hdc, 200, 250, str, nSize);
}

void notActiveKeyFa(HBRUSH brush) {
	HDC hdc = GetDC(GetConsoleWindow());
	WORD nSize;	TCHAR str[100];

	HFONT hfont = setFont();
	SelectObject(hdc, hfont);

	SelectObject(hdc, brush);
	Rectangle(hdc, 270, 0, 360, 1000);

	nSize = wsprintf(str, TEXT("%c"), 'f');
	SetTextColor(hdc, RGB(255, 255, 255));	// цвет текста
	SetBkColor(hdc, RGB(50, 50, 50));		// цвет фона
	TextOut(hdc, 290, 250, str, nSize);
}

void notActiveKeySol(HBRUSH brush) {
	HDC hdc = GetDC(GetConsoleWindow());
	WORD nSize;	TCHAR str[100];

	HFONT hfont = setFont();
	SelectObject(hdc, hfont);

	SelectObject(hdc, brush);
	Rectangle(hdc, 360, 0, 450, 1000);

	nSize = wsprintf(str, TEXT("%c"), 'g');
	SetTextColor(hdc, RGB(0, 0, 0));		// цвет текста
	SetBkColor(hdc, RGB(255, 255, 255));	// цвет фона
	TextOut(hdc, 380, 250, str, nSize);
}

void notActiveKeyLa(HBRUSH brush) {
	HDC hdc = GetDC(GetConsoleWindow());
	WORD nSize;	TCHAR str[100];

	HFONT hfont = setFont();
	SelectObject(hdc, hfont);

	SelectObject(hdc, brush);
	Rectangle(hdc, 450, 0, 540, 1000);

	nSize = wsprintf(str, TEXT("%c"), 'h');
	SetTextColor(hdc, RGB(255, 255, 255));	// цвет текста
	SetBkColor(hdc, RGB(50, 50, 50));		// цвет фона
	TextOut(hdc, 470, 250, str, nSize);
}

void notActiveKeySi(HBRUSH brush) {
	HDC hdc = GetDC(GetConsoleWindow());
	WORD nSize;	TCHAR str[100];

	HFONT hfont = setFont();
	SelectObject(hdc, hfont);

	SelectObject(hdc, brush);
	Rectangle(hdc, 540, 0, 630, 1000);

	nSize = wsprintf(str, TEXT("%c"), 'j');
	SetTextColor(hdc, RGB(0, 0, 0));		// цвет текста
	SetBkColor(hdc, RGB(255, 255, 255));	// цвет фона
	TextOut(hdc, 560, 250, str, nSize);
}

void notActiveKeyDodies(HBRUSH brush) {
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN penWhite = CreatePen(PS_DASHDOT, 2, RGB(200, 200, 200));
	WORD nSize;	TCHAR str[100];

	HFONT hfont = setFont();
	SelectObject(hdc, hfont);

	SelectObject(hdc, penWhite);
	SelectObject(hdc, brush);
	Rectangle(hdc, 60, 0, 120, 200);
}

void notActiveKeyRedies(HBRUSH brush) {
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN penWhite = CreatePen(PS_DASHDOT, 2, RGB(200, 200, 200));
	WORD nSize;	TCHAR str[100];

	HFONT hfont = setFont();
	SelectObject(hdc, hfont);

	SelectObject(hdc, penWhite);
	SelectObject(hdc, brush);
	Rectangle(hdc, 150, 0, 210, 200);
}
void notActiveKeyFadies(HBRUSH brush) {
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN penWhite = CreatePen(PS_DASHDOT, 2, RGB(200, 200, 200));
	WORD nSize;	TCHAR str[100];

	HFONT hfont = setFont();
	SelectObject(hdc, hfont);

	SelectObject(hdc, penWhite);
	SelectObject(hdc, brush);
	Rectangle(hdc, 330, 0, 390, 200);
}

void notActiveKeySoldies(HBRUSH brush) {
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN penWhite = CreatePen(PS_DASHDOT, 2, RGB(200, 200, 200));
	WORD nSize;	TCHAR str[100];

	HFONT hfont = setFont();
	SelectObject(hdc, hfont);

	SelectObject(hdc, penWhite);
	SelectObject(hdc, brush);
	Rectangle(hdc, 420, 0, 480, 200);
}

void notActiveKeyLadies(HBRUSH brush) {
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN penWhite = CreatePen(PS_DASHDOT, 2, RGB(200, 200, 200));
	WORD nSize;	TCHAR str[100];

	HFONT hfont = setFont();
	SelectObject(hdc, hfont);

	SelectObject(hdc, penWhite);
	SelectObject(hdc, brush);
	Rectangle(hdc, 510, 0, 570, 200);
}