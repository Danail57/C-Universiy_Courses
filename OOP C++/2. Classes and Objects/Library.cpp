/*Задача 1. Да се състави програма, която съхранява
 *в масив следните данни за книгите в една библиотека:
 *- инвентарен номер - низ до 6 знака;
 *- автор - низ от 20 знака;
 *- заглавие - низ до 30 знака;
 *- обем на книгата (брой страници) - цяло число;
 *- цена - реално число;

 и извършва следните операции:
 *- добавя към масива данни за поредна книга;
 *- извежда на екрана данните за всички книги;
 *- изтрива данните за книга със зададен инв.номер;
 *- намира и извежда сумата от цените на всички книги;
 *- извежда данните на всички книги от зададен автор;
 *- създава нов масив с всички данни за книгите с
 *цена до 15 лв.
 *- създава нов масив, съдържащ заглавията и цените
 *на книгите до 150 стр.
 */

#include <cstring>
#include <iostream>
using namespace std;

class BookBrief {
public:
    char book_title[76];
    float price;
    void display()
    {
        cout << "Title: " << book_title << " | Price: " << price << " lv." << endl;
    }
};

class Book
{
public:
    char inventory_number[7];
    char author_name[21];
    char book_title[76];
    int pages;
    float price;

    void get_data();
    void display();
};

void Book::get_data()
{
    cin.ignore();
    cout << "Inventory number: "; cin.getline(inventory_number, 7);
    cout << "Author: "; cin.getline(author_name, 20);
    cout << "Book title: "; cin.getline(book_title, 76);
    cout << "Pages: "; cin >> pages;
    cout << "Price: "; cin >> price;
}

void Book::display()
{
    cin.ignore();
    cout << "\nInventory number: " << inventory_number << endl;
    cout << "Author: " << author_name << endl;
    cout << "Book title: " << book_title << endl;
    cout << "Pages: " << pages << endl;
    cout << "Price: " << price << endl;
}

float sum_prices(Book books[], int n)
{
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        total += books[i].price;
    }
    return total;
}

void display_by_author(Book books[], int n, char author[])
{
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(books[i].author_name, author) == 0)
        {
            books[i].display();
            found = true;
        }
    }
    if (!found)
        cout << "No books from this author." << endl;
}

void delete_book(Book books[], int &n, char inv_num[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(books[i].inventory_number, inv_num) == 0)
        {
            for (int j = i; j < n - 1; j++)
            {
                books[j] = books[j + 1];
            }
            n--;
            cout << "Successfully deleted book " << endl;
            return;
        }
    }
    cout << "No such book with this inventory number" << endl;
}

int filter_by_price(Book books[], int n, Book result[])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (books[i].price <= 15.0)
        {
            result[count] = books[i];
            count++;
        }
    }
    return count;
}

int filter_brief(Book books[], int n, BookBrief result[])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (books[i].pages <= 150)
        {
            strcpy(result[count].book_title, books[i].book_title);
            result[count].price = books[i].price;
            count++;
        }
    }
    return count;
}

int main() {
    Book library[100];
    int book_count = 0;
    int choice;

    do {
        cout << "\n===== MENU =====\n"
             << "1. Insert Book\n"
             << "2. Show All\n"
             << "3. Delete Book\n"
             << "4. Sum of Prices\n"
             << "5. Search by Author\n"
             << "6. Books <= 15 lv\n"
             << "7. Books <= 150 pages\n"
             << "8. Exit\n"
             << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                if (book_count < 100)
                    library[book_count++].get_data();
                else
                    cout << "Library full!" << endl;
                break;

            case 2:
                for (int i = 0; i < book_count; i++)
                    library[i].display();
                break;

            case 3: {
                char inv[7];
                cin.ignore();
                cout << "Enter inventory number: ";
                cin.getline(inv, 7);
                delete_book(library, book_count, inv);
                break;
            }

            case 4:
                cout << "Total price: "
                     << sum_prices(library, book_count)
                     << " lv." << endl;
                break;

            case 5: {
                char author[21];
                cin.ignore();
                cout << "Enter author: ";
                cin.getline(author, 21);
                display_by_author(library, book_count, author);
                break;
            }

            case 6: {
                Book filtered[100];
                int count = filter_by_price(library, book_count, filtered);
                for (int i = 0; i < count; i++)
                    filtered[i].display();
                break;
            }

            case 7: {
                BookBrief filtered[100];
                int count = filter_brief(library, book_count, filtered);
                for (int i = 0; i < count; i++)
                    filtered[i].display();
                break;
            }

            case 8:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}
