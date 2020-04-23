//////////////////////////////////////
// rollover.js
//////////////////////////////////////
// Copyright 2005 Christopher Gronbeck
// christopher@susdesign.com
//////////////////////////////////////

function PopUp (filename, windowName, type) {

	switch (type) {
	
		case 'medium':
		
			parameters = "width=600,height=400,scrollbars=yes";
		
			break;

		case 'large':
		
			parameters = "width=1000,height=700,scrollbars=yes,resizable=yes";
		
			break;
	}

	window.open (filename, windowName, parameters);

	windowName.focus ();
}
