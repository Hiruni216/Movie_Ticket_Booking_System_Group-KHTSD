#include "view_revenue.h"

void view_revenue_report(const Movie movies[]) {
    double grand_total_revenue = 0.0;
    int grand_total_tickets = 0;

    printf("\n=================== REVENUE REPORT ===================\n");
    for (int m = 0; m < NUM_MOVIES; m++) {
        printf("Movie: %s\n", movies[m].title);
        for (int s = 0; s < NUM_SHOWTIMES; s++) {
            Showtime st = movies[m].showtimes[s];
            printf("  Time: %-10s | Tickets Sold: %2d | Revenue: Rs. %.2f\n",
                   st.time, st.total_tickets_sold, st.total_revenue);
            grand_total_revenue += st.total_revenue;
            grand_total_tickets += st.total_tickets_sold;
        }
        printf("----------------------------------------------------\n");
    }
    printf("GRAND TOTAL: Tickets Sold = %d | Total Revenue = Rs. %.2f\n", grand_total_tickets, grand_total_revenue);
    printf("====================================================\n");
}
