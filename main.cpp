#include <iostream>
#include <string>
#include "Caesar.h"

using namespace std;

int main() {
    string a = "It's was amazing time. I hope we will can repeat this.";
    string d = "How have your day gone?";

    cout << d << endl;

    string b = encrypt(d, 4);

    cout << b << endl;

    string c = decrypt(b, 4);

    cout << c << endl;


    return 0;
}
