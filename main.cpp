#include "stack.hpp"
#include "binary.hpp"
#include <stdexcept>
#include <vector>
using namespace std;


int main()
{
    string query;
    vector<string> buf;
    vector<string>::iterator itt;
    cout<<"?"<<endl;

        while ((cin.peek() != '\n')) {
            cin >> query;
            buf.push_back(query);
        }

    Digit number1 = 0;
    Digit number2 = 0;
    Digit result = 0;
    Stack<int> test;

    try {

        for (itt = buf.begin(); itt!=buf.end(); ++itt)
        {
            if ((*itt) != "+" && (*itt) != "-" && (*itt) != "*")
            {
                if ((stoi(*itt) > pow(2,SIZE-1)-1) || ((stoi(*itt)) < -pow(2,SIZE-1))) throw runtime_error("Invalid values");
                else
                {
                    Digit forPrint = stoi(*itt);
                    forPrint.printValues();
                    test.push(stoi(*itt));
                }
            }

            else {

                number1 = test.pop();
                number2 = test.pop();

                if ((*itt) == "+")
                    result = number1.binSum(&number2);

                else if ((*itt) == "-")
                    result = number2.binSubstr(&number1);

                else  if ((*itt) == "*")
                    result = number2.binMultip(&number1);

                else throw -1;
                
                 test.push(result.getDec());

            }
        }
        result.printResult();

    } catch (const std::exception&error) {
        cout<<error.what()<<" error occured\nTry again \n";

    }
    return 0;
}


