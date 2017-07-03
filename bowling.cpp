/***
 * Program Filename: bowling.cpp
 * Author: Ryan Miura
 * Date: 3/13/2017
 * Description: Bowling simulator
 * Input: Number of players, names
 * Output: Bowling scores
 */

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

void setup (char**, int*, int**, int**);
void score_populate (int**, int*);
void names (int*);
void frame_cycle(int, int**, int*, char**, int**, int*);
void turn_cycle(int, int **, int*, char **, int **, int*, int);
void bowl (int, int**, int, int*, char**, int**, int*);
int ran (int);
void print (int**, char**, int**, int x);
void fixer (int**, int**, int);
void bowl_10 (int, int**, int, int*, char**, int**, int*);
void play_again (int*);
void header();
void name_print (char**, int);
void ten_print (int, int, int**);
void s_print (int**, int, int);
void total (int**, int);
void spacing ();
void scores (int**, int);
void roll (int*, int*, int, int*, int*, int**, char**, int**, int);
void norm_10 (int*, int, int*, int**, char**, int**, int, int, int*);
void strike_10 (int*, int*, int*, int*, int**, char**, int**, int);
void spare_10 (int*, int*, int*, int**, char**, int**, int);
void score_array(int**, int*);
void frame_array(int**, int*);
void char_array(char**, int*);
void enter_names(int*, char**);
void del (int **, int);
void del (char **, int);

int main() {

	int check = 0;
	char ch;

	do {

	int num = 0, tracker = 0, tracker2 = 0;
	int ** s;
	int ** d;
	char ** a;


	setup(&*a, &num, &*s, &*d);
	frame_cycle(num, &*s, &tracker, &*a, &*d, &tracker2);
	del (&*s, num);
	del (&*d, num);
	del (&*a, num);
	play_again (&check);
	} while (check == 0);
	return 0;
}

void del (int **a, int x) {

	for (int i = 0; i < x; i++)
		delete [] a[i];
	delete [] a;

}

void del (char **a, int x) {

	for (int i = 0; i < x; i++)
		delete [] a[i];
	delete [] a;

}

void score_array(int ** s, int *x) {
	
	s = new int* [*x];
	/*for (int i = 0; i < *x; i++)
		s[i] = new int [21];*/

}

void frame_array(int ** d, int *x) {

	d = new int* [*x];
	for (int i = 0; i < *x; i++) {
		d[i] = new int [10];
		for (int j = 0; j < 10; j++)
			d[i][j] = 0;
	}
}

void char_array(char ** a, int *x) {

	a = new char* [*x];
	for (int i = 0; i < *x; i++)
		a[i] = new char [20];
}

/***
 * Function: play_again
 * Description: Asks if user wants to play again and either breaks do while loop or continues it.
 * Parameters: int *x
 * Pre-Conditions: parameters exist
 * Post-Conditions: none
 * Return: none
 */

void play_again (int *x) {

	char a = 'o';

	while (a == 'o') {
		cout << "Play again? y/n: ";
		cin >> a;

		if (a == 'n')
			*x = 1;
		else if (a == 'y')
			*x = 0;
		else {
			cout << "Invalid!" << endl;
			a = 'o';
		}
	}
}

/***
 * Function: header
 * Description: Draws scoreboard header
 * Parameters: None
 * Pre-conditions: None
 * Post: None
 * Return: None
 */

void header () {

	cout << " | " << "Name";
	for (int t = 4; t < 19; t++)
		cout << " ";
	for (int x = 1; x < 11; x++)
		cout << "  |  " << x;
	cout << "    |  " << endl;

}

/***
 * Function: name_print
 * Description: Prints names in scoreboard
 * Parameters: char array, int i
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void name_print (char **a, int i) {
	
	int si = 0;

	cout << " | ";

	for (int k = 0; a[i][k] != '\0'; k++) {
		cout << a[i][k];
		si++;
	}
	for (si; si < 20; si++)
		cout << " ";

}

/***
 * Function: ten_print
 * Description: Handles tenth frame printing
 * Parameters: int i and j, int array s
 * Pre: parameters exist
 * Post: None
 * Return: none
 */

void ten_print (int i, int j, int **s) {

	cout << " | ";
	for (j = 18; j < 21; j++) {
		if (s[i][j] == 10)
			cout << "x" << " ";
		else if ((s[i][j] + s[i][j - 1]) == 10 && j != 18 && s[i][j - 1] != 10)
			cout << "/" << " ";
		else if (s[i][j] == 0)
			cout << "-" << " ";
		else
			cout << s[i][j] << " ";

	}

}

