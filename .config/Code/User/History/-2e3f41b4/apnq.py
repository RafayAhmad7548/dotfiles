from base_conversion_kit import convert_to_base_n 

num_code = input('enter your number code: ')
name_code = input('enter your name code: ')


def convert_to_coded_base(x: int, base: int, code: str) -> str:
    based = convert_to_base_n(int(x), base)
    for i in range(base):
        based.replace(str(i), code[i])
    return based

