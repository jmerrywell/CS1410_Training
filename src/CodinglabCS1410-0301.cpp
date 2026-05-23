#include <iostream>
#include <string>
using namespace std;

string repChar(char, int);
long hms_2_secs(int h, int m, int s);
void swapV(double& x, double& y);

void swapV(double& x, double& y){
    double t = x;
    x = y; 
    y = t; 
}

long hms_2_secs(int h, int m, int s){
    long secs = h * 60 * 60 + m * 60 + s;
    return secs;
}

int main(){

    cout << repChar('X', 8) << endl;
    cout << hms_2_secs(4, 56, 17) <<" seconds" << endl;

    double x = 10.0, y = 30.0;
    cout << x << ", " << y << endl;
    swapV(x, y); 
    cout << x << ", " << y << endl;
    
    return 0;
}

string repChar(char c, int n){
    string r;
    for(int i = 0; i < n; i++){
        r = r + c;
    }
    return r;
}