import math
R=float(input("Enter radius value: "))
if 1<=R<=200:
    S=4*math.pi*R*R
    V=(4/3)*math.pi*R*R*R
    print(f"Area: {S:.6f}")
    print(f"Volume: {V:.6f}")
else:
    print("Invalid input")
