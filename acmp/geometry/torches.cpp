// https://acmp.ru/index.asp?main=task&id_task=55
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    float pi = 3.1415926;
    int x1, y1, x2, y2, r, s;
    fin >> x1 >> y1
        >> x2 >> y2
        >> r
        >> s;
    float dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if(dist >= 2 * r)
    {
        float square = 2 * pi * r * r;
        if(square - 0.000001 > s) fout << "YES";
        else fout << "NO";
    }
    else
    {
        float cosalpha = (dist / (2 * r));
        float alpha = acos(cosalpha) * 2;
        float spart = pi * r * r * alpha / (2 * pi);
        float stri = r * dist * sqrt(1 - cosalpha * cosalpha) / 2;
        float sseg = spart - stri;
        float square = 2 * pi * r * r - 2 * sseg;
        if(square - 0.000001 > s) fout << "YES";
        else fout << "NO";
    }
}