/***
 * Function: s_print
 * Description: Handles frame 1-9 bowl by bowl printing
 * Parameters: int array s, int i and j
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void s_print (int **s, int i, int j) {
	if (j == 18)
		ten_print (i, j, &*s);
	else if (s[i][j] == 10)
		cout << " | " << "x" << "  ";
	else if ((s[i][j] + s[i][j+1]) == 10)
		cout << " | " << s[i][j] << " " << "/";
	else if (s[i][j] == 0 && s[i][j + 1] == 0)
		cout << " | " << "-" << " " << "-";
	else if (s[i][j] == 0 && s[i][j+1] != 0)
		cout << " | " << "-" << " " << s[i][j+1];
	else if (s[i][j] != 0 && s[i][j+1] == 0)
		cout << " | " << s[i][j] << " " << "-";
	else
		cout << " | " << s[i][j] << " " << s[i][j+1];
}

/***
 * Function: total
 * Description: Prints total game scores for each player
 * Parameters: int array d, int i
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void total (int **d, int i) {

	int sum = 0;

	for (int x = 0; x < 10; x++)
		sum += d[i][x];
	
	cout << " | " << sum;
	cout << " | " << endl;

}

/***
 * Function: spacing
 * Description: Adds spaces so the bottom row is the same as the top row on scoreboard.
 * Parameters: None
 * Pre: none
 * Post: none
 * Return: none
 */

void spacing () {

	cout << " | ";
	for (int x = 0; x < 19; x++)
		cout << " ";

}

