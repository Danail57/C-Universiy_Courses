/*  Системен мониторинг (Resource Tracker)
Представи си, че пишеш малък инструмент за следене
на системните ресурси.

Задача: Създай структура Process,
която съдържа: ID на процеса (integer),
име (string), консумация на памет в MB (float)
и статус (boolean – дали е активен).

Функция: Напиши функция, която приема масив от
такива процеси и връща общата консумация на
памет само на активните процеси.

 */
#include <iostream>
#include <string>
using namespace std;

struct Process {
 int id_processor;
 string name;
 float memory_usage;
 bool is_active;
};

float active_processors_usage(Process processes[], int n)
{
  float total = 0.0;
  for (int i = 0; i < n; i++) {
   if (processes[i].is_active) {
    total += processes[i].memory_usage;
   }
 }
 return total;
}

int main()
{
 int count;
 cout << "How many processes do you want to run?" << endl;
 cin >> count;

 Process list[count];
 for (int i = 0; i < count; i++) {
  cout << "Process #" << i + 1 << ": " << endl;
  cout << "ID: " << endl;
  cin >> list[i].id_processor;

  cout << "Name: ";
  cin >> list[i].name;

  cout << "Memory usage: ";
  cin >> list[i].memory_usage;

  cout << "Is active? ";
  cin >> list[i].is_active;
 }
 float total = active_processors_usage(list, count);
 cout << "Total MB usage: " << total << endl;
}
