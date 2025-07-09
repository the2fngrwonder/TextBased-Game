#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const string zom = "Zombie";
const string gob = "Goblin";
const string rain = "RainMaster";

int get_party(int choice, int party_member);
double set_stats(double mod, double start_stat);
void battle(struct party_member p1, struct party_member p2, struct party_member e);

/**class stats
{
    public:
    double attack;
    double defense;
    double evade;
    
    void atk_mod(int mod)
	{
	    attack = attack*mod;
	}

    void def_mod(int mod)
	{
	    defense = defense*mod;
	}

    void evd_mod(int mod)
	{
	    evade = evade*mod;
	}
};

class zombie: public stats
{
    public:
        double attack = 2.5;
        double defense = 5.5;
	    double evade = 1.0;
};

class goblin: public stats
{
    public:
	    double attack = 3.0;
	    double defense = 3.0;
	    double evade = 2.5;
};

class rainm: public stats
{
    public:
	    double attack = 5.5;
	    double defense = 1.0;
	    double evade = 2.5;
};
*/

struct party_member
{
    string name;
    double attack;
    double defense;
    double evade;
    double health;
    int lvl;
};

int main()
{
    struct party_member zomb;
    struct party_member gobl;
    struct party_member rai;
    struct party_member temp_mem;
    struct party_member enemy;
    party_member * party = new party_member[3];
    
    zomb.name = "Zombie";
    zomb.attack = 2.5;
    zomb.defense = 5.5;
    zomb.evade = 1;
    zomb.health = 50;
    zomb.lvl = 1;
    
    gobl.name = "Goblin";
    gobl.attack = 3;
    gobl.defense = 3;
    gobl.evade = 2.5;
    gobl.health = 50;
    gobl.lvl = 1;
    
    rai.name = "RainMaster";
    rai.attack = 5.5;
    rai.defense = 1;
    rai.evade = 2.5;
    rai.health = 50;
    rai.lvl = 1;

    enemy.name = "Henchmam";
    enemy.evade = 2;
    enemy.lvl = 0; //This is used to count how many times player has encountered an enemy
    
    int choice;
    int temp;
    int finish = -4;
    string location[5] = {"Northern Plains", "Frozen Tundra", "Crashing Cliffs", "Mountain Pass", "Dessert of the Dead"};
    string current_location;
    string player;
    string options[5];
    
    cout << "Before we get started, please enter your name: ";
    
    getline(cin, player);
    
    cout << "WELCOME! " << player << "! Lets get you started with your party.\n";
    
    cout << "Please choose which character you would like in your party.\n"
    << "\t\tAttack\tDefense\tEvade\tLevel\n"
    << "1. Zombie\t" << zomb.attack << "\t" << zomb.defense << "\t" << zomb.evade << "\t" << zomb.lvl
    << "\n2. Goblin\t" << gobl.attack << "\t" << gobl.defense << "\t" << gobl.evade << "\t" << gobl.lvl
    << "\n3. RainMaster\t" << rai.attack << "\t" << rai.defense << "\t" << rai.evade << "\t" << rai.lvl << endl;
    
    do
    {
    cin >> choice;

    switch(choice)
    {
        case 1:
        party[0] = zomb;
        break;
        
        case 2:
        party[0] = gobl;
        break;
        
        case 3:
        party[0] = rai;
        break;
        
        default:
        cout << "Do you really not want a first party member?...\nEnter option 1-3\n";
    }
    }while(choice > 3 || choice < 1);
    
    cout << "\nPlease choose your second party member.\n";
    
    do
    {
    cin >> choice;

   switch(choice)
    {
        case 1:
        party[1] = zomb;
        break;
        
        case 2:
        party[1] = gobl;
        break;
        
        case 3:
        party[1] = rai;
        break;
        
        default:
        cout << "Do you really not want a second party member?...\nEnter option 1-3\n";
    }
    }while(choice > 3 || choice < 1);
    
    while(party[0].name == party[1].name)
    {
        cout << "You can't have two of the same person stupid...\n"
            << "Please choose another party member.\n";
            
            cin >> choice;
            
            switch(choice)
            {
                case 1:
                party[1] = zomb;
                break;
        
                case 2:
                party[1] = gobl;
                break;
        
                case 3:
                party[1] = rai;
                break;
            }
    }
    
    cout << "Are you satisfied with this party?: " << party[0].name << ", " << party[1].name << "\n1. Yes\n2. No\n";
    
    do
    {
        cin >> choice;
        
        switch(choice)
        {
            case 1:
            break;
        
            case 2:
            cout << "Who would you like to replace?\n1.\t" << party[0].name << "\n2.\t" << party[1].name << endl;
            cin >> choice;
            if(choice == 1)
            {        
                cout << "Who would you like to replace " << party[0].name << " with?" << endl;
                cin >> choice;
                switch(choice)
                {
                    case 1:
                    party[0] = zomb;
                    break;
        
                    case 2:
                    party[0] = gobl;
                    break;
        
                    case 3:
                    party[0] = rai;
                    break;
                }
            
                while(party[0].name == party[1].name)
                {
                    cout << "You can't have two of the same person stupid...\n"
                        << "Please choose another party member.\n";
                    cin >> choice;
                    switch(choice)
                    {
                        case 1:
                        party[0] = zomb;
                        break;
        
                        case 2:
                        party[0] = gobl;
                        break;
        
                        case 3:
                        party[0] = rai;
                        break;
                    }
                }
                cout << "Are you satisfied with this party?: " << party[0].name << ", " << party[1].name << "\n1. Yes\n2. No\n";
    
                cin >> choice;
            }
            
            if(choice == 2)
            {
                cout << "Who would you like to replace: " << party[1].name << endl;
                cin >> choice;
                switch(choice)
                {
                    case 1:
                    party[1] = zomb;
                    break;
        
                    case 2:
                    party[1] = gobl;
                    break;
        
                    case 3:
                    party[1] = rai;
                    break;
                }
            
                while(party[0].name == party[1].name)
                {
                    cout << "You can't have two of the same person stupid...\n"
                        << "Please choose another party member.\n";
                    cin >> choice;
                    switch(choice)
                    {
                        case 1:
                        party[1] = zomb;
                        break;
        
                        case 2:
                        party[1] = gobl;
                        break;
        
                        case 3:
                        party[1] = rai;
                        break;
                    }
                }
                cout << "Are you satisfied with this party?: " << party[0].name << ", " << party[1].name << "\n1. Yes\n2. No\n";
    
                cin >> choice;
            }
            
            else
            {
                choice = 2;
                cout << "Please enter either 1 or 2 to choose the party member you wish to replace";
            }
            break;
            
            default:
            choice = 2;
            cout << "Don't be difficult... Please enter either 1 or 2\n";
        } 
    }while(choice == 2);
    
    if((party[0].name == zom || party[1].name == zom)&&(party[0].name == gob || party[1].name == gob))
    party[2] = rai;
    
    if((party[0].name == zom || party[1].name == zom)&&(party[0].name == rain || party[1].name == rain))
    party[2] = gobl;
    
    if((party[0].name == gob || party[1].name == gob)&&(party[0].name == rain || party[1].name == rain))
    party[2] = zomb;
    
    cout << "Wait... what's happening?....\n" << party[2].name << " just stormed off? What's wrong with him?";
    
    cout << " Well, now that you have your party it is time for you to start your adventure!\n"
    << "Before we start though.. Who would you like to lead the march?\n1. " << party[0].name << "\n2. " << party[1].name << endl;
    
    do
    {
    cin >> choice;
    
    switch(choice)
    {
        case 1:
        break;
        
        case 2:
        temp_mem = party[0];
        party[0] = party[1];
        party[1] = temp_mem;
        break;
        
        default:
        cout << "You're really having a hard time with the whole choose an available number thing...\n"
        << "Please choose either 1 or 2\n";
        break;
    }
    }while(choice > 2 || choice < 1);
    
    do
    {
    cout << "Alright. " << party[0].name << " will lead.\n\n"
    << "Now it's time to get on the old dusty trail. Here is a picture of the map.\n"
    << "--------____-----------_______------\n"
    << "-------/    \\_-----___/       \\-----\n"
    << "-----_/ 1*    \\___/            \\_---\n"
    << "---_/       ^^^^    2*           \\--\n"
    << "--/           ^^^^          5*   |--\n"
    << "--\\  ^^^    3*                   |--\n"
    << "---\\_    /\\         ^^^  ^^^^^   \\--\n"
    << "-----\\__/  \\    ^^^^4*^^^    ^^^  \\-\n"
    << "------------\\______       ________/-\n"
    << "-------------------\\_____/----------\n\n"
    << "Where would you like to start your adventure?";
    
    cin >> choice;
    
    if(choice <= 5 && choice >= 1)
    current_location = location[choice-1];
    
    if(choice > 5 || choice < 1)
    cout << "Please enter options 1-5" << endl;
    }while(choice < 1 || choice > 5);
    
    do
    {
        cout << "So you would like to start in the " << current_location << "?\n1. Yes\n2. No\n";
        cin >> choice;

	if(choice == 1)
        break;
        
        if(choice == 2)
        {
            cout << "Where would you like to start your adventure?\n";
            cin >> choice;
            
            current_location = location[choice-1];
        }
        
        else
        cout << "Please enter either 1 or 2." << endl;

    }while(choice != 1);
    
    cout << "You and your party set forth for your first mission in the " << current_location << endl;
    
    //create a seperate source code in project for each location
    //each location will have their own set of missions and then
    //a chance at the end to choose your new location with the completed
    //locations taken off the map. can create a seperate function
    //that tells which locations have been completed and outputs
    //the correct map. when all missions in all locations have been
    //completed, player will face the rogue party member to destroy 
    //him and his plot for revenge. each location and missions have 
    //something to do with some sort of sabotage or something
    //the rogue party member started.Create a counter at the end of
    //each map to count how many missions/areas have been cleared
    //so that the difficulty will scale with the player.
    //dont forget to give lvl's/gear that will enhance the party
    //members.In the final boss battle against the 3rd member he
    //pleads for his life. tells of another greaterevil you will have
    //to face. gives you opportunity to let him join your team or 
    //kill him for chance at special weapon.
    
    string npoptions[4];
    string ftoptions[5];
    string ccoptions[5];
    string mpoptions[5];
    string ddoptions[5];
    
    npoptions[0] = "1. Continue to the cabin in hopes to find something.";
    npoptions[1] = "2. Split up to look for food and water.";
    npoptions[2] = "3. Set up camp to rest.";
    npoptions[3] = "4. Go to another location.";
    
    do
    {
    if(current_location == "Northern Plains")
    {
        cout << "You have been traveling for what seems to be an eternity.\n You and your party"
        << " finally come to the Northern Plains only to find it barren.\n"
        << " While looking off into the distance you see a small cabin, but\n"
        << " your party is about ready to collapse.\n"; 
        do
        {
        cout << "What should you do?\n"
        << npoptions[0] << endl << npoptions[1] << endl << npoptions[2] << endl << npoptions[3] << endl;
        
        cin >> choice;
        
        switch(choice)
        {
            case 1:
            cout << "You continue wandering on and on only to find that you've walked in a circle.\n";
            if(npoptions[0] == "DONE")
            break;
            
            cout << "You and your party continue to the cabin only to find it abandoned.\n"
            << " All you find are tiny scraps of food, barely enough to get you through\n"
            << " the night. At least you have a roof over your head?";
            npoptions[0] = "DONE";
            break;
            
            case 2:
            if(npoptions[1] == "DONE")
            break;
            
            cout << "You and your party split up and find enough food and water for the\n"
            << " night. However, " << party[1].name << " hasn't made it back to camp yet. Should you\n"
            << " go look for him or keep waiting?\n1. Go looking\n2. Wait a little longer\n";
            
            cin >> temp;
            
            switch(temp)
            {
                case 1:
                cout << "You go out to find " << party[1].name << " but can't find him anywhere!\n"
                << "When you return back to camp at nightfall exhausted you see him already there sleeping.\n";
                break;
                
                case 2:
                cout << "You decide to trust in your friend and within 30 minutes he shows up.\n";
                break;
                
                default:
                cout << "Because of your stupidity, you choose option 1.\n";
                cout << "You go out to find " << party[1].name << " but can't find him anywhere!\n"
                << "When you return back to camp at nightfall exhausted you see him already there sleeping.\n";
            }
            cout << "You ask " << party[1].name << ", where were you?! He says he got lost when\n"
            << " he ran after what he thought looked like " << party[2].name << ". You find this strange,\n"
            << " but decide not to investigate further.\n";
            npoptions[1] = "DONE";
            break;
            
            case 3:
            if(npoptions[2] == "DONE")
            break;
            
            cout << "While setting up camp " << party[0].name << " stumbles over something hard in the ground.\n"
            << "When he looks at it closer he realized that it's a sword! What luck!";
            
            party[0].attack = set_stats(1.15, party[0].attack);
            
            cout << party[0].name << "'s attack is now: " << party[0].attack << endl;
            npoptions[2] = "DONE";
            break;
            
            case 4:
            break;
            
            default:
            cout << "Please enter option 1-4" << endl;
        }
        }while(choice != 4);
        
        if(npoptions[0] == "DONE" && npoptions[1] == "DONE" && npoptions[2] == "DONE")
        {

            battle(party[0], party[1], enemy);
            
	    party[0].lvl++;
	    party[1].lvl++;

	    cout << "Congradulations! " << party[0].name << " is now level " << party[0].lvl << "!\n";
	    cout << "Congradulations! " << party[1].name << " is now level " << party[1].lvl << "!\n";

            finish++;
            location[0] = "Northern Plains - COMPLETED";
        }
        
    do
    {
        for(int i = 0; i < 5; i++)
        {
            cout << i+1 << ". " << location[i] << endl;
        }
        
    cout << "\n--------____-----------_______------\n"
    << "-------/    \\_-----___/       \\-----\n"
    << "-----_/ 1*    \\___/            \\_---\n"
    << "---_/       ^^^^    2*           \\--\n"
    << "--/           ^^^^          5*   |--\n"
    << "--\\  ^^^    3*                   |--\n"
    << "---\\_    /\\         ^^^  ^^^^^   \\--\n"
    << "-----\\__/  \\    ^^^^4*^^^    ^^^  \\-\n"
    << "------------\\______       ________/-\n"
    << "-------------------\\_____/----------\n\n"
    << "Where would you like to go?\n";
    
    cin >> choice;
    current_location = location[choice-1];
    }while(choice > 5 || choice < 1);
    }
    
    if(current_location == "Frozen Tundra")
    {
        cout << "Hello. You're in the " << current_location << "\nWhere would you like to go?\n";
        cin >> choice;
        current_location = location[choice-1];
    }
    
    if(current_location == "Crashing Cliffs")
    {
        cout << "Hello. You're in the " << current_location << "\nWhere would you like to go?\n";
        cin >> choice;
        current_location = location[choice-1];
    }
    
    if(current_location == "Mountain Pass")
    {
        cout << "Hello. You're in the " << current_location << "\nWhere would you like to go?\n";
        cin >> choice;
        current_location = location[choice-1];
    }
    
    if(current_location == "Dessert of the Dead")
    {
        cout << "Hello. You're in the " << current_location << "\nWhere would you like to go?\n";
        cin >> choice;
        current_location = location[choice-1];
    }
    }while(finish != 1);
    
    return 0;
}

