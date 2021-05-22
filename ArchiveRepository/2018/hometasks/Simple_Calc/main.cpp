#include "firstCalc.h"





int main()
{
        double x, y, result;
        char op;

        while(true){
            if(inputv2(x,y,op) == -1){
                cerr << "Error: Input error. Restart program and enter values same as example(: x + y)";
                return -1;
            }
            switch(op)
            {
            case '+':
                result = summ(x,y);
                break;
            case '-':
                result = diff(x,y);
                break;
            case '*':
                result = multiply(x,y);
                break;
            case '/':
                result = divide(x,y);
                break;
            case '%':
                result = ost(x,y);
                break;
            default:
                cout << "Undefined operator. Enter data again\n";
                continue;
            }
            cout << "Result of expression = " << result << '\n'
                 << "Want continue?(\"y\" for yes and someone else for no)\n" << ':';
            while(iscntrl(cin.peek()))getchar();
            if(getchar() == 'y');
            else {
                cout << "End program." << endl;
                break;
            }
        }
        return 0;
}


