/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bhaskar
 *
 * Created on December 26, 2015, 10:07 PM
 */

#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;


class PalindromePrime{
#define MAX_SIZE 1000
    
public:
    
    int count(int l,int r){
    int primeseive[MAX_SIZE+1]={0};

    for(int i=2;i<=MAX_SIZE;i++)
        for(int k=2;k*i<=MAX_SIZE;k++){
            primeseive[k*i]=1;
        }
    int palindromicCountUpto[MAX_SIZE+1]={0};
    int count=0;
    for(int i=2;i<=MAX_SIZE;i++)
    {
        if(primeseive[i]==0){
            int temp=i;
            int rev=0;
            while(temp>0){rev=rev*10+(temp%10);temp/=10;}
            if(rev==i) count++;
        }
        palindromicCountUpto[i]=count;
    }
    
    return palindromicCountUpto[r]-palindromicCountUpto[l-1]; 
}
};
/*
 * 
 */


class FourStrings{
	public:
	int shortestLength(string a,string b,string c,string d){
            
	}
	};
        
        
int main(int argc, char** argv) {
    
#define DEBUG2
#ifdef DEBUG
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a>> b;
        cout<<test.count(a,b)<<endl;
    }
#endif
    

#ifdef DEBUG2
    freopen("input1.txt","r",stdin);
    int t;
    cin >> t;
    while(t--){
        string a,b,c,d;
        cin >> a>> b>>c>>d;
        cout<<test.count(a,b)<<endl;
    }
#endif
    
    
    
    
    return 0;
}

