#include <iostream> 
#include <string> 
#include <ctype.h> 
#include <stack> 

using namespace std; 

string expr; 
int pos = 0; 

string get_token(){ 
    string token = ""; 
    if(pos == expr.size() ){ 
        token = "$"; return token; 
    } 
    while( expr[pos] == ' ') pos++; 
    
    if(expr[pos] == '+' || expr[pos] == '-' || expr[pos] == '/' || expr[pos] == '*'){ 
        token = token + expr[pos]; 
        pos = pos + 1; 
        return token; 
    } else if(isdigit(expr[pos]) ){ 
        while( isdigit(expr[pos]) ){ 
            token = token + expr[pos]; 
            pos = pos + 1; 
        } 
        return token; 
    } 
    return token; 
} 

int main(){ 
    getline(cin, expr); 
    stack <int> s; 
    string token = get_token(); 
    
    while(token != "$"){ 
        if(token == "+"){ 
            auto x = s.top(); 
            s.pop(); 
            x = x + s.top(); 
            s.pop(); 
            s.push(x); 
        } else if(token == "-"){ 
            auto x = s.top(); 
            s.pop(); 
            x = x - s.top(); 
            s.pop(); 
            s.push(x); 
        } else if(token == "/"){ 
            auto x = s.top(); 
            s.pop(); 
            x = x / s.top(); 
            s.pop(); 
            s.push(x); 
        } else if(token == "*"){ 
            auto x = s.top(); 
            s.pop(); 
            x = x * s.top(); 
            s.pop(); 
            s.push(x); 
        }else{ 
            s.push(atoi(token.c_str())); 
        } 
    
        token = get_token();
    } 
    
    cout << s.top() << endl; 
}