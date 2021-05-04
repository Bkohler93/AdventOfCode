#include <iostream>
#include <string>

using namespace std;


/* lower char is 'F' for rows and 'L' for columns (take lower half if this char is present) */
int get_binary_partition(char lower_char, int up_bound, int lo_bound, string pass) {

    int length = pass.length();
    int mp;

    for (int i = 0; i < length; ++i) {
        mp = (up_bound - lo_bound) / 2;

        if (pass[i] == lower_char)
            up_bound -= (mp + 1);
        else lo_bound += (mp + 1);
    }

    return lo_bound;
}

int main () {
    int col = get_binary_partition('L', 7, 0, "RLR");
    int row = get_binary_partition('F', 127, 0, "FBFBBFF");
    printf("FBFBBFFRLR is row %d and col is %d\n", row, col);
    string example = "FBFBBFF";
    string column_example = "RLR";

    return 0;
}