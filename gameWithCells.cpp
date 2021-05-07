#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// code execution: g++-10 -std=c++17 -o gameWithCells gameWithCells.cpp; ./gameWithCells

// problem statement: https://www.hackerrank.com/challenges/game-with-cells/problem

// solution: based on x%2 = 0 or 1; and on finding the relationship between inputs & outputs through multiple instances (brute force)

int gameWithCells(int n, int m)
{

    // idea: for 4 bases, we need exactly 1 drop;
    // but if we have a 1 spare cell, either because the row or column is odd, then we need to add an additional drop
    // i.E if either row or column is even: n%2 or m%2 = 0 -> no additional drops
    //     if either row or column is odd: n%2 or m%2 = 1 -> additional drops are added
    return ((n + n % 2) * (m + m % 2)) / 4;

    // idea: four bases require one drop, so we divide by 4
    // return ceil(n/2.0) * ceil(m/2.0); // P.S. didn't work return ceil(n*m/4.0);
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int result = gameWithCells(n, m);

    //fout << result << "\n";
    cout << result << "\n";

    //fout.close();

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
