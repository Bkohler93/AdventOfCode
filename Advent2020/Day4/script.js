const input = document.querySelector('#inputs');
const preview = document.querySelector('#preview');

input.style.opacity = 0;

input.addEventListener('change', updateImageDisplay);