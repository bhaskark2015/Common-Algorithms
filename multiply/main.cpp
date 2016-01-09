/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bhaskar
 *
 * Created on December 27, 2015, 8:45 PM
 */
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<unordered_map>
#include<algorithm>
#include<map>
#include<queue>
#include<climits>
#include <sstream>

template < typename T > std::string to_string(const T& n) {
    std::ostringstream stm;
    stm << n;
    return stm.str();
}


using namespace std;

class Solution {
public:
    string multiply(string, string);
    int isNumber(const string &);
    double findMedianSortedArrays(const vector<int> &, const vector<int>&);
    int search(const vector<int> &, int);
    vector<int> order(vector<int> &heights, vector<int> &infronts);
    string getPermutation(int n, int k);
    int pow(int, int, int);
    vector<vector<string> > solveNQueens(int A);
    string minWindow(string S, string T);
    string fractionToDecimal(int numerator, int denominator);

};

int Solution::isNumber(const string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    //handle leading spaces;
    int i = 0;
    while (i < A.length() && A[i] == ' ') i++;



    int signfound = false, numfound = false, decimalfound = false, efound = false;
    for (; i < A.length(); i++) {
        if (A[i] == '-' || A[i] == '+') {
            if (!efound) {
                if (numfound || signfound || decimalfound) return 0;
            } else {
                if (numfound || signfound) return 0;
            }
            signfound = true;
        } else if (A[i] == '.') {
            if (i == A.length() - 1 || decimalfound || efound) return 0;
            decimalfound = true;
            numfound = false;
            //    cout<<"decimal found"<<endl;
        } else if (A[i] == 'e') {
            if (!numfound || efound || i == A.length() - 1) return false;
            efound = true;
            numfound = false;
            signfound = false;
        } else if (A[i] >= '0' && A[i] <= '9') {
            numfound = true;
        } else if (A[i] == ' ') {

            //only trailing spaces are allowed
            while (i < A.length() && A[i] == ' ')i++;
            if (i == A.length() && numfound)return 1;
            else return 0;
        } else {

            return 0;
        }

    }
    if (numfound) return 1;
    else return 0;
}

