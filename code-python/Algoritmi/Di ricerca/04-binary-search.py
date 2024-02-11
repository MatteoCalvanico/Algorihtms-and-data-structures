def binarySearch(array,From,to,elem):
    while From <= to:
        pos = (From + to) // 2
        if(array[pos] == elem):
            return pos
        if(array[pos] < elem):
            From = pos + 1
        else:
            to = pos - 1
    return -1

def interpolationSearch(array, From, to, elem):
    x0 = From
    x1 = to
    y = elem

    while x0 <= x1:
        y0 = array[x0]
        y1 = array[x1]

        if y1 == y0:  #Se siamo alla fine dell'array o l'array dato è di un solo valore
            if array[x0] == y:
                return x0  #Se presente
            else:
                return -1  #Se non presente

        pos = x0 + ((x1 - x0) * (elem - y0)) // (y1 - y0)

        if pos < 0 | pos >= len(array):  #Controllo se la posizione calcolata è all'interno dei limiti dell'array
            return -1

        if array[pos] == y:
            return pos
        elif array[pos] < y:
            x0 = pos + 1
        else:
            x1 = pos - 1
    return -1



test = [1,2,3,4,4,6,7,8,9,10]

print(interpolationSearch(test, 0, 8, 4))