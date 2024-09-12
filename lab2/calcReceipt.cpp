#include <cstdlib>  // for exit
#include <fstream>  // for ifstream
#include <string>   // for getline, stoi
#include <iomanip>  // for setw and setfill
#include <iostream> // for cout
#include "vec.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " order_file.csv" << endl;
        exit(1);
    }

    ifstream ifs(argv[1]);
    if (!ifs.is_open()) {
        cout << "Error: Could not open file " << argv[1] << endl;
        return 1;
    }

    Vec prices;
    string line;
    while (getline(ifs, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != string::npos) {
            string priceStr = line.substr(commaPos + 1);  // Extract the price part
            int price = stoi(priceStr);  // Convert to integer (cents)
            prices.push_back(price);
        }
    }

    prices.sort();  // Sort the prices

    // Print the sorted prices
    for (int i = 0; i < prices.size(); ++i) {
        int dollars = prices.at(i) / 100;
        int cents = prices.at(i) % 100;
        cout << "$" << dollars << "." << setw(2) << setfill('0') << cents << endl;
    }

    // Calculate and print the total
    int total = 0;
    for (int i = 0; i < prices.size(); ++i) {
        total += prices.at(i);
    }
    cout << "------" << endl;
    cout << "$" << total / 100 << "." << setw(2) << setfill('0') << total % 100 << endl;

    return 0;
}
