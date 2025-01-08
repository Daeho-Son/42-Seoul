import sys

def main():
	"""
	# building.py
	- Features: A function that receives a single string through program arguments and displays the sum of uppercase, lowercase, punctuation, numbers, and spaces.
	- If the string is not provided through the program arguments, you must enter the string directly.
    - Output [AssertionError] if there are two or more strings entered as program parameters.
	"""

	args = sys.argv
	if len(args) > 2:
		print("[AssertionError] Please enter no more than one argument.")
		return
	if len(args) == 2:
		input_str = args[1]
		get_string_info(input_str)
	else:
		input_str = input("What is the text to count?\n")
		get_string_info(input_str)

def get_string_info(string):

	length = len(string)

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
		except:
			punctuation_marks_count += 1
	print(f"The text contains {len(string)} characters:")
	print(f"{upper_letters_count} upper letters")
	print(f"{lower_letters_count} lower letters")
	print(f"{punctuation_marks_count} punctuation marks")
	print(f"{spaces_count} spaces")
	print(f"{digits_count} digits")

if __name__ == '__main__':
	main()