/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bhaskar
 *
 * Created on December 18, 2015, 9:23 PM
 */

#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

/*
 * 
 */

class FarmvilleDiv2{
public:
int minTime(vector<int> time , vector<int > cost,int budget){

    vector< pair<int,int> > cost_pos_pairs;
    for(int i=0;i<cost.size();i++){
        cost_pos_pairs.push_back(make_pair(cost[i],i));
    }
    
    sort(cost_pos_pairs.begin(),cost_pos_pairs.end(),[](pair<int,int> &first,pair<int,int> &second){return first.first> second.first;});
    for(int i=0;i<cost_pos_pairs.size();i++){
        int tot_cost=cost_pos_pairs[i].first * time[cost_pos_pairs[i].second];
        if(budget > = tot_cost){
            budget-=tot_cost;
            time[cost_pos_pairs[i].second]=0;
        }
        else{
            time[cost_pos_pairs[i].second]-= budget/cost_pos_pairs[i].first;
        }
    }
    int min_time=0;
    for(int i=0;i<time.size();i++)
        min_time+=time[i];
    return min_time;
}   
};

class BoardEscapeDiv2 {
	public:
	string findWinner( vector<string> s, int k){
	int w=s[0].length();
	int h=s.size();
              bool allostacles(int i,int j, vector<string> s){
            //left possible
            if(i>0){
                if(s[i-1][j]!='#') return false;
            }
            //right possible
            if(i<(s[0].length()-1)){
                if(s[i+1][j]!='#') return false;
            }
            //up possible
            if(j>0){
                if(s[i][j-1]!='#') return false;
            }
            //down possible
            if(j<s.size()-1){
                if(s[i][j+1]!='#')return false;
            }
            return true;
        }
        bool anyEnearby(int i,int j,vector<string> s){
              if(i>0){
                if(s[i-1][j]=='E') return true;
            }
            //right possible
            if(i<(s[0].length()-1)){
                if(s[i+1][j]=='E') return true;
            }
            //up possible
            if(j>0){
                if(s[i][j-1]=='E') return true;
            }
            //down possible
            if(j<s.size()-1){
                if(s[i][j+1]=='E')return true;
            }
            return false;
        }
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j+)
			{
			if(s[i][j] == 'T'){
				if( allobstacles(i,j,s) )
					return "Bob";
				else if(anyEnearby(i,j,s))
					return "Alice";
				else if(k%2==1) return "Alice";
				else return "Bob";
                            }
                        }
	return "Bob";
	}
  
};

int main(int argc, char** argv) {

    return 0;
}