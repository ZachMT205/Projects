/* Zach Tinsley
 * Auburn ID - zmt0006@auburn.edu
 * project2_Tinsley_zmt0006.cpp
 * HINTS : I used the project2_hints.pdf file
 *         I also used the zoom recording of Dr. Li going over project2 
 *         and how he recommends implementing each function. 
 * Compile : g++ project2_Tinsley_zmt0006.cpp
 * Run : ./a.out
 */ 
#include <fstream>
#include <iostream> 
#include <stdlib.h> 
#include <assert.h> 
#include <ctime> 
using namespace std; 
/* 
* Input: A_alive indicates Aaron is alive true for alive, false for dead 
*   B_alive indicates Bob is alive 
*   C_alive indicates Charlie is alive 
* Return: true if at least two are alive otherwise return false 
*/ 
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive); 
 
/* 
* Call by reference 
* Strategy 1: Everyone shoots to kill the highest accuracy player alive 
* Input: B_alive indicates Bob is alive or dead 
*  C_alive indicates Aaron is alive or dead 
* Return: Change B_alive into false if Bob is killed 
*    Change C_alive into false if Charlie is killed 
*/ 
void Aaron_shoots1(bool& B_alive, bool& C_alive); 
 
/* 
* Call by reference 
* Input: A_alive indicates Aaron is alive or dead 
*  C_alive indicates Charlie is alive or dead 
* Return: Change A_alive into false if Aaron is killed 
*    Change C_alive into false if Charlie is killed 
*/ 
void Bob_shoots(bool& A_alive, bool& C_alive); 
 
/* 
* Call by reference 
* Input: A_alive indicates Aaron is alive or dead 
*  B_alive indicates Bob is alive or dead 
* Return: Change A_alive into false if Aaron is killed 
*    Change B_alive into false if Bob is killed 
*/ 
void Charlie_shoots(bool& A_alive, bool& B_alive); 
 
/* 
* Call by reference 
* Strategy 2: Aaron intentionally misses if both are alive 
* Input: B_alive indicates Bob is alive or dead 
*  C_alive indicates Aaron is alive or dead 
* Return: Change B_alive into false if Bob is killed 
*    Change C_alive into false if Charlie is killed 
*/ 
void Aaron_shoots2(bool& B_alive, bool& C_alive); 
 
//Simple method to implement pause function in linux 
void Press_any_key(void); 
 
//TEST PROTOTYPES 
void test_at_least_two_alive(void); 
void test_Aaron_shoots1(void); 
void test_Bob_shoots(void); 
void test_Charlie_shoots(void); 
void test_Aaron_shoots2(void); 
 
//VARIABLES 
bool A_alive = true;
bool B_alive = true;
bool C_alive = true;
const int TOTAL_RUNS = 10000;
int aaronWins1 = 0;
int bobWins = 0;
int charlieWins = 0;
const int AARON_SHOOT = 33;
const int BOB_SHOOT = 50;
const int CHARLIE_SHOOT = 100;

 
int main() { 
 //Initializes Random number generator's seed and calls test functions 
 cout << "*** Welcome to Zach's Duel Simulator ***\n"; 
 srand(time(0)); 
 test_at_least_two_alive(); 
 Press_any_key(); 
 test_Aaron_shoots1(); 
 Press_any_key(); 
 test_Bob_shoots(); 
 Press_any_key(); 
 test_Charlie_shoots(); 
 Press_any_key(); 
 test_Aaron_shoots2(); 
 Press_any_key(); 
  
 //Starts strategy 1 and runs 10,000 times 
 cout << "Ready to test strategy 1 (run 10000 times):\n"; 
 Press_any_key(); 
 for (int i = 0; i < TOTAL_RUNS; i++ ){ 
  A_alive = true;
  B_alive = true;
  C_alive = true;
  while (at_least_two_alive(A_alive, B_alive, C_alive)) {  
      if (A_alive == true && at_least_two_alive(A_alive, B_alive, C_alive)) {
          Aaron_shoots1(B_alive, C_alive);
      }
      if (B_alive == true && at_least_two_alive(A_alive, B_alive, C_alive)) {
          Bob_shoots(A_alive, C_alive);
      }
      if (C_alive == true && at_least_two_alive(A_alive, B_alive, C_alive)) {
          Charlie_shoots(A_alive, B_alive);
      }
    } 
   
  if (A_alive == true) {
      aaronWins1++;
  }
  if (B_alive == true) {
      bobWins++;
  } 
  if (C_alive == true) {
      charlieWins++;
  }
 } 
 cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) / 
