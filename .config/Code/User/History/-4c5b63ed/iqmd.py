import random

num_characters = ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9')

def removeCharacters(number: str) -> str:
    for c in number:
        if c not in num_characters:
            number = number.replace(c, '')
    return number

num = random.randint(1, 100)
i = 0
while i < 5:
    guess = input('guess the number btw 1 and 100: ')
    guess = removeCharacters(guess)
    if len(guess) == 0:
        print('invalid input')
        continue
    guess = int(guess)
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