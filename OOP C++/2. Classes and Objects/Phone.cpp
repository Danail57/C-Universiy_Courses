/*Да се състави програма, която съхранява
 *в масив следните данни за мобилни телефони в магазин:

сериен номер – низ до 10 знака
марка – низ до 20 знака
модел – низ до 30 знака
памет (GB) – цяло число
цена – реално число

Програмата трябва да извършва следните операции:

Добавя нов телефон към масива
Извежда на екрана всички телефони
Изтрива телефон със зададен сериен номер
Намира и извежда средната цена на всички телефони
Извежда всички телефони от зададена марка
Създава нов масив с всички телефони с цена до 800 лв.
Създава нов масив, съдържащ само моделите и цените
на телефоните с памет над 128 GB
Меню за избор на операции
 */

#include <cstring>
#include <iostream>
using namespace std;

class PhoneBrief {
public:
    char brand[11];
    float price;
    void display()
    {
        cout << "Brand: " << brand << "| Price: " << price << "lv." << endl;
    }
};

class Phone
{
public:
    char serial_number[11];
    char brand[11];
    char model[31];
    int memory;
    float price;

    void get_data()
    {
        cin.ignore();
        cout << "Enter serial number: ";
        cin.getline(serial_number,11);

        cout << "Brand: ";
        cin.getline(brand,21);

        cout << "Model: ";
        cin.getline(model,31);

        cout << "Memory (GB): ";
        cin >> memory;

        cout << "Price: ";
        cin >> price;
    }

    void display()
    {
        cout << "\nSerial number: " << serial_number << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Memory: " << memory << "GB" << endl;
        cout << "Price: " << price << "lv." << endl;
    }
};

float average_price(Phone phones[], int n)
{
    if (n == 0) return 0;
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += phones[i].price;
    return sum / n;
}

void delete_phone(Phone phones[], int &n, char serial[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(phones[i].serial_number,serial) == 0)
        {
            for (int j = i; j < n - 1; j++)
                phones[j] = phones[j + 1];
            n--;
            cout << "Phone deleted successfully"<< endl;
            return;
        }
    }
    cout << "No such phone!" << endl;
}

void search_by_brand(Phone phones[], int n, char brand[])
{
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(phones[i].brand, brand) == 0)
        {
            phones[i].display();
            found = true;
        }
    }
    if (!found)
        cout << "No phones from this brand" << endl;
}

int filter_price(Phone phones[], int n, Phone result[])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (phones[i].price <= 800)
        {
            result[count++] = phones[i];
        }
    }
    return count;
}

int filter_memory(Phone phones[], int n, PhoneBrief result[])
{
    int count = 0;
    for (int i = 0; i< n; i++)
    {
        if (phones[i].memory > 128)
        {
            strcpy(result[count].brand, phones[i].brand);
            result[count].price = phones[i].price;
            count++;
        }
    }
    return count;
}

int main()
{
    Phone store[100];
    int count = 0;
    int choice;
    do {
        cout << "\nMENU\n"
        << "1. Add phone\n"
        << "2. Show all\n"
        << "3. Delete phone\n"
        << "4. Average price\n"
        << "5. Search by brand\n"
        << "6. Phones <= 800 lv.\n"
        << "7. Price > 128 GB\n"
        << "8. Exit\n"
        << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (count < 100)
                    store[count++].get_data();
                else
                    cout << "Store is full!\n";
                break;
            case 2:
                for (int i = 0; i < count; i++)
                    store[i].display();
                break;
            case 3: {
                char serial[11];
                cin.ignore();
                cout << "Enter serial number: ";
                cin.getline(serial,11);
                delete_phone(store,count,serial);
                break;
            }
            case 4:
                cout << "Average price: " << average_price(store,count) << endl;
                break;
            case 5: {
                char brand[21];
                cin.ignore();
                cout << "Enter brand: ";
                cin.getline(brand,21);
                search_by_brand(store, count, brand);
                break;
            }
            case 6: {
                Phone filtered[100];
                int new_count = filter_price(store, count, filtered);
                for (int i = 0; i < new_count; i++)
                    filtered[i].display();
                break;
            }
            case 7: {
                PhoneBrief filtered[100];
                int new_count = filter_memory(store, count, filtered);

                for (int i = 0; i < new_count; i++)
                    filtered[i].display();
                break;
            }
            case 8:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }
    while (choice != 8);
}