double findMedianSortedArrays_util(const vector<int> &A, int start_a, int end_a, const vector<int> &B, int start_b, int end_b) {
    //assuming array A is always smaller in length than array B

    int len1 = end_a - start_a + 1;
    int len2 = end_b - start_b + 1;
    int mid_a = (start_a + end_a) / 2;
    int mid_b = (start_b + end_b) / 2;

    if (len1 == 1 && len2 == 1) {
        return (A[mid_a] + B[mid_b]) / 2;
    }

    if (len1 == 1) {
        if (len2 % 2 == 0) //length of second array is even
        {
            if (B[mid_b] > A[mid_a]) {
                return B[mid_b];
            } else {
                return min(B[mid_b + 1], A[mid_a]);
            }
        } else {
            if (B[mid_b] > A[mid_a]) {
                int temp = max(B[mid_b - 1], A[mid_a]);
                return (temp + B[mid_b]) / 2.0;
            } else {
                int temp = min(A[mid_a], B[mid_b + 1]);
                return (temp + B[mid_b]) / 2.0;
            }
        }
    }

    if (len1 == 2 && len2 == 2) {
        if (A[mid_a] < B[mid_b]) {
            return (B[mid_b] + min(A[mid_a + 1], B[mid_b + 1])) / 2.0;
        } else {
            return (A[mid_a] + min(A[mid_a + 1], B[mid_b + 1])) / 2.0;
        }
    }

    if (len1 == 2) {
        if (len2 % 2 == 0) {//the second array is of even length
            if (A[mid_a + 1] < B[mid_b - 1]) {
                return (B[mid_b] + B[mid_b - 1]) / 2.0;
            } else if (A[mid_a] > B[mid_b + 2]) {
                return (B[mid_b + 1] + B[mid_b + 2]) / 2.0;

            } else {
                //now have to find mid of A[0]A[1] B[mid_b] B[mid_b+1]
                if (A[mid_a] < B[mid_b]) {
                    return (min(A[mid_a + 1], B[mid_b + 1]) + B[mid_b]) / 2.0;
                } else {
                    return (min(A[mid_a + 1], B[mid_b + 1]) + A[mid_a]) / 2.0;
                }

            }
        } else {//the second array is of odd length
            if (A[mid_a + 1] < B[mid_b - 1]) {
                return B[mid_b - 1];
            } else if (A[mid_a] > B[mid_b + 1]) {
                return B[mid_b + 1];
            } else {
                //median of A[mid_a] and A[mid_a+1] and B[mid_b]
                return min(max(A[mid_a], B[mid_b]), A[mid_a + 1]);
            }

        }

    }

    if (A[mid_a] < B[mid_b]) {
        return findMedianSortedArrays_util(A, mid_a, end_a, B, start_b, end_b - (mid_a - start_a - 1) - 1);
    } else {
        return findMedianSortedArrays_util(A, start_a, mid_a, B, start_b + (end_a - mid_a), end_b);
    }
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A.size() == 0) {
        if (B.size() % 2 == 0)
            return (B[B.size() / 2] + B[B.size() / 2 - 1]) / 2.0;
        else
            return (B[B.size() / 2]);

    }
    if (B.size() == 0) {
        if (A.size() % 2 == 0)
            return (A[A.size() / 2] + A[A.size() / 2 - 1]) / 2.0;
        else
            return A[A.size() / 2];
    }
    if (A.size() > B.size())
        return findMedianSortedArrays_util(B, 0, B.size() - 1, A, 0, A.size() - 1);
    else
        return findMedianSortedArrays_util(A, 0, A.size() - 1, B, 0, B.size() - 1);


}

string Solution::multiply(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string ans = "0";
    for (int i = B.length() - 1; i >= 0; i--) {
        int carry = 0;

        string To_be_added = "";

        int multiplier = B[i] - '0';

        for (int j = A.length() - 1; j >= 0; j--) {
            int multiplicand = A[j] - '0';
            int temp = multiplier * multiplicand + carry;
            To_be_added += temp % 10 + '0';
            carry = temp / 10;
        }
        while (carry > 0) {
            To_be_added += carry % 10 + '0';
            carry /= 10;

        }
        for (int j = i; j < B.length() - 1; j++)
            To_be_added.insert(To_be_added.begin(), '0');
        //now add To_be_added to ans
        string newans;
        carry = 0;
        int k;
        for (k = 0; k < ans.length() && k < To_be_added.length(); k++) {
            int digit1 = ans[k] - '0';
            int digit2 = To_be_added[k] - '0';
            int temp = digit1 + digit2 + carry;
            newans += temp % 10 + '0';
            carry = temp / 10;
        }
        while (k < ans.length()) {
            int digit = ans[k] - '0';
            int temp = digit + carry;
            newans += temp % 10 + '0';
            carry = temp / 10;
            k++;
        }
        while (k < To_be_added.length()) {
            int digit = To_be_added[k] - '0';
            int temp = digit + carry;
            newans += temp % 10 + '0';
            carry = temp / 10;
            k++;
        }
        while (carry > 0) {
            newans += (carry % 10) + '0';
            carry /= 10;
        }
        ans = newans;
    }
    //remove trailing zeroes and reverse the string to get the final answer
    int j = ans.length() - 1;
    while (j > 0 && ans[j] == '0') j--;
    ans = ans.erase(j + 1, ans.length() - j);
    int i = 0;
    j = ans.length() - 1;
    while (i < j) swap(ans[i++], ans[j--]);

    return ans;


}

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    //find the pivot

    int beg = 0;
    int end = A.size() - 1;
    int pivot = -1;
    int mid;
    while (beg <= end) {
        mid = (beg + end) / 2;
        if (A[mid] > A[mid + 1]) {
            pivot = mid;
            break;
        } else if (A[mid] >= A[beg])//pivot lies to the right 
            beg = mid + 1;
        else if (A[mid] < A[beg])//pivot lies to the left
            end = mid - 1;
    }
    // cout<<pivot<<endl;
    if (A[0] < B) {
        beg = 0;
        end = pivot;
    } else {
        beg = pivot + 1;
        end = A.size() - 1;
    }
    bool found = false;
    while (beg <= end) {
        mid = (beg + end) / 2;
        if (A[mid] == B) {
            found = true;
            break;
        } else if (A[mid] < B)//pivot lies to the right
            beg = mid + 1;
        else if (A[mid] > B)//pivot lies to the left
            end = mid - 1;
    }
    if (!found) return -1;
    else return mid;
}

