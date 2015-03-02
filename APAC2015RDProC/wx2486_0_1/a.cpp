#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 300;
int n;
int mtr[MAX][MAX];
bool used[MAX][MAX];

void dig(int i, int j)
{
	used[i][j] = true;
	for (int ii=-1; ii<=1; ii++)
		for (int jj=-1; jj<=1; jj++)
			if (i+ii>=0 && i+ii<n && j+jj>=0 && j+jj<n
				&& mtr[i+ii][j+jj] >= 0 && !used[i+ii][j+jj])
			{
				used[i+ii][j+jj] = true;
				if (mtr[i+ii][j+jj] == 0)
					dig(i+ii, j+jj);
			}
}

int main()
{
	int cn;
	cin >> cn;

	for (int cc=1; cc<=cn; cc++)
	{
		cin >> n;

		for (int i=0; i<n; i++)
		{
			string s;
			cin >> s;
			for (int j=0; j<n; j++)
				mtr[i][j] = (s[j] == '*') ? -1 : 0;
		}

		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (mtr[i][j] < 0)
					for (int ii=-1; ii<=1; ii++)
						for (int jj=-1; jj<=1; jj++)
							if (i+ii>=0 && i+ii<n && j+jj>=0 && j+jj<n && mtr[i+ii][j+jj]>=0)
								mtr[i+ii][j+jj]++;

		fill_n(used[0], sizeof(used), 0);

		int click = 0;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (mtr[i][j] == 0 && !used[i][j])
				{
					click++;
					dig(i, j);
				}

		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (mtr[i][j] >= 0 && !used[i][j])
					click++;

		cout << "Case #" << cc << ": " << click << endl;
	}

	return 0;
}
