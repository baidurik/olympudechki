// https://acmp.ru/index.asp?main=task&id_task=12

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
 
int main()
{
    ifstream fin;
    fin.open("input.txt");
    long long n;
    fin >> n;
    long long ct = 0;
    for(int i = 0; i < n; i++)
    {
        long double x, y, x1, y1, x2, y2, x3, y3, x4, y4;
        fin >> x >> y >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if(x1 == x2 && x3 == x2 && x4 == x2 && y1 == y2 && y1 == y3 && y1 == y4)
        {
            if(x == x1 && y == y1) ct ++;
            continue;
        }
        if((x1 == x2 && x3 == x4 && y1 == y2 && y3 == y4) || (x1 == x4 && x3 == x2 && y1 == y4 && y3 == y2))
        {
            if(x1 != x3)
            {
                long double k = (y1 - y3) / (x1 - x3);
                if(k * x == y && (y - y1) * (y - y3) <= 0 && (x - x1) * (x - x3) <= 0) ct ++;
                continue;
            }
            else
            {
                if(x == x1 && (y - y1) * (y - y3) <= 0) ct ++;
                continue;
            }
        }
        if (x1 != x2)
        {
            long double k = (y1 - y2) / (x1 - x2);
            long double b1 = y1 - k * x1;
            long double b2 = y3 - k * x3;
            if((k * x + b1 - y) * (k * x + b2 - y) > 0)
                continue;
        }
        else
        {
            if((x - x1)*(x - x3) > 0 || (y - y1) * (y - y3) > 0) continue;
        }
        if(x2 != x3)
        {
            long double k2 = (y2 - y3) / (x2 - x3);
            long double b3 = y2 - k2 * x2;
            long double b4 = y4 - k2 * x4;
            if((k2 * x + b3 - y) * (k2 * x + b4 - y) > 0)
                continue;
        }
        else
        {
            if((x - x2) * (x - x4) > 0 || (y - y2) * (y - y4) > 0) continue;
        }
        ct ++;
    }
    ofstream fout;
    fout.open("output.txt");
    fout << ct;
}