// CS154-HW11.cpp
/*注1：不能在没有注明“此处需填写代码”的地方添加代码。
注2：用户输入的是范围在[1,100]内的整数。
注3：除了定义Cell 类的派生类，并实现这两个类以及它们的运算符重载函数以
外，不定义全局变量或函数。
注4：Cell 类的派生类中包含2 个新的私有数据成员，没有公有数据成员。2 个
私有数据成员分别为id 与counter，都是整型。
注5：Cell 类的派生类的定义代码中只包含至多三个成员函数。
注6：需要重载的运算符有且只有：=、<<、>>。
注7：运行示例和Homework 10 一致，也就是说输出信息也要一致。*/

#include <iostream>

using namespace std;

class Cell {
	friend istream& operator>>(istream&, Cell&);
protected:
	int size;
	static int resource;
public:
	int get_size() const { return size; }
	bool grow();
};

// 此处需填写代码（定义一个基于 Cell 类的派生类）
class NewCell :public Cell {
private:
	int id;
	static int counter;
	friend ostream& operator<<(ostream&, NewCell&);
public:
	bool operator=(Cell&);
	bool operator=(NewCell&);
	bool grow();
};

int main() {
	Cell init_cell; NewCell cells[100];
	int born = 1, eaten = 0, maxsize;

	cout << "Initial Cell Size: "; cin >> init_cell;  //用户输入的是范围在[1,100]内的整数
	if (cells[0] = init_cell) return 0;

	while (true) {
		if (init_cell.grow()) return 0;
		int thisround = born;
		for (int i = 0; i < thisround; ++i) {
			if (cells[i].get_size() == 0) continue;
			if (cells[i].grow()) return 0;
			if (cells[i].get_size() > 5) {
				if (cells[born] = cells[i]) return 0;
				if (cells[born].get_size() > cells[eaten].get_size()) eaten = born;
				born++;
				if (born >= 100) return 0;
			}
		}
		if (cells[eaten].get_size() > 10) {
			cout << cells[eaten]; eaten = 0, maxsize = 0;
			for (int i = 0; i < born; ++i) {
				if (cells[i].get_size() > maxsize) { maxsize = cells[i].get_size(); eaten = i; }
			}
		}
	}

	return 0;
}

// 此处需填写代码（Cell 类及其派生类的实现，以及它们的运算符重载函数的定义）
int Cell::resource = 500;  // 整个环境中最初的 resource 为 500
int NewCell::counter = 0;

istream& operator>>(istream &in, Cell &right) {
	//>>运算符重载
	int init_size;
	in >> init_size;
	right.size = init_size;
	Cell::resource -= init_size;
	cout << "Initial Cell is born, remaining resource = " << Cell::resource << endl;
	return in;
}

ostream& operator<<(ostream &out, NewCell &in) {
	//<<运算符重载
	Cell::resource += in.size;
	in.size = 0;
	out << "Cell " << in.id << " is eaten, remaining resource = " << Cell::resource << endl;
	return out;
}

bool NewCell::operator=(Cell &right) {
	//=运算符重载
	if (Cell::resource <= 0)
		return true;

	size = right.get_size() / 2;
	resource -= size;
	counter = 0;
	id = counter;
	cout << "Cell " << id << " is born, remaining resource = " << resource << endl;
	return false;

}



bool NewCell::operator=(NewCell& right) {
	if (Cell::resource <= 0)
		return true;

	size = right.get_size() / 2;
	resource -= size;
	id = ++counter;
	cout << "Cell " << id << " is born, remaining resource = " << resource << endl;
	return false;

}

bool Cell::grow() {
	//初始细胞成长
	if (Cell::resource <= 0)
		return true;

	resource -= 1;
	cout << "Initial Cell grows, remaining resource = " << resource << endl;
	return false;
}

bool NewCell::grow() {
	//普通细胞成长
	if (Cell::resource <= 0)
		return true;

	size += 1;
	resource -= 1;
	cout << "Cell " << id << " grows, remaining resource = " << resource << endl;
	return false;
}
