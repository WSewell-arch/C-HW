#include<iostream>
#include<Vector>

using namespace std;

/**
 * @file Exercise1_wsewell.cpp
 * @author Winston Sewell
 * @date 2025-01-15
 * @brief This program validates UPC-A barcodes performing the UPC-A check digit algorithm.
 */


int main()
{   //test upc number: 05150024163 9" 
    string user_input;
    vector<int>ODD_UPC;
    vector<int>EVN_UPC;
    vector<string>ODD_STR;
    vector<string>EVN_STR; 

    int check_digit;
    int first_digit;
    int odd_nums;
    int even_nums;

    int odd_x = 0;
    int odd_sum;

    int even_x = 0;
    int even_sum;

    int MOD_num;


    cout << "Do you have a number to test? (y or n) " << endl;
    cin >> user_input;
    while (user_input != "n")
    {
        cout << "Enter in the first number of the UPC: " << endl;
        cin >> first_digit;

        cout << "Enter in the last number of the UPC: " << endl;
        cin >> check_digit;

        cout << "Enter your Manufacturer Number (First set of five digits)" << endl;
        for (int i = 0; i < 5; i++)
        {
            cin >> odd_nums;
            ODD_UPC.push_back(odd_nums);
            cout << ODD_UPC[i] << endl;
        }

        cout << "Enter your Product Number (The second set of five digits)" << endl;
        for (int i = 0; i < 5; i++)
        {
            cin >> even_nums;
            EVN_UPC.push_back(even_nums);
            cout << EVN_UPC[i] << endl;
        }
        
        
        
       for (int i = 0; i < 5; i++)
        {
            odd_x = odd_x + ODD_UPC[i];
            odd_sum = (odd_x + first_digit) * 3;            
        }

        for (int i = 0; i < 5; i++)
        {
            even_x = even_x + EVN_UPC[i];
            even_sum = even_x + odd_sum;            
        }

        MOD_num = even_sum % 10;
        
        if (MOD_num == 0)
        {
            cout << "Sorry Your UPC Isn't Valid" << endl;
        }

        else
        {
            cout <<"Your UPC Is Valid" << endl;
        }

        cout << "Do you have a number to test? (y or n) " << endl;
        cin >> user_input;
        
    }


    
    
}
