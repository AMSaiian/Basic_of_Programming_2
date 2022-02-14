import Function as f

f.add_file("FirstFile.txt")
print("\nИсходный файл:")
f.output_file("FirstFile.txt")
f.copy_rows("FirstFile.txt", "SecondFile.txt")
print("\nФайл со скопированным текстом:")
f.output_file("SecondFile.txt")
deleted = 0
deleted = f.delete_rows("SecondFile.txt", deleted)
print("Файл со скопированным текстом без повторов:")
f.output_file("SecondFile.txt")
flag = True
while flag:
    choose = int(input("\nДля того чтобы дописать к исходному файлу, введите 1.\n"
                       "Для того чтобы дописать к отредактированному файлу, введите 2.\n"
                       "Чтобы закончить работу программы введите 0.\nВыбор: "))
    if choose == 1:
        f.add_text("FirstFile.txt")
        f.output_file("FirstFile.txt")
    elif choose == 2:
        f.add_text("SecondFile.txt")
        f.output_file("SecondFile.txt")
    elif choose == 0:
        flag = False
