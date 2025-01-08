echo "========== TEST ex00 =========="

output=$(python Hello.py | cat -e)

expected_output1="['Hello', 'World!']$
('Hello', 'France!')$
{'Hello', 'Paris!'}$
{'Hello': '42Paris!'}$"

expected_output2="['Hello', 'World!']$
('Hello', 'France!')$
{'Paris!', 'Hello'}$
{'Hello': '42Paris!'}$"


echo -n "Result: "
if [[ "$output" == "$expected_output1" || "$output" == "$expected_output2" ]]; then
	echo "OK"
else
	echo "KO"
fi
