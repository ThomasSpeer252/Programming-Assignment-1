#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    // Include a check ensuring user gives n
    if (argc != 2)
    {
        cerr << "Program Paused, provide n";
        return 1;
    }

    // Convert string to integer and create random generation 
    int n = stoi(argv[1]); 
    mt19937 rng(random_device{}());
    cout << n << "\n";

    // Create vector to hold preference lists
    vector<int> pref_lists(n);
    iota(pref_lists.begin(), pref_lists.end(), 1);

    // Create hospital preference lists 
    for (int h = 1; h <= n; h++)
    {
        // Responsible for the randomness of each list
        shuffle(pref_lists.begin(), pref_lists.end(), rng);
        for (int i = 0; i < n; i++)
            cout << pref_lists[i] << (i + 1 == n ? '\n' : ' ');
    }

    // Create student preference lists 
    for (int s = 1; s <= n; s++)
    {
        // Responsible for the randomness of each list
        shuffle(pref_lists.begin(), pref_lists.end(), rng);
        for (int i = 0; i < n; i++)
            cout << pref_lists[i] << (i + 1 == n ? '\n' : ' ');
    }

    return 0;

}