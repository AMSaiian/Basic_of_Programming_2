def add_file(name):
    with open(name, 'w') as put:
        print(f"Создан и открыт файл с названием {name} в корне проекта\n")
        print("Для записи текста вводите его построчно с помощью Enter.\n"
              "Для завершения в последней строке в конце нажмите Ctrl + X и Enter\n")
        while True:
            row = input()
            if row.find("") != -1:
                row = row.replace('', '')
                put.write(row)
                put.write("\n")
                break
            put.write(row)
            put.write("\n")


def output_file(name):
    with open(name) as show:
        print(f"Файл {name} открыт\nСодержимое:\n")
        while True:
            line = show.readline()
            print(line, end="")
            if not line:
                break


def copy_rows(original, copy):
    with open(original) as buf:
        with open(copy, 'w') as put:
            lines = buf.readlines()
            flag = True
            while flag:
                amount = int(input("\nВведите количество строк, которые нужно скопировать: "))
                if len(lines) >= amount > 0:
                    flag = False
            for i in range(len(lines) - amount, len(lines)):
                put.write(lines[i])


def delete_rows(name, deleted):
    with open(name) as copy:
        rows = copy.readlines()
    unique = []
    for row in rows:
        if row not in unique:
            unique.append(row)
        else:
            deleted += 1
    with open(name, 'w') as nodoubles:
        nodoubles.writelines(unique)
    print(f"\nУдалено строчек: {deleted}")
    return deleted


def add_text(name):
    with open(name, 'a') as app:
        print(f"Открыт файл с названием {name} в корне проекта\n")
        print("Для записи текста вводите его построчно с помощью Enter.\n"
              "Для завершения в последней строке в конце нажмите Ctrl + X и Enter\n")
        while True:
            row = input()
            if row.find("") != -1:
                row = row.replace('', '')
                app.write(row)
                app.write("\n")
                break
            app.write(row)
            app.write("\n")
