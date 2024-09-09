import random

num = random.randint(1, 100)

for i in range(5):
    guess = input('guess the number')
    if guess == num:
        print('congratualtions you guessed correctly')
        break
    else:
        print('incorrect guess try again')
        