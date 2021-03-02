/************************************************************************
* Name: Exercise 6.57 & 6.58 Computer Assisted Instruction
* File: hexCode.cpp
* Author: Milo Osterman
* Date: 2/16/2021
 *************************************************************************/

#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

unsigned int generateProblem();
void generateCorrectResponse();
void generateIncorrectResponse();
const int SENTINEL_VALUE = -1;

//Main method, uses enum to keep track of status.
int main(int argc, const char * argv[]) {
    enum class Status {CONTINUE, CORRECT, END};
    
    Status gameStatus = Status::CONTINUE;
    int userGuess = 0;
    int sum;
    
    while (gameStatus != Status::END){
        srand(static_cast<unsigned int>(time(0)));
        sum = generateProblem();
        cin >> userGuess;
        
        if (userGuess == sum){
            generateCorrectResponse();
            gameStatus = Status::CORRECT;
        }
        else if (userGuess == SENTINEL_VALUE){
            gameStatus = Status::END;
        }
        else {gameStatus = Status::CONTINUE;}
        
        while (Status::CONTINUE == gameStatus){
            generateIncorrectResponse();
            cin >> userGuess;
            
            if (userGuess == sum){
                generateCorrectResponse();
                gameStatus = Status::CORRECT;
            }
            
        }
        
        if (Status::END == gameStatus){
            cout << "Great job today!" << endl << "See you next time." << endl;
            return 0;
        }
    }
}

//Generates math problem for user by generating two numbers and returning the sum to be checked in main
unsigned int generateProblem(){
    int number1{1 + rand() % 10};
    int number2{1 + rand() % 10};
    int sum = number1 * number2;
    
    cout << "What is " << number1 << " * " << number2 << "?" << endl;
    cout << "Enter '-1' to quit." << endl;

    return sum;
    
}

//When called, generates a random correct feedback using rand()
void generateCorrectResponse(){
    int seed{1 + rand() % 4};
    
    switch (seed) {
        case 1:
            cout << "Very good!" << endl;
            break;
        case 2:
            cout << "Excellent!" << endl;
            break;
            
        case 3:
            cout << "Nice work!" << endl;
            break;
            
        case 4:
            cout << "Keep up the good work!" << endl;
            break;
            
        default:
            break;
    }
}

//When called, generates random incorrect feedback using rand()
void generateIncorrectResponse(){
    int seed{1 + rand() % 4};
    
    switch (seed) {
        case 1:
            cout << "No. Please try again." << endl;
            break;
        case 2:
            cout << "Wrong. Try once more." << endl;
            break;
            
        case 3:
            cout << "Don't give up!" << endl;
            break;
            
        case 4:
            cout << "No. Keep trying." << endl;
            break;
            
        default:
            break;
    }
}
