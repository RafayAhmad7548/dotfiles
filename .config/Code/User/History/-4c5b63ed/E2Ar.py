import random

num = random.randint(1, 100)

for i in range(5):
    guess = int(input('guess the number: '))
    if guess == num:
        print('congratualtions you guessed correctly: ')
        break
    elif guess > num:
        print('too high try again: ')
    else:
        print('too low try again: ')

print('you failed the number was ', num)