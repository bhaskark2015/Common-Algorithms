/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bhaskar
 *
 * Created on December 16, 2015, 3:30 PM
 */
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution{
public:
    string simplifyPath(string);
};


string Solution::simplifyPath(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<string> st;
    
    string prevdir("..");
    string currdir(".");
    for(int i=0;i<A.length();i++)
        {
            int beg=i;
            while(i<A.length()&& A[i]!='/')
                i++;
            int end=i-1;
            if(beg>=end) continue;
            string temp=A.substr(beg,end-beg+1);
            if(temp.compare(currdir)){continue;}
            else if(temp.compare(prevdir)){st.pop();}
            else st.push(temp);
        }
    string answer;
    while(!st.empty()){
        answer+=string("/");
        answer+=st.top();
        st.pop();
    }
    
    return answer;
}
