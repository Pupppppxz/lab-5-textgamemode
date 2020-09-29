#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
void gotoxy(int, int);
void draw_ship(int, int);
void erase_ship(int, int);
void set_color(int, int);
void set_cursor(bool);
void draw_bullet(int, int);
void bullet_ship(int, int);

int main()
{
    set_cursor(0);
    
    char ch = ' ';
    int movee[2], x = 38, y = 20, bullet[5];
    int bullet_x[5];
    int bullet_y[5];
    draw_ship(x, y);
    
    for (int i = 0; i < 5; i++)
    {
        bullet[i] = 0;
    }

    do {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 'w')
            {
                movee[0] = 1;
            }
            if (ch == 'a')
            {
                movee[0] = 2;
            }
            if (ch == 'd')
            {
                movee[0] = 3;
            }
            if (ch == 's')
            {
                movee[0] = 4;
            }
            if (ch == ' ') 
            {
                for (int i = 0; i < 5; i++)
                {
                    if (bullet[i] == 0) 
                    {
                        bullet[i] = 1;
                        bullet_x[i] = x;
                        bullet_y[i] = y - 2;
                        draw_bullet(bullet_x[i], bullet_y[i]);
                        break;
                    }
                }
            }
            

            fflush(stdin);

        }
        if (movee[0] == 1)
        {
            erase_ship(x, y), draw_ship(x, y);
        }
        if (movee[0] == 3 && x < 113)
        {
            erase_ship(x, y), draw_ship(++x, y);
        }
        if (movee[0] == 2 && x > 0)
        {
            erase_ship(x, y), draw_ship(--x, y);
        }
        if (movee[0] == 4)
        {
            erase_ship(x, y), draw_ship(x, y);
        }
        for (int i = 0; i < 5; i++)
        {
            if (bullet[i] == 1)
            {
                bullet_ship(bullet_x[i], bullet_y[i]);
                bullet_y[i] = bullet_y[i] - 1;
                if (bullet_y[i] > 0)
                {
                    draw_bullet(bullet_x[i], bullet_y[i]);
                }
                else 
                {
                    bullet[i] = 0;
                }
            }
        }
        Sleep(100);
        set_color(2, 0);
    } while (ch != 'x');

    return 0;
}
void gotoxy(int x, int y)
{
    COORD c = { x , y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
    set_cursor(0);
    set_color(2, 4);
    gotoxy(x, y); printf(" <-0-> ");
}
void erase_ship(int x, int y)
{
    set_color(0, 0);
    gotoxy(x, y); printf("       ");
}
void set_color(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void set_cursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}
void draw_bullet(int x, int y)
{
    set_color(1, 0);
    gotoxy(x, y);
    printf(" < ^ > ");

}
void bullet_ship(int x, int y)
{
    set_color(0, 0);
    gotoxy(x, y); 
    printf("        ");
}
