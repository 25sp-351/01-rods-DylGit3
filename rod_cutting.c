#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIECES 100
#define MAX_LINE 100

typedef struct {
    int length;
    int value;
} Piece;

void read_pieces(int *num_pieces, Piece *pieces) {
    char line_input[MAX_LINE];

    while (fgets(line_input, sizeof(line_input), stdin) != NULL)
        if (sscanf(line_input, "%d, %d", &pieces[*num_pieces].length,
                   &pieces[*num_pieces].value) == 2)
            (*num_pieces)++;
}

void calculate_ratios(Piece *pieces, double *ratios, int num_pieces) {
    for (int ix = 0; ix < num_pieces; ++ix)
        if (pieces[ix].length != 0)
            ratios[ix] = (double)pieces[ix].value / pieces[ix].length;
}

void print_result(Piece *pieces, int *count, int num_pieces, int remainder,
                  int total_value) {
    for (int i = 0; i < num_pieces; ++i)
        if (count[i] > 0)
            printf("%d @ %d = %d\n", count[i], pieces[i].length,
                   count[i] * pieces[i].value);
    printf("Remainder: %d\n", remainder);
    printf("Value: %d\n", total_value);
}

void rod_cut_process(Piece *pieces, int num_pieces, int rod_length) {
    double ratios[MAX_PIECES] = {0.0};
    calculate_ratios(pieces, ratios, num_pieces);

    int remainder = rod_length;
    int total_value = 0;
    int count[MAX_PIECES] = {0};

    while (1) {
        int best_index = -1;
        double best_ratio = 0.0;

        for (int i = 0; i < num_pieces; ++i) {
            if (pieces[i].length <= remainder && ratios[i] > best_ratio) {
                best_ratio = ratios[i];
                best_index = i;
            }
        }

        if (best_index == -1)
            break;  // No more valid cuts

        int num_cuts = remainder / pieces[best_index].length;
        count[best_index] += num_cuts;
        total_value += num_cuts * pieces[best_index].value;
        remainder -= num_cuts * pieces[best_index].length;
    }

    print_result(pieces, count, num_pieces, remainder, total_value);
}

int main(int argc, char *argv[]) {
    int rod_length;
    char rod_input[MAX_LINE];

    if (argc == 2) {
        if (sscanf(argv[1], "%d", &rod_length) != 1 || rod_length < 0)
            fprintf(stderr, "Invalid input. Please enter a valid integer.\n");
    } else {
        while (1) {
            printf("Enter rod length: ");
            if (fgets(rod_input, sizeof(rod_input), stdin) == NULL) {
                printf("\nExiting.\n");
                return 0;
            }
            if (sscanf(rod_input, "%d", &rod_length) == 1 && rod_length >= 0)
                break;
            fprintf(stderr, "Invalid input. Please enter a valid integer.\n");
        }
    }

    Piece pieces[MAX_PIECES];
    int num_pieces = 0;

    read_pieces(&num_pieces, pieces);
    if (num_pieces == 0) {
        fprintf(stderr, "Error: No valid pieces read.\n");
        return 1;
    }

    rod_cut_process(pieces, num_pieces, rod_length);

    return 0;
}
