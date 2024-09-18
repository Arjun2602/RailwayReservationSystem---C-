#ifndef TICKETBOOKER_H_INCLUDED
#define TICKETBOOKER_H_INCLUDED

#include <unordered_map>
#include <map>
#include <queue>
#include <vector>

#include "Passenger.h"

class TicketBooker
{
public:
    static int total_lower_berth;
    static int total_middle_berth;
    static int total_upper_berth;
    static int total_Rac;
    static int total_Waiting_list;

    static std::map<int, Passenger> bookedTickets;

    static std::queue<int> racList;
    static std::queue<int> waitingList;

    // seats....
    static std::vector<int> lowerBerthSeats;
    static std::vector<int> middleBerthSeats;
    static std::vector<int> upperBerthSeats;
    static std::vector<int> racSeats;
    static std::vector<int> waitingListSeats;

    void initiateBooking();
    void bookTicket(Passenger& obj,char haveChild);
    void printAvailableTickets();
    void printBookedTickets();
    void initiateCancel();
    void cancelTicket(int id);
    void storeInBookedList(Passenger& p); // for child passenger alone
    void storeInBookedList(Passenger& p, int seat, char berth); // for remaining passenger except child

};

#endif // TICKETBOOKER_H_INCLUDED
