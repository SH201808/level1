#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	vector<int>obj;
	for (int i = 0; i < 100; i++){
		obj.push_back(i);
	}
	for (int i = 0; i < 100; i++)
		cout << obj[i] << endl;
}