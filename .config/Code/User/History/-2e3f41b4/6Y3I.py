from base_conversion_kit import convert_to_base_n 

def convert_to_coded_base(x: int, base: int, code: str) -> str:
    based = convert_to_base_n(int(x), base)
    for i in range(base-1, 0, -1):
        based = based.replace(str(i), code[i])
    return based


# num_code = input('enter your number code: ')
# name_code = input('enter your name code: ')
num_code = '1569'
name_code = 'AZMaT@'
bases = [2, 3, 4, 5, 6, 8, 16]

file = open(num_code+"_"+name_code+".csv", "a")
a = range(5, 1, -1)
print(a)

for i in range(51):
    for base in bases:
        if base == 2 or base == 8 or base == 16:
            based = convert_to_base_n(i, base)
        elif base < 5:
            based = convert_to_coded_base(i, base, num_code)
        else:
            based = convert_to_coded_base(i, base, name_code)
        file.write(based+",")
    file.write("\n")
file.close()