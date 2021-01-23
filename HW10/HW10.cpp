// CS154-HW10.cpp
/*注1：不能在没有注明“此处需填写代码”的地方添加代码。
注2：用户输入的int_size是范围在[1,100]内的整数。
注3：Cell类中包含2个私有数据成员与8个公有成员函数，没有公有数据成员或私有成员函数。2个私有数据成员分别为size与resource，都是整型数；8个成员函数的名称为Cell、~Cell、grow、eat、get_size、get_resource（虽然有8个函数，但却只有6个函数名）。
注4：本程序模拟一个细胞培养环境，整个环境中最初的resource为500。
注5：在while循环的每个周期中进行以下操作：初始细胞与每个已经诞生的普通细胞都会成长一次；一个普通细胞的成长会使其个体的size加1，而整个环境中的resource减1；初始细胞的成长则不会改变其size，但仍会使环境resource减1；如果一个普通细胞的size大于5，那么它将会创造一个新的普通细胞，该细胞的size为原细胞的一半（取整，舍去小数），而环境中的resource会减少相当于新细胞size的量。
注6：在while循环的每个周期结束之前，如果环境中size最大的一个细胞的size大于10，那么初始细胞会将它吃掉，并使环境中的resource增加相当于被吃掉的细胞的size的量。
注7：当环境中的resource减少到0或负数的时候，或当第100个普通细胞被创造之后，中断while循环。
注8：每当有细胞成长时，输出：“Initial Cell grows, remaining resource = XX”或“Cell YY grows, remaining resource = XX”，其中XX为当前resource的值，YY为相应的普通细胞的编号。每当有细胞被创造时，输出“Cell YY is born, remaining resource = XX”。每当有细胞被吃掉时，输出“Cell YY is eaten, remaining resource = XX”。*/

#include <iostream> 
using namespace std;

class Cell {
	// 此处需填写代码
	// 包含 2 个私有数据成员与 8 个公有成员函数
	// 没有公有数据成员或私有成员函数
private:
	int size;
	static int resource;

public:
	//（虽然有 8 个函数，但却只有 6 个函数名）
	Cell(const Cell& c) {
		size = (c.size / 2);
		eat(size);
	}

	Cell(int init_size) {
		//初始状态
		size = init_size;
		eat(init_size);
	}

	~Cell() {

		// 那么初始细胞会将它吃掉，并使环境中的 resource 增加相当于被吃掉的细胞的 size 的量
		eat(-size);		//吃掉负的相当于增加

	}

	static void grow(int init_size) {

		// 初始细胞的成长则不会改变其 size，
		// 但仍会使环境 resource 减 1
		eat(1);
	}

	void grow() {

		size += 1;	// 一个普通细胞的成长会使其个体的 size 加 1
		eat(1);	// 而整个环境中的 resource 减 1

	}
	
	static void eat(int r_eat) {
		resource -= r_eat;
	}

	int get_size() {
		return size;
	}

	static int get_resource() {
		return resource;
	}

};

int main()
{
	int init_size, id = 1, eaten = 0, i, size, eat; 
	Cell* cells[100] = { 0 };

	cout << "Initial Cell Size: "; 
	cin >> init_size; //范围在[1,100]内的整数
	const Cell* init_cell = new const Cell(init_size); 
	cout << "Initial Cell is born, remaining resource = " << Cell::get_resource() << endl;

	cells[0] = new Cell(*init_cell);
	cout << "Cell 0 is born, remaining resource = " << Cell::get_resource() << endl; 
	while (true) {

		// 此处需填写代码

		size = cells[eaten]->get_size();	// size初始化

		// 初始细胞与每个已经诞生的普通细胞都会成长一次

		init_cell->grow(init_size);			//初始细胞成长

		// 每当有细胞成长时，输出：
		// “Initial Cell grows, remaining resource = XX”
		cout << "Initial Cell grows, remaining resource = " << Cell::get_resource() << endl;

		int tmp = id;

		for (i = eaten; i < tmp; ++i) {		//到id号结束
			if (i >= eaten) {		//普通细胞不为空
				cells[i]->grow();
				// 或“Cell YY grows, remaining resource = XX”，
				// 其中 XX 为当前 resource 的值， YY 为相应的普通细胞的编号
				cout << "Cell " << i << " grows, remaining resource = " << Cell::get_resource() << endl;

				if (Cell::get_resource() <= 0)	// [1]当环境中的 resource 减少到 0 或负数的时候		
					return 0;					// 中断 while 循环

				if (cells[i]->get_size() > 5) {
					// 如果一个普通细胞的 size 大于 5，那么它将会创造一个新的普通细胞
					cells[id] = new Cell(*cells[i]);

					// 每当有细胞被创造时，输出
					// “Cell YY is born, remaining  resource  =  XX”。
					cout << "Cell " << id << " is born, remaining resource = " << Cell::get_resource() << endl;

					//计数器增加
					++id;
					//内部增加计数器会导致终止条件改变

					if (id >= 101)	// 或当第 100 个普通细胞被创造之后，即下一个制造的是第101个
						return 0;
				}
				//准备找出size最大的细胞
				if (cells[i]->get_size() > size) {
					size = cells[i]->get_size();
					eat = i;
				}
				
				if (Cell::get_resource() <= 0)	// [2]当环境中的 resource 减少到 0 或负数的时候		
					return 0;					// 中断 while 循环
			}
		}


		// 在 while 循环的每个周期结束之前，如果环境中 size 最大的一个细胞的 size 大于 10
		if (size > 10) {

			cells[eat]->~Cell();

			// 每当有细胞被吃掉时，输出
			// “Cell  YY  is  eaten, remaining resource = XX”。
			cout << "Cell " << eat << " is eaten, remaining resource = " << Cell::get_resource() << endl;
			eaten++;
		}
		
	}

	return 0;
}

// 此处需填写代码（Cell 类的实现）
int Cell::resource = 500;	// 整个环境中最初的 resource 为 500