
/* 
 * File:   main.cpp
 * Author: Bhaskar
 *
 * Created on December 25, 2015, 4:39 PM
 */

#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
enum{B,S,W};

pair<string,int> findleastmovement(vector<vector<int> >bins){
    
    vector<int> permutation={0,1,2};
    vector<int> ans(3);
    int cost=INT_MAX;
    
    do{
        int temp=0;
        for(int j=0;j<3;j++)
            for(int i=0;i<3;i++){
                if(i!=permutation[j]) temp+=bins[j][i];
            }
        if(temp<cost) {
            cost=temp;
            ans=permutation;
        }
    }while(next_permutation(permutation.begin(),permutation.end()));
    
    string answer;
    for(int i=0;i<3;i++){
        switch (ans[i]){
            case B: answer+="B"; break;
            case W: answer+="W"; break;
            case S: answer+="S"; break;
        }
    }
    return make_pair(answer,cost);
    
    
}



/*
 * 
 */
int main(int argc, char** argv) {
    #define DEBUG
    #ifdef DEBUG
    freopen("input.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    vector<vector<int> > bins(3,vector<int> (3));
    while(t--){
    
        for(int i=0;i<3;i++)
            cin>>bins[i][W]>>bins[i][B]>>bins[i][S];
        pair<string,int> answer=findleastmovement(bins);
        cout<<answer.first<<" "<<answer.second<<endl;
    }
    return 0;
}