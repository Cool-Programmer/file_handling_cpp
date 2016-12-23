#include <iostream>
#include <fstream>

using namespace std;

/*
 * Prototypes
 */
int getWhatTheyWant();
void displayItems(int choice);


/*
 * function main
 * return 0
 */
int main()
{
    int whatTheyWant;

    whatTheyWant = getWhatTheyWant();

    while (whatTheyWant != 4){ // until 4 is hit, getWhatTheyWant()
        switch (whatTheyWant){ // cases
            case 1:
                displayItems(1);
                break;
            case 2:
                displayItems(2);
                break;
            case 3:
                displayItems(3);
                break;
            default:
                cout << "Please select the right choice" << endl;
        }

        whatTheyWant = getWhatTheyWant();
    }
}


/*
 * function getWhatTheyWant
 * get user's choice as input (int)
 * @return int choice
 */
int getWhatTheyWant()
{
    int choice;
    cout << "\nPress 1 for plain items " << endl;
    cout << "Press 2 for helpful items " << endl;
    cout << "Press 3 for harmful items " << endl;
    cout << "Press 4 for exiting \n " << endl;

    cin >> choice;
    return choice;
}


/*
 * display items function
 * display per user's choice
 * @return void
 */

void displayItems(int choice)
{
    ifstream xFile("items.txt");
    string name;
    double power;

    // Plain items
    if(choice == 1){
        cout << "Plain items are: " << endl;
        while (xFile >> name >> power){ //loop as long as the file is open
            if(power == 0){
                cout << name << ' ' << power << endl;
            }
        }
    }

    // Helpful items
    if(choice == 2){
        cout << "Helpful items are: " << endl;
        while (xFile >> name >> power){
            if (power > 0){
                cout << name << ' ' << power << endl;
            }
        }
    }

    // Harmful items
    if(choice == 3){
        cout << "Harmful items are: " << endl;
        while(xFile >> name >> power){
            if (power < 0){
                cout << name << ' ' << power << endl;
            }
        }
    }
}
