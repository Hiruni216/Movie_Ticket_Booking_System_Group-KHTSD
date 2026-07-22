#include "view_showtime.h"

void view_showtimes(const Movie movies[]) {
    printf("\n================ AVAILABLE SHOWTIMES ================\n");
    for (int i = 0; i < NUM_MOVIES; i++) {
        printf("Movie %d: %s\n", movies[i].id, movies[i].title);
        for (int j = 0; j < NUM_SHOWTIMES; j++) {
            printf("  Showtime %d: %s\n", j + 1, movies[i].showtimes[j].time);
        }
        printf("----------------------------------------------------\n");
    }
}
