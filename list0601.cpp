// Listing 6-1. Deliberate Errors

// error: misspelt
// #include <iosteam>
#include <iostream>

// Look for errors
int main()

// error: bogus character
// [
{

  // error: unknown operator - doesn't use a double <
  //std::cout < "This program prints a table of squares.\n";
  std::cout << "This program prints a table of squares.\n";

  // error: doesn't assign string to a variable
  //       "Enter the starting value for the table: ";

  int start{0};
  std::cin >> start;
  std::cout << "Enter the ending value for the table: ";
  int end(start);

  // error: Unknown name
  // std::cin << endl
  std::cin >> end;


  std::cout << "#   #^2\n";
  int x{start};
  end = end + 1; // exit loop when x reaches end 
  while (x != end)
  {
    // error: Symbol error, requires double colon
    //std:cout << x << "   " << x*x << "\n";
    std::cout << x << "   " << x*x << "\n";


    x = x + 1;
  }

  return 0;
}
