// Handle ENTER (key id 13) key press
// adapted from http://www.digitalsymmetry.co.uk/web-design-code.php?id=32
nn=(document.layers)?true:false;
ie=(document.all)?true:false;
function keyDown(e) {
  var evt=(e)?e:(window.event)?window.event:null;
  if(evt) {
    var key=(evt.charCode)?evt.charCode:((evt.keyCode)?evt.keyCode:((evt.which)?evt.which:0));
    if(key==13) {
      handleReturn();
    }
  }
}
document.onkeydown=keyDown;
if(nn) document.captureEvents(Event.KEYDOWN); 
function handleReturn () {
  if ( during_input )
    run_simulator();
}

var pchex = "0000";
var pchexbak = "0000";
var during_input = 0;

function reset() {
  document.getElementById("accum").value = "0000";
  document.getElementById("pc").value = "0000";
  if ( pchex != "xxxx" )
    document.getElementById("pc"+pchex).innerHTML=""; // erase old PC
  document.getElementById("pc"+pchexbak).innerHTML=""; // erase old PC
  document.getElementById("pc0000").innerHTML = "<-";
  pchex = "0000";
  document.getElementById("inputtitle").innerHTML = "Input:";
  document.getElementById("input").value = "";
  document.getElementById("output").value = "";
  during_input = 0;
  document.getElementById("bptitle").innerHTML = "Breakpoint (4 digits): ";
}


/**
*
*  Javascript sprintf
*  http://www.webtoolkit.info/
*
*
**/

sprintfWrapper = {

    init : function () {

        if (typeof arguments == "undefined") { return null; }
        if (arguments.length < 1) { return null; }
        if (typeof arguments[0] != "string") { return null; }
        if (typeof RegExp == "undefined") { return null; }

        var string = arguments[0];
        var exp = new RegExp(/(%([%]|(\-)?(\+|\x20)?(0)?(\d+)?(\.(\d)?)?([bcdfosxX])))/g);
        var matches = new Array();
        var strings = new Array();
        var convCount = 0;
        var stringPosStart = 0;
        var stringPosEnd = 0;
        var matchPosEnd = 0;
        var newString = '';
        var match = null;

        while (match = exp.exec(string)) {
            if (match[9]) { convCount += 1; }

            stringPosStart = matchPosEnd;
            stringPosEnd = exp.lastIndex - match[0].length;
            strings[strings.length] = string.substring(stringPosStart, stringPosEnd);

            matchPosEnd = exp.lastIndex;
            matches[matches.length] = {
                match: match[0],
                left: match[3] ? true : false,
                sign: match[4] || '',
                pad: match[5] || ' ',
                min: match[6] || 0,
                precision: match[8],
                code: match[9] || '%',
                negative: parseInt(arguments[convCount]) < 0 ? true : false,
                argument: String(arguments[convCount])
            };
        }
        strings[strings.length] = string.substring(matchPosEnd);

        if (matches.length == 0) { return string; }
        if ((arguments.length - 1) < convCount) { return null; }

        var code = null;
        var match = null;
        var i = null;

        for (i=0; i<matches.length; i++) {

            if (matches[i].code == '%') { substitution = '%' }
            else if (matches[i].code == 'b') {
                matches[i].argument = String(Math.abs(parseInt(matches[i].argument)).toString(2));
                substitution = sprintfWrapper.convert(matches[i], true);
            }
            else if (matches[i].code == 'c') {
                matches[i].argument = String(String.fromCharCode(parseInt(Math.abs(parseInt(matches[i].argument)))));
                substitution = sprintfWrapper.convert(matches[i], true);
            }
            else if (matches[i].code == 'd') {
                matches[i].argument = String(Math.abs(parseInt(matches[i].argument)));
                substitution = sprintfWrapper.convert(matches[i]);
            }
            else if (matches[i].code == 'f') {
                matches[i].argument = String(Math.abs(parseFloat(matches[i].argument)).toFixed(matches[i].precision ? matches[i].precision : 6));
                substitution = sprintfWrapper.convert(matches[i]);
            }
            else if (matches[i].code == 'o') {
                matches[i].argument = String(Math.abs(parseInt(matches[i].argument)).toString(8));
                substitution = sprintfWrapper.convert(matches[i]);
            }
            else if (matches[i].code == 's') {
                matches[i].argument = matches[i].argument.substring(0, matches[i].precision ? matches[i].precision : matches[i].argument.length)
                substitution = sprintfWrapper.convert(matches[i], true);
            }
            else if (matches[i].code == 'x') {
                matches[i].argument = String(Math.abs(parseInt(matches[i].argument)).toString(16));
                substitution = sprintfWrapper.convert(matches[i]);
            }
            else if (matches[i].code == 'X') {
                matches[i].argument = String(Math.abs(parseInt(matches[i].argument)).toString(16));
                substitution = sprintfWrapper.convert(matches[i]).toUpperCase();
            }
            else {
                substitution = matches[i].match;
            }

            newString += strings[i];
            newString += substitution;

        }
        newString += strings[i];

        return newString;

    },

    convert : function(match, nosign){
        if (nosign) {
            match.sign = '';
        } else {
            match.sign = match.negative ? '-' : match.sign;
        }
        var l = match.min - match.argument.length + 1 - match.sign.length;
        var pad = new Array(l < 0 ? 0 : l).join(match.pad);
        if (!match.left) {
            if (match.pad == "0" || nosign) {
                return match.sign + pad + match.argument;
            } else {
                return pad + match.sign + match.argument;
            }
        } else {
            if (match.pad == "0" || nosign) {
                return match.sign + match.argument + pad.replace(/0/g, ' ');
            } else {
                return match.sign + match.argument + pad;
            }
        }
    }
}

