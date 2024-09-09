province_map = {
    "11" : "KPK, Bannu",
    "12" : "KPK, Dera Ismail Khan",
    "13" : "KPK, Hazara",
    "14" : "KPK, Kohat",
    "15" : "KPK, Malakand",
    "16" : "KPK, Mardan",
    "17" : "KPK, Peshawar",
    "2" : "FATA",
    "31" : "Punjab, Bahawalpur",
    "32" : "Punjab, Dera Ghazi Khan",
    "33" : "Punjab, Faisalabad",
    "34" : "Punjab, Gujranwala/Gujrat",
    "36" : "Punjab, Lahore",
    "36" : "Punjab, Multan/Sahiwal",
    "37" : "Punjab, Rawalpindi",
    "38" : "Punjab, Sarghodha/Mianwali",
    "41" : "Sindh, Hyderabad",
    "42" : "Sindh, Karachi",
    "43" : "Sindh, Larkana",
    "44" : "Sindh, Mirpur Khas",
    "45" : "Sindh, ",
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