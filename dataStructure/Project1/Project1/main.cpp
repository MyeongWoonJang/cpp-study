#include <iostream>
#include <fstream>
#include <string>
#include <random>

#include "LinkedList.h"

using namespace std;

struct _tagData
{
	int		iData;
	//char	cName[20];
};

struct Champion
{
	std::string		name;
	int				hp;
	int				mp;
	int				attack;
	int				defense;
};	

random_device rd;
mt19937 gen(rd());

bool DataSort(const _tagData& tSrc, const _tagData& tDest)
{
	return tSrc.iData > tDest.iData;
}

int random(int min, int max);
void createData(int amount);
template <typename _T>
void readData(const CLinkedList<_T>& _Linkedlist);

int main()
{
	CLinkedList<Champion> listChampion;
	readData(listChampion);

	/*CLinkedList<int>	listInt;

	for (int i = 0; i < 100; ++i)
	{
		listInt.push_back(i);
	}

	cout << "Size : " << listInt.size() << endl;

	CLinkedList<int>::iterator iter;
	CLinkedList<int>::iterator iterEnd = listInt.end();

	for (iter = listInt.begin(); iter != iterEnd; ++iter)
	{
		cout << *iter << endl;
	}

	CLinkedList<int>::reverse_iterator riter;
	CLinkedList<int>::reverse_iterator riterEnd = listInt.rend();
	
	for (riter = listInt.rbegin(); riter != riterEnd; ++riter)
	{
		cout << *riter << endl;
	}

	CLinkedList<_tagData> dataList;

	cout << "========== data List ==========" << endl;

	for (int i = 0; i < 10; ++i)
	{
		_tagData tData = {};

		tData.iData = random(0, 99);

		dataList.push_back(tData);

		cout << tData.iData << endl;
	}

	cout << "========== sort ==========" << endl;
	dataList.sort(DataSort);

	CLinkedList<_tagData>::iterator iterD;
	CLinkedList<_tagData>::iterator iterDEnd = dataList.end();
	
	for (iterD = dataList.begin(); iterD != iterDEnd; ++iterD)
	{
		cout << (*iterD).iData << endl;
	}*/

	listChampion.size();

	return 0;
}

int random(int min, int max)
{
	uniform_int_distribution<> uid(min, max);

	return uid(gen);
}

void createData(int amount)
{
	ofstream out;
	out.open("data.txt");

	string alphabet{ "abcdefghijklmnopqrstuvwxyz" };

	for (int i = 0; i < amount; ++i)
	{
		// ·£´ýÇÑ ±æÀÌÀÇ ÀÌ¸§
		string randomName;
		int nameLength = random(5, 10);

		for (int i = 0; i < nameLength; ++i)
		{
			int randomValue = random(0, 25);
			randomName.push_back(alphabet[randomValue]);
		}
		randomName[0] = toupper(randomName[0]);

		// ·£´ý hp
		int randomHp = random(100, 200);
		// ·£´ý mp
		int randomMp = random(60, 120);
		// ·£´ý attack
		int randomAttack = random(50, 100);
		// ·£´ý defense
		int randomDefense = random(0, 20);

		out << randomName << ' ' << randomHp << ' ' << randomMp
			<< ' ' << randomAttack << ' ' << randomDefense << '\n';
	}
}

template<typename _T>
void readData(CLinkedList<_T>& _Linkedlist)
{
	Champion c = { "Lenoa" ,120, 100, 20, 3 };

	_Linkedlist.push_back(c);
}
