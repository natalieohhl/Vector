#include <iostream>
#include <fstream>
#include <string>

#include "MyVector.h"

using namespace std;

//SalesDetails struct
typedef struct {
    string compName;
    string partsDesc;
    double unitPrice;
    int qtyItem;
} SalesDetails;

//methods
void menuoption1(); /** @brief print menu option 1, @return void */
void menuoption2(); /** @brief print menu option 2, @return void */
void menuoption3(); /** @brief print menu option 3, @return void */
void menuoption4(); /** @brief print menu option 4, @return void */

void LoadFileContents(string filename, MyVector<SalesDetails> &salesData);

ostream &operator <<(ostream &os, const SalesDetails &S);
istream &operator >>(istream &input, SalesDetails &S);

//declare and initialize variables
MyVector<SalesDetails> salesData;
int menu;
bool menuok = true;
int sizeofvector =0;

int main()
{
    LoadFileContents("sales.csv", salesData);

    while(menuok){
    cout << "----------------------------------------------------------------------\n"
         << "Menu Options: \n\n\n"
         << "1: Total Sales in dollars \n\n"
         << "2: Search by Parts description \n\n"
         << "3: Search by Company Name\n\n"
         << "4: Quit \n"
         << "----------------------------------------------------------------------\n\n\n"
         << "Menu Option (Key in 1 to 4 only): ";
         cin >> menu;

        if (menu < 1 || menu > 4){
            cout << "Key in number 1 to 4 only."<< endl;
        }

        switch(menu)
        {
            case 1:
                menuoption1();
                break;

             case 2:
                cout << "Enter Part Name\n";
                menuoption2();
                break;

             case 3:
                cout << "Enter Company Name\n";
                menuoption3();
                break;

            case 4:
                cout<< "Good Bye. Program will terminate." << endl;
                menuok = false;
                break;
        }
    }



return 0;
}
void menuoption1()
{
    double sumofsales;

    for (int i =0; i < sizeofvector; i++)
    {
    sumofsales = sumofsales + ((salesData.at(i).qtyItem) * (salesData.at(i).unitPrice));
    }

    cout << "\n" << "The total sales amount is $" << sumofsales << "\n\n";

}

void menuoption2()
{
    string partname;
    cin >> partname;
    double totalsales;
    string partsdescholder;
    bool partsdescbool = false;

    for (int i =0; i < sizeofvector; i++)
    {
        partsdescholder = salesData.at(i).partsDesc;
        if (partname == partsdescholder)
        {
           totalsales = totalsales + ((salesData.at(i).qtyItem) * (salesData.at(i).unitPrice));
           partsdescbool = true;
        }
    }



    if (partsdescbool == false)
    {
        cout << "Name not found. \n";
    }
    else
    {
        cout << "\nTotal sales amount for " << partname << ": $" << totalsales << "\n" << endl;
    }

}

void menuoption3()
{
    string compname;
    cin >> compname;
    double totalsales;
    string compnameholder;
    bool compnamebool = false;


    for (int i =0; i < sizeofvector; i++)
    {
        compnameholder = salesData.at(i).compName;
        if (compname == compnameholder)
        {
           totalsales = totalsales + ((salesData.at(i).qtyItem) * (salesData.at(i).unitPrice));
           compnamebool = true;
        }


    }

    if (compnamebool == false)
    {
        cout << "Name not found. \n";
    }
    else
    {
        cout << "\nTotal sales amount for " << compname << ": $" << totalsales << "\n" << endl;
    }

}

void LoadFileContents(string filename, MyVector<SalesDetails> &salesData)
{
    string cn, pd, up, qi; //CompName,PartsDesc, UnitPrice,QtyItem holder
    int intqi;
    float floatup;
    string line;
    string tempdata;

    ifstream infile(filename.c_str());

    if (infile.rdstate()==0)
    {
        getline(infile,tempdata,'\n'); //take in the header row
        while (!infile.eof())
        {

            getline(infile, cn, ',');
            getline(infile, pd, ',');
            getline(infile, up, ',');
            getline(infile, qi);

            floatup = atof(up.c_str()); //convert unitprice to float
            intqi = atoi(qi.c_str()); //convert qtyitem to int

            SalesDetails S; //create a SalesDetails struct to store in vector

            S.compName = cn;
            S.partsDesc = pd;
            S.unitPrice = floatup;
            S.qtyItem = intqi;

            salesData.pushBack(S);
            sizeofvector = sizeofvector +1;
        }
    }

        //-----------------------------------------------------------------------------end
    else
    {
    cerr << "Problem with reading  \"" << filename << "\" ." << endl;
    }
}

ostream &operator <<(ostream &os, const SalesDetails &S)
{
    os << S.compName << "," << S.partsDesc << "," << S.unitPrice << "," << S.qtyItem;
	return os;
}

istream &operator >>(istream &input, SalesDetails &S)
{
    input >> S.compName >> S.partsDesc >> S.unitPrice>> S.qtyItem;
	return input;
}
