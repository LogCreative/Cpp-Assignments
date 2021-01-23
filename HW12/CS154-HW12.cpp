// CS154-HW12.cpp
/*
注1：请按注释中的要求填补完程序代码，不定义其它全局变量或函数。
注2：用户输入的是范围在 [1,100]内的整数。
注3：该程序从文件 actors_int.txt和 actors_float.txt中读取各个人物的数据，分
别存入一个 Actor<int>数组和一个 Actor<float>数组。两边人数不一定相等，合
计不超过 20人，一起组成一个 team。
注4：该程序按用户输入的 threshold值从 team中挑选符合要求的人物并输出
到文件 team.txt。要求人物满足以下四个条件中的至少三个： 1) HP大于 threshold
2) ATK大于 threshold/3 3) DEF大于 threshold/3 4) 具有治疗能力。
注5：附件中的 actors_int.txt和 actors_float.txt为输入文件的格式样本，实际测
试时使用的输入文件中人数可能变化（但不 会为零，且格式不变）。输出文件只
有一个，即 team.txt，包含从两边挑选出来的人物。输出时的 ID按先 int后 float的顺序重新从 1开始编号， int人物内部（或 float人物内部）按原 ID从小到大
排序。
注6：本次作业没有运行示例，附件中的 team.txt为以附件中的 actors_int.txt和
actors_float.txt为输入文件，且用户输入的 threshold 为 60时得到的输出文件。
*/
// THIS FILE IS UNABLE TO PASS THE COMPILATION OF GCC.
// PLEASE USE MSVC TO COMPILE.
// THE SOLUTION DOES NOT MEET THE REQUIREMENTS OF THE PROBLEM.
// ONLY THE RESULT IS CORRECT.
// PLEASE DO NOT REFER TO THIS SOLUTION.

#include <iostream> 
#include <fstream> 
#define NUM 20 
using namespace std;

class Team;
template <class T> class Actor;

//此处填写一个函数模板的声明语句
template<class T>
int judge(Actor<T> &obj,int threshold) {
	/*要求人物满足以下四个条件中的至少三个：1) HP 大于threshold；
	2) ATK 大于threshold / 3；3) DEF 大于threshold / 3；4) 具有治疗能力。*/
	/*int condition_count = 0;
	if (obj.hp > threshold)
		condition_count++;
	if (obj.atk > threshold / 3)
		condition_count++;
	if (obj.def > threshold / 3)
		condition_count++;
	if (obj.heal)
		condition_count++;
	if (condition_count >= 3) {
		return true;
	}
	else
		return false;*/
}

template <class T> 
class Actor {
	//不需要const限定
	template<class T> friend ifstream& operator>>(ifstream& ifs, Actor<T>& obj);//此处填写 Actor 类模板的输入运算符重载函数模板的友元声明语句
	friend ofstream& operator<<(ofstream& ofs, const Team& obj);//此处填写 Team 类的输出运算符重载函数的友元声明语句
private:
	int id;
	char name[10]; 
	T hp;
	T atk;
	T def;
public:
	bool heal;
	Actor(int i = 0, bool h = false) :id(i), heal(false) {}
};

class Team {
	friend ofstream& operator<<(ofstream& ofs, const Team& obj);
	//此处填写一个友元声明语句
private:
	//定义三个数据成员（私有）
	Actor<int> intTeamActor[NUM]; //两边人数不一定相等，合计不超过 20人，一起组成一个 team
	Actor<float> floatTeamActor[NUM];
	int threshold;
public:
	//一个构造函数（公有)
	Team(Actor<int>* intActor, Actor<float>* floatActor, int threshold):threshold(threshold) {
		

		//先组合 
		for (int k = 0; k < NUM; ++k) {
			intTeamActor[k] = *(intActor + k);
		}
		
		for (int k = 0; k < NUM; ++k) {
			floatTeamActor[k] = *(floatActor + k);
		}


	}
};

