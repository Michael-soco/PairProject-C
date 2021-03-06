// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//
#pragma once
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>

// TODO: 在此处引用程序需要的其他头文件
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstring>
#include<sstream>
#include<algorithm>

using namespace std;
class Word
{
public:
	string name;
	int count;

	bool isWord();
	Word(string na)
	{
		name = na;
		count = 1;
	}
};

class Paper
{
public:
	int general_wordCount;

	vector<Word> Title;
	vector<Word> Abstract;

	void titleFind(Word W);
	void abstractFind(Word W);
	void Vsort();
	int cmp(Word W1,Word W2);
	int getgeneral_wordCount(int per);

	Paper()
	{
		general_wordCount = 0;
	}
};

void Paper::titleFind(Word W)
{
	if (W.isWord())
	{
		for (vector<Word>::iterator it = Title.begin();it != Title.end();it++)
		{
			if (it->name == W.name)
			{
				it->count++;
				return;
			}
		}
		Title.push_back(W);
	}
}

void Paper::abstractFind(Word W)
{
	if (W.isWord())
	{
		for (vector<Word>::iterator it = Abstract.begin();it != Abstract.end();it++)
		{
			if (it->name == W.name)
			{
				it->count++;
				return;
			}
		}
		Abstract.push_back(W);
	}
}
int Paper::cmp(Word W1,Word W2)
{
	return W1.count > W2.count;
}

void Paper::Vsort()
{
	sort(Title.begin(), Title.end(), cmp);
	sort(Abstract.begin(), Abstract.end(), cmp);
}

int Paper::getgeneral_wordCount(int weight)
{
	for (vector<Word>::iterator it = Title.begin();it != Title.end();it++)
	{
		general_wordCount = general_wordCount + it->count * weight;
	}

	for (vector<Word>::iterator it = Abstract.begin();it != Abstract.end();it++)
	{
		general_wordCount = general_wordCount + it->count;
	}
}


bool Word::isWord()
{
	int l = name.length();
	if (l < 4) return false;
	for (int i = 0;i < 4;i++)
	{
		if (!(name[i] >= 97 && name[i] <= 122)) return false;
		else if (name[i] >= 65 && name[i] <= 90)
			name[i] = name[i] + 32;		//转小写
	}
	for (int i = 4;i < l;i++)
	{
		if (!((name[i] >= 97 && name[i] <= 122) || (name[i] >= 48 && name[i] <= 57)))
			return false;
		else if(name[i] >= 65 && name[i] <= 90)	//转小写
			name[i] = name[i] + 32;
	}
	return true;
}
