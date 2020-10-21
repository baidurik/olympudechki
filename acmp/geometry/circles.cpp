// https://acmp.ru/index.asp?main=task&id_task=26

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
int main()
{
    double x1, y1, r1, x2, y2, r2;
    ifstream fin;
    fin.open("input.txt");
    fin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    ofstream fout;
    fout.open("output.txt");
    double s = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if(s <= (r1 + r2) && (s >= abs(r1 - r2)))
        fout << "YES";
    else
        fout << "NO";
}