#include <stdio.h>

void takeInput(); //to take input of number of users,number of coins & and coin values

void startGame(int,int,int*,int*); //to caluculate the coin of each user

void findWinner(int, int*); //to compare user coin values

void displayWinner(int,int); //to display the winner detail

void takeInput() {
    int playerCount, coinCount, i;
    
    printf("Enter number of players:"); //no. of user
    scanf("%d", &playerCount);
    
    int playerScoreArray[playerCount]; //user score array
    
    for(i = 0; i<playerCount; i++)
        playerScoreArray[i] = 0;
    
    printf("Enter number of coins:"); //no. of coins
    scanf("%d", &coinCount);
    
    if (coinCount % playerCount != 0) {
        printf("Invalid Input\n"); //to terminate if invalid input
    }else {
        int coinArray[coinCount];
        printf("Enter coins:");  //coin value
        for(i = 0; i < coinCount; i++)
            scanf("%d", &coinArray[i]);
        startGame(playerCount,coinCount, playerScoreArray, coinArray); 
    }
}

void startGame(int playerCount, int coinCount, int* playerScoreArray, int* coinArray) {
    int i = 0, j = coinCount - 1, playerIndex = 0;
    
    while (i<=j) { 
        int index = playerIndex % playerCount; //score of different user (for eg if 2 users then 1 or 2)
        if (coinArray[i] > coinArray[j]) {  //check which coin value is high 
            playerScoreArray[index] += coinArray[i]; //assign higher value to user
            i++;
        } else { //if the last coin value is higher
            playerScoreArray[index] += coinArray[j];
            j--;
        }
        playerIndex += 1;
    }
    
    findWinner(playerCount,playerScoreArray);
}

void findWinner(int playerCount, int* playerScoreArray) {
    int max = playerScoreArray[0], index = 0,i; 
    
    for(i = 0; i < playerCount; i++) {
        if (max < playerScoreArray[i]) { //max value
            max = playerScoreArray[i]; //if the other is max, substitue max value
            index = i;
        }
    }
    
    displayWinner(max, index+1);
}

void displayWinner(int highestScore, int index) {
    printf("Player%d with %d is the winner", index, highestScore); //winner displayed
}

int main() {
    takeInput(); //program starts here by taking input
    return 0;
}
