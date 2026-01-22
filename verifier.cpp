#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	
	int n;
	cin >> n;

	// Next n lines: hospital preference lists.
	vector<vector<int>> hospitalPreferences(n + 1, vector<int>(n));

	// Next n lines: student preference lists.
	vector<vector<int>> studentPreferences(n + 1, vector<int>(n + 1));
	//Parse example.in
	for (int h = 1; h <= n; h++)
	{
		for (int i = 0; i < n; i++)
		{
		cin >> hospitalPreferences[h][i];
		}
	}

	for (int a = 1; a <= n; a++)
	{
		for (int i = 0; i < n; i++)
		{
		cin >> studentPreferences[a][i];
		}
	}

	//Now that example.in is parsed and saved we parse example.out

	vector<int> hospitalMatch(n + 1, -1);
	vector<int> studentMatch(n + 1, -1);
	//Parse example.out
	for (int i=0; i<n; i++)
	{
		int h;
		int s;
		cin >> h >> s;
		hospitalMatch[h] = s;
		studentMatch[s] = h;//Take the values in and store in respective vectors
	}

	for(int i=1; i<hospitalPreferences.size(); i++)//Now we loop through the preference list and check if every item is a stable match
	{
		int currentStudent = studentMatch[i];

		for(int x = 0; x<hospitalPreferences[i].size(); x++)
		{
			int student = hospitalPreferences[i][x];
			if (student == currentStudent) break; //Stop if current match is reached

			int currentHospital = hospitalMatch[student];//Get the current hospital of that student
			//Now we have to check if that student prefers the hospital over its current match
			for (int y=0; y<studentPreferences[student].size(); y++)
			{
				if(studentPreferences[student][y] == i){ cout << "UNSTABLE.. BLOCKING PAIR:" << i << "," << student << endl; return 0;}//If blocking pair is found

				if(studentPreferences[student][y] == currentHospital)
				{
					break; //Not blocking case
				}
			}
		
		}




	}
	cout << "VALID STABLE" << endl;
	return 0;
}
