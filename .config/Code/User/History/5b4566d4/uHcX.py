bookstore = []

num = int(input('how many books would you like to add: '))

for i in range(num):
    title = input('enter book title: ')
    author = input('enter book author: ')
    quantity = input('enter book quantity: ')
    price = input('enter book price: ')
    bookstore.append({"title" : title, "author" : author, "quantity" : quantity, "price" : price})

search_title = input('enter a title to search for a book: ')
for book in bookstore:
    book = dict(book)
    if book.get('title') == search_title:
        for key in book.keys():
            print(key, ':', book.get(key))
        found = True
        break
if not found:
    print('book title not function')

update_title = input('enter a title to update a book: ')

for book in bookstore:
    book = dict(book)
    if book.get('title') == search_title:
        for key in book.keys():
            print(key, ':', book.get(key))
        found = True
        break
if not found:
    print('book title not function')