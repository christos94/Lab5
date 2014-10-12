/*Christos Hadjikyriacou
10/8/14
Lab 5
Program 2
*/

#include <stdio.h>	//printf, scanf
#include <stdlib.h>	//rand

//Function prototypes
void playGame();
char getPlayerMove();
int getPlayerChoice();
char quit();
int rollDice();

//Main function
int main (void){
	srand(time(NULL));
	playGame();

	return 0;
}

//Calls all other functions in the order that creates a coherent game
void playGame(){
	char playerMove;
	int dice1;
	int dice2;
	int sum;
	int playerCount;
	int choice;
	while(1)
	{
		printf("Welcome to Dice Blackjack!\n");
		printf("I am now rolling two dice\n");
		dice1 = rollDice();
		dice2 = rollDice();
		printf("You got a %d and a %d\n",dice1,dice2);
		sum = dice1 + dice2;
		printf("Total sum is %d\n",sum);
		playerCount = (sum + sum);
		printf("Your total player count is %d\n",playerCount);

		while(playerMove != 'S'){

			playerMove = getPlayerMove();

			if(playerMove == 'H')
			{
				printf("Rolling two more dice\n");
				dice1 = rollDice();
				dice2 = rollDice();
				printf("You have rolled a %d from the first dice and a %d on the second dice\n",dice1,dice2);
				choice = getPlayerChoice();

				if(playerCount > 21)
				{
				printf("You have busted!\n");
				break;
				}	

				else
				printf("You have a %d player count\n", playerCount);
				}
			}
		

			//Call the rest of the functions to get the game working
			//Game logic
			//Declare the winner of this round
			printf("Would you like to play again? Y/N:\n");	//If the player enters  			
			if(playerMove == 'N')// N, the game ends.
				exit(0);
		
	}
}


//Retrieves and returns the player's entry. Checks to ensure proper entry.
char getPlayerMove(){
	char playerInput = 'p';
	/*Write code to return the player's entry, should be safe and not crash program if an 	 * incorrect entry is found. */
	while(playerInput != 'H' && playerInput !='S')
{
		printf("Do you want to hit or stand? Press H to hit, S to Stand\n");

	scanf("%c",&playerInput);
	getchar();
}	
	return playerInput;
}


int getPlayerChoice(){
	int playerInput = 0;
	/*Write code to return the player's entry, should be safe and not crash program if an 	 * incorrect entry is found. */
	while(playerInput != 1 && playerInput != 2 && playerInput != 3)
{
		printf("Press 1 for Dice 1, Press 2 for Dice 2, or Press 3 for both dice\n"); 

	scanf("%d",&playerInput);
	getchar();
}	
	return playerInput;

}


int rollDice()
{
return rand() % 6 + 1;
}

