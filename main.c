#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Global Variables

int array[100]; //Array to store 100 students' marks
int numStudents; //Variable-stores the number of students
void sortarray(int array[],int size);//Function to sort the array
int inputMarks(); //Function to input students' marks
int totalAndAverage(); //Function to display total and average of marks
int highestAndLowest(); //Function to display highest and lowest mark among all students
void displayMedian();//Function to calculate and display Median
void standardDeviation();


int main()
{
    int choice; //Variable-stores user's choice of the menu

    //The loop-continuous until user choose to exit in the main programe
    while(1){
    //Display the main menu
    printf("\nMenu Structure\n\n");
    printf("1.Input Scores\n");
    printf("2.Display total and average\n");
    printf("3.Display highest and lowest scores\n");
    printf("4.Display median\n");
    printf("5.Display standard deviation\n");
    printf("6.Show grades\n");
    printf("7.Exit\n\n");

    //prompt user to input a choice
    printf("Enter your choice(1-7):");
    scanf("%d",&choice);

    //For user's choice
    switch(choice){
    case 1:
        inputMarks(); //Calling function to input marks
        break;

    case 2:
        totalAndAverage(); //Calling function to display total and average
        break;

    case 3:
        highestAndLowest(); //Calling function to display highest and lowest mark
        break;

    case 4:



    case 5:
    case 6:
    case 7:



    }
    }


    return 0;
}

int inputMarks()
{
    int i;

    //Get the number of marks to be entered
    printf("Enter number of marks that you are going to enter:");
    scanf("%d",&numStudents);

    for(i=0;i<numStudents;i++){
        int mark;

        while(1) {//keep asking until valid mark is entered
                printf("Enter mark %d:",i+1);
        scanf("%d",&mark);

        if(mark>=0 && mark<=100){ //Check whether the mark is in valid range (0-100)
            array[i]=mark;

            break; //Exit from the loop
        }else{
            printf("Invalid mark! Please enter a value between 0 and 100\n"); //send a message to the user that the mark is invalid

        }
    }


}
    return 0;
}
//Function to calculate total and average of the marks
int totalAndAverage(){
    int i;
    int total=0;
    float average=0;

    // Loop to go through all the  marks to calculate total
    for(i=0;i<numStudents;i++){
        total+=array[i];
    }
    // Calculate average using total
    average=(float)total/numStudents;


    printf("Total:%d\n",total);
    printf("Average:%.2f\n",average);

    return 0;
}
//Function to find the highest and lowest mark
int highestAndLowest(){
    int i;
    int max=array[0];//Variable to maximum number
    int min=array[0];//Variable to minimum number

    for(i=1;i<numStudents;i++){
        if(array[i]>max){
            max=array[i];
        }
        if(array[i]<min){
            min=array[i];
        }
    }
    printf("Highest mark is:%d\n",max);
    printf("Lowest mark is:%d\n",min);

    return 0;
}
//Function to sort the elements of array
void sortarray(int array[],int size){
    int i,j;
    for (i=0;i<size-1;i++){
        for (j=0;j<size -i-1;j++){
            if (array[j]>array[j+1]){
                int t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;
            }
        }
    }
}
//Function to calculate and display Median
void displayMedian(){
    if (numStudents==0){
        printf("No marks entered.\n");
        return;
    }

    int t[100];//The copy of marks to sort
    int i;
    for(i=0;i<numStudents;i++){
        t[i]=array[i];
    }
    sortarray(t,numStudents);
    float median;//Variable for the median
    //For even number of students' marks
    if(numStudents%2==0){
        median=(t[numStudents/2-1]+t[numStudents/2])/2.0;
    }
    //For odd number of students' marks
    else {
        median=t[numStudents/2];
    }
    printf ("Median:%2f\n",median);
}
//Function to calculate standard deviation
void standardDeviation(){
    if (numStudents==0){
        printf("No marks enterd.\n");
        return;
    }
    int total=0;//Variable to calculate total of marks at first
    int i;
    for (i=0;i<numStudents;i++){
        total += array[i];
    }
    float average=(float)total/numStudents;

    float sumSquared=0;//Variable to calculate sum of squared differences
    for (i=0;i<numStudents;i++){
        sumSquared += (array[i]-average)*(array[i]-average);
    }
    float variance = sumSquared/numStudents;
    float standardDev = sqrt(variance);

    printf("Standard Deviation: %.2f\n",standardDev);
}


