/*
	Title:      lab4.cpp
	Author:     Harrison Allen (hcallen42)
	Date:	    9/25/2025
	Purpose:    To improve upon my game from Lab 3, which
                was a turn-based RPG similar in scope to
                Pokemon. This game will similarly be a turn-
                based RPG, however it will also incorporate
                more complex elements, such as a shop system
                and more story-based elements.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;

int main() {
    
    /*
    All ASCII text used in the program generated from https://patorjk.com/software/taag
    All ASCII art used in the pgraom generated from https://www.asciiart.eu/image-to-ascii
    */
    
    string playerName;
    string strInput;
    char monsterType;
    char charInput;
    int intInput;
    int attackDamage;
    int attackChance;
    int money = 0;
    int damageIncrease = 0;
    int healthIncrease = 0;
    int healingAmount = 20;
    int playerHealth = 100;
    int enemyHealth = 100;
    int numDefeated = 0;
    int damageDone = 0;
    int totalHealed = 0;
    bool isAlive = true;

    // Establish random number seed
    srand(time(0));

    cout << "This game is best played in full screen.\nPress enter to continue... ";
    getline(cin, strInput);

    // Print title ASCII art
    cout << "***************************************************************************************************************************************************" << endl;
    cout << " __   __  _______  __    _  _______  _______  _______  ______      _______  ___   _______  __   __  _______  _______  ______      __   __  _______ " << endl;
    cout << "|  |_|  ||       ||  |  | ||       ||       ||       ||    _ |    |       ||   | |       ||  | |  ||       ||       ||    _ |    |  | |  ||       |" << endl;
    cout << "|       ||   _   ||   |_| ||  _____||_     _||    ___||   | ||    |    ___||   | |    ___||  |_|  ||_     _||    ___||   | ||    |  |_|  ||____   |" << endl;
    cout << "|       ||  | |  ||       || |_____   |   |  |   |___ |   |_||_   |   |___ |   | |   | __ |       |  |   |  |   |___ |   |_||_   |       | ____|  |" << endl;
    cout << "|       ||  |_|  ||  _    ||_____  |  |   |  |    ___||    __  |  |    ___||   | |   ||  ||       |  |   |  |    ___||    __  |  |       || ______|" << endl;
    cout << "| ||_|| ||       || | |   | _____| |  |   |  |   |___ |   |  | |  |   |    |   | |   |_| ||   _   |  |   |  |   |___ |   |  | |   |     | | |_____ " << endl;
    cout << "|_|   |_||_______||_|  |__||_______|  |___|  |_______||___|  |_|  |___|    |___| |_______||__| |__|  |___|  |_______||___|  |_|    |___|  |_______|" << endl << endl;
    cout << "***************************************************************************************************************************************************" << endl << endl << endl;

    // Print introduction message
    cout << "[<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>]" << endl;
    cout << "[  Welcome, young monster, to the land of Monstovia. This is a land where the monsters of the world converge,  ]" << endl;
    cout << "[   to fight in a brutal tournament where only the victor shall make it out alive. This tournament is called   ]" << endl;
    cout << "[     MONSTER KOMBAT: a name completely original and not inspired from any of our rival tournament brands.     ]" << endl;
    cout << "[<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>]" << endl << endl;

    // Prompt the user for their name
    cout << "Now, what shall I call you, young monster? ";
    getline(cin, playerName);
    cout << "Excellent! It is a pleasure to meet you, " << playerName << "! I am sure you and your monster prowess will excel in the tournament!" << endl << endl;

    // Prompt the user for their monster type (a, b, or c)
    cout <<  "I apologize if this comes across as rude, but I can't quite tell which type of monster you are. Would you mind" << endl;
    cout << "telling me for the tournament registration?" << endl << endl;
    cout << "Select one of the following monster types:\nA. Zombie\nB. Vampire\nC. Shape-shifter\nPlease enter A, B, or C: ";
    cin >> monsterType;

    // Validate the user's monster selection input
    while (toupper(monsterType) != 'A' && toupper(monsterType) != 'B' && toupper(monsterType) != 'C') {
        cout << "Invalid input! Please enter either A, B, or C: ";
        cin >> monsterType;
    }

    // Send a specific continuing message depending on the monster type selected prior
    cout << endl << "Ah, I see! So you are a";
    if (toupper(monsterType) == 'A') {
        cout << " zombie! ";
    } else if (toupper(monsterType) == 'B') {
        cout << " vampire! ";
    } else {
        cout << " shape-shifter! ";
    }
    cout << "Very interesting indeed." << endl << endl;
    cout << "Well " << playerName << ", your registration is now complete!\nBefore the tournament begins, would you like an explanation as to how the tournament process works?" << endl;
    cout << "Enter 'Y' to hear about the tournament process, or 'N' to skip and proceed to the tournament: ";
    cin >> charInput;

    // Validate user input as 'Y', 'y', 'N', or 'n'
    while (toupper(charInput) != 'Y' && toupper(charInput) != 'N') {
        cout << "Invalid input! Please enter either Y or N: ";
        cin >> charInput;
    }

    // Display the tournament information if the user inputted Y
    if (toupper(charInput) == 'Y') {
        cout << endl << endl;
        cout << "[<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>]" << endl;
        cout << "[            Excellent! Here's the basic information you need to know to succeed in MONSTER KOMBAT:            ]" << endl;
        cout << "[ ------------------------------------------------------------------------------------------------------------ ]" << endl;
        cout << "[ In MONSTER KOMBAT, you will face off against 3 rounds of increasingly difficult opponents, all in an attempt ]" << endl;
        cout << "[      to successfully survive until the end. As a monster, you have 3 moves you can do at any given time      ]" << endl;
        cout << "[   during combat. The first two are your attacks, which are unique to your monster type. The first of which   ]" << endl;
        cout << "[   will always do some amount of damage to your opponent (anywhere from 10 to 50 damage), whilst the second   ]" << endl;
        cout << "[  of which has a 50 percent chance to do 30 damage, 20 percent chance to do 100 damage and defeat your enemy  ]" << endl;
        cout << "[  instantly, and a 30 percent chance to do no damage and skip your attack turn. Finally, your third move is   ]" << endl;
        cout << "[        your healing move, which skips your attack turn but heals some amount of health from 20 to 40.        ]" << endl;
        cout << "[ ------------------------------------------------------------------------------------------------------------ ]" << endl;
        cout << "[    For each enemy that you defeat in the tournament, you'll earn some coins. These coins can then be used    ]" << endl;
        cout << "[  between rounds to purchase permanent upgrades, such as healing more, or doing more damage from your attack  ]" << endl;
        cout << "[                                                    moves.                                                    ]" << endl;
        cout << "[ ------------------------------------------------------------------------------------------------------------ ]" << endl;
        cout << "[              That should be everything that you need to know to succeed! Best of luck, monster!              ]" << endl;
        cout << "[<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>]" << endl << endl << endl;
    }

    // Initalize tournament start
    cout << "Alright! Well, are you ready to proceed to the tournament, then?" << endl;
    cout << "(Press enter to continue...) ";
    cin.ignore();
    getline(cin, strInput);
    cout << endl << endl;


    // Loop for each opponent in the tournament (3 rounds total)
    while (numDefeated < 3 && isAlive) {
        // Display a different match-starting message, depending on the opponent the user is about to face
        if (numDefeated == 0) {
            cout << "[<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>]" << endl;
            cout << "[                 For your first opponent, you will face the mysterious and elusive Skeleton!!                 ]" << endl;
            cout << "[ ------------------------------------------------------------------------------------------------------------ ]" << endl;
            cout << "[                                              ##################                                              ]" << endl;
            cout << "[                                          #####                #####                                          ]" << endl;
            cout << "[                                        ####                      ####                                        ]" << endl;
            cout << "[                                       ###                          ###                                       ]" << endl;
            cout << "[                                      ###                            ###                                      ]" << endl;
            cout << "[                                      ## #                          # ##                                      ]" << endl;
            cout << "[                                      #####                        #####                                      ]" << endl;
            cout << "[                                      #####                        #####                                      ]" << endl;
            cout << "[                                      ######  ######      ######  ######                                      ]" << endl;
            cout << "[                                       ##############    ##############                                       ]" << endl;
            cout << "[                                        #############    ######### ###                                        ]" << endl;
            cout << "[                                         ##  #######      ######## ##                                         ]" << endl;
            cout << "[                                         ##   ####   ####   ####   ###                                        ]" << endl;
            cout << "[                                         ###        ######         ##                                         ]" << endl;
            cout << "[                                          #####    ########    #####                                          ]" << endl;
            cout << "[                                            ######  ######  ######                                            ]" << endl;
            cout << "[                                            ######          ######                                            ]" << endl;
            cout << "[                                             ####################                                             ]" << endl;
            cout << "[                                             #####################                                            ]" << endl;
            cout << "[                                             ## ############## ##                                             ]" << endl;
            cout << "[                                             ###     #####    ###                                             ]" << endl;
            cout << "[                                              ####          ####                                              ]" << endl;
            cout << "[                                                ##############                                                ]" << endl;
            cout << "[ ------------------------------------------------------------------------------------------------------------ ]" << endl;
            cout << "[             With his spine-chilling and bone-crushing attacks, he's sure to be a difficult foe!!             ]" << endl;
            cout << "[                          But I'm sure he won't be a problem for you, young monster!                          ]" << endl;
            cout << "[<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>]" << endl << endl;
        } else if (numDefeated == 1) {
            cout << "[<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>]" << endl;
            cout << "[                      Your next opponent will be the strong and monstrous Frankenstein!!                      ]" << endl;
            cout << "[ ------------------------------------------------------------------------------------------------------------ ]" << endl;
            cout << "[                                                 #  +######+                                                  ]" << endl;
            cout << "[                                          .- #####################                                            ]" << endl;
            cout << "[                                        #############################                                         ]" << endl;
            cout << "[                                       ##########+##+-###+####+######+                                        ]" << endl;
            cout << "[                                      #######+#+#-+++-+#-++#+--#######                                        ]" << endl;
            cout << "[                                       ######+#+------------+++++####                                         ]" << endl;
            cout << "[                                       ####++#++--------------++++###                                         ]" << endl;
            cout << "[                                       ###+#+-+++---------------++###                                         ]" << endl;
            cout << "[                                       -###+-++#-----+++++-----++#+##                                         ]" << endl;
            cout << "[                                        ###+#+---------+--------+####                                         ]" << endl;
            cout << "[                                        ####--+###############++-+###                                         ]" << endl;
            cout << "[                                      ++###+###+-+####-+###++-+#++###+#                                       ]" << endl;
            cout << "[                                     ####+#+++###+###---+##+++##++#+##+#                                      ]" << endl;
            cout << "[                                     ###+#++--++###++---+++#++++--+#+#+                                       ]" << endl;
            cout << "[                                      ##+++++---++-+++--+++-+++++++#++#                                       ]" << endl;
            cout << "[                                       #+#++#++#++++#####+-+-+++#+#++#                                        ]" << endl;
            cout << "[                                        ++-++##+++---+++----+-##+#+-+                                         ]" << endl;
            cout << "[                                         +##++##+-+-++++#+++++#++###                                          ]" << endl;
            cout << "[                                           #+-+###+------++---++-#                                            ]" << endl;
            cout << "[                                           ##++---+++++++++++-+++#                                            ]" << endl;
            cout << "[                                         +++###++--+----------###++++                                         ]" << endl;
            cout << "[                                         ++++####+-+--------+####++-#                                         ]" << endl;
            cout << "[                                         ####++####++++++++####+#+##                                          ]" << endl;
            cout << "[                                            ##-+##############++#                                             ]" << endl;
            cout << "[                                              #+++#############                                               ]" << endl;
            cout << "[                                                  ##########                                                  ]" << endl;
            cout << "[ ------------------------------------------------------------------------------------------------------------ ]" << endl;
            cout << "[    The reanimated man of mismatched parts, Frankenstein's power is certainly a force to be reckoned with!    ]" << endl;
            cout << "[     This fight will certainly be difficult than the last. Best of luck, young monster! I believe in you!     ]" << endl;
            cout << "[<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>]" << endl << endl;
            
        } else if (numDefeated == 2) {
            cout << "[<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>]" << endl;
            cout << "[                  For your last opponent, you will face the powerful and mysterious wizard!!                  ]" << endl;
            cout << "[ ------------------------------------------------------------------------------------------------------------ ]" << endl;
            cout << "[                                                      #+-+                                                    ]" << endl;
            cout << "[                                                  #+---..-#                                                   ]" << endl;
            cout << "[                                              +--++---+###-#                                                  ]" << endl;
            cout << "[                                               ###--..-------                                                 ]" << endl;
            cout << "[                                               #---+.-----.-+##                                               ]" << endl;
            cout << "[                                              #-.----+.---#+-#                                                ]" << endl;
            cout << "[                                             -+++++..----#---                                                 ]" << endl;
            cout << "[                                               -+-+-..-.--+-+                                                 ]" << endl;
            cout << "[                                             ###----.--++++++#                                                ]" << endl;
            cout << "[                                           ##+++++-+.-+----+#++##                                             ]" << endl;
            cout << "[                                           ###++++-+-.#.--+++++-++                                            ]" << endl;
            cout << "[                                          ###++#++-.++#++#####+#++                                            ]" << endl;
            cout << "[                                          ###+##++--.-##########+#                                            ]" << endl;
            cout << "[                                         ###-#####-.--####+++-+#++                                            ]" << endl;
            cout << "[                                         ###-######...-.+.+##-##++                                            ]" << endl;
            cout << "[                                        #+#+-######+..++-+.##+##+#                                            ]" << endl;
            cout << "[                                    #####+--########.--++#--####+####                                         ]" << endl;
            cout << "[                                    ######+-#########--++++-###########                                       ]" << endl;
            cout << "[                                    #######+#########+.-+--.###########                                       ]" << endl;
            cout << "[                                    ##################..++#.###########                                       ]" << endl;
            cout << "[ ------------------------------------------------------------------------------------------------------------ ]" << endl;
            cout << "[             His origins are unknown, but he's known to be a dangerous master of the mystic arts!             ]" << endl;
            cout << "[                 He will be your most difficult opponent indeed! Best of luck, young monster!                 ]" << endl;
            cout << "[<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>]" << endl << endl;
        }

        // Pause the input stream to allow the user to read the information on each fighter
        cout << "Press enter to continue... ";
        getline(cin, strInput);

        cout << "The battle is beginning!" << endl << endl;
        
        // Loop the attack cycle until either the player or the enemy is dead
        while (playerHealth > 0 && enemyHealth > 0) {
            // Print the player's attack options
            cout << "[<><><><><><><><><><><><><><><><><><><><><><><><><><><>]" << endl;
            cout << "[           What move would you like to do?:           ]" << endl;
            cout << "[ ---------------------------------------------------- ]" << endl;
            if (toupper(monsterType) == 'A') {
                cout << "[                       1. Chomp                       ]" << endl;
                cout << "[                       2. Slash                       ]" << endl;
            } else if (toupper(monsterType) == 'B') {
                cout << "[                     1. Fang Bite                     ]" << endl;
                cout << "[                 2. Supersonic Scream                 ]" << endl;
            } else {
                cout << "[                    1. Sword Morph                    ]" << endl;
                cout << "[             2. Projectile Transformation             ]" << endl;
            }
            cout << "[                 3. Regenerate Health                 ]" << endl;
            cout << "[<><><><><><><><><><><><><><><><><><><><><><><><><><><>]" << endl << endl;

            // Prompt the user to choose which move they'd like to do
            cout << "Please enter 1, 2, or 3: ";
            cin >> intInput;

            // Validate the user's input as being in the range of 1-3
            while (intInput < 1 || intInput > 3) {
                cout << "Invalid input! Please enter 1, 2, or 3: ";
                cin >> intInput;
            }

            cout << endl;

            // Print attack information
            cout << "********************************************************" << endl;

            // Determine how much damage the user does based on their input choice (or heal the user if they chose option 3)
            if (intInput == 1) {
                /*
                Determine attack damage by combining 2 random numbers
                (One from 10-30, and another from 0-20, for a total of 10-50 damage)
                */
                attackDamage = (rand() % (30-10+1) + 10) + (rand() % (20-0+1) + 0) + damageIncrease;
                
                // Decrement enemyHealth by attackDamage
                enemyHealth -= attackDamage;

                // Save the total damage dealt
                damageDone += attackDamage;

                // Print the damage dealt to the enemy by the player
                cout << "You attacked and did " << attackDamage << " damage!" << endl;
            } else if (intInput == 2) {
                // Determine attack chance by rolling one random number from 0-10
                attackChance = rand() % (10-1+1 + 1);
                if (attackChance <= 2) {
                    // 20% chance to instakill the enemy
                    attackDamage = 100;
                } else if (attackChance <= 7) {
                    // 50% chance to do 30 damage to the enemy
                    attackDamage = 30 + damageIncrease;
                } else {
                    // 30% chance to do no damage to the enemy
                    attackDamage = 0 + damageIncrease;
                }

                // Decrement enemyHealth by attackDamage
                enemyHealth -= attackDamage;

                // Save the total damage dealt
                damageDone += attackDamage;

                // Print the damage dealt to the enemy by the player
                cout << "You attacked and did " << attackDamage << " damage!" << endl;
            } else if (intInput == 3) {
                /*
                Increase the user's health by healingAmount (20-40 health), or up to 100 if they are
                less than healingAmount health away from 100
                */
                healingAmount = rand() % (40 - 20 + 1) + 20 + healthIncrease;
                playerHealth += healingAmount;
                if (playerHealth > 100) {
                    playerHealth = 100;
                }

                // Save the total amount healed
                totalHealed += healingAmount;

                // Print message letting the user know they healed
                cout << "You healed for " << (healingAmount) << " health!" << endl;

            }

            if (enemyHealth > 0) {
                // Print remaining enemy health if the enemy has more than 0 remaining
                cout << "The enemy has " << enemyHealth << " health remaining!" << endl << endl;

                /*
                Determine the amount of damage that the enemy does back to the user, and print the result
                (Damage amount increases by +5 with each enemy)
                */
                attackDamage = rand() % (30 - 0 + 1) + 0 + (numDefeated * 5);
                cout << "The enemy attacked back and did " << attackDamage << " damage!" << endl;
                
                // Check to see if the enemy defeated the player (reduced playerHealth to 0 / less than 0)
                playerHealth -= attackDamage;

                if (playerHealth < 0) {
                    playerHealth = 0;
                    isAlive = false;

                }
                cout << "You have " << playerHealth << " health remaining!" << endl;
            } else {
                // Don't allow the enemy to attack back if the user defeats them first
                cout << "You've defeated the enemy! You have " << (2-numDefeated) << " enemies remaining!" << endl;
            }
            cout << "********************************************************" << endl << endl;

        }
        // Increment numDefeated by 1
        numDefeated++;

        // Reset enemy health to 100 after each round
        enemyHealth = 100;

        cin.ignore();
        cout << "Press enter to continue... ";
        getline(cin, strInput);

        // Create shopkeeper menu, as long as it isn't the final round and the user is still alive
        if (numDefeated < 3 && isAlive) {
            // Increase money by 10
            money += 10;
            // Print shopkeeper ASCII art
            cout << "[<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>]" << endl;
            cout << "[                                                    ######                                                    ]" << endl;
            cout << "[                                                  ####+++####                                                 ]" << endl;
            cout << "[                                                  ##+----.-#+                                                 ]" << endl;
            cout << "[                                                  ++-++-+--+-                                                 ]" << endl;
            cout << "[                                                   +-++-----                                                  ]" << endl;
            cout << "[                                                    +++--++                                                   ]" << endl;
            cout << "[                                                    -##+++-                                                   ]" << endl;
            cout << "[                                                 --+-++--+.-..                                                ]" << endl;
            cout << "[                                        --   ....-+--+-------...... -.                                        ]" << endl;
            cout << "[                                      ---- ......-#-.......-+.......---.                                      ]" << endl;
            cout << "[                                     ----- .-....-#--......-#.......----.                                     ]" << endl;
            cout << "[                                     --+-  .----.+++++++++-+++......-----                                     ]" << endl;
            cout << "[                                      ----.------#++++++++-+++-.-....-+--                                     ]" << endl;
            cout << "[                                      -+---..-+-+#++++#++#+#+++.------+--                                     ]" << endl;
            cout << "[                                      -++-------+#++++#++#+++++. ---+++--                                     ]" << endl;
            cout << "[                                      -+++-.-- +####++#++++++++- ----++--                                     ]" << endl;
            cout << "[                                       -----   +#####+#+++++++++   ---..                                      ]" << endl;
            cout << "[                                              ++#++++++-++-+++++                                              ]" << endl;
            cout << "[                                              +++#++++++++-+++++                                              ]" << endl;
            cout << "[ ------------------------------------------------------------------------------------------------------------ ]" << endl;
            cout << "[             Welcome to the shop, young monster! I will be your shopkeeper. What can I do for ya?             ]" << endl;
            cout << "[<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>]" << endl << endl;
            
            cout << "Press enter to continue... ";
            getline(cin, strInput);

            // Loop shop until the user chooses to quit
            do{
                // Print purchase options
                cout << "*******************************************************" << endl;
                cout << "You have [" << money << "] coins!" << endl << endl;
                
                // Only allow the user to purchase something if they have the coins needed to do so
                if (money >= 5) {
                    cout << "What would you like to purchase?" << endl;
                    cout << "1. Damage Upgrade (+5 damage) [5 coins]\n2. Healing Upgrade (+5 health regenerated) [5 coins]" << endl;
                    cout << "*******************************************************" << endl << endl;
                    cout << "Please enter 1 or 2 (or enter 0 to leave the shop): ";
                    cin >> intInput;

                    // Validate user input as between 0-2
                    while (intInput < 0 || intInput > 2) {
                        cout << "Invalid input! Please enter 0, 1, or 2: ";
                        cin >> intInput;
                    }

                    // Increase damageIncrease or healthIncrease, depending on what the user purchases
                    if (intInput == 1) {
                        // If the user selects option 1:
                        damageIncrease += 5; // Increase the amount of damage they deal by 5
                        money -= 5; // Decrease their amount of money by 5
                        cout << "Your total damage increase is now " << damageIncrease << endl;
                    } else if (intInput == 2) {
                        // If the user selects option 2:
                        healthIncrease += 5; // Increase the amount they heal by 5
                        money -= 5; // Decrease their amount of money by 5
                        cout << "Your total health increase is now " << healthIncrease << endl;
                    }
                } else {
                    // Restrict the user from purchasing anything if they have less than 5 coins (not enough to buy anything)
                    cout << "You don't have enough to purchase anything!" << endl;
                    cout << "Enter '0' to exit the shop: ";
                    cin >> intInput;

                    // Validate user input to quit the shop
                    while (intInput > 0 || intInput < 0) {
                        cout << "Invalid input! Enter 0 to exit the shop: ";
                        cin >> intInput;
                    }
                }
                cout << endl;
            } while (intInput != 0);
        }
        if (numDefeated < 3 && isAlive) {
            cin.ignore();
        }
    }

    // Print a different ending message depending on if you are alive or not at the end
    if (!isAlive) {
        // Output "YOU DIED!!" ASCII text if you end the game dead
        cout << endl << " __   _____  _   _   ___ ___ ___ ___  _ _ " << endl;
        cout << " \\ \\ / / _ \\| | | | |   \\_ _| __|   \\| | |" << endl;
        cout << "  \\ V / (_) | |_| | | |) | || _|| |) |_|_|" << endl;
        cout << "   |_| \\___/ \\___/  |___/___|___|___/(_|_)" << endl;
    } else {
        // Output "CONGRATS!!" ASCII text if you end the game alive
        cout << endl << "   ___ ___  _  _  ___ ___    _ _____ ___ _ _ " << endl;
        cout << "  / __/ _ \\| \\| |/ __| _ \\  /_\\_   _/ __| | |" << endl;
        cout << " | (_| (_) | .` | (_ |   / / _ \\| | \\__ \\_|_|" << endl;
        cout << "  \\___\\___/|_|\\_|\\___|_|_\\/_/ \\_\\_| |___(_|_)" << endl;
    }

    // Print the total amount of damage the player dealt across the run
    cout << playerName << ", you dealt " << damageDone << " damage and healed " << totalHealed << " health!" << endl;
    
    return 0;
}