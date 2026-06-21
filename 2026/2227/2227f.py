t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    def calculate_movement(heights):
        """Calculate total movement distance"""
        total = 0
        max_height = max(heights) if heights else 0

        for h in range(1, max_height + 1):
            # Find rightmost column with height >= h
            rightmost = -1
            for j in range(n - 1, -1, -1):
                if heights[j] >= h:
                    rightmost = j
                    break

            if rightmost >= 0:
                # Sum movement distances for all cubes at height h
                for i in range(rightmost + 1):
                    if heights[i] >= h:
                        total += rightmost - i

        return total

    # Case 1: No removal
    result = calculate_movement(a)

    # Case 2: Try removing one cube from each position
    for idx in range(n):
        if a[idx] > 0:
            a[idx] -= 1
            result = max(result, calculate_movement(a))
            a[idx] += 1

    print(result)
