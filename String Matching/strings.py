str = "4/10+15/50"

f1, f2 = str.split('+')

num1 = f1.split('/')
num2 = f2.split('/')

def gcd (a, b):
    while b:
        a, b = b, a % b
    return a

def lcm (a, b):
    return a * b // gcd(a, b)

def add_fractions(num1, num2):
    x, y = int(num1[0]), int(num1[1])
    a, b = int(num2[0]), int(num2[1])

    denominator = lcm(y, b)
    numerator = (x * (denominator // y)) + (a * (denominator // b))
    return f"{numerator}/{denominator}"