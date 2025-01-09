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
    if len(args) > 2:
        print("[AssertionError] Please enter no more than one argument.")
        return
    if len(args) == 2:
        input_str = args[1]
        get_string_info(input_str)
    else:
        while True:
            input_str = sys.stdin.readline()
            if input_str != '':
                get_string_info(input_str)
                break
            print("Please enter a string")


def get_string_info(string):
    """
    Functions for string analysis. After analyzing, output the content.

    - Parameters: String you want to analyze
    """

    upper_letters_count = 0
    lower_letters_count = 0
    punctuation_marks_count = 0
    spaces_count = 0
    digits_count = 0
    for c in string:
        try:
            if 'A' <= c <= 'Z':
                upper_letters_count += 1
            elif 'a' <= c <= 'z':
                lower_letters_count += 1
            elif c == ' ':
                spaces_count += 1
            elif 0 <= int(c) <= 9:
                digits_count += 1
        except Exception:
            punctuation_marks_count += 1
    print(f"The text contains {len(string)} characters:")
    print(f"{upper_letters_count} upper letters")
    print(f"{lower_letters_count} lower letters")
    print(f"{punctuation_marks_count} punctuation marks")
    print(f"{spaces_count} spaces")
    print(f"{digits_count} digits")


if __name__ == '__main__':
    main()
