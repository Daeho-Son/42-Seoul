import sys


def main():
    """
    Convert a single string argument to Morse code.
    Raises AssertionError if wrong number of arguments or wrong type.
    """

    NESTED_MORSE = {
        " ": "/",
        "A": ".-", "B": "-...", "C": "-.-.", "D": "-..", "E": ".",
        "F": "..-.", "G": "--.", "H": "....", "I": "..", "J": ".---",
        "K": "-.-", "L": ".-..", "M": "--", "N": "-.", "O": "---",
        "P": ".--.", "Q": "--.-", "R": ".-.", "S": "...", "T": "-",
        "U": "..-", "V": "...-", "W": ".--", "X": "-..-", "Y": "-.--",
        "Z": "--..", "0": "-----", "1": ".----", "2": "..---", "3": "...--",
        "4": "....-", "5": ".....", "6": "-....", "7": "--...", "8": "---..",
        "9": "----."
    }

    argv = sys.argv
    try:
        assert len(argv) == 2, "AssertionError: the arguments are bad"
        for c in argv[1]:
            assert c.upper() in NESTED_MORSE.keys(), \
                "AssertionError: the arguments are bad"

        morse_words = [NESTED_MORSE.get(c) for c in argv[1].upper()]
        print(" ".join(morse_words))
    except Exception as e:
        print(e)


if __name__ == "__main__":
    main()
