import re
text = "ab abb abbb abbbb ac a abbbb"
print(re.findall(r'a(b*)', text))
print(re.findall(r'a(b?)', text))
print(re.findall(r'a(b+)', text))
print(re.findall(r'ab{4}c', text))
