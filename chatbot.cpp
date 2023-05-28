#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vec vector
#define loop(i, n) for (int i = 0; i < n; i++)
using namespace std;
vector<pair<regex, string>> rules = {
    {regex("Hi| HELLO"), "How Are You "},
    {regex(".name."), "Omkar "},
    {regex(".Sports."), "Cricket "},
    {regex(".are you doing."), " Well I am fine!!! "}};

string searchreg(string &userInput)
{
    for (auto i : rules)
    {
        if (regex_search(userInput, i.first))
        {
            return i.second;
        }
    }

    return "I am Sorry Unable to Understand You !!";
}
int main()
{
    string userInput;
    std::cout << "Chatbot: Hello! How can I assist you?" << endl;
    while (true)
    {
        std::cout << "User: ";
        cin >> userInput;
        string answer = searchreg(userInput);
        cout << answer << endl;
        if (regex_search(userInput, regex("Exit | exit")))
        {
            break;
        }
    }

    return 0;
}

// #include <iostream>
// #include <regex>
// #include <string>
// #include <vector>
// using namespace std;

// vector<pair<regex, string>> rules = {
//     {regex("hi|hello", regex_constants::icase), "Hello! How can I assist you?"},
//     {regex(".name.", regex_constants::icase), "My name is Chatbot."},
//     {regex(".sports.", regex_constants::icase), "I love Sports !! I like playing Cricket"},
//     {regex(".actor.", regex_constants::icase), "Hrithik Roshan is my Favourite Actor !"},
//     {regex(".created. | .creator.", regex_constants::icase), "Ruturaj Panditrao is my God"},
//     {regex("how.*are.*you", regex_constants::icase), "I'm doing well, thank you!"},
//     {regex("exit", regex_constants::icase), "Goodbye!"},
// };

// string generateResponse(string &userInput)
// {
//     for (const auto &rule : rules)
//     {
//         if (regex_search(userInput, rule.first))
//         {
//             return rule.second;
//         }
//     }
//     return "I'm sorry, I don't understand.";
// }

// int main()
// {
//     string userInput;
//     std::cout << "Chatbot: Hello! How can I assist you?" << std::endl;
//     while (true)
//     {
//         std::cout << "User: ";
//         getline(cin, userInput);
//         string response = generateResponse(userInput);
//         cout << "Chatbot: " << response << std::endl;
//         if (regex_search(userInput, regex("exit", regex_constants::icase)))
//         {
//             break;
//         }
//     }
// }