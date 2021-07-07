#include "WordSearch.h"
#include <iostream>
#include <vector>
#include <ctype.h>

using namespace std;

WordSearch::WordSearch()
{
	cout << "WordSearch constructed" << endl;
}

WordSearch::~WordSearch()
{
	cout << "WordSearch destructed" << endl;
	_flag.clear();
}

void WordSearch::Impl()
{
#pragma region init list
	
	vector<vector<char>> board;
	vector<char> row;
	row.emplace_back('A');
	row.emplace_back('B');
	row.emplace_back('C');
	row.emplace_back('E');
	board.emplace_back(row);

	row.clear();
	row.emplace_back('S');
	row.emplace_back('F');
	row.emplace_back('C');
	row.emplace_back('S');
	board.emplace_back(row);
	row.clear();

	row.clear();
	row.emplace_back('A');
	row.emplace_back('D');
	row.emplace_back('E');
	row.emplace_back('E');
	board.emplace_back(row);
	row.clear();

#pragma endregion

	string word = "ABCCED";
	cout << "word:" << word << ",result:" << exist(board, word) << endl;
}

bool WordSearch::exist(vector<vector<char>>& board, string word)
{
	if (board.size() == 0)
		return false;

	if (word.size() == 0)
		return false;

	if (board.size() * board[0].size() < word.length())
		return false;

	auto size = word.size();
	for (int i = 0; i < size; i++)
		word[i] = tolower(word[i]);

	auto startSearchIndex = 0;
	auto rowCount = board.size();
	auto colCount = board[0].size();

	for (int i = 0; i < rowCount; i++)
	{
		vector<bool> vec;
		for (int j = 0; j < colCount; j++)
			vec.push_back(false);

		_flag.push_back(vec);
	}

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			if (!tolower(board[i][j]) == word[0])
				continue;

			if (is_match(board, /*word[1]*/1, i, j, word))
				return true;
		}
	}

	return false;
}

bool WordSearch::is_match(vector<vector<char>>& board, int find_index, int i, int j, string word)
{
	if (word[find_index] == '\0')
		return true;

	if (i < 0 || i >= board.size())
		return false;

	if (j < 0 || j >= board[0].size())
		return false;

	if (word[find_index] != tolower(board[i][j]))
		return false;

	if (_flag[i][j])
		return false;

	_flag[i][j] = true;

	find_index = find_index + 1;
	return
		is_match(board, find_index , i + 1, j, word) ||
		is_match(board, find_index , i - 1, j, word) ||
		is_match(board, find_index , i, j + 1, word) ||
		is_match(board, find_index , i, j - 1, word);
}
