def NULL_not_found(object: any) -> int:
	object_type = type(object)
	if object is None:
		print(f"Nothing: {object} {type(object)}")
		return 0
	elif object != object:
		print(f"Cheese: {object} {type(object)}")
		return 0
	elif object_type is bool and object is False:
		print(f"Fake: {object} {type(object)}")
		return 0
	elif object == 0:
		print(f"Zero: {object} {type(object)}")
		return 0
	elif object == '':
		print(f"Empty: {type(object)}")
		return 0
	else:
		print("Type not Found")
		return 1