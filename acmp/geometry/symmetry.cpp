// https://acmp.ru/index.asp?main=task&id_task=28

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    long long int x1, y1, x2, y2;
    fin >> x1 >> y1 >> x2 >> y2;
    long long int x, y;
    fin >> x >> y;
    ofstream fout("output.txt");
    if(x1 == x2) fout << x - 2 * (x - x1) << " " << y;
    else if(y1 == y2) fout << x << " " << y - 2 * (y - y1);
    else
    {
        double k = (y1 - y2) / (x1 - x2);
        double b = y1 - k * x1;
        double k2 = (-1) / k;
        double b2 = y - k2 * x;
        double xc = (b - b2) / (k2 - k);
        double yc = k * xc + b;
        double xans = x - 2 * (x - xc);
        double yans = y - 2 * (y - yc);
        fout << xans << " " << yans;
    }
}