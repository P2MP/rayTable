#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <conio.h>

using namespace std;

const short tsize_x = 30;
const short tsize_y = 15;
string rayTable[tsize_y][tsize_x];


int validation(string convert)
{
    int i;
    stringstream ss(convert);
    ss >> i;
    if(ss.fail())
    {
        return -1;
    }
    else
    {
        return i;
    }

}
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
COORD getCoord()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h,&csbi);
    return csbi.dwCursorPosition;
}
void gotoCoord(COORD coord)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
COORD strToIndex(string strx, string stry)
{
    char px[100];
    char py[100];
    COORD coord;
    coord.X = -1;
    coord.Y = -1;

    for (int i = 0; i < tsize_y; i++)
    {
        if (i < 26)
        {
            py[i] = i + 97;
        }
        if (i >= 26)
        {
            py[i] = i + 39;
        }
        if (stry[0] == py[i])
        {
            coord.Y = i;
        }
    }
    for (int i = 0; i < tsize_x; i++)
    {
        if (i < 26)
        {
            px[i] = i + 97;
        }
        if (i >= 26)
        {
            px[i] = i + 39;
        }
        if (strx[0] == px[i])
        {
            coord.X = i;
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
        if (i < 26)
        {
            p0[i] = i + 97;
        }
        if (i >= 26)
        {
            p0[i] = i + 39;
        }
        cout << " " << p0[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < tsize_x; i++)
    {
        if (i < 26)
        {
            p0[i] = i + 97;
        }
        if (i >= 26)
        {
            p0[i] = i + 39;
        }
        cout << p0[i];
    }
    cout << endl << endl;
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
void rayDraw(COORD rayOrigin, short rayDirection)
{
    COORD rayCursor = rayOrigin;

    switch (rayDirection)
    {
    case 2:
        {
            while (rayCursor.Y < tsize_y)
            {
                rayTable[rayCursor.Y][rayCursor.X] = '1';
                rayCursor.Y++;
            }
            break;
        }
    case 4:
        {
            while (rayCursor.X >= 0)
            {
                rayTable[rayCursor.Y][rayCursor.X] = '1';
                rayCursor.X--;
            }
            break;
        }
    case 6:
        {
            while (rayCursor.X < tsize_x)
            {
                rayTable[rayCursor.Y][rayCursor.X] = '1';
                rayCursor.X++;
            }
            break;
        }
    case 8:
        {
            while (rayCursor.Y >= 0)
            {
                rayTable[rayCursor.Y][rayCursor.X] = '1';
                rayCursor.Y--;
            }
            break;
        }
    case 1:
        {
            while (rayCursor.Y < tsize_y && rayCursor.X >= 0)
            {
                rayTable[rayCursor.Y][rayCursor.X] = '1';
                rayCursor.Y++;
                rayCursor.X--;
            }
            break;
        }
    case 3:
        {
            while (rayCursor.Y < tsize_y && rayCursor.X < tsize_x)
            {
                rayTable[rayCursor.Y][rayCursor.X] = '1';
                rayCursor.Y++;
                rayCursor.X++;
            }
            break;
        }
    case 7:
        {
            while (rayCursor.Y >= 0 && rayCursor.X >= 0)
            {
                rayTable[rayCursor.Y][rayCursor.X] = '1';
                rayCursor.Y--;
                rayCursor.X--;
            }
            break;
        }
    case 9:
        {
            while (rayCursor.Y >= 0 && rayCursor.X < tsize_x)
            {
                rayTable[rayCursor.Y][rayCursor.X] = '1';
                rayCursor.Y--;
                rayCursor.X++;
            }
            break;
        }
    default:
        {
            rayTable[rayOrigin.Y][rayOrigin.X] = '.';
        }
    }
}
int main()
{
    string xIn,yIn,rayDirectionIn;
    int rayDirection;
    COORD cursorPos,rayTableIndex;

    rayTableClear();
    rayTablePrint();
    cursorPos = getCoord();
    for(int j = 0; j == 0;)
    {
        do
        {
            cout << "Podaj wspolrzedna x: ";
            xIn = getch();
            cout << xIn << endl;
            cout << "Podaj wspolrzedna y: ";
            yIn = getch();
            cout << yIn << endl;
            rayTableIndex = strToIndex(xIn, yIn);
            if(rayTableIndex.X == -1 || rayTableIndex.Y == -1)
            {
                gotoCoord(cursorPos);
                for(int i = 0; i < 400; i++)
                {
                    cout << " ";
                }
                gotoCoord(cursorPos);
                cout << endl << "Podano zla wartosc!" << endl;
            }else
            {
                gotoCoord(cursorPos);
                for(int i = 0; i < 400; i++)
                {
                    cout << " ";
                }
                rayTable[rayTableIndex.Y][rayTableIndex.X] = '*';
                gotoxy(0,0);
                rayTablePrint();
            }
        }
        while(rayTableIndex.X == -1 || rayTableIndex.Y == -1);
        cout << "W jakim kierunku skierowac laser?: ";
        rayDirectionIn = getch();
        cout << rayDirectionIn << endl;
        rayDirection = validation(rayDirectionIn);
        rayDraw(rayTableIndex, rayDirection);
        gotoxy(0,0);
        rayTablePrint();
        for(int i = 0; i < 400; i++)
        {
            cout << " ";
        }
        gotoCoord(cursorPos);
    }
    return 0;
}
