#include <iostream>
#include <cmath>
#include <limits>
#include "Figures.h"
#include "menu.h"

using namespace std;

void menu()
{

    cout << "\tHello!" << endl << endl;

    ListOfFigures lFig;

    ListOfGroups lG;

    int k;

    do{
        cout << "\tMain menu" << endl << endl;
        cout << "Please choose: " << endl;
        cout << "[1] to create a figure,\n[2] to activate an editor mode" << endl;
        cout << "[0] to exit a program." << endl;


        k = getInteger();

        cout << endl;

        switch( k )
        {
        case 1:
            createFigure( lFig );
            break;
        case 2:
            editMode( lFig, lG );
            break;
        case 0:
            cout << "Exciting. ";
            break;
        default:
            cout << "Don't know what to do!" << endl;
        break;
        }

    }while( k != 0);

    cout << "Thank you! Goodbye! " << endl;

}

int getInteger()
{

    int i;
    bool log_val = false;

    do{
        cin >> i;
        if ( cin.good() )
            log_val = true;
        else {
            cout << "Given characters are not a number." << endl;
            cout << "Enter an appropriate number" << endl;
            cin.clear ();
        }
        cin.ignore( numeric_limits<streamsize>::max(), '\n');
    } while ( !log_val );

    return i;

}

float getFloat()
{
    float i;
    bool log_val = false;

    do{
        cin >> i;
        if ( cin.good() )
            log_val = true;
        else {
            cout << "Given characters are not a number." << endl;
            cout << "Enter an appropriate number" << endl;
            cin.clear ();
        }
        cin.ignore( numeric_limits<streamsize>::max(), '\n');
    } while ( !log_val );

    return i;
}

void createFigure( ListOfFigures &lF )
{
    cout << endl << "\tCreator mode" << endl << endl;
    
    int i;
    
    do{

        cout << "Choose to create: \n[1] Line Segment, \n[2] Triangle," << endl;
        cout << "[3] Rectangle, \n[4] Circle, \n[5] Other figure, \n[0] to exit." << endl;

    
        i = getInteger();

        cout << endl;

        switch ( i )
        {
        case 0:
            cout << "Exiting the creator mode." << endl << endl; 
            break;
        case 1:
            createLineSeg( lF );
            cout << endl;
            break;
        case 2:
            createTriangle( lF );
            cout << endl;
            break;
        case 3:
            createRectangle( lF );
            cout << endl;
            break;
        case 4:
            createCircle( lF );
            cout << endl;
            break;
        case 5:
            createNewFigure( lF );
            cout << endl;
            break;
        default:
            cout << "Don't know what to do." << endl;
        break;
        }
    
    }while( i != 0 );
}

string createName( ListOfFigures &lF )
{
   string h;

    do{
        cout << "Enter a name of this figure: " << endl;

        cin >> h;

        if( lF.inList( h ) )
            cout << "This name is already in use!" << endl;
    }while( lF.inList( h ));

    return h;
}

string getColour()
{
    cout << "Please enter a colour: " << endl;
    
    string c;

    cin >> c;

    return c;
}

void createLineSeg( ListOfFigures &lF )
{
    cout << "Give coordinates of first point: " << endl;

    float a,b;
    a = getFloat();
    b = getFloat();

    cout << endl;

    Point p ( a, b );

    cout << "Give coordinates of second point : " << endl;

    float c,d;

    do{
    
        c = getFloat();
        d = getFloat();
        if ( ( c==a ) && (d == b) )
            cout << "You must give 2 diffrent points! " << endl;
    
    } while ( ( c==a ) && (d == b) );
    cout << endl;

    Point q ( c, d );

    string n = createName( lF );

    string col = getColour();

    LineSeg *l = new LineSeg ( p, q, n, col );

    lF.list.push_back( l );

    l->draw();

}

void createTriangle( ListOfFigures &lF )
{
    cout << "Please give coordinates of first point: " << endl;

    float a,b;
    a = getFloat();
    b = getFloat();

    cout << endl;

    Point p ( a, b );

    cout << "Please give coordinates of second point: " << endl;

    float c,d;

    do{
    
        c = getFloat();
        d = getFloat();
        if ( ( c==a ) && (d == b) )
            cout << "You must give 3 diffrent points! " << endl;
    
    } while ( ( c==a ) && (d == b) );

    cout << endl;

    Point q ( c, d );

    cout <<"Enter coordinates of last point: " << endl;

    float e,f;

    do{
        e = getFloat();
        f = getFloat();

        if ( ( ( e == a ) && ( f == b) || ( (e == c) && (f == d))))
            cout << "You must give 3 diffrent points! " << endl;

    }while ( ( ( e == a ) && ( f == b) || ( (e == c) && (f == d))));

    cout << endl;

    Point w ( e, f );

    string n = createName( lF );

    string col = getColour();

    Triangle *t = new Triangle ( p, q, w, n, col );

    lF.list.push_back( t );

    t->draw();

}

