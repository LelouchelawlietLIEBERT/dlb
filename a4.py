with open("text.txt", "w") as f:
    print("Enter 5-6 Lines :\n")
    for _ in range(6): f.write(input() + "\n")

filename = "text.txt"

with open(filename, "r") as f:
    content = f.read()

uppercase_count = sum(ch.isupper() for ch in content)
lowercase_count = sum(ch.islower() for ch in content)
digit_count = sum(ch.isdigit() for ch in content)

print(f"File: {filename}")
print(f"Uppercase letters: {uppercase_count}")
print(f"Lowercase letters: {lowercase_count}")
print(f"Digits: {digit_count}")

