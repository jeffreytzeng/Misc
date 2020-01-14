class BDConverter:
    def __init__(self, string):
        self.string = string

    def SetString(self, string):
        self.string = string

    def ShowB2D(self):
        decimal = 0

        for i in range(len(self.string)):
            decimal += int(self.string[i]) * pow(2, len(self.string) - i - 1);

        print("BIN " + self.string + " = " + str(decimal))
        self.ShowD2B()


    def ShowD2B(self):
        binary = ''
        decimal = int(self.string)

        while decimal > 0:
            binary = str(decimal % 2) + binary
            decimal = int(decimal / 2)

        print("DEC " + self.string + " = " + binary)