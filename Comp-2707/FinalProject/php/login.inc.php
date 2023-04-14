<?php
	session_start();
	if(isset($_POST['submit'])){
		$username = "username"; // change to your username
		$password = "password"; // change to your password
		if($_POST['username'] == $username && $_POST['password'] == $password){
			// successful login
			$_SESSION['username'] = $username;
			header("Location: home.php"); // redirect to home page
		} else{
			// unsuccessful login
			echo "Invalid login credentials.";
		}
	}
?>