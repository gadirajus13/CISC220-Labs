#include <vector>
#include <deque>
#include <list>
#include <iostream>
using namespace std;
//Nicholas Fafel and Sohan Gadiraju

int main() {
    string clueString;
    cout << "Please enter your clue for the jumbled sequence in the following format, [n, +, +, -, -]:" << endl;
    getline(cin, clueString);

    vector<char> clueVector;
    deque<int> numbersDeque;
    list<int> solution;

    /* The following block of code parses the user input clue and fills a vector with the individual 
     * clue operations such that the vector matches the whole user clue. The following code also fills a deque
     * with the numbers 0, 1, 2, ... x, where x is one less than the length of the user clue vector. The numbers 0, 1,
     * 2, ... x are the numbers that will be used in the solution. */
    int num = 0;
    for (int i = 0; i<clueString.size(); i++) {
        char c = clueString.at(i);
        if (c == 'n' || c == '+' || c == '-') {
            clueVector.push_back(c);
            numbersDeque.push_back(num);
            num++;
        }
    }

    //The following block of code determines a solution corresponding to the given clue, and uses a list to store the solution.
    char currentOperator;
    for (int i = clueVector.size()-1; i>=0; i--) {
        currentOperator = clueVector.at(i);
        if (currentOperator == '-') { //If the current symbol is '-', we want to push the smallest remaining number in the deque to the front of the solution list.
            solution.push_front(numbersDeque.front());
            numbersDeque.pop_front();
        } else { //If the current symbol is '+' or 'n', we want to push the largest remaining number in the deque to the front of the solution list.
            solution.push_front(numbersDeque.back());
            numbersDeque.pop_back();
        }
    }

    //The following block of code prints out the solution list.
    list<int>::iterator it, end; 
    cout << "[";
    for (it=solution.begin(), end=solution.end(), end--; it!=end; it++) {
        cout << *it << ", ";
    }
    cout << solution.back() << "]" << endl;
}