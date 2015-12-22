/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bhaskar
 *
 * Created on December 21, 2015, 3:01 AM
 */

#include <cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<vector<int> > subsets_util(vector<int> &A,int beg)
{
    vector<vector<int> > answer;
    for(int i=beg;i<A.size();i++)
        {
            vector<vector<int> > temp_answer= subsets_util(A,i+1);
            vector<int> temp;
            temp.push_back(A[i]);
            answer.push_back(temp);
            for(int j=0;j<temp_answer.size();j++)
                {
                    
                    vector<int> temp1(1,A[i]);
                    temp1.insert(temp1.end(),temp_answer[0].begin(),temp_answer[0].end());
                    answer.push_back(temp1);
                }
            for(int j=0;j<temp_answer.size();j++)
                {
                    answer.push_back(temp_answer[j]);
                }
            
        }
    return answer;
}


vector<vector<int> > subsets(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> answer;
    answer.push_back(vector<int> (0));
    sort(A.begin(),A.end(),[](const int A,const int B){ return A < B;});
    vector<vector<int> > temp=subsets_util(A,0);
    answer.insert(answer.end(),temp.begin(),temp.end());
    
}
/*
 * 
 */
int main(int argc, char** argv) {
    vector<int> hello={12,13};
    vector<vector<int>> answer=subsets(hello);
    for(int i=0;i<answer.size();i++)
    {for(int j=0;j<answer[i].size();j++)
            cout<<answer[i][j]<<" ";
     cout<<endl;
    }
    return 0;
}

