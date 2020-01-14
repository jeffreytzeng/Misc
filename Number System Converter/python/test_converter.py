import io
import sys
import unittest
from bdconverter import BDConverter

class ConvterTest(unittest.TestCase):
    def setUp(self):
        self.bd = BDConverter("")
    
    # Solution of get stdout from
    # https:// stackoverflow.com/questions/33767627/python-write-unittest-for-console-print
    # Solution of pass by function pointer from
    # https:// stackoverflow.com/questions/2283210/python-function-pointer
    def GetStdout(self, funName):
        output = io.StringIO()          # Create StringIO object
        sys.stdout = output             # and redirect stdout.
        funName()                       # Call print function.
        sys.stdout = sys.__stdout__     # Reset redirection

        return output.getvalue()

    def test_B2D_5(self):
        self.bd.SetString("101")
        output = self.GetStdout(self.bd.ShowB2D)
        self.assertEqual("BIN 101 = 5\nDEC 101 = 1100101\n", output)

    def test_B2D_12(self):
        self.bd.SetString("1100")
        output = self.GetStdout(self.bd.ShowB2D)
        self.assertEqual("BIN 1100 = 12\nDEC 1100 = 10001001100\n", output)

    def test_B2D_123(self):
        self.bd.SetString("01111011")
        output = self.GetStdout(self.bd.ShowB2D)
        self.assertEqual("BIN 01111011 = 123\nDEC 01111011 = 100001111001111100011\n", output)

    def test_B2D_188(self):
        self.bd.SetString("10111100")
        output = self.GetStdout(self.bd.ShowB2D)
        self.assertEqual("BIN 10111100 = 188\nDEC 10111100 = 100110100100100001111100\n", output)

    def test_D2B_5(self):
        self.bd.SetString("5")
        output = self.GetStdout(self.bd.ShowD2B)
        self.assertEqual("DEC 5 = 101\n", output)

    def test_D2B_12(self):
        self.bd.SetString("12")
        output = self.GetStdout(self.bd.ShowD2B)
        self.assertEqual("DEC 12 = 1100\n", output)

    def test_D2B_123(self):
        self.bd.SetString("123")
        output = self.GetStdout(self.bd.ShowD2B)
        self.assertEqual("DEC 123 = 1111011\n", output)

    def test_D2B_188(self):
        self.bd.SetString("188")
        output = self.GetStdout(self.bd.ShowD2B)
        self.assertEqual("DEC 188 = 10111100\n", output)


unittest.main()