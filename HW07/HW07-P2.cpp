#include <iostream>
#define HEAL_VALID 20
#define HEAL_EFFECT 10
using namespace std;

struct Actor{
	// 此处需填写代码
	char name[10];
	int hp;
	int atk;
	int def;
	bool heal;
};

Actor &GetPlayer(char[], int);
Actor &GetEnemy(int);
void Action(Actor&, Actor&, int);

int main(){
	char name[10];
	int money, act;

	cout << "What's your name? (No more than 9 letters) ";
	cin >> name;
	cout << "How much will you pay for the game? $";
	cin >> money;

	Actor &player = GetPlayer(name, money);
	Actor &enemy = GetEnemy(money);

	cout << "===== " << player.name << " vs " << enemy.name << " =====" << endl;
	if(money < 1) {cout << "You Loose!" << endl; return 0;}
	for (int i = 1; i <= 10; ++i) {
		cout << "Round " << i << endl;
		// 此处需填写代码
		cout << player.name;
		if (player.heal) {
			cout << " 's act (1-attack;2-heal;othwewise-wait):";
			cin >> act;
		}
		else {
			cout << " 's act (1-attack;othwewise-wait):";
			cin >> act;
			if (act != 1)
				act++;
		}
		Action(player, enemy, act);

		if (enemy.hp < 10 && enemy.heal) act = 2;
		else act = 1;
		Action(enemy, player, act);

		if (player.hp > 0 && enemy.hp <= 0) {
			cout << "You Win!" << endl; return 0;
		}
		else if(enemy.hp > 0 && player.hp <= 0) {
			cout << "You Loose!" << endl; return 0;
		}
		else if (player.hp <= 0 && enemy.hp <= 0) {
		cout << "End of Game with Draw." << endl; return 0;
		}
	cout << player.name << "'s remaining HP: " << player.hp << endl;
	cout << enemy.name << "'s remaining HP: " << enemy.hp << endl;
	cout << "------------------------------------------" << endl;
	}
	cout << "End of Game with Draw." << endl;
	return 0;
}
Actor &GetPlayer(char name[], int m){
	Actor* player = new Actor({"1", m, m / 2, m / 3, m >= HEAL_VALID });
	strcpy_s(player->name, 10 * sizeof(char), name);
	//Actor* player = new Actor({name, m, m / 2, m / 3, m >= HEAL_VALID });
	// 此处需填写代码
	cout << "Welcome to this game, " << player->name << "!" << endl;
	cout << "Your status: " << "HP" << player->hp << ", ATK" << player->atk
		<< ", DEF" << player->def << endl;
	cout << "You can attack the enemy and heal yourself." << endl;
	return *player;
}

Actor &GetEnemy(int m){
	Actor *enemy;
	int choice;
	cout << "Input a digit to choose your enemy (0 for Wolf, or otherwise Slime): ";
	cin >> choice;
	if (choice) {
		enemy = new Actor({"Slime", 20 + m / 5, 8 + m / 6, 7 + m / 6,true });
	}
	else enemy = new Actor({"Wolf", 25 + m / 4, 9 + m / 6, 6 + m / 6,false });
	// 此处需填写代码
	cout << "Your enemy " << enemy->name << ": HP" << enemy->hp << ", ATK" << enemy->atk
		<< ", DEF" << enemy->def << endl;
	return *enemy;
}
void Action(Actor &user, Actor &target, int act){
	if(act == 1) {
		cout << user.name << " attacks " << target.name << "!" << endl;
		int damage = user.atk - target.def;
		if(damage < 0) damage = 0;
		target.hp -= damage;
	}else if(act == 2){
		cout << user.name << " does self healing!" << endl;
		user.hp += HEAL_EFFECT;
	}else cout << user.name << " is waiting..." << endl;
}

/*
要求以上程序运行一个需要充值的简陋游戏，游戏规则满足：
（1）玩家每回合开始时选择本回合的行动 1为攻击， 2为治疗， 3为等待；
（2）当且仅当玩家充值不少于 $20时，允许玩家使用治疗，否则无此选项；
（3）符合运行示例中所示的输入与输出（运行示例有两个，请往后翻页）。
注1 不能在没有 注明“此处需填写代码”的地方 添加代码 。
注2：不需要考虑用户乱输入的情况。
注3：虽然跟作业本身无关，可以试试最少充值多少能打败狼和史莱姆。
注4 虽然跟作业本身无关， 可以考虑如何扩充一些功能，比如增加新的行动选
项（ 使用道具、 逃跑 等 ）、增加新的敌人、 设置 敌人 HP低于某阈值时攻击力上
升等等 。
*/