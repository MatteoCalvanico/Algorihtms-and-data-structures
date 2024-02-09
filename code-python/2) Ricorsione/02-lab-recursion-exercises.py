#Test
def test(I, O):
    if(I == O):
        print("Passed")
    else:
        print("NOT Passed")

#Implementazioni
def sum_numbers(a,b):
    if(b == a):
        return a
    return b + sum_numbers(a, b-1)

def pow(a,n):
    if(n == 1):
        return a
    return a * pow(a, n-1)

def list_contains(lst,elem):
    if(len(lst) == 0):
        return False
    if(lst[0] == elem):
        return True
    return list_contains(lst[1:], elem)

def palindrome(string):
    if(len(string) == 1):
        return True
    if(string[0] != string[-1]):
        return False
    else:
        palindrome(string[1:-1])

#Prova
print("\n*** sum_numbers' TEST ***")
test(sum_numbers(1,10), 55)
print("\n*** pow TEST ***")
test(pow(3,6), 729)
print("\n*** list_contains TEST ***")
test(list_contains([0,3,4,5], 4), True)