// this code adapted from
// http://stackoverflow.com/questions/2368784/draw-by-mouse-with-html5-canvas
// and
// http://stackoverflow.com/questions/4037212/html-canvas-full-screen

var canvas, ctx, flag = false,
    prevX = 0,
    currX = 0,
    prevY = 0,
    currY = 0,
    dot_flag = false;

var x = "red",
  y = 2,
  w = 0,
  h = 0;

// These are the offsets from where the mouse is to where the canvas
// mousedown point is.  If the offsets are BOTH set to zero, then the
// canvasinit() function will try to calibrate them (likely
// unsuccessfully).  If EITHER are set to non-zero, then it will
// assume those are the initial values to start with; these values can
// be determined by selecting the 'notify' checkbox when doing a
// calibrate

var xoffset = -60, // the x offset for canvas drawing, computed in canvasinit()
    yoffset = -66; // the x offset for canvas drawing, computed in canvasinit()

var calibrateimg = new Image(); // the calibrate image target
var canvases = new Array(); // holds a map of the canvas IDs to their CTX's
var canvas_border = 100; // how much wider than the slide itselt to allow drawing
var colors = new Array("red","orange","yellow","green","blue","purple","white","black"); // drawing colors
var numCanvases = 0;

function canvasinit() {
  for ( var id in canvases ) {
    canvas = document.getElementById(id);
    canvases[id] = canvas.getContext("2d");
    canvas.width = 960+2*canvas_border; // the width of the reveal.js slides
    canvas.height = 700+2*canvas_border; // the height of the reveal.js slides
    w = canvas.width; // all are assumed to be the same size
    h = canvas.height; // all are assumed to be the same size

    canvas.addEventListener("mousemove", function (e) {
        findxy('move', e, this.id)
    }, false);
    canvas.addEventListener("mousedown", function (e) {
        findxy('down', e, this.id)
    }, false);
    canvas.addEventListener("mouseup", function (e) {
        findxy('up', e, this.id)
    }, false);
    canvas.addEventListener("mouseout", function (e) {
        findxy('out', e, this.id)
    }, false);

    calibrateimg.src = "../slides/images/calibrate.png";

    if ( (xoffset == 0) && (yoffset == 0) ) {
      var pos = getPosition(canvas);
      yoffset = pos.offsetTop + canvas_border;
      xoffset = pos.offsetLeft + canvas_border;
    }
  }
  //alert("offsets: (x,y) = (" + xoffset + "," + yoffset + ")");
}

function color(obj, which) {
    switch (obj.id) {
        case "green":
            x = "green";
            break;
        case "blue":
            x = "blue";
            break;
        case "red":
            x = "red";
            break;
        case "yellow":
            x = "yellow";
            break;
        case "orange":
            x = "orange";
            break;
        case "black":
            x = "black";
            break;
        case "white":
            x = "white";
            break;
    }
    y = 2;
    //if (x == "white") y = 14; // enable if the eraser is set
    menutoggle(which);
}

function draw(which) {
    canvases[which].beginPath();
    canvases[which].moveTo(prevX-xoffset, prevY-yoffset);
    canvases[which].lineTo(currX-xoffset, currY-yoffset);
    canvases[which].strokeStyle = x;
    canvases[which].lineWidth = y;
    canvases[which].stroke();
    canvases[which].closePath();
}

function erase(which) {
  //var m = confirm("Want to clear?");
  //if (m) {
  canvases['canvas_'+which].clearRect(0, 0, w, h);
  //document.getElementById("canvasimg").style.display = "none";
  //}
  menutoggle(which);
}

function save(which) {
  // NOT WORKING, as I broke it when allowing multiple canvases
    document.getElementById("canvasimg").style.border = "2px solid";
    var dataURL = canvas.toDataURL();
    document.getElementById("canvasimg").src = dataURL;
    document.getElementById("canvasimg").style.display = "inline";
}

function findxy(res, e, which) {
    var canvas = document.getElementById(which);
    //canvas.offsetTop = canvas_border;
    //canvas.offsetLeft = canvas_border;
    //console.log("findxy("+res+","+e+","+which+"): canvas offsets ("+canvas.offsetLeft+","+canvas.offsetTop+"), (x,y) offsets (" + xoffset +","+yoffset+") and canvas border "+canvas_border);
    if (res == 'down') {
        prevX = currX;
        prevY = currY;
        currX = e.clientX; // - xoffset; //canvas.offsetLeft;
        currY = e.clientY; // - yoffset; //canvas.offsetTop;

        flag = true;
        dot_flag = false; // this was true, but was causing a stray pixel to be drawn from the natural (i.e., not offset) position, so it was turned to false
        if (dot_flag) {
            canvases[which].beginPath();
            canvases[which].fillStyle = x;
            canvases[which].fillRect(currX, currY, 2, 2);
            canvases[which].closePath();
            dot_flag = false;
        }
    }
    if (res == 'up' || res == "out") {
        flag = false;
    }
    if (res == 'move') {
        if (flag) {
            prevX = currX;
            prevY = currY;
            currX = e.clientX; // - xoffset; //canvas.offsetLeft;
            currY = e.clientY; // - yoffset; //canvas.offsetTop;
            draw(which);
        }
    }
}


