#include <stdio.h>

void seatArrangment(int);

void userInput() {
    int t; //test case
	int n; //seat number
	int i; //for loop variable 
    printf("Number of testcases :");
    scanf("%d", &t); //input for number of test cases
    if(t<=1 || t>=105){ //to check constraint given in problem (for test case)
    	printf("Invalid input");	
	}
	else{
		for (i=0; i<t; i++){
        	printf("Enter the seat number: ");
        	scanf("%d", &n); //input for seat number
        		if(n<=1 || n>=108){ //to check constraint given in problem (for seat number)
        			printf("Invalid input");	
				}
				else{
					seatArrangment(n); //to check seat arrangment	
				}
    	}	
	}
}

void seatArrangment(int n) {
    int seat = n % 12; // the cycle is repeating after every 12 seats
    switch (seat) {
        case 1:
            printf("%d %s\n", (n + 11), "WS");  //difference between seat number 1 and 12 
            break;
        case 2:
            printf("%d %s\n", (n + 9), "MS"); //difference between seat number 2 and 11
            break;
        case 3:
            printf("%d %s\n", (n + 7), "AS"); //difference between seat number 3 and 10
            break;
        case 4:
            printf("%d %s\n", (n + 5), "AS"); //difference between seat number 4 and 9
            break;
        case 5:
            printf("%d %s\n", (n + 3), "MS"); //difference between seat number 5 and 8 
            break;
        case 6:
            printf("%d %s\n", (n + 1), "WS"); //difference between seat number 6 and 7
            break;
            
    	//from cases 7 to 12, we reverse the counting difference technique. i.e. if the user enters 7, the opposite seat should be 6
            
        case 7:
            printf("%d %s\n", (n - 1), "WS"); //difference between seat number 7 and 6
            break;
        case 8:
            printf("%d %s\n", (n - 3), "MS"); //difference between seat number 8 and 5 
            break;
        case 9:
            printf("%d %s\n", (n - 5), "AS"); //difference between seat number 9 and 4
            break; 
        case 10:
            printf("%d %s\n", (n - 7), "AS"); //difference between seat number 10 and 3
            break;
        case 11:
            printf("%d %s\n", (n - 9), "MS"); //difference between seat number 11 and 2
            break;
        default:
            printf("%d %s\n", (n - 11), "WS"); //difference between seat number 12 and 1
            break;
    }
}

int main() {
    userInput(); //the program starts with user input
    return 0;
}
