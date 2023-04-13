#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class DictionaryException
{
private:
	string message;
public:
	DictionaryException(string message)
	{
		this->message = message;
	}
	string getMessage()
	{
		return message;
	}
};

class Dictionary
{
private:
	map<string, string> dictionary;
public:
	Dictionary(){}
	Dictionary(const Dictionary& d)
	{
		dictionary = d.dictionary;
	}
	Dictionary(map<string, string> dictionary)
	{
		this->dictionary = dictionary;
	}
	~Dictionary(){}
	void fillDictionary()
	{
		string word, translate;
		cout << "Enter word and translate: ";
		cin >> word >> translate;
		if (dictionary.find(word) != dictionary.end())
		{
			throw DictionaryException("Word already exists");
		}
		dictionary.insert(pair<string, string>(word, translate));
	}
	void findWord() 
	{
		string word;
		cout << "Enter word: ";
		cin >> word;
		if (dictionary.find(word) == dictionary.end())
		{
			throw DictionaryException("Word not found");
		}
		cout << "Translate: " << dictionary[word] << endl;
	}
	void addWord() 
	{
		string word, translate;
		cout << "Enter word and translate: ";
		cin >> word >> translate;
		if (dictionary.find(word) != dictionary.end())
		{
			throw DictionaryException("Word already exists");
		}
		dictionary.insert(pair<string, string>(word, translate));
	}
	void deleteWord()
	{
		string word;
		cout << "Enter word: ";
		cin >> word;
		if (dictionary.find(word) == dictionary.end())
		{
			throw DictionaryException("Word not found");
		}
		dictionary.erase(word);
	}
	void writeDictionary()
	{
		string fileName;
		cout << "Enter file name: ";
		cin >> fileName;
		ofstream fout(fileName);
		if (!fout.is_open())
		{
			throw DictionaryException("Error opening file");
		}
		for (auto it = dictionary.begin(); it != dictionary.end(); it++)
		{
			fout << it->first << " " << it->second << endl;
		}
		fout.close();
	}
	void readDictionary() 
	{
		string fileName; 
		cout << "Enter file name: "; 
		cin >> fileName; 
		ifstream fin(fileName);
		if (!fin.is_open())
		{
			throw DictionaryException("Error opening file");
		}
		string word, translate;
		while (!fin.eof())
		{
			fin >> word >> translate;
			dictionary.insert(pair<string, string>(word, translate));

		}
		for (auto it = dictionary.begin(); it != dictionary.end(); it++)
		{
			cout << it->first << " " << it->second << endl;
		}

		fin.close();
	}
	friend istream& operator>>(istream& in, Dictionary& d) 
	{
		string word, translate;
		while (!in.eof())
		{
			in >> word >> translate;
			d.dictionary.insert(pair<string, string>(word, translate));
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, Dictionary& d)
	{
		for (auto it = d.dictionary.begin(); it != d.dictionary.end(); it++)
		{
			out << it->first << " " << it->second << endl;
		}
		return out;
	}
};

int main()
{
	Dictionary d;
	int choice;
	while (true)
	{
		cout << "1. Fill dictionary" << endl;
		cout << "2. Find word" << endl;
		cout << "3. Add word" << endl;
		cout << "4. Delete word" << endl;
		cout << "5. Write dictionary" << endl;
		cout << "6. Read dictionary" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			try
			{
				d.fillDictionary();
			}
			catch (DictionaryException e)
			{
				cout << e.getMessage() << endl;
			}
			break;
		case 2:
			try
			{
				d.findWord();
			}
			catch (DictionaryException e)
			{
				cout << e.getMessage() << endl;
			}
			break;
		case 3:
			try
			{
				d.addWord();
			}
			catch (DictionaryException e)
			{
				cout << e.getMessage() << endl;
			}
			break;
		case 4:
			try
			{
				d.deleteWord();
			}
			catch (DictionaryException e)
			{
				cout << e.getMessage() << endl;
			}
			break;
		case 5:
			try
			{
				d.writeDictionary();
			}
			catch (DictionaryException e)
			{
				cout << e.getMessage() << endl;
			}
			break;
		case 6:
			try
			{
				d.readDictionary();
			}
			catch (DictionaryException e)
			{
				cout << e.getMessage() << endl;
			}
			break;
		case 7:
			exit(0);
		default:
			cout << "Invalid choice" << endl;
		}
	}
	return 0;
}