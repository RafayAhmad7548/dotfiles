province_map = {
    "0" : "",
    "1" : "",
    "2" : "",
    "3" : "",
    "4" : "",
    "5" : "",
    "6" : "",
    "7" : "",
    "8" : "",
    "9" : "",
}

name = input('Enter name of Student: ')

while not valid:
    cnic = input('Enter ID of Student: ')
    if len(cnic) == 13:
        valid = True
    else:
        valid = False
        print('invalid CNIC\n')