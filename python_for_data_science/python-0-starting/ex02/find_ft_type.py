def all_thing_is_obj(object: any) -> int:
	object_type = type(object)

	if object_type is list:
		print(f"List : {object_type}")
	elif object_type is tuple:
		print(f"Tuple : {object_type}")
	elif object_type is set:
		print(f"Set : {object_type}")
	elif object_type is dict:
		print(f"Dict : {object_type}")
	elif object_type is str:
		print(f"{object} is in the kitchen : {type(object)}")
	else:
		print("Type not found")
	return 42