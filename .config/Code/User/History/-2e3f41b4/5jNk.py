from base_conversion_kit import convert_to_base_n 

def convert_to_coded_base(x: int, base: int, code: str) -> str:
    based = convert_to_base_n(int(x), base)
    for i in range(base):
        based = based.replace(str(i), code[i])
    return based


num_code = input('enter your number code: ')
name_code = input('enter your name code: ')

file = open("test.txt", "a")

for i in range(1, 50):
    num = convert_to_coded_base(i, 3, num_code)
