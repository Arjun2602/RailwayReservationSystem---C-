#include <iostream>
#include <string>

#include "TicketBooker.h"

using namespace std;

void displayModule()
{
    cout << "\n1.Book\n";
    cout << "2.Cancel\n";
    cout << "3.Print booked tickets\n";
    cout << "4.Print available ticket\n";
    cout << "5.Exit\n";
}
int main()
{
    cout << "\t\tRailway Reservation System!!\n";
    cout << "\t\t===========================\n";
    bool flag = true;
    int choice = 0;
    while(flag)
    {
        displayModule();
        cin >> choice;

        switch(choice)
        {
        case 1:
            {
                // book
                TicketBooker t;
                t.initiateBooking();
                break;
            }
        case 2:
            {
                // cancel Ticket
                TicketBooker t;
                t.initiateCancel();
                break;
            }
        case 3:
            {
                // print booked Tickets
                TicketBooker t;
                t.printBookedTickets();
                break;
            }
        case 4:
            {
                // print tickets
                TicketBooker t;
                t.printAvailableTickets();
                break;
            }
        case 5:
            {
                flag = false;
                break;
            }
        default:
            {
                cout << "Invalid try !!" << endl;
                break;
            }
        }
    }
}
