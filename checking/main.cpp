#include <bits/stdc++.h>
#include<iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<string> > partition(string);
};

bool checkifpalindrome(string A){
    int i=0,j=A.length()-1;
    while(i<j){
        if(A[i++]!=A[j--]) return false; 
    }
    return true;
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string> > answer;
   
    for(int i=0;i<A.length()-1;i++)
    {
        string B=A.substr(0,i+1);
        if(checkifpalindrome(B)){
            vector<vector<string> > temp_answer=partition(A.substr(i+1,A.length()-(i+1))); 
            for(int j=0;j<temp_answer.size();j++){
                vector<string> t(1,B);
                t.insert(t.end(),temp_answer[j].begin(),temp_answer[j].end());
                answer.push_back(t);
            }
            
        }
        
    }
    if(checkifpalindrome(A))
        answer.push_back(vector<string> (1,A));
    return answer;
}

int main(int argc, char** argv) {
    Solution test;
    vector<vector<string> > ans=test.partition("aab");
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}


