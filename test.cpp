#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void iferror(string word){

}

int main(){
	stringstream ss (stringstream::in | stringstream::out);
	int flag = 0;
	string keywords[] = {"let", "and", "in", "if", "then", "else", "recur", "loop", "end"}, operators[] = {"(", ")", "=", "&&", "||", "!", "<", "==", "+", "*", "-"};
	string program,word;
	getline(cin,program,'.');    //using . as a delimiter for now; will replace with an eof later 
	ss<<program;
	cout<<endl;
	word = "test";
	while(word!=""){
		flag = 0;
		word = "";
		ss>>word;
		if(word == "")
			continue;
		for(int i = 0 ; i<(sizeof(keywords)/sizeof(string)) && flag!=1; i++){
			if(word.compare(keywords[i]) == 0){
				cout<<"keyword\t"<<"\t"<<word<<endl;
				flag = 1;
				break;
			}
		}
		for(int i = 0 ; i<(sizeof(operators)/sizeof(string)) && flag!=1; i++){
			if(word.compare(operators[i]) == 0){
				cout<<"operator\t"<<word<<endl;
				flag = 1;
				break;
			}
		}
		if((word.find_first_not_of("0123456789") == string::npos) && flag!=1){
			cout<<"integer\t"<<"\t"<<word<<endl;
			flag = 1;
			continue;
		}
		if((word.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == string::npos) && (!(word.at(0)>='0' && word.at(0)<='9')) && flag!=1){
			cout<<"identifier\t"<<word<<endl;
			flag = 1;
			continue;
		}
		if(flag != 1){
			iferror(word);
			cout<<"error\t\t"<<word<<endl;
		}
	}
	return 0;
}
