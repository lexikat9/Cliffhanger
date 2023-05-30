/* Lexi Katramados                                                                            
    CPSC 1071: 005                                                                              
    Runtime Terror                                                                              
    2/10/23  */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// Declare future methods
void runGame(void);
char runMenu(int, int);
string getItem();
int getPrice (string);
double guessPrice(string, double);
void displayBoard(char [26][26], int, int, int);
void playCliffHanger(char [26][26], int, int, int, int, int);
void resetGame (int&, int&, int&);

// Main method
int main () {

  // Print welcome statement          
  cout << "Welcome to the CPSC 1070 Cliff Hanger!!!";

  // Run game
  runGame();

}

// Method to run game
void runGame() {
  
  // Declare variables for prizes won, left, and the users choice
  int prizesWon = 0;
  int prizesLeft = 3;
  char userChoice = ' ';
  bool won = false;
  double priceGuess = 0;
  double guessCheck = 0;
  int rows = 26;
  int columns = 26;
  int position = 0;
  char board[26][26];
  bool reset = false;
  bool quit = false;
  
  // As long as they don't quit...
  while (!quit) {

    while (!reset) {
      // Print the menu
      userChoice = runMenu(prizesWon, prizesLeft);
      
      // If they choose quit, exit the loop
      if (userChoice == 'Q' || userChoice == 'q') {
	exit(0);
      }
      
      // If they choose 1, randomly select an item, prompt their guess, rnadomly generate price, then compare
      if (userChoice == '1') {
	if (position >= 25) {
	  cout << "You have reached the end of the board! You cannot play!" << endl;
	  reset = true;
	}
	else if (prizesLeft == 0) {
	  cout << "You have no guess left! You cannot play!" << endl;
	  reset = true;
	}
	else {
	string currItem = getItem();
	cout << "Guess the price of the " << currItem << ": $";
	cin >> priceGuess;
	guessCheck = round(priceGuess);
	while (priceGuess < 0) {
	  cout << "You cannot guess a negative price! Try again." << endl;
	  cout << "Guess the price of the " << currItem << ": $";
	  cin >> priceGuess;
	}
	while (priceGuess -  guessCheck != 0) {
	  cout << "You did not enter an integer! Try again." << endl;
	  cout << "Guess the price of the " << currItem << ": $";
          cin >> priceGuess;
	  guessCheck = round(priceGuess);
	}
	int difference = guessPrice(currItem, priceGuess);
	position += difference;
	if (position >= 25){
	  cout << "You fell over the edge and lost the prize! Better luck next time!" << endl;
	  displayBoard(board, rows, columns, position);
	  prizesLeft--;
	  reset = true;
	}
	else {
	  cout << "You won the prize! Congratulations!" << endl << endl;
	  playCliffHanger(board, rows, columns, position, prizesWon, prizesLeft);
	  prizesWon++;
	  prizesLeft--;
	}
	}
      }

      // and they choose 2...
      if (userChoice == '2') {
	displayBoard(board, rows, columns, position);
      }

      // and they choose 3...
      if (userChoice == '3') {
	resetGame(position, prizesWon, prizesLeft);
	cout << "Resetting the game..." << endl;
      }
     
    } // end of reset loop
    
    if (position >= 25){
      userChoice = ' ';
      reset = false;
    }

    if (prizesLeft == 0) {
      reset = false;
    }
    
  } // end of quit loop
  
} // end of runGame method


// Method to print menu
  char runMenu(int prizesWon, int prizesLeft) {
      char userChoice;
      cout << endl;
      cout << "---- CPSC 1070 Cliff Hanger Menu ----" << endl << endl;
      cout << "You have won " << prizesWon << " Prizes So Far!" << endl;
      cout << "Prizes Left: " << prizesLeft << "!" << endl << endl;
      cout << "[1] guess the next prize in Cliff Hanger" << endl;
      cout << "[2] to print out the current board" << endl;
      cout << "[3] restart the game" << endl;
      cout << "[Q] to quit" << endl << endl;
      cout << "Your choice?: ";
      cin >> userChoice;

      while (userChoice != '1' && userChoice != '2' && userChoice != '3' && userChoice != 'Q' && userChoice != 'q') {
	cout << "You did not enter a valid response!" << endl;
	cout << "Enter another choice?: ";
	cin >> userChoice;
      }

      return userChoice;
  }

// Method to play the game
  void playCliffHanger(char board[26][26], int rows, int columns, int position, int prizesWon, int prizesLeft) {
    displayBoard(board, rows, columns, position);
  }

