#include <iostream>
#include <string>
#include <vector>
using namespace std;
void Backtracking(int length);
bool Checksudoku(int x, int y);
int Board[9][9] = { false };
const int boardlength = 9;
bool answer = false;
vector<pair<int, int>> zeros;
int main()
{
	for (int i = 0; i < boardlength; i++)
	{
		for (int j = 0; j < boardlength; j++)
		{
			cin >> Board[i][j];
			if (Board[i][j] == 0)
			{
				zeros.push_back(make_pair(i, j));
			}
		}
	}
	Backtracking(0);
	cout << "\n";

}
void Backtracking(int length)
{

	if (length == zeros.size())
	{
		cout << "\n";
		for (int i = 0; i < boardlength; i++)
		{
			for (int j = 0; j < boardlength; j++)
			{
				cout << Board[i][j] << " ";
			}
			cout << "\n";
		}
		answer = true;
		return;
	}


	for (int j = 0; j < 9; j++)
	{

		Board[zeros[length].first][zeros[length].second] = j + 1;
		if (Checksudoku(zeros[length].first, zeros[length].second))
		{
			Backtracking(length + 1);
		}
		if (answer)
		{
			return;
		}
	}
	Board[zeros[length].first][zeros[length].second] = 0;
	return;
}
bool Checksudoku(int x, int y)
{
	for (int i = 0; i < 9; i++)
	{
		if (y != i && Board[x][i] == Board[x][y])
			return false;
		if (x != i && Board[i][y] == Board[x][y])
			return false;
	}
	for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)
	{
		for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
		{
			if (i != x && j != y && Board[i][j] != 0 && Board[x][y] == Board[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
