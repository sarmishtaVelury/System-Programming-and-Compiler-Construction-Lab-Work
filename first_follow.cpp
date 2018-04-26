#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int identify(char x){

	vector<char> non_terminals = {'E','F','T','Z','Y'};
	vector<char> terminals = {'a','+','*','(',')'};
	char end_of_input = '$', epsilon = '#';

	if(x == epsilon)
		return 0;

	for (std::vector<char>::iterator i = non_terminals.begin(); i != non_terminals.end(); ++i)
	{
		if(*i == x)
			return 1;
	}

	for (std::vector<char>::iterator i = terminals.begin(); i != terminals.end(); ++i)
	{
		if(*i == x)
			return 2;
	}

}

int main(){

	map <char, vector<string> > production_map;
	map <char,set<char> > first;
	map <char,set<char> > follow;

	production_map['E'].push_back("TZ");
	production_map['Z'].push_back("+TZ");
	production_map['Z'].push_back("#");
	production_map['T'].push_back("FY");
	production_map['Y'].push_back("*FY");
	production_map['Y'].push_back("#");
	production_map['F'].push_back("(E)");
	production_map['F'].push_back("a");

	vector<char> non_terminals = {'E','F','T','Z','Y'};
	vector<char> terminals = {'a','+','*','(',')'};

	char start_symbol = '$', epsilon = '#';

	cout<<"Productions:\n";

	for (std::vector<char>::iterator i = non_terminals.begin(); i != non_terminals.end(); ++i)
	{
		for (std::vector<string>::iterator j = production_map[(*i)].begin(); j != production_map[(*i)].end(); ++j)
		{
			cout<<*i<<"->";
			cout<<*j<<"\n";

			int temp = identify((*j)[0]);

			if(temp == 0){
				first[(*i)].insert('#');
			}

			else if(temp == 2){
				first[(*i)].insert((*j)[0]);
			}

			else if(temp == 1){
				std::set<char> v;
				set<char>::iterator it;
				it = first[(*j)[0]].begin();
				v.insert(it,first[(*j)[0]].end());
				first[(*i)].insert(v.begin(),v.end());
			}
		}
		
	}

	cout<<"\nFirst iteration:\n";

	for(auto& x:first){
		cout<<x.first<<"= {";
		for (set<char>::iterator i = x.second.begin(); i != x.second.end(); ++i)
		{
			cout<<*i<<", ";
		}
		cout<<"}\n";
	}

	cout<<"\n";

	for (std::vector<char>::iterator i = non_terminals.begin(); i != non_terminals.end(); ++i)
	{
		
		string non_term = (*i) + "";
		for (std::vector<string>::iterator j = production_map[(*i)].begin(); j != production_map[(*i)].end(); ++j)
		{
			int temp = identify((*j)[0]);

			if(temp == 0){
				first[(*i)].insert('#');
			}

			else if(temp == 2){
				first[(*i)].insert((*j)[0]);
			}

			else if(temp == 1){
				std::set<char> v;
				set<char>::iterator it;
				it = first[(*j)[0]].begin();
				v.insert(it,first[(*j)[0]].end());
				first[(*i)].insert(v.begin(),v.end());
			}
		}
		
	}

	cout<<"Final:\n";

	for(auto& x:first){
		cout<<x.first<<"= {";
		for (set<char>::iterator i = x.second.begin(); i != x.second.end(); ++i)
		{
			cout<<*i<<", ";
		}
		cout<<"}\n";
		
	}

}