

#include <iostream> 
using namespace std; 
  
// Function to check if a number is palindrome or not 
bool isPalindrome(int num) 
{ 
    // Find the appropriate divisor 
    // to extract the leading digit 
    int divisor = 1; 
    while (num / divisor >= 10) 
        divisor *= 10; 
  
    while (num != 0) { 
        int leading = num / divisor;   // Extract leading digit of num 
        int trailing = num % 10;      // Extract trailing digit of num 

        // If first and last digit not same return false 
        if (leading != trailing)   return false;  

        // Removing the leading and trailing digit from number 
        num = (num % divisor) / 10;  

        // Reducing divisor by a factor of 2 as 2 digits are dropped.    		divisor = divisor / 100;  	}

    return true;  	// Number is palindrome in case of single digit numbers.     }

    int main() {    	int n = 121;    	if (isPalindrome(n))         cout << "Yes";    	else         cout << "No";    	return 0; }