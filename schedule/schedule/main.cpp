#include "cal.h"
#include "study.h"
#include "data.h"
#include "settime.h"

HANDLE CIN = 0; // console input
HANDLE COUT = 0; // console output
enum Color { BLUE = 9, YELLOWGREEN, SKY, RED, PINK };

void fullscreen()
{
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void TC(int background, int text)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (background << 4) | text);
}

void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int be_input()
{
    INPUT_RECORD input_record;
    DWORD input_count;
    PeekConsoleInput(CIN, &input_record, 1, &input_count);
    return input_count;
}

int get_input(WORD* vkey, COORD* pos)
{
    INPUT_RECORD input_record;
    DWORD input_count;
    ReadConsoleInput(CIN, &input_record, 1, &input_count);
    switch (input_record.EventType) {
    case MOUSE_EVENT:
        if (pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(COUT, &csbi);
            *pos = input_record.Event.MouseEvent.dwMousePosition;
            pos->X -= csbi.srWindow.Left;
            pos->Y -= csbi.srWindow.Top;
            return MOUSE_EVENT;
        }
        break;
    }
    return 0;
}

int main(void) {
    
    CONSOLE_FONT_INFOEX cfi;                //글자크기지정
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 9;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);


    DWORD mode;
    WORD key;
    COORD pos;

    cal c;
    study d;
    cdata v;
    settime s;
    int n;

    int event;        // 마우스 이벤트에 이용
    int x;            // 마우스의 x좌표 저장소
    int y;            // 마우스의 y좌표 저장소

    CIN = GetStdHandle(STD_INPUT_HANDLE);
    COUT = GetStdHandle(STD_OUTPUT_HANDLE);

    // 마우스 활성화
    GetConsoleMode(CIN, &mode);
    SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

    gotoxy(41, 2);
    cout << "월";
    gotoxy(62, 2);
    cout << "월";
    gotoxy(83, 2);
    cout << "화";
    gotoxy(104, 2);
    cout << "수";
    gotoxy(125, 2);
    cout << "목";
    gotoxy(146, 2);
    cout << "금";
    gotoxy(167, 2);
    cout << "토";

    while (true) {
        c.set_cal();
        c.print_cal();

        s.gettime();
        s.Leapyear(2021);
        s.set_date();
        s.show();
        







        while (true)
        {
            if (be_input())
            {
                if (get_input(&key, &pos) != 0)
                {
                    MOUSE_EVENT;
                    x = pos.X; y = pos.Y;
                    gotoxy(x, y);
                    cout << x << "," << y << "/";

                    if (x > 97 && x < 111 && y>66 && y < 70)
                    {
                        system("cls");

                        gotoxy(41, 2);
                        cout << "월";
                        gotoxy(62, 2);
                        cout << "화";
                        gotoxy(83, 2);
                        cout << "수";
                        gotoxy(104, 2);
                        cout << "목";
                        gotoxy(126, 2);
                        cout << "금";

                        d.set_study();
                        d.print_study();
                        v.cdata_set();
                        v.cdata_store();
                    }
                }
            }
        }

        cin >> n;
        return 0;
    }
}