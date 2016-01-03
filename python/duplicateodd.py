def duplicateodd(arraylist):
    res = 0
    for i in arraylist:
        res = res ^ i
    return res

if __name__ == "__main__":
    s = raw_input()
    arraylist = map(int, s.split())
    print "Duplicate in odd is %d:", duplicateodd(arraylist)

    