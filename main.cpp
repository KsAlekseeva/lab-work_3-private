#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string st; //10 2 5 + *
    stack <int> valStack;
    string n1 = "";
    string n2 = "";
    int right, left;
    int i = 0;
    cout << "Enter the st:" << endl;
    getline(cin, st);
    for(const char &a : st) {
        if(isdigit(a)) {
            n1 += a;
            if(stoi(n1) >= 10){
                i++;
            }
        }
        else{
            i++;
            if(n1 != ""){
                n1 = "";
            }
        }
    }

    int size_st = st.size() - i;
    for(const char &b : st) {
        if(isdigit(b)){
            n2 += b;
        }
        else{
            if(n2 != ""){
                valStack.push(stod(n2));
                n2 = "";
            }
            if((valStack.size() == size_st) && (valStack.size() > 1)) {
                right = valStack.top();
                valStack.pop();
                left = valStack.top();
                valStack.pop();
                size_st = size_st - 1;
            }
            switch(b) {
                case '+': valStack.push( right + left ); break;
                case '-': valStack.push( right - left ); break;
                case '*': valStack.push( right * left ); break;
                case '/': try{
                    if(right == 0) throw runtime_error("division by zero");
                    left/right;
                    valStack.push(right);
                    } catch(const runtime_error &error){
                        cout << "Runtime error: " << error.what() << std::endl;
                    } continue;
            }
        }
    }
    cout << "Result: " << valStack.top() << endl;
    return 0;
}