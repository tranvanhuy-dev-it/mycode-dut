import sys
import math

t = int(input())  # số test case

for _ in range(t):
    x = int(input())

    # Bước 1: Tìm số mũ sao cho 2^(steps-1) <= x
    steps = 0
    while (1 << steps) < x:
        steps += 1

    # Lúc này 2^(steps-1) < x <= 2^steps
    base_power = 1 << (steps - 1)
    missing = x - base_power

    # Bước 2: Tính số hành động cần để tăng thêm từng đơn vị (mỗi bước +3 tối đa)
    extra_steps = (missing + 2) // 3  # làm tròn lên

    # Tổng số hành động
    result = steps + extra_steps

    print(result)
