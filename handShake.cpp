#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// code execution: g++-10 -std=c++17 -o handShake handShake.cpp 

// problem statement: https://www.hackerrank.com/challenges/handshake/problem

// solution: based on combinations without repetition where n=attendees (number of people) k=2 (two different people's hands shake at a time)
// after simplification: one person (perspective) out of n people, needs to shake hands with (n-1) people. this reasoning holds true for all of the N people, so the total number of hand shakes is N * (N-1).
// however; two different people have to shake hands once, no matter the perspective. so we don't count each combination twice. hence why we divide by 2

// log
// ERR1: Solution.cpp:30:1: error: control reaches end of non-void function [-Werror=return-type]
// SOL: return statement has to be before the last closing bracket; not embedded

// ERR2: Runtime Error + Incorrect returned values for larger input
// SOL: Simplify the code
// TIP: when it's factorials, just expand and cancel out factorial terms
// the below h = factN / (2 * factNm2) function becomes: h = (n*(n-1))/2 (no fact => no for loop/ no recursive function)

/* final corrected solution */
int handshake(int n)
{
    return (n * (n - 1)) / 2;
}

/* initial error-prone solution 
int handshake(int n)
{
    long long factN = 1;
    long long factNm2 = 1;
    long long h = 0;
     

    // edge cases: n = 0, 1, 2
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else if (n >= 3)
    {
        // calculate factorial of n
        for (int i = 1; i <= n; ++i)
        {
            factN *= i;
        }
        // calculate factorial of n-2
        for (int j = 1; j <= n - 2; ++j)
        {
            factNm2 *= j;
        }
        // factorial of 2 is 2
    } 
    h = factN / (2 * factNm2);

    return (int) h;
}
*/

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int result = handshake(n);

        // fout << result << "\n";
        cout << result << "\n";
    }

    // fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