/**string get_party(int choice)
{
    int party;
    
    switch(choice)
    {
        case 1:
        party = 1;
        break;
        
        case 2:
        party = 2;
        break;
        
        case 3:
        party = 3;
        break;
    }
    
    return party;
}*/

double set_stats(double mod, double start_stat)
{
    double mod_stat;
    
    mod_stat = mod*start_stat;
    
    return mod_stat;
}
double set_enemy_attack(double p1, double p2)
{
    double e = (p1+p2)*.75;
    
    return e;
}
double set_enemy_defense(double p1, double p2)
{
    double e = (p1+p2)*.6;
    
    return e;
}
double set_enemy_health(double p1, double p2)
{
    double e = (p1+p2)/2;
    
    return e;
}
void battle(struct party_member p1, struct party_member p2, struct party_member e)
{
    int p1choice;
    int p2choice;
    int random;
    int random2;
    int random3;
    double health_holder[2];
    
    health_holder[0] = p1.health;
    health_holder[1] = p2.health;

    e.attack = (p1.attack + p2.attack)*.75;
    e.defense = (p1.defense + p2.defense)*.6;
    e.health = (p1.health + p2.health)*.5;
    
    switch(e.lvl)
    {
        case 0:
        cout << "Who the hell is this guy? and why does he want us dead so bad?!\n";
        break;
        
        case 1:
        cout << "Another one? Where are they coming from?\n";
        break;
        
        case 2:
        cout << "Alright, they really want us dead... Maybe they're trying to hide something.\n";
        break;
        
        case 3:
        cout << e.name << " #4? We got this.\n";
        break;
        
        case 4:
        cout << "They have to be getting tired soon! Now let's beat this bitch!\n";
        break;
    }
    
    cout << e.name << " moves in to attack. ";

    do
    {
        
        
        random = (rand()%3);
        
        if(random == 0)
            random = 2; 
        
        if(p1.health > 0)
        {
        cout << "What's " << p1.name << " going to do?\n1. Attack\n2. Defend\n3. Dodge\n";
        cin >> p1choice;
        
        if(p1choice == 1)
        {
            if(random == 1)
            {
                cout << p1.name << " attacks " << e.name << "!\n" 
                << e.name << "'s health: " << e.health;
                e.health = e.health - p1.attack;
                cout << " -> " << e.health << endl;
            }
            if(random == 2)
            {
                cout << p1.name << " attacks " << e.name << "! " << e.name << " is defending himself!\n"
                << e.name << "'s health: " << e.health;
                e.health = e.health - p1.attack + e.defense;
                cout << " -> " << e.health << endl;
            }
            if(random == 3)
            {
                cout << p1.name << " attacks " << e.name << "! " << e.name << " tries to dodge his attack!\n";
                random2 = (rand()%6);
                if(random2 > e.evade)
                {
                    cout << e.name << " failed to dodge the attack! \n" << e.name << "'s health: " << e.health;
                    e.health = e.health - p1.attack;
                    cout << " -> " << e.health << endl;
                }
                if(random2 < e.evade)
                {
                    cout << e.name << " dodged the attack! Sneaky little fucker...\n"
                    << e.name << "'s health: " << e.health << endl;
                }
            }
        }
        if(p1choice == 2)
            cout << p1.name << " defends himself!\n";
        if(p1choice == 3)
            cout << p1.name << " waits for " << e.name << " to attack so he can try to dodge it!\n";
        }
        
        if(p2.health > 0)
        {
        cout << "What should " << p2.name << " do?\n1. Attack\n2. Defend\n3. Dodge\n";
        cin >> p2choice;
        
        if(p2choice == 1)
        {
            if(random == 1)
            {
                cout << p2.name << " attacks " << e.name << "!\n" 
                << e.name << "'s health: " << e.health;
                e.health = e.health - p2.attack;
                cout << " -> " << e.health << endl;
            }
            if(random == 2)
            {
                cout << p2.name << " attacks " << e.name << "! " << e.name << " is defending himself!\n"
                << e.name << "'s health: " << e.health;
                e.health = e.health - p2.attack + e.defense;
                cout << " -> " << e.health << endl;
            }
            if(random == 3)
            {
                cout << p2.name << " attacks " << e.name << "! " << e.name << " tries to dodge his attack!\n";
                random2 = (rand()%9);
                if(random2 > e.evade)
                {
                    cout << e.name << " failed to dodge the attack! \n" << e.name << "'s health: " << e.health;
                    e.health = e.health - p2.attack;
                    cout << " -> " << e.health << endl;
                }
                if(random2 < e.evade)
                {
                    cout << e.name << " dodged the attack! Sneaky little fucker...\n"
                    << e.name << "'s health: " << e.health << endl;
                }
            }
        }
        if(p2choice == 2)
            cout << p2.name << " defends himself!\n";
        if(p2choice == 3)
            cout << p2.name << " waits for " << e.name << " to attack so he can try to dodge it!\n";
        }
            
        if(random == 1)
        {
            random2 = (rand()%1);
            
            if(random2 == 0)
            {
                if(p1choice == 1)
                {
                    cout << e.name << " attacks " << p1.name << "!\n"
                    << p1.name << "'s health: " << p1.health;
                    p1.health = p1.health - e.attack;
                    cout << " -> " << p1.health << endl;
                }
                if(p1choice == 2)
                {
                    cout << p1.name << " was defending himself! Suck it " << e.name << "!\n"
                    << p1.name << "'s health: " << p1.health;
                    p1.health = p1.health - e.attack + p1.defense;
                    cout << " -> " << p1.health << endl;
                }
                if(p1choice == 3)
                {
                    cout << p1.name << " tries to avoid " << e.name << "'s attack!\n";
                    random3 = (rand()%7);
                    if(random3 > p1.evade)
                    {
                        cout << e.name << " lands a hit... Lucky bastard\n"
                        << p1.name << "'s health: " << p1.health;
                        p1.health = p1.health - e.attack;
                        cout << " -> " << p1.health << endl;
                    }
                    if(random3 < p1.evade)
                    {
                        cout << p1.name << " dodges the attack!\n"
                        << p1.name << "'s health: " << p1.health << endl;
                    }
                }
            }
            if(random2 == 1)
            {
                if(p2choice == 1)
                {
                    cout << e.name << " attacks " << p2.name << "!\n"
                    << p2.name << "'s health: " << p2.health;
                    p2.health = p2.health - e.attack;
                    cout << " -> " << p2.health << endl;
                }
                if(p2choice == 2)
                {
                    cout << p2.name << " was defending himself! Suck it " << e.name << "!\n"
                    << p2.name << "'s health: " << p2.health;
                    p2.health = p2.health - e.attack + p2.defense;
                    cout << " -> " << p2.health << endl;
                }
                if(p2choice == 3)
                {
                    cout << p2.name << " tries to avoid " << e.name << "'s attack!\n";
                    random3 = (rand()%7);
                    if(random3 > p2.evade)
                    {
                        cout << e.name << " lands a hit... Lucky bastard\n"
                        << p2.name << "'s health: " << p2.health;
                        p2.health = p2.health - e.attack;
                        cout << " -> " << p2.health << endl;
                    }
                    if(random3 < p2.evade)
                    {
                        cout << p2.name << " dodges the attack!\n"
                        << p2.name << "'s health: " << p2.health << endl;
                    }
                }
            }
        }
    }while((p1.health > 0 || p2.health > 0) && e.health > 0);
    
    p1.health = health_holder[0];
    p2.health = health_holder[1];
}