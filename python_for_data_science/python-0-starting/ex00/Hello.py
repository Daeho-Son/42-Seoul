ft_list = ["Hello", "tata!"]
ft_tuple = ("Hello", "toto!")
ft_set = {"Hello", "tutu!"}
ft_dict = {"Hello" : "titi!"}

# ft_list 수정
ft_list[1] = "World!"

# ft_tuple 수정
ft_tuple = ("Hello", "France!")

# ft_sest 수정
ft_set.remove("tutu!")
ft_set.add("Paris!")

# ft_dict 수정
ft_dict.update({"Hello": "42Paris!"})

print(ft_list)
print(ft_tuple)
print(ft_set)
print(ft_dict)