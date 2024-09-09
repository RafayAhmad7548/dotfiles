import random

num = random.randint(1, 100)
i = 0
while i < 5:
    try:
        guess = int(input('guess the number: '))
    except ValueError:
        print('enter a number please')
        i = i - 1
        continue
    if guess == num:
        print('congratualtions you guessed correctly: ')
        break
    elif guess > num:
        print('too high try again: ')
    else:
        print('too low try again: ')
    i = i + 1

print('you failed the number was ', num)