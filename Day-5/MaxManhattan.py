def max_manhattan_distance(s: str, k: int) -> int:
    # Count the number of each direction
    N = S = E = W = 0
    max_distance = 0

    for move in s:
        if move == 'N':
            N += 1
        elif move == 'S':
            S += 1
        elif move == 'E':
            E += 1
        elif move == 'W':
            W += 1

        # Greedy step: use up to k changes to reduce opposing directions

        # Vertical direction optimization
        min_vert = min(N, S)
        used_vert = min(k, min_vert)
        remaining = k - used_vert

        # Horizontal direction optimization
        min_horiz = min(E, W)
        used_horiz = min(remaining, min_horiz)

        # Compute current net distances after changes
        vertical_dist = abs(N - S) + 2 * used_vert
        horizontal_dist = abs(E - W) + 2 * used_horiz
        total_distance = vertical_dist + horizontal_dist

        # Update the maximum distance found
        max_distance = max(max_distance, total_distance)

    return max_distance

# Example test cases
print("Example 1:", max_manhattan_distance("NWSE", 1))  # Output: 3
print("Example 2:", max_manhattan_distance("NSWWEW", 3))  # Output: 6