from bdconverter import BDConverter

string = input()
bd = BDConverter(string)
decimal = False

for s in string:
    if int(s) > 1:
        decimal = True
        break

show = lambda decimal: bd.ShowD2B() if decimal else bd.ShowB2D()
show(decimal)
