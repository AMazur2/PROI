#include <iostream>
#include <cmath>
#include "Figures.h"
using namespace std;

Point::Point( const Point &p )
{
    x = p.x;
    y = p.y;
}

void Point::showPoint()
{
    cout << "Punkt o wspolrzednych: ( " << x << " , " << y << " )" << endl;
}

void Point::tranByVec( float x0, float y0 )
{
    x += x0;
    y += y0;
}

void Point::rot( float a, float x0, float y0 )
{
    float c = x - x0; // rotation relative to (0,0)
    float b = y - y0; // allows the following transformation

    if( x != 0 )
    x = c*cos( a ) - b*sin( a ); // using a formula
    y = c*sin( a ) + b*cos( a ); // of rotation matrix

    x += x0;
    y += y0;
}

void Point::scale( float x0, float y0, float f)
{
    float a = x - x0;
    float b = y - y0;

    x = f*a;
    y = f*b;

    x += x0;
    y += y0;
}

Figure::Figure() {};
Figure::~Figure() {};

string Figure::getName()
{
    return name;
}

void Figure::addVerticle( Point a)
{
    vertices.push_back( a );
}

void Figure::draw()
{
    cout << name << ": ";

    for( vector< Point >::iterator it = vertices.begin(); it != vertices.end(); ++it )
        cout <<"( " << it->x << " , " << it->y << " )" << "  ";

    cout << "Colour: " << colour << " ";

}

void Figure::scale( float x0, float y0, float factor )
{
    for ( auto &it : vertices )
       it.scale( x0, y0, factor );
}

void Figure::move( float a, float b )
{

    for ( auto &it : vertices){
        it.x += a;
        it.y += b;
    }

}

void Figure::setColour( string c )
{
    colour = c;
}

void Figure::rot( float angle, float x0, float y0 )
{
    for ( auto &it : vertices )
        it.rot( angle, x0, y0 );
}

Point Figure::getCenter()
{
    float sumx = 0;
    float sumy = 0;
    int number = 0;

    for ( auto &it : vertices ){
        sumx += it.x;
        sumy += it.y;
        number++;
    }

    float a = ( sumx / number );
    float b = ( sumy / number );

    Point p ( a, b );

    return p;
}

void Figure::rotAroCen( float angle )
{
    Point a = getCenter();
    Figure::rot( angle , a.x, a.y );

}

void Figure::scaleAroCen( float factor )
{
    Point a = getCenter();
    Figure::scale( a.x, a.y, factor );
}

LineSeg::LineSeg( Point a, Point b, string n, string c )
{

    vertices.push_back( a );
    vertices.push_back( b );
    name = n;
    colour = c;

}

void LineSeg::draw()
{

    cout << "Line segment: ";
    Figure::draw();
    cout << endl;

}

Triangle::Triangle( Point a, Point b, Point c, string n, string col )
{
    vertices.push_back( a );
    vertices.push_back( b );
    vertices.push_back( c );
    name = n;
    colour = col;
}

void Triangle::draw()
{
    cout << "Triangle: ";
    Figure::draw();
    cout << endl;
}

Rectangle::Rectangle( Point a, Point c, string n, string col )
{
    vertices.push_back( a );
    Point b ( c.x, a.y );
    vertices.push_back( b );
    vertices.push_back( c );
    Point d ( a.x, c.y );
    vertices.push_back( d );
    name = n;
    colour = col;
}

void Rectangle::draw()
{
    cout << "Rectangle: ";
    Figure::draw();
    cout << endl;
}

Circle::Circle( Point s, float r, string n, string c )
{
    if( r < 0 ) throw "Invalid parameter: negative radius";
    
    vertices.push_back( s );
    radius = r;
    name = n;
    colour = c;
}

void Circle::draw()
{
    cout << "Circle: ";
    Figure::draw();
    cout << "radius: " << radius << endl;
}

void Circle::scale (float x0, float y0, float f )
{
    Figure::scale( x0, y0, f );
    radius *= f;
}

void Circle::scaleAroCen( float factor )
{
    radius *= factor;
}

Group::Group ( string n )
{
    name = n;
}

void Group::draw()
{
    cout << endl << "Group: " << name << endl;
    for ( auto &figure : figures){
        figure->draw();
    }
}

void Group::addFigure ( Figure* f )
{
    figures.push_back( f );
}

void Group::scale( float x0, float y0, float factor )
{
    for ( auto &it : figures)
        it->scale( x0, y0, factor );
}

void Group::move( float a, float b )
{
    for ( auto &it : figures )
        it->move( a, b );
}

void Group::rot( float angle, float x0, float y0 )
{
    for ( auto &it : figures )
        it->rot( angle, x0, y0 );
}

void Group::setColour( string c )
{
    for( auto &it : figures)
        it->setColour( c );
}

ListOfFigures::~ListOfFigures()
{
    for( auto &it : list )
        delete it;
    list.clear();
}

void ListOfFigures::showList()
{
    for( auto &it: list )
        it->draw();
}

bool ListOfFigures::inList( string n )
{
    for ( auto &it: list ){
        string k = it->getName();
        if ( n == k ){
            return true;
        }
    }
    return false;
}

ListOfGroups::~ListOfGroups()
{
    for ( auto &it : listg ){
        for( auto &iterek : it->figures )
            iterek = nullptr;
        delete it;
    }   
}

void ListOfGroups::showList()
{
    for( auto &it: listg )
        it->draw();
}

bool ListOfGroups::inList( string n )
{
    for ( auto &it: listg ){
        string k = it->getName();
        if ( n == k ){
            return true;
        }
    }
    return false;
}