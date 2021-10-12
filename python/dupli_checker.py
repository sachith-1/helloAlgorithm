txt = "Hello World"
dupli = {}

for ch in txt:

    if ch in dupli:
        dupli[ch] += 1
    else:
        dupli[ch] = 1

for key, val in dupli.items():
    if val > 1:
        print(key, end=" ")