// this function from
// http://stackoverflow.com/questions/9040768/getting-coordinates-of-objects-in-js

function getPosition(elem) {
    var dims = {offsetLeft:0, offsetTop:0};
    do {
        dims.offsetLeft += elem.offsetLeft;
        dims.offsetTop += elem.offsetTop;
    }
    while ( (elem = elem.offsetParent) );
    return dims;
}


//----------------------------------------
// calibrate functions
//----------------------------------------

var calibratewin;
var which_canvas_id;

function on_mousedown_for_calibrate(e) {
    // determine the vertical and horizontal offset
    var top = parseInt(calibratewin.style.top, 10);
    var left = parseInt(calibratewin.style.left, 10);
    
    // for the spot that was clicked:
    // * e.clientY is the distance from that to the top of the browser window (example: 437)
    // * top (from above) is the distance between the top of the dynamic window and the top of the browser window (example: 265)
    // * (calibrateimg.height+1) is the height of the image (example: 300)
    // * there are 22 pixels above the image (the "Calibrate" title window)
    //
    // so in the example above, the click was in the center because 437-265=300/2+22
    // or because 437-265-300/2-22 = 0
    // so the vertical offset is e.clientY - top - (calibrateimg.height+1)/2 - 22
    //
    // likewise with the horizontal, but the extra is 4 instead of 22

    var vertoff = e.clientY - top - (calibrateimg.height+1) / 2 - 22;
    var horizoff = e.clientX - left - (calibrateimg.width+1) / 2 - 4;

    var pos = getPosition(document.getElementById('canvas_'+which_canvas_id));
    yoffset = pos.offsetTop + vertoff;
    xoffset = pos.offsetLeft + horizoff;

    //console.log("calibrate: horizoff = " + horizoff + ", vertoff = " + vertoff + ", new offsets: (" + xoffset + "," + yoffset + "), pos.offset: (" + pos.offsetLeft+","+pos.offsetTop+")");

    //console.log("vert: " +e.clientY+" "+top+" "+(calibrateimg.height+1)+" "+vertoff +" "+canvas.height + " / horiz: " + e.clientX+" "+left+" "+(calibrateimg.width+1)+" "+horizoff+" "+canvas.width + " -> (" + xoffset + ", " + yoffset + "); canvas at top:" + getPosition(document.getElementById('canvas_'+which_canvas_id)).offsetTop + ", left:" + getPosition(document.getElementById('canvas_'+which_canvas_id)).offsetLeft);

    // all done!  close window.  This also un-grays out the window
    calibratewin.close();

    if ( document.getElementById('cal_notify_'+which_canvas_id).checked ) {
	alert ("calibration set to (" + xoffset + "," + yoffset + ")");
    }
}

function calibrate(which) {
    grayOut(true);

    // create the window: the window must be created BEFORE one modifies the objects in the window.
    calibratewin = dhtmlwindow.open('divbox', 'div', 'calibratediv', 'Calibrate', 'width=' + ((calibrateimg.width+1) + 6) + 'px,height=' + ((calibrateimg.height+1) + 60) + 'px,center=1,resize=0,scrolling=0');
    calibratewin.onclose = function () {
        grayOut(false);
        return true;
    };

    // set which canvas ID we are on, so the event listener knows where to grab the position from
    which_canvas_id = which;    

    // get the elements, and set the mousedown listener
    //var caldiv = document.getElementById("calibratecanvasdiv");
    var calcan = document.getElementById("calibratecanvas");
    calcan.addEventListener("mousedown", on_mousedown_for_calibrate, false);

    // display the image in the canvas
    // the image is loaded in init()
    //while ( !calibrateimg.complete );
    var ctx2 = calcan.getContext("2d");
    ctx2.clearRect(0, 0, (calibrateimg.width+1), (calibrateimg.height+1));
    ctx2.drawImage(calibrateimg, 0, 0, (calibrateimg.width+1), (calibrateimg.height+1));

    menutoggle(which);
}

