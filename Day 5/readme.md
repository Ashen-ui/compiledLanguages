# Light Payment Manager
A currently working textual application to write and save all your payments

## Features
- Add a payment (description, Amount, Category and date)
- Remove a payment
- Filter by categories (case insensitive)
- Calculate totals by categories
- Saved in a CSV file inside saves folder

## Compiling and Starting
- For Linux Distros :
  1. You need to install Make : `sudo apt install make`
  2. Run "make" from the projects root folder to build by typing : `make`
  3. Run the app after building: `./PM`

- For Windows users 
  1. The steps are the same but you'll need a compiler like gcc.
  2. For this you'll need to either install WSL or use an online compiler
  3. Rest of the steps are the same as for Linux Distros

The Project compiles without warnings from -Wall -Wextra.

## Clearing build
- If you want to clear the built files like "PM" or any .o files
  Run: `make clean`