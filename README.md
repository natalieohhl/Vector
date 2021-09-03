# Vector


When your program runs, it loads all the data from sales.csv and then displays a menu. Menu option 4 is the only way to exit the program. Until the number 4 is entered at the keyboard, the menu will be displayed and the option selected (numeric 1, 2 or 3) will result in the corresponding task being performed by your program.

1. Total Sales in dollars
2. Search by Parts description
3. Search by Company Name
4. Quit

Option 1: Will print the total sales amount in dollars on the screen. It will take into account the unit price and Number of Items for all sales. Only a single number is printed to the screen. (As an example of possible output: $3000)
Option 2: The user is prompted to enter the name of the part using the keyboard. If the part has an entry in the data, the total sales amount for the part is printed to the screen using the following format:

Part Name: Peelers
Total sales:  $146.79

If the part doesn’t exist (e.g. Calculator in this example), the output to screen is:
Part Name: Calculator
Not found.

Option 3: The user is prompted to enter the company name using the keyboard. If the company has an entry in the data, the total sales amount for the company is printed to the screen using the following format:

Company: Turneep Inc
Total Sales: $146.79

If the company doesn’t exist (e.g. IBC in this example), the output to screen is:

Company: IBC
Not found.

Option 4: Exit the program
