#include <iostream>

using namespace std;

int main (void){
    //variables
    int rock = 0;
    int paper = 1;
    int scissors = 2;
    int playerChoice;
    bool valueInRange;
    int computerValue;
    bool playerwin = 0;
    bool computerwin = 0;
    int playerScore = 0;
    int computerScore = 0;
    bool draw = 0;
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
        srand(time(0));
        computerValue = rand()%3;
        
        /*check who won?? and display result*/
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
    return 0;
}