province_map = {
    "11" : "KPK, Bannu",
    "12" : "KPK, Dera Ismail Khan",
    "13" : "KPK, Hazara",
    "14" : "KPK, Kohat",
    "15" : "KPK, Malakand",
    "16" : "KPK, Mardan",
    "17" : "KPK, Peshawar",
    "2" : "FATA",
    "31" : "Punjab",
    "32" : "Punjab",
    "33" : "Punjab",
    "34" : "Punjab",
    "36" : "Punjab",
    "36" : "Punjab",
    "37" : "Punjab",
    "38" : "Punjab",
    "4" : "Sindh",
    "5" : "Balochistan",
    "6" : "Islamabad",
    "7" : "Gilgit Baltistan",
    "8" : "Azad Kashmir",
}

name = input('Enter name of Student: ')

while not valid:
    cnic = input('Enter ID of Student: ')
    if len(cnic) == 13:
        valid = True
    else:
        valid = False
        print('invalid CNIC\n')