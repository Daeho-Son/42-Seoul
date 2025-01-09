def ft_filter(function, iterable):
    """filter(function or None, iterable) --> filter object

Return an iterator yielding those items of iterable for which function(item)
is true. If function is None, return the items that are true."""
    if function is None:
        yield [item for item in iterable if item]
    yield [item for item in iterable if function(item)]


def main():
    ft_filter(None, [])


if __name__ == '__main__':
    main()
