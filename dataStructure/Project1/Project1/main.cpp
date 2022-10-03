#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

struct Champion
{
	string		name;
	int			hp;
	int			mp;
	int			attack;
	int			defense;
};

random_device rd;
mt19937 gen(rd());

int random(int min, int max);
void createData(int amount);

int main()
{
	createData(1000);
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
