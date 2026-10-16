// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <string>


int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_number
  //  variable, and its position in the declaration. It must always be directly before the variable used for input.
  //  You must notify the user if they entered too much data.

  const std::string account_number = "CharlieBrown42";
  char user_input[20];

  while (true) {
	std::cout << "Enter a value: ";

	// Read input first to check length
	std::string temp;
	std::cin >> temp;


	// Check if length is too long, notify user if too long and force user to input again
	if (temp.size() >= sizeof(user_input)) {
		std::cout << "Error: Input length too long. Buffer overflow attempt detected.\n";
		std::cout << " Please try again.\n\n";
		continue;
	}

	// Safe copy into fixed size buffer
	strncpy_s(user_input, temp.c_str(), sizeof(user_input) - 1);
	user_input[sizeof(user_input) - 1] = '\0';

	break;
	
  }

  std::cout << "You entered: " << user_input << std::endl;
  std::cout << "Account Number = " << account_number << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
