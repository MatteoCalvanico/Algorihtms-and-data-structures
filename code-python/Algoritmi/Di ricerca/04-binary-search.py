def binarySearch(array,From,to,elem):
    while From <= to:
        pos = (From + to) // 2
        if(array[pos] == elem):
            return pos
        if(array[pos] < elem):
            From = pos
        else:
            to = pos
    return -1

def interpolationSearch(array,From,to,elem):
    x0 = From
    x1 = to
    y = elem

    while From <= to:
        y0 = array[From]
        y1 = array[to]

        #Se la diff fra il più grande e il più piccolo nell'intervallo è 0 il calcolo darebbe dei problemi
        if((y1 - y0) == 0): 
            if(array[x0] == y): #Controlliamo se abbiamo trovato il valore, altrimenti concludiamo
                return x0 
            else: 
                return - 1

        #Calcolo pivot
        pos = x0 + ((x1 - x0) * (elem - y0)) // (y1 - y0)

        #Se il valore è fuori dal range dell'array allora non è presente
        if((pos > x1) | (pos < x0)): return -1 
        
        #Parte identica a quello binario
        if(array[pos] < y):
            x0 = pos + 1
        else:
            x1 = pos - 1
    return -1


test = [1,2,3,4,4,6,7,8,9,10]

print(binarySearch(test, 0, 8, 4))