sprintf = sprintfWrapper.init;

function create_ibcm_memory_table() {
  str = "<table id=\"tbl\" BORDER=\"7\" width=\"98%\">\n";
  var top = 100;
  if ( document.simulate.loadmem.checked )
      top = 4096;
  for ( i = 0; i < top; i++ ) {
    divname = sprintf ("%04x", i);
    str += "\n<tr><td>" + divname + "</td><td><input type=\"text\" id=\"v" + divname + "\" size=5></td><td><div id=\"pc" + divname + "\"></div></td></tr>";
  }
  str += "</table>";
  document.getElementById("memtable").innerHTML = str;
}


function init() {
  create_ibcm_memory_table();
  revert();
  document.getElementById("bptitle").innerHTML = "Breakpoint (4 digits): ";
}

function run_simulator () {
  var breakpoint = document.getElementById("breakpoint").value;
  document.getElementById("bptitle").innerHTML = "Breakpoint (4 digits): ";
  execute_instruction();
  while ( (pchex != "xxxx") && (!during_input) && (pchex != breakpoint) )
    execute_instruction();
  if ( pchex == breakpoint )
    document.getElementById("bptitle").innerHTML = "<blink>Breakpoint (4 digits): </blink>";
}

function step_simulator () {
  document.getElementById("bptitle").innerHTML = "Breakpoint (4 digits): ";
  execute_instruction();
}

function convert_hex_digit_to_decimal (hex) {
  if ( hex <= '9' )
    return hex;
  else
    return hex.toLowerCase().charCodeAt(0)-"a".charCodeAt(0)+10;
}

function get_IBCM_opcode (hexinst) {
  return convert_hex_digit_to_decimal(hexinst.charAt(0));
}
function get_IBCM_address (hexinst) {
  return parseInt(hexinst.substring(1,4),16);
}
function get_IBCM_2bitop (hexinst) {
  return Math.floor(convert_hex_digit_to_decimal(hexinst.charAt(1))/4);
}
function get_IBCM_shift (hexinst) {
  return convert_hex_digit_to_decimal(hexinst.charAt(3));
}

function increment_pc () {
  pchex = convert_dec_to_hex4(eval(convert_hex_to_dec(pchex)+1));
}

function convert_dec_to_hex4 (value) {
  if ( value < 0 )
    value += 65536;
  hex = value.toString(16);
  if ( hex.length < 4 )
    hex = "0" + hex;
  if ( hex.length < 4 )
    hex = "0" + hex;
  if ( hex.length < 4 )
    hex = "0" + hex;
  hex = hex.toLowerCase();
  return hex;
}

function convert_hex_to_dec (hex) {
  if ( parseInt(hex,16) > 32767 )
    return parseInt(hex,16) - 65536;
  else
    return parseInt(hex,16);
}

