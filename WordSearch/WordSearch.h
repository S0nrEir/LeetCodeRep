#ifndef WORD_SEARCH_H
#define WORD_SEARCH_H

#include "../Entrance.h"
#include <string>
#include <vector>

using namespace std;

class WordSearch : public Entrance
{
public:
	WordSearch();
	~WordSearch();

	virtual void Impl();
private:
	bool exist(vector<vector<char>> board, string word);
};


#endif
