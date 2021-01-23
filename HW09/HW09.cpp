// CS154-HW09-P1.cpp

#include <iostream> 
#define HEAL_VALID 20
#define HEAL_EFFECT 10
#define TOTAL_MONEY 50 
using namespace std;

class Weapon {
	// 此处需填写代码
public:
	Weapon(int a,int b) : effect(a),price(b){}

	const int effect; 
	const int price;
};

class Actor {
	char* name; 
	int hp;
	int atk; 
	int def; 
	bool heal;
	bool isPlayer;
	// 此处需填写代码
public:
	Actor(char* nm, int m);
	Actor(int em_c, int m);

	void Action(Actor& a);

	void equip(Weapon& w) { atk += w.effect; }; 
	char* get_name() { return name; };
	int get_hp() { return hp; };
};

int main() {
	char name[10];
	int money, enemy_choice, weapon_choice;
	Weapon sword(10, 10);

	cout << "What's your name? (No more than 9 letters) "; 
	cin >> name;
	cout << "You have $" << TOTAL_MONEY << " in total." << endl; 
	cout << "How much will you pay for your basic attributes? $";
	cin >> money;
	Actor player(name, money);
	cout << "-------------------------------" << endl;
	cout << "Input a digit to choose your enemy (0 for Wolf, or otherwise Slime): "; 
	cin >> enemy_choice;
	Actor enemy(enemy_choice, money);
	cout << "-------------------------------" << endl;
	cout << "You have $" << TOTAL_MONEY - money << " left." << endl; 
	if (TOTAL_MONEY - money >= sword.price) {
		cout << "If you want to spend $10 to buy a sword, input 1: "; 
		cin >> weapon_choice;
		if (weapon_choice == 1) {
			cout << name << " has a sword now! ATK+" << sword.effect << "!" << endl; 
			player.equip(sword);
		}
		else cout << name << " has no sword." << endl;
	}
	cout << "===== " << player.get_name() << " vs " << enemy.get_name() << " ====="
		<< endl;
	if (money < 1) { cout << "You Loose!" << endl; return 0; }

	for (int i = 1; i <= 10; ++i) {
		cout << "Round " << i << endl; player.Action(enemy); enemy.Action(player);
		cout << player.get_name() << "'s remaining HP: " << player.get_hp() << endl; 
		cout << enemy.get_name() << "'s remaining HP: " << enemy.get_hp() << endl; 
		cout << " 	" << endl;

		// 此处需填写代码，判断是否结束战斗，且输出的胜负信息与 Homework 07 一致
		if (player.get_hp() > 0 && enemy.get_hp() <= 0) {
			cout << "You Win!" << endl; return 0;
		}
		else if (enemy.get_hp() > 0 && player.get_hp() <= 0) {
			cout << "You Loose!" << endl; return 0;
		}
		else if (player.get_hp() <= 0 && enemy.get_hp() <= 0) {
			cout << "End of Game with Draw." << endl; return 0;
		}
	}
	cout << "End of Game with Draw." << endl; return 0;
}
// 此处需填写代码 （一个函数的函数头)
Actor::Actor(char* nm, int m) :name(nm), hp(m), atk(m / 2), def(m / 3), heal(m >= HEAL_VALID), isPlayer(true) {
	// 此处需填写代码 ，使得玩家的基本属性设置方式、输出的 Welcome 信息和 Status 信息都与 Homework 07 一致
	cout << "Welcome to this game, " << name << "!" << endl;
	cout << "Your status: " << "HP" << hp << ", ATK" << atk
		<< ", DEF" << def << endl;
	cout << "You can attack the enemy and heal yourself." << endl;

	cout << "You can act with 1 to attack the enemy, " << (heal ? "2 to heal yourself, " : "") << "and otherwise wait" << endl;
}

// 此处需填写代码 （一个函数的定义），使得选择敌人的方式、敌人的属性设置方式、输出的敌人信息都与 Homework 07 一致
Actor::Actor(int em_c, int m) :hp(20 + m / 5), atk(8 + m / 6), def(7 + m / 6), isPlayer(false) {
	if (em_c == 0) {
		name = (char*)"Wolf";
		heal = false;
	}
	else {
		name = (char*)"Slime";
		heal = true;
	}
	cout << "Your enemy " << name << ": HP" << hp << ", ATK" << atk
		<< ", DEF" << def << endl;
}


// 此处需填写代码 （一个函数的定义），使得每回合玩家的选项、敌人的行动模式、双方 HP的变化方式、输出的信息都与 Homework 07 一致
void Actor::Action(Actor& a) {
	int act;
	if (a.isPlayer) {
		//敌人攻击
		if (hp < 10 && heal) act = 2;
		else act = 1;
	}
	else {
		cout << name;
		if (heal) {
			cout << " 's act (1-attack;2-heal;othwewise-wait):";
			cin >> act;
		}
		else {
			cout << " 's act (1-attack;othwewise-wait):";
			cin >> act;
			if (act != 1)
				act++;
		}
	}

	if (act == 1) {
		cout << name << " attacks " << a.name << "!" << endl;
		int damage = atk - a.def;
		if (damage < 0) damage = 0;
		a.hp -= damage;
	}
	else if (act == 2) {
		cout << name << " does self healing!" << endl;
		hp += HEAL_EFFECT;
	}
	else cout << name << " is waiting..." << endl;
}