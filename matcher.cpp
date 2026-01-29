#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    // Input Format: The input describes preferences for a one-to-one market with complete strict rankings.
    //First line: integer n.
    int n;

    // Handle edge case where input is an empty file
    if (!(cin >> n))
    {
        cerr << "Error: Empty File." << endl;
        return 1;
    }

    // Handle edge case where n is negative/zero
    if (n <= 0)
    {
        cerr << "Error: Negative numbers or zero as input is not acceptable." << endl;
        return 1;
    }

    // Next n lines: hospital preference lists.
    vector<vector<int>> hospitalPreferences(n + 1, vector<int>(n));

    // Next n lines: student preference lists.
    vector<vector<int>> studentPreferences(n + 1, vector<int>(n + 1));

    for (int h = 1; h <= n; h++)
    {
        // Use bool to track if any duplicates are present (violates G-S)
        bool duplicateHospital[n + 1] = {false};

        for (int i = 0; i < n; i++)
        {
            // Handle uneven input
            if (!(cin >> hospitalPreferences[h][i]))
            {
                cerr << "Error: Invalid input." << endl;
                return 1;
            }

            // Check input is valid
            if (hospitalPreferences[h][i] < 1 || hospitalPreferences[h][i] > n)
            {
                cerr << "Error: Invalid input.";
                return 1;
            }

            // Raise error if duplicates present
            if (duplicateHospital[hospitalPreferences[h][i]])
            {
                cerr << "Error: Invalid input.";
                return 1;
            }

            duplicateHospital[hospitalPreferences[h][i]] = true;
        }
    }


    for (int a = 1; a <= n; a++)
    {
        // Use bool to track if any duplicates are present (violates G-S)
        bool duplicateStudent[n + 1] = {false};

        for (int i = 0; i < n; i++)
        {
            // Handle uneven input
            if (!(cin >> studentPreferences[a][i]))
            {
                cerr << "Error: Invalid input." << endl;
                return 1;
            }

            // Check input is valid
            if (studentPreferences[a][i] < 1 || studentPreferences[a][i] > n)
            {
                cerr << "Error: Invalid input.";
                return 1;
            }

            // Raise error if duplicates present
            if (duplicateStudent[studentPreferences[a][i]])
            {
                cerr << "Error: Invalid input.";
                return 1;
            }

            duplicateStudent[studentPreferences[a][i]] = true;
        }
    }

    // Stores paired students
    vector<int> studentPaired(n + 1, 0);

    // Stores list of students hospitals wish to pair with next if other preferences don't work out
    vector<int> nextStudent(n + 1, 0);

    // Queue of hospitals not yet matched
    queue<int> freeHospitals;

    //Initialize each person and hospital to be free.
    // Push all hospitals into queue as no pairings have been made thus far
    for (int h = 1; h <= n; h++)
        freeHospitals.push(h);

    // Task A: Matching Engine: Implement the hospital-proposing deferred acceptance algorithm
    // if a hospital is present in the freeHospital queue, we know they have not been 
    // paired with any student

    //while (some hospital is free and hasn’t been matched/assigned to every applicant)
    while (!freeHospitals.empty())
    {
        //Choose such a hospital h
        int h = freeHospitals.front();
        freeHospitals.pop();

        // Sanity check to avoid going out of bounds
        if (nextStudent[h] >= n)
            continue;

        //a = 1st applicant on h's list to whom h has not been matched
        int a = hospitalPreferences[h][nextStudent[h]];
        nextStudent[h]++;

        // if (a is free)
        if (studentPaired[a] == 0)
        {
            // assign h to a
            studentPaired[a] = h;
        }

        // else if (a prefers h to her/his current assignment h')
        // assign a and h, and h’ has a slot free
        else
        {
            int current = studentPaired[a];

            int preferred = -1;
            for (int i = 0; i < n; i++)
            {
                // figure out which hospital the student prefers more (current or new possible pairing)
                if (studentPreferences[a][i] == h || studentPreferences[h][i] == current)
                {
                    preferred = studentPreferences[a][i];
                    break;
                }
            }

            if (preferred == h)
            {
                studentPaired[a] = h;
                freeHospitals.push(current);
            }

            // else a rejects h (add it back to free hospitals )
            else
                freeHospitals.push(h);
            
        }

    }

    // Output Format for Matching Algorithm
    //Output n lines, one per hospital i:
    //i j
    // meaning hospital i is matched to student j.

    vector<int> output(n + 1, 0);
    for (int s = 1; s <= n; s++)
    {
        int h = studentPaired[s];
        output[h] = s;
    }

    // format output as expected
    for (int h = 1; h <= n; h++)
        cout << h << " " << output[h] << endl;

    return 0;

}
