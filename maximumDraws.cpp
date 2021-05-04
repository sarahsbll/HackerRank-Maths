#include <bits/stdc++.h>

using namespace std;
// code execution: g++-10 -std=c++17 -o maximumDraws maximumDraws.cpp; ./maximumDraws

// problem statement: https://www.hackerrank.com/challenges/maximum-draws/problem

// solution: based the pigeonhole principle

int maximumDraws(int n)
{

    return (n + 1);
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n";

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = maximumDraws(n);

        cout << result << "\n";
        //fout << result << "\n";
    }

    //fout.close();

    return 0;
}
