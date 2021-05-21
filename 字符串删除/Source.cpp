#include<iostream>
#include<string>
using namespace std;
void Delete(string &str, char n){
	int i;
	int len = str.size();
	for (i = 0; i < len; i++){
		if (str[i] == n){
			break;
		}
	}
	for (i; i < len; i++){
		str[i] = str[i + 1];
	}
	for (int j = 0; j < len; j++)
		cout << str[j];
}
void Stop(string &str, char n){
	int len = str.size();
	for (int i = 0; i < len; i++){
		if (str[i] == n){

		}
	}
}
int main()
{
	string s;
	s = "py\nthon";
	cout << s << endl;;
	Stop(s, '\n');
	cout << s;
	return 0;
}