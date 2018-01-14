// Satvik Anand
// 404-823-011
// Discussion 1E
// Project 3


#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

bool isWellFormedAirportString ( string commands ) ;
double ontimeArrivalPercentage ( string commands , string airlinecode ) ;

// retrieves the airline code
string airlineCode ( string commands , size_t position ) ;

// checks the validity of the airline code
bool validAirlineCode ( string airlineCode , size_t& position ) ;

// retrieves the airline number
string airlineNumber ( string commands , size_t position ) ;

// checks the validity of the airline number
bool validAirlineNumber ( string commands , size_t& position) ;

// checks whether there's a plus or a minus after the airline number
bool validPlusOrMinus ( string commands , size_t& position ) ;

// retrieves the minutes
string minutes ( string commands , size_t position ) ;

// checks the validity of the minutes
bool validMinutes ( string commands , size_t& position ) ;

// counts how many individual flight codes are there
int counter ( string commands ) ;

// checks whether the airline code in the second function is valid
bool wellFormedAirlineCode ( string commands ) ;

// retrieves minutes of the early flights
string earlyMinutes ( string commands , size_t position ) ;

// checks whether the minutes are early or late
bool early ( string commands , size_t position ) ;

// counts the total number of flights
double flightCounter ( string commands , string airlinecode ) ;

// counts the number of early flights
double ontimeFlightCounter ( string commands , string airlinecode ) ;

// lowers the case of the values entered if it's a string of 2 letters
string decapitalizer ( string commands ) ;


int main() {
    string commands;
    string airlinecode;
    getline ( cin , commands ) ;
    getline ( cin , airlinecode ) ;
    cout << isWellFormedAirportString ( commands ) << endl;
    cout << wellFormedAirlineCode ( airlinecode ) << endl;
    cout << ontimeArrivalPercentage ( commands , airlinecode ) << endl;
    cout << flightCounter ( commands , airlinecode ) << endl;
    cout << ontimeFlightCounter ( commands , airlinecode ) << endl;
    
    return 0 ;
}

bool isWellFormedAirportString ( string commands ) {
    
    // loops the verifying functions around the entire string
    
    bool last = false;
    
    int trueCount = 0;
    size_t j = 0;
    
    for ( int i = 0 ; i != counter ( commands ) ; i++ ) {
        
        if ( j < commands.size () ) {
            if ( validAirlineCode ( commands , j ) ) {
                trueCount++;
            }
            
            if ( validAirlineNumber ( commands , j ) ) {
                trueCount++;
            }
            
            if ( validPlusOrMinus ( commands , j ) ) {
                trueCount++;
            }
            
            if ( validMinutes ( commands , j ) ) {
                trueCount++;
            }
        }
        
        
    }
    
    /* If the function is a valid airline string, there has to be 4 of each
     validity, and there needs to be at least 4 validities.
     */
    
    if (trueCount >= 4 && trueCount % 4 == 0 ) {
        last = true;
    }
    
    return last;
    
}

// retrieves the airline code given the position
string airlineCode ( string input , size_t position ) {
    
    string airlineCode = "";
    
    if ( position + 2 < input.size() ) {
        
        if ( isalpha ( input [ position ] ) && isalpha ( input [ position + 1 ] ) && isdigit ( input [ position + 2 ] )) {
            airlineCode += input [ position ] ;
            airlineCode += input [ position + 1 ] ;
        }
        
        if ( airlineCode.size() == 2 ) {
            
            if ( isupper ( airlineCode [ 0 ] ) ) {
                airlineCode [ 0 ] += 32 ;
            }
            
            if ( isupper ( airlineCode [ 1 ] ) ) {
                airlineCode [ 1 ] += 32 ;
            }
        }
        
    }
    return airlineCode;
}

// checks whether the airline code is valid
bool validAirlineCode ( string input , size_t& position ) {
    
    bool last = false;
    
    if (airlineCode ( input , position ) == "aa" || airlineCode ( input , position ) == "da" || airlineCode ( input , position ) == "ua" || airlineCode ( input , position ) == "al" || airlineCode ( input , position )== "sw" || airlineCode ( input , position ) == "va") {
        last = true;
        position += 2;
    }
    
    return last;
}

// retrieves the airline number
string airlineNumber ( string commands , size_t position ) {
    
    string airlineNumber = "" ;
    
    if ( position + 3 <= commands.size() ) {
        
        for ( size_t i = position - 2 ; i < position + 3 ; i++) {
            if ( isdigit ( commands [ i ] ) && commands [ i - 1 ] != '+' && commands [ i - 1 ] != '-' && commands [ i - 2 ] != '+' && commands [ i - 2 ] != '-') {
                airlineNumber += commands [ i ];
            }
        }
        
    }
    
    return airlineNumber;
}

// verifies validity of airline number
bool validAirlineNumber ( string commands , size_t& position ) {
    
    bool last = false;
    
    string number = airlineNumber ( commands , position ) ;
    int value = -1;
    
    if ( number != "" ) {
        
        if ( number.size() == 1 ) {
            value = number [ 0 ] - 48;
            position++;
        } else
            if ( number.size() == 2 ) {
                value = (number [ 0 ]-48) * 10 + (number [ 1 ]-48) ;
                position += 2;
            } else
                if ( number.size() == 3 ) {
                    value = (number [ 0 ]-48) * 100 + (number [ 1 ]-48)*10 + (number [ 2 ]-48);
                    position += 3;
                }
        
        if ( value >= 0 && value <= 999 ) {
            last = true;
        }
    }
    
    return last;
}


