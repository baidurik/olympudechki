// https://acmp.ru/index.asp?main=task&id_task=90
#include <bits/stdc++.h>
using namespace std;

long double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

long double geron(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double s1 = dist(x1, y1, x2, y2);
    double s2 = dist(x1, y1, x3, y3);
    double s3 = dist(x2, y2, x3, y3);
    double p = (s1 + s2 + s3) / 2;
    return sqrt(p * (p - s1) * (p - s2) * (p - s3));
}

bool point_in(double xp, double yp, double x1, double y1, double x2, double y2, double x3, double y3)
{
    double sqex = geron(x1, y1, x2, y2, x3, y3);
    double sq1 = geron(x1, y1, x2, y2, xp, yp);
    double sq2 = geron(x1, y1, x3, y3, xp, yp);
    double sq3 = geron(x2, y2, x3, y3, xp, yp);
    if(sq1 && sq2 && sq3 && sq1 + sq2 + sq3 < sqex + 0.0001) return true;
    return false;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    double xn, yn;
    int k;
    fin >> xn >> yn 
        >> k;
    vector<int> ans;
    for(int i = 0; i < k; i++)
    {
        double x1, y1, x2, y2, x3, y3;
        fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if(point_in(xn, yn, x1, y1, x2, y2, x3, y3))
        {
            ans.push_back(i+1);
        }
    }
    fout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
    {
        fout << ans[i] << " ";
    }
}