let button = document.querySelector('#menu');
let navbar = document.querySelector('.header .flex .nav');

button.onclick = () => {
    button.classList.toggle('fa-times');
    navbar.classList.toggle('active');
}