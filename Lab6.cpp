#include<iostream>
#include<Vector>
#include<algorithm>
using namespace std;

/**
 * @file Lab6_wsewell.cpp
 * @author Winston Sewell
 * @date 2025-02-19
 * @brief Compare static arrays and vectors for processing student scores.
 */

void arraysolution();
void vectorsolution();

int main()
{

    arraysolution();
    vectorsolution();
    return 0;
}

void arraysolution()
{
    /**
 * @brief Calculates the average of the scores.
 * @return The average score as a float.
 */

 int scores[10];
 int user_score;
 int max_score;
 int lowest_score;
 int avg_num = 0;

 cout << "Please Enter some test scores" << endl;

 for (int i = 0; i < 10; i++)
 {
    cin >> user_score;
    if ((user_score >= 0) && (user_score <= 100))
    {
        scores[i] = user_score;
        //cout << "You Entered: " << scores[i] << endl;
    }
    else
    {
        cout << "Sorry, that's not an valid score!";
    }
 }

 for (int i = 0; i < 10; i++)
 {
    avg_num += scores[i];
    if (i == 9)
    {
        cout << "The Average Score is: " << (avg_num / 10) << endl;
    }  
 }

 for (int i = 1; i < 10; i++)
 {
    //max_score = scores[0];
    if (scores[i] > max_score)
    {
         max_score = scores[i];
         //cout << "Thet Highest Score is : " << max_score << endl;
    }
 }
    cout << "The Highest Score is : " << max_score << endl;


 for (int i = 1; i < 10; i++)
 {
    lowest_score = scores[0];
    if (lowest_score > scores[i])
    {
        lowest_score = scores[i];
        //cout << "The lowest score is : " << lowest_score << endl;
    } 
 }
    cout << "The lowest score is : " << lowest_score << endl;

}

void vectorsolution()
{
    vector<int>ScoreVector;
    int user_num;
    int avg_num;
    int max_score;
    int low_score;

    cout << "Please Enter Test Scores: " << endl;
    cout << "Enter -1 To Stop" << endl;

    while (user_num != -1)
    {
        cin >> user_num;
        if ((user_num > -1) && (user_num <= 100))
        {
            ScoreVector.push_back(user_num);
        }
        else
        {
            cout << "Sorry! That is not a Valid entry" << endl;
        }
    }

    for (int i = 0; i < ScoreVector.size(); i++)
    {
        avg_num += ScoreVector[i];
        if (i == ScoreVector.size() - 1)
        {
            cout << "The Average Score is: " << (avg_num / ScoreVector.size()) << endl;
        }
    }

    for (int i = 0; i < ScoreVector.size(); i++)
    {
        if (ScoreVector[i] > max_score)
        {
            max_score = ScoreVector[i];
        }    
    }

    for (int i = 0; i < ScoreVector.size() - 1; i++)
    {
        low_score = ScoreVector[0];
        if (low_score < ScoreVector[i])
        {
            low_score = ScoreVector[i];
        }
    }
    
    std:: sort(ScoreVector.begin(), ScoreVector.end());

    for (int i = 0; i < ScoreVector.size(); i++)
    {
        cout << ScoreVector[i] << " " << endl;
    }
    

    
    cout << "This Vector Size in sorted order is : " << endl;
    cout << "The Highest Score is: " << max_score << endl;
    cout << "The Lowest Score is: " << low_score << endl;

    
}
