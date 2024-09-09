province_map = {
    "11" : "KPK, Bannu",
    "12" : "KPK, Dera Ismail Khan",
    "13" : "KPK, Hazara",
    "14" : "KPK, Kohat",
    "15" : "KPK, Malakand",
    "16" : "KPK, Mardan",
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
    "3" : "",
    "4" : "",
    "5" : "",
    "6" : "",
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