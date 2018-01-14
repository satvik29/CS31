#ifndef ZODIACREADER_H

#define ZODIACREADER_H



#include <string>

#include "Date.h"



class ZodiacReader

{
    
public:
    
    ZodiacReader( Date date );
    
    
    
    enum Sign { ARIES, TAURUS, GEMINI, CANCER, LEO, VIRGO, LIBRA, SCORPIO, SAGITTARIUS,
        
        CAPRICORN, AQUARIUS, PISCES };
    
    
    
    ZodiacReader::Sign checkSign( ) const;
    
    std::string stringifySign( ZodiacReader::Sign sign ) const;
    
    bool onCusp( ) const;
    
    ZodiacReader::Sign cuspSign( ) const;
    
    
    
private:
    
    Date mDate;
    
    
    
    ZodiacReader::Sign checkSign( Date date ) const;
    
};