void createRectangle( ListOfFigures &lF )
{
    cout << "Please give first verticle of rectangle: " << endl;

    float a,b;
    a = getFloat();
    b = getFloat();

    cout << endl;

    Point p ( a, b );

    cout << "Please give second verticle which will be on a diagonal of this rectangle: " << endl;

    float c,d;

    do
    {
        c = getFloat();
        if ( c == a)
            cout << "This point mest be on diagonal of rectangle, give a correct coordinate" << endl;
    } while ( c == a );

    do
    {
        d = getFloat();
        if ( d == b)
            cout << "This point mest be on diagonal of rectangle, give a correct coordinate" << endl;
    } while ( d == b );

    cout << endl;
    
    Point q ( c, d );

    string n = createName( lF );

    string col = getColour();

    Rectangle *r = new Rectangle ( p, q, n, col );

    lF.list.push_back( r );

    r->draw();
}

void createCircle( ListOfFigures &lF )
{
    cout << "Give a coordinates of the center of the circle: " << endl;

    float a,b;

    a = getFloat();
    b = getFloat();

    cout << endl;

    Point s ( a, b );

    float r;

    Circle *c = nullptr;

    do
    {
        try
        {
            cout <<"Give a radius of the circle: " << endl;
            r = getFloat();
            string n = createName( lF );
            string col = getColour();
            c = new Circle ( s, r, n, col);

        }
        catch(const char* e)
        {
            cout<< e << '\n';
        }
        
    } while ( !c );
    

    lF.list.push_back( c );

    c->draw();
    
}

void createNewFigure( ListOfFigures &lF )
{
    string n = createName( lF );

    string col = getColour();

    Figure *f = new Figure ( n, col );
    cout << "How many verticles do you want to enter? ( more than 3 ) " << endl;
    
    int k;

    do{
        k = getInteger();
        if( k == 3 )
            cout << "This is triangle, use an appropiate option!" << endl;
        if( k == 2 )
            cout << "This is Line Segment, use an appropiate option!" << endl;
        if( k < 2)
            cout << "This kind of figure does not exist!" << endl;
    }while( k < 4 );

    for( int i = 0; i < k; ++i ){
        float a,b;

        cout << "Enter the coordinates of verticle: " << endl;
        a = getFloat();
        b = getFloat();

        cout << endl;

        Point p ( a, b );

        f->addVerticle( p );
    }

    lF.list.push_back( f );
    
    f->draw();

    cout << endl;
}

void editMode( ListOfFigures &lF, ListOfGroups &lG  )
{
    cout << endl;
    cout << "\tEditor mode" << endl << endl;

    int j;

    do {
        
        cout << "Please choose:\n[1] to see the list of created figures,\n[2] to move,\n[3] to rotate" << endl;
        cout << "[4] to scale,\n[5] to set colour,\n[6] to create a group, \n[0] to exit this mode." << endl;

        j = getInteger();

        cout << endl;

        switch( j )
        {
            case 1:
                lF.showList();
                cout << endl;
                lG.showList();
                cout << endl;
                break;
            case 2:
                moveFigure( lF, lG );
                cout << endl;
                break;
            case 3:
                rotateFigure( lF, lG );
                cout << endl;
                break;
            case 4:
                scaleFigure( lF, lG );
                cout << endl;
                break;
            case 5:
                setFigColour( lF, lG );
                break;
            case 6:
                createGroup( lF, lG );
                cout << endl;
                break;
            case 0:
                cout << "Exiting editor mode." << endl << endl;
                break;
            default:
                cout << "Don't know what to do!" << endl;
        }

    }while( j !=0 );

}

void moveFigure( ListOfFigures &lF, ListOfGroups &lG )
{
     cout << "Please enter the coordinates of the vector: " << endl;

    float a = getFloat();
    float b = getFloat();

    cout << "Which figure do you want to move? " << endl;
    
    string n;

    cin >> n;

    if ( lF.inList( n )){

        for( auto &it : lF.list ){
            if( n == it->getName() ){
                it->move( a, b );
                it->draw();
            }
        }
    }
    else if ( lG.inList( n )){

        for( auto &it : lG.listg ){
            if( n == it->getName() ){
                it->move( a, b );
                it->draw();
            }
        }
    }
    if( !lG.inList( n ) && !lF.inList( n ) )
        cout << "Cannot find the figure! Exiting option" << endl;
    
}

void rotateFigure( ListOfFigures &lF, ListOfGroups &lG  )
{
    cout <<"Choose:\n[1] to rotate around some point,\n[2] to rotate around center." << endl;

    int l = getInteger();

    switch( l )
    {
        case 1:
            rotAroPoint( lF, lG );
            break;
        case 2:
            rotAroCenter( lF, lG );
            break;
        default:
            cout << "Don't know what to do! Exiting option." << endl;
            break;
    }

}

float getAngle()
{
    cout << "Please enter an angle of rotation in deegres: " << endl;

    float a = getFloat();

    float b;

    b = (a/180)*M_PI;

    return b;
}