// Method to randomly generate an item (make a random number generator, use that to pick item randomly)
  string getItem() {
      int randNum = 0;
      string randItem = "";
      unsigned seed;
      seed = time(0);
      srand(seed);
      randNum = rand() % 10 + 1;

      if (randNum == 1) {
	randItem = "Coffee Maker";
      }
      else if (randNum == 2) {
	randItem = "Conair Hair Dryer";
      }
      else if (randNum == 3) {
	randItem = "1 Quart of White Paint";
      }
      else if (randNum == 4) {
	randItem = "Red T-Shirt";
      }
      else if (randNum == 5) {
	randItem = "Toaster";
      }
      else if (randNum == 6) {
	randItem = "One Touch Can Opener";
      }
      else if (randNum == 7) {
	randItem = "Regular Cooler";
      }
      else if (randNum == 8) {
	randItem = "Blender";
      }
      else if (randNum == 9) {
	randItem = "Balloon Inflator";
      }
      else {
	randItem = "Hand Crack Ice Crusher";
      }

      return randItem;  

    } // end of getItem method

// Method to randomly generate price of a prize
  int getPrice (string currItem) {

    int price = 0;
   
    if (currItem == "Coffee Maker") {
      price = rand() % 71 + 30;
    }
    else if (currItem == "Conair Hair Dryer") {
      price = rand() % 16 + 20;
    }
    else if (currItem == "1 Quart of White Paint") {
      price = rand() % 19 + 12;
    }
    else if (currItem == "Red T-Shirt") {
      price = rand() % 9 + 8;
    }
    else if (currItem == "Toaster") {
      price = rand() % 11 + 20;
    }
    else if (currItem == "One Touch Can Opener") {
      price = rand() % 11 + 20;
    }
    else if (currItem == "Regular Cooler") {
      price = rand() % 21 + 20;
    }
    else if (currItem == "Blender") {
      price = rand() % 31 + 50;
    }
    else if (currItem == "Balloon Inflator") {
      price = rand() % 7 + 17;
    }
    else {
      price = rand() % 9 + 27;
    }

    return price;
  }

// Method to return difference in price
double guessPrice(string currItem, double priceGuess) {
  int actualPrice = getPrice(currItem);
  int difference = abs(priceGuess-actualPrice);
  cout << "\tActual Retail Price is $" << actualPrice << endl;
  cout << "\twhich is a differences of $" << difference << endl;
  return difference;
}

// Method to display board
void displayBoard(char board[26][26], int rows, int columns, int position) {

  char userSpot = 'C';
  int tempVal = 1;

  // Add blank spaces in board
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      board[i][j] = ' ';
    }
  }

  // Add hashtags to board                                                                                                              
  for (int i = rows; i > 0; i--) {
    for (int j = tempVal; j < columns; j++) {
      board[i][j] = '#';
    }
    ++tempVal;
  }

  // Add numbers to the board
  int j = 0;
  for (int i = rows; i > 0; i--) {
    switch(i) {
      case 25:
  	board[i][1] = '1';
	break;
      case 24:
    	board[i][2] = '2';
	break;
      case 23:
    	board[i][3] = '3';
	break;
      case 22:
    	board[i][4] = '4';
	break;
      case 21:
    	board[i][5] = '5';
	break;
      case 20:
    	board[i][6] = '6';
	break;
      case 19:
    	board[i][7] = '7';
	break;
      case 18:
	board[i][8] = '8';
	break;
      case 17:
	board[i][9] = '9';
	break;
      case 16:
	board[i][10] = '0';
	break;
      case 15:
	board[i][11] = '1';
	break;
      case 14:
	board[i][12] = '2';
	break;
      case 13:
	board[i][13] = '3';
	break;
      case 12:
	board[i][14] = '4';
	break;
      case 11:
	board[i][15] = '5';
	break;
      case 10:
	board[i][16] = '6';
	break;
      case 9:
	board[i][17] = '7';
	break;
      case 8:
	board[i][18] = '8';
	break;
      case 7:
	board[i][19] = '9';
	break;
      case 6:
	board[i][20] = '0';
	break;
      case 5:
	board[i][21] = '1';
	break;
      case 4:
	board[i][22] = '2';
	break;
      case 3:
	board[i][23] = '3';
	break;
      case 2:
	board[i][24] = '4';
	break;
      case 1:
	board[i][25] = '5';
	break;
    }
    j++;
  }

  // Add users position to board
  if (position < 25) {
    board[25-position][position] = userSpot;
  }

  //  Print board all together                                                                                                           
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

// Method to reset the game
  void resetGame (int& position, int& prizesWon, int& prizesLeft) {
    prizesWon = 0;
    prizesLeft = 3;
    position = 0;
  }                                                              
