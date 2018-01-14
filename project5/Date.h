#ifndef DATE_H

#define DATE_H





class Date

{
    
public:
    
    Date( int month, int day );
    
    
    
    int getMonth( ) const;
    
    int getDay( ) const;
    
    
    
private:
    
    int mMonth, mDay;
    
};



#endif