function execute_instruction () {
  var hexinst = document.getElementById('v'+pchex).value;
  if ( hexinst == "" )
    hexinst = "0000";
  opcode = eval(get_IBCM_opcode(hexinst));
  var accum = document.getElementById("accum").value;
  hexaddress = hexinst.substring(1,4).toLowerCase();
  document.getElementById("pc"+pchex).innerHTML=""; // erase old PC
  if ( !during_input )
    increment_pc();

  //  try {
    switch (opcode) {
    case 0: // halt
      pchex = convert_dec_to_hex4(eval(convert_hex_to_dec(pchex)-1));
      document.getElementById("pc"+pchex).innerHTML="H";
      document.getElementById("pc").value = pchex + " (halted)";
      pchexbak = pchex; // so the 'H' can be erased by the reset button
      pchex = "xxxx";
      break;
    case 1: // I/O
      var input = document.getElementById("input");
      var output = document.getElementById("output");
      asciimode = get_IBCM_2bitop(hexinst);
      switch ( asciimode ) {
      case 0: // read hex
	// FALL THRU
      case 1: // read ascii
	if ( !during_input ) {
	  if ( asciimode )
	    document.getElementById("inputtitle").innerHTML = "<blink>Input (asc):</blink>";
	  else
	    document.getElementById("inputtitle").innerHTML = "<blink>Input (hex):</blink>";
	  document.getElementById("input").value = "";
	  pchex = convert_dec_to_hex4(eval(convert_hex_to_dec(pchex)-1));
	  document.getElementById("pc"+pchex).innerHTML="I";
	  document.getElementById("pc").value = pchex + " (awaiting input)";
	  during_input = 1;
	  document.getElementById("input").focus();
	  return;
	} else {
	  // is the value empty?
	  if ( document.getElementById("input").value == "" ) {
	    document.getElementById("pc"+pchex).innerHTML="I";
	    document.getElementById("input").focus();
	    return;
	  }

	  document.getElementById("inputtitle").innerHTML = "Input:";
	  document.getElementById("pc"+pchex).innerHTML=""; // remove the 'I'
	  during_input = 0;
	  increment_pc();
	  if ( asciimode ) {
	    accum = convert_dec_to_hex4(document.getElementById("input").value.charCodeAt(0));
	  } else { // hex
	    accum = convert_dec_to_hex4(parseInt(document.getElementById("input").value,16));
	  }

	}
	break;
      case 2: // write hex
	output.value += accum + "\n";
	break;
      case 3: // write ascii
	output.value += String.fromCharCode(convert_hex_to_dec(accum) & 0xff) + "\n";
	break;
      }

      break;
    case 2: // shifts
      shiftamount = get_IBCM_shift(hexinst);
      accdec = convert_hex_to_dec(accum);
      switch ( get_IBCM_2bitop(hexinst) ) {
      case 0: // shift left
	accdec = (accdec << shiftamount) & 0xffff;
	break;
      case 1: // shift right
	accdec = (accdec >> shiftamount) & (0xffff >> shiftamount);
	break;
      case 2: // rotate left
	accdec = ((accdec << shiftamount) & 0xffff) | ((accdec >> 16-shiftamount) & (0xffff >> 16-shiftamount));
	break;
      case 3: // rotate right
	accdec = ((accdec >> shiftamount) & (0xffff >> shiftamount)) | ((accdec << 16-shiftamount) & 0xffff);
	break;	
      }
      accum = convert_dec_to_hex4(accdec);
      break;
    case 3: // load
      var accum = document.getElementById("v0"+hexaddress).value;
      break;
    case 4: // store
      document.getElementById("v0"+hexaddress).value = accum;
      break;
    case 5: // add
      var val = document.getElementById("v0"+hexaddress).value;
      accum = convert_dec_to_hex4(eval(convert_hex_to_dec(accum)+convert_hex_to_dec(val)));
      break;
    case 6: // sub
      var val = document.getElementById("v0"+hexaddress).value;
      accum = convert_dec_to_hex4(eval(convert_hex_to_dec(accum)-convert_hex_to_dec(val)));
      break;
    case 7: // and
      var val = document.getElementById("v0"+hexaddress).value;
      accum = convert_dec_to_hex4(eval(convert_hex_to_dec(accum)&convert_hex_to_dec(val)));
      break;
    case 8: // or
      var val = document.getElementById("v0"+hexaddress).value;
      accum = convert_dec_to_hex4(eval(convert_hex_to_dec(accum)|convert_hex_to_dec(val)));
      break;
    case 9: // xor
      var val = document.getElementById("v0"+hexaddress).value;
      accum = convert_dec_to_hex4(eval(convert_hex_to_dec(accum)^convert_hex_to_dec(val)));
      break;
    case 10: // not
      accum = convert_dec_to_hex4(eval(~convert_hex_to_dec(accum)));
      break;
    case 11: // nop
      // do nothing
      break;
    case 12: // jmp
      pchex = "0"+hexaddress;
      break;
    case 13: // jmpe
      if ( accum == "0000" )
	pchex = "0"+hexaddress;
      break;
    case 14: // jmpl
      if ( convert_hex_to_dec(accum) < 0 )
	pchex = "0"+hexaddress;
      break;
    case 15: // brl
      accum = pchex;
      pchex = "0"+hexaddress;
      break;
    }
    // } catch (err) {
    // alert ("Error executing instruction at address " + pchex + " (" + err + ")");
    //  }

  if ( pchex != "xxxx" ) {
    document.getElementById("pc"+pchex).innerHTML="<-"; // set new PC
    document.getElementById("pc").value = pchex;
  }

  document.getElementById("accum").value = accum.toLowerCase();
}
