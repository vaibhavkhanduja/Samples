def power(a, b):
    # check if b is multiple of 2
    if ((b % 2) == 0):
        return power(a, b/2)
