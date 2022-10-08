#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <iomanip>

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
	// readData(listChampion);
	
	Champion c[10] = { 
		{"Wikzae", 162, 83, 91, 16},
		{"Vhmlucb", 124, 108, 54, 3},
		{"Dtufrkax", 127, 94, 98, 8},
		{"Qrbqrt", 144, 73, 53, 12},
		{"Ylckbqbwhg", 113, 65, 52, 1},
		{"Ydmivi", 184, 60, 83, 12},
		{"Fxaghnrx", 157, 110, 86, 7},
		{"Felqmyixn", 145, 93, 55, 19},
		{"Qhribos", 158, 69, 74, 14},
		{"Acrvstwqyg", 123, 113, 79, 0},
	};

	for (int i = 0; i < 10; ++i)
	{
		listChampion.push_back(c[i]);
	}
	
	cout << listChampion.size() << endl;

	CLinkedList<Champion>::iterator iter;
	CLinkedList<Champion>::iterator iterEnd = listChampion.end();
	
	for (iter = listChampion.begin(); iter != iterEnd; ++iter)
	{
		Champion temp;
		temp = *iter;

		cout.setf(ios::left);
		cout << setw(4) << "Name : "	 << setw(20) << temp.name
			 << setw(4) << "HP : "		 << setw(10) << temp.hp
			 << setw(4) << "MP : "		 << setw(10) << temp.mp
			 << setw(4) << "Attack : "  << setw(10) << temp.attack
			 << setw(4) << "Defense : " << setw(10) << temp.defense << "\n";
	}


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

	_Linkedlist->push_back();
}
