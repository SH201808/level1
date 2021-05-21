#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
struct student{
	string ID;
	string name;
	string Cla;
	int math;
	int physics;
	int c;
}s;
class Student_System{
public:
	void input();
	void output();
	void Add();
	void Search_Dele_Modify();
	void Delete(int s);
	void Modify(int v);
	void Sort();
	void select(int k,int F);
	void exchangeA(int z);
	void outData(int o);
private:
	int max = 0;
	vector<student>a = {};
}ss;
bool judge(string &s, string &s1);
template<class T>
void exchange(T &x, T &y){
		T t;
		t = x;
		x = y;
		y = t;
}
void Student_System::exchangeA(int z){
	exchange(a[z].math, a[z + 1].math);
	exchange(a[z].physics, a[z + 1].physics);
	exchange(a[z].c, a[z + 1].c);
	exchange(a[z].name, a[z+1].name);
	exchange(a[z].ID, a[z + 1].ID);
	exchange(a[z].Cla, a[z + 1].Cla);
}
int main()
{
	int n;
	cout << "【1】输入文件内容" << endl;
	cout << "【2】显示文件内容" << endl;
	cout << "【3】增添数据" << endl;
	cout << "【4】查找数据，修改数据，删除数据" << endl;
	cout << "【5】成绩排序" << endl;
	cout << "请选择功能，或者按0退出程序" << endl;
	while (cin >> n){
		if (n == 0){
			return 0;
		}
		else{
			switch (n)
			{
			case 1:
				ss.input();
				break;
			case 2:
				ss.output();
				break;
			case 3:
				ss.Add();
				break;
			case 4:
				ss.Search_Dele_Modify();
				break;
			case 5:
				ss.Sort();
				break;
			case 6:
				system("cls");
				break;
			default:
				cout << "输入方式错误" << endl;
				break;
			}
		}
		cout << "【1】输入文件内容" << endl;
		cout << "【2】显示文件内容" << endl;
		cout << "【3】增添数据" << endl;
		cout << "【4】查找数据，修改数据，删除数据" << endl;
		cout << "【5】成绩排序" << endl;
		cout << "【6】清屏" << endl;
		cout << "请选择功能，或者按0退出程序" << endl;
	}
}
//输入
void Student_System::input(){
	string filename,temp1,temp2,temp3;
	cout << "请输入打开的csv文件格式:" << endl;
	cin >> filename;
	//filename = "C:\\Users\\DELL\\Desktop\\Data.csv";
	ifstream infile(filename);
	if (!infile)
		cout << "文件打开失败" << endl;
	else
		cout << "文件打开成功" << endl;
	while (infile.peek() != EOF){
		getline(infile, s.ID, ',');
		getline(infile, s.name, ',');
		getline(infile, s.Cla, ',');
		getline(infile, temp1,',');
		stringstream ss1(temp1);
		ss1 >> s.math;
		getline(infile, temp2, ',');
		stringstream ss2(temp2);
		ss2 >> s.physics;
		getline(infile, temp3);
		stringstream ss3(temp3);
		ss3 >> s.c;
		a.push_back(s);
		max++;
	}
}
//输出
void Student_System::output(){
	cout << "序号\t" << "ID\t\t" << "姓名\t\t"<<"班级\t\t" << "高等数学\t" <<"大学物理\t"<<"编程基础\t"<< endl;
	for (int i = 0; i < max; i++){
		outData(i);
	}
}
//查找
void Student_System::Search_Dele_Modify(){
	int f = 0;
	int n;
	cout << "【1】学号查找" << endl;
	cout << "【2】姓名查找" << endl;
	cout << "【3】序号查找" << endl;
	cout << "【4】班级查找" << endl;
	cout << "请选择查找方式:" << endl;
	cin >> n;
	if (n == 1){
		string SID;
		int f = 0;
		cout << "请输入查找的学号:" << endl;
		cin >> SID;
		for (int i = 0; i < max; i++){
			if (judge(a[i].ID, SID)){
				select(i, n);
				f++;
				break;
			}
		}
		if (f==0)
			cout << "查无此人" << endl;
	}
	else if (n == 2){
		string Sname;
		cout << "请输入查找的姓名:" << endl;
		cin >> Sname;
		for (int i = 0; i < max; i++){
			if (judge(a[i].name, Sname)){
				select(i, n);
				f++;
			}
		}
		if (f == 0)
			cout << "查无此人" << endl;
	}
	else if (n == 3){
		int No_;
		cout << "请输入查找的序号" << endl;
		cin >> No_;
		if (No_ <= max){
			select(No_-1, n); 
		}
		else{
			cout << "查无此人" << endl;
		}
	}
	else if (n == 4){
		string cla;
		cout << "请输入查找的班级" << endl;
		cin >> cla;
		for (int i = 0; i < max; i++){
			if (judge(a[i].Cla, cla)){
				select(i, n);
				f++;
			}
		}
		if (f == 0){
			cout << "查无此人" << endl;
		}
	}
}
//增添问题
void Student_System::Add(){
	cout << "请输入增添的学号:" << endl;
	cin >> s.ID;
	cout << "请输入增添的姓名:" << endl;
	cin >> s.name;
	cout << "请输入增添的班级:" << endl;
	cin >> s.Cla;
	cout << "请输入增添的高数成绩:" << endl;
	cin >> s.math;
	cout << "请输入增添的大物成绩:" << endl;
	cin >> s.physics;
	cout << "请输入增添的编程成绩:" << endl;
	cin >> s.c;
	cout << "插入完成" << endl;
	a.push_back(s);
	max++;
}
//删除
void Student_System::Delete(int v){
	int sign = v;
	int i = 0;
	if (sign+1 == max){
		a.pop_back();
	}
	else{
		vector<student>::iterator del;
		for (del = a.begin(); del != a.end(); del++,i++){
			if (sign == i){
				del = a.erase(del);
			}
		}
	}
	max--;
	cout << "删除成功" << endl;
}
//修改数据
void Student_System::Modify(int v){									
	int n2,tmath,tphy,tc;
	int sign = v;
	string Itemp, Ntemp,Ctemp;
	cout << "请选择需要修改的数据:" << endl;
	cout << "【1】学号" << endl;
	cout << "【2】姓名" << endl;
	cout << "【3】班级" << endl;
	cout << "【4】高数成绩" << endl;
	cout << "【5】大物成绩" << endl;
	cout << "【6】编程成绩" << endl;
	cin >> n2;
	if (n2 == 1){
		cout << "请输入修改后的学号:" << endl;
		(cin>>Itemp);
		a[sign].ID = Itemp;
	}
	else if (n2 == 2){
		cout << "请输入修改后的姓名:" << endl;
		cin>>Ntemp;
		a[sign].name = Ntemp;
	}
	else if (n2 == 3){
		cout << "请输入修改后的班级:" << endl;
		cin >> Ctemp;
		a[sign].Cla = Ctemp;
	}
	else if (n2 == 4){
		cout << "请输入修改后的高数成绩:" << endl;
		cin >> tmath;
		a[sign].math = tmath;
	}
	else if (n2 == 5){
		cout << "请输入修改后的大物成绩:" << endl;
		cin >> tphy;
		a[sign].physics = tphy;
	}
	else if (n2 == 6){
		cout << "请输入修改后的编程成绩:" << endl;
		cin >> tc;
		a[sign].c = tc;
	}
	cout << "修改完成" << endl;
}
//查找
void Student_System::select(int k,int F){
	int n;
	if (F == 1 || F == 2||F==4){
		cout << "查找成功" << endl;
		cout << "序号\t" << "ID\t\t" << "姓名\t\t" << "班级\t\t" << "高等数学\t" << "大学物理\t" << "编程基础\t" << endl;
		outData(k);
		cout << "请问是否对该学生数据进行删除或修改:" << endl;
		cout << "【5】删除数据" << endl;
		cout << "【6】修改数据" << endl;
		cout << "【0】继续查找或返回主菜单" << endl;
		cin >> n;
		if (n == 5){
			Delete(k);
		}
		else if (n == 6){
			Modify(k);
		}
	}
	else if (F==3){
		cout << "查找成功" << endl;
		cout << "序号\t" << "ID\t\t" << "姓名\t\t" << "班级\t\t" << "高等数学\t" << "大学物理\t" << "编程基础\t" << endl;
		outData(k);
		cout << "请问是否对该学生数据进行删除或修改:" << endl;
		cout << "【5】删除数据" << endl;
		cout << "【6】修改数据" << endl;
		cout << "【0】继续查找或返回主菜单" << endl;
		cin >> n;
		if (n == 5){
			Delete(k);
		}
		else if (n == 6){
			Modify(k);
		}
	}
}
//排序
void Student_System::Sort(){
	int r;
	cout << "请输入需要排序的科目" << endl;
	cout << "【1】高等数学" << endl;
	cout << "【2】大学物理" << endl;
	cout << "【3】编程基础" << endl;
	cin >> r;
	for (int i = 0; i < max - 1; i++){
		bool flag = false;
		for (int j = 0; j < max -i-1 ; j++){
			if (r == 1){
				if (a[j].math < a[j + 1].math){
					exchangeA(j);
					flag = true;
				}
			}
			else if (r==2){
				if (a[j].physics < a[j + 1].physics){
					exchangeA(j);
					flag = true;
				}
			}
			else if (r == 3){
				if (a[j].c < a[j + 1].c){
					exchangeA(j);
					flag = true;
				}
			}
		}
		if (!flag)
			break;
	}
	cout << "排序完成" << endl;
}
//输出单条数据
void Student_System::outData(int o){
	if (a[o].name.size() <= 6){
		cout << o + 1 << "\t" << a[o].ID << "\t" << a[o].name << "\t\t" << a[o].Cla << "\t" << a[o].math << "\t\t" << a[o].physics << "\t\t" << a[o].c << endl;
	}
	else{
		cout << o + 1 << "\t" << a[o].ID << "\t" << a[o].name << "\t" << a[o].Cla << "\t" << a[o].math << "\t\t" << a[o].physics << "\t\t" << a[o].c << endl;
	}
}
//判断数据是否匹配
bool judge(string &s, string&s1){
	int len = s.size(), len1 = s1.size();
	if (len != len1){
		return false;
	}
	else{
		for (int i = 0; i < len; i++){
			if (s[i] != s1[i]){
				return false;
			}
		}
		return true;
	}
}







