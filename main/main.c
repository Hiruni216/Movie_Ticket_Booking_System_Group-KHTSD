#include <stdio.h>
#include <stdlib.h>

#include "booking.h"
#include "view_showtime.h"
#include "view_seat_map.h"
#include "book_seats.h"
#include "cancel_booking.h"
#include "search_bookings.h"
#include "view_revenue.h"

int main(void) {
    Movie movies[NUM_MOVIES];
    init_system(movies);

    int choice;
    do {
        printf("\n====================================\n");
        printf("   MOVIE TICKET BOOKING SYSTEM\n");
        printf("====================================\n");
        printf("1. View Showtimes\n");
        printf("2. View Seat Map\n");
        printf("3. Book a Seat\n");
        printf("4. Cancel a Booking\n");
        printf("5. Search Booking\n");
        printf("6. View Revenue Report\n");
        printf("7. Exit\n");
        printf("------------------------------------\n");

        choice = get_valid_int("Enter option (1-7): ", 1, 7);

        switch (choice) {
            case 1: view_showtimes(movies); break;
            case 2: view_seat_map(movies); break;
            case 3: book_seats(movies); break;
            case 4: cancel_booking(movies); break;
            case 5: search_booking(movies); break;
            case 6: view_revenue_report(movies); break;
            case 7: printf("\nExiting system. Goodbye!\n"); break;
        }
    } while (choice != 7);

    return 0;
}
