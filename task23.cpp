using namespace std;
#include <iostream>
int mystrlen(char* str) {
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        k++;
    }
    return k;
}
char* mystrcpy(char* str, char* str2) {
    cout << "You got:\n";
    cout << "string 1 - " << str << endl;
    cout << "string 2 - " << str2 << endl;
    for (int i = 0; i < mystrlen(str2)+1; i++) {
        if (i == mystrlen(str2)) {
            str[i] = '\0';
        }
        else {
            str[i] = str2[i];
        }
    }
    return str;
}
char* mystrcat(char* str, char* str2) {
    int k = 0;
    for (int i = mystrlen(str); i < (mystrlen(str) + mystrlen(str2)) + 1; i++) {
        if (i == mystrlen(str2)+ (mystrlen(str))) {
            str[i] = '\0';
        }
        else {
            str[i] = str2[k];
            k++;
        }
    }   
    return str;
}
int mystrchr(char* str, char s) {
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == s) {
            return k + 1;
        }
        k++;
    }
    cerr << "Have not this symbol\n";
    return 0;
}
int mystrstr(char* str, char* str2) {
    int m = 0;
    for (int i = 0; str[i] != '\0'; i++) {
     int k = 0;
        if (str[i] == str2[0]) {
            for (int j = i; str2[j] != '\0'; j++) {
                if (str[j] != str2[k]) {
                    m++;
                    break;
                }
                else {
                    k++;
                }
                if (k == mystrlen(str2)) {
                    return ++m;
                }
            }
        }
        else {
            m++;
        }
    }
    return 0;
}
int main()
{
    start:
    cout << "Choose the function you want to try:\n";
    cout << "The string length ------------------------- 1\n";
    cout << "Copying the string into other string ------ 2\n";
    cout << "Adding string to other string ------------- 3\n";
    cout << "Searching the symbol in the string -------- 4\n";
    cout << "Searching the substring in the string ----- 5\n";
    cout << "Exit -------------------------------------- 0\n";
    char q; cin >> q;
    if (q == '1') {
        char* str = new char[100];
        cout << "\nInput some text\n";
        cin >> str;
        cout << mystrlen(str)<< " symbols\n\n";
        goto start;
    }
    else if (q == '2') {
        char* str = new char[100];
        cout << "\nInput some text for str1\n";
        cin >> str;
        char* str2 = new char[100];
        cout << "\nInput some text for str2\n";
        cin >> str2;
        mystrcpy(str, str2);
        cout << "After copying:\n";
        cout << "string 1 - " << str << " (changed string)" << endl;
        cout << "String 2 - " << str2 << endl;
        goto start;
    }
    else if (q == '3') {
        char* str = new char[100];
        cout << "\nInput some text for str1\n";
        cin >> str;
        char* str2 = new char[100];
        cout << "\nInput some text for str2\n";
        cin >> str2;
        cout << "You got:\n";
        cout << "string 1 - " << str << endl;
        cout << "string 2 - " << str2 << endl;
        mystrcat(str, str2);
        cout << "string 1 - " << str << " (changed string)" << endl;
        cout << "String 2 - " << str2 << endl;
        goto start;
    }
    else if (q == '4') {
        four:
        char* str = new char[100];
        cout << "\nInput some text for\n";
        cin >> str;
        char s;
        cout << "Input the symbol you want ot find\n";
        cin >> s;
        int k = mystrchr(str, s);
        if (k != 0){
            cout << "Found by " << k << " symbol\n";
        }
        else {
            four_:
            cout << "Want to try again? (1 - yes; 0 - go to menu)\n";
            cin >> q;
            if (q == '1') {
                goto four;
            }
            else if (q == '0') {
                goto start;
            }
            else {
                cerr << "Wrong.Try again\n";
                goto four_;
            }
        }
        goto start;
    }
    else if (q == '5') {
        char* str = new char[100];
        cout << "\nInput some text for\n";
        cin >> str;
        char* str2 = new char[100];
        cout << "\nInput text for search\n";
        cin >> str2;
        int k = mystrstr(str, str2);
        if (k != 0) {
            cout << "The \"" << str2 << "\"has started from " << k << "element\n\n";
        }
        else {
            cerr << "There is not this word\n\n";
        }
        goto start;
    }
    else if (q == '0') {
        return 0;
    }
    else {
        cerr << "Wrong inputting\n\n";
        goto start;
    }
}

