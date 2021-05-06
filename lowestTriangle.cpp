#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// code execution: g++-10 -std=c++17 -o lowestTriangle lowestTriangle.cpp; ./lowestTriangle

// problem statement: https://www.hackerrank.com/challenges/lowest-triangle/problem

// solution: based on formula for area of a triangle: area = height*base/2

int lowestTriangle(int trianglebase, int area)
{

    //return ceil(2*area/trianglebase);    wrong answer: need float or implicity 2.0
    //return round(2.0*area/trianglebase);    wrong answer: need ceiling instead of round; read comment below for explanation

    return ceil((float)2 * area / trianglebase);
}

/* alternative solutions: add 1 or 0 without using ceil()

1. add base-1 to numerator


Normal devision returns floor value which means:

4/4 = 1
6/4 = 1 (floor)
8/4 = 2
To convert floor value to ceiling value, easiest way is to add base - 1 to numerator so you get:

4/4 = (4+3)/4 = 1
6/4 = (6+3)/4 = 2 (ceiling)
8/4 = (8+3)/4 = 2

solution: return (area * 2 + (base - 1)) / base;




2. using modulo 
If numerator divides into denominator -> mod = 0 -> false -> adds 0 (doesn't round up)

If numerator doesn't divide into denominator -> 0 < mod < base -> true (because > 0) -> adds 1 (rounds up, in all remaining cases)

solution: return   2 * a / b     + bool((2 * a) % b);  // bool((2 * a) % b) is either 0 (no change) or 1 (round up = ceiling) 



*/

/* the difference between round() and ceiling() 

reminder:
floor(3.5) => 3
ceiling(3.5) => 4

round(4.100000) = 4.000000
ceil(4.100000) = 5.000000
floor(4.100000) = 4.000000

possibly, for this problem, ceiling fits better (gives the correct answer) than round.
meaning halfway cases (<.5) needing to be rounded up, instead of down.
hence why only some test cases failed with round.

*/

// P.S. the conversion to float is necessary so that ceil will have some effect. the above code works for c++;
// but will not work for javascript and simillar languages since it does not have float data type.

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int trianglebase = stoi(first_multiple_input[0]);

    int area = stoi(first_multiple_input[1]);

    int height = lowestTriangle(trianglebase, area);

    //fout << height << "\n";
    cout << height << "\n";

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
