import sys

def whatis():
	args = sys.argv

	if len(args) == 1:
		return
	try:
		assert len(args) <= 2, "AssertionError: more than one argument is provided"
	
		num = int(args[1])
		if num % 2 == 0:
			print("I'm Even.")
		else:
			print("I'm Odd.")
	except ValueError:
		print("AssertionError: argument is not an integer")
	except Exception as e:
		print(e)

if __name__ == '__main__':
	whatis()