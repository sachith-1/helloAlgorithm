def bucket_sort(my_list: list) -> list:
    if len(my_list) == 0:
        return []
    min_value, max_value = min(my_list), max(my_list)
    bucket_count = int(max_value - min_value) + 1
    buckets: list[list] = [[] for _ in range(bucket_count)]

    for i in range(len(my_list)):
        buckets[(int(my_list[i] - min_value) // bucket_count)].append(my_list[i])

    return [v for bucket in buckets for v in sorted(bucket)]

if __name__ == "__main__":
    user_input = input("Enter numbers separated by a comma:\n").strip()
    unsorted = [int(item) for item in user_input.split(",")]
    print(bucket_sort(unsorted))