#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

const int MAX_YEARS = 100; // Maximum number of years the data can handle

// Class to manage inflation data using arrays
class InflationInfo {
public:
    int years[MAX_YEARS];
    double inflationRates[MAX_YEARS];
    double priceGrowths[MAX_YEARS];
    int dataCount;

    InflationInfo() : dataCount(0) {}

    void loadCSV(const string &filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error: Could not open the file!" << endl;
            return;
        }

        string line;
        getline(file, line); // Skip the header

        int rowNumber = 1; // Track row numbers for better error reporting

        while (getline(file, line) && dataCount < MAX_YEARS) {
            rowNumber++;
            stringstream ss(line);
            string yearStr, growthStr, inflationStr;

            getline(ss, yearStr, ',');
            getline(ss, growthStr, ',');
            getline(ss, inflationStr, ',');

            cout<<growthStr<<endl;
            cout<<inflationStr<<endl;

            try {
                // Check if any value is empty or invalid before conversion
                if (!yearStr.empty() && !growthStr.empty() && !inflationStr.empty()) {
                    // Debugging output to show the row contents
                    cout << "Processing row " << rowNumber << ": " << yearStr << ", " << growthStr << ", " << inflationStr << endl;
                    
                    years[dataCount] = stoi(yearStr.substr(0, 4)); // Extract the year
                    inflationRates[dataCount] = stod(inflationStr); // Extract inflation rate
                    priceGrowths[dataCount] = stod(growthStr); // Extract price growth rate
                    dataCount++;
                } else {
                    cout << "Warning: Skipping invalid data at row " << rowNumber << ": " << line << endl;
                }
            } catch (const invalid_argument &e) {
                // Handle invalid argument exception
                cout << "Error: Invalid data at row " << rowNumber << ": " << line << ". Skipping this row." << endl;
            } catch (const out_of_range &e) {
                // Handle out of range exception if the number is too large for the data type
                cout << "Error: Out of range data at row " << rowNumber << ": " << line << ". Skipping this row." << endl;
            }
        }

        file.close();
    }
};

// Class to calculate selling price and long-term capital gains (LTCG) using arrays
class CapitalGainsCalculator {
public:
    double initialCost;
    int purchaseYear;
    int saleYear;

    CapitalGainsCalculator(double price, int pYear, int sYear)
        : initialCost(price), purchaseYear(pYear), saleYear(sYear) {}

    // Calculate the selling price based on yearly inflation and growth rates stored in arrays
    double computeSellingPrice(int years[], double inflationRates[], double priceGrowths[], int size) {
        double finalPrice = initialCost;

        for (int i = 0; i < size; i++) {
            if (years[i] > purchaseYear && years[i] <= saleYear) {
                double adjustmentFactor = 1 + ((priceGrowths[i]) / 100.0);
                cout << "Growth Factor for " << years[i] << ": " << adjustmentFactor << endl;
                finalPrice *= adjustmentFactor;
            }
        }
        return finalPrice;
    }

     double computeSellingPrice_OLD(int years[], double inflationRates[], double priceGrowths[], int size) {
        double finalPrice = initialCost;

        for (int i = 0; i < size; i++) {
            if (years[i] > purchaseYear && years[i] <= saleYear) {
                double adjustmentFactor = 1 + ((priceGrowths[i] - inflationRates[i]) / 100.0);
                cout << "Growth Factor for " << years[i] << ": " << adjustmentFactor << endl;
                finalPrice *= adjustmentFactor;
            }
        }
        return finalPrice;
    }

    // Calculate the long-term capital gains tax (LTCG)
    double computeLTCG(double sellingPrice) {
        double profit = sellingPrice - initialCost;
        return profit > 0 ? 0.125 * profit : 0;  // Taxed at 20%
    }

     double computeLTCG_OLD(double sellingPrice) {
        double profit = sellingPrice - initialCost;
        return profit > 0 ? 0.2 * profit : 0;  // Taxed at 20%
    }
};

int main() {
    string filepath;
    int yearOfSale;
    double originalPrice = 50.0;  // Price in lakhs
    int yearOfPurchase = 2010;

    // Input file path and sale year
    cout << "Enter the year of sale: ";
    cin >> yearOfSale;

    // Load inflation data into arrays
    InflationInfo inflationData;
    inflationData.loadCSV("price-inflation.csv");

    // Calculate selling price and tax using arrays
    CapitalGainsCalculator calculator(originalPrice, yearOfPurchase, yearOfSale);
    double estimatedSellingPrice = calculator.computeSellingPrice(inflationData.years, inflationData.inflationRates, inflationData.priceGrowths, inflationData.dataCount);
    double tax = calculator.computeLTCG(estimatedSellingPrice);

    double OldSellingPrice = calculator.computeSellingPrice_OLD(inflationData.years, inflationData.inflationRates, inflationData.priceGrowths, inflationData.dataCount);
    double Oldtax = calculator.computeLTCG_OLD(OldSellingPrice);


    cout << "Estimated Selling Price: Rs " << estimatedSellingPrice << " lakhs" << endl;
    cout << "Long-term Capital Gains Tax (LTCG): Rs " << tax << " lakhs" << endl;

    double diff = Oldtax - tax;

    if(diff>0){
        cout<<"Old tax is higher by new tax with a difference of "<<diff<<endl;
    }
    else if(diff<0){
        cout<<"New tax is higher by old tax with a difference of "<<(-diff)<<endl;
    }
    else{
        cout<<"Both tax rates are same"<<endl;
    }
    

    return 0;
}
