#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int> >  subsets(vector<int> & );   
};

vector<vector<int> > subsets_util(vector<int> &A,int beg)
{
    vector<vector<int> > answer;
    if(beg==A.size()){
        answer.push_back(vector<int> (0));
        return answer;
    }
    vector<vector<int> > temp_answer= subsets_util(A,beg+1);
    answer.insert(answer.end(),temp_answer.begin(),temp_answer.begin()+1);
    for(int k=0;k<temp_answer.size();k++)
        {
        vector<int> temp(1,A[beg]);
        temp.insert(temp.end(),temp_answer[k].begin(),temp_answer[k].end());
       
        answer.push_back(temp);
        }
    answer.insert(answer.end(),temp_answer.begin()+1,temp_answer.end());    
    
    return answer;
}

bool my_compare ( const vector<int> A, const vector<int> B){
    int i,j;
    for( i=0,j=0;i<A.size()&&j<B.size();i++,j++){
        if(A[i]<B[j]) return true;
    }
    if(i==A.size()) return true;
    else return false;
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //sort the array
    sort(A.begin(),A.end(),[](const int A,const int B){ return A < B;});
    //remove duplicates
    int i,j;
    for(j=0,i=0;i<A.size();i++,j++)
    {
        while(i+1 < A.size() && A[i]==A[i+1]) i++;
        A[j]=A[i];
    }
    A.erase(A.begin()+j,A.end());
    
    vector<vector<int> > answer=subsets_util(A,0);
    //sort the answer
   // sort(answer.begin(),answer.end(),my_compare);
    return answer;
    
}


int main(){
    vector<int> array={1000248, 1000467, 1000467 ,23 ,232 ,2323};
    Solution test;
    cout<<array.size()<<endl;
    vector<vector<int> > ans=test.subsets(array);
    cout<<"Total number of subsets="<<ans.size()<<endl;
    for ( int i=0;i<ans.size();i++)
        {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
        }
    return 0;
}