// https://acmp.ru/index.asp?main=task&id_task=37

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    long double q;
    cin >> n >> q;
    bool canwe = true;
    for(int i = 0; i < n; i++)
    {
        long double x, y, ax, ay;
        cin >> x >> y >> ax >> ay;
        long double s = sqrt(x * x + y * y);
        long double as = sqrt(ax * ax + ay * ay);
        if(as != q * s && as > q * s - 0.00000000001) canwe = false;
    }
    if(canwe) cout <<"Yes";
    else cout << "No";
}