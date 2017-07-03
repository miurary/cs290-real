/**********************************************************
 * Program: adventure.cpp
 * Author: Ryan Miura
 * Date: 1/17/17
 * Description: Adventure game about a donut shop owner.
 * Input: 1, 2, and 3 to make choices.
 * Output: Text to advance story plot. 
 *********************************************************/


#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>


using namespace std;


int main() {

int play = 1;

while (play == 1){

	int story = 0;
		
	int emp = 0;

		cout << "You are a youngin' beginning your journey through life." << endl;

		cout << "You own a donut shop which you manage with one employee." << endl;

		cout << "This is your story." << endl;


	
		while (story == 0) {

			cout << "Type 1 to wake up: " << endl;
		
			cin >> story;
			
				if (story == 1) {
			 
				cout << "You open your eyes, ready to start another day." << endl;
			
				}	

				else {
			
					story = 0;
	
				}
	
		}
	
		story = 0;
	
		cout << "You get dressed and head into work at your shop." << endl;

		cout << "You meet your employee who has arrived to start the day as well." << endl;

	
		while (story == 0) {

			cout << "Type 1 to talk to them. Type 2 to open up shop instead: " << endl;

			cin >> story;
		
				if (story == 1) {		 
					
					int talk = 0;
	
					cout << "You talk to your employee." << endl;

					cout << "You notice they seemed troubled." << endl;

					while (talk == 0){

						cout << "Type 1 to ask what's wrong. Type 2 to open up shop instead." << endl;

						cin >> talk;

							if (talk == 1){

								cout << "You ask what's wrong." << endl;

								cout << "They tell you that their relative recently passed." << endl;

								cout << "You tell them that you are sorry and that they can" << endl;

								cout << "take the rest of the day off if they wish." << endl;

								cout << "They thank you, but decide to stay." << endl;

								cout << "Their mood seems to have improved." << endl;

								emp = 1;

								cout << "After that, you decide to open up shop." << endl;
							}

							else if (talk == 2){

								cout << "You decide to open up shop." << endl;
			
							}	

							else {

								talk = 0;

							}

					}

				}

				else if (story == 2) {

					cout << "You decide to open up shop." << endl;

				}

				else {

					story = 0;

				}

		}
		
		story = 0;
		
		while (story == 0){

			cout << "Type 1 to man the register. Type 2 to work on a new donut." << endl;

			cin >> story;

			int donut = 0;

			int cust = 0;

				if (story == 1){

					cout << "You stand at the register, waiting for customers." << endl;
					
					cout << "A woman comes through the door." << endl;

					cout << "She asks for a maple bar." << endl;

					while (cust == 0){

						cout << "Type 1 to give her a maple bar. Type 2 to tell her that you are out: " << endl;

						cin >> cust;

						if (cust == 1){

							cout << "She thanks you and leaves happily." << endl;
					
						}
						
						else if (cust == 2){

							cout << "She cries and runs away." << endl;

						}

						else{
		
							cust = 0;

						}

					}

					cout << "You decide to go create a new donut flavor." << endl;

					while (donut == 0){

						cout << "Type 1 to choose Rainbow Filled Lucky Charms." << endl;

						cout << "Type 2 to choose Death." << endl;

						cout << "Type 3 to choose Oatmeal Raisin Hung: " << endl;
 						
						cin >> donut;

						if (donut == 1){

							cout << "You put all your love into creating the Rainbow Filled Lucky Charms donut." << endl;

						}

						else if (donut == 2){

							cout << "You put no effort whatsoever into creating the Death donut." << endl;

						}

						else if (donut == 3){

							cout << "You rely on someone else to create the Oatmeal Raisin Hung donut." << endl;

						}

						else{

							donut = 0;

						}			

					}	
			
				}	

				else if (story == 2){

					cout << "You decide to go create a new donut flavor." << endl;

					while (donut == 0){

						cout << "Type 1 to choose Rainbow Filled Lucky Charms." << endl;
						
						cout << "Type 2 to choose Death." << endl;

						cout << "Type 3 to choose Oatmeal Raisin Hung: " << endl;

						cin >> donut;

						if (donut == 1){

							cout << "You put all your love into creating the Rainbow Filled Lucky Charms donut." << endl;
					
						}

						else if (donut == 2){

							cout << "You put no effort whatsoever into creating the Death donut." << endl;

						}

						else if (donut == 3){

							cout << "You rely on someone else to create the Oatmeal Raisin Hung donut." << endl;

						}

						else{

							donut = 0;
				
						}						

					}

					cout << "You stand at the register, waiting for customers." << endl;

					cout << "A woman comes through the door." << endl;

					cout << "She asks for a maple bar." << endl;

					while (cust == 0){

						cout << "Type 1 to give her a maple bar. Type 2 to tell her that you are out." << endl;

						cin >> cust;
				
						if (cust == 1){

							cout << "She thanks you and leaves happily." << endl;

						}

						else if (cust == 2){

							cout << "She cries and runs away." << endl;

						}

						else{

							cust = 0;

						}

					} 
					

				}

				else{

					story = 0;

				}	

			


		}


		story = 0;

		cout << "A man comes through the door." << endl;

		cout << "He asks for your best donut." << endl;

		while(story == 0){

			cout << "Type 1 to give him a maple bar. Type 2 to give him your special donut. Type 3 to give him nothing: " << endl;

			cin >> story;

			if(story == 1){

				cout << "He says it's alright, but not what he's looking for." << endl;

				return 0;

			}

			else if(story == 2){

				cout << "He says it's delicious! The best thing he's ever tasted!" << endl;

			}

			else if(story == 3){

				cout << "He turns around and walks away." << endl;

				return 0;

			}
			
			else{

				story = 0;

			}






		}

		story = 0;

		cout << "He asks if you've ever though of going on the road with your donuts." << endl;

		cout << "He offers to fund your international donut trip." << endl;

		while (story == 0){

			cout << "Type 1 to take him up on his offer. Type 2 to decline and go home for the day: " << endl;

			cin >> story;

			if (story == 1){

				cout << "You graciously take him up on his offer." << endl; 	

			}

			else if (story == 2){

				cout << "You thank him for the offer, but decline and head home for the day." << endl;

				return 0;	

			}

			else{

				story = 0;
			
			}

		}

		story = 0;

		cout << "You take a day to gather your stuff together, then go and pick up your cart." << endl;

		if (emp == 1){

			cout << "Your employee meets up with you, saying they want to come along too." << endl;

		}

		else{

			cout << "You check the cart, preparing yourself for a long journey alone." << endl;

		}

		cout << "Finally ready, you take your cart to LA for the start of your journey." << endl;

		cout << "A rival donut shop approaches you and tells you to get off their turf." << endl;

		int fr = 0;

		while (story == 0){

			cout << "Type 1 to fight them. Type 2 to ignore them. Type 3 to ask them to work with you." << endl;
	
			cin >> story;

			if (story == 1){
			
				cout << "You try to fight them, but lose terribly. You return home, defeated." << endl;

				return 0;

			}

			else if (story == 2){

				cout << "You decide to ignore them, going about your own business." << endl;

			}

			else if (story == 3){

				cout << "You ask them to work with you. They agree and you quickly become friends." << endl;

				fr ++;

			}

			else{

				story = 0;

			}

		}

		story = 0;

		cout << "You have amazing success in LA, so you decide to continue your journey westward." << endl;

		cout << "You pack your cart on a boat and head towards Japan." << endl;

		cout << "On the way, some sharks surround your boat, refusing to let you move forward." << endl;

		while (story == 0){

			cout << "Type 1 to fight them. Type 2 to run away. Type 3 to feed them some donuts." << endl;

			cin >> story;

			if (story == 1){

				cout << "You successfully fight off the sharks and head to Tokyo." << endl;

			}

			else if (story == 2){

				cout << "You flee back to LA, ending your journey early." << endl;

				return 0;

			}

			else if (story == 3){

				cout << "You decide to feed the sharks some donuts. They love them and even guide you to Tokyo." << endl;

				cout << "You wave to them from the shore as they head back out to the ocean." << endl;

				fr ++;

			}

			else{

				story = 0;

			}

		}

		story = 0;

		cout << "You enter Tokyo and immediately look for somewhere to set up shop." << endl;

		cout << "You also immediately get lost. You find yourself infront of a hotel and a ramen shop." << endl;

		while (story == 0){

			cout << "Type 1 to enter the hotel. Type 2 to enter the ramen shop." << endl;

			cin >> story;

			if (story == 1){

				cout << "You enter the hotel. They offer you a room for the night, which you accept." << endl;

				cout << "In the morning, you find that you've been scammed out of a majority of your money." << endl;

				cout << "You return home having learned a lot along your journey." << endl;

				return 0;

			}

			else if (story == 2){

				cout << "You enter the ramen shop. The chef offers you a bowl." << endl;

				cout << "You tell him your story and he relates, telling you about his own cart adventure." << endl;

				cout << "He tells you where to head to and you thank him for the meal." << endl;

				fr ++;

			}

			else{

				story = 0;

			}

		}

		story = 0;

		cout << "You set up your cart for the final time along your journey. Again, you are very successful." << endl;

		cout << "The next day, you head back to LA. You drop off your cart and head back home." << endl;

		cout << "On the way home, you get run off the road by some robbers after your money." << endl;

		while (story == 0){

			cout << "Type 1 to fight them. Type 2 to give them your money. Type 3 to call for help." << endl;

			cin >> story;

			if (story == 1){

				cout << "You try and fight them, but are beaten. You lose all your money and head home." << endl;

				return 0;

			}

			else if (story == 2){

				cout << "You give them all your money and head home." << endl;

				return 0;

			}

			else if (story == 3){

				cout << "You call for help." << endl;

				if (fr == 3){

					cout << "The people you met along your journey show up to help you fight." << endl;

					int ran;

					srand (time(NULL));

					ran = rand() % 10;

					if (ran <= 5){

						cout << "You fight, but even with your friends it isn't enough." << endl;

						cout << "You lose all your money and head home." << endl;

						return 0;

					}

					else{
					
						cout << "You fight together and beat the robbers." << endl;

						cout << "You head home with your money and the experiences of your adventure." << endl;

					}

				}
		
				else{

					cout << "No one comes. You lose all your money and return home." << endl;

					return 0;

				}	
	
			}

			else{

				story = 0;

			}

		}

		




play = 2;

cout << "The End." << endl;

cout << "Play again? Type 1 for yes. Type 2 for no." << endl;

cin >> play;

if (play == 2){

	return 0;

	}

else if (play == 1){

	play = 1;

}

else{

	return 0;

}

}
 
}





	
	/* srand (time(NULL));

	cout << rand() % 100 + 1 << endl;

	return 0;
	*/


	
