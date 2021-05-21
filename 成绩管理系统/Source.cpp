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
	cout << "��1�������ļ�����" << endl;
	cout << "��2����ʾ�ļ�����" << endl;
	cout << "��3����������" << endl;
	cout << "��4���������ݣ��޸����ݣ�ɾ������" << endl;
	cout << "��5���ɼ�����" << endl;
	cout << "��ѡ���ܣ����߰�0�˳�����" << endl;
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
				cout << "���뷽ʽ����" << endl;
				break;
			}
		}
		cout << "��1�������ļ�����" << endl;
		cout << "��2����ʾ�ļ�����" << endl;
		cout << "��3����������" << endl;
		cout << "��4���������ݣ��޸����ݣ�ɾ������" << endl;
		cout << "��5���ɼ�����" << endl;
		cout << "��6������" << endl;
		cout << "��ѡ���ܣ����߰�0�˳�����" << endl;
	}
}
//����
void Student_System::input(){
	string filename,temp1,temp2,temp3;
	cout << "������򿪵�csv�ļ���ʽ:" << endl;
	cin >> filename;
	//filename = "C:\\Users\\DELL\\Desktop\\Data.csv";
	ifstream infile(filename);
	if (!infile)
		cout << "�ļ���ʧ��" << endl;
	else
		cout << "�ļ��򿪳ɹ�" << endl;
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
//���
void Student_System::output(){
	cout << "���\t" << "ID\t\t" << "����\t\t"<<"�༶\t\t" << "�ߵ���ѧ\t" <<"��ѧ����\t"<<"��̻���\t"<< endl;
	for (int i = 0; i < max; i++){
		outData(i);
	}
}
//����
void Student_System::Search_Dele_Modify(){
	int f = 0;
	int n;
	cout << "��1��ѧ�Ų���" << endl;
	cout << "��2����������" << endl;
	cout << "��3����Ų���" << endl;
	cout << "��4���༶����" << endl;
	cout << "��ѡ����ҷ�ʽ:" << endl;
	cin >> n;
	if (n == 1){
		string SID;
		int f = 0;
		cout << "��������ҵ�ѧ��:" << endl;
		cin >> SID;
		for (int i = 0; i < max; i++){
			if (judge(a[i].ID, SID)){
				select(i, n);
				f++;
				break;
			}
		}
		if (f==0)
			cout << "���޴���" << endl;
	}
	else if (n == 2){
		string Sname;
		cout << "��������ҵ�����:" << endl;
		cin >> Sname;
		for (int i = 0; i < max; i++){
			if (judge(a[i].name, Sname)){
				select(i, n);
				f++;
			}
		}
		if (f == 0)
			cout << "���޴���" << endl;
	}
	else if (n == 3){
		int No_;
		cout << "��������ҵ����" << endl;
		cin >> No_;
		if (No_ <= max){
			select(No_-1, n); 
		}
		else{
			cout << "���޴���" << endl;
		}
	}
	else if (n == 4){
		string cla;
		cout << "��������ҵİ༶" << endl;
		cin >> cla;
		for (int i = 0; i < max; i++){
			if (judge(a[i].Cla, cla)){
				select(i, n);
				f++;
			}
		}
		if (f == 0){
			cout << "���޴���" << endl;
		}
	}
}
//��������
void Student_System::Add(){
	cout << "�����������ѧ��:" << endl;
	cin >> s.ID;
	cout << "���������������:" << endl;
	cin >> s.name;
	cout << "����������İ༶:" << endl;
	cin >> s.Cla;
	cout << "����������ĸ����ɼ�:" << endl;
	cin >> s.math;
	cout << "����������Ĵ���ɼ�:" << endl;
	cin >> s.physics;
	cout << "����������ı�̳ɼ�:" << endl;
	cin >> s.c;
	cout << "�������" << endl;
	a.push_back(s);
	max++;
}
//ɾ��
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
	cout << "ɾ���ɹ�" << endl;
}
//�޸�����
void Student_System::Modify(int v){									
	int n2,tmath,tphy,tc;
	int sign = v;
	string Itemp, Ntemp,Ctemp;
	cout << "��ѡ����Ҫ�޸ĵ�����:" << endl;
	cout << "��1��ѧ��" << endl;
	cout << "��2������" << endl;
	cout << "��3���༶" << endl;
	cout << "��4�������ɼ�" << endl;
	cout << "��5������ɼ�" << endl;
	cout << "��6����̳ɼ�" << endl;
	cin >> n2;
	if (n2 == 1){
		cout << "�������޸ĺ��ѧ��:" << endl;
		(cin>>Itemp);
		a[sign].ID = Itemp;
	}
	else if (n2 == 2){
		cout << "�������޸ĺ������:" << endl;
		cin>>Ntemp;
		a[sign].name = Ntemp;
	}
	else if (n2 == 3){
		cout << "�������޸ĺ�İ༶:" << endl;
		cin >> Ctemp;
		a[sign].Cla = Ctemp;
	}
	else if (n2 == 4){
		cout << "�������޸ĺ�ĸ����ɼ�:" << endl;
		cin >> tmath;
		a[sign].math = tmath;
	}
	else if (n2 == 5){
		cout << "�������޸ĺ�Ĵ���ɼ�:" << endl;
		cin >> tphy;
		a[sign].physics = tphy;
	}
	else if (n2 == 6){
		cout << "�������޸ĺ�ı�̳ɼ�:" << endl;
		cin >> tc;
		a[sign].c = tc;
	}
	cout << "�޸����" << endl;
}
//����
void Student_System::select(int k,int F){
	int n;
	if (F == 1 || F == 2||F==4){
		cout << "���ҳɹ�" << endl;
		cout << "���\t" << "ID\t\t" << "����\t\t" << "�༶\t\t" << "�ߵ���ѧ\t" << "��ѧ����\t" << "��̻���\t" << endl;
		outData(k);
		cout << "�����Ƿ�Ը�ѧ�����ݽ���ɾ�����޸�:" << endl;
		cout << "��5��ɾ������" << endl;
		cout << "��6���޸�����" << endl;
		cout << "��0���������һ򷵻����˵�" << endl;
		cin >> n;
		if (n == 5){
			Delete(k);
		}
		else if (n == 6){
			Modify(k);
		}
	}
	else if (F==3){
		cout << "���ҳɹ�" << endl;
		cout << "���\t" << "ID\t\t" << "����\t\t" << "�༶\t\t" << "�ߵ���ѧ\t" << "��ѧ����\t" << "��̻���\t" << endl;
		outData(k);
		cout << "�����Ƿ�Ը�ѧ�����ݽ���ɾ�����޸�:" << endl;
		cout << "��5��ɾ������" << endl;
		cout << "��6���޸�����" << endl;
		cout << "��0���������һ򷵻����˵�" << endl;
		cin >> n;
		if (n == 5){
			Delete(k);
		}
		else if (n == 6){
			Modify(k);
		}
	}
}
//����
void Student_System::Sort(){
	int r;
	cout << "��������Ҫ����Ŀ�Ŀ" << endl;
	cout << "��1���ߵ���ѧ" << endl;
	cout << "��2����ѧ����" << endl;
	cout << "��3����̻���" << endl;
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
	cout << "�������" << endl;
}
//�����������
void Student_System::outData(int o){
	if (a[o].name.size() <= 6){
		cout << o + 1 << "\t" << a[o].ID << "\t" << a[o].name << "\t\t" << a[o].Cla << "\t" << a[o].math << "\t\t" << a[o].physics << "\t\t" << a[o].c << endl;
	}
	else{
		cout << o + 1 << "\t" << a[o].ID << "\t" << a[o].name << "\t" << a[o].Cla << "\t" << a[o].math << "\t\t" << a[o].physics << "\t\t" << a[o].c << endl;
	}
}
//�ж������Ƿ�ƥ��
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







