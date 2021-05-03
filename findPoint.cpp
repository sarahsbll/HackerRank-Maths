#include <bits/stdc++.h>
/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm> // for unique
*/

using namespace std;

// code execution: g++-10 -std=c++17 -o findPoint findPoint.cpp; ./findPoint

// problem statement: https://www.hackerrank.com/challenges/find-point/problem

// solution: based on mid-point formula:
// the middle for X is (Mx = (Rx + Px) / 2 ) and for Y is (My = (Ry + Py) / 2)

vector<string> split_string(string);

vector<int> findPoint(int px, int py, int qx, int qy)
{

    vector<int> r{0, 0};

    r[0] = 2 * qx - px;
    r[1] = 2 * qy - py;

    return r;
}

// Instead of the template below; you could read input & print output; something like this in python
/*for i in range(int(raw_input())):
    px, py, qx, qy = map(int, raw_input().split())
    print ("{0} {1}".format(2*qx-px, 2*qy-py))
*/
int main()
{
    //auto res = getenv("OUTPUT_PATH");
    //ofstream fout(res);

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int n_itr = 0; n_itr < n; n_itr++)
    {
        string pxPyQxQy_temp;
        getline(cin, pxPyQxQy_temp);

        vector<string> pxPyQxQy = split_string(pxPyQxQy_temp);

        int px = stoi(pxPyQxQy[0]);

        int py = stoi(pxPyQxQy[1]);

        int qx = stoi(pxPyQxQy[2]);

        int qy = stoi(pxPyQxQy[3]);

        vector<int> result = findPoint(px, py, qx, qy);

        for (int result_itr = 0; result_itr < result.size(); result_itr++)
        {
            cout << result[result_itr];

            //fout << result[result_itr];

            if (result_itr != result.size() - 1)
            {
                cout << " ";
                //fout << " ";
            }
        }
        cout << "\n";
        //fout << "\n";
    }

    //fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
