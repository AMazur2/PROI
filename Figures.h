#include <vector>
#include <cmath>
#include <vector>
using namespace std;



class Point
{

public:
    float x;
    float y;
    Point ( float x, float y ): x(x), y(y) {};
    Point ( const Point &p );
    void showPoint ();
    void tranByVec( float x0, float y0 );
    void rot( float angle, float x0, float y0 );
    void scale( float x0, float y0, float factor );
};

class Figure
{

protected:
    vector<Point> vertices;
    string colour;
    string name;

public:
    Figure();
    Figure ( string n, string c = "Black" ) : colour(c), name(n) {}
    ~Figure ();
    string getName();
    void addVerticle( Point a );
    virtual void draw();
    virtual void scale( float x0, float y0, float factor );
    virtual void move( float x, float y );
    virtual void setColour( string c );
    virtual void rot( float angle, float x0, float y0 );
    virtual Point getCenter();
    virtual void rotAroCen( float angle ); // rotate around center
    virtual void scaleAroCen( float factor ); // scale using center point
};

class LineSeg : public Figure
{

public:
    LineSeg( Point a, Point b, string name, string colour );
   void draw() override;

};

class Triangle : public Figure
{

public:
    Triangle( Point a, Point b, Point c, string name, string colour );
    void draw() override;

};

class Rectangle : public Figure
{

public:
    Rectangle ( Point a, Point b, string name, string colour ); // point a and b must lie on diagonal
    void draw() override;

};

class Circle : public Figure
{

private:
    float radius;

public:
    Circle ( Point s, float r, string name, string colour );
    void draw() override;
    void scale ( float x0, float y0, float factor) override;
    void scaleAroCen( float favtor ) override;
};

class Group : public Figure
{

public:
    vector<Figure*> figures;
    Group ( string n );
    ~Group() {};
    void draw() override;
    void addFigure( Figure *f );
    void scale( float x0, float y0, float factor ) override;
    void move( float a, float b ) override;
    void rot( float angle, float x0, float y0 ) override;
    void setColour( string c) override;

};

class ListOfFigures : public Figure
{

public:
    vector<Figure*> list;
    ListOfFigures() {};
    ~ListOfFigures();   
    void showList();
    bool inList( string n ); 
};

class ListOfGroups : public Figure
{

public:
    vector<Group*> listg;
    ListOfGroups() {};
    ~ListOfGroups();   
    void showList();
    bool inList( string n ); 
};
