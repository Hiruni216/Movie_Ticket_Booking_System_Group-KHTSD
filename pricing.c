#include "pricing.h"

double calculate_ticket_price(char row, CustomerCategory cat, int is_group) {
    row = toupper(row);
    double base_price = 0.0;

    if (row == 'A' || row == 'B') {
        base_price = 500.0;  // Regular Tier[span_7](start_span)[span_7](end_span)
    } else if (row == 'C' || row == 'D') {
        base_price = 750.0;  // Premium Tier[span_8](start_span)[span_8](end_span)
    } else if (row == 'E') {
        base_price = 1000.0; // VIP Tier[span_9](start_span)[span_9](end_span)
    }

    double total_discount_rate = 0.0;

    if (cat == CATEGORY_STUDENT) {
        total_discount_rate += 0.10;
    } else if (cat == CATEGORY_SENIOR) {
        total_discount_rate += 0.20;
    }

    if (is_group) {
        total_discount_rate += 0.10;
    }

    return base_price * (1.0 - total_discount_rate);
}