int main() {
	Actor<int> intActor[NUM];
	Actor<float> floatActor[NUM];//两边人数不一定相等，合计不超过20 人
	//此处定义两个数组
	char waste[100], test;
	int threshold, i;

	//此处填写读取文件内容的代码，不定义任何变量、对象或数组
	//但可以定义流对象
	/*	该程序从文件actors_int.txt 和actors_float.txt 中读取各个人物的数据，分
		别存入一个Actor<int>数组和一个Actor<float>数组。两边人数不一定相等，合
		计不超过20 人，一起组成一个team。*/
	ifstream in,in2;

	in.open("actors_int.txt");
	if (!in) { cerr << "open file error\n"; return 1; }
	/*	附件中的actors_int.txt 和actors_float.txt 为输入文件的格式样本，实际测
		试时使用的输入文件中人数可能变化（但不会为零，且格式不变）。输出文件只
		有一个，即team.txt，包含从两边挑选出来的人物。输出时的ID 按先int 后float
		的顺序重新从1 开始编号，int 人物内部（或float 人物内部）按原ID 从小到大
		排序。	*/
		/* actors.txt: ID \t Name \t HP \t ATK \t DEF \n */
	in.seekg(19);			//跳过首行
	for (i = 0; i < NUM; ++i) {
		in >> intActor[i];
		in.getline(waste, 8, '\n');
		if (waste[1]=='h')
			intActor[i].heal = true;
		else
			intActor[i].heal = false;
		waste[1] = '\0';

		if (in.get() == EOF)
			break;
		in.seekg(-1, ios::cur); //退一格
	}
	in.close();



	in.open("actors_float.txt");
	if (!in) { cerr << "open file error\n"; return 1; }

	in.seekg(19);			//跳过首行
	for (i = 0; i < NUM; ++i) {
		in >> floatActor[i];
		in.getline(waste, 8, '\n');
		if (waste[1] == 'h')
			floatActor[i].heal = true;
		else
			floatActor[i].heal = false;
		waste[1] = '\0';

		if (in.get() == EOF)
			break;
		in.seekg(-1, ios::cur); //退一格
	}
	
	in.close();				//关闭文件
	
	cout << "Standard (%): ";
	cin >> threshold;
	Team team(intActor, floatActor, threshold);
	ofstream fout("team.txt");
	fout << team;
	fout.close();

	return 0;
}

//此处定义 Actor 类模板的输入运算符重载函数模板
template <class T>
ifstream& operator>>(ifstream& ifs, Actor<T>& obj) {
	ifs >> obj.id >> obj.name >> obj.hp >> obj.atk >> obj.def;
	return ifs;
}

//此处定义 Team 类的输出运算符重载函数
ofstream& operator<<(ofstream& ofs, const Team& team) {
	/* 该程序按用户输入的threshold 值从team 中挑选符合要求的人物并输出
		到文件team.txt。*/

	//文件头
	ofs << "ID\tName\tHP\tATK\tDEF\n";

	int newid = 1;
	

	//后判定
	for (int k = 0; k < NUM; k++) {
		int condition_count = 0;
		if (team.intTeamActor[k].hp > team.threshold)
			condition_count++;
		if (team.intTeamActor[k].atk > team.threshold / 3)
			condition_count++;
		if (team.intTeamActor[k].def > team.threshold / 3)
			condition_count++;
		if (team.intTeamActor[k].heal)
			condition_count++;
		if (condition_count >= 3) {
			ofs << newid << "\t"
				<< team.intTeamActor[k].name << "\t"
				<< team.intTeamActor[k].hp << "\t"
				<< team.intTeamActor[k].atk << "\t"
				<< team.intTeamActor[k].def;
			if (team.intTeamActor[k].heal)
				ofs << "\t healer";
			ofs << "\n";
			newid++;
		}
	}


	for (int k = 0; k < NUM; k++) {
		int condition_count = 0;
		if (team.floatTeamActor[k].hp > team.threshold)
			condition_count++;
		if (team.floatTeamActor[k].atk > team.threshold / 3)
			condition_count++;
		if (team.floatTeamActor[k].def > team.threshold / 3)
			condition_count++;
		if (team.floatTeamActor[k].heal)
			condition_count++;
		if (condition_count >= 3) {
			ofs << newid << "\t"
				<< team.floatTeamActor[k].name << "\t"
				<< team.floatTeamActor[k].hp << "\t"
				<< team.floatTeamActor[k].atk << "\t"
				<< team.floatTeamActor[k].def;
			if (team.floatTeamActor[k].heal)
				ofs << "\t healer";
			ofs << "\n";
			newid++;
		}
	}

	return ofs;
}