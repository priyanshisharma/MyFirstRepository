//Below is the code for Turing Machine that accepts
// the language L = {0(1^n)0 n>=1 , {0,1}*}

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int tapehead = 1;
string state = "A";
vector<char> tape;

//The function for each transition
bool action(char input_char, char replace_with, char move, string new_state)
{
    if (tape[tapehead] == input_char)
    {
        tape[tapehead] = replace_with;
        state = new_state;
            if (move == 'L')
            {
                tapehead -= 1;
            }
            else
            {
                tapehead += 1;
            }

            return true;

    }
    return false;
}

int main()
{
    int t; //number of testcases
    cout<<"Enter total number of strings to be checked ";
    cin>>t;

    while(t--)
    {
        string str; //input string
        cout<<"Enter String ";
        cin>>str;

        int length = str.length() + 2; //for tape length
        tape.resize(length,'_');

        //writing input string on tape
        for(int i=1; i<=str.length(); i++)
        {
            tape[i] = str[i-1];
        }

        //assigning variables for requisite characters
        char zero = '0', one = '1', X='X', Y='Y', blank='_', R='R', L='L';

        int oldtapehead = -1;
        bool accept = false;

        //Running the turing machine
        while(oldtapehead != tapehead)
        {
            oldtapehead = tapehead;

            //Printing current state
            cout<<"The tape looks like ";
            for(int c=0; c<tape.size(); c++)
            {
                cout<<tape[c]<<" , ";
            }
            cout<<"with tapehead at index "<<tapehead<<" on state "<<state<<endl;

            //Transitioning to ubsequent state according to the language
            if(state=="A")
            {
                if (action(zero, X, R, "B"))    //acceptable transition to next state
                    continue;
                else if (action(one,one,R,"REJECT") || action(blank, blank,R,"REJECT")) //transition to reject state
                    break;
            }
            else if (state == "B")
            {
                if (action(one, Y, R, "B") || action(zero, X, R, "C")) //acceptable transition to next state
                    continue;
                else if (action(blank, blank,R,"REJECT")) //transition to reject state
                    break;
            }
            else if (state == "C")
            {
                if (action(blank, blank, R, "ACCEPT")) //acceptable transition to next state
                    continue;
                else if (action(one,one,R,"REJECT") || action(zero,zero,R,"REJECT")) //transition to reject state
                    break;
            }
            else
                accept = true; //when in ACCEPT state
        }


        if (accept)
            cout<<endl<<"String accepted by the language L = {0(1^n)0 n>=1 , {0,1}*}"<<endl;
        else
            cout<<endl<<"String not accepted by the language L = {0(1^n)0 n>=1 , {0,1}*}"<<endl;

        //Resetting the variables for the next string
        tapehead = 1;
        state = "A";
        tape.clear();

    }

    return 0;
}
