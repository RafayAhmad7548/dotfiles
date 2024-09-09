import random

num_characters = ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9')

def removeCharacters(number: str):
    for c in number:
        

num = random.randint(1, 100)
i = 0
while i < 5:
    try:
        guess = int(input('guess the number btw 1 and 100: '))
    except ValueError:
        print('enter a number please')
        continue
    if guess < 1 or guess > 100:
        print('enter number in range please')
        continue
    if guess == num:
        print('congratualtions you guessed correctly: ')
        break
    elif guess > num:
        print('too high try again: ')
    else:
        print('too low try again: ')
    i += 1

print('you failed the number was ', num)