TOTAL_RUNS * 100 << "%\n" 
      << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS 
* 100 << "%\n" 
      << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / 
TOTAL_RUNS * 100 << "%\n" 
      << endl; 
  
 //Reinitializes variables and starts strategy 2 to run 10,000 times 
 A_alive = true;
 B_alive = true;
 C_alive = true;
 int aaronWins2 = 0;
 bobWins = 0;
 charlieWins = 0;

 cout << "Ready to test strategy 2 (run 10000 times):\n"; 
 Press_any_key(); 
 for (int i = 0; i < TOTAL_RUNS; i++ ){ 
  A_alive = true;
  B_alive = true;
  C_alive = true;
  while (at_least_two_alive(A_alive, B_alive, C_alive)) { 
      if (A_alive == true && at_least_two_alive(A_alive, B_alive, C_alive)) {
          Aaron_shoots2(B_alive, C_alive);
      }
      if (B_alive == true && at_least_two_alive(A_alive, B_alive, C_alive)) {
          Bob_shoots(A_alive, C_alive);
      }
      if (C_alive == true && at_least_two_alive(A_alive, B_alive, C_alive)) {
          Charlie_shoots(A_alive, B_alive);
      }
  } 
  if (A_alive == true)  
    aaronWins2++;
  if (B_alive == true)  
    bobWins++;
  if (C_alive == true)  
    charlieWins++;
 } 
 cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) / 
TOTAL_RUNS * 100 << "%\n" 
      << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS 
* 100 << "%\n" 
      << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / 
TOTAL_RUNS * 100 << "%\n" 
      << endl; 
  
 if (aaronWins1 > aaronWins2) { 
  cout << "Strategy 1 is better than strategy 2.\n"; 
 } 
 else { 
  cout << "Strategy 2 is better than strategy 1.\n"; 
 } 
  
 return 0; 
} 
 
//Implementation of functions. Look above for documentation of them. 
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) { 
    if (A_alive == true && B_alive == true) {
        return true;
    }
    else if (A_alive == true && C_alive == true) {
        return true;
    }
    else if (B_alive == true && C_alive == true) {
        return true;
    }
    else if (B_alive == true && A_alive == true) {
        return true;
    }
    else if (C_alive == true && A_alive == true) {
        return true;
    }
    else if (C_alive == true && B_alive == true) {
        return true;
    }
    else {
        return false;
    }
} 
 
void test_at_least_two_alive(void) { 
    cout << "Unit Testing 1: Function - at_least_two_alive()\n"; 
  
    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n"; 
    assert(true == at_least_two_alive(true, true, true)); 
    cout << "\tCase passed ...\n"; 
  
    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n"; 
    assert(true == at_least_two_alive(false, true, true)); 
    cout << "\tCase passed ...\n";
    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n"; 
    assert(true == at_least_two_alive(true, false, true));  
    cout << "\tCase passed ...\n";
    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n"; 
    assert(true == at_least_two_alive(true, true, false));  
    cout << "\tCase passed ...\n";
    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n"; 
    assert(false == at_least_two_alive(false, false, true)); 
    cout << "\tCase passed ...\n";
    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false)); 
    cout << "\tCase passed ...\n"; 

    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n"; 
    assert(false == at_least_two_alive(true, false, false)); 
    cout << "\tCase passed ...\n"; 
    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n"; 
    assert(false == at_least_two_alive(false, false, false)); 

} 

 
void Aaron_shoots1(bool& B_alive, bool& C_alive) { 
 assert(B_alive == true || C_alive == true); 
 int shootResult1 = rand() % 100; 
 if (shootResult1 <= AARON_SHOOT) {
     if (C_alive == true) {
         C_alive = false;
     }
     else {
         B_alive = false;
     }
 } 
} 
 
void test_Aaron_shoots1(void) { 
 cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n"; 
  
 B_alive = true;
 C_alive = true; 
 cout << "\tCase 1: Bob alive, Charlie alive\n" 
      << "\t\tAaron is shooting at Charlie\n"; 
 Aaron_shoots1(B_alive, C_alive); 
  
 B_alive = false; 
 C_alive = true; 
 cout << "\tCase 2: Bob dead, Charlie alive\n" 
      << "\t\tAaron is shooting at Charlie\n"; 
 Aaron_shoots1(B_alive, C_alive); 
 
 B_alive = true; 
 C_alive = false; 
 cout << "\tCase 3: Bob alive, Charlie dead\n" 
      << "\t\tAaron is shooting at Bob\n"; 
 Aaron_shoots1(B_alive, C_alive); 
} 
 
void Bob_shoots(bool& A_alive, bool& C_alive) { 
 assert(A_alive == true || C_alive == true); 
 int shootResult2 = rand() % 100; 
 if (shootResult2 <= BOB_SHOOT) {
     if (C_alive == true) {
         C_alive = false;
     }
     else {
         A_alive = false;
     }
 }
} 
 
void test_Bob_shoots(void) { 
 cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n"; 
  
 A_alive = true;
 C_alive = true; 
 cout << "\tCase 1: Aaron alive, Charlie alive\n" 
      << "\t\tBob is shooting at Charlie\n"; 
 Bob_shoots(A_alive, C_alive); 
  
 A_alive = false; 
 C_alive = true; 
 cout << "\tCase 2: Aaron dead, Charlie alive\n" 
      << "\t\tBob is shooting at Charlie\n"; 
 Aaron_shoots1(A_alive, C_alive); 
 
 A_alive = true; 
 C_alive = false; 
 cout << "\tCase 3: Aaron alive, Charlie dead\n" 
      << "\t\tBob is shooting at Aaron\n"; 
 Aaron_shoots1(A_alive, C_alive);
  
} 
  
void Charlie_shoots(bool& A_alive, bool& B_alive) { 
 assert(A_alive == true || B_alive == true); 
 int shootResult3 = rand() % 100; 
 if (shootResult3 <= CHARLIE_SHOOT) {
     if (B_alive == true) {
         B_alive = false;
     }
     else {
         A_alive = false;
     }
 }
} 
 
void test_Charlie_shoots(void) { 
 cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Charlie_alive)\n"; 
  
 A_alive = true;
 B_alive = true; 
 cout << "\tCase 1: Aaron alive, Bob alive\n" 
      << "\t\tCharlie is shooting at Bob\n"; 
 Bob_shoots(A_alive, B_alive); 
  
 A_alive = false; 
 B_alive = true; 
 cout << "\tCase 2: Aaron dead, Bob alive\n" 
      << "\t\tCharlie is shooting at Bob\n"; 
 Aaron_shoots1(A_alive, B_alive); 
 
 A_alive = true; 
 B_alive = false; 
 cout << "\tCase 3: Aaron alive, Bob dead\n" 
      << "\t\tCharlie is shooting at Aaron\n"; 
 Aaron_shoots1(A_alive, B_alive);
 } 
 
void Aaron_shoots2(bool& B_alive, bool& C_alive) { 
    if (C_alive && !B_alive) {
        int shootResult4 = rand() % 100;
        if (shootResult4 <= AARON_SHOOT) {
            C_alive = false;
        }
    }
    if (B_alive && !C_alive) {
       int shootResult = rand() % 100;
        if (shootResult <= AARON_SHOOT) {
            B_alive = false;
        } 
    }
    
} 
 
void test_Aaron_shoots2(void) { 
 cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n"; 
  
 B_alive = true;
 C_alive = true; 
 cout << "\tCase 1: Bob alive, Charlie alive\n" 
      << "\t\tAaron intentionally misses his first shot\n"; 
 Aaron_shoots2(B_alive, C_alive); 
 cout << "\tBoth Bob and Charlie are alive.\n";
  
 B_alive = false; 
 C_alive = true; 
 cout << "\tCase 2: Bob dead, Charlie alive\n" 
      << "\t\tAaron is shooting at Charlie\n"; 
 Aaron_shoots2(B_alive, C_alive); 
 
 B_alive = true; 
 C_alive = false; 
 cout << "\tCase 3: Bob alive, Charlie dead\n" 
      << "\t\tAaron is shooting at Bob\n"; 
 Aaron_shoots2(B_alive, C_alive);
} 
 
void Press_any_key(void) { 
 cout << "Press any key to continue..."; 
 cin.ignore().get();  
}