// Проба новых функций в C++, которые я освоил
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>

using namespace std;

class Player;
class Weapon;
class Armor;
class MenuPeace;

class Player
{
public:
	string name;
	int hpCurr, hpMax, lvl, exp;

	Player(string cName, int cHpCurr, int cHpMax, int cLvl, int cExp)
	{
		name = cName;
		hpCurr = cHpCurr;
		hpMax = cHpMax;
		lvl = cLvl;
		exp = cExp;
	}
};

class Weapon
{
public:
	string name;
	int damageMin, damageMax, durabilityCurr, durabilityMax;

	Weapon(string cName, int cDamageMin, int cDamageMax, int cDurabilityCurr, int cDurabilityMax)
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

	Armor(string cName, int cDefence, int cDurabilityCurr, int cDurabilityMax)
	{
		name = cName;
		defence = cDefence;
		durabilityCurr = cDurabilityCurr;
		durabilityMax = cDurabilityMax;
	}
};

void MenuPeaceUp(const Player& player, const Armor& playerArmor, const Weapon& playerWeapon)
{
	system("cls");

	cout << player.name << endl
		<< "hp " << player.hpCurr << " из " << player.hpMax << endl << endl
		<< "броня " << playerArmor.name << endl
		<< "класс брони " << playerArmor.defence << endl
		<< "прочность " << playerArmor.durabilityCurr << " из " << playerArmor.durabilityMax << endl << endl
		<< "оружие " << playerWeapon.name << endl
		<< "урон " << playerWeapon.damageMin << "-" << playerWeapon.damageMax << endl
		<< "состояние оружия " << playerWeapon.durabilityCurr << " из " << playerWeapon.durabilityMax;
}

void MenuPeaceMiddle()
{
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}

void MenuPeaceDown(const Player& player)
{
	cout << "Твои действия:" << endl
		<< "1) стоять настороже" << endl
		<< "2) отдыхать" << endl;
}

int main()
{
	// русский язык в консоли
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// переменные
	int tempInt;
	string tempString;
	bool check = false;

	// инициализация игрока
	Weapon emptyWeapon("Кулаки", 1, 2, 100, 100);
	Armor emptyArmor("голый", 0, 100, 100);

	Weapon playerWeapon = emptyWeapon;
	Armor playerArmor = emptyArmor;



	

	


	

	// пошла жара
	cout << "Игра \"Мудила\"" << endl;
	cout << "Введите свое имя: ";
	cin >> tempString;
	Player player(tempString, 10, 10, 1, 0);
	cout << "\nПривет, " << player.name << "! Готов отправиться в приключение? \n1) Да\n2) Нет\n";
	cin >> tempInt;

	do 
	{
		switch (tempInt) {
		case 1:
			check = true;
			break;
		case 2:
			cout << "\nНу и вали тогда нахер!!!\n";
			return 0;
		default:
			cout << "\nЧе за херню ты ввел? Попробуй еще раз.\n\nГотов отправиться в приключение? \n1) Да\n2) Нет\n";
			cin >> tempInt;
			break;
		}
	} while (!check);

	// Очистка консоли
	system("cls");

	cout << "\nИтак, уебок, ой, то есть " << player.name << ", ты, по классике жанра, полюбому сдохнешь, вопрос когда." << endl
		<< "На тебя будут нападать рандомные враги и с них будет падать рандомный лут. Отсоси богу рандома, чтобы он снизошел до тебя и тебе повезло. Удачи." << endl
		<< "P.S. Знай, что если ты выберешь вариант 0, то можешь прочитать справку по данному экрану" << endl << endl
		<< "для продолжения нажми любую кнопку" << endl;
	_getch();

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
	TODO проработать отрисовку меню с зонами
	TODO проверка в menu middle длины строк когда буду делать перегрузку или вообще перепридумать

	сперва делаю монстры, дроп оружия и бронек, сам бой и учет опыта
	____________________________________________________________________________________________________________________________________________________
	*/











	check = false;

	while (!check)
	{
		MenuPeaceUp(player, playerArmor, playerWeapon);
		MenuPeaceMiddle();
		MenuPeaceDown(player);

		tempInt = _getch();
		
		switch (tempInt)
		{
		case 49:
			if (player.hpCurr < player.hpMax)
			{
				player.hpCurr++;
				check = true;
				break;
			}
		case 50:
			if ((player.hpMax - player.hpCurr) >= (player.lvl + 1))
			{
				player.hpCurr += (player.lvl + 1);
			}
			else
			{
				player.hpCurr = player.hpMax;
			}
			check = true;
			break;
		default:
			break;
		}
	}

	// отсюда пилю рандом на атаку и далее по списку
	



		
}

