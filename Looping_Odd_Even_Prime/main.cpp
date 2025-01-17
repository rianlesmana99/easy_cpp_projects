#include <iostream>

using namespace std;

int main()
{
    while (true)
    {
        system("clear");
        int number;
        string type;
        bool isPrime = true;

        cout << "Enter the number: ";
        cin >> number;
        cin.ignore();

        if (number % 2 != 0)
        {
            type = "odd"; // ganjil
        } else {
            type = "even"; // genap
        }

        if (number > 1)
        {
            if (number % 2 != 0)
            {
                for (int i = 2; i < number; i++)
                {
                    if (number % i == 0)
                    {
                        cout << number << " is " << type << " but not a prime number!\n";
                        isPrime = false;
                        break;
                    }
                }

                if (isPrime)
                {
                    cout << number << " is " << type << " and a prime number!\n";
                }

            } else
            {
                isPrime = false;
                cout << number << " is " << type << " definitely not a prime number!\n";
            }

        } else
        {
            cout << "Please enter the hightes number!\n";
        }

        cout << "Enter to continue ...";
        cin.get();
    }
    
    return 0;
}