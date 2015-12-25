/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bhaskar
 *
 * Created on December 25, 2015, 5:17 PM
 */

#include <cstdlib>
#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_NUM 1000000
int cycle_length[MAX_NUM+1]={0};

int find_cycle_length(long long num){
    if(num>=1 && num <=MAX_NUM){
        
        if(cycle_length[num]!=0) return cycle_length[num];
        else {
            if(num%2==0) return cycle_length[num]=find_cycle_length(num/2)+1;
            else return cycle_length[num]=find_cycle_length(3*num+1)+1;
        }
    }
    else {
        if(num%2==0) return find_cycle_length(num/2)+1;
        else return find_cycle_length(3*num+1)+1;
    }
}
/*
 * 
 */
int main(int argc, char** argv) {
    cycle_length[1]=1;
    #define DEBUG
    #ifdef DEBUG
    freopen("input.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--){
        long long  a,b;
        cin>> a>> b;
        int max=find_cycle_length(a);
        while(a<=b){
            int temp=find_cycle_length(a);
            if(temp>max)max=temp;
            a++;
        }
        cout<<max<<endl;
    }
    return 0;
}

