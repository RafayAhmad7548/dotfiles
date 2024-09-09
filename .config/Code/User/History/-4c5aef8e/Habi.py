stop_words = ("a", "an", "and", "are", "as", "at", "be", "but", "by", "for", "if", "in", "is", "it", "of", "on", "or", "so", "that", "the", "to", "with")
punctuation_marks = (".", ",", "?", "!", ":", ";", "'", "\"", "''", "(", ")", "[", "]", "{", "}", "-", "—", "...", "/", "\\", "&", "*", "@", "#", "_", "~", "|", "<", ">", "=", "+")

def removePunctuationMarks(text: str) -> str:
    for mark in punctuation_marks:
        text.replace(mark, "")
    return text

def removeStopWords(text: str) -> str:
    for word in stop_words:
        text.replace(word, "")
    return text

def main():
    print('welcome')
    # sentence = input('enter a sentence:\n')
    # sentence = removePunctuationMarks(sentence)
    # sentence = removeStopWords(sentence)

    # print('sentence with removed stuff is:\n', sentence)
    a = 'test thing'
    a = a.replace('test ', '')
    print(a)

if __name__== "__main__":
    main()