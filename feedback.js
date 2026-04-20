// feedback.js
// Handles the feedback form submission

document.addEventListener('DOMContentLoaded', function() {
  const form = document.querySelector('form');
  if (!form) return;

  form.addEventListener('submit', function(e) {
    e.preventDefault();
    alert('Thank you for your feedback!');
    form.reset();
  });
});
