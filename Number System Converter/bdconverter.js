'use strict';

process.stdin.setEncoding('utf8');
var os = require('os');
var input = "";

process.stdin.on("data", (data) => {
	input = data.split(os.EOL)[0];
	process.stdin.emit('end');
});

process.stdin.on('end', _ => {
	main(input);
});

function ShowB2D (binary) {
	var decimal = 0;
	for (var i = 0; i < binary.length; i++) {
		decimal += parseInt(binary[i]) * Math.pow(2, binary.length - i - 1);
	}
	console.log("BIN " + binary + " = " + decimal + " DEC");
	ShowD2B(binary);
}

function ShowD2B (number) {
	var binary = "";
	var decimal = parseInt(number);
	while (decimal > 0) {
		binary = (decimal % 2).toString() + binary;
		decimal = parseInt(decimal / 2);
	}
	console.log("DEC " + number + " = " + binary + " BIN");
}

function main(input) {
	var decimal = false;
	var arr = input.split("");

	// Using some with return ture to break loop.
	arr.some(value => {
		if (value > 1) {
			decimal = true;
			return decimal;
		}
	});

/*
	// Using every with return false to break loop.
	arr.every(value => {
		if (value > 1) {
			decimal = true;
			return !decimal;
		}
	});
*/
/*
	// Using forEach and exception to break loop.
	try {
		arr.forEach(value => {
			if (value > 1) {
				decimal = true;
				throw decimal;
			}
		});
	} catch (e) {
		if (e !== true) throw e;
	}
*/

	// Following calls arrow expression with condition expression.
//	var f = decimal ? str => ShowD2B(input) : str => ShowB2D(input);
//	f(input)

	decimal ? ShowD2B(input) : ShowB2D(input);
}