/***
 * Function: scores
 * Description: Enters frame scores
 * Parameters: int array d, int i
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void scores (int **d, int i) {

	for (int x = 0; x < 10; x++) {
		
		if (x == 9)
			cout << "  |   " << d[i][x];
		else {
			if (d[i][x] > 9)
				cout << "  | " << d[i][x];
			else 
				cout << "  |  " << d[i][x];
		}
	}

	if (d[i][9] < 10)
		cout << "    |  " << endl;
	else if (d[i][9] >= 10 && d[i][9] < 100)
		cout << "   |  " << endl;
	else 
		cout << "  |  " << endl;

}

/***
 * Function: print
 * Description: prints scoreboard
 * Parameters: int array s and d, char array a, int x
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void print (int **s, char **a, int **d, int x) {

	fixer(&*s, &*d, x);
	header();
	for (int i = 0; i < x; i++) {
		name_print (&*a, i);

		for (int j = 0; j < 19; j += 2)
			s_print (&*s, i, j);

		total(&*d, i);
		spacing ();
		scores (&*d, i);
	}
}

/***
 * Function: setup
 * Description: calls function to set up game
 * Parameters: char array a, int x, int arrays s and d
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void setup(char **a, int *x, int **s, int **d) {

	names(&*x);
	score_array(&*s, &*x);
	frame_array(&*d, &*x);
	char_array(&*a, &*x);
	score_populate(&*s, &*x);
	enter_names(&*x, &*a);

}

/***
 * Function: score_populate
 * Description: Populates int arrays with zeros
 * Parameters: int arrays s and d
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void score_populate(int **s, int *x) {

	for (int i = 0; i < *x; i++) {
		s[i] = new int [21];
		for (int j = 0; j < 21; j++) {
			s[i][j] = 0;
		}
	}
}

/***
 * Function: names
 * Description: gets number of players and names for each
 * Parameters: char array a, int x
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void names(int *x) {

	cout << "How many players?" << endl;
	cin >> *x;

}

void enter_names(int *x, char ** a) {
	cout << "Please enter name(s)" << endl;
	for (int i = 0; i < *x; i++) {
		cout << "Player " << i + 1 << ": ";
		cin.getline(a[i], '\0');

	}

}

/***
 * Function: frame_cycle
 * Description: loops for number of frames (10)
 * Parameters: int x, int arrays s and d, char array a, int t and t2
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void frame_cycle (int x, int **s, int *t, char **a, int **d, int *t2) {

	for (int i = 0; i < 10; i ++) {

		cout << "Frame " << i + 1 << endl;
		turn_cycle (x, &*s, &*t, &*a, &*d, &*t2, i);

	}

}

/***
 * Function: turn_cycle
 * Description: loops for number of players
 * Parameters: int x, int arrays a and d, char array a, int t, t2, and j
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void turn_cycle (int x, int **s, int *t, char **a, int **d, int *t2, int j) {

	for (int i = 0; i < x; i++) {
		if (j == 9) {
			cout << "Player " << i + 1 << "\'s turn!" << endl;
			*t = 18;
			*t2 = 18;
			bowl_10 (x, &*s, i, &*t, &*a, &*d, &*t2);
		}
		else {
			cout << "Player " << i + 1 << "\'s turn!" << endl;
			bowl (x, &*s, i, &*t, &*a, &*d, &*t2);
		}
	}

	*t += 2;
	*t2 += 2;
}

/***
 * Function: roll
 * Description: handles cases in bowling function
 * Paramters: int arrays s and d, char array a, ints bo, par, i, t, t2, and x
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void roll (int *bo, int *par, int i, int *t, int *t2, int **s, char **a, int **d, int x) {

	*bo = ran (*par);
	s[i][*t] = *bo;

	if (s[i][*t2] == 10)
		cout << "Strike!!" << endl;
	else if (s[i][*t2] + s[i][*t2 + 1] == 10)
		cout << "Spare!" << endl;
	else
		cout << "You bowled " << *bo << " pins!" << endl;

	print (&*s, &*a, &*d, x);
	*par = *bo;
}

/**
 * Function: bowl
 * Description: handles main bowling
 * Parameters: int arrays s and d, char array a, ints x, i, t, and t2
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void bowl (int x, int **s, int i, int *t, char **a, int **d, int *t2) {

	int bo, par = 0, check = 0;

	do {
		cout << "Press enter to bowl!" << endl;
		cin.ignore();
		if (cin.get() == '\n')
			roll (&bo, &par, i, &*t, &*t2, &*s, &*a, &*d, x);

		if (bo == 10 && *t != 1 && *t != 3 && *t != 5 && *t != 7 && *t != 9 && *t != 11 && *t != 13 && *t != 15 && *t != 17) {
			*t += 1;
			check = 2;
		}	

		*t += 1;
		check += 1;

	} while (check < 2);	
	*t -= 2;
}

/***
 * Function: strike_10
 * Description: handles strike cases on 10th frame
 * Parameters: int arrays s and d, char array a, ints par, t2, stc, check, and x
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void strike_10 (int *par, int *t2, int *stc, int *check, int **s, char **a, int **d, int x) {

	cout << "Strike!!" << endl;
	*par = 0;
	*t2 += 1;
	print (&*s, &*a, &*d, x);
	*stc += 1;
	*check += 1;
	if (*stc == 3)
		*check = 4;

}

/***
 * Function: spare_10
 * Description: handles spare cases on 10th frame
 * Parameters: int arrays s and d, char array a, ints par, t2, check, and x
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void spare_10 (int *par, int *t2, int *check, int **s, char **a, int **d, int x) {

	cout << "Spare!" << endl;
	*par = 0;
	*t2 += 2;
	print (&*s, &*a, &*d, x);
	check += 2;

}

/***
 * Function: norm_10
 * Description: handles normal cases on 10th frame
 * Parameters: int arrays s and d, char array a, int par, bo, check, x, i, and t2
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void norm_10 (int *par, int bo, int *check, int **s, char **a, int **d, int x, int i, int *t2) {

	cout << "You bowled " << bo << " pins!" << endl;
	*par = bo;
	print (&*s, &*a, &*d, x);
	*check += 1;
	if (*check == 2 && s[i][*t2] != 10 && s[i][*t2 +1] + s[i][*t2] != 10 && s[i][*t2 - 1] != 10 || *check == 3 && s[i][*t2 - 1] == 10)
		*check = 4;
}

/***
 * Function: bowl_10
 * Description: handles general bowling on 10th frame
 * Parameters: int arrays s and d, char array a, ints x, i, t, and t2
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void bowl_10 (int x, int **s, int i, int *t, char **a, int **d, int *t2) {

	int bo, par = 0, check = 0, check2 = 0, stc = 0;
	
	do {
		cout << "Press enter to bowl!" << endl;
		cin.ignore();
		if (cin.get() == '\n') {
		
			bo = ran (par);
			s[i][*t] = bo;
			if (s[i][*t2] == 10) 
				strike_10 (&par, &*t2, &stc, &check, &*s, &*a, &*d, x);
			else if (s[i][*t2] + s[i][*t2 + 1] == 10) 
				spare_10 (&par, &*t2, &check, &*s, &*a, &*d, x);
			else 
				norm_10 (&par, bo, &check, &*s, &*a, &*d, x, i, &*t2);

			*t += 1;
		
		}
	
	} while (check <= 3);

}

/***
 * Function: ran
 * Description: generates random number accounting for previous bowl in frame
 * Parameters: int z
 * Pre: parameters exist
 * Post: none
 * Return: r
 */

int ran (int z) {

	srand (time(NULL));
	int r = rand () % (11 - z);
	return r;
}

/***
 * Function: fixer
 * Description: sets array d equal to 2 values in s 
 * Parameters: int arrays s and d
 * Pre: parameters exist
 * Post: none
 * Return: none
 */

void fixer (int **s, int **d, int x) {
	
	for (int i = 0; i < x; i++) {
		
		int k = 0;

		for (int j = 0; j < 21; j += 2) {
			if (s[i][j] == 10) {
				if (j == 18 && s[i][j] == 10)
					d[i][k] = (s[i][j] + s[i][j+1] + s[i][j+2]);
				else if (s[i][j + 2] != 10 || j == 16)
					d[i][k] = (s[i][j] + s[i][j+2] + s[i][j+3]);
				else
					d[i][k] = (s[i][j] + s[i][j+2] + s[i][j+4]);
			}
			else if (s[i][j] != 10 && (s[i][j] + s[i][j+1]) == 10)
				d[i][k] = (s[i][j] + s[i][j+1] + s[i][j+2]);
			else 
				d[i][k] = ((s[i][j]) + (s[i][(j+1)]));

			k++;

		}

	}

}

