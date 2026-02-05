
/*17)Потребителят въвежда текст в конзолата. Трябва да се
 *намери разликата между най-дългата и най-късата дума
 *и да се изведе число.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text;
    cout << "Write some text: ";
    getline(cin, text);

    int min_len = 100000;
    int max_len = 0;
    int current_len = 0;

    for (int i = 0; i <= text.length(); i++)
    {
        if (i < text.length() && text[i] != ' ')
        {
            current_len++;
        }
        else
        {
            if (current_len > 0)
            {
                if (current_len < min_len)
                    min_len = current_len;

                if (current_len > max_len)
                    max_len = current_len;
            }
            current_len = 0;
        }
    }
    cout << "Longest word = " << max_len << endl;
    cout << "Shortest word = " << min_len << endl;
    cout << "Difference = " << max_len - min_len << endl;
}
