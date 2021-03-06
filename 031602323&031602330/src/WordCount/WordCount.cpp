// WordCount.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define title true
#define abstract false

void writeTxt(Paper p,string fname)
{
	int i = 0;
	ofstream outfile;
	outfile.open(fname, std::ios::out | std::ios::ate);
	if (!outfile.is_open())
		cout << "open error!" << endl;

	outfile << "characters:" << << endl;
	outfile << "words:" <<  << endl;
	outfile << "lines:" <<  << endl;


	outfile.close();
}



int main(int argc,const char* argv[])
{
	vector<Paper> paper;

	//读文件
	string filename;
	ifstream ifs(filename);
	string line;
	int lineCount;
	bool type;
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
	}
	else
	{
		for (int i = 0;getline(ifs, line);i++)
		{
			istringstream iss(line);
			string str;

			if (line != "") lineCount++;

			for (int j = 0;iss >> str;j++)
			{
				if (j == 0 && str == "Title:")
					type = title;
				else if (j == 0 && str == "Abstract:")
					type = abstract;

				Word word(str);
				if (type == title&&j!=0)
				{
					paper[i].titleFind(word);
				}
				else if (type == abstract && j != 0)
				{
					paper[i].abstractFind(word);
				}
			}
		}
	}

	for (int i = 1;i < argc;i=i+2)
	{
		if (argv[i] == "-i")
		{
			string inf_name = argv[i + 1];
		}
		else if (argv[i] == "-o")
		{
			string outf_name = argv[i + 1];
		}
		else if (argv[i] == "-w")
		{
			if (argv[i + 1] == "0")
			{

			}
			else if (argv[i + 1] == "1")
			{

			}
			else
			{
				cout << "-w相关参数错误！" << endl;
			}
		}
		else if (argv[i]=="-m")
		{
			string s = argv[i + 1];
			int num = stoi(s);
		}
		else if (argv[i] == "-n")
		{
			string s = argv[i + 1];
			int num = stoi(s);
		}
	}










    return 0;
}

