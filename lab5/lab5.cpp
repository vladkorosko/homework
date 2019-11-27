#include <iostream>
#include <fstream>
#include <string> 
#include <vector>

using namespace std;

struct dictionary 
{
	string word;
	int num;
};

int charInInt(char r)
{
	switch (r)
	{
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	case '0':
		return 0;
		break;
	default:
		break;
	}
}

vector<dictionary> fill(ifstream &fin)
{
	string str;
	vector<dictionary> a;
	while (getline(fin, str))
	{
		string s = "";
		int n = 0;
		bool t = true;
		for (int i = 0; i < str.length(); i++)
		{
			if (t)
			{
				if (str[i] == ' ')
					t = false;
				else
					s += str[i];
			}
			else
			{
				n *= 10;
				n += charInInt(str[i]);
			}
		}
		dictionary res;
		res.word = s;
		res.num = n;
		a.push_back(res);
	}
	return a;
}

void print(ifstream &fin, vector<dictionary> a)
{
	string str;
	while (getline(fin, str))
	{
		string s = "";
		int n = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				for (int j = 0; j < a.size(); j++)
				{
					if (a[j].word == s)
						n += a[j].num;
				}
				s = "";
			}
			else
				s += str[i];
		}
		for (int j = 0; j < a.size(); j++)
		{
			if (a[j].word == s)
				n += a[j].num;
		}
		cout << n << endl;
	}
}

int main()
{
	ifstream fin1("dictionary.txt");
	vector<dictionary> a = fill(fin1);
	fin1.close();
	ifstream fin2("text.txt");
	print(fin2, a);
	fin2.close();
	return 0;
}

