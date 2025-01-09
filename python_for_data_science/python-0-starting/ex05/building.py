import sys


def main():
    """
    # building.py
    Analyze the string and output the information below.
    - Length of string
    - Number of uppercase letters
    - the number of lowercase letters
    - the number of punctuation marks
    - Number of spaces
    - Number of digits

    Enter the numbers through the program argument.
    However, if there is no program argument, the string is entered directly.

    If there are many program arguments, output AssertionError.
    """

    args = sys.argv

    try:
        assert len(args) <= 2, \
            "[AssertionError] Please enter no more than one argument."

        if len(args) == 2:
            input_str = args[1]
            get_string_info(input_str)
        else:
            while True:
                print("What is the text to count?")
                input_str = sys.stdin.readline()
                if input_str != '':
                    get_string_info(input_str)
                    return
                print("Please enter a string")
    except Exception as e:
        print(e)


def get_string_info(input_string):
    """
    Functions for string analysis. After analyzing, output the content.

    - Parameters: String you want to analyze
    """

    upper_count = sum(1 for char in input_string if char.isupper())
    lower_count = sum(1 for char in input_string if char.islower())
    digit_count = sum(1 for char in input_string if char.isdigit())
    space_count = sum(1 for char in input_string if char.isspace())
    punctuation_count = sum(1 for char in input_string if is_punctuation(char))
    print(f"The text contains {len(input_string)} characters:")
    print(f"{upper_count} upper letters")
    print(f"{lower_count} lower letters")
    print(f"{punctuation_count} punctuation marks")
    print(f"{space_count} spaces")
    print(f"{digit_count} digits")


def is_punctuation(c):
    """a function of determining punctuation"""
    ascii_value = ord(c)
    return 33 <= ascii_value <= 47 or \
        58 <= ascii_value <= 64 or \
        91 <= ascii_value <= 96 or \
        123 <= ascii_value <= 126


if __name__ == '__main__':
    main()