// checks whether there is a plus or a minus
bool validPlusOrMinus ( string commands , size_t& position ) {
    
    bool last = false;
    
    if ( position < commands.size() ) {
        if ( commands [ position ] == '+' || commands [ position ] == '-' ) {
            last = true;
            position++;
        }
    }
    return last;
}

// checks whether the minutes are valid
bool validMinutes ( string commands , size_t& position ) {
    
    bool last = false;
    
    string number = minutes ( commands , position ) ;
    int value = -1;
    
    if ( number != "") {
        size_t total = number.size();
        
        for ( size_t i = 0 ; i < total ; i++ ) {
            number [ i ] -= 48;
        }
        
        if ( total == 1 ) {
            value = number [ 0 ];
            position++;
        } else
            if ( total == 2 ) {
                value = number [ 0 ] * 10 + number [ 1 ] ;
                position += 2;
            } else
                if ( total == 3 ) {
                    value = number [ 0 ] * 100 + number [ 2 ];
                    position += 3;
                }
        
        if ( value <= 999 && value >= 0 ) {
            last = true;
        }
    }
    return last;
    
}

// checks whether the minutes are early or not
bool early ( string commands , size_t position ) {
    bool last = false;
    int value = -1;
    
    string number = minutes ( commands , position );
    
    if ( number != "") {
        size_t total = number.size();
        
        if ( total == 1 ) {
            value = number [ 0 ]-48;
        } else
            if ( total == 2 ) {
                value = (number [ 0 ]-48) * 10 + number [ 1 ]-48 ;
            } else
                if ( total == 3 ) {
                    value = (number [ 0 ]-48) * 100 + (number [ 1 ]-48)*10 + (number[2]-48);
                }
        
        if ( value < 15 && value >= 0) {
            last = true;
        }
    }
    return last;
}

// retrieves the minutes
string minutes ( string commands , size_t position ) {
    
    string minutes = "";
    
    if ( position < commands.size() ) {
        if ( isdigit ( commands [ position ] ) ) {
            minutes += commands [ position ];
        }
    }
    
    if ( position + 1 < commands.size() ) {
        if ( isdigit ( commands [ position + 1 ] ) ) {
            minutes += commands [ position + 1 ];
        }
    }
    
    if ( position + 2 < commands.size() ) {
        if ( isdigit ( commands [ position + 2 ] ) ) {
            minutes += commands [ position + 2 ];
        }
    }
    
    return minutes;
}

// counts the number of individual flights
int counter ( string commands ) {
    
    int count = 0;
    
    for ( size_t i = 0 ; i != commands.size() ; i++ ) {
        if ( commands [ i ] == '+' || commands [ i ] == '-' ) {
            count++;
        }
    }
    return count;
}

// checks whether the airline code entered is valid or not
bool wellFormedAirlineCode ( string commands ) {
    
    bool last = false;
    
    string airlineCode = "";
    
    if ( commands.size() == 2 ) {
        if ( isalpha ( commands [ 0 ] ) && isalpha ( commands [ 1 ] ) ) {
            if ( isupper ( commands [ 0 ] ) ) {
                airlineCode += commands [ 0 ] + 32 ;
            } else {
                airlineCode += commands [ 0 ] ;
            }
            
            if ( isupper ( commands [ 1 ] ) ) {
                airlineCode += commands [ 1 ] + 32 ;
            } else {
                airlineCode += commands [ 1 ] ;
            }
        }
    }
    
    if ( airlineCode == "aa" || airlineCode == "ua" || airlineCode == "da" || airlineCode == "va" || airlineCode == "sw" || airlineCode == "al" ) {
        last = true;
    }
    
    return last;
}

// decapitalizes the airline code if any of its letters are capital
string decapitalizer ( string commands ) {
    
    string small = "";
    
    if ( isupper ( commands [ 0 ] ) ) {
        small += commands [ 0 ] + 32 ;
    } else {
        small += commands [ 0 ] ;
    }
    
    if ( isupper ( commands [ 1 ] ) ) {
        small += commands [ 1 ] + 32 ;
    } else {
        small += commands [ 1 ] ;
    }
    
    return small;
}

// counts the total number of flights of a particular airline code
double flightCounter ( string commands , string airlinecode ) {
    
    double count = 0 ;
    
    for ( size_t i = 0 ; i != commands.size() ; i++ ) {
        if ( airlineCode ( commands , i ) == decapitalizer ( airlinecode ) ) {
            count++;
        }
    }
    
    return count;
}

// counts the total number of flights that are early of a particular airline code
double ontimeFlightCounter ( string commands , string airlinecode ) {
    
    double count = 0 ;
    size_t pos = 0;
    
    for ( int i = 0 ; i != counter ( commands ) ; i++ ) {
        if ( airlineCode ( commands , pos ) == decapitalizer ( airlinecode ) ) {
            validAirlineCode ( commands , pos );
            validAirlineNumber ( commands, pos );
            validPlusOrMinus ( commands, pos );
            if ( early ( commands , pos ) ) {
                count++;
            }
            validMinutes ( commands, pos );
        }
    }
    
    
    return count;
}

double ontimeArrivalPercentage ( string commands , string airlinecode ) {
    
    float percentage = -1.00 ;
    
    if ( isWellFormedAirportString ( commands ) && wellFormedAirlineCode ( airlinecode ) ) {
        if ( flightCounter ( commands , airlinecode ) == 0 ) {
            percentage = 0.00;
        }
        
        if ( flightCounter ( commands , airlinecode ) > 0 ) {
            percentage = ontimeFlightCounter ( commands , airlinecode ) / flightCounter ( commands , airlinecode );
        }
    }
    
    return percentage;
}
















