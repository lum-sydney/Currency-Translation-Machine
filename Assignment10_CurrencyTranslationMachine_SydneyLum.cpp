/*==========================================================

 Title:     Assignment 10 (Final) - C++ Currency Translation Machine
 Course:  	CIS 2252
 Author:  	<Sydney Lum>
 Date:    	<11/16/2023>
 Description: This program takes an amount needed in exchanged currency and
              calculates the total in USD to complete a transaction.

 ==========================================================
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class ctm
{
    public:
        string ctype;  //currency type
        float amt;  //amount in currency
        float cfact;  //conversion factor
        float amtInUsd;  //amount in USD
        float tax;  //tax
        float tAmt;  //total amount in USD
        
        ctm()
        {
            ctype = "";
            amt = 0;
        }
        
        void intro()
        {
            while (1)
            {
                int t;
                cin >> t;
                
                if (t == 1)
                {
                    ctype = "Yuan";
                    cfact = 6.77;
                    break;
                }
                
                else if (t == 2)
                {
                    ctype = "Euro";
                    cfact = 0.98;
                    break;
                }
                    
                else if (t == 3)
                {
                ctype = "Pounds";
                cfact = 0.83;
                break;
                }
                    
                cout << "Invalid entry, Please enter a number between 1-3:\n";
            }
        }
};

class amount : public ctm
{
public:
    void calculations()
    {
        cin >> amt;
        amtInUsd = amt / cfact;
        tax = amtInUsd * 0.05;
        tAmt = amtInUsd + tax;
    }
};

class rc : public amount
{
public:
    void rctype()
    {
        ofstream MyFile("filename.txt");
            
    MyFile << fixed << setprecision(2);
    MyFile << amt << " "<< ctype << endl;  //amount in currency & currency type
    MyFile << amtInUsd << " dollars"<< endl;  //amount in USD
    MyFile << tax << " dollars" << endl;  //tax
    MyFile << tAmt << " dollars" << endl;  //total amount in USD
            
    MyFile.close();
    
    cout << fixed << setprecision(2);
    cout << amt << " " << ctype << endl;
    cout << amtInUsd << " dollars" << endl;
    cout << tax << " dollars" << endl;
    cout << tAmt << " dollars" << endl;
    
            
    }
};


int main()
{
    //No need to modify main as everything should be handled in the classes
    rc obj; 
    obj.ctm::intro();
    obj.amount::calculations();
    obj.rctype();
    
    return 0;
}

