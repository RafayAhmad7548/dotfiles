stop_words = ("a", "an", "and", "are", "as", "at", "be", "but", "by", "for", "if", "in", "is", "it", "of", "on", "or", "so", "that", "the", "to", "with")
punctuation_marks = (".", ",", "?", "!", ":", ";", "'", "\"", "''", "(", ")", "[", "]", "{", "}", "-", "—", "...", "/", "\\", "&", "*", "@", "#", "_", "~", "|", "<", ">", "=", "+")

def removePunctuationMarks(text: str) -> str, list:
    for mark in punctuation_marks:
        text.replace(mark, "")
    return text

def removeStopWords(text: str) -> str:
    for word in stop_words:
        text.replace(word, "")
    return text

def main():
    print('welcome')

