bookstore = []

num = input('how many books would you like to add: ')
for i in range(num):
    title = input('enter book title for book ', i, ': ')
    author = input('enter book author for book ', i, ': ')
    quantity = input('enter book quantity for book ', i, ': ')
    price = input('enter book price for book ', i, ': ')
    bookstore.append({"title" : title, "author" : author, "quantity" : quantity, "price" : price})

search_title = input('enter a title to search for a book: ')
for book in bookstore:
    book = dict(book)
    if book.get('title') == search_title:
        for details in book:
            print(details)