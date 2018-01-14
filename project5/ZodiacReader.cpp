#include "ZodiacReader.h"

#include <iostream>



ZodiacReader::ZodiacReader( Date date ) : mDate( date )

{
    
    
    
}



ZodiacReader::Sign ZodiacReader::checkSign( ) const

{
    
    ZodiacReader::Sign result = checkSign( mDate );
    
    return( result );
    
}



std::string ZodiacReader::stringifySign( ZodiacReader::Sign sign ) const

{
    
    // turn the sign parameter into its corresponding string name
    
    std::string result;
    
    switch( sign )
    
    {
            
        case ARIES:
            
            result = "Aries";
            
            break;
            
        case TAURUS:
            
            result = "Taurus";
            
            break;
            
        case GEMINI:
            
            result = "Gemini";
            
            break;
            
        case CANCER:
            
            result = "Cancer";
            
            break;
            
        case LEO:
            
            result = "Leo";
            
            break;
            
        case VIRGO:
            
            result = "Virgo";
            
            break;
            
        case LIBRA:
            
            result = "Libra";
            
            break;
            
        case SCORPIO:
            
            result = "Scorpio";
            
            break;
            
        case SAGITTARIUS:
            
            result = "Sagittarius";
            
            break;
            
        case CAPRICORN:
            
            result = "Capricorn";
            
            break;
            
        case AQUARIUS:
            
            result = "Aquarius";
            
            break;
            
        case PISCES:
            
            result = "Pisces";
            
            break;
            
    }
    
    return( result );
    
}



bool ZodiacReader::onCusp( ) const

{
    
    bool result( false );
    
    // is the member variable date on a sign cusp?
    
    // if we add or subtract two from the day, will the sign change?
    
    ZodiacReader::Sign actualSign = checkSign();
    
    Date plusTwo( mDate.getMonth(), mDate.getDay() + 2 );
    
    Date minusTwo( mDate.getMonth(), mDate.getDay() - 2 );
    
    ZodiacReader::Sign plusTwoSign = checkSign( plusTwo );
    
    ZodiacReader::Sign minusTwoSign = checkSign( minusTwo );
    
    
    
    if (plusTwoSign != actualSign || minusTwoSign != actualSign)
        
    {
        
        result = true;
        
    }
    
    return( result );
    
}



ZodiacReader::Sign ZodiacReader::cuspSign( ) const

{
    
    ZodiacReader::Sign result( ARIES );
    
    // determine the cusp sign, if any
    
    // if we add or subtract one from the day, will the sign change?
    
    ZodiacReader::Sign actualSign = checkSign();
    
    Date plusTwo( mDate.getMonth(), mDate.getDay() + 2 );
    
    Date minusTwo( mDate.getMonth(), mDate.getDay() - 2 );
    
    ZodiacReader::Sign plusTwoSign = checkSign( plusTwo );
    
    ZodiacReader::Sign minusTwoSign = checkSign( minusTwo );
    
    
    
    if (plusTwoSign != actualSign)
        
    {
        
        result = plusTwoSign;
        
    }
    
    if (minusTwoSign != actualSign)
        
    {
        
        result = minusTwoSign;
        
    }
    
    return( result );
    
}



ZodiacReader::Sign ZodiacReader::checkSign( Date date ) const

{
    
    ZodiacReader::Sign result( ARIES );
    
    // determine the sign of the member variable date
    
    switch( date.getMonth() )
    
    {
            
        case 1:
            
            if (date.getDay() >= 20)
                
            {
                
                result = AQUARIUS;
                
            }
            
            else
                
            {
                
                result = CAPRICORN;
                
            }
            
            break;
            
        case 2:
            
            if (date.getDay() >= 19)
                
            {
                
                result = PISCES;
                
            }
            
            else
                
            {
                
                result = AQUARIUS;
                
            }
            
            break;
            
        case 3:
            
            if (date.getDay() >= 21)
                
            {
                
                result = ARIES;
                
            }
            
            else
                
            {
                
                result = PISCES;
                
            }
            
            break;
            
        case 4:
            
            if (date.getDay() >= 20)
                
            {
                
                result = TAURUS;
                
            }
            
            else
                
            {
                
                result = ARIES;
                
            }
            
            break;
            
        case 5:
            
            if (date.getDay() >= 21)
                
            {
                
                result = GEMINI;
                
            }
            
            else
                
            {
                
                result = TAURUS;
                
            }
            
            break;
            
        case 6:
            
            if (date.getDay() >= 21)
                
            {
                
                result = CANCER;
                
            }
            
            else
                
            {
                
                result = GEMINI;
                
            }
            
            break;
            
        case 7:
            
            if (date.getDay() >= 23)
                
            {
                
                result = LEO;
                
            }
            
            else
                
            {
                
                result = CANCER;
                
            }
            
            break;
            
        case 8:
            
            if (date.getDay() >= 23)
                
            {
                
                result = VIRGO;
                
            }
            
            else
                
            {
                
                result = LEO;
                
            }
            
            break;
            
        case 9:
            
            if (date.getDay() >= 23)
                
            {
                
                result = LIBRA;
                
            }
            
            else
                
            {
                
                result = VIRGO;
                
            }
            
            break;
            
        case 10:
            
            if (date.getDay() >= 23)
                
            {
                
                result = SCORPIO;
                
            }
            
            else
                
            {
                
                result = LIBRA;
                
            }
            
            break;
            
        case 11:
            
            if (date.getDay() >= 22)
                
            {
                
                result = SAGITTARIUS;
                
            }
            
            else
                
            {
                
                result = SCORPIO;
                
            }
            
            break;
            
        case 12:
            
            if (date.getDay() >= 22)
                
            {
                
                result = CAPRICORN;
                
            }
            
            else
                
            {
                
                result = SAGITTARIUS;
                
            }
            
            break;
            
        default:
            
            std::cerr << "Bad Month value!" << std::endl;
            
            break;
            
    }
    
    
    
    
    
    return( result );
    
}

