/*
Satvik Anand
404-823-011
Discussion 1E

                                         Project 4
*/

#include <iostream>
#include <cassert>
using namespace std;

int locateMinimum (const string array[], int n);
int findLastOccurrence (const string array [], int n, string target);
int flipAround(string array[] , int n);
bool hasNoDuplicates(const string array[], int n);
void unionWithNoDuplicates(const string array1[], int n1, const string array2[], int n2, string resultingString[], int& resultingSize);
int shiftRight(string array[], int n, int amount, string placeholderToFillEmpties);
bool isInIncreasingOrder(const string array[], int n);

int main() {
    
    const string array[6] = {"f", "b", "c", "z", "aa", "a"};
    string array3[8] = {"fa", "fb", "fc", "fd", "ww", "wz", "x", "y"};
//    const string array2[7] = {"f", "b", "c", "z", "aa", "a"};
    string array1[6] = {"sansa", "jon", "jacob", "alisa", "mk", "fm"};
    cout << locateMinimum(array, 6);
    cout << findLastOccurrence(array, 6, "z");
    cout << flipAround(array1, 6);
    cout << shiftRight(array1, 6, 1, "foo");
    assert (hasNoDuplicates(array, 4));
    assert (isInIncreasingOrder(array3, 8));
    
    string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };
    
    string b[6] = { "delta", "gamma", "beta", "alpha", "beta", "alpha" };
    string h[7] = { "samwell", "jon", "margaery", "daenerys", "", "tyrion", "margaery" };
    int answer;
    
    
    string output[6] = { " ", " ", " ", " ", " ", " "  };
    int outputSize = 6;
    
    assert(locateMinimum(a, 3 ) == 0);
    assert(locateMinimum(b, 3 ) == 2);
    
    assert(findLastOccurrence(a, 5, "beta" ) == 4);
    assert(findLastOccurrence(b, 3, "beta" ) == 2);
    
    assert(hasNoDuplicates(a, 3) == true);
    assert(hasNoDuplicates(a, 6) == false);
    
    assert(isInIncreasingOrder(a, 3) == true);
    assert(isInIncreasingOrder(a, 6) == false);

    unionWithNoDuplicates(a, 6, b, 2, output, outputSize );
    assert( outputSize == 4 );
    assert( output[0] == "alpha" );
 
    answer = shiftRight(h, 6, 1, "foobar" );
    assert( answer == 5 );
    assert( h[0] == "foobar" );
    
    assert(flipAround(b, 3 ) == 1);
    assert(flipAround(b, 4 ) == 2);
    
    cout << "All tests succeeded" << endl;
    return 0;
}

// returns the index of the smallest item in the array
int locateMinimum(const string array[], int n) {
    int index = -2;
    
    if (n <= 0) {
        index = -1;
    } else {
        string temp = array[0];
        for (int i = 1; i < n; i++) {
            if (array[i] < temp) {
                index = i;
            } else {
                index = 0;
            }
        }
    }
    
    return index;
}
// 4, 16, 39, 40, 42, 43, 45, 46, 47, 48 And 49


// returns the largest index that holds the target value
int findLastOccurrence(const string array[], int n, string target) {
    int index = -1;
    
    if (n > 0) {
        for (int i = n - 1; i >= 0; i--) {
            if (array[i] == target) {
                index = i;
                break;
            }
        }
    }
    
    return index;
}

// flips the items in the array around so that the first item holds what the last used to hold, second item holds what the second last held, and so on..
int flipAround(string array[], int n) {
    int count = 0;
    
    if (n > 0) {
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            if (i < j) {
                string temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                count++;
            }
        }
    }
    
    return count;
}

// returns true if every item of the array entered is unique
bool hasNoDuplicates(const string array[], int n) {
    bool last = false;
    
    int count = 0;
    
    if (n == 0) {
        last = true;
    }
    
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != i && array[i] == array[j]) {
                    count++;
                    break;
                }
            }
        }
    }
    
    if (count == 0) {
        last = true;
    }
    
    return last;
}

// creates a new array that's a union (set operator) of the two existing arrays
// also saves the size of the new array in resultingSize
void unionWithNoDuplicates(const string array1[], int n1, const string array2[], int n2, string resultingString[], int& resultingSize) {
    
    if (n1 <= 0 || n2 <= 0) {
        resultingSize = -1;
    }
    
    resultingSize = 0;
    
    if (n1 > 0 && n2 > 0) {
        for (int i = 0; i < n1; i++) {
            resultingSize++;
            resultingString[i] = array1[i];
        }
        
        for (int i = resultingSize - 1; i < n2; i++) {
            resultingSize++;
            resultingString[i] = array2[i];
        }

    }
    
    for (int i = 0; i < resultingSize; i++) {
        for (int j = 0; j < resultingSize; j++) {
            if (i != j && resultingString[i] == resultingString[j]) {
                resultingSize--;
                for (int k = j; k + 1 < resultingSize; k++) {
                    resultingString[k] = resultingString[k + 1];
                }
            }
        }
    }
    
    resultingSize++;
}

// outputs the size - 1

// adjusts the items in the array, shifting each value to the right by the amount parameter
// filling the first amount elements of the array with the placeholder string
// returning the amount of original array items still remaining in the string
int shiftRight(string array[], int n, int amount, string placeholderToFillEmpties) {
    int count = n;
    
    for (int i = 0; i < amount; i++) {
        array[i + amount] = array[i];
        array[i] = placeholderToFillEmpties;
        count--;
    }
    
    return count;
}

// checks if all the members of the array are in increasing order
bool isInIncreasingOrder(const string array[], int n) {
    bool last = false;
    
    if (n == 0) {
        last = true;
    }
    
    int count = 0;
    if (n > 0) {
        for (int i = 1; i < n; i++) {
            if (array[i] > array[i - 1]) {
                count++;
            }
        }
    }
    
    if (count == n - 1) {
        last = true;
    }
    
    return last;
}
