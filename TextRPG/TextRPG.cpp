class Player
{
public:
	string name;
	int hpCurr, hpMax;

	Player(string cName, int cHpCurr, int cHpMax)
	{
		name = cName;
		hpCurr = cHpCurr;
		hpMax = cHpMax;
	}
};

class Weapon 
{
public:
	string name;
	int damageMin, damageMax, durabilityCurr, durabilityMax;

	Weapon (string cName, int cDamageMin, int cDamageMax, int cDurabilityCurr, int cDurabilityMax)
	{
		name = cName;
		damageMin = cDamageMin;
		damageMax = cDamageMax;
		durabilityCurr = cDurabilityCurr;
		durabilityMax = cDurabilityMax;
	}
};

class Armor
{
public:
	string name;
	int defence, durabilityCurr, durabilityMax;

	Armor (string cName, int cDurabilityCurr, int cDurabilityMax)
	{
		name = cName;
		durabilityCurr = cDurabilityCurr;
		durabilityMax = cDurabilityMax;
	}
};










// Проба новых функций в C++, которые я освоил
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
	// русский язык в консоли
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	

	// переменные
	int tempInt;
	string tempString;
	bool check = false;

	Weapon playerWeapon("Кулаки", 1, 2, 100, 100);
	Armor playerArmor("голый", 100, 100);


	

	// пошла жара
	cout << "Игра \"Мудила\"" << endl;
	cout << "Введите свое имя: ";
	cin >> tempString;
	Player player(tempString, 10, 10);
	cout << "Привет, " << player.name << "! Готов отправиться в приключение? \n1) Да\n2) Нет\n";
	cin >> tempInt;

	do 
	{
		switch (tempInt) {
		case 1:
			cout << "Ну тогда погнали!!!";
			check = true;
			break;
		case 2:
			cout << "Ну и вали тогда нахер!!!";
			return 0;
		default:
			cout << "Че за херню ты ввел? Попробуй еще раз.\n\nГотов отправиться в приключение? \n1) Да\n2) Нет\n";
			cin >> tempInt;
			break;
		}
	} while (!check);

	cout << "\nИтак, уебок, ой, то есть " << player.name << ", ты, по классике жанра, полюбому сдохнешь, вопрос когда." << endl
		<< "На тебя будут нападать рандомные враги и с них будет падать рандомный лут. Отсоси богу рандома, чтобы он снизошел до тебя и тебе повезло. Удачи." << endl
		<< "P.S. Знай, что если ты выберешь вариант 0, то можешь прочитать справку по данному экрану" << endl
		<< "для продолжения напиши 1" << endl;
	cin >> tempInt;

	/*
	-----------------------------------------------------------------------------------------------------------------------------------------------------
	есть 3 вида монстров, у них рандомное количество хитов, атака и броня. Их мощь скалируется от уровня персонажа и порядкового номера боя.
		
	из лута есть лечилки (в том числе еда), лечки которые добавляют хп постоянно, есть оружие, которое дропается в зависимости от уровня, есть броньки.
	у бронек и оружия есть прочность. чем ниже прочность, тем меньше урон и защита.
		
	у персонажа есть опыт, уровень, и скиллы, которые можно получать от уровня. 
	уровни:
	2 100
	3 200
	4 400
	и т.д.
	каждый уровень растет хп

	также есть навыки, которые растут от количества использования оружия. также их можно прокачать перками.
	навыки:
	кулаки
	нож
	короткий меч
	длинный меч
	полуторный меч
	двуручный меч
	уворот
	щит
	сила (размер инвентаря) ??? подумать как растет
	.........

	перки: 
	рост прироста опыта
	медленнее ломается оружие
	медленнее ломается броня
	регенерация здоровья
	ремонт оружия
	ремонт брони
	ловкость (увороты и точность попадания)
	обучаемость (усиленный рост навыков)
	+1 од (максимум 10)

	варианты команд: 
	стоять настороже (нет внезапной атаки и можно нанести первый удар, но хп растет по 1)
	отдыхать (хп растет по 1+lvl, но если враг нападет, то ударит первым)
	поменять оружие, починить оружие, починить доспехи (вероятность 50/50)
	использовать предмет (вероятность 10%)

	команды во время боя:
	атаковать (в зависимости от оружия. кулаки 3 - двуручник 7)
	использовать предмет (3 од)
	защита (2 од)
	................................













	нужно придумать как отрисовывать пункты по скиллам и игнорировать ввод еще не изученных скиллов
	фиксированный размер консоли


	TODO сделать справку, размер инвентаря, вес оружия и прочего
	TODO прочность кулаков и голого (наверное перегрузка, но тогда нужен аналог ifExist)



	сперва делаю хп броня атака, монстры, дроп оружия и бронек, и учет опыта
	____________________________________________________________________________________________________________________________________________________
	*/



	cout << player.name << endl
		<< "hp " << player.hpCurr << " из " << player.hpMax << endl << endl
		<< "броня " << playerArmor.name << endl
		<< "класс брони " << playerArmor.defence << endl
		<< "прочность " << playerArmor.durabilityCurr << " из " << playerArmor.durabilityMax << endl << endl
		<< "оружие " << playerWeapon.name << endl
		<< "урон " << playerWeapon.damageMin << "-" << playerWeapon.damageMax << endl
		<< "состояние оружия " << playerWeapon.durabilityCurr << " из " << playerWeapon.durabilityMax << endl << endl << endl << endl
		<< "Твои действия:" << endl
		<< "1) стоять настороже" << endl
		<< "2) отдыхать" << endl
		<< "3) поменять оружие" << endl;

		
}