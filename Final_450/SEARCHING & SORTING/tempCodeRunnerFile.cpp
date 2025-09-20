//Optimum location of point to minimize total distance

#include <bits/stdc++.h>
using namespace std;

//defining a point
class point{
    public:
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
};

//defining a line of   ax+by+c=0
class line{
    public:
    int a,b,c;
    line (){}
    line(int a,int b,int c):a(a),b(b),c(c){}
};

// calculate distance between two point
double dist(double x,double y,point p)
{
    return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
}

//compute total distance from all point and their sum
double compute(point p[],int n,line L,double X)
{
    double res=0;
    // calculate Y of chosen point by line eq
    double Y= -1*(L.a*X+L.c)/L.b;
    for (int i=0;i<n;i++)
    {
        res+=dist(X,Y,p[i]);
    }
    return res;
}

// ternary search to get optimum distance
double findOptimumCostUtil(point p[],int n ,line L)
{
    double low = INT_MIN;
    double high = INT_MAX;

    while(low<high)
    {
        double mid1 = low + (high-low) /3;
        double mid2 = high - (high-low) /3;

        //distance calculate function call
        double dist1= compute(p,n,L,mid1);
        double dist2= compute(p,n,L,mid2);

        if(dist1<dist2)
        {
            high = mid2;
        }
        else {
            low = mid1;
        }
    }
    return compute(p,n,L, (low+high)/2);
}

//converting 2D array input to point
double findOptimumCost(int points[][2],line L)
{
    point p[5];
    for(int i=0;i<5;i++)
    {
        p[i]= point(points[i][0],points[i][1]);
    }
    return findOptimumCostUtil(p,5,L);
}
int main()
{
    line L(1,-1,-3);
    int points[5][2]={ { -3, -2 }, { -1, 0 }, { -1, 2 }, { 1, 2 }, { 3, 4 }};

    cout << findOptimumCost(points,L)<<endl;
    return 0;
}