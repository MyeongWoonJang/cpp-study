#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <random>
#include <iomanip>
#include <chrono>

#include "LinkedList.h"

using namespace std;
using namespace chrono;

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
void readData(CLinkedList<_T>& _Linkedlist);
template <>
void readData(CLinkedList<Champion>& _Linkedlist);

int main()
{
	createData(10000);

	// 코드 실행시간을 확인하기 위한 변수들
	//============================================
	system_clock::time_point begin_time, end_time;
	milliseconds diff_time;
	//============================================

	CLinkedList<Champion> listChampion;

	cout << "파일에서 데이터를 읽어 옵니다..." << endl;
	begin_time = system_clock::now();

	readData(listChampion);

	end_time = system_clock::now();
	
	diff_time = duration_cast<milliseconds>(end_time - begin_time);
	cout << "완료(지연시간 " << (int)diff_time.count() << "ms)" << endl;

	/*Champion c[10] = { 
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
			 << setw(4) << "Attack : "   << setw(10) << temp.attack
			 << setw(4) << "Defense : "  << setw(10) << temp.defense << "\n";
	}*/


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

	cout << "리스트의 크기 : " << listChampion.size() << endl;

	/*while (true)
	{

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
		// 랜덤한 길이의 이름
		string randomName;
		int nameLength = random(5, 10);

		for (int i = 0; i < nameLength; ++i)
		{
			int randomValue = random(0, 25);
			randomName.push_back(alphabet[randomValue]);
		}
		randomName[0] = toupper(randomName[0]);

		// 랜덤 hp
		int randomHp = random(100, 200);
		// 랜덤 mp
		int randomMp = random(60, 120);
		// 랜덤 attack
		int randomAttack = random(50, 100);
		// 랜덤 defense
		int randomDefense = random(0, 20);

		out << randomName << ' ' << randomHp << ' ' << randomMp
			<< ' ' << randomAttack << ' ' << randomDefense << '\n';
	}
}

template<>
void readData(CLinkedList<Champion>& _Linkedlist)
{
	ifstream fin("data.txt");
	
	char line[100];

	while (fin.getline(line, sizeof(line)))
	{
		Champion c;
		istringstream iss(line);

		iss >> c.name >> c.hp >> c.mp >> c.attack >> c.defense;
		_Linkedlist.push_back(c);
	}
	
	fin.close();
}
