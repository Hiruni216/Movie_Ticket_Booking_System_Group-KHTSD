#include "book_seats.h"
#include "view_showtime.h"
#include "pricing.h"

void book_seats(Movie movies[]) {
    view_showtimes(movies);
    int m_idx = get_valid_int("Select Movie ID (1-3): ", 1, NUM_MOVIES) - 1;
    int s_idx = get_valid_int("Select Showtime (1-2): ", 1, NUM_SHOWTIMES) - 1;

    int num_seats = get_valid_int("How many seats do you want to book? ", 1, ROWS * SEATS_PER_ROW);
    int is_group = (num_seats >= 4) ? 1 : 0;

    char customer_name[50];
    printf("Enter Customer Name: ");
    fgets(customer_name, sizeof(customer_name), stdin);
    customer_name[strcspn(customer_name, "\n")] = 0;

    printf("Select Category:\n 0. Regular\n 1. Student (10%% off)\n 2. Senior Citizen (20%% off)\n");
    CustomerCategory cat = (CustomerCategory)get_valid_int("Choice: ", 0, 2);

    double transaction_total = 0.0;

    for (int i = 0; i < num_seats; i++) {
        char row_char;
        int col;
        int r_idx, c_idx;

        while (1) {
            printf("\nSeat %d of %d - Enter Row (A-E) and Seat Number (1-10) [e.g. C 5]: ", i + 1, num_seats);
            if (scanf(" %c %d", &row_char, &col) == 2) {
                row_char = toupper(row_char);
                r_idx = row_char - 'A';
                c_idx = col - 1;

                if (r_idx < 0 || r_idx >= ROWS || c_idx < 0 || c_idx >= SEATS_PER_ROW){
                    printf("Error: Seat out of range! Try again.\n");
                } else if (movies[m_idx].showtimes[s_idx].seats[r_idx][c_idx].is_booked) {
                    printf("Error: Seat %c%d is already booked! Try another.\n", row_char, col);
                } else {
                    clear_input_buffer();
                    break;
                }
            } else {
                printf("Invalid input format!\n");
                clear_input_buffer();
            }
        }

        double seat_price = calculate_ticket_price(row_char, cat, is_group);

        Seat *seat = &movies[m_idx].showtimes[s_idx].seats[r_idx][c_idx];
        seat->is_booked = 1;
        strcpy(seat->customer_name, customer_name);
        seat->price_paid = seat_price;
        seat->category = cat;

        movies[m_idx].showtimes[s_idx].total_tickets_sold++;
        movies[m_idx].showtimes[s_idx].total_revenue += seat_price;
        transaction_total += seat_price;

        printf("-> Seat %c%d Booked successfully for Rs. %.2f\n", row_char, col, seat_price);
    }

    printf("\nBooking Complete! Total Amount Paid: Rs. %.2f\n", transaction_total);
}
