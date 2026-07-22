#include "search_bookings.h"
#include "view_showtime.h"

void search_booking(const Movie movies[]) {
    int mode = get_valid_int("Search by:\n 1. Customer Name\n 2. Seat Number\n Choice: ", 1, 2);
    int found = 0;

    if (mode == 1) {
        char name[50];
        printf("Enter Customer Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        printf("\n--- Search Results for '%s' ---\n", name);
        for (int m = 0; m < NUM_MOVIES; m++) {
            for (int s = 0; s < NUM_SHOWTIMES; s++) {
                for (int r = 0; r < ROWS; r++) {
                    for (int c = 0; c < SEATS_PER_ROW; c++) {
                        Seat seat = movies[m].showtimes[s].seats[r][c];
                        if (seat.is_booked && strcasecmp(seat.customer_name, name) == 0) {
                            printf("Movie: %s | Showtime: %s | Seat: %c%d | Price Paid: Rs. %.2f\n",
                                   movies[m].title, movies[m].showtimes[s].time, 'A' + r, c + 1, seat.price_paid);
                            found = 1;
                        }
                    }
                }
            }
        }
    } else {
        view_showtimes(movies);
        int m_idx = get_valid_int("Select Movie ID: ", 1, NUM_MOVIES) - 1;
        int s_idx = get_valid_int("Select Showtime: ", 1, NUM_SHOWTIMES) - 1;

        char row_char;
        int col;
        printf("Enter Seat Row (A-E) and Number (1-10): ");
        if (scanf(" %c %d", &row_char, &col) == 2) {
            clear_input_buffer();
            row_char = toupper(row_char);
            int r_idx = row_char - 'A';
            int c_idx = col - 1;

            if (r_idx >= 0 && r_idx < ROWS && c_idx >= 0 && c_idx < SEATS_PER_ROW) {
                Seat seat = movies[m_idx].showtimes[s_idx].seats[r_idx][c_idx];
                if (seat.is_booked) {
                    printf("\n--- Seat Details ---\n");
                    printf("Movie: %s | Showtime: %s | Seat: %c%d\nBooked By: %s | Price Paid: Rs. %.2f\n",
                           movies[m_idx].title, movies[m_idx].showtimes[s_idx].time, row_char, col,
                           seat.customer_name, seat.price_paid);
                    found = 1;
                }
            }
        }
    }

    if (!found) {
        printf("No booking record found.\n");
    }
}
