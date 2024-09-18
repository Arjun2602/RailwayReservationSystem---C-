#include <iostream>
#include "TicketBooker.h"
#include "Passenger.h"

int TicketBooker::total_lower_berth = 1;
int TicketBooker::total_middle_berth = 1;
int TicketBooker::total_upper_berth = 1;
int TicketBooker::total_Rac = 1;
int TicketBooker::total_Waiting_list = 1;

std::map<int, Passenger> TicketBooker::bookedTickets;

std::queue<int> TicketBooker::racList;
std::queue<int> TicketBooker::waitingList;

// seats....
std::vector<int> TicketBooker::lowerBerthSeats = {1};
std::vector<int> TicketBooker::middleBerthSeats = {1};
std::vector<int> TicketBooker::upperBerthSeats = {1};
std::vector<int> TicketBooker::racSeats = {1};
std::vector<int> TicketBooker::waitingListSeats = {1};

void TicketBooker::initiateBooking()
{
    std::string name;
    int age;
    char gender;
    char bp = ' ';
    std::string cName;
    int cage;
    char haveChild = ' ';
    std::cout << "\nEnter name                     :";
    std::cin >> name;
    std::cout << "Enter age                      :";
    std::cin >> age;
    std::cout << "Enter gender (M/F)             :";
    std::cin >> gender;
    std::cout << "Enter Berth preference (L/M/U) :";
    std::cin >> bp;

    if(gender == 'F'){
        std::cout << "\nHave child? (y/n)              :";
        std::cin >> haveChild;
        if(haveChild == 'y'){
            std::cout << "\nEnter child name               :";
            std::cin >> cName;
            std::cout << "Enter child age                :";
            std::cin >> cage;

            Passenger p(name, age,gender, bp, cName, cage);
            bookTicket(p,haveChild);
        }else{
            // no child
            Passenger p(name, age, gender, bp, "",0);
            bookTicket(p,haveChild);
        }
    }else{
        // male
        Passenger p(name, age, gender, bp, "",0);
        bookTicket(p,haveChild);
    }
}

// store in booked map for child
void TicketBooker::storeInBookedList(Passenger& p)
{
    int key = p.PassengerId;
    bookedTickets[key] = p;
    std::cout << "\nChild details stored!!";
}

// store in booked map for rest of the adult passenger

void TicketBooker::storeInBookedList(Passenger& p, int seat, char berth)
{
    int key = p.PassengerId;
    p.number = seat;
    p.alloted = berth;
    bookedTickets[key] = p;
    if(berth == 'R')
    {
        std::cout << "\nRac booked !!";
        racList.push(p.PassengerId);
    }else if(berth == 'W')
    {
        std::cout << "\nWL booked !!";
        waitingList.push(p.PassengerId);
    }else
    {
        std::cout << "\nBooked Successfully !!";
    }
}

//  book ticket function
void TicketBooker::bookTicket(Passenger& p, char haveChild)
{
    if(total_Waiting_list == 0)
    {
        std::cout << "\nNo tickets Availabl !!";
        return;
    }
    if(p.age < 5)
    {
        storeInBookedList(p);
        return;
    }
    if(p.age > 60 || (p.gender == 'F' && haveChild == 'y'))
    {
        if(total_lower_berth > 0)
        {
            storeInBookedList(p,lowerBerthSeats[0],'L');
            lowerBerthSeats.erase(lowerBerthSeats.begin());
            total_lower_berth--;
            return;
        }
    }

    // prefered..
    if(p.berthPreference == 'L' || p.berthPreference == 'M' || p.berthPreference == 'U')
    {
        if(p.berthPreference == 'L' && total_lower_berth > 0)
        {
            storeInBookedList(p,lowerBerthSeats[0],'L');
            lowerBerthSeats.erase(lowerBerthSeats.begin());
            total_lower_berth--;
            std::cout << "\nLower berth allocated";
            return;
        }else if(p.berthPreference == 'M' && total_middle_berth > 0)
        {
            storeInBookedList(p,middleBerthSeats[0],'M');
            middleBerthSeats.erase(middleBerthSeats.begin());
            total_middle_berth--;
            std::cout << "\nMiddle berth allocated";
            return;
        }else if(p.berthPreference == 'U' && total_upper_berth > 0)
        {
            storeInBookedList(p, upperBerthSeats[0],'U');
            upperBerthSeats.erase(upperBerthSeats.begin());
            total_upper_berth--;
            std::cout << "\nUpper berth allocated";
            return;
        }
    }

    if(total_lower_berth > 0)
    {
        storeInBookedList(p,lowerBerthSeats[0],'L');
        lowerBerthSeats.erase(lowerBerthSeats.begin());
        total_lower_berth--;
        std::cout << "\nLower berth allocated";
        return;
    }
    if(total_middle_berth > 0)
    {
        storeInBookedList(p, middleBerthSeats[0],'M');
        middleBerthSeats.erase(middleBerthSeats.begin());
        total_middle_berth--;
        std::cout << "\nMiddle berth allocated";
        return;
    }
    if(total_upper_berth > 0)
    {
        storeInBookedList(p, upperBerthSeats[0], 'U');
        upperBerthSeats.erase(upperBerthSeats.begin());
        total_upper_berth--;
        std::cout << "\nUpper berth allocated";
        return;
    }
    if(total_Rac > 0)
    {
        storeInBookedList(p, racSeats[0], 'R');
        racSeats.erase(racSeats.begin());
        total_Rac--;
        return;
    }
    if(total_Waiting_list > 0)
    {
        storeInBookedList(p, waitingListSeats[0],'W');
        waitingListSeats.erase(waitingListSeats.begin());
        total_Waiting_list--;
        return;
    }

    std::cout << "\nNo tickets Available !!";
    return;
}



