#include <iostream>
#include <fstream>
#include <map>
#include <array>
#include <list>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

//include fstream, map, array, list, string
using namespace std;

//const for num of sims
const int PERIODS = 25;

//funciton prototypes:
//fin orders data
//output shop
//simulate shop

void loadOrders(vector<string>&, vector<string>&);
void displayShop(map<string, array<list<string>, 3>>);
void simShop(array<list<string>, 3>&, vector<string>&, vector<string>&, int);

int main()
{
	//seed rand generater

	//declare boba shop map
	//key = station, value = array of 3 lists

	//declare pair vectrs for upcoming order pool
	//orderNames and stationNames

	//create stations in map

	//load all orders from txt file into vectors

	//display beg state of shop

	//run sim

	//display final state of shop
}

//function definitions:

//fin orders data
void loadOrders(vector<string>& orderNames, vector<string>& stationNames) {

	//open file of order data
	//output error if file fails
	ifstream fin("orders.txt");

	if (!fin.good()) {
		cout << "File not found.";
		return;
	}


	// each line will contain orderName and stationName
	string orderName;
	string stationName;

	// read each order and place in waiting list
	while (fin >> orderName >> stationName) {
		orderNames.push_back(orderName);
		stationNames.push_back(stationName);
	}

	// close file
	fin.close();

}

//output shop
void displayShop(map<string, array<list<string>, 3>> shop){

	//loop through each station in map
	for (const auto& pair : shop) {
		cout << "Station: " << pair.first << endl;
		//print orders waiting
		cout << "   Waiting: ";
		for (const auto& drink : pair.second[0]) {
			cout << drink << " ";
		}
		cout << endl;
		//print orders in progress
		cout << "   In Progress: ";
		for (const auto& drink : pair.second[1]) {
			cout << drink << " ";
		}
		cout << endl;

		//print orders completed
		cout << "   Completed: ";
		for (const auto& drink : pair.second[2]) {
			cout << drink << " ";
		}
		cout << endl;

	}
}

//simulate shop
void simShop(map<string, array<list<string>, 3>> shop, vector<pair<string, string>>& orderPool, int periods) {

	//loop for 25 time periods
	for (int i = 1; i <= periods; i++) {

		//random amount of new orders for this period
		int newOrders = rand() % 6;

		//make sure new orders !> orders left in pool
		if (newOrders > (int)orderPool.size()) {
			newOrders = orderPool.size();
		}

		//random amount of orders from pool moved to correct station
		for (int i = 0; i < newOrders; i++) {
			//check for empty pool
			if (orderPool.empty()) {
				break;
			}

			//choose rand index
			int index = rand() % orderPool.size();

			//get rand pair
			string orderName = orderPool[index].first;
			string stationName = orderPool[index].second;

			//find station
			auto it = shop.find(stationName);

			//check it exists and add order to waiting list
			if (it != shop.end()) {
				it->second[0].push_back(orderName);
				cout << orderName << " arrived at " << stationName << endl;
			}

			//remove order from pool so it is not reused
			orderPool.erase(orderPool.begin() + index);
		}

		//loop through each station
		for (auto& pair : shop) {
			string stationName = pair.first;

			//rand num of waiting drinks are started
			int started = rand() & 3;
			for (int i = 0; i < started && !pair.second[0].empty(); i++) { //loop through and check waiting list is not empty
				string drink = pair.second[0].front(); //first drink in waiting list
				pair.second[0].pop_front(); //drink taken from waiting list and put into in progress
				pair.second[1].push_back(drink);
				cout << drink << " started at " << stationName << endl;
				
			}

			//rand num of in progress drinks completed
			int finished = rand() % 3;
			for (int i = 0; i < finished && !pair.second[1].empty(); i++) { //loop through and check in progress not empty
				string drink = pair.second[1].front(); //first drink in in progress
				pair.second[1].pop_front(); //drink taken from in progress and put in finished 
				pair.second[2].push_back(drink);
				cout << drink << " finished at " << stationName << endl;
			}
		}


		//print current time period

		//randomly decide how many new orders will arive for this period

		//randomly pull some orders from name/type vectors
		//each order goes into waiting list of its station

			//stop if orders is empty

			//choose one random order left in order pool

			//get chosen order and its matching station

			//place order into waiting ist for that station

			//dislay where order went

			//erase order from both vectors so not resused


		//loop through each station
			//move some wiaint drinks to in progress
			//move some in progress drinks to completed

				//random num of drinks to start perdiod

				//move drinks from waiting to in progress

				//rand num drinks that finish period

				//move drinks from in progress to completed
	}

}








	