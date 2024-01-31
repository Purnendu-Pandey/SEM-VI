//acc.html
<html>
    <head>
        <title> Access </title>
    </head>

    <body>
        <form action="access.php" method="POST">
           Press submit  to go page :<br>
            <input type="submit" value="submit">
        </form>
    </body>
</html>

//access.php
<?php
session_start();

if (isset($_SESSION['cnt'])){
    $_SESSION['cnt']+=1;

}
else{
    $_SESSION['cnt']=1;
}

   $msg="The web page has been accessed ".$_SESSION['cnt'];
   $msg.=" Times ";
?>
<html>
   <head>
       <title> Web page access</title>
   </head>
   <body>
          <?php echo"<br>".$msg."<br>";?>
   </body>
</html>


//empfirst.php
<?php

?>
<html>
    <head>
        <title> first page </title>

    </head>

    <form action="empsecond.php" method="POST">
        Enter employee no : <input type="text" name="no"><br><br>
        Enter employee name : <input type="text" name="name"><br><br>
        Enter employee address : <input type="text" name="address"><br><br>
        <input type="submit" value="submit">

    </form>
</html>

//empsecond.php
<?php

$no=$_POST['no'];
$name=$_POST['name'];
$address=$_POST['address'];
setcookie('no',$no);
setcookie('name',$name);
setcookie('address',$address);
?>
<html>
    <head>
        <title> Second page </title>
    </head>
    <body>
    <?php
         echo"<br>Employee No : ".$no."<br>";
        echo"Employee Name : ".$name."<br>";
        echo"Employee Address : ".$address."<br><br>";
        ?>
    <form action="empthird.php" method="POST">
        Enter salary :<input type="number" name="sal"><br><br>
        Enter DA :<input type="number" name="da"><br><br>
        Enter HRA :<input type="number" name="hra"><br><br>
        <input type="submit" value="Send">
    </form>
</body>
</html>

//empthird.php
<?php
$sal=$_POST['sal'];
$da=$_POST['da'];
$hra=$_POST['hra'];

$total=$sal+$da+$hra;
  if (isset($_COOKIE['no'])){
    $eno=$_COOKIE['no'];
  }
  if (isset($_COOKIE['name'])){
    $ename=$_COOKIE['name'];
  }
  if (isset($_COOKIE['address'])){
    $eadd=$_COOKIE['address'];
  }

?>

<html>
    <head>
        <title> third page by atharv</title>
    </head>
    <body>
    <?php
         echo"<br>Employee No : ".$eno."<br><br>";
        echo"Employee Name : ".$ename."<br>";
        echo"Employee Address : ".$eadd."<br>";
        echo"Employee Salary : ".$sal."<br>";
        echo"Employee DA : ".$da."<br>";
        echo"Employee HRA : ".$hra."<br>";
        echo"Employee's Total salary  : ".$total."<br><br>";
        ?>
    </body>
</html>

//first.php
<?php
// $fstyle=$_POST['fstyle'];
// $fsize=$_POST['fsize'];
// $fcolor=$_POST['fcolor'];
// $bgcolor=$_POST['bgcolor'];


// setcookie('style',$fstyle);
// setcookie('color',$fcolor);
// setcookie('bgcolor',$bgcolor);
// setcookie('size',$fsize);

?>
<html>
    <head>
        <title> Enter page </title>
        <style>
            p{
                /* font-style: ; */
            }
        </style>
    </head>
    <body>
       
        <form action="second.php" method="POST">
          Enter font style : <input type="text" name="fstyle"><br>
          Enter font size : <input type="text" name="fsize"><br>
          Enter font color : <input type="text" name="fcolor"><br>
          Enter bg color : <input type="text" name="bgcolor"><br>
          <input type="submit" value="submit"><br>
        </form>
    </body>
</html>

//second.php
<?php

$fstyle=$_POST['fstyle'];
$fsize=$_POST['fsize'];
$fcolor=$_POST['fcolor'];
$bgcolor=$_POST['bgcolor'];



setcookie('style',$fstyle);
setcookie('color',$fcolor);
setcookie('bgcolor',$bgcolor);
setcookie('size',$fsize);




//    if (isset($_COOKIE['style']))
//    {
//       $st=$_COOKIE['style'];
//    }
//    if (isset($_COOKIE['color']))
//    {
//       $color=$_COOKIE['color'];
//    }
//    if (isset($_COOKIE['bgcolor']))
//    {
//       $bgcolor=$_COOKIE['bgcolor'];
//    }
//    if (isset($_COOKIE['size']))
//    {
//       $size=$_COOKIE['size'];
//    }

?>

<html>
   <head>
       <title> Second page</title>

    </head>
    <body>

        <p> The information is </p>

        <?php  echo"The font style : ".$fstyle."<br>";
               echo"The font size : ".$fsize."<br>";
               echo"The font color : ".$fcolor."<br>";
               echo"The font bgcolor : ".$bgcolor."<br>";
        ?>
        <form action="third.php" method="$_POST">
          Press submit to show implementation:<br>
           <input type="submit" value="Send">

        </form> 
    </body>
</html>


//form.php
<?php
// session_start();
?>

<html>
    <head>
        <title> Authentication </title>
    </head>

    <form action="<?php echo$_SERVER['PHP_SELF']; ?>" method="POST">
        Enter the username : <input type="text" name='uname'><br><br>
        Enter the password: <input type="text" name='pass'><br><br>
        <input type="submit" value="Submit">
    </form>
</html>

<?php
session_start();
$cnt=0;
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $user = $_POST['uname'];
    $pass = $_POST['pass'];

if($user=="atharv" and $pass=="123"){
        
        $_SESSION['username'] = $user;

        echo"<form fieldset=1>
               
                Welcome...
             </form>";
       
        
    }
    else {
        $cnt = isset($_SESSION['attempt']) ? $_SESSION['attempt'] : 0;
        echo"Its your ".$cnt." try";
         $cnt++; 
    
    if ($cnt >3){
       echo "<br> Error ...Too many unsuccessful attempts<br>";
        session_destroy();
    }
    else
         $_SESSION['attempt']=$cnt;
    }
}
?>

//third.php
<?php
   if (isset($_COOKIE['style']))
   {
      $st=$_COOKIE['style'];
   }
   if (isset($_COOKIE['color']))
   {
      $color=$_COOKIE['color'];
   }
   if (isset($_COOKIE['bgcolor']))
   {
      $bgcolor=$_COOKIE['bgcolor'];
   }
   if (isset($_COOKIE['size']))
   {
      $size=$_COOKIE['size'];
   }
?>
<html>
    <head>
        <title> Final webpage </title>

        <style>
            body{
                background-color: <?php echo$bgcolor ?>;
            }
            p{
                font-style: <?php echo$st?>;
                font-size: <?php  echo$size?>;
                color: <?php echo$color?>;

            }
        </style>
    </head>

    <body>
           <p>
              Hello this is your final results .
           </p>
    </body>
</html>