function grayOut(vis, optionsparam) {
    // this function from http://www.hunlock.com/blogs/Snippets:_Howto_Grey-Out_The_Screen
    //
    // Pass true to gray out screen, false to ungray
    // options are optional.  This is a JSON object with the following (optional) properties
    // opacity:0-100         // Lower number = less grayout higher = more of a blackout 
    // zindex: #             // HTML elements with a higher zindex appear on top of the gray out
    // bgcolor: (#xxxxxx)    // Standard RGB Hex color code
    // grayOut(true, {'zindex':'50', 'bgcolor':'#0000FF', 'opacity':'70'});
    // Because options is JSON opacity/zindex/bgcolor are all optional and can appear
    // in any order.  Pass only the properties you need to set.
    var options = optionsparam || {};
    var zindex = options.zindex || 50;
    var opacity = options.opacity || 70;
    var opaque = (opacity / 100);
    var bgcolor = options.bgcolor || '#000000';
    var dark = document.getElementById('darkenScreenObject');
    if (!dark) {
        // The dark layer doesn't exist, it's never been created.  So we'll
        // create it here and apply some basic styles.
        // If you are getting errors in IE see: http://support.microsoft.com/default.aspx/kb/927917
        var tbody = document.getElementsByTagName("body")[0];
        var tnode = document.createElement('div'); // Create the layer.
        tnode.style.position = 'absolute'; // Position absolutely
        tnode.style.top = '0px'; // In the top
        tnode.style.left = '0px'; // Left corner of the page
        tnode.style.overflow = 'hidden'; // Try to avoid making scroll bars            
        tnode.style.display = 'none'; // Start out Hidden
        tnode.id = 'darkenScreenObject'; // Name it so we can find it later
        tbody.appendChild(tnode); // Add it to the web page
        dark = document.getElementById('darkenScreenObject'); // Get the object.
    }
    if (vis) {

        var pageWidth, pageHeight;
        // Calculate the page width and height 
        if (document.body && (document.body.scrollWidth || document.body.scrollHeight)) {
            pageWidth = document.body.scrollWidth + 'px';
            pageHeight = document.body.scrollHeight + 'px';
        } else if (document.body.offsetWidth) {
            pageWidth = document.body.offsetWidth + 'px';
            pageHeight = document.body.offsetHeight + 'px';
        } else {
            pageWidth = '100%';
            pageHeight = '100%';
        }
        //set the shader to cover the entire page and make it visible.
        dark.style.opacity = opaque;
        dark.style.MozOpacity = opaque;
        dark.style.filter = 'alpha(opacity=' + opacity + ')';
        dark.style.zIndex = zindex;
        dark.style.backgroundColor = bgcolor;
        dark.style.width = pageWidth;
        dark.style.height = pageHeight;
        dark.style.display = 'block';
    } else {
        dark.style.display = 'none';
    }
}

//----------------------------------------
// canvas insertion function
//----------------------------------------

function insertCanvas() {
  var which = ++numCanvases;
  canvases['canvas_'+which] = false;
  document.write('\
<canvas id="canvas_'+which+'" width="1000" height="1000" style="position:absolute;top:-'+canvas_border+'px;left:-'+canvas_border+'px;border:0px solid"></canvas> \
<!-- <table class="default" style="position:absolute;bottom:-15%"> --> \
<table class="transparent" style="position:fixed;bottom:-150px"><tr> \
<td><input type="image" src="../slides/images/menu-icon.png" id="menu" onclick="menutoggle('+which+')"></td> \
<td><div id="menu_'+which+'" style="display:none"> \
<table class="default"> \
      <tr> \
	<td><input type="button" value="clear" id="clr" onclick="erase('+which+')"></td> \
	<td><input type="button" value="calibrate" id="cal" onclick="calibrate('+which+')"></td> \
	<td><input type="checkbox" value="notify" id="cal_notify_' + which + '"><span style="margin-top:20px;font-size:50%">notify</span></td> \
	<td><input type="button" value="close" id="cal" onclick="menutoggle('+which+')"></td> \
	<td style="width:10px"></td> \
');

  for ( var i in colors ) {
    document.write('<td><div style="width:15px;height:15px;background:' + colors[i] + ';" id="' + colors[i] + '" onclick="color(this,' + which + ')"></div></td>');
  }

  document.write('\
	<td style="width:50px"></td> \
      </tr> \
    </table> \
</div></td> \
</tr></table> \
');

  // stuff not included in the above:
  // <td><input type="button" value="save" id="btn" size="30" onclick="save('+which+')"></td>
  // <td>Eraser: </td>
  // <td><div style="width:30px;height:30px;background:white;border:2px solid;" id="white" onclick="color(this)"></div> -->

}

//----------------------------------------
// menu pop-up
//----------------------------------------

function menutoggle(which) {
  //alert("offsets: (x,y) = (" + xoffset + "," + yoffset + ")");
  if ( document.getElementById('menu_'+which).style.display == 'none' )
    document.getElementById('menu_'+which).style.display = 'block';
  else
    document.getElementById('menu_'+which).style.display = 'none';
}
