#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// code execution: g++-10 -std=c++17 -o leonardoPrimes leonardoPrimes.cpp; ./leonardoPrimes

// problem statement: https://www.hackerrank.com/challenges/leonardo-and-prime/problem

// solution:
// -> unique primes using gcd

// RE: Timeout
// -> efficient types: 'unsigned long long int', instead of just 'int', to avoid overflow
// -> hardcoded values

unsigned long long int gcd(unsigned long long int a, unsigned long long int b)
{
    // explanation: (exercice 3) https://drive.google.com/file/d/13WsQNJGTjh6AKGp4AR79L5ldgFcw7PRR/view?usp=sharing
    while (b)
    { // stop when the rest of divison (a % b) = 0
        unsigned long long int t = b;

        b = a % b;
        a = t;
    }
    return a;
}

unsigned int primeCount(unsigned long long int n)
{
    unsigned int count;
    unsigned long long int prod;
    unsigned long long int prim;

    if (n < 2)
        return 0;

    prod = 2;
    count = 1;

    // look for all combinations of prime products which is below the given number
    for (prim = 3; prod * prim <= n; prim += 2)
    { // odd (3) + even (2) = odd
        // because there are no even prime numbers except for 2; which is accounted for in prod = 2
        if (gcd(prod, prim) == 1)
        { // check if the odd number is prime compared with the rest of proud,
            // including that it isn't already apart of the prod, e.G. gcd(3, 3) = 3 -> which is non-unique
            prod *= prim;
            count++;
        }
    }
    return count;
}

// N.B. calculating max primes runs in O(n*log(n)) (n for looking at all the numbers and log(n) for the gcd).

// Using a hardcoded list of primes is O(1). However, you'd have to experiement with the primes array (at least in Java 8) to pass all test cases.
// long primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

/* alternative solution using a hardcoded list of primes in Python

prime=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
for i in range(int(input())):
    count,result=0,1
    n=int(input())
    // cycle through the array multiplying each prime until we get higher number then given number
    for j in prime:
        result*=j
        if(result<=n):
            count+=1
    print(count)

*/

/* alternative solution using a hardcoded list of primorials
    a primorial is a product of the first n primes. 

Instead of defining an array of primes, define an array of primorials to avoid calculating products. 
Then simply perform an equality test in a loop and output the index of the array. 
Keep in mind that 16th primorial is larger than 2^64 so when defining your array, simply reduce the 16th primorial to fit into 2^64, 
but keep it larger than 10^18 limit specified by the question.

*/

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        unsigned long long int n = stol(ltrim(rtrim(n_temp)));

        unsigned int result = primeCount(n);

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
