#ifndef CONVERSIONS
#define CONVERSIONS

#include <string>

string binHex(string number, bool type){
    const int length = number.length();
    string output;
    int tab[4];
    if(type){ //true: 2->16, false: 16->2
        for(int i=0; i<length/2; ++i){
            char help = number[i];
            number[i] = number[length-i-1];
            number[length-i-1] = help;
        }
        return number;
    }
    else{

    }
}

string binDec(string number, bool type){

}

string decHex(string number, bool type){
    
}
#endif
