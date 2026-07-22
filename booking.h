
#ifndef BOOKING_H
#define BOOKING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_MOVIES 3
#define NUM_SHOWTIMES 2
#define ROWS 5            // Rows A-E[span_4](start_span)[span_4](end_span)
#define SEATS_PER_ROW 10  // Seats 1-10[span_5](start_span)[span_5](end_span)

typedef enum {
    CATEGORY_REGULAR = 0,
    CATEGORY_STUDENT,
    CATEGORY_SENIOR
} CustomerCategory;

typedef struct {
    int is_booked;
    char customer_name[50];
    double price_paid;
    CustomerCategory category;
} Seat;

typedef struct {
    char time[10];
    Seat seats[ROWS][SEATS_PER_ROW];
    int total_tickets_sold;
    double total_revenue;
} Showtime;

typedef struct {
    int id;
    char title[50];
    Showtime showtimes[NUM_SHOWTIMES];
} Movie;

// Helper & Core Functions
void clear_input_buffer(void);
int get_valid_int(const char *prompt, int min, int max);
void init_system(Movie movies[]);

#endif
