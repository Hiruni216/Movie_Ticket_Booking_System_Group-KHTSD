#include "view_seat_map.h"
#include "view_showtime.h"

void view_seat_map(const Movie movies[]) {
    view_showtimes(movies);
    int m_choice = get_valid_int("Select Movie ID (1-3): ", 1, NUM_MOVIES) - 1;
    int s_choice = get_valid_int("Select Showtime (1-2): ", 1, NUM_SHOWTIMES) - 1;

    Showtime st = movies[m_choice].showtimes[s_choice];
    printf("\nSeat Map for %s at %s\n", movies[m_choice].title, st.time);
    printf("   ");
    for (int c = 1; c <= SEATS_PER_ROW; c++) printf("%2d ", c);
    printf("\n");

    for (int r = 0; r < ROWS; r++) {
        char row_letter = 'A' + r;
        char *tier = (row_letter <= 'B') ? "Reg" : (row_letter <= 'D') ? "Prem" : "VIP";
        printf("%c (%-4s) ", row_letter, tier);

        for (int c = 0; c < SEATS_PER_ROW; c++) {
            if (st.seats[r][c].is_booked) {
                printf(" X ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("Legend: [.] Free  [X] Booked\n");
}
