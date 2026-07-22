#include "cancel_booking.h"
#include "view_showtime.h"

void cancel_booking(Movie movies[]) {
    view_showtimes(movies);
    int m_idx = get_valid_int("Select Movie ID (1-3): ", 1, NUM_MOVIES) - 1;
    int s_idx = get_valid_int("Select Showtime (1-2): ", 1, NUM_SHOWTIMES) - 1;

    char row_char;
    int col;
    printf("Enter Seat Row (A-E) and Seat Number (1-10) to cancel: ");
    if (scanf(" %c %d", &row_char, &col) == 2) {
        clear_input_buffer();
        row_char = toupper(row_char);
        int r_idx = row_char - 'A';
        int c_idx = col - 1;

        if (r_idx < 0 || r_idx >= ROWS || c_idx < 0 || c_idx >= SEATS_PER_ROW) {
            printf("Error: Invalid seat numbers.\n");
            return;
        }

        Seat *seat = &movies[m_idx].showtimes[s_idx].seats[r_idx][c_idx];
        if (!seat->is_booked) {
            printf("Error: Seat %c%d is not currently booked.\n", row_char, col);
            return;
        }

        movies[m_idx].showtimes[s_idx].total_tickets_sold--;
        movies[m_idx].showtimes[s_idx].total_revenue -= seat->price_paid;

        printf("Booking for %s at seat %c%d (Refund: Rs. %.2f) has been CANCELLED.\n",
               seat->customer_name, row_char, col, seat->price_paid);

        seat->is_booked = 0;
        seat->customer_name[0] = '\0';
        seat->price_paid = 0.0;
    } else {
        printf("Invalid input format.\n");
        clear_input_buffer();
    }
}
