var names = ['btn0', 'btn1', 'btnClr', 'btnEql',
			 'btnSum', 'btnSub', 'btnMul', 'btnDiv'];
var surfaces = ['0', '1', 'C', '=', '+', '-', '*', '/'];

var op1 = '', op = '', op2 = '', str = '';

for (let i = 0; i < 8; i++) {
	var btn = document.createElement('button');
	btn.id = names[i];
	btn.innerHTML = surfaces[i];
	btn.className = 'buttonClass';
	document.body.appendChild(btn);


	if (btn.id == 'btnClr')	{
		btn.addEventListener('click', _ => {
			op1 = op = op2 = str = '';
			document.getElementById('res').innerHTML = str;
		});
	} else if (btn.id == 'btnEql') {
		btn.addEventListener('click', _ => {
			str = parseInt(op1, 2) + op + parseInt(op2, 2);
			var ans = parseInt(eval(str)).toString(2);
			document.getElementById('res').innerHTML = ans;
			op1 = ans;
			op = op2 = str = '';
		});
	} else if (btn.id != 'res') {
		btn.addEventListener('click', e => {
			var pressed = e.target || e.srcElement;

			if (pressed.id == 'btn0' || pressed.id == 'btn1') {
				if (op == '') {
					op1 += pressed.innerHTML;
				} else {
					op2 += pressed.innerHTML;
				}
			} else {
				op = pressed.innerHTML;
			}

			str = op1 + op + op2;
			document.getElementById('res').innerHTML = str;
		});
	}
}


