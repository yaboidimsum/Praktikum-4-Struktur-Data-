#include <iostream>

using namespace std;

//https://www.geeksforgeeks.org/program-nth-catalan-number/
//catalan number - using dynamic programming

unsigned long int catalan_DP(unsigned int n)
{
    // Tabel untuk menyimpan hasil subproblem
    unsigned long int catalan[n + 1];

    // Menginisialisasi dua value pertama dalam tabel
    catalan[0] = catalan[1] = 1;

     // Mengisi entri dalam catalan[] menggunakan rekursif
    for (int i = 2; i <= n; i++)
    {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
    // Mengembalikan last entry
    return catalan[n];
}

int main()
{
    unsigned long int test_case, input;

    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        cin >> input;

        if (input == 0)
        {
            cout << "0" << endl;

            continue;
        }
        else
        {
            cout << catalan_DP(input) << endl;}
    }
    return 0;
}
