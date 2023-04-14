function loginNow() {
    if (confirm("You must be logged in to perform this action. Do you want to log in now?")) {
        // redirect user to login page here
        window.location.href = "login.html";
    }
}