#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const short tsize_x = 20;
const short tsize_y = 10;
string rayTable[tsize_y][tsize_x];

int validation(string convert)
{
    int i;
    stringstream ss(convert);
    ss >> i;
    if (ss.fail())
    {
        return 0;
    }
    else
    {
        return i;
    }

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
    rayTableClear();
    rayTablePrint();
    return 0;
}
