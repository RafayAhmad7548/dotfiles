province_map = {
    "1" : "KPK",
    "2" : "FATA",
    "3" : "Punjab",
    "4" : "Sindh",
    "5" : "Balochistan",
    "6" : "Islamabad",
    "7" : "Gilgit Baltistan",
    "8" : "Azad Kashmir",
}
division_map = {
    "1" : "Bannu",
    "2" : "Dera Ismail Khan",
    "3" : "Hazara",
    "4" : "Kohat",
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