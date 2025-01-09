def count_in_list(input_list: list, target: any) -> int:
    """Return the number of occurrences of `target` in `input_list`.

Args:
    input_list (list): List to search in.
    target (any): Target value to count.

Returns:
    int: Number of occurrences of `target` in `input_list`."""

    return input_list.count(target)


def main():
    count_in_list(None, '')


if __name__ == '__main__':
    main()
