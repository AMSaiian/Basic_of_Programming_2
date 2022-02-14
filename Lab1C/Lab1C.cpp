#include "Header.h"

int main()
{
    SetConsoleOutputCP(1251);
    int rowsorig = 0;
    AddFile("FirstFile.txt", rowsorig);
    cout << "\nПроверка содержимого исходного файла:\n";
    OutputRows("FirstFile.txt");
    int amount;
    CopyRows("FirstFile.txt", "SecondFile.txt", amount, rowsorig);
    cout << "Проверка содержимого файла с копированным текстом:\n";
    OutputRows("SecondFile.txt");
    int deleted = 0;
    cout << "\nУдаление строчек:\n";
    DeleteRows("SecondFile.txt", deleted);
    cout << "Удалено строчек: " << deleted << "\n\n";
    cout << "Исходный текст:\n\n";
    OutputRows("FirstFile.txt");
    cout << "Отредактированный скопированный текст без повторов:\n\n";
    OutputRows("SecondFile.txt");
    int choose;
    do
    {
        cout << "Для того чтобы дописать к исходному файлу, введите 1.\nДля того чтобы дописать к отредактированному файлу, введите 2.\n";
        cout << "Чтобы закончить работу программы введите 0.\nВыбор: ";
        cin >> choose;
        cin.ignore(1000, '\n');
        cout << endl;
        if (choose == 1)
        {
            AddText("FirstFile.txt");
            cout << endl;
            OutputRows("FirstFile.txt");
        }
        else if (choose == 2)
        {
            AddText("SecondFile.txt");
            cout << endl;
            OutputRows("SecondFile.txt");
        }
    } while (choose != 0);
}