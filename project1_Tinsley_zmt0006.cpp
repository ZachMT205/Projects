/* Zach Tinsley
 * Auburn ID - zmt0006@auburn.edu
 * project1_Tinsley_zmt0006.cpp
 * I did not use any help on this project
 * Compile : g++ project1_Tinsley_zmt0006.cpp
 * Run : ./a.out
 */ 
 
#include <iostream> 
using namespace std; 
 
int main() { 
 // VARIABLE INITIALIZATION 
  float loan;
  float interestRate;
  float interestRateC;
  int monthlyPaid;
  int currentMonth;
  float interestTotal;
        
  
 // CURRENCY FORMATTING 
 cout.setf(ios::fixed); 
 cout.setf(ios::showpoint); 
 cout.precision(2); 
  
 // USER INPUT 
 // NOTE: For valid input, the loan, interest, and monthly payment must 
 // be positive. The monthly payment must also be large enough to 
 // terminate the loan. 
 cout << "\nLoan Amount: "; 
 cin >> loan;
 if (loan <= 0) {
      return 0;
 }
 

 
 
 
 cout << "Interest Rate (% per year): "; 
 cin >> interestRate; 
  if (interestRate <= 0) {
      return 0;
 }
       
 
 
 
 // GET PROPER INTEREST RATES FOR CALCULATIONS 
 interestRate /= 12; 
 interestRateC = interestRate / 100; 
 cout << "Monthly Payments: "; 
 cin >> monthlyPaid; 
 
  
 if (monthlyPaid <= loan * interestRateC) {
      return 0;
 }
   
  
 cout << endl; 
  
 // AMORTIZATION TABLE 
 cout << "*****************************************************************\n" 
      << "\tAmortization Table\n" 
      << "*****************************************************************\n" 
      << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n"; 
 
 // LOOP TO FILL TABLE 
 while (loan > 0) { 
  if (currentMonth == 0) { 
		cout << currentMonth++ << "\t$" << loan; 
  		if (loan < 1000) cout << "\t"; // Formatting MAGIC 
   			cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n"; 
  } 
  else { 
       while (loan > 0) {
		    float tempLoan = loan - (monthlyPaid - (loan * interestRateC));
			float interest = loan * interestRateC;
			float principal = monthlyPaid - interest;
			loan = loan - principal;
			interestTotal = interestTotal + interest;
			if (loan < 0) {
			    cout << currentMonth++ << "\t$0.00" << "\t\t$" << monthlyPaid + tempLoan << "\t" << interestRate << "\t$" << interest << "\t\t$" << monthlyPaid + tempLoan - interest << endl;
				break;
			}
			if (loan > 1000) {
				cout << currentMonth++ << "\t$" << loan << "\t$" << monthlyPaid << "\t" << interestRate << "\t$" << interest << "\t\t$" << principal << endl;
				break;
			}
            cout << currentMonth << "\t$" << loan << "\t\t$" << monthlyPaid << "\t" << interestRate << "\t$" << interest << "\t\t$" << principal << endl;
			currentMonth++;
       }
  }
       
     
   
 } 
 cout << "****************************************************************\n"; 
 cout << "\nIt takes " << --currentMonth << " months to pay off " 
      << "the loan.\n" 
      << "Total interest paid is: $" << interestTotal; 
 cout << endl << endl;  
 return 0; 
} 