int compare(const pair<int, int> &A, const pair<int, int> &B) {
    return (A.first < B.first);
}

int initialize(int tree[], int start, int end, int index) {
    if (start > end) return 0;
    else if (start == end) {
        tree[index] = 1;
    } else {
        int mid = (start + end) / 2;
        tree[index] = initialize(tree, start, mid, 2 * index + 1) + initialize(tree, mid + 1, end, 2 * index + 2);
    }
    return tree[index];
}

void update(int tree[], int start, int end, int index, int update_index) {
    if (start > end) return;
    else if (start > update_index || end < update_index) {
        return;
    }
    tree[index]--;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(tree, start, mid, 2 * index + 1, update_index);
    update(tree, mid + 1, end, 2 * index + 2, update_index);
}

int update_and_search(int tree[], int start, int end, int index, int val) {
    if (start > end) return 0;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int mid = (start + end) / 2;
    if (start == end) {
        return end;
    } else if (tree[left] <= val) {
        return update_and_search(tree, mid + 1, end, 2 * index + 2, val - tree[left]);
    } else return update_and_search(tree, start, mid, 2 * index + 1, val);
}

vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {

    vector<pair<int, int> > height_infronts;
    for (int i = 0; i < heights.size(); i++) {
        height_infronts.push_back(make_pair(heights[i], infronts[i]));
    }

    sort(height_infronts.begin(), height_infronts.end(), compare);

    vector<int> answer(height_infronts.size());
    int *segment_tree = (int*) malloc(sizeof (int)*2 * height_infronts.size());
    initialize(segment_tree, 0, height_infronts.size() - 1, 0);

    for (int i = 0; i < height_infronts.size(); i++) {
        int temp = height_infronts[i].second;
        int pos = update_and_search(segment_tree, 0, height_infronts.size() - 1, 0, temp);
        update(segment_tree, 0, height_infronts.size() - 1, 0, pos);
        answer[pos] = height_infronts[i].first;
    }
    return answer;
}

string Solution::getPermutation(int n, int k) {
    int *answer = new int[n];
    for (int i = 0; i < n; i++)
        answer[i] = i + 1;
    int *fact = new int[n];
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < n; i++) {
        fact[i] = i * fact[i - 1];
    }
    k--;
    for (int i = 0; i < (n - 1); i++) {
        int pos = i + (k / fact[n - (i + 1)]);
        if (i != pos) {
            int temp = answer[i];
            answer[i] = answer[pos];
            for (int j = pos; j > i + 1; j--) {
                answer[j] = answer[j - 1];
            }
            if (i + 1 < n) answer[i + 1] = temp;
        }
        k = k % fact[n - (i + 1)];

    }

    string ans;
    for (int i = 0; i < n; i++) {
        ans += (to_string(answer[i]));
    }
    return ans;
}

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if (d == 1) return 0;
    while (x < 0) x += d;
    long long int ans = 1;
    x = x % d;
    while (n > 0) {
        if (n % 2 == 1)
            ans = (ans * x) % d;
        n = n >> 1;
        x = (x * x) % d;
    }
    return ans;
}

