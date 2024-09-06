## README
NOTE :I HAVE TAKEN REFERENCE FROM CHAT GPT

## README

### Overview

This C++ application is designed to estimate the selling price of an asset and compute the long-term capital gains tax (LTCG). It leverages historical inflation and price growth data to calculate these values. The application assumes that you have a CSV file with historical data and provides a user-friendly interface for inputting necessary parameters.

### Components

1. **`InflationInfo` Class**
   - **Purpose:** Manages inflation and price growth data.
   - **Data Storage:** Uses arrays to store years, inflation rates, and price growth rates.
   - **Functionality:** Reads data from a CSV file and populates the arrays. It handles errors like missing data and invalid formats gracefully.

2. **`CapitalGainsCalculator` Class**
   - **Purpose:** Computes the estimated selling price and LTCG.
   - **Parameters:** Takes the initial cost, purchase year, and sale year as inputs.
   - **Methods:**
     - `computeSellingPrice`: Calculates the adjusted selling price by applying yearly price growth rates and inflation adjustments.
     - `computeLTCG`: Computes the LTCG based on the profit (selling price minus initial cost) and applies a 20% tax rate on positive profits.

### How It Works

1. **CSV Data Format:**
   - Ensure the CSV file `price-inflation.csv` contains the following columns:
     - Year (e.g., 2010, 2011)
     - Price Growth Rate (e.g., 2.5 for 2.5%)
     - Inflation Rate (e.g., 1.5 for 1.5%)

2. **Loading Data:**
   - The program skips the header row of the CSV file.
   - It processes each subsequent row, converting values from strings to numerical data while handling potential conversion errors.

3. **User Interaction:**
   - The user is prompted to enter the year of sale.
   - The application calculates the estimated selling price based on the provided year of sale and fixed initial cost and purchase year.
   - It computes the LTCG based on the profit from selling price and initial cost.

4. **Output:**
   - Displays the estimated selling price and LTCG on the console.

### Steps to Run

1. **Prepare the CSV File:**
   - Create a CSV file named `price-inflation.csv` with the required columns and data.
   - Place the CSV file in the same directory as the compiled executable.

2. **Compile the Program:**
   - Use a C++ compiler to compile the source code into an executable.

3. **Run the Executable:**
   - Execute the compiled program.
   - Enter the year of sale when prompted.

4. **View Results:**
   - The estimated selling price and LTCG will be displayed on the console.

### Error Handling

- **File Opening Errors:** If the CSV file cannot be opened, an error message will be displayed.
- **Invalid Data:** The program will skip rows with missing or invalid data and provide warnings.
- **Conversion Errors:** Errors during data conversion will be caught, and problematic rows will be skipped.

### Example Usage

To use the program, follow these steps:
1. Ensure `price-inflation.csv` is in the same directory as the executable.
2. Compile the code with a C++ compiler.
3. Run the program, enter the desired year of sale, and review the results provided.

Feel free to modify the initial cost and purchase year within the code as needed for different scenarios.
