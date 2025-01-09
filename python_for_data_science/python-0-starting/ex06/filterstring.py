import sys
from ft_filter import ft_filter


def filter_string(string: str, length: int):
    words = [word for word in string.split(' ')]
    return list(ft_filter(lambda x: len(x) > length, words))


def main():
    argv = sys.argv
    try:
        assert len(argv) == 3, "AssertionError: the arguments are bad"
        assert argv[2].isdigit(), "AssertionError: the arguments are bad"

        string = argv[1]
        length = int(argv[2])
        print(filter_string(string, length))
    except Exception as e:
        print(e)


if __name__ == '__main__':
    main()
