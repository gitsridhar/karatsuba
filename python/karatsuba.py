num1 = '3141592653589793238462643383279502884197169399375105820974944592'
num2 = '2718281828459045235360287471352662497757247093699959574966967627'

def calcproduct(num1, num2):
    n = len(num1)
    if n == 1:
        return num1*num2

    a = int(num1[:n/2])
    b = int(num1[n/2:])

    c = int(num2[:n/2])
    d = int(num2[n/2:])

    product1 = ((10 ** n) * (a * c))
    product2 = ((10 ** (n/2)) * (a*d + b*c))
    product3 = (b * d)

    return product1+product2+product3

def product(num1, num2):
    m = calcproduct(num1, num2)
    return m

print product(num1, num2)
