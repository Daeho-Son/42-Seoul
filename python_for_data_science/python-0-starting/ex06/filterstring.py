import sys
from ft_filter import ft_filter


def main():
    """Find the word in the string that is longer than the given length.

- python filterstring.py <string> <length>
- If incorrect, output AssertionError.
"""
    argv = sys.argv
    try:
        assert len(argv) == 3, "AssertionError: the arguments are bad"
        assert argv[2].isdigit(), "AssertionError: the arguments are bad"

        string = argv[1]
        length = int(argv[2])
        words = [word for word in string.split(' ')]
        print(list(ft_filter(lambda x: len(x) > length, words)))
    except Exception as e:
        print(e)


if __name__ == '__main__':
    main()
