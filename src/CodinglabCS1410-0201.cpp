#include <iostream>
#include <iomanip>

using namespace std;

int main(){

//    int i = 1;
//    while(i <= 19){
//        int even = odd +1
//        cout << setw (4) << setw(4) << endl;
//        odd += 2;
//    }
        for(int odd = 1; odd <= 29; odd += 2){
            int even = odd +1;

            cout << setw(6) << odd << setw(6) << even << endl;
        }

    return 0;
}
// 2 big changes I used was <= rather than < 20 and second was trimming down as much as I could to make it eaier to read