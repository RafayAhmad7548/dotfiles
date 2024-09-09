# Write your code here
shopping_cart = []
items = ['AI response Simulator', 'Investment decison', 'random thing']

print('welcome to the store')
loop = True

while loop:
    i = 1
    for item in items:
        print(i,'. ',item)
        i+=1
    index = input('enter a number to add to shopping cart or q to exit')

    if index == 'q':
        loop = False
        break
    index = int(index)
    if index < 1 or index > 3:
        print('invalid index, try again')
        continue

    shopping_cart.append(items[index-1])

print('your shopping cart')
for item in shopping_cart:
    print(item)
print('goodbye')