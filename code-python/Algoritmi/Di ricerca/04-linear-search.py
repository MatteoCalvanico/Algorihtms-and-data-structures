def linearSearch(array, elem):
    pos = 0
    for i in array:
        if(i == elem):
            return pos
        pos+=1
    return -1   

#Min/Max
def bestSearch(array, better):
    bestElem = array[0]
    for i in range(len(array)):
        if(better(array[i], bestElem)): #Se l'elem dell'array è 'better' di quello attuale lo salviamo
            bestElem = array[i]
    return bestElem



test = [0,4,1,7,5]

print(linearSearch(test,7))
