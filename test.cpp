#include <iostream>
#include <cmath>
#include <vector>
#include "Figures.h"
#include "test.h"

vector<Figure*> listOfFigures;

void test()
{
    cout << "Testy funkcji dla klasy Point : " << endl;

    Point a ( 10 , 5 );
    a.showPoint();

    a.tranByVec( 6, 2.5 );
    cout << "Translacja o wektor : ";
    a.showPoint();

    a.rot( 3.14159265358979323846/2 , 2, 3 );
    cout << "Obrot wzgledem punktu : ";
    a.showPoint();

    a.scale( 3, 2, 3 );
    cout << "Skalowanie wzgledem punktu : ";
    a.showPoint();

    cout << endl;

    string n1 = "Odc1";

    LineSeg l ( Point( 1 , 8), Point( 2 , 7 ), n1 );
    cout << "Rysowanie odcinka : " << endl;
    l.draw();

    cout << "Translacja odcinka o wektor : " << endl;
    l.move( 6, 5 );
    l.draw();

    cout << endl;

    string n2 = "Odc2";

    cout << "Testowanie grupowania : " << endl;
    LineSeg k ( Point( 2, 3), Point( 4, 9 ), n2 );
    Group g ( "Grupa" );
    g.addFigure( &l );
    g.addFigure( &k );
    g.draw();

    cout << endl;

    cout << "Testowanie skalowania grupy wzgl punktu : " << endl;
    g.scale( 2, 1, 2 );
    g.draw();

    cout << endl;

    cout << "Testowanie translacji grupy o wektor : " << endl;
    g.move( 3, 4 );
    g.draw();

    cout << endl;

    cout << "Testowanie obrotu grupy wzgl punktu : " << endl;
    g.rot( 3.14159265358979323846/2, 2, 3 );
    g.draw();

    cout << endl;

    cout << "Testowanie wyznaczania srodka : " << endl;
    l.draw();
    Point m = l.getCenter();
    m.showPoint();

    cout << "\nTestowanie skalowania odcinka wzgl punktu : " << endl;
    l.scale(1, 1, 2);
    l.draw();

    cout << endl;

    cout << "Testowanie obrotu odcinka wzgl srodka : " << endl;
    l.rotAroCen( 3.14159265358979323846/2 );
    l.draw();

    cout << endl;

    Point b ( 1, 8 );
    Point c ( 2, 12 );
    Point d ( -3, -4 );

    string n3 = "T1";

    Triangle t ( b, c, d, n3 );
    cout << "Testowanie rysowania trojkatu : " << endl;
    t.draw();

    cout << "\nTestowanie skalowania trojkata wzgl punktu : " << endl;
    t.scale(1, 1, 2);
    t.draw();

    cout << endl;

    cout << "Testowanie obrotu trojkata wzgl punktu : " << endl;
    t.rot( 3.14159265358979323846/2, 1, 2 );
    t.draw();

    cout << endl;

    Point e ( 2, 4);
    Point f ( 5, 6);

    string n4 = "R1";

    Rectangle r ( e, f, n4 );
    cout << "Testowanie rysowania prostokata : " << endl;
    r.draw();

    cout << "\nTestowanie skalowania prostokata wzgl punktu : " << endl;
    r.scale(1, 1, 2);
    r.draw();

    cout << endl;

    cout << "Testowanie obrotu prostokata wzgl punktu : " << endl;
    r.rot( 3.14159265358979323846/2, 1, 2 );
    r.draw();

    cout << endl;

    Point s ( 3, 5 );

    string n5 = "C1";

    Circle q ( s , 5, n5 );
    cout << "Testowanie rysowania okregu : " << endl;
    q.draw();

    cout << endl;

    cout << "Tesotwanie translacji okregu o wektor : " << endl;
    q.move( 6, 7 );
    q.draw();

    cout << endl;

    cout << "Testowanie skalowania okregu wzgl punktu : " << endl;
    q.scale( 3, 2, 4 );
    q.draw();

    cout << endl;

    cout<< "Testowanie skalowania ogregu wzgl srdoka: " << endl;
    q.scaleAroCen( 3 );
    q.draw();

    string n6 = "C2";

    
    Circle *p = new Circle ( s, 6, n6 );
    ListOfFigures listf;
    listf.list.push_back( p );

    for( auto &it : listf.list )
        it->draw();
    
    cout << endl;

    string nam = p->getName();

    cout << nam << endl;

    cout << endl << endl;
}
