/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
    ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/


#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<cstdlib>



using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int>st;
        string str;
        int sum=0,a,b;
        for(size_t i=0; i<tokens.size(); i++){
            int op=0;
            if(!tokens[i].compare("+"))
                op=1;
            else if(!tokens[i].compare("-"))
                op=2;
            else if(!tokens[i].compare("*"))
                op=3;
            else if(!tokens[i].compare("/"))
                op=4;
            else {
                st.push(atoi(tokens[i].c_str()));
                continue;
            }
                
            b=st.top();
            st.pop();
            a=st.top();
            st.pop();
             
            if(op == 1)
                st.push(a+b);
            else if(op == 2)
                st.push(a-b);
            else if(op ==3)
                st.push(a*b);
            else{
				if(!b)
					return -1;
				st.push(a/b);
			}
        }
    }
};

int main(){
	vector<string>tokens;
	tokens.push_back("0");
	tokens.push_back("3");
	tokens.push_back("/");

	Solution solution;
	cout<<solution.evalRPN(tokens)<<endl;
}
