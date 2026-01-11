
//ENCRYPTION DECRYPTION PROGRAM
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char encrypted_data[] = 
{
    'q','7','A','m','2','Z','e','9','K','b','X','0','r',
    'C','5','t','H','1','W','d','8','P','Y','4','s','F'
};

char decrypted_data[] = 
{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
'h', 'i', 'j', 'k', 'l', 'm' ,'n', 
'o', 'p', 'q', 'r', 's', 't', 'u',
'v', 'w', 'x', 'y', 'z' };

const int MAX_SIZE = sizeof(encrypted_data);

// sizeof will return the total number of
// characters in array

int get_index(char arr[], char x)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

string encryption(string s)
{
    int index;
    for (int i = 0; i < s.size(); i++)
    {
        index = get_index(decrypted_data, s[i]);
        if (index >= 0)
        {
            s[i] = encrypted_data[index];
        }
    }
    return s;
}


int main()
{
    cout << "Size: " << MAX_SIZE << endl;
    
    string text;
    cout << "Enter text to encrypt: ";
    getline(cin, text);
    
    string encrypted_text = encryption(text);
    cout << "Encrypted text: " << encrypted_text << endl;

    return 0;
}
