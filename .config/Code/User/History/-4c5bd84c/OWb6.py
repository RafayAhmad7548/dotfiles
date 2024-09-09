province_map = {
    "11" : "KPK, Bannu",
    "12" : "KPK, Dera Ismail Khan",
    "13" : "KPK, Dera Ismail Khan",
    "14" : "KPK, Dera Ismail Khan",
    "15" : "KPK, Dera Ismail Khan",
    "16" : "KPK, Dera Ismail Khan",
    "17" : "KPK, Dera Ismail Khan",
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
    "2" : "",
    "3" : "Hazara",
    "4" : "Kohat",
    "5" : "Malakand",
    "6" : "Mardan",
    "7" : "Peshawar",
}

name = input('Enter name of Student: ')

while not valid:
    cnic = input('Enter ID of Student: ')
    if len(cnic) == 13:
        valid = True
    else:
        valid = False
        print('invalid CNIC\n')