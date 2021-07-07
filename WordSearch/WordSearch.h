#ifndef WORD_SEARCH_H
#define WORD_SEARCH_H

#include "../Entrance.h"
#include <string>
#include <vector>

using namespace std;

/// <summary>
/// 给定一个mxn二维字符网格board和一个字符串单词word。如果word存在于网格中，返回true ；否则，返回false 。
/// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
/// </summary>
class WordSearch : public Entrance
{
public:
	WordSearch();
	~WordSearch();

	virtual void Impl();
private:
	bool exist(vector<vector<char>> &board, string word);
	bool is_match(vector<vector<char>>& board,int find_index,int i,int j,string word);

	vector<vector<bool>> _flag;
};


#endif
