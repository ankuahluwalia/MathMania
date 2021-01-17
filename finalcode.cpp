 
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
 
 
 
void mp_RNG(vector<int>& math_num) {
   for (unsigned int i = 0; i < math_num.size(); ++i) {
       math_num.at(i) = (rand() % 20) + 1;
   }
}
 
void menu() {
   cout << "MENU" << endl;
}
 
void StoreAnswers(vector<double>& answer, vector<int>& math_num) {
   int calculation = 0;
   calculation = math_num.at(0) + math_num.at(1);
   answer.push_back(calculation);
   int sum = 0;
   for (unsigned int i =0; i < math_num.size(); ++i) {
       sum += math_num.at(i);
   }
   double average = (1.0 * sum) / math_num.size();
   answer.push_back(average);
 
   calculation = math_num.at(0) + (math_num.at(3) * (math_num.at(1) - math_num.at(2))) + math_num.at(4);
   answer.push_back(calculation);
   //add other other answers
}
 
string math_check(const vector<double>& answer, double& user_num, int& counter) {
   if (user_num == answer.at(counter - 1)) {
       return "Great job! You got it right!";
   }
   else {
       return "Aww. The Math Monster tricked you.";
   }
}
 
void math_p(int& level, vector<int>& math_num) { //math problem
 
   if (level == 1){
       cout << "What's " << math_num.at(0) << " + " << math_num.at(1) << "?" << endl;
  
       cout << endl;
       ++level;
   }
   else if (level == 2) {
       cout << "What's the mean of these numbers? ";
       for (unsigned int i = 0; i < math_num.size(); ++i) {
           cout << math_num.at(i) << " ";
       }
       cout << endl;
       ++level;
   }
   else if (level == 3) {
       cout << "Solve " << math_num.at(0) << " + (" << math_num.at(1) << " - " << math_num.at(2) << ") * " << math_num.at(3) << " + " << math_num.at(4) << endl;
   }
}
 
 
 
int main() {
 
   srand(time(0));
 
   string user_input;
   char user_hint;
 
 
   double user_num;
   int level;
   int counter = 0;
   int score;
 
   vector<double> answer; //correct answer
   vector<int> math_num(5);
   vector<string> hints(3);
   hints.at(0) = "HINT: Use your calculator or google.";
   hints.at(1) = "HINT: mean = average, sum / 5.";
   hints.at(2) = "HINT: PEMDAS";
 
   system("clear");
   cout << "Pick a level (1-3). 1-easiest, 3-hardest. ";
   cin >> level;
   counter = level - 1;
   score = level - 1;
   cout << "OH NO, a Math Monster has appeared!" << endl;
 
   while (user_input != "n") {
 
       cout << "----------------" << endl;
       cout << "|     ^V^      |" << endl;
       cout << "|   ~O~ ~O~    |" << endl;;
       cout << "|     _|_      |" << endl;
       cout << "|   _// \\\\_    |" << endl;
       cout << "|   vvvvvvv    |" << endl;
       cout << "----------------" << endl;
       cout << endl;
 
       answer.clear();
       //system("clear");
       user_input = " ";
 
       mp_RNG(math_num); //randomly generates num values
       math_p(level, math_num);
       StoreAnswers(answer, math_num);
 
       counter++;
       //cout << counter << endl;
       cin >> user_num;
 
      
       while (math_check(answer, user_num, counter) == "Aww. The Math Monster tricked you.") {
           cout << "Your attack missed! Would you like a potion to defeat the Math Monster? :(" << endl;
           cout << "Would you like a hint? (y/n)" << endl;
           cin >> user_hint;
          
           if (user_hint == 'y') {
               cout << hints.at(counter - 1) << endl;
           }
           cout << "Try again: ";
           cin >> user_num;
       }
       if (math_check(answer, user_num, counter) == "Great job! You got it right!"){
           cout << "You landed a hit on the Math Monster! :)" << endl;
           score++;
       }
       /*
       for (unsigned int i = 0; i < answer.size(); ++i) {
           cout << answer.at(i) << " ";
       }
 
       cout << endl;
       cout << counter << endl;*/
      
 
       if (counter < 3) {
           user_input = " ";
           cout << endl << "Would you like to continue? (y/n) ";
           cin >> user_input;
           cout << endl;
       }
       else {
           user_input = "n";
       }
   }
  
   if (score == 3) {
       cout << "----------------" << endl;
       cout << "|     ^V^      |" << endl;
       cout << "|   ~X~ ~X~    |" << endl;;
       cout << "|     _|_      |" << endl;
       cout << "|   _// \\\\_    |" << endl;
       cout << "|   vvvvvvv    |" << endl;
       cout << "----------------" << endl;
       cout << endl;
       cout << endl << "Good job! You defeated the Math Monster!" << endl;
   }
   else {
       cout << endl << "Aww the Math Monster tricked you! Try again next time!" << endl;
   }
 
   return 0;
}
