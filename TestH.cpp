#include "TestH.hpp"
#include "Histogram.hpp"

bool TEST_OP_GET() 
{
    Histogram<string> h1;
    h1.add_ele( "abcd" );
    h1.add_ele( "dcba" );
    h1.add_ele( "abcd" );
    cout << "TEST nr. 1: OPERATOR << ";

    if (h1[0].element == "abcd" && h1[0].number == 2){
        if (h1[1].element == "dcba" && h1[1].number == 1) {
            return true;
        }
    }
    else
        return false;
    return false;

}

bool TEST_OP_NEW_ElEM() 
{
    Histogram<char> h1;

    h1 << 'c' << 'c' << 'c';

    cout << "TEST nr. 2: OPERATOR []";


    if( h1[0].element == 'c' ){
        if( h1[0].number == 3 )
            return true;
    }
    else
        return false;
    return false;
}

bool TEST_OP_PLUS() 
{
    cout << "TEST nr. 3: OPERATOR +";
    Histogram<int> h1, h2, h3;
    h1 << 2 << 4 << 6 << 3 << 6 << 4 << 6 << 7;
    h2 << 6 << 2 << 1 << 6 << 1;

    h3 = h1 + h2;

    if ( h3[2].element == 6 ){
        if( h3[2].number == 5)
            return true;
    }else
        return false;

    return false;
}

bool TEST_FROM_FILE()
{
    Histogram<int> h6;

    h6.from_file( "new 1.txt");

    cout << "TEST nr. 4: FROM FILE";

    if( h6[3].element == 12 ){
        if( h6[4].element == 3)
            return true;
    }else
        return false;

    return false;
}

bool TEST_GET_NUM() 
{
    Histogram<int> h1;

    h1 << 5 << 2 << 3 << 6 << 5 << 4 << 3 << 2 << 1 << 2 << 2;

    int k = h1.get_num();

    cout << "TEST nr. 5: FUNCTION GET_NUM";

    if ( k == 6)
        return true;
    else
        return false;

}

bool TEST_SET_VALUE() 
{
    cout << "TEST nr. 6: FUNCTION SET_VALUE";

    Histogram<int> h;

    h << 5 << 2 << 1 << 3 << 4 << 6 << 7 << 5 << 5 << 3 << 2 << 4 << 3 << 3;

    h.set_value( 1, 6 );
    h.set_value( 2, 15 );
    h.set_value( 3, 63 );
    h.set_value( 4, 150 );
    h.set_value( 5, 16 );
    h.set_value( 6, 3 );
    h.set_value( 7, 95 );

    h << 5 << 6 << 3 << 3 << 2 << 5 << 4 << 6;

    if ( h[0].number == 18 && h[2].number == 6){
        if ( h[4].number == 151 && h[6].number == 95)
            return true;
    }

    return false;

}

void TEST() {

    int a = 0;

    bool k = TEST_OP_GET();
        if ( k == 1 ){
            cout << "\t\tSUCCEEDED" << endl;
            a++;
        }
        else
            cout << "\t\tFAILED" << endl;

    bool l = TEST_OP_NEW_ElEM();
        if ( l == 1 ){
            cout << "\t\t\tSUCCEEDED" << endl;
            a++;
        }
        else
            cout << "\t\t\tFAILED" << endl;

    bool j = TEST_OP_PLUS();
        if ( j == 1 ){
            cout << "\t\t\tSUCCEEDED" << endl;
            a++;
        }
        else
            cout << "\t\t\tFAILED" << endl;

    bool n = TEST_FROM_FILE();
        if ( n == 1 ){
            cout << "\t\t\tSUCCEEDED" << endl;
            a++;
        }
        else
            cout << "\t\t\tFAILED" << endl;

    bool i = TEST_GET_NUM();
        if ( i == 1 ){
            cout << "\t\tSUCCEEDED" << endl;
            a++;
        }
        else
            cout << "\t\tFAILED" << endl;

    bool o = TEST_SET_VALUE();
        if ( o == 1 ){
            cout << "\t\tSUCCEEDED" << endl;
            a++;
        }
        else
            cout << "\t\tFAILED" << endl;

    cout << endl;

    if ( a == 6 )
        cout << "All Tests ended successfully!" << endl;
    else
        cout << "Something is wrong!" << endl;
}

