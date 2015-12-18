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

#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> permute( string s){
    sort(s.begin(),s.end());
    int i,j,pos;
    vector<string> answer;
    answer.push_back(s);
    while(true){
    i=s.length()-1;
    while( i>=1 && s[i]<= s[i-1])
        i--;
    pos=i-1;
    if(pos == -1 ) break;
    for(j=i;j<s.length()&& s[pos]<s[j];j++);
    swap(s[pos],s[j-1]);
    i=pos+1;
    j=s.length()-1;
    while(i<j){ swap(s[i++],s[j--]);}
    answer.push_back(s);
    }
    return answer;
 }

/*
 * 
 */

string TopView::findOrder(vector<string> A){
	map< char,vector<char> > graph;
	
	for(int i=0;i<A.size();i++)
		for(int j=0;j<A[0].length();j++){
				if(A[i][j]=='.') continue;
				if(graph.count(A[i][j]) =0)
					{
					//this character is encounterd for the first time
					
					}

int main(int argc, char** argv) {
    vector<string> ans=permute("aaaa");
    for(int i=0;i<ans.size();i++)
        cout<<i<<" "<<ans[i]<<endl;
    return 0;
}

