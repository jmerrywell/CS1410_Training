#include <iostream>
using namespace std;

int main(){
    double x, y;
    char c; 

    do{
        cout << "Enter operation (+, - ,* ,/, %) or q to terminate:";
        cin >> c;
        if(c == 'q') break;

        cout << "Enter x amd y: ";
        cin >> x >> y;
        switch(c){
            case '+': cout << x + y << endl; break;
            case '-': cout << x - y << endl; break;
            case '*': cout << x * y << endl; break;
            case '/': if(y == 0){
                cout << "Can not divide By 0";
             }  else {
                    cout << x / y << endl;} break;
            case '%': if(y == 0){
                cout << "Error Invalid operation";
            }   else {
                cout << (int)x % (int)y << endl;} break;
            default: cout << "Invalid Operator\n.";
        }

    }while(c != 'q');

    return 0;
}
// I added if statemants from previous video activitys within the chapter for to prevent both / and % 
// from crashing the program. Added a defualt to inform user that they did not input an operation.
