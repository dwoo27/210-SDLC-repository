#include <iostream>
//include fstream, map, array, list, string
using namespace std;

//const for num of sims

//funciton prototypes:
//fin orders data
//output shop
//simulate shop

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
	//open file of order data
	//output error if file fails
	 
	// each line will contain orderName and stationName
	 
	// read each order and place in waiting list
	
	// close file

//output shop
	//loop through each station in map
	
	//print orders waiting

	//print orders in progress

	//print orders completed


//simulate shop
	//loop for 25 time periods
		
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
		









		//check if drink is in progress
			//move one drink to completed
			//ouptut action

		//check if there is waiting order
			//move one drink to in progress
			//output action

