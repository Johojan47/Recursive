#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;


// Start off not having a weapon
bool hasWeapon = false; 

void showCorridorText()
{
    cout << R"(
    ||=======================||
    ||                       ||
    ||   Spaceship Corridor  ||
    ||                       ||
    ||=======================||)"
         << endl;
}

void showAlien()
{
    cout << "YOU'VE ENCOUNTERED AN ALIEN!!" << endl;
}

void showWeapon()
{
    cout << "You spot a gun on the floor. You pick it up.\n";
    hasWeapon = true;
}

void exploreRoom(int depth, int fearLevel)
{
    if (depth <= 0)
    {
        cout << "\nYou've reached the end of the corridor. \nA hatch opens... You see the rays of sunlight. Congratulations you survived.\n";
        return;
    }

    // If the fear is equal or greater than 5 than you kill yourself

    if (fearLevel >= 5)
    {
        if (hasWeapon)
        {
            cout << "\nThe fear becomes too much to bear. Your hands tremble uncontrollably.\n";
            cout << "In a moment of sheer panic, you raise the gun to your head..\n";
            cout << "The last thing you feel is your ears ringing out and warm blood running on your face.\n";
            return;
        }
        else
        {
            cout << "\nYour mind breaks from the pressure...\nYour mind slowly drifts into the void\n";
            return;
        }
    }

    showCorridorText();
    cout << "\n[Depth: " << depth << "] [Fear Level: " << fearLevel << "]\n";
    cout << "You start hearing clicking noises..\n";

    if (!hasWeapon && (rand() % 4 == 0))
    {
        showWeapon();
    }

    cout << "\nChoose a direction:\n";
    cout << "1. Left - The air feels colder.\n";
    cout << "2. Right - There's something... breathing.\n";
    cout << "3. Forward - The corridor looks endless.\n";
    if (hasWeapon)
    {
        cout << "4. Fire weapon at alien\n";
    }
    cout << "> ";

    int choice;
    cin >> choice;

    // Randomize the encounters make the game not feel repeatable

    int encounter = rand() % 6;

    if (encounter == 0) 
    {
        showAlien();
        if (hasWeapon)
        {
            cout << "\nThe alien charges at you! You raise your weapon and fire!\n";
            cout << "The gun hit the alien... but it keeps flying and hits the wall!\n";
            cout << "A massive hole now opens! You're sucked out into the vacuum of space...\n";
            return;
        }
        else
        {
            cout << "\nYou see a shadowy figure running towards you!\nThe alien crushes your skull.\n";
            return;
        }
    }

    switch (choice) {
        case 1:
            cout << "\nYou take the left path...\n";
            exploreRoom(depth - 1, fearLevel + 1);
            break;
        case 2:
            cout << "\nYou take the right path...\n";
            exploreRoom(depth - 2, fearLevel + 2);
            break;
        case 3:
            cout << "\nYou push forward...\n";
            exploreRoom(depth - 1, fearLevel);
            break;
        case 4:
            if (hasWeapon)
            {
                if (rand() % 2 == 0)
                {
                    cout << "\nYou fire hastily and hit a panel!\n";
                    cout << "An emergency hatch opens revealing an escape pod!\n";
                    cout << "You jump in and eject into space...\n";
                    cout << "As you float away, you realize there's no rescue coming...\n";
                    return;
                }
                else
                {
                    cout << "\nYou fire wildly in panic!\n";
                    cout << "The gun jumps back close to you!\n";
                    cout << "Your fear increases rapidly!\n";
                    exploreRoom(depth - 1, fearLevel + 3);
                }
            }
            else
            {
                cout << "\nInvalid Choice!\n";
                exploreRoom(depth, fearLevel);
            }
            break;
        default:
            cout << "\nYou freeze up... the walls feel closer.\n";
            exploreRoom(depth - 1, fearLevel + 1);
            break;
    }      
}

int main()
{
    srand(time(0));
  
    cout << "Welcome to The Void\n";
    cout << "You are Captain Chad Whiteley, the last survivor of the S.S. Faith.\n";
    cout << "Your mission: Escape the haunted corridors before madness or worse consumes you.\n\n";
  
    exploreRoom(5, 0);
  
    cout << "\nGame Over.\n";
  
    return 0;
}