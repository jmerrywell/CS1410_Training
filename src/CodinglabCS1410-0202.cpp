#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "Enter day: ";
    string day;

    cin >> day;
    
    for(auto &c : day)
        c = tolower(c);

    if(day == "sun" || day == "sat"){
        cout << "It's a weekend." << endl;
    } else if (day == "fri"){
        cout << "It's Friday!";
    }else if(day == "mon" || day == "tue" || day == "wed" || day == "thu") {
        cout << "It's a weekday." << endl;
    }else {
        cout << "Plaese use abriviated days.";
    }

    return 0;
}
// biggest change made was adding the other week days and an else for all other inqueries to preven incorrect 
// inputs returning weekday. I struggled with the tolower even after pulling up w3 school so I had AI teach me
// an efficent way to use it. At the moment I do not know another way to use it or can not remember so.