#include <iostream>
#include <ctime>
using namespace std;

//RPS means ROCK,PAPER,SCISSOR
class RPS
{
private:

	enum Choice
	{
		ROCK,PAPER,SCISSOR
	};

	// values array 
	string values[3];
	
	// playerChoice is used to collect the input of playerChoice which is atmost 2
    int playerChoice;
	// computerValue is used to generate the random value between 0 and 2
    int computerValue;
	
	// valueInRange is used to check whether the user input for playerChoice is in between 0 and 2
	bool valueInRange;
	
	// playerwin is used to check if player win in the particular round or not
    bool playerwin;
	// computerwin is used to check if computer win in the particular round or not
    bool computerwin;
	
	// playerscore is used to count the player score
	// if player win adds 2 points
	// if draw 1 point is added
    int playerScore;
	// computerwin is used to count the computer score
	// if computer win adds 2 points
	// if draw 1 point is added
    int computerScore;
	// draw is used to verify it is draw or not
    bool draw;
	
	// playTime is used to set the no.of rounds
    int playTime;
	
public:
	// constructor
	RPS()
	{
		values[0] = "ROCK";
		values[1] = "PAPER";
		values[2] = "SCISSOR";
		computerwin = 0;
		playerwin = 0;
		playerScore = 0;
		computerScore = 0;
		draw = 0;
		playTime = 3;
	}
	void play()
	{
		cout << "\t\t (0-> rock), (1-> paper), (2-> scissors)\n";
		cout<<"======================================\n";
		//get player's choice
		cout << "play: ";

		while(playTime){
			// Taking user input until he enters a valid value
			do {
				cout<<"\nInput new value in range (0,3) **exclude 3: ";
				cin >> playerChoice;
				valueInRange= ((playerChoice<0) || (playerChoice>2))? 0 : 1;
				if(!valueInRange){
					cout<<"****Repeat! previous values wasn't in range****";
				}
			}while(!valueInRange);
			
			
			cout<<"----------------------------------\n";

			// generate random value between (0 , 3)
			// to get computer's choice
			srand(time(NULL));
			computerValue = rand()%3;
			
			// if playerChoice and computerValue are equal make draw to 1
			if(playerChoice == computerValue)
			{
				draw = 1;
			}
			else
			{
				switch(playerChoice)
				{
					case Choice::ROCK : 
										if(computerValue == Choice::SCISSOR)
										{
											playerwin = 1;
										}
										else if(computerValue == Choice::PAPER)
										{
											computerwin = 1;
										}
										break;
					case Choice::PAPER :
										if(computerValue == Choice::ROCK)
										{
											playerwin = 1;
										}
										else if(computerValue == Choice::SCISSOR)
										{
											computerwin = 1;
										}
										break;
					case Choice::SCISSOR:
										if(computerValue == Choice::PAPER)
										{
											playerwin = 1;
										}
										else if(computerValue == Choice::ROCK)
										{
											computerwin = 1;
										}
										break;
				}
			}
			
			
			//check and display result
			cout<< "Result: ";
			if(draw){
				cout << "computer's choice is " << values[computerValue] << endl;
				cout << "player's choice is " << values[playerChoice] << endl;
				cout<< "It was a draw\n";
				computerScore += 1;
				playerScore += 1;
			}
			else if(playerwin){
				cout << "computer's choice is " << values[computerValue] << endl;
				cout << "player's choice is " << values[playerChoice] << endl;
				cout <<"You Win\n";
				playerScore += 2;
			}
			else if(computerwin){
				cout << "computer's choice is " << values[computerValue] << endl;
				cout << "player's choice is " << values[playerChoice] << endl;
				cout<<"Computer Won\n";  
				computerScore += 2;     
			}
			cout<<"        --------\n";
			playTime--;
			playerwin = 0;
			computerwin = 0;
			draw = 0;
		}
		this->checkWin();
	}
private:
	void checkWin()
	{
		//view the played choices
		cout<<"======================================\n";
		cout <<"Your score: " << playerScore <<endl;
		cout <<"Computer score: " << computerScore << endl;
		cout<<"---------------------------------------\n";
		cout <<"Final Verdict\n";
		cout<<"======================================\n";
		if (playerScore > computerScore){
			cout <<"II\t Congrats! You won \tII "<<endl;
		}
		else if(playerScore < computerScore){
			cout<<"II\t Ooops! Computer won \tII"<<endl;
		}
		else {
			cout<<"II\t It was a draw \tII"<<endl;
		}
		cout<<"======================================\n";
	}
};

int main()
{
		RPS *rps = new RPS();
		rps->play();
}