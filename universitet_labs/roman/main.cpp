#include "Word.h"

int main()
{
    vector<Word> vect;
    for (int i = 0; i < 5; i++)
    {
        Word tmp = Word();
        vect.push_back(tmp);
    }

  
    for (int i = 0; i < vect.size(); i++)
    {
        cout << "Word " << i + 1 << ": " << endl;
        vect[i].show();
        cout << endl;
    }

    cout << "Set max number of pages:\n";
    int number;
    cin >> number;

    cout << "Showing you the words which contains more than " << number << " times" << endl;

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i].get_number() > number)
        {
            vect[i].show();
            cout << endl;
        }
    }

    cout << "Set extra word:\n";
    string slowo;
    cin >> slowo;

    cout << "Showing you the page with word " << slowo << endl;

    int counter = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i].get_word() == slowo)
        {   
            vect[i].show();
            cout << endl;
            counter++;
        }
        
    }

    if (counter == 0)
    {
        cout << "Word is not found \n";
    }

    for (size_t i = 0; i < vect.size(); i++)
    {
        for (size_t i = 0; i < vect.size() - 1; i++)
        {
            if (vect[i].get_word() > vect[i+1].get_word()) //если одно больше второго
            {
                swap(vect[i], vect[i+1]); //пузырьковая сортировка (меняем местами 2 штуки)
            }
        }
    }

    for (size_t i = 0; i < vect.size(); i++)
    {
        cout << vect[i].get_word() << ' '; //вывод на экран собственно только слов
    }
    cout << endl;
    
}