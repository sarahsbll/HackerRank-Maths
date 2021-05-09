#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// code execution: g++-10 -std=c++17 -o connectingTowns connectingTowns.cpp; ./connectingTowns

// problem statement: https://www.hackerrank.com/challenges/connecting-towns/problem

// solution: modular reduction within operations (vs at completion)
// the idea is that taking the mod before calculating the poduct is more efficient, aside from it being correct due to modular arithmetic

int connectingTowns(int n, vector<int> routes)
{

    int prod = 1;

    for (int i = 0; i < n - 1; i++) // Or: for(int i=0; i<routes.size(); i++)
                                    // for(int i=0; i<n; i++) would return 0, because you're exceeding the bounds of the routes array
    {
        prod *= routes[i];
        prod %= 1234567;
        // Or: prod *= routes[i]%1234567;
    }

    return prod; // return prod % 1234567; would fail test cases because of overflow, you must reduce as you multiply
                 // because of the way to modular arithmatic works,
                 // we can take the mod of each component of the product before calculating the product ->  (a*b)%c=((a%c)*(b%c))%c
                 // and we'd get the same result as if we were to mod the poduct after multiplying
                 // sum=((sum%1234567)*(x%1234567))%1234567;
                 // however, we can can remove the first two modulos because a) x is between 1 and 1000, so x modulo 1234567 is pointless,
                 // and b) modulo-ing sum before it is used in the equation and before assigning the result back to sum is redundant.

    // source: https://www.chegg.com/homework-help/definitions/modular-arithmetic-33
}

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

        string routes_temp_temp;
        getline(cin, routes_temp_temp);

        vector<string> routes_temp = split(rtrim(routes_temp_temp));

        vector<int> routes(n - 1);

        for (int i = 0; i < n - 1; i++)
        {
            int routes_item = stoi(routes_temp[i]);

            routes[i] = routes_item;
        }

        int result = connectingTowns(n, routes);

        //fout << result << "\n";
        cout << result << "\n";
    }

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
