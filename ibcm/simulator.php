<?php
// global variables
$CPAGE = isset($_GET["CPAGE"]) ? $_GET["CPAGE"] : "";
if($CPAGE=="")
  $CPAGE="unloaded";
$mem = array();
$filestatus = "";
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">
 <head>
  <meta http-equiv="content-type" content="text/html;charset=utf-8" />
  <meta name="description" content="Site description" />
  <meta name="keywords" content="IBCM, Itty Bitty Computing Machine" />
  <title>IBCM Interface: Simulator</title>
  <link rel="stylesheet" type="text/css" href="ibcm.css" media="screen" />

<?php
function load_ibcm_file () {
  global $CPAGE;
  global $mem;
  global $filestatus;
  if($CPAGE=="loaded")
    $errornum = $_FILES['userfile']['error'];

  // error codes:
  // 0 - successful upload
  // 1 - file exceeds maximum upload size
  // 2 - file exceeds maximum file size
  // 3 - file partially uploaded
  // 4 - no file uploaded

  if (($errornum == 1) or ($errornum == 2)) {
    $filestatus = "Error: The file uploaded was too big! The maximum file size that can be uploaded is " . ini_get("upload_max_filesize") . "; but above " . ini_get("post_max_size") . ", it won't even indicate a file upload has been attempted. To fix this, you need to set the values (in php.ini) of upload_max_filesize and post_max_size.";
  } else if ( $errornum == 3 ) {
    $filestatus = "Error: 'file partially uploaded'. No idea what this means -- try it again.";
  } else if ( $errornum == 4 ) {
    $filestatus = "Error: You must select a valid file!";
  } else {
    if ( $_FILES['userfile']['tmp_name'] != "" ) {
      $fp = fopen($_FILES['userfile']['tmp_name'],"r");
      $n=0;         // line number of memory
      $linenum=0;   // line number of file (includes comments and blank lines)

      // Check file format
      while( !feof($fp) ) {
        $line = trim(fgets($fp));
        $linenum++;

        // ignore blank lines and comments
        if ( $line == "" )
          continue;
        if ( substr($line,0,2) == "//" )
          continue;
        if ( substr($line,0,1) == "#"  )
          continue;

        // validate the line starts with 4 hex digits
        $hexline = substr($line,0,4);
        if (!preg_match('/^[a-fA-F0-9]{4}/', $hexline)) {
          $filestatus = "Error: The file is malformed at line " . $linenum . " -- please fix and try again.";

          // reset contents of memory, close file, and exit early
          $mem = array();
          fclose($fp);
          return;
        }

        // insert line into memory
        $mem[$n++] = $hexline;
      }

      // determine upper bound of memory
      $top = 100;
      if ( isset($_POST['loadmem']) && $_POST['loadmem'] )
        $top = 4096;

      // fill in remaining spots with 0's
      for ( ; $n < $top; $n++ )
        $mem[$n] = "0000";

      fclose($fp);
    }
  }
}
// if the user posted a file in this request, then load it
if (isset($_FILES['userfile'])) {
  load_ibcm_file();
}
?>

<script type="text/javascript">
<!--
function revert() {
  reset();
<?php
  foreach ( array_keys($mem) as $key )
    echo "  document.getElementById('v" . sprintf("%04x", $key) . "').value = '$mem[$key]';\n";
?>
}
-->
</script>
<script language="javascript1.2" type="text/javascript" src="simulator.js"></script>

 </head>

 <body onload="init()">
  <!-- Master Container: 88px Tall -->
  <div id="wrap">
   <div id="top">
    <h2><a href="./index.html" title="Back to main page">IBCM Interface</a></h2>
     <!-- Top Menu Container -->
     <div id="menu">
      <ul>
       <li><a href="./index.html">Home</a></li>
       <li><a href="./directions.html">Directions</a></li>
       <li><a href="./simulator.php" class="current">Simulator</a></li>
      </ul>
     </div> <!-- id="menu" -->
   </div> <!-- id="top" -->

   <!-- Main Content Container -->
   <div id="content2">
    <p class="center"><a href="directions.html">Directions for how to use this simulator</a> are available.</p>
    <table border="7" cellpadding="10">
     <!-- Browse section -->
     <tr><td colspan="2" align="center">

     <form id="simulate" name="simulate" enctype="multipart/form-data" action="./simulator.php?CPAGE=loaded" method="post">
      <p class="center">Load IBCM file:
        <input type="file" name="userfile" tabindex="4" size="20" />
        <input type="submit" value="Load" />
      </p>
      <p class="center danger">
        <?php echo $filestatus; ?>
      </p>
      <p class="center">Load all of memory: <input type="checkbox" id="loadmem" name="loadmem"
      <?php if ( isset($_POST['loadmem']) && $_POST['loadmem'] )
        echo " checked";
      ?>> (leave unchecked if unsure)</p>
      <p class="center">Enable watchdog timer: <input type="checkbox" id="watchtimer" name="watchtimer"
      <?php if ( isset($_POST['watchtimer']) && $_POST['watchtimer'] )
        echo " checked";
      ?>> (check to guard against infinite loops)</p>
      <p id="watchwarning" class="center danger"></p>
     </form>

     </td></tr>

     <!-- Mem Table -->
     <tr><td>
      <div id="tabletitle"><table border="7" width="300"><tr><th>Mem</th><th>Value</th><th>PC</th></tr></table></div>
      <div id="tbl-container">
      <div id="memtable"></div>
      </div> <!-- id="tbl-container" -->
     </td>

     <!-- Accum and Input Section -->
     <td valign="top">

      <table border=0>
       <tr><td><p class="righttitle">Accumulator (hex): </p></td><td>&nbsp;<input name="accum" id="accum" type="text" value="0000" readonly="readonly"/></td></tr>
       <tr><td>&nbsp;</td><td>&nbsp;</td></tr>
       <tr><td><p class="righttitle">PC (hex): </p></td><td>&nbsp;<input name="pc" id="pc" type="text" value="0000" readonly="readonly"/></td></tr>
       <tr><td>&nbsp;</td><td>&nbsp;</td></tr>
       <tr><td><p class="righttitle"><div id="bptitle">Breakpoint (4 digits): </div></p></td><td>&nbsp;<input name="breakpoint" id="breakpoint" type="text" value="" /></td></tr>
       <tr><td>&nbsp;</td><td>&nbsp;</td></tr>
       <tr><td><p class="righttitle"><div id="inputtitle">Input: </div></p></td><td>&nbsp;<input name="input" id="input" type="text" value="0" /></td></tr>
      </table>

      <p>&nbsp;</p><hr /><p>&nbsp;</p>

      <table border="5" cellpadding="25">
       <tr>
        <td><input name="Runner" type="button" value="Run" onclick='run_simulator()'/></td>
        <td><input name="Stepper" type="button" value="Step" onclick="step_simulator()" /></td>
       </tr>
       <tr>
        <td><input name="Resetter" type="button" value="Reset" onclick="reset()" /></td>
        <td><input name="Reverter" type="button" value="Revert" onclick="revert()" /></td>
       </tr>
      </table>

      <p>&nbsp;</p><hr /><p>&nbsp;</p>

      <!-- Display Section -->
      <p class="center">Output</p>
      <textarea name="output" id="output" cols="40" rows="15" readonly="readonly"></textarea>

      <!-- Separation Divider -->
      <div id="clear">
      </div> <!-- id="clear" -->

      </td>
     </tr>
    </table>

   </div> <!-- id="content2" -->
     
   <!-- Footer -->
   <div id="footer">
   </div>

  </div> <!-- id="wrap" -->
 </body>
</html>
