/*
Create a grade calculator for that says whether the final grade for a course is A, B, C, D or F once you enter all grades. On the command line, you should enter the number of HWs, quizzes and exams along with the weight of each in the order: number of HWs weight of HWs number of exams weight of exams number of quizzes weight of quizzes
For example:
C computer$ ./a.out 3 15 3 70 5 15
number of HWs-3
weight of HWs-15%
number of exams-3 weight of exams -70% number of quizzes-5 weight of quizzes-15%
If the user tries to run the program without all of the information given above, the program should exit:
If the user does not enter the weights correctly (meaning the weights cannot accurately be used in a grading scheme), the program should exit:
Here, the weights are 15%, 70%, 50%, which is greater than 100%
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

float calculate_grades(int num_grades,char type[])
{   
    int i;
    float total_num[num_grades],ret_avg,overall=0.0;
    for(i=0;i<num_grades;i++)
    {
        printf("Enter %s grade %d: ",type,(i+1));
        scanf("%f",&total_num[i]);
        while(total_num[i]<0.00||total_num[i]>100.00)
        {
            printf("--Not a valid grade.  Re-enter: ");
            scanf("%f",&total_num[i]);
        }
        overall+=total_num[i];
    }
    printf("\n");
    ret_avg=(overall/(float)num_grades);
    return ret_avg;
}
void output_letter(float grades[][2])
{
    float total=0.0, avg;
    char letter_grade;
    int i;
    for(i=0;i<3;i++)
    {
        total+=(grades[i][0]*grades[i][1]);
    }
    avg=(total*0.01);
    if(avg<=100.00&&avg>=90.00)
    {
        letter_grade='A';
    }
    else if(avg<90.00&&avg>=80.00)
    {
        letter_grade='B';
    }
    else if(avg<80.00&&avg>=70.00)
    {
        letter_grade='C';
    }
    else if(avg<70.00&&avg>=60.00)
    {
        letter_grade='D';
    }
    else
    {
        letter_grade='F';
    }
    printf("Final numeric grade: %.2f\nYou have a %c!\n",avg,letter_grade);
}
int main (int argc, char **argv)
{
    int first,second,third,i;
    int v_int[6];
    float grades[3][2];
    char type[3][20]={"HW","exam","quiz"};

    if(argc!=7)
    {
    printf("Missing info. Exiting...\n");
    }
    else
    {
        for(i=0;i<(argc-1);i++)
        {
            v_int[i]=atoi(argv[i+1]);
        }
        if(v_int[1]+v_int[3]+v_int[5]!=100)
        {
            printf("Weights not accurate...Exiting\n");
        }
        else
        {
            printf("\n");
            for(i=0;i<3;i++)
            {
                grades[i][0]=(float) v_int[((i*2)+1)];
            }
            for(i=0;i<3;i++)
            {
                grades[i][1]=calculate_grades(v_int[(i*2)],type[i]);
            }
            output_letter(grades);
        }
    }
}