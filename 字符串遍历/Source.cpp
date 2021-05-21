#include<iostream>
#include<string>
using namespace std;
bool bianli(string &s, string&s1){
	int len = s.size(),len1=s1.size();
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
int main(){
	string s, s1;
	getline(cin, s);
	getline(cin, s1);
	if (bianli(s, s1)){
		cout << "Æ¥Åä" << endl;
	}
	else{
		cout << "²»Æ¥Åä" << endl;
	}
}