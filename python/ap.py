def findsum(aplist):
    return sum(aplist)

def findmissing(aplist):
    lastelement = aplist[(len(aplist) - 1)]
    sumofgoodseq = lastelement*(lastelement + 1)/2
    return(sumofgoodseq - sum(aplist))

if __name__ == "__main__":
    applist = [1 ,2, 3, 5]
    print findmissing(applist)