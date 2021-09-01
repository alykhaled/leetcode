#include <iostream>
using namespace std;

class Figure
{

private: int ID;
public:
    Figure(int id = 0)
    { ID = id; }
    double getID()
    { return ID; }
    double getArea()
    { return 0; }
};

class Rect : public Figure
{
    double L,W;
    public:
    Rect(int id, double l, double w)
    { ID=id; L=l; W=w; }
    Rect( )
    { ID=0; L=2; W=1; }
    double getArea()
    {
        return L*W;
    }
};