void TicketBooker::printAvailableTickets()
{
    std::cout << "\t\tAvailable ticket\n";
    std::cout << "\t\t================\n";
    std::cout << "\nTotal Lower berth    :" << total_lower_berth;
    std::cout << "\nTotal Middle berth   :" << total_middle_berth;
    std::cout << "\nTotal Upper berth    :" << total_upper_berth;
    std::cout << "\n\nTotal Rac            :" << total_Rac;
    std::cout << "\nTotal Waiting List   :" << total_Waiting_list << "\n";
}

void TicketBooker::printBookedTickets()
{

    for(auto it : bookedTickets)
    {
        Passenger p = it.second;
        std::cout << "\nPassenger Id            :" << p.PassengerId;
        std::cout << "\nName                    :" << p.name;
        std::cout << "\nAge                     :" << p.age;
        std::cout << "\nGender                  :" << p.gender;
        std::cout << "\nAlloted                 :" << p.number << p.alloted;
        std::cout << "\n=====================================";
    }
}

void TicketBooker::initiateCancel()
{
    int id;
    std::cout << "\nEnter Id :";
    std::cin >> id;
    if(bookedTickets.count(id) == 0)
    {
        std::cout << "\nEnter valid Id !!";
        return;
    }
    cancelTicket(id);
}
// (id) name, age , gender, berth preference, number, alloted, cname, cage
void TicketBooker::cancelTicket( int id)
{
    Passenger p =  bookedTickets[id];
    bookedTickets.erase(id);
    std::cout << "\nCanceled Successfully !!";
    int position = p.number;
    if(p.alloted == "L"){
        total_lower_berth++;
        lowerBerthSeats.push_back(position);
    }else if(p.alloted == "M"){
        total_middle_berth++;
        middleBerthSeats.push_back(position);
    }else{
        total_upper_berth++;
        upperBerthSeats.push_back(position);
    }

    if(!racList.empty())
    {
        Passenger Pass_from_rac = bookedTickets[racList.front()];
        racList.pop();
        int rac_position = Pass_from_rac.number;
        total_Rac++;
        racSeats.push_back(rac_position);

        if(!waitingList.empty())
        {
            Passenger pass_from_wL = bookedTickets[waitingList.front()];
            waitingList.pop();
            int wl_position = pass_from_wL.number;

            total_Waiting_list++;
            waitingListSeats.push_back(wl_position);

            {
                //std::cout << "This Waiting list pass moved to RAC";
                //bookedTickets[pass_from_wL.PassengerId].number = racSeats[0];
                //bookedTickets[pass_from_wL.PassengerId].alloted = "R";
                pass_from_wL.number = racSeats[0];
                pass_from_wL.alloted = "R";

                bookedTickets[pass_from_wL.PassengerId] = pass_from_wL;
            }

            racSeats.erase(racSeats.begin());
            racList.push(pass_from_wL.PassengerId);
            total_Rac--;
        }
        char haveChild = ' ';
        if(Pass_from_rac.cName != "")
        {
            haveChild = 'y';
        }else
        {
            haveChild = 'n';
        }
        bookTicket(Pass_from_rac, haveChild);
    }
}
