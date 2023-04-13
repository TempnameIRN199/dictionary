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

// Используя контейнер map реализовать программу – словарь.
// Основные возможности :
// ■ заполнение словаря с клавиатуры
// ■ поиск слова;
// ■ добавление слов
// ■ удаление слов;
// ■ запись словаря в файл.

// Словарь должен быть реализован в виде контейнера map, где ключом является слово, а значением – его перевод.
// При заполнении словаря с клавиатуры, пользователь вводит слово и его перевод, разделенные пробелом.
// При поиске слова, пользователь вводит слово, и программа выводит его перевод.
// При добавлении слова, пользователь вводит слово и его перевод, разделенные пробелом.
// При удалении слова, пользователь вводит слово, и программа удаляет его из словаря.
// При записи словаря в файл, пользователь вводит имя файла, и программа записывает словарь в этот файл.

// В программе должны быть реализованы следующие функции :
// ■ заполнение словаря с клавиатуры;
// ■ поиск слова;
// ■ добавление слов;
// ■ удаление слов;
// ■ запись словаря в файл;
// ■ чтение словаря из файла.

// В программе должны быть реализованы следующие классы :
// ■ класс Dictionary, реализующий словарь;
// ■ класс DictionaryException, реализующий исключения, возникающие при работе со словарем.

// В программе должны быть реализованы следующие исключения :
// ■ слово не найдено;
// ■ слово уже существует;
// ■ ошибка открытия файла.

// В программе должны быть реализованы следующие операции :
// ■ операция ввода словаря с клавиатуры;
// ■ операция вывода словаря на экран;
// ■ операция поиска слова;
// ■ операция добавления слова;
// ■ операция удаления слова;

// В программе должны быть реализованы следующие операторы :
// ■ оператор ввода словаря из файла;
// ■ оператор вывода словаря в файл.

// В программе должны быть реализованы следующие методы :
// ■ метод заполнения словаря с клавиатуры;
// ■ метод поиска слова;
// ■ метод добавления слова;
// ■ метод удаления слова;
// ■ метод записи словаря в файл;
// ■ метод чтения словаря из файла.

// В программе должны быть реализованы следующие конструкторы :
// ■ конструктор по умолчанию;
// ■ конструктор копирования;
// ■ конструктор с параметрами.

// В программе должны быть реализованы следующие деструкторы :
// ■ деструктор по умолчанию.

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
	void fillDictionary() // этот метод 
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
	void findWord() // поиск слова
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
	void addWord() // добавление слова
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
	void deleteWord() // удаление слова
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
	void writeDictionary() // запись словаря в файл
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