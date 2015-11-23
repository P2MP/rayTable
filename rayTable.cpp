#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <conio.h>

using namespace std;

const short tsize_x = 30;
const short tsize_y = 15;
string rayTable[tsize_y][tsize_x];

int getx()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h,&csbi);
    return csbi.dwCursorPosition.X;
}
int gety()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h,&csbi);
    return csbi.dwCursorPosition.Y;
}
COORD getxy()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h,&csbi);
    return csbi.dwCursorPosition;
}
void gotoxy(COORD coord)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int strToCoordX(string str)
{
    char p0[100];
    int coord = -1;
    for (int i = 0; i < tsize_x; i++)
    {
        if (i < 10)
        {
            p0[i] = i + 48;
        }
        if (i >= 10 && i < 36)
        {
            p0[i] = i + 87;
        }
        if (i >= 36)
        {
            p0[i] = i + 29;
        }
        if (str[0] == p0[i])
        {
            coord = i;
        }
    }
    return coord;
}
int strToCoordY(string str)
{
    char p0[100];
    int coord = -1;
    for (int i = 0; i < tsize_y; i++)
    {
        if (i < 10)
        {
            p0[i] = i + 48;
        }
        if (i >= 10 && i < 36)
        {
            p0[i] = i + 87;
        }
        if (i >= 36)
        {
            p0[i] = i + 29;
        }
        if (str[0] == p0[i])
        {
            coord = i;
        }
    }
    return coord;
}
void rayTablePrint()
{
    char p0[100];
    for (int i = 0; i < tsize_y; i++)
    {
        for (int j = 0; j < tsize_x; j++)
        {
            cout << rayTable[i][j];
        }
        if (i < 10)
        {
            p0[i] = i + 48;
        }
        if (i >= 10 && i < 36)
        {
            p0[i] = i + 87;
        }
        if (i >= 36)
        {
            p0[i] = i + 29;
        }
        cout << " " << p0[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < tsize_x; i++)
    {
        if (i < 10)
        {
            p0[i] = i + 48;
        }
        if (i >= 10 && i < 36)
        {
            p0[i] = i + 87;
        }
        if (i >= 36)
        {
            p0[i] = i + 29;
        }
        cout << p0[i];
    }
    cout << endl;
}
void rayTableClear()
{
    for (int i = 0; i < tsize_y; i++)
    {
        for (int j = 0; j < tsize_x; j++)
        {
            rayTable[i][j] = '.';
        }
    }
}
int main()
{
    string xIn,yIn;
    int xCoord,yCoord;
    COORD cursorPos;
    rayTableClear();
    rayTablePrint();
    cursorPos = getxy();
    for(int j = 0; j == 0;)
    {
        do
        {
            cout << endl << "Podaj wspolrzedna x: ";
            xIn = getch();
            cout << xIn << endl;
            cout << "Podaj wspolrzedna y: ";
            yIn = getch();
            cout << yIn << endl;
            xCoord = strToCoordX(xIn);
            yCoord = strToCoordY(yIn);
            if(xCoord == -1 || yCoord == -1)
            {
                gotoxy(cursorPos);
                for(int i = 0; i < 400; i++)
                {
                    cout << " ";
                }
                gotoxy(cursorPos);
                cout << endl << "Blad";
            }else
            {
                gotoxy(cursorPos);
                for(int i = 0; i < 400; i++)
                {
                    cout << " ";
                }
                rayTable[yCoord][xCoord] = '*';
            }
        }
        while(xCoord == -1 || yCoord == -1);
        COORD coord00;
        coord00.X = 0;
        coord00.Y = 0;
        gotoxy(coord00);
        rayTablePrint();
    }
    return 0;
}
