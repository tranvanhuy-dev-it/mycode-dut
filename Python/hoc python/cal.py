def add(a, b):
    return a + b

def sub(a, b):
    return a - b

def mult(a, b):
    return a * b

def div(a, b):
    return a / b

a = int(input('Enter a: '))
b = int(input('Enter b: '))
op = input('Enter Operator: ')

if op == "+":
    print(add(a, b))
elif op == "-":
    print(sub(a, b))
elif op == "*":
    print(mult(a, b))
else:
    print(div(a, b))
