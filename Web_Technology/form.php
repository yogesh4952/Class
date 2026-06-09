<?php

$name = "";
$email = "";
$error_message = "";

if($_SERVER["REQUEST_METHOD"] == "POST")
{
    if(empty($_POST["name"]))
    {
        $error_message .= "Name is required<br>";
    }
    else
    {
        $name = $_POST["name"];
    }

    if(empty($_POST["email"]))
    {
        $error_message .= "Email is required<br>";
    }
    else
    {
        $email = $_POST["email"];

        if(!filter_var($email, FILTER_VALIDATE_EMAIL))
        {
            $error_message .= "Invalid Email Format<br>";
        }
    }
}

?>

<form method="POST">

    <label>Name:</label>
    <input type="text" name="name"><br><br>

    <label>Email:</label>
    <input type="text" name="email"><br><br>

    <input type="submit" value="Submit">

</form>

<?php
echo $error_message;
?>