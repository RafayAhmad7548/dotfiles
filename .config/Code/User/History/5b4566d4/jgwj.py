def getdict(books: list, title: str) -> dict:
    for book in books:
        book = dict(book)
        if book.get('title') == title:
            return book
    return None

bookstore = []

num = int(input('how many books would you like to add: '))


for i in range(num):
    title = input('enter book title: ')
    author = input('enter book author: ')
    quantity = input('enter book quantity: ')
    price = input('enter book price: ')
    bookstore.append({"title" : title, "author" : author, "quantity" : quantity, "price" : price})

search_title = input('enter a title to search for a book: ')

book = getdict(bookstore, search_title)
if book is None:
    print('book title not function')
else:
    for key in book.keys():
        print(key, ':', book.get(key))

update_title = input('enter a title to update a book: ')
book = getdict(bookstore, update_title)
if book is None:
    print('book title not function')
else:
    new_author = input('enter updated author')
    new_quantity = input('enter updated quantity')
    new_price = input('enter updated price')
