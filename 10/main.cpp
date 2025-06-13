#include <list> 
#include <vector> 
#include <algorithm> 
#include <string> 
#include "Soldier.h"
#include "PrivateSoldier.h"
#include "Officer.h"
#include "Commander.h"
using namespace std;

enum option {
    EXIT,                   // Exit the program
    ADD_NEW_SOLDIER,        // Add a new soldier to the list
    DESERVES_MEDAL,         // Print details of all soldiers deserving a medal
    HIGHEST_SOCIOMETRIC,    // Print name (last and first) of the soldier with the highest sociometric score
    PRIVATE_MEDAL_COUNT,    // Print the number of private soldiers deserving a medal
    NONCOMBAT_COMMANDER,    // Print names (last and first) of commanders who are not in combat
    SUPER_SOLDIER,          // Print a suitable message, is there a soldier who participated in more than 15 military operations
    REMOVE_OFFICER,         // Remove all officers who did not participate in any military operation
}; 


void add(vector<Soldier*>& soldiers); 

void printMedalList(const vector<Soldier*>& soldiers); 

Soldier* highestSociometricScore(const vector<Soldier*>& soldiers); 

int main()
{ 
    Soldier* s; 
    vector<Soldier*> soldiers; 
    int op; 
    cout<<"enter 0-7\n"; 
    cin>>op; 
    while(op!=EXIT) 
    { 
        switch (op) 
        { 
            case ADD_NEW_SOLDIER:add( soldiers ); 
            // Add a new soldier
                break; 
            case DESERVES_MEDAL:printMedalList( soldiers ); 
            // Print details of all soldiers deserving a medal
                break; 

            case HIGHEST_SOCIOMETRIC: 
                // Print name (last and first) of the soldier with the highest sociometric score
                s=highestSociometricScore( soldiers ); 
                // Complete with vector or list parameter
                cout<<"Officer with the highest sociometric score: "; 
                cout <<s->getFirstName()<<' '<<s->getLastName()<<endl; break;

            case PRIVATE_MEDAL_COUNT: 
                cout<<"number of privates that received medals: "; 
                // Print the number of private soldiers deserving a medal
                cout<<endl; 
                break; 

            case NONCOMBAT_COMMANDER:
                cout << "list of non combat commmanders: " << endl;
                // Print names (last and first) of commanders who are not in combat
                for (auto& soldier : soldiers) 
                { 
                    if (soldier->soldierType() == "commander") 
                    { 
                        Commander* c = dynamic_cast<Commander*>(soldier); 
                        if (c && !c->combat()) 
                        { 
                            cout << c->getLastName() << ' ' << c->getFirstName() << endl; 
                        } 
                    } 
                }
                cout<<endl; 
                break; 

            case SUPER_SOLDIER:
                // Print a suitable message, is there a soldier who participated in more than 15 military operations
                bool found = false;
                for (Soldier* soldier : soldiers) 
                {
                    if (soldier->getNumOperations() > 15) 
                    {
                        found = true;
                        break;
                    }
                }
                if (found) 
                    cout << "there is at least one soldier that did more than 15 operations\n";
                else 
                    cout << "no soldier did more than 15 operations\n"; 
                break; 
                
        case REMOVE_OFFICER:
            // Remove all officers who did not participate in any military operation from the list / vector
            
            // Print the list / vector after removing officers
            
            break;
        }

        cout << "enter 0-7" << endl;
        cin >> op;
    }

    return 0;
}


void add(vector<Soldier*>& soldiers)
{

}

void printMedalList(const vector<Soldier*>& soldiers)
{

}

Soldier* highestSociometricScore(const vector<Soldier*>& soldiers)
{

}