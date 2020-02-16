#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
float tempPoints(float avgtemp, float gold, float range){
	//gold is optimal temp
	float v = abs(avgtemp - gold);
	float gbpoints=(2 - pow((v/range), 2));
	//if negative then give 0 points
	if(gbpoints<0){
		gbpoints=0; 
	}
	return gbpoints;
}

bool is_file_exist(const string fileName)
{
    std::ifstream fin(fileName);
    return fin.good();
}

void emergency(char type, int time){
	//report
	if (type == 'W') {
		cout << "\nEmergency notification sent, water running with no one home at time " << time << endl;
	} else if (type == 'd'){
		cout << "\nEmergency notification sent, door opened with no one home at time " << time << endl;
	} else if (type == 'w'){
		cout << "\nEmergency notification sent, window opened with no one home at time " << time << endl;
	} else {
		cout << "\nuh oh\n";
	}
}

void advice(char type){
	//report
	if (type == 'W') {
		cout << "\nYou should make sure your water heater temperature isn't so high\n";
	} else if (type == 'w'){
		cout << "\nYou should make sure your water heater temperature isn't so low\n";
	} else if (type == 's'){
		cout << "\nYou should consider investing in security measures\n";
	} else {
		cout << "\nuh oh\n";
	}
}

int main()
{	
	//file name variable
	string fileName;
	int tCounter = 0;
	int whCounter = 0;
	char choice;
	//float temp = 0;
	float dummyValue = 0;
	float waterHeater = 0;
	float gbpoints = 0;
	int familyNum = 4;
	bool security = false;
	char timeOfDay = 'D';
	int working = 0;
	float equipmentAmount = 0;
	int time;
	int emergencies = 0;
	int deleted = 0;
	int doorE = 0;
	int windowE = 0;
	float discount;
	int user;
	
	//set up file stream
	ifstream fin;
	
	//which test case
	cout << "Which user do you wish to test? (1, 2, 3): ";
	
	//get prompt
	cin >> user;
	
	switch(user){
		
		case 1:
		fileName = "perfect.dat";
		break;
		
		case 2:
		fileName = "bad.dat";
		break;
		
		case 3:
		fileName = "general.dat";
		break;
		
		default:
		fileName = "perfect.dat";
		
	}
	
	if (is_file_exist(fileName) == true){
		//open file
		fin.open(fileName);
		while(choice != 'x'){
			//get choice
			fin >> choice;
			
			if (choice == 'h'){
				//add new temp to running total
				fin >> dummyValue;
				waterHeater += dummyValue;
				whCounter++;
			} else if ((choice == 's') && (security == false)){
				//check if security system is true or not
				fin >> dummyValue;
				if (dummyValue == 1){
					security = true;
				}
			}else if (choice == 's'){
				//type of security
				fin >> choice;
				
				//if it's working
				fin >> working;
				
				//check what kind of equipment
				if ((choice == 's') && (working == 1)){
					equipmentAmount += 2;
				} else if ((choice == 'c') && (working == 1)){
					equipmentAmount += 1;
				} else if ((choice == 'a' )&& (working == 1)){
					equipmentAmount += 1;
				}
				
				//cap the good boy point number
				if (equipmentAmount > 8){
					equipmentAmount = 8;
				}
				
				
			} else if (choice == 'W'){
				//water usage
				fin >> choice;
				
				if (choice == 'p'){
					//useless info
				} else if (choice == 'n'){
					//not present, so get time and report emergency
					fin >> time; 
					
					//emergency function
					emergency('W', time);
					emergencies++;
					windowE++;
				}
			} else if (choice == 'd'){
				//door opened
				fin >> choice;
				
				if (choice == 'p'){
					//useless info
					fin >> dummyValue;
					//cout << "\nworking\n";
				} else if (choice == 'n'){
					//get amount of door values
					fin >> dummyValue;
					
					//time
					fin >> time;
					
					//emergency
					emergency('d', time);
					emergencies++;
					doorE++;
				}
			}else if (choice == 'N'){
				//change time of day to Night
				timeOfDay = choice;
			} else if (choice == 'D'){
				//set time to day
				timeOfDay == choice;
			} else if (choice == 'w'){
				//window opened
				fin >> choice;
				
				if (choice == 'p'){
					fin >> dummyValue;
				} else if (choice == 'n'){
					//report emergency
					fin >> dummyValue;
					
					//get time
					fin >> time;
					emergency('w', time);
					emergencies++;
				}
			} else if (choice == 'e'){
				//see if nest data was deleted
				fin >> deleted;
				//cout << "worked\n\n\n\n\n";
				if (deleted == 0){
					gbpoints += 2;
					}
			} else {
				fin >> dummyValue;
			}
		}
	}
	
	//get average water heater temp
	waterHeater /= whCounter;
	//add temp ammount good boy points
	gbpoints += tempPoints(waterHeater, 120, 16);
	
	//security system check
	if (security){
		gbpoints += 3;
		gbpoints += equipmentAmount;
	}
	
	
	//add door break in points
	if (doorE > 5){
		doorE ==5;
	}
	//good boy points for door
	gbpoints += 5;
	//take away points for break ins
	gbpoints -= doorE;
	
	
	//add door break in points
	if (windowE > 4){
		windowE ==4;
	}
	//good boy points for door
	gbpoints += 4;
	//take away points for break ins
	gbpoints -= windowE;
	
	
	//emergency general points
	if (emergencies > 4){
		emergencies == 4;
	}
	
	//good boy points for door
	gbpoints += 4;
	//take away points for break ins
	gbpoints -= emergencies;
	
	//advice
	if (waterHeater > 142){
		advice('W');
	} else if (waterHeater < 98){
		advice('w');
	}
	
	if (equipmentAmount < 2){
		advice('s');
	}
	
	
	//Calculate discount ammount
	discount = 5 + gbpoints;
	
	//raw data
	cout << "\n\ndisocunt ammount = " << discount;
	
	//formatting
	cout.precision (3);
	
	//display
	cout << "\n\nCongrats your discount ammount is " << discount << "% \n";
	
	
	//test good boi points
	//cout << "GoodBoi Points: "<<gbpoints;
	
	//formatting
	cout << endl;
	
	//close file
	fin.close();	
	return 0;
}