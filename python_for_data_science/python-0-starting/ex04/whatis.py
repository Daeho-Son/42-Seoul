import sys

def whatis():
	args = sys.argv

	if len(args) == 1:
		return
	if len(args) > 2:
		print("AssertionError: more than one argument is provided")
		return
	
	try:
		num = int(args[1])
		if num % 2 == 0:
			print("I'm Even.")
		else:
			print("I'm Odd.")
	except:
		print("AssertionError: argument is not an integer")

if __name__ == '__main__':
	whatis()