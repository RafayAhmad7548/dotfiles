from base_conversion_kit import convert_to_base_n 

def convert_to_coded_base(x: int, base: int, code: str) -> str:
    based = convert_to_base_n(int(x), base)
    for i in range(base):
        based = based.replace(str(i), code[i])
    return based


num_code = input('enter your number code: ')
name_code = input('enter your name code: ')

a = convert_to_coded_base(5, 3, "7584")
print(a)