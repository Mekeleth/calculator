#ifndef CONVERSION
#define CONVERSION

#include <string>

using std::string;
using std::to_string;

string convert(int number, int base){
    string output = "";
    int modulo;
    while(number > 0){
        modulo = number%base;
        switch(modulo){
            case 10:
                output.append("A");
            break;
            case 11:
                output.append("B");
            break;
            case 12:
                output.append("C");
            break;
            case 13:
                output.append("D");
            break;
            case 14:
                output.append("E");
            break;
            case 15:
                output.append("F");
            break;
            default:
                output.append(to_string(modulo));
        }
        number/=base;
    }
    char help;
    for(int i=0; i<output.length()/2; ++i){
        help = output[i];
        output[i] = output[output.length()-i-1];
        output[output.length()-i-1] = help;
    }
    return output;
}

#endif