void rotAroPoint( ListOfFigures &lF, ListOfGroups &lG )
{
    float a = getAngle();

    cout << "Enter coordinates of the point around which figure will be rotated: " << endl;

    float x = getFloat();
    float y = getFloat();
    
    cout << "Which figure do you want to move? " << endl;
    
    string n;

    cin >> n;  

    if( lF.inList( n ) ){

        for( auto &it : lF.list ){
            if( n == it->getName() ){
                it->rot( a, x, y );
                it->draw();
            }
        }
    }
    else if( lG.inList( n ) ){
        
        for( auto &it : lG.listg ){
            if( n == it->getName() ){
                it->rot( a, x, y );
                it->draw();
            }
        }
    }
    if( !lG.inList( n ) && !lF.inList( n ) )
        cout << "Cannot find the figure! Exiting option" << endl;
    
}

void rotAroCenter( ListOfFigures &lF, ListOfGroups &lG )
{
    float a = getAngle();
    
    cout << "Which figure do you want to move? " << endl;
    
    string n;

    cin >> n;  

    if( lF.inList( n ) ){


        for( auto &it : lF.list ){
            if( n == it->getName() ){
                Point s = it->getCenter();
                it->rot( a, s.x, s.y );
                it->draw();
            }
        }

    }
    if( lG.inList( n ) ){


        for( auto &it : lG.listg ){
            if( n == it->getName() ){
                Point s = it->getCenter();
                it->rot( a, s.x, s.y );
                it->draw();
            }
        }

    }
    if( !lG.inList( n ) && !lF.inList( n ) )
        cout << "Cannot find the figure! Exiting option" << endl;
}

void scaleFigure( ListOfFigures &lF, ListOfGroups &lG )
{
    cout <<"Choose:\n[1] to scale around some point,\n[2] to scale around center." << endl;

    int l = getInteger();

    switch( l )
    {
        case 1:
            scaleArouPoint( lF, lG );
            break;
        case 2:
            scaleArouCenter( lF, lG );
            break;
        default:
            cout << "Don't know what to do! Exiting option." << endl;
            break;
    }
}

void scaleArouPoint( ListOfFigures &lF, ListOfGroups &lG )
{
    cout << "Enter a factor: " << endl;

    float f = getFloat();

    
    cout << "Enter coordinates of the point which will be used in this operation: " << endl;

    float x = getFloat();
    float y = getFloat();
    
    cout << "Which figure do you want to move? " << endl;
    
    string n;

    cin >> n;  

    if( lF.inList( n ) ){

        for( auto &it : lF.list ){
            if( n == it->getName() ){
                it->scale( x, y, f );
                it->draw();
            }
        }

    }
    if( lG.inList( n ) ){

        for( auto &it : lG.listg ){
            if( n == it->getName() ){
                it->scale( x, y, f );
                it->draw();
            }
        }

    }
    if( !lG.inList( n ) && !lF.inList( n ) )
        cout << "Cannot find the figure! Exiting option" << endl; 

}

void scaleArouCenter( ListOfFigures &lF, ListOfGroups &lG )
{
    cout << "Enter a factor: " << endl;

    float f = getFloat();
    
    cout << "Which figure do you want to move? " << endl;
    
    string n;

    cin >> n;  

    if( lF.inList( n ) ){

        for( auto &it : lF.list ){
            if( n == it->getName() ){
                Point c = it->getCenter();
                it->scale( c.x, c.y, f );
                it->draw();
            }
        }

    }
    if( lG.inList( n ) ){

        for( auto &it : lG.listg ){
            if( n == it->getName() ){
                Point c = it->getCenter();
                it->scale( c.x, c.y, f );
                it->draw();
            }
        }

    }
    if( !lG.inList( n ) && !lF.inList( n ) )
        cout << "Cannot find the figure! Exiting option" << endl; 
}

void setFigColour( ListOfFigures &lF, ListOfGroups &lG )
{
    cout << "Colour of which figure do you want to set?" << endl;

    string n;

    do{
        cin >> n;

        if( !lF.inList( n ) && !lG.inList( n ) )
            cout << "This figure do not exist! Give a name of existing one!" << endl;

    }while( !lF.inList( n ) && !lG.inList( n ) );

    string c = getColour();

    if( lF.inList( n ) ){
        for( auto &it: lF.list){
            if( n == it->getName() )
                it->setColour( c );
        }
    }
    if( lG.inList( n ) ){
        for( auto &it: lG.listg){
            if( n == it->getName() )
                it->setColour( c );
        }
    }
    
}

void createGroup( ListOfFigures &lF, ListOfGroups &lG )
{

    string name;

    do{
        cout << "Enter a name of group: " << endl;

        cin >> name;

        if( lG.inList( name ) || lF.inList( name ) )
            cout << "This name is already in use!" << endl;
    }while( lG.inList( name ) || lF.inList( name ));

    Group *g = new Group ( name );

    int k;
    
    do{ 

        string n;

        do{
            cout << "Enter name of figure that you want to add to the Group" << endl;
            cin >> n;
            if( !lF.inList( n ) )
                cout << "This figure do not exist. Enter appropiate one!" << endl;

        }while ( !lF.inList( n ) );

        for ( auto &it: lF.list ){
            if( n == it->getName() )
                g->addFigure( it );
        }

        cout << "If you don't want to add next figure enter 0" << endl;

        k = getInteger();        

    }while( k != 0 );

    lG.listg.push_back( g );
}