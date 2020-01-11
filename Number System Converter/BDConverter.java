import java.util.Scanner;

public class BDConverter {
	// Function interface for lambda expression.
	interface FuncInterface1 {
		void AbstractFunc1();
	}

	interface FuncInterface2 {
		String AbstractFunc2(String s);
	}


	static void ShowB2D(String bin) {
		int decimal = 0;
		for (int i = 0; i < bin.length(); i++) {
			decimal += Integer.parseInt(bin.substring(i,i+1)) * Math.pow(2, bin.length() - i - 1);
		}
		System.out.println("BIN " + bin + " = " + decimal + " DEC");
	}

	static void ShowD2B(String number) {
		String binary = "";
		int decimal = Integer.parseInt(number);
		while (decimal != 0) {
			binary = Integer.toString(decimal % 2) + binary;
			decimal /= 2;
		}
		System.out.println("DEC " + number + " = " + binary + " BIN");
	}


	static String B2D(String bin) {
		int decimal = 0;
		for (int i = 0; i < bin.length(); i++) {
			decimal += Integer.parseInt(bin.substring(i,i+1)) * Math.pow(2, bin.length() - i - 1);
		}
		return Integer.toString(decimal);
	}

	static String D2B(String number) {
		String binary = "";
		int decimal = Integer.parseInt(number);
		while (decimal != 0) {
			binary = Integer.toString(decimal % 2) + binary;
			decimal /= 2;
		}
		return binary;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("What number do you want to convert? ");
		String get = input.next();

		boolean decimal = false;
		for (int i = 0; i < get.length(); i++) {
			if (Integer.parseInt(get.substring(i,i+1)) > 1) {
				decimal = true;
				break;
			}
		}

		if (decimal) {
			System.out.println();
			System.out.println("Using lambda without parameter:");
			FuncInterface1 f = decimal ? () -> ShowD2B(get) : () -> ShowB2D(get);
			f.AbstractFunc1();

			System.out.println();
			System.out.println("Using lambda with parameter:");
			FuncInterface2 f2 = decimal ? str -> D2B(get) : str -> B2D(get);
			System.out.println("DEC " + get + " = " + f2.AbstractFunc2(get) + " BIN");
		} else {
			System.out.println();
			System.out.println("Using lambda without parameter:");
			FuncInterface1 f = () -> ShowD2B(get);
			f.AbstractFunc1();
			f = () -> ShowB2D(get);
			f.AbstractFunc1();
			

			System.out.println();
			System.out.println("Using lambda with parameter:");
			FuncInterface2 f2 = str -> D2B(get);
			System.out.println("DEC " + get + " = " + f2.AbstractFunc2(get) + " BIN");
			f2 = str -> B2D(get);
			System.out.println("BIN " + get + " = " + f2.AbstractFunc2(get) + " DEC");
		}
	}
}