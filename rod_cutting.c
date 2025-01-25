#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void rodCutting(int rod_length) {
    int lengths[100] = {0};
    int values[100] = {0};
    double ratios[100] = {0.0};  // List of values/lengths
    int num_values = 0;          // Number of values listed
    int smallest_length = INT_MAX;

    while (scanf("%d, %d", &lengths[num_values], &values[num_values]) == 2) {
        if (lengths[num_values] > 0) {
            ratios[num_values] =
                (double)values[num_values] / lengths[num_values];
            smallest_length = (smallest_length > lengths[num_values])
                                  ? lengths[num_values]
                                  : smallest_length;
            ++num_values;
            continue;
        }
        printf("Invalid peice length: %d\n", lengths[num_values]);
    }

    int total_value = 0;
    int remainder = rod_length;

    printf("Cutting List:\n");
    while (smallest_length <= remainder) {
        int best_index = -1;
        double best_ratio = 0.0;

        for (int i = 0; i < num_values; ++i) {
            if (lengths[i] <= remainder && ratios[i] > best_ratio) {
                best_ratio = ratios[i];
                best_index = i;
            }
        }

        // Break if no more pieces fit
        if (best_index == -1)
            break;

        int count = remainder / lengths[best_index];
        int count_value = count * values[best_index];
        total_value += count_value;
        remainder -= count * lengths[best_index];

        printf("%d @ %d = %d\n", count, lengths[best_index], count_value);
    }
    printf("Remainder: %d\n", remainder);
    printf("Value: %d\n", total_value);
}

int main() {
    int rod_length = 0;
    printf("Supplied rod length: ");
    scanf("%d", &rod_length);

    rodCutting(rod_length);

    return 0;
}
