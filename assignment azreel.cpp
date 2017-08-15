
#include <iostream>
#include <fstream> // file & outfile 
#include <sstream> // convert from string to int
using namespace std;

int main() {

ifstream file("input.txt");
ofstream outfile;


 if (file.good())
  {
  	string n, item_id;
	double ori_price, sell_price;
	int qtty;
    getline(file, n);
	
	int total;
	istringstream ( n ) >> total;
	
	outfile.open("output.txt");
	outfile << "Profit made :\n";
	
	double profit, totalProfit = 0;
	
	for(int i=0; i<total; i++){
		file >> item_id >> ori_price >> sell_price >> qtty;
		//cout <<item_id<<endl;
		
		profit = (sell_price * qtty) - (ori_price * qtty);
		totalProfit += profit;
		outfile << item_id <<"\tRM" << profit <<"\n";
	}
	
	outfile <<"***TOTAL PROFIT ===> RM" << totalProfit << "\n";
	outfile.close();
	file.close();
  }
return 0;
}
