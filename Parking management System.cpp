#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <regex>
#include <set>
#include <windows.h> 
using namespace std;
void setConsoleColor(int color)
	{
	    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	    SetConsoleTextAttribute(hOut, color);
	}
struct Car
	{ 
	    string type;
	    string regNum;
	    double amount;
	    int slotNum;
	};
string to_uppercase(const string& s)
	{
	    string result = s;
	    for (char& c : result) 
		{
	        c = toupper(c);
	    }
	    return result;
	}
	
bool is_valid_reg_num(string regNum) 
	{
	    regex pattern("[A-Za-z]{3}-\\d{3}");
	    return regex_match(regNum, pattern);
	}

void white(){
	setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void blue() 
{
	  setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
void green()
{
	 setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
void red()
{
	 setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
}
void magneta()
{
	setConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY); 
}
void titleline()
{   blue();
	cout<<" ===============================================================================================================================================================================================================";
	cout<<"\n||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>The ZAIDI's Parking Space<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<||";
	cout<<"\n   ===============================================================================================================================================================================================================\n\n"<<endl;
	}

int main() 
{
	    int choice1,check;
	    int parkingSpace = 50;
	    vector<Car> cars; 
	    double totalAmount = 0; 
	    vector<int> parkingSlots(parkingSpace, 0); 
		set<string> previousCars;
	   
	while (true) 
		{   			
	        system("cls");
	        int option;
	       titleline();
			white();
	        	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t1. Press -> 1 for Entering"<<endl;
		        cout<<"\t\t\t\t\t\t\t\t\t\t\t2. Press -> 2 for Exiting"<<endl;
		        cout<<"\t\t\t\t\t\t\t\t\t\t\t3. Press -> 3 for Total Revenue"<<endl;
		        cout<<"\t\t\t\t\t\t\t\t\t\t\t4. Press -> 4 for Exit The program"<<endl;
		        cout<<"\t\t\t\t\t\t\t\t\t\t\t5. Press -> 5 to Check all parked Cars"<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\t\t6. Press -> 6 to Check all available slots"<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\t\t7. Press -> 7 to Check number of parked Cars"<<endl;
		        cout<<"\t\t\t\t\t\t\t\t\t\t\t8. Press -> 8 to Check all exited Cars" << endl;
	        cin >> option;
		    if (option == 1) 
			{
	            system("cls");
	            if (parkingSpace > 0)
				{
	                Car car;
	                int carTypeNum;
					titleline();
	                magneta();
				
	                cout <<"\t\t\t\t\t\t\t\t\t\t\t\t1. PRESS -> 1 for Car"<<endl;
	                cout <<"\t\t\t\t\t\t\t\t\t\t\t\t2. PRESS -> 2 for Bus"<<endl;
	                cout <<"\t\t\t\t\t\t\t\t\t\t\t\t3. Press -> 3 for Rikshaw"<<endl;
	                cout <<"\t\t\t\t\t\t\t\t\t\t\t\t4. Press -> 4 to go Back to mainmenu"<<endl;
	                cin >> carTypeNum;
				
	                
	                switch (carTypeNum) {
	                    case 1:
	                        car.type = "Car";
	                        car.amount = 100;
	                        system("cls");
	                        break;
	                    case 2:
	                        car.type = "Bus";
	                        car.amount = 150;
	                        system("cls");
	                        break;
	                    case 3:
	                        car.type = "Rickshaw";
	                        car.amount = 50;
	                        system("cls");
	                        break;
	                    case 4:
	                    	continue;    
	                    default:
	                        system("cls");
	                        
	                        {
	                        titleline();
	                        }red();
	                        {
	                        cout << "\t\t\t\t\t\t\t\t\t\t\t\tInvalid car type number." << endl;
							}
	                        return 1;
	                }
	                
	                int availableSlot = -1;
	                for (int i = 0; i < parkingSlots.size(); i++) 
					{
	                    if (parkingSlots[i] == 0) 
						{
	                        availableSlot = i;
	                        break;
	                    }
	                }
	                if (availableSlot == -1)
					{	titleline();
					    red();
	                    cout << "\t\t\t\tError: No available parking slot found." << endl;
	                    return 1;
	                }
	                car.slotNum = availableSlot;
	              
	            
	              	titleline();
	                red();
	                {	
				    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Parking space available at slot: " << availableSlot + 1 << "\n\n" << endl;
	                }
					cout << "\t\t\t\t\t\t\t\t\t   Enter the registration number of the " << car.type << " (format: AAA-000): ";
		           		 while (true) 
						{	
							while (true)
							{
							cin >> car.regNum;
							
							if (is_valid_reg_num(car.regNum)) 
								break;
						    
						    else
						    	{
								system("cls");
								titleline();
								red();
			                    cout << "\t\t\t\t\t\t\t\tInvalid registration number format. Please enter in the format AAA-000: ";
			               		}
			            	}
							car.regNum = to_uppercase(car.regNum);
						        bool isCarParked = false;
						        for (const auto& parkedCar : cars)
						        {
						            if (parkedCar.regNum == car.regNum)
						            {
						                isCarParked = true;
						                break;
						            }
						        }
						        if (isCarParked)
						        {
						        	blue();
						            system("cls");
						            titleline();
						            red();
						            cout <<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t!!!!!!! WARNING !!!!!!!";
						            
						            white();
						            cout << "\n\n\t\t\t\t\t\t\t\t\t\tThe car with registration number " << car.regNum << " is already parked.\n\n" << endl;
						            system("pause");
						            check=0;
						            
						            break;
						        }
						        else 
						        {
								
						        check=1;
						      
						    }
						        if (previousCars.find(car.regNum) != previousCars.end()) 
						        {
						            car.amount *= 0.9; 
						            system("cls");
						           	titleline();
						            green();
						            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\tWelcome Back\n\t\t\t\t\t\t\t\t\t\t\t Its Good to see you again ";
						        }
						        break;
						    } 
						    if (check==1)
						    {
							parkingSlots[availableSlot] = 1; 
					totalAmount += car.amount;
	                cars.push_back(car);
	                parkingSpace--; 
	                green();
	                {
	                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t    Your " << car.type << " is parked at slot " << car.slotNum + 1 << endl;
	                cout << "\t\t\t\t\t\t\t\t\t\t\t       Amount payable : $" << car.amount << endl;
	                system("pause");
					}
				}
	            } 
				else 
				{
					system("cls");
					titleline();
					red();
		            cout << "\n\n\t\t\t\tParking is full. No space available.\n\n" << endl;
		            system("pause");
		        }
	        } 
			else if (option == 2) 
				{
					Car car;
		            system("cls");
		            if (cars.size() > 0) 
					{
		                string regNum;
		               	titleline();
		               	green();
		                cout << "\n\n\t\t\t\t\t\t\t\t\tEnter the registration number of the vehicle to exit (format AAA-000) : ";
		                 while (true) 
						{
			                cin >> regNum;
			                regNum = to_uppercase(regNum);
			                if (is_valid_reg_num(regNum)) 
							{
								
			                    break;
			                } 
							else 
							{
								system("cls");
								titleline();
								red();
			                    cout << "\t\t\t\t\t\t\t\t\t\t\t Invalid registration number format. Please enter in the format AAA-000: ";
			                }
		           		}
		                bool carFound = false;
		                for (int i = 0; i < cars.size(); i++) 
						{
		                    if (cars[i].regNum == regNum) 
							{
								system("cls");
								previousCars.insert(regNum);
		                        parkingSlots[cars[i].slotNum] = 0;
		                        
		                        parkingSpace++; 
								titleline();
								green();
		                        cout << "\n\n\t\t\t\t\t\t\t\t\t\t Your " << cars[i].type << " with registration number " << cars[i].regNum << " has exited." << endl;
		                        cars.erase(cars.begin() + i); 
		                        carFound = true;
		                        break;
		                    }
		                }
		                if (!carFound) 
							{
							system("cls");
							titleline();
							red();
			                    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t No vehicle found with the given registration number.\n\n" << endl;
			                }
		                system("pause");
		            }
					 else
						{
							system("cls");
	
							titleline();
							white();
			                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t No vehicles are parked currently.\n\n" << endl;
			                system("pause");
			            }
		        } 
			
			else if (option == 3) 
			{
	            system("cls");
	     		titleline();
	     		green();
	            cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\tTotal Revenue: $" << totalAmount << endl;
	            system("pause");
	        } 
			else if (option == 4) 
				{
		            break;
		        } 
			else if (option == 5) 
			{
			   system("cls");
				if (cars.size() > 0) 
					{
					    titleline();
					    blue();
					    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\tList of parked cars:\n\n" << endl;
					    cout << "\t\t\t\t\t\t\t\t\t\t---------------------------------------------------------" << endl;
					    cout << "\t\t\t\t\t\t\t\t\t\t|    Type    |   Registration Number   |  Parking Slot  |" << endl;
					    cout << "\t\t\t\t\t\t\t\t\t\t---------------------------------------------------------" << endl;
					
					    for (int i = 0; i < cars.size(); ++i)
						{
					        Car car = cars[i];
					        cout << "\t\t\t\t\t\t\t\t\t\t| " << setw(10) << car.type << " | " << setw(23) << car.regNum << " | " << setw(14) << car.slotNum + 1 << " |" << endl;
					    }
					    cout << "\t\t\t\t\t\t\t\t\t\t---------------------------------------------------------" << endl;
					   
					}  
				else
				    {
				    	cout << "No cars are currently parked." << endl;
					}
					 system("pause");
			}
			else if (option == 6) 
		{
		    system("cls");
			titleline();
		    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Available parking slots: " << endl;
		    cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
		    cout << "\t\t\t\t\t\t\t\t\t\t\t\t| Slot No. | Availability      |" << endl;
		    cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
		    for (int i = 0; i < parkingSlots.size(); i++) 
			{
				white();
		        cout << "\t\t\t\t\t\t\t\t\t\t\t\t| " << setw(8)  <<i + 1 << " |";
		        
		        if (parkingSlots[i] == 0) 
					{green();
		            	cout << " " << setw(17) << "Available" << " |" << endl;
		        	}
		        else  
					{
						red();
		        	    cout << " " << setw(17) << "Occupied" << " |" << endl;
		        	}
		    }
		    white();
		    cout << "\t\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
		    cout << endl;
		    system("pause");
		}
		else if (option == 7) 
	    {
	        system("cls");
	       	titleline();
	        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t      Number of parked cars: " << cars.size() << "\n\n" << endl;
	        system("pause");
	    }
	    else if (option == 8) 
	        {
	            system("cls");
	            if (previousCars.size() > 0) 
	            {
	        		titleline();
	                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\tList of exited cars:\n\n" << endl;
	                for (auto regNum : previousCars) 
	                {
	                    cout << "\t\t\t\t\t\t\t\t\t\t\t   Registration Number: " << regNum << endl;
	                }
	            } 
	            else 
	            {
	            	red();
	                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\tNo cars have exited yet.\n\n" << endl;
	            white();
	           
	        }
	         system("pause");
	        }
		else
		{
			red();
			cout<<"\t\t\t\t\t\t\t\t\t\t\t Invalid input"<<endl;
			system("pause");
		}
	}	
	return  0;
}


