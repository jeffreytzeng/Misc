for (var i = 1; i < 10; i++) {
	var btn = document.createElement('button');
	btn.id = 'btn' + i;
	btn.className = 'buttonClass';
	btn.innerHTML = i;
	document.body.appendChild(btn);
}

var btns = [1, 2, 3, 6, 9, 8, 7, 4];
var pos = Array.from(btns);
var btn5 = document.getElementById('btn5');

btn5.addEventListener('click', _ => {
	btns.unshift(btns.pop());

	for (let i = 0; i < 8; i++) {
		document.getElementById('btn' + pos[i]).innerHTML = btns[i];
	}
});