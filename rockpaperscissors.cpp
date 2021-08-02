#include <iostream>
#include <ctime>
using namespace std;

int main (void){
    // declaring and initializing variables
	// ---------------------------------
	// value for rock is 0
	// value for paper is 1
	// value for scissors is 2
    int rock = 0;
    int paper = 1;
    int scissors = 2;
	
	// playerChoice is used to collect the input of playerChoice which is atmost 2
    int playerChoice;
	// computerValue is used to generate the random value between 0 and 2
    int computerValue;
	
	// valueInRange is used to check whether the user input for playerChoice is in between 0 and 2
	bool valueInRange;
	
	// playerwin is used to check if player win in the particular round or not
    bool playerwin = 0;
	// computerwin is used to check if computer win in the particular round or not
    bool computerwin = 0;
	
	// playerscore is used to count the player score
	// if player win adds 2 points
	// if draw 1 point is added
    int playerScore = 0;
	// computerwin is used to count the computer score
	// if computer win adds 2 points
	// if draw 1 point is added
    int computerScore = 0;
	// draw is used to verify it is draw or not
    bool draw = 0;
	
	// playTime is used to set the no.of rounds
    int playTime = 3;
    cout << "\t\t (0-> rock), (1-> paper), (2-> scissors)\n";
    cout<<"======================================\n";
    //get player's choice
    cout << "play: ";

    while(playTime){
        //validate player input
        do {
            cout<<"\nInput new value in range (0,3): ";
            cin >> playerChoice;
            valueInRange= ((playerChoice<0) || (playerChoice>2))? 0 : 1;
            if(!valueInRange){
                cout<<"****Repeat! previous values wasn't in range****";
            }
        }while(!valueInRange);
        cout<<"----------------------------------\n";

        //generate random value between (0 , 3)
        srand(time(NULL));
        computerValue = rand()%3;
        
        //check who won?? and display result
        //rock vs scissors
        if((playerChoice==0) && (computerValue==2)){
            playerwin = 1;
        }
        if((playerChoice==2) && (computerValue==0)){
            computerwin = 1;
        }

        //paper vs scissors
        if((playerChoice==1) && (computerValue==2)){
            computerwin = 1;
        }
        if((playerChoice==2) && (computerValue==1)){
            playerwin = 1;
        }

        //rock vs paper
        if((playerChoice==0) && (computerValue==1)){
            computerwin = 1;
        }
        if((playerChoice==1) && (computerValue==0)){
            playerwin = 1;
        }

        //draw condition
        if(playerChoice == computerValue){
            draw = 1;        
        }

        //check and display result
        cout<< "Result: ";
        if(playerwin){
            cout <<"You Win\n";
            playerScore += 2;
        }
        else if(computerwin){
            cout<<"Computer Won\n";  
            computerScore += 2;     
        }
        else if(draw){
            cout<< "It was a draw\n";
            computerScore += 1;
            playerScore += 1;
        }
        cout<<"        --------\n";
        playTime--;
		
		// initializing player win and computerwin and draw to 0
		computerwin = 0;
		playerwin = 0;
		draw = 0;
		
    }
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