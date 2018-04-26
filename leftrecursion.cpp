#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int identify(char x){

	vector<char> non_terminals = {'A', 'B', 'C'};
	vector<char> terminals = {'a','+','c','b'};
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

int main()
{
	vector <string> prods;
	map <string,vector<string> > production_map;
	map <string,vector<string> > new_production_map;

	production_map["A"].push_back("A+B");
	production_map["A"].push_back("b");
	production_map["B"].push_back("Ca");
	production_map["C"].push_back("Bb");
	production_map["B"].push_back("c");

	for(auto& x:production_map){
		for (vector<string>::iterator i = x.second.begin(); i != x.second.end(); ++i)
		{
			cout<<x.first<<"->"<<*i<<"\n";
		}
	}

	for(auto& x:production_map){
		for(auto& y:production_map){
			for (vector<string>::iterator j = y.second.begin(); j != y.second.end(); ++j)
			{
				string current_rule = *j;
				cout<<"Check for indirect left recursion of "<<x.first[0]<<":"<<current_rule<<"\n";
				if(x.first[0] == current_rule[0] && y.first[0] != current_rule[0] && x.first[0]<y.first[0]){
					cout<<"Found indirect left recursion"<<"\n";
					(x.second[0]).replace(0,1,current_rule);
					cout<<"Adding rule:"<<(*j)<<"\n";
				}		
			}
		}
	}

	for(auto& x:production_map){
		for (vector<string>::iterator i = x.second.begin(); i != x.second.end(); ++i)
		{
			string old_rule = *i;
			cout<<"Check for direct left recursion:"<<old_rule[0]<<"\n";
			if(x.first[0] == old_rule[0]){
				cout<<"Found direct left recursion"<<"\n";
				string new_non_terminal = x.first + "\'";
				string new_rule = *(++i) + x.first + "\'";
				new_production_map[x.first].push_back(new_rule);
				new_rule = (*(--i)).substr(1,string::npos) + new_non_terminal ;
				new_production_map[new_non_terminal].push_back(new_rule);
				new_production_map[new_non_terminal].push_back("#");
				break;
			}
			else{
				new_production_map[x.first].push_back((*i));
			}	
		}
	}

	for(auto& x:new_production_map){
		for (vector<string>::iterator i = x.second.begin(); i != x.second.end(); ++i)
		{
			cout<<x.first<<"->"<<*i<<"\n";
		}
		
	}
	
	return 0;
}





	
	// for(auto& x:production_map){
	// 	for(auto& y:production_map){
	// 		for (vector<string>::iterator j = y.second.begin(); j != y.second.end(); ++j)
	// 		{
	// 			string current_rule = *j;
	// 			cout<<"Check for indirect left recursion of "<<x.first[0]<<":"<<current_rule<<"\n";
	// 			if(x.first[0] == current_rule[0] && y.first[0] != current_rule[0]){
	// 				cout<<"Found indirect left recursion"<<"\n";
	// 				// string new_non_terminal = x.first + "\'";
	// 				// string new_rule = *(++i) + x.first + "\'";
	// 				// new_production_map[x.first].push_back(new_rule);
	// 				// new_rule = (*(--i)).substr(1,string::npos) + new_non_terminal ;
	// 				// new_production_map[new_non_terminal].push_back(new_rule);
	// 				// new_production_map[new_non_terminal].push_back("#");
	// 				// string new_rule = *j 
	// 				production_map[x.first].push_back((*j)+)
	// 				(*j).replace(0,1,current_rule);
	// 				cout<<"Adding rule:"<<(*j)<<"\n";
	// 			}		
	// 		}
	// 	}
	// }