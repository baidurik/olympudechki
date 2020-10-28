// https://acmp.ru/index.asp?main=task&id_task=69
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, a;
    fin >> n >> a;
    float pi = 3.1415926;
    long double central_corner = pi / n;
    long double delta = (1 - cos(central_corner)) * (a / (2 * sin(central_corner)));
    if(delta < 1) fout << "YES";
    else fout << "NO";
}