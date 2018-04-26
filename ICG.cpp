#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void iferror(string word){
	cout<<"Error at "<<word;
}

int main(){
	stringstream ss (stringstream::in | stringstream::out);
	int flag = 0;

	vector <string> op, key, var, consts;

	string keywords[] = {"let", "and", "in", "if", "then", "else", "recur", "loop", "end"}, operators[] = {"(", ")", "=", "&&", "||", "!", "<", ">", "==", "+", "*", "-", "^"};
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
				key.push_back(word);
				flag = 1;
				break;
			}
		}
		for(int i = 0 ; i<(sizeof(operators)/sizeof(string)) && flag!=1; i++){
			if(word.compare(operators[i]) == 0){
				cout<<"operator\t"<<word<<endl;
				op.push_back(word);
				flag = 1;
				break;
			}
		}
		if((word.find_first_not_of("0123456789") == string::npos) && flag!=1){
			cout<<"integer\t"<<"\t"<<word<<endl;
			consts.push_back(word);
			flag = 1;
			continue;
		}
		if((word.find_first_not_of("0123456789.") == string::npos) && flag!=1){
			cout<<"float\t"<<"\t"<<word<<endl;
			consts.push_back(word);
			flag = 1;
			continue;
		}
		if((word.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == string::npos) && (!(word.at(0)>='0' && word.at(0)<='9')) && flag!=1){
			cout<<"identifier\t"<<word<<endl;
			var.push_back(word);
			flag = 1;
			continue;
		}
		if(flag != 1){
			//iferror(word);
			cout<<"error\t\t"<<word<<endl;
		}
	}

	//cout<<int(op.size())<<"\t"<<int(key.size())<<"\t"<<int(var.size())<<"\t"<<int(consts.size());

	int n = int(var.size());
	int c = 1, j = 0, k = 0;
	for (int i = 0 ; i < int(var.size()) ;){
		string second, oper;
		string first = var.at(j);
		i++;
		j++;
		if(k < int(op.size())){
			second = var.at(j);
			i++;
			j++;
			oper = op.at(k);
			k++;
		}
		else{
			break;
		}
		stringstream pushingvar;
		pushingvar<<"T"<<k;
		var.push_back(pushingvar.str());
		cout<<pushingvar.str()<<" = "<<first<<oper<<second<<"\n";

	}

	return 0;
}