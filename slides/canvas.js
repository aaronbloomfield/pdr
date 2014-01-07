// this code adapted from http://stackoverflow.com/questions/2368784/draw-by-mouse-with-html5-canvas and http://stackoverflow.com/questions/4037212/html-canvas-full-screen

var canvas, ctx, flag = false,
    prevX = 0,
    currX = 0,
    prevY = 0,
    currY = 0,
    dot_flag = false;

var x = "red",
    y = 2;

var xoffset = 0,
    yoffset = 0;

var calibrateimg = new Image();

function init() {
    canvas = document.getElementById('canvas');
    ctx = canvas.getContext("2d");
    canvas.width = document.body.clientWidth;
    canvas.height = document.body.clientHeight;
    w = canvas.width;
    h = canvas.height;

    canvas.addEventListener("mousemove", function (e) {
        findxy('move', e)
    }, false);
    canvas.addEventListener("mousedown", function (e) {
        findxy('down', e)
    }, false);
    canvas.addEventListener("mouseup", function (e) {
        findxy('up', e)
    }, false);
    canvas.addEventListener("mouseout", function (e) {
        findxy('out', e)
    }, false);

    calibrateimg.src = "images/calibrate.png";
}

function color(obj) {
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
    if (x == "white") y = 14;
    else y = 2;
}

function draw() {
    ctx.beginPath();
    ctx.moveTo(prevX-xoffset, prevY-yoffset);
    ctx.lineTo(currX-xoffset, currY-yoffset);
    ctx.strokeStyle = x;
    ctx.lineWidth = y;
    ctx.stroke();
    ctx.closePath();
}

function erase() {
    var m = confirm("Want to clear?");
    if (m) {
        ctx.clearRect(0, 0, w, h);
        document.getElementById("canvasimg").style.display = "none";
    }
}

function save() {
    document.getElementById("canvasimg").style.border = "2px solid";
    var dataURL = canvas.toDataURL();
    document.getElementById("canvasimg").src = dataURL;
    document.getElementById("canvasimg").style.display = "inline";
}

function findxy(res, e) {
    if (res == 'down') {
        prevX = currX;
        prevY = currY;
        currX = e.clientX - canvas.offsetLeft;
        currY = e.clientY - canvas.offsetTop;

        flag = true;
        dot_flag = true;
        if (dot_flag) {
            ctx.beginPath();
            ctx.fillStyle = x;
            ctx.fillRect(currX, currY, 2, 2);
            ctx.closePath();
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
            currX = e.clientX - canvas.offsetLeft;
            currY = e.clientY - canvas.offsetTop;
            draw();
        }
    }
}


//----------------------------------------
// calibrate functions
//----------------------------------------

function on_mousedown_for_calibrate(e) {
    // determine the vertical and horizontal offset
    var top = parseInt(calibratewin.style.top, 10);
    var left = parseInt(calibratewin.style.left, 10);
    var vertoff = e.clientY - top - (calibrateimg.height+1) / 2 + 12;
    var horizoff = e.clientX - left - (calibrateimg.width+1) / 2 + 12;

    // vertical offset should be 400; data:
    // 725 550 300 37 1487: at center
    // 594 550 300 -94 1487: at top
    // 854 550 300 166 1487: at bottom

    yoffset = (canvas.height-e.clientY)/2;
    xoffset = (canvas.width-e.clientX)/2;

    alert("vert: " +e.clientY+" "+top+" "+(calibrateimg.height+1)+" "+vertoff +" "+canvas.height + " / horiz: " + e.clientX+" "+left+" "+(calibrateimg.width+1)+" "+horizoff+" "+canvas.width + " -> " + yoffset + ", " + xoffset + " (should be 400,163)");

    // all done!  close window.  This also un-grays out the window
    calibratewin.close();
}

function calibrate() {
    grayOut(true);

    // create the window: the window must be created BEFORE one modifies the objects in the window.
    calibratewin = dhtmlwindow.open('divbox', 'div', 'calibratediv', 'Calibrate', 'width=' + ((calibrateimg.width+1) + 6) + 'px,height=' + ((calibrateimg.height+1) + 60) + 'px,center=1,resize=0,scrolling=0');
    calibratewin.onclose = function () {
        grayOut(false);
        return true;
    };

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
