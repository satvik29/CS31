// Satvik Anand
// Discussion 1E
// 404-823-011
//                                      Project 5

#include <iostream>
#include "Date.h"
#include "ZodiacReader.h"
#include <cassert>
using namespace std;

int main() {
    
    // test code
    Date jan1( 1, 1 );
    ZodiacReader reader( jan1 );
    assert( reader.stringifySign( reader.checkSign() ) == "Capricorn" );
    assert( reader.checkSign( ) == ZodiacReader::CAPRICORN );
    assert( !reader.onCusp( ) );
    
    Date jan20( 1, 20 );
    ZodiacReader reader1( jan20 );
    assert( reader1.stringifySign( reader1.checkSign() ) == "Aquarius" );
    assert( reader1.checkSign( ) == ZodiacReader::AQUARIUS );
    assert( reader1.onCusp( ) );
    assert( reader1.stringifySign( reader1.cuspSign() ) == "Capricorn" );
    assert( reader1.cuspSign( ) == ZodiacReader::CAPRICORN );
    
    Date dec31(12, 31);
    ZodiacReader reader2(dec31);
    assert(reader2.stringifySign(reader1.checkSign()) == "Aquarius");
    assert(!reader2.onCusp());
    assert(reader2.stringifySign(reader2.cuspSign()) == "Aries");
    
    Date jul22(7, 22);
    ZodiacReader reader3(jul22);
    assert(reader3.stringifySign(reader3.checkSign()) == "Cancer");
    assert(reader3.checkSign() == ZodiacReader::CANCER);
    assert(reader3.onCusp());
    assert(reader3.cuspSign() == ZodiacReader::LEO);
    assert(reader3.stringifySign(reader3.cuspSign()) == "Leo");
    
    Date oct29(10, 29);
    ZodiacReader reader4(oct29);
    assert(reader4.stringifySign(reader4.checkSign()) == "Scorpio");
    assert(reader4.checkSign() == ZodiacReader::SCORPIO);
    assert(!reader4.onCusp());
    assert(reader4.cuspSign() == ZodiacReader::ARIES);
    assert(reader4.stringifySign(reader4.cuspSign()) == "Aries");
    
    Date jan17(1, 17);
    ZodiacReader reader5(jan17);
    assert(reader5.checkSign() == ZodiacReader::CAPRICORN);
    assert(!reader5.onCusp());
    assert(reader5.cuspSign() == ZodiacReader::ARIES);
    assert(reader5.stringifySign(reader5.checkSign()) == "Capricorn");
    assert(reader5.stringifySign(reader5.cuspSign()) == "Aries");
    
    cout << "all tests passed!" << endl;
    
    return 0;
    
    return 0;
}
