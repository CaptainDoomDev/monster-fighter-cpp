/*
	Title:  	lab3.cpp
	Author:		Harrison Allen (hcallen42)
	Date:		Thursday, September 18th, 2025	
	Purpose:	This program is written as a game similar to Pokemon,
                where the user selects a monster, names it, and will
                attack however many monsters they decide,
                in an attempt to defeat all of them.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    string name;
    string monsterName;
    string monsterChoice;
    int choice;
    int attackDamage;
    int attackChance;
    int numEnemies;
    int points = 0;
    int health = 100;
    int enemyHealth = 100;
    int totalDamage = 0;
    bool hasHealthItem = false;
    bool didRun = false;
    bool alive = true;

    // Establish randomization seed
    srand(time(0));

    /*
    Create Title Screen
    Title ASCII art generated from https://patorjk.com/software/taag
    */ 
    cout << "  __  __                 _              ______ _       _     _            " << endl;
    cout << " |  \\/  |               | |            |  ____(_)     | |   | |           " << endl;
    cout << " | \\  / | ___  _ __  ___| |_ ___ _ __  | |__   _  __ _| |__ | |_ ___ _ __ " << endl;
    cout << " | |\\/| |/ _ \\| '_ \\/ __| __/ _ \\ '__| |  __| | |/ _` | '_ \\| __/ _ \\ '__|" << endl;
    cout << " | |  | | (_) | | | \\__ \\ ||  __/ |    | |    | | (_| | | | | ||  __/ |   " << endl;
    cout << " |_|  |_|\\___/|_| |_|___/\\__\\___|_|    |_|    |_|\\__, |_| |_|\\__\\___|_|   " << endl;
    cout << "                                                  __/ |                   " << endl;
    cout << "                                                 |___/                    " << endl;
    cout << endl << endl;

    // Prompt the user for their name (user input 1/5)
    cout << "Hello! Welcome to Monster Fighter. What is your name?\nPlease enter name: ";
    getline(cin, name);
    cout << endl;

    // Prompt the user for their monster choice (1, 2, or 3) (user input 2/5)
    cout << "Excellent! Now, " << name << ", which monster would you like to select for your journey?\n1. Zombie\n2. Vampire\n3. Spider" << endl;
    cout << "Enter 1, 2, or 3 to select your monster: ";
    cin >> choice;

    // Confirm that the user's input is valid by checking if it is within the range 1-3
    while (choice < 1 || choice > 3) {
        cout << "Invalid input! Please enter 1, 2, or 3: ";
        cin >> choice;
    }

    cout << endl;

    // Save the user's monster choice as a string variable to determine available attacks later
    if (choice == 1) {
        monsterChoice = "Zombie";
    } else if (choice == 2) {
        monsterChoice = "Vampire";
    } else {
        monsterChoice = "Spider";
    }

    // Prompt the user to name their monster (user input 3/5)
    cout << "What would you like to name your monster?\nPlease enter monster name: ";
    cin.ignore();
    getline(cin, monsterName);
    cout << endl;

    // Ask the user how many enemies they'd like to fight (user input 4/5)
    cout << "How many enemies would you like to fight?\nPlease enter a number: ";
    cin >> numEnemies;

    cout << endl << endl;

    // Loop for all number of enemies selected by the user (numEnemies)
    while (numEnemies > 0) {
        cout << "An enemy appeared! ";
        
        while (enemyHealth > 0) {
            cout << "What would you like to do? " << endl;
            // Prompt the user what they would like to do in combat (1, 2, or 3) (user input 5/5)
            cout << "1. Attack\n2. Heal\n3. Run\nPlease enter 1, 2, or 3: ";
            cin >> choice;

            // Confirm that the user's input is valid
            while (choice < 1 || choice > 3) {
                cout << "Invalid input! Please enter 1, 2, or 3: ";
                cin >> choice;
            }

            cout << endl;

            if (choice == 1) {
                cout << "What attack would you like " << monsterName << " to do?" << endl;
                
                /*
                Provide the user with attack options depending on their monster type:
                Option 1 will guaranteed do some damage (10 to 50)
                Option 2 is a has a 20% chance to do 100 damage, 50% chance to do 30 damage, and 30% chance to do no damage
                */ 
                if (monsterChoice == "Zombie") {
                    cout << "1. Chomp\n2. Slash" << endl;
                } else if (monsterChoice == "Vampire") {
                    cout << "1. Bite\n2. Scream" << endl;
                } else {
                    cout << "1. Web\n2. Venom Spit" << endl;
                }

                // Prompt the user which attack they'd like to select (1 or 2)
                cout << "Please enter 1 or 2: ";
                cin >> choice;

                // Confirm that the user's input is valid by checking if its either 1 or 2
                while (choice < 1 || choice > 2) {
                    cout << "Invalid input! Please enter 1 or 2: ";
                    cin >> choice;
                }

                cout << endl << endl;

                if (choice == 1) {
                    /*
                    Determine attack damage by combining 2 random numbers
                    (One from 10-30, and another from 0-20, for a total of 10-50 damage)
                    */
                    attackDamage = (rand() % (30-10+1) + 10) + (rand() % (20-0+1) + 0);
                } else {
                    // Determine attack chance by rolling one random number from 0-10
                    attackChance = rand() % (10-1+1 + 1);
                    if (attackChance <= 2) {
                        // 20% chance to instakill the enemy
                        attackDamage = 100;
                    } else if (attackChance <= 7) {
                        // 50% chance to do 30 damage to the enemy
                        attackDamage = 30;
                    } else {
                        // 30% chance to do no damage to the enemy
                        attackDamage = 0;
                    }
                }

                // Announce the damage done to the enemy from the attack, as well as the enemy's total health remaining
                cout << "**************************************************" << endl; // Framing for attack screen
                cout << "You did " << attackDamage << " damage!" << endl;
                enemyHealth -= attackDamage;

                // Store total attack damage in totalDamage variable to display at the end of the run
                totalDamage += attackDamage;

                // If enemy health dips below zero, set its value to 0
                if (enemyHealth < 0) {
                    enemyHealth = 0;
                }
                cout << "The enemy has " << enemyHealth << " health remaining!" << endl << endl;

            } else if (choice == 2) {
                /*
                Check to see if the user has a health item, and if they do, add 50 to their total health
                then reset hasHealthItem to false

                If they don't, simply skip the user's turn
                */ 
                if (hasHealthItem == true) {
                    health += 50;
                    cout << "**************************************************" << endl; // Framing for attack screen
                    cout << "You now have " << health << " health!" << endl << endl;
                    hasHealthItem = false;
                } else {
                    cout << "**************************************************" << endl; // Framing for attack screen
                    cout << "You don't currently have an available health item!" << endl << endl;
                }
            } else {
                /*
                If the user runs, set enemyHealth to 0 to break loop, and set didRun to true to store running status
                (prevents user from earning a point for running away during battle)
                */
                enemyHealth = 0;
                didRun = true;
                cout << endl << endl;
            }
            

            
            /*
            After the user attacks or heals, the enemy attacks back (random damage value from 0 to 30)
            Then announce the damage done to the user from the attack, as well as the user's total health remaining
            */
            attackDamage = rand() % (30 - 0 + 1) + 0;
            cout << "The enemy attacked back and did " << attackDamage << " damage!" << endl;
            health -= attackDamage;
            
            /*
            If the user's health is less than zero, set its value to 0 and set alive to false
            Set enemyHealth to 0 to break the loop
            */
            if (health <= 0) {
                alive = false;
                enemyHealth = 0;
                health = 0;
            }
            cout << "You have " << health << " health remaining!" << endl;
            cout << "**************************************************" << endl; // Framing for attack screen
            cout << endl << endl << endl;

        }

        // Check if the user is still alive or not, and end the loop if they aren't
        if (!alive) {
            numEnemies = 0;
        } else {
            // Give the user points if they successfully defeated the enemy without running, otherwise, reset didRun to false
            if (!didRun) {
                points++;
                cout << endl << "Congrats! You and " << monsterName << " have defeated " << points << " enemies!\n";
                // Determine if user earns a health item or not from defeating the monster (50% chance)
                hasHealthItem = rand() % (1 - 0 + 1) + 0;
                if (hasHealthItem) {
                    cout << "You earned a health item!\n";
                }
            } else {
                didRun = false;
                cout << endl << "You and " << monsterName << " have defeated " << points << " enemies.\n";
            }

            // Decrease numEnemies by 1
            numEnemies--;

            // If there are still enemies left, ask the user if they would like to continue fighting or not
            if (numEnemies > 0) {
                cout << "Would you like to continue fighting?\n1. Yes\n2. No\nPlease enter 1 or 2: ";
                cin >> choice;

                // Confirm that the user's input is valid
                while (choice < 1 || choice > 2) {
                    cout << "Invalid input! Please enter 1 or 2: ";
                    cin >> choice;
                }

                cout << endl << endl << endl;

                /*
                If the user would like to continue, reset enemy health and continue with the loop
                If not, set numEnemies to 0 to end the loop
                */
                if (choice == 1) {
                    enemyHealth = 100;
                } else {
                    numEnemies = 0;
                }
            }
        }
    }
    
    /*
    Send unique ending message depending on if the player died or not during their run
    ASCII art generated from https://patorjk.com/software/taag
    */
    if (!alive) {
        // Print "YOU DIED!!" in ASCII art
        cout << "___  _ ____  _       ____  _  _____ ____  _  _ " << endl;
        cout << "\\  \\///  _ \\/ \\ /\\  /  _ \\/ \\/  __//  _ \\/ \\/ \\ " << endl;
        cout << " \\  / | / \\|| | ||  | | \\|| ||  \\  | | \\|| || |" << endl;
        cout << " / /  | \\_/|| \\_/|  | |_/|| ||  /_ | |_/|\\_/\\_/" << endl;
        cout << "/_/   \\____/\\____/  \\____/\\_/\\____/\\____/(_)(_)" << endl;
        cout << endl;
    } else {
        // Print "CONGRATS!!" in ASCII art
        cout << " ____  ____  _      _____ ____  ____ _____ ____  _  _ " << endl;
        cout << "/   _\\/  _ \\/ \\  /|/  __//  __\\/  _ Y__ __Y ___\\/ \\/ \\ " << endl;
        cout << "|  /  | / \\|| |\\ ||| |  _|  \\/|| / \\| / \\ |    \\| || |" << endl;
        cout << "|  \\__| \\_/|| | \\||| |_//|    /| |-|| | | \\___ |\\_/\\_/" << endl;
        cout << "\\____/\\____/\\_/  \\|\\____\\\\_/\\_\\\\_/ \\| \\_/ \\____/(_)(_)" << endl;
        cout << endl;
    }
    // Send a following message telling the user the enemies they defeated (points earned) and the total damage they dealt
    cout << name << ", you successfully defeated " << points << " enemies and dealt a total of " << totalDamage << " damage!";
    return 0;
}