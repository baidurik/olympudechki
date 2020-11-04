// https://acmp.ru/index.asp?main=task&id_task=102
#include <bits/stdc++.h>
using namespace std;

int double_area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return abs((x1 - x2) * (y3 - y2) - (y1 - y2) * (x3 - x2));
}

bool point_in(double xp, double yp, double x1, double y1, double x2, double y2, double x3, double y3)
{
    double sqex = double_area(x1, y1, x2, y2, x3, y3);
    double sq1 = double_area(x1, y1, x2, y2, xp, yp);
    double sq2 = double_area(x1, y1, x3, y3, xp, yp);
    double sq3 = double_area(x2, y2, x3, y3, xp, yp);
    if(sq1 + sq2 + sq3 == sqex) return true;
    return false;
}

int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int x4, y4;
    fin >> x1 >> y1 
        >> x2 >> y2 
        >> x3 >> y3 
        >> x4 >> y4;
    if(point_in(x4, y4, x1, y1, x2, y2, x3, y3)) fout << "In";
    else fout << "Out";
}