inline bool issafe(vector<string> &board, int row, int column, int n) {
    bool answer = true;

    //check for verfical and horizontal cashing
    for (int i = 0; i < n; i++) {
        if (board[row][i] == 'Q') answer = false;
        if (board[i][column] == 'Q') answer = false;
    }
    //check for diagonal crossing
    for (int i = 1; (row - i) >= 0; i++) {
        if ((column + i) < n && board[row - i][column + i] == 'Q')answer = false;
        if ((column - i) >= 0 && board[row - i][column - i] == 'Q')answer = false;
    }

    return answer;
}

void solveNQueens_util(vector<vector<string> > &answer, vector<string> & board, int row, int n) {
    if (row == n) {
        answer.push_back(board);
        return;
    }


    for (int j = 0; j < n; j++) {
        if (issafe(board, row, j, n)) {
            board[row][j] = 'Q';
            solveNQueens_util(answer, board, row + 1, n);
            board[row][j] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


    vector<vector < string>> answer;

    vector<string> board;
    for (int i = 0; i < A; i++)
        board.push_back(string(A, '.'));

    solveNQueens_util(answer, board, 0, A);

    return answer;




}

string Solution::minWindow(string S, string T) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack<pair<int, int> > minwindow;

#define CHAR_SIZE 256
    int hash[CHAR_SIZE] = {0};
    int unique_characters_count = 0;
    for (int i = 0; i < T.length(); i++) {
        if (hash[T[i]] == 0)
            unique_characters_count++;
        hash[T[i]] = 1;
    }

    int windowhash[CHAR_SIZE] = {0};
    int characters_left = unique_characters_count;
    int beg, end;
    int ans_beg, ans_end;
    for (beg = 0, end = 0; end < S.length() && characters_left > 0; end++) {
        if (windowhash[S[end]] == 0) {
            if (hash[S[end]] != 0)
                characters_left--;
        }
        windowhash[S[end]]++;
    }
    end--;

    if (characters_left > 0) return "";
    else {
        ans_beg = beg;
        ans_end = end;

        while (beg < S.length() && end < S.length()) {
            while (windowhash[S[beg]] > 1 || hash[S[beg]] == 0) {
                windowhash[S[beg]]--;
                beg++;
            }
            characters_left++;
            windowhash[S[beg]]--;
            beg++;
            while (windowhash[S[beg]] > 1 || hash[S[beg]] == 0) {
                windowhash[S[beg]]--;
                beg++;
            }
            while (characters_left > 0 && end < S.length()) {
                end++;
                if (windowhash[S[end]] == 0) {
                    if (hash[S[end]] != 0)
                        characters_left--;
                }
                windowhash[S[end]]++;
            }
            if (characters_left == 0) {
                if (end - beg < ans_end - ans_beg) {
                    ans_beg = beg;
                    ans_end = end;
                }
            }

        }


    }
    return S.substr(ans_beg, ans_end - ans_beg + 1);

}

string Solution::fractionToDecimal(int numerator, int denominator) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


    string answer;

    long long int divisor = denominator;
    long long int dividend = numerator;

    if (divisor < 0 && dividend < 0) {
        divisor = -divisor;
        dividend = -dividend;
    } else if (divisor > 0 && dividend < 0) {
        dividend = -dividend;
        answer += '-';
    } else if (divisor < 0 && dividend > 0) {
        divisor = -divisor;
        answer += '-';
    }

    //cout<<dividend<<" "<<divisor<<endl;

    unsigned long long int temp_quotient = dividend / divisor;
    unsigned long long int remain = dividend % divisor;

    answer += to_string(temp_quotient);
    if (remain != 0) {
        answer += '.';
        unordered_map<unsigned long long int, int> hash;
        while (remain != 0 && hash.count(remain) == 0) {
            hash[remain] = answer.length();
            remain=remain*10;
            while (remain < divisor) {
                answer += '0';
                if (hash.count(remain) != 0) break;
                remain *= 10;
            }
            if (hash.count(remain) != 0) 
                break;
            temp_quotient = remain / divisor;
            answer += to_string(temp_quotient);
            remain = remain % divisor;
        }

        if (remain != 0) {
            answer.insert(answer.begin() + hash[remain], '(');
            answer += ')';
        }
    }

    return answer;

}

int main() {
#define DEBUG9
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while (t--) {
        string num1;
        string num2;
        cin >> num1>>num2;
        Solution test;
        string ans = test.multiply(num1, num2);
        cout << ans << endl;
    }
#endif
#ifdef DEBUG1
    freopen("input1.txt", "r", stdin);
    int t;
    cin>>t;
    while (t--) {
        string num;
        cin>>num;
        Solution test;
        cout << test.isNumber(num) << endl;
    }
#endif
#ifdef DEBUG2
    freopen("input2.txt", "r", stdin);
    int t;
    cin>>t;
    while (t--) {
        vector<int> A;
        vector<int> B;
        int a, b;
        cin>> a;
        while (a--) {
            int temp;
            cin>>temp;
            A.push_back(temp);
        }
        cin>>a;
        while (a--) {
            int temp;
            cin>>temp;
            B.push_back(temp);
        }
        Solution test;
        cout << test.findMedianSortedArrays(A, B) << endl;
    }
#endif
#ifdef DEBUG3
    freopen("input3.txt", "r", stdin);
    int t;
    cin>>t;
    while (t--) {
        vector<int> array;
        int size;
        cin>> size;
        while (size--) {
            int temp;
            cin>>temp;
            array.push_back(temp);
        }
        int num;
        cin>>num;
        Solution test;
        cout << test.search(array, num) << endl;
    }
#endif
#ifdef DEBUG4
    freopen("input4.txt", "r", stdin);
    int t;
    cin>>t;
    while (t--) {
        int size1;
        cin>>size1;
        vector<int> A;
        while (size1--) {
            int temp;
            cin>>temp;
            A.push_back(temp);
        }
        int size2;
        cin>>size2;
        vector<int> B;
        while (size2--) {
            int temp;
            cin>>temp;
            B.push_back(temp);
        }
        Solution test;
        vector<int> answer = test.order(A, B);
        for (int i = 0; i < answer.size(); i++)
            cout << answer[i] << " ";
    }

#endif
#ifdef DEBUG5
    freopen("input5.txt", "r", stdin);
    int t;
    cin>>t;
    while (t--) {
        int a, b;
        cin >> a>>b;
        Solution test;
        cout << test.getPermutation(a, b) << endl;

    }
#endif
#ifdef DEBUG6
    freopen("input6.txt", "r", stdin);
    int t;
    cin>>t;
    while (t--) {
        int x, n, d;
        cin >> x >> n>>d;
        Solution test;
        cout << test.pow(x, n, d) << endl;
    }
#endif
#ifdef DEBUG7
    freopen("input7.txt", "r", stdin);
    int t;
    cin>>t;
    while (t--) {
        int a;
        cin>>a;
        Solution test;
        vector<vector<string > > ans = test.solveNQueens(a);
        cout << "finding solutions for " << a << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << "Solution " << i << ":" << endl;
            for (int j = 0; j < ans[0].size(); j++) {
                cout << ans[i][j] << endl;
            }

        }
    }
#endif
#ifdef DEBUG8
    freopen("input8.txt", "r", stdin);
    int t;
    cin>>t;
    while (t--) {
        string A, B;
        cin >> A>>B;
        Solution test;
        cout << test.minWindow(A, B);


    }
#endif
#ifdef DEBUG9
    freopen("input9.txt", "r", stdin);
    int t;
    cin>>t;
    while (t--) {
        int numerator, denominator;
        cin >> numerator>>denominator;
        Solution test;
        cout << test.fractionToDecimal(numerator, denominator)<<endl;
    }
#endif
    return 0;
}