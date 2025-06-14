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

enum soldier_type { PRIVATE = 1, COMMANDER, OFFICER };


void add(vector<Soldier*>& soldiers); 

void printMedalList(const vector<Soldier*>& soldiers); 

Soldier* highestSociometricScore(const vector<Soldier*>& soldiers); 

int main()
{ 
    Soldier* s; 
    vector<Soldier*> soldiers; 
    int op; 
    cout << "enter 0-7" << endl; 
    cin >> op;

    while(op!= EXIT) 
    {
        int sumPrivateMedal = 0;
        switch (op) 
        { 
            case ADD_NEW_SOLDIER:
                // Add a new soldier
                add(soldiers);
                break; 
            case DESERVES_MEDAL:
                // Print details of all soldiers deserving a medal 
                printMedalList(soldiers); 
                break; 

            case HIGHEST_SOCIOMETRIC: 
                // Print name (last and first) of the soldier with the highest sociometric score
                s = highestSociometricScore(soldiers); 
                // Complete with vector or list parameter
                cout << "Officer with the highest sociometric score: "; 
                cout << s->getFirstName() << ' ' << s->getLastName() << endl; 
                break;

            case PRIVATE_MEDAL_COUNT: 
                // Print the number of private soldiers deserving a medal
                for (Soldier* s : soldiers)
                {
                    if (s->soldierType() == "private" && s->medal())
                        ++sumPrivateMedal;
                }
                cout << "number of privates that received medals: " << sumPrivateMedal << endl; 
                break; 

            case NONCOMBAT_COMMANDER:
                cout << "list of non combat commmanders: " << endl;
                // Print names (last and first) of commanders who are not in combat
                for (Soldier* s : soldiers) 
                    if (s->soldierType() == "commander" && ! ((Commander*)s)->isCombat()) 
                        cout << s->getLastName() << ' ' << s->getFirstName() << endl;  
                break; 

            case SUPER_SOLDIER:
                // Print a suitable message, is there a soldier who participated in more than 15 military operations
                for (Soldier* soldier : soldiers) 
                {
                    if (soldier->getNumOperations() > 15) 
                    {
                        cout << "there is at least one soldier that did more than 15 operations" << endl;
                        break;
                    }
                }

                cout << "no soldier did more than 15 operations\n"; 
                break; 
            
            case REMOVE_OFFICER:
                // Remove all officers who did not participate in any military operation from the vector
                for (auto it = soldiers.begin(); it != soldiers.end(); )
                {
                    if ((*it)->soldierType() == "officer" && (*it)->getNumOperations() == 0)
                        it = soldiers.erase(it);
                    else
                        ++it;
                }
                // Print the vector after removing officers
                for (Soldier* s : soldiers)
                    s->print();
                break;
        }

        cout << "enter 0-7" << endl;
        cin >> op;
    }

    return 0;
}


void add(vector<Soldier*>& soldiers)
{
    cout << "choose a soldier" << endl
         << "enter " << PRIVATE   << " to add a private"   << endl
         << "enter " << COMMANDER << " to add a commander" << endl
         << "enter " << OFFICER   << " to add an officer"  << endl;

    int choice;
    cin >> choice;

    Soldier* s = nullptr;
    
    switch (choice)
    {
        case PRIVATE:
            soldiers.push_back(new PrivateSoldier);
            break;
        case COMMANDER:
            soldiers.push_back(new Commander);
            break;
        case OFFICER:
            soldiers.push_back(new Officer);
            break;
        default:
            break;
    }
}

void printMedalList(const vector<Soldier*>& soldiers)
{
    for (Soldier* s : soldiers)
    {
        if (s->medal())
            s->print();
    }
}

Soldier* highestSociometricScore(const vector<Soldier*>& soldiers)
{
    Officer* topScore = nullptr;
    int n = 0;
    for (Soldier* s : soldiers)
    {
        if (s->soldierType() == "officer")
        {
            Officer* tmp = static_cast<Officer*>(s);
            if (tmp->getSocScore() > n)
            {
                n = tmp->getSocScore();
                topScore = tmp;
            }
        }
    }
    return topScore;
}