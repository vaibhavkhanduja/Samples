import re, collections

def worddict(text):
    return collections.defaultdict(re.findall('[a-z]+', text.lower()))

def readwords():
    f = open("big.txt", "r")
    contents = f.read()
    return contents

def correct(str):
    dict = worddict(readwords())
    for word in dict:
        if str == word:
            return True
    return False

def removeduplicates(sentence):
    seen=set()
    result = []
    for char in sentence:
        if char not in seen:
            seen.add(char)
            result.append(char)
    return ''.join(result)

def main():
    str = raw_input()
    print correct(str)

if __name__ == '__main__':
    main()

