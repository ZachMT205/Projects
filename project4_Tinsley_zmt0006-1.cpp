/*
* Zach Tinsley
* Auburn ID - zmt0006@auburn.edu
* project4_Tinsley_zmt0006.cpp
* HINTS :
*   Project4_hints.pdf
*   I used the zoom lecture of Dr. Li going over how to implement each function
*   I googled how to use the toLower() function for user input - https://cplusplus.com/forum/general/28440/
*   I used https://www.w3schools.com/cpp/cpp_do_while_loop.asp to refresh on do-while loops to replace while
*   I used https://cplusplus.com/doc/tutorial/pointers/ to further understand pointers and how they work
*   I used https://cplusplus.com/reference/string/string/compare/ to learn how to use .compare for user input
*   I used https://www.youtube.com/watch?v=ue2pNcRArdU to locate and fix segmentation fault
*   I used https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus to use cin.ignore() because 
*       program was skipping a line when entering an answer to question
*   I used https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/ to further understand how to
*       implement single linked lists
* Compile : g++ project4_Tinsley_zmt0006.cpp
* Run : ./a.out
*/

//Libary imports.
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <climits>
#include <assert.h>
using namespace std;

//Structure for creating a linked list that holds a trivia question,answer and point amount.
struct triva_node {
    string question;
    string answer;
    int point;
    triva_node *next;
};

//creates a pointer to triva_node.
typedef triva_node* ptr_node;

//Variables
int numberQuestions = 0;
//Prototypes
void init_question_list(ptr_node& q_list);
void add_question(ptr_node& q_list);
int ask_question(ptr_node q_list, int num_ask);
void Unit_Test();

//creates two versions.
//#define UNIT_TESTING
#define triva_quiz

int main() {
    Unit_Test();
    numberQuestions = 0;
    ptr_node node_list = new triva_node;
#ifdef triva_quiz
    
    
    //Creates a new trivia game /
    //Sets up three original questions/
    //Sets up loop for user to input his or her own questions.
    //Quiz questions are stored in linked list.
    
    init_question_list(node_list);
    cout << endl;
    cout << endl;
    cout << "*** Welcome to Zach's trivia quiz game ***\n";
    string input;
	do {
		add_question(node_list);
		cout << "Continue? (Y/N): ";
		getline(cin, input);
	} while (input.compare("Y") == 0 || input.compare("y") == 0);
	cout << endl;
    


    //This is start of Trivia quiz game.
    ask_question(node_list, numberQuestions);
    cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***";
    return 0;
}
#endif

//Method for testing
#ifdef UNIT_TESTING
    Unit_Test();
    return 0;
}
#endif

//initializes the quiz to have these three questions inputted into the linked list.
void init_question_list(ptr_node& q_list) {
    //ptr_node cur_ptr;
    //ptr_node cur_ptr;
    //string bob;
    ptr_node cur_ptr = new triva_node;
    cur_ptr->question = " How long was the shortest war on record? (Hint: how many minutes)";
    cur_ptr->answer = "38";
    cur_ptr->point = 100;
    cur_ptr->next = new triva_node;
    q_list = cur_ptr;
    cur_ptr = q_list->next;
    
    cur_ptr->question = "What was Bank of America’s original name? (Hint: Bank of Italy or Bank of Germany)";
    cur_ptr->answer = "Bank of Italy";
    cur_ptr->point = 50;
    cur_ptr->next = new triva_node;
    cur_ptr = cur_ptr->next;

    cur_ptr->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
    cur_ptr->answer = "Wii Sports";
    cur_ptr->point = 20;
    cur_ptr->next = NULL;
    numberQuestions += 3;
}
//gives user the option to add a question to the linked list.
//question is added to the front of the linked list.
void add_question(ptr_node& q_list) {
    //string answer;
    //gets data from user.
    ptr_node new_ptr = new triva_node;
    cout << "Enter a new question: ";
    getline(cin, new_ptr->question);
    cout << "Enter an answer: ";
    getline(cin, new_ptr->answer);
	cout << "Enter award points: ";
	cin >> new_ptr->point;
    cin.ignore();
    new_ptr->next = NULL;
    // Add to the end of the list
	triva_node* end = q_list;
	while (end->next != NULL) {
		end = end->next;
	}
	end->next = new_ptr;
    numberQuestions++;
}
//Checks for null value
//Ask the user trivia questions and starts the game
int ask_question(ptr_node q_list, int num_ask) {
    ptr_node cur_ptr = q_list;
    int rewards = 0;
    string user_answer;
    if (q_list == NULL)
        return 0;
    if(num_ask < 1) {
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
    }
    else if(numberQuestions < num_ask) {
        cout << "Warning - There is only " << numberQuestions << " trivia in the list.";
    }
    
    else {
        for(int x = 0; x < num_ask; x++) {

            cout << "Question: " << cur_ptr->question << endl;
            cout << "Answer: ";
            getline(cin, user_answer);
            if (user_answer.compare(cur_ptr->answer) == 0) {//correct_answer) {
                rewards += cur_ptr->point;
                cout << "Your answer is correct. You receive " << cur_ptr->point << " points.";
                cout << endl;
                cout << "Your total points: " << rewards << endl;
                cout << endl;
                cur_ptr = cur_ptr->next;
                
            }
            else {
                cout << "Your answer is wrong. The correct answer is " << cur_ptr->answer << endl;
                cout << "Your total points: " << rewards << endl;
                cout << endl;
                cur_ptr = cur_ptr->next;
                
            }
            
        
        }
        
        
    }
    
    return 0;

}

//Test cases to check whether the methods work.
void Unit_Test() {
    cout << "*** This is a debugging version ***\n";
	ptr_node node_list = new triva_node;
	init_question_list(node_list);
	cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
	ask_question(node_list, 0);
	cout << "Case 1 passed\n\n";
	cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
	ask_question(node_list,1);
	cout << "Case 2.1 passed\n\n";
	cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
	ask_question(node_list,1);
	cout << "Case 2.2 passed\n\n";
	cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
	ask_question(node_list,3);
	cout << "Case 3 passed\n\n";
	cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
	ask_question(node_list,5);
    cout << endl;
	cout << "Case 4 passed\n\n";
	cout << "*** End of the Debugging Version ***";
}





