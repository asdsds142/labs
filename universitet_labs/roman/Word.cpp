#include "Word.h"

Word::Word()
{
    cout << "Enter the word you want to search.";
    cin >> word;
    cout << "how many times does this word appear in the text.";
    int number;
    cin >> number;
    for (int i = 0; i < number; ++i)
    {
        pages.push_back((rand() % 10) + 1);
    }
}

Word::Word(string a, int number)
{
    word = a;
    for (int i = 0; i < number; ++i)
    {
        pages.push_back((rand() % 10) + 1);
    }
}

string Word::get_word()
{
    return word;
}

int Word::get_number()
{
    return pages.size();
}

vector<int> Word::get_pages()
{
    return pages;
}

void Word::set_word(string tmp_word)
{
    word = tmp_word;
}

void Word::show()
{
    cout << "Your word - " << word << ".\n";
    cout << "Page numbers - ";
    for (int i = 0; i < pages.size(); ++i)
    {
        cout << pages[i] << " ";
    }
    cout << ".\n";
}