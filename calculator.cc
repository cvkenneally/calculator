#include <iostream>
#include "stack.h"
#include "dictionary.h"
#include "fraction.h"
#include <ctype.h>
#include <string>
#include "exceptions.h"
#include <sstream>

using namespace std;

Dictionary<string, Fraction> d;
Stack<char> opStack;
Stack<Fraction> numStack;

void ScanForVar(string expr, int &first, string &dest);
void evaluate(string expr);
void doOp ();
bool hasPrecedence(char a, char b);
void ProcessSymbol(string expr, int &first);

unsigned int hash(string s){
        unsigned int sum = 0;

        for(int i = 0; i<s.length(); i++) {
                sum = sum *  i +s[i];
        }

        return sum;

}

void ScanForVar(string expr, int &first, string &dest){

        for(int i=0; i < expr.length(); i++)
                if (expr[i] == '=') {
                        first = i + 1;
                        break;
                }

        if (first > 0) {
                for (int i=0; i<first; i++)
                        if (isalpha(expr[i]) || expr[i] == '_') {
                                while (isalnum(expr[i]) || expr[i] == '_') {
                                        dest += expr[i];
                                        i++;
                                }
                                break;
                        }
        }
}

void evaluate(string expr){

        int first = 0;
        string dest = "";
        numStack.clear();
        opStack.clear();
        opStack.push('$');
        Fraction answer = 0;


        // Scan forward for '='
        ScanForVar(expr, first, dest);

        while(first < expr.length()) {
                ProcessSymbol(expr,first);
        }

        while(opStack.peek() != '$') {
                doOp();
        }

        if(dest != "") {
                d.insert(dest,numStack.peek());
                answer = numStack.peek();
        }

        cout << dest << "   =   " << answer << endl;

}

void doOp (){

        Fraction l,r, ans;

        char op;

        // Pop both sides of the operator, the operator and assign them to their respective sides
        r = numStack.pop();
        l = numStack.pop();
        op = opStack.pop();

        // Analyze the operator and evaluate accordingly
        if (op == '+') {
                ans = l + r;
                numStack.push(ans);
        }

        else if (op == '-') {
                ans = l - r;
                numStack.push(ans);
        }

        else if (op == '*') {
                ans = l * r;
                numStack.push(ans);
        }

        else if (op == '/') {
                ans = l / r;
                numStack.push(ans);
        }
}         // DONE

bool hasPrecedence(char a, char b){
        if (a == '*' || a == '/') {
                return true;
        }
        else if(a == '$' || a == '(' || a == ')') {
                return false;
        }

        else{
                return false;
        }
}                                     // DONE

void ProcessSymbol(string expr, int &first){
        string s_val;
        int n_val = 0;
        Fraction num1;


        if(isdigit(expr[first])) {
                while(isdigit(expr[first])) {
                        s_val += expr[first];
                        first++;
                }
                // object from class stringstream :: https://www.geeksforgeeks.org/converting-strings-numbers-cc/
                stringstream geek(s_val);
                geek >> n_val;
                num1 = n_val;
                numStack.push(num1);
        }

        else if(isalpha(expr[first])) {                          //finish
                s_val = "";
                while(isalpha(expr[first])) {
                        s_val += expr[first];
                        first++;
                }
                numStack.push(d.search(s_val));
                //  first += 1;
        }

        else if(expr[first] == '(') {
                opStack.push('(');
                first++;
        }

        else if(expr[first] == ')') {
                while(opStack.peek() != '(') {
                        doOp();
                }
                opStack.pop();
                first++;
        }

        else if(expr[first] == '+' || expr[first] == '-' || expr[first] == '*' || expr[first] == '/') {
                if(hasPrecedence(opStack.peek(),expr[first])) {
                        doOp();
                }
                opStack.push(expr[first]);
                first++;
        }
        else {first++;}

}

int main(){
        string expr;
        // Gets input and sends it to the evaluate function to perform the arithmetic ( ctrl + d : to break)
        while (true) {
                getline(cin,expr);

                if(!cin) {
                        break;
                }
                evaluate(expr);
        }

}
