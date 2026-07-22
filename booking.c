#include "booking.h"

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int get_valid_int(const char *prompt, int min, int max) {
    int val;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &val) == 1) {
            if (val >= min && val <= max) {
                clear_input_buffer();
                return val;
            }
        }
        printf("Invalid input! Please enter a number between %d and %d.\n", min, max);
        clear_input_buffer();
    }
}

void init_system(Movie movies[]) {
    strcpy(movies[0].title, "Avatar");
    movies[0].id = 1;
    strcpy(movies[0].showtimes[0].time, "10:00 AM");
    strcpy(movies[0].showtimes[1].time, "02:00 PM");

    strcpy(movies[1].title, "The oddyesy");
    movies[1].id = 2;
    strcpy(movies[1].showtimes[0].time, "11:30 AM");
    strcpy(movies[1].showtimes[1].time, "05:00 PM");

    strcpy(movies[2].title, "Moana");
    movies[2].id = 3;
    strcpy(movies[2].showtimes[0].time, "01:00 PM");
    strcpy(movies[2].showtimes[1].time, "07:00 PM");

    for (int m = 0; m < NUM_MOVIES; m++) {
        for (int s = 0; s < NUM_SHOWTIMES; s++) {
            movies[m].showtimes[s].total_tickets_sold = 0;
            movies[m].showtimes[s].total_revenue = 0.0;
            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < SEATS_PER_ROW; c++) {
                    movies[m].showtimes[s].seats[r][c].is_booked = 0;
                    movies[m].showtimes[s].seats[r][c].customer_name[0] = '\0';
                    movies[m].showtimes[s].seats[r][c].price_paid = 0.0;
                }
            }
        }
    }
}
