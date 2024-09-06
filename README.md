
How It Works
Data File:

The CSV file named price-inflation.csv should contain the following columns:
Year
Price Growth Rate
Inflation Rate
Loading Data:

The loadCSV() method reads the CSV file, skipping the header row and parsing each line to fill the arrays. It includes error handling for invalid or missing data.
Calculations:

The computeSellingPrice() method calculates the selling price based on price growth rates alone.
The computeSellingPrice_OLD() method calculates the selling price considering both inflation and price growth.
The computeLTCG() method computes the tax using the new selling price method.
The computeLTCG_OLD() method computes the tax using the old selling price method.
Comparison:

The program calculates and compares the LTCG from both methods, reporting the differences.
Steps to Run
Prepare the CSV File:

Ensure the price-inflation.csv file is properly formatted and located in the same directory as the compiled executable.
Compile the Program:

Use a C++ compiler to compile the source code into an executable.
Run the Executable:

Execute the compiled program.
When prompted, enter the year of sale.
View Results:

The program displays the estimated selling price and LTCG based on both methods.
It also shows the difference in tax calculations between the old and new methods
