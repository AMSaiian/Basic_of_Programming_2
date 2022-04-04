import pickle as pick
from datetime import datetime


class Client:
    def __init__(self, name=None, timein=None, timeout=None):
        self.name = name
        self.timein = timein
        self.timeout = timeout

    def __str__(self):
        return f'{self.name}   {self.timein.strftime("%H:%M")}   {self.timeout.strftime("%H:%M")}'


def add_client():
    client = Client()
    client.name = input("\nВведите имя клиента: ")
    client.timein = datetime.strptime(input("Введите время начала обслуживания (в формате 00:00 - 23:59): "), "%H:%M")
    client.timeout = datetime.strptime(input("Введите время конца обслуживания (в формате 00:00 - 23:59): "), "%H:%M")
    if check_doubles(client):
        return
    else:
        with open("timetable.txt", 'ab') as add:
            pick.dump(client, add)


def check_doubles(client):
    start_workday = datetime.strptime("09:00", "%H:%M")
    end_workday = datetime.strptime("17:00", "%H:%M")
    if client.timein >= client.timeout or client.timein < start_workday or client.timeout > end_workday:
        print("\nВведено некорректное время, клиент не записан")
        return True
    else:
        with open("timetable.txt", 'rb') as check:
            while True:
                try:
                    temp_client = pick.load(check)
                    if client.timein < temp_client.timeout:
                        print("\nКонфликт времен\nКлиент не записан")
                        return True
                except EOFError:
                    return False


def output_list():
    with open("timetable.txt", 'rb') as output:
        print("\nСписок клиентов:")
        while True:
            try:
                temp_client = pick.load(output)
                print(temp_client)
            except EOFError:
                break


def clear_list():
    with open("timetable.txt", 'wb'):
        print("\nСписок очищен")


def count_free_periods():
    am = 0
    pm = 0
    start_workday = datetime.strptime("09:00", "%H:%M")
    midday = datetime.strptime("12:00", "%H:%M")
    end_workday = datetime.strptime("17:00", "%H:%M")
    clients = []
    with open("timetable.txt", 'rb') as count:
        while True:
            try:
                clients.append(pick.load(count))
            except EOFError:
                break
        if len(clients):
            if len(clients) == 1:
                if clients[0].timein == start_workday and clients[0].timeout == midday:
                    pm += 1
                elif clients[0].timein == midday and clients[0].timeout == end_workday:
                    am += 1
                elif clients[0].timein > start_workday and clients[0].timeout < midday:
                    am += 2
                    pm += 1
                elif clients[0].timein > midday and clients[0].timeout < end_workday:
                    am += 1
                    pm += 2
                elif clients[0].timein != start_workday and clients[0].timeout != end_workday:
                    am += 1
                    pm += 1
            else:
                if clients[0].timein != start_workday:
                    am += 1
                for i in range(len(clients) - 1):
                    if clients[i].timeout != clients[i + 1].timein:
                        if clients[i].timeout < midday < clients[i + 1].timein:
                            am += 1
                            pm += 1
                        elif clients[i].timeout < midday:
                            am += 1
                        else:
                            pm += 1
                if clients[len(clients) - 1].timeout != end_workday:
                    pm += 1
        else:
            am += 1
            pm += 1
    return am, pm
