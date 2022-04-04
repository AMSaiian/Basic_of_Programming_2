import Function as Fnc

with open("timetable.txt", "ab"):
    flag = True
while flag:
    choice = int(input("\nВведите:\n1 для ввода нового клиента\n2 для вывода списка клиентов\n"
                       "3 для очистки списка\n4 для завершения работы и подсчета свободных промежутков: "))
    if choice == 1:
        Fnc.add_client()
    elif choice == 2:
        Fnc.output_list()
    elif choice == 3:
        Fnc.clear_list()
    elif choice == 4:
        am, pm = Fnc.count_free_periods()
        print(f"Свободных периодов в первой половине дня: {am}; во второй: {pm}")